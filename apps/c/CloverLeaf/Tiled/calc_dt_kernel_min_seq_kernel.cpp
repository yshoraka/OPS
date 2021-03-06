//
// auto-generated by ops.py
//
#define OPS_ACC0(x, y)                                                         \
  (n_x * 1 + n_y * xdim0_calc_dt_kernel_min * 1 + x +                          \
   xdim0_calc_dt_kernel_min * (y))

// user function

// host stub function
void ops_par_loop_calc_dt_kernel_min_execute(ops_kernel_descriptor *desc) {
  int dim = desc->dim;
  int *range = desc->range;
  ops_arg arg0 = desc->args[0];
  ops_arg arg1 = desc->args[1];

  // Timing
  double t1, t2, c1, c2;

  ops_arg args[2] = {arg0, arg1};

#ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args, 2, range, 28))
    return;
#endif

  if (OPS_diags > 1) {
    ops_timing_realloc(28, "calc_dt_kernel_min");
    OPS_kernels[28].count++;
    ops_timers_core(&c2, &t2);
  }

  // compute locally allocated range for the sub-block
  int start[2];
  int end[2];

  for (int n = 0; n < 2; n++) {
    start[n] = range[2 * n];
    end[n] = range[2 * n + 1];
  }

#ifdef OPS_DEBUG
  ops_register_args(args, "calc_dt_kernel_min");
#endif

  // set up initial pointers and exchange halos if necessary
  int base0 = args[0].dat->base_offset;
  const double *__restrict__ dt_min = (double *)(args[0].data + base0);

#ifdef OPS_MPI
  double *__restrict__ p_a1 =
      (double *)(((ops_reduction)args[1].data)->data +
                 ((ops_reduction)args[1].data)->size * block->index);
#else  // OPS_MPI
  double *__restrict__ p_a1 = (double *)((ops_reduction)args[1].data)->data;
#endif // OPS_MPI

  // initialize global variable with the dimension of dats
  int xdim0_calc_dt_kernel_min = args[0].dat->size[0];

  // Halo Exchanges
  ops_H_D_exchanges_host(args, 2);
  ops_halo_exchanges(args, 2, range);
  ops_H_D_exchanges_host(args, 2);

  if (OPS_diags > 1) {
    ops_timers_core(&c1, &t1);
    OPS_kernels[28].mpi_time += t1 - t2;
  }

  double p_a1_0 = p_a1[0];
#pragma omp parallel for reduction(min : p_a1_0)
  for (int n_y = start[1]; n_y < end[1]; n_y++) {
#ifdef intel
#pragma omp simd reduction(min : p_a1_0)
#else
#pragma simd reduction(min : p_a1_0)
#endif
    for (int n_x = start[0]; n_x < end[0]; n_x++) {
      double *dt_min_val = &p_a1_0;

      *dt_min_val = MIN(*dt_min_val, dt_min[OPS_ACC0(0, 0)]);
    }
  }
  p_a1[0] = p_a1_0;
  if (OPS_diags > 1) {
    ops_timers_core(&c2, &t2);
    OPS_kernels[28].time += t2 - t1;
  }
  ops_set_dirtybit_host(args, 2);

  if (OPS_diags > 1) {
    // Update kernel record
    ops_timers_core(&c1, &t1);
    OPS_kernels[28].mpi_time += t1 - t2;
    OPS_kernels[28].transfer += ops_compute_transfer(dim, start, end, &arg0);
  }
}
#undef OPS_ACC0

void ops_par_loop_calc_dt_kernel_min(char const *name, ops_block block, int dim,
                                     int *range, ops_arg arg0, ops_arg arg1) {
  ops_kernel_descriptor *desc =
      (ops_kernel_descriptor *)malloc(sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->index = 28;
#ifdef OPS_MPI
  sub_block_list sb = OPS_sub_block_list[block->index];
  if (!sb->owned)
    return;
  for (int n = 0; n < 2; n++) {
    desc->range[2 * n] = sb->decomp_disp[n];
    desc->range[2 * n + 1] = sb->decomp_disp[n] + sb->decomp_size[n];
    if (desc->range[2 * n] >= range[2 * n]) {
      desc->range[2 * n] = 0;
    } else {
      desc->range[2 * n] = range[2 * n] - desc->range[2 * n];
    }
    if (sb->id_m[n] == MPI_PROC_NULL && range[2 * n] < 0)
      desc->range[2 * n] = range[2 * n];
    if (desc->range[2 * n + 1] >= range[2 * n + 1]) {
      desc->range[2 * n + 1] = range[2 * n + 1] - sb->decomp_disp[n];
    } else {
      desc->range[2 * n + 1] = sb->decomp_size[n];
    }
    if (sb->id_p[n] == MPI_PROC_NULL &&
        (range[2 * n + 1] > sb->decomp_disp[n] + sb->decomp_size[n]))
      desc->range[2 * n + 1] +=
          (range[2 * n + 1] - sb->decomp_disp[n] - sb->decomp_size[n]);
  }
#else // OPS_MPI
  for (int i = 0; i < 4; i++) {
    desc->range[i] = range[i];
  }
#endif // OPS_MPI
  desc->nargs = 2;
  desc->args = (ops_arg *)malloc(2 * sizeof(ops_arg));
  desc->args[0] = arg0;
  desc->args[1] = arg1;
  desc->function = ops_par_loop_calc_dt_kernel_min_execute;
  ops_enqueue_kernel(desc);
}
