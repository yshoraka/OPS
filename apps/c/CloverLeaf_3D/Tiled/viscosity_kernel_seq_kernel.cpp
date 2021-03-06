//
// auto-generated by ops.py
//
#define OPS_ACC0(x, y, z)                                                      \
  (n_x * 1 + n_y * xdim0_viscosity_kernel * 1 +                                \
   n_z * xdim0_viscosity_kernel * ydim0_viscosity_kernel * 1 + x +             \
   xdim0_viscosity_kernel * (y) +                                              \
   xdim0_viscosity_kernel * ydim0_viscosity_kernel * (z))
#define OPS_ACC1(x, y, z)                                                      \
  (n_x * 1 + n_y * xdim1_viscosity_kernel * 1 +                                \
   n_z * xdim1_viscosity_kernel * ydim1_viscosity_kernel * 1 + x +             \
   xdim1_viscosity_kernel * (y) +                                              \
   xdim1_viscosity_kernel * ydim1_viscosity_kernel * (z))
#define OPS_ACC2(x, y, z)                                                      \
  (n_x * 1 + n_y * xdim2_viscosity_kernel * 0 +                                \
   n_z * xdim2_viscosity_kernel * ydim2_viscosity_kernel * 0 + x +             \
   xdim2_viscosity_kernel * (y) +                                              \
   xdim2_viscosity_kernel * ydim2_viscosity_kernel * (z))
#define OPS_ACC3(x, y, z)                                                      \
  (n_x * 0 + n_y * xdim3_viscosity_kernel * 1 +                                \
   n_z * xdim3_viscosity_kernel * ydim3_viscosity_kernel * 0 + x +             \
   xdim3_viscosity_kernel * (y) +                                              \
   xdim3_viscosity_kernel * ydim3_viscosity_kernel * (z))
#define OPS_ACC4(x, y, z)                                                      \
  (n_x * 1 + n_y * xdim4_viscosity_kernel * 1 +                                \
   n_z * xdim4_viscosity_kernel * ydim4_viscosity_kernel * 1 + x +             \
   xdim4_viscosity_kernel * (y) +                                              \
   xdim4_viscosity_kernel * ydim4_viscosity_kernel * (z))
#define OPS_ACC5(x, y, z)                                                      \
  (n_x * 1 + n_y * xdim5_viscosity_kernel * 1 +                                \
   n_z * xdim5_viscosity_kernel * ydim5_viscosity_kernel * 1 + x +             \
   xdim5_viscosity_kernel * (y) +                                              \
   xdim5_viscosity_kernel * ydim5_viscosity_kernel * (z))
#define OPS_ACC6(x, y, z)                                                      \
  (n_x * 1 + n_y * xdim6_viscosity_kernel * 1 +                                \
   n_z * xdim6_viscosity_kernel * ydim6_viscosity_kernel * 1 + x +             \
   xdim6_viscosity_kernel * (y) +                                              \
   xdim6_viscosity_kernel * ydim6_viscosity_kernel * (z))
#define OPS_ACC7(x, y, z)                                                      \
  (n_x * 1 + n_y * xdim7_viscosity_kernel * 1 +                                \
   n_z * xdim7_viscosity_kernel * ydim7_viscosity_kernel * 1 + x +             \
   xdim7_viscosity_kernel * (y) +                                              \
   xdim7_viscosity_kernel * ydim7_viscosity_kernel * (z))
#define OPS_ACC8(x, y, z)                                                      \
  (n_x * 0 + n_y * xdim8_viscosity_kernel * 0 +                                \
   n_z * xdim8_viscosity_kernel * ydim8_viscosity_kernel * 1 + x +             \
   xdim8_viscosity_kernel * (y) +                                              \
   xdim8_viscosity_kernel * ydim8_viscosity_kernel * (z))
#define OPS_ACC9(x, y, z)                                                      \
  (n_x * 1 + n_y * xdim9_viscosity_kernel * 1 +                                \
   n_z * xdim9_viscosity_kernel * ydim9_viscosity_kernel * 1 + x +             \
   xdim9_viscosity_kernel * (y) +                                              \
   xdim9_viscosity_kernel * ydim9_viscosity_kernel * (z))
#define OPS_ACC10(x, y, z)                                                     \
  (n_x * 1 + n_y * xdim10_viscosity_kernel * 1 +                               \
   n_z * xdim10_viscosity_kernel * ydim10_viscosity_kernel * 1 + x +           \
   xdim10_viscosity_kernel * (y) +                                             \
   xdim10_viscosity_kernel * ydim10_viscosity_kernel * (z))
#define OPS_ACC11(x, y, z)                                                     \
  (n_x * 1 + n_y * xdim11_viscosity_kernel * 1 +                               \
   n_z * xdim11_viscosity_kernel * ydim11_viscosity_kernel * 1 + x +           \
   xdim11_viscosity_kernel * (y) +                                             \
   xdim11_viscosity_kernel * ydim11_viscosity_kernel * (z))

// user function

// host stub function
void ops_par_loop_viscosity_kernel_execute(ops_kernel_descriptor *desc) {
  int dim = desc->dim;
  int *range = desc->range;
  ops_arg arg0 = desc->args[0];
  ops_arg arg1 = desc->args[1];
  ops_arg arg2 = desc->args[2];
  ops_arg arg3 = desc->args[3];
  ops_arg arg4 = desc->args[4];
  ops_arg arg5 = desc->args[5];
  ops_arg arg6 = desc->args[6];
  ops_arg arg7 = desc->args[7];
  ops_arg arg8 = desc->args[8];
  ops_arg arg9 = desc->args[9];
  ops_arg arg10 = desc->args[10];
  ops_arg arg11 = desc->args[11];

  // Timing
  double t1, t2, c1, c2;

  ops_arg args[12] = {arg0, arg1, arg2, arg3, arg4,  arg5,
                      arg6, arg7, arg8, arg9, arg10, arg11};

#ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args, 12, range, 45))
    return;
#endif

  if (OPS_diags > 1) {
    ops_timing_realloc(45, "viscosity_kernel");
    OPS_kernels[45].count++;
    ops_timers_core(&c2, &t2);
  }

  // compute locally allocated range for the sub-block
  int start[3];
  int end[3];

  for (int n = 0; n < 3; n++) {
    start[n] = range[2 * n];
    end[n] = range[2 * n + 1];
  }

#ifdef OPS_DEBUG
  ops_register_args(args, "viscosity_kernel");
#endif

  // set up initial pointers and exchange halos if necessary
  int base0 = args[0].dat->base_offset;
  const double *__restrict__ xvel0 = (double *)(args[0].data + base0);

  int base1 = args[1].dat->base_offset;
  const double *__restrict__ yvel0 = (double *)(args[1].data + base1);

  int base2 = args[2].dat->base_offset;
  const double *__restrict__ celldx = (double *)(args[2].data + base2);

  int base3 = args[3].dat->base_offset;
  const double *__restrict__ celldy = (double *)(args[3].data + base3);

  int base4 = args[4].dat->base_offset;
  const double *__restrict__ pressure = (double *)(args[4].data + base4);

  int base5 = args[5].dat->base_offset;
  const double *__restrict__ density0 = (double *)(args[5].data + base5);

  int base6 = args[6].dat->base_offset;
  double *__restrict__ viscosity = (double *)(args[6].data + base6);

  int base7 = args[7].dat->base_offset;
  const double *__restrict__ zvel0 = (double *)(args[7].data + base7);

  int base8 = args[8].dat->base_offset;
  const double *__restrict__ celldz = (double *)(args[8].data + base8);

  int base9 = args[9].dat->base_offset;
  const double *__restrict__ xarea = (double *)(args[9].data + base9);

  int base10 = args[10].dat->base_offset;
  const double *__restrict__ yarea = (double *)(args[10].data + base10);

  int base11 = args[11].dat->base_offset;
  const double *__restrict__ zarea = (double *)(args[11].data + base11);

  // initialize global variable with the dimension of dats
  int xdim0_viscosity_kernel = args[0].dat->size[0];
  int ydim0_viscosity_kernel = args[0].dat->size[1];
  int xdim1_viscosity_kernel = args[1].dat->size[0];
  int ydim1_viscosity_kernel = args[1].dat->size[1];
  int xdim2_viscosity_kernel = args[2].dat->size[0];
  int ydim2_viscosity_kernel = args[2].dat->size[1];
  int xdim3_viscosity_kernel = args[3].dat->size[0];
  int ydim3_viscosity_kernel = args[3].dat->size[1];
  int xdim4_viscosity_kernel = args[4].dat->size[0];
  int ydim4_viscosity_kernel = args[4].dat->size[1];
  int xdim5_viscosity_kernel = args[5].dat->size[0];
  int ydim5_viscosity_kernel = args[5].dat->size[1];
  int xdim6_viscosity_kernel = args[6].dat->size[0];
  int ydim6_viscosity_kernel = args[6].dat->size[1];
  int xdim7_viscosity_kernel = args[7].dat->size[0];
  int ydim7_viscosity_kernel = args[7].dat->size[1];
  int xdim8_viscosity_kernel = args[8].dat->size[0];
  int ydim8_viscosity_kernel = args[8].dat->size[1];
  int xdim9_viscosity_kernel = args[9].dat->size[0];
  int ydim9_viscosity_kernel = args[9].dat->size[1];
  int xdim10_viscosity_kernel = args[10].dat->size[0];
  int ydim10_viscosity_kernel = args[10].dat->size[1];
  int xdim11_viscosity_kernel = args[11].dat->size[0];
  int ydim11_viscosity_kernel = args[11].dat->size[1];

  // Halo Exchanges
  ops_H_D_exchanges_host(args, 12);
  ops_halo_exchanges(args, 12, range);
  ops_H_D_exchanges_host(args, 12);

  if (OPS_diags > 1) {
    ops_timers_core(&c1, &t1);
    OPS_kernels[45].mpi_time += t1 - t2;
  }

#pragma omp parallel for collapse(2)
  for (int n_z = start[2]; n_z < end[2]; n_z++) {
    for (int n_y = start[1]; n_y < end[1]; n_y++) {
#ifdef intel
#pragma omp simd
#else
#pragma simd
#endif
      for (int n_x = start[0]; n_x < end[0]; n_x++) {

        double grad2, pgradx, pgrady, pgradz, pgradx2, pgrady2, pgradz2, grad,
            ygrad, xgrad, zgrad, div, limiter, pgrad;

        double ugradx1 = xvel0[OPS_ACC0(0, 0, 0)] + xvel0[OPS_ACC0(0, 1, 0)] +
                         xvel0[OPS_ACC0(0, 0, 1)] + xvel0[OPS_ACC0(0, 1, 1)];
        double ugradx2 = xvel0[OPS_ACC0(1, 0, 0)] + xvel0[OPS_ACC0(1, 1, 0)] +
                         xvel0[OPS_ACC0(1, 0, 1)] + xvel0[OPS_ACC0(1, 1, 1)];
        double ugrady1 = xvel0[OPS_ACC0(0, 0, 0)] + xvel0[OPS_ACC0(1, 0, 0)] +
                         xvel0[OPS_ACC0(0, 0, 1)] + xvel0[OPS_ACC0(1, 0, 1)];
        double ugrady2 = xvel0[OPS_ACC0(0, 1, 0)] + xvel0[OPS_ACC0(1, 1, 0)] +
                         xvel0[OPS_ACC0(0, 1, 1)] + xvel0[OPS_ACC0(1, 1, 1)];
        double ugradz1 = xvel0[OPS_ACC0(0, 0, 0)] + xvel0[OPS_ACC0(1, 0, 0)] +
                         xvel0[OPS_ACC0(0, 1, 0)] + xvel0[OPS_ACC0(1, 1, 0)];
        double ugradz2 = xvel0[OPS_ACC0(0, 0, 1)] + xvel0[OPS_ACC0(1, 0, 1)] +
                         xvel0[OPS_ACC0(0, 1, 1)] + xvel0[OPS_ACC0(1, 1, 1)];

        double vgradx1 = yvel0[OPS_ACC1(0, 0, 0)] + yvel0[OPS_ACC1(0, 1, 0)] +
                         yvel0[OPS_ACC1(0, 0, 1)] + yvel0[OPS_ACC1(0, 1, 1)];
        double vgradx2 = yvel0[OPS_ACC1(1, 0, 0)] + yvel0[OPS_ACC1(1, 1, 0)] +
                         yvel0[OPS_ACC1(1, 0, 1)] + yvel0[OPS_ACC1(1, 1, 1)];
        double vgrady1 = yvel0[OPS_ACC1(0, 0, 0)] + yvel0[OPS_ACC1(1, 0, 0)] +
                         yvel0[OPS_ACC1(0, 0, 1)] + yvel0[OPS_ACC1(1, 0, 1)];
        double vgrady2 = yvel0[OPS_ACC1(0, 1, 0)] + yvel0[OPS_ACC1(1, 1, 0)] +
                         yvel0[OPS_ACC1(0, 1, 1)] + yvel0[OPS_ACC1(1, 1, 1)];
        double vgradz1 = yvel0[OPS_ACC1(0, 0, 0)] + yvel0[OPS_ACC1(1, 0, 0)] +
                         yvel0[OPS_ACC1(0, 1, 0)] + yvel0[OPS_ACC1(1, 1, 0)];
        double vgradz2 = yvel0[OPS_ACC1(0, 0, 1)] + yvel0[OPS_ACC1(1, 0, 1)] +
                         yvel0[OPS_ACC1(0, 1, 1)] + yvel0[OPS_ACC1(1, 1, 1)];

        double wgradx1 = zvel0[OPS_ACC7(0, 0, 0)] + zvel0[OPS_ACC7(0, 1, 0)] +
                         zvel0[OPS_ACC7(0, 0, 1)] + zvel0[OPS_ACC7(0, 1, 1)];
        double wgradx2 = zvel0[OPS_ACC7(1, 0, 0)] + zvel0[OPS_ACC7(1, 1, 0)] +
                         zvel0[OPS_ACC7(1, 0, 1)] + zvel0[OPS_ACC7(1, 1, 1)];
        double wgrady1 = zvel0[OPS_ACC7(0, 0, 0)] + zvel0[OPS_ACC7(1, 0, 0)] +
                         zvel0[OPS_ACC7(0, 0, 1)] + zvel0[OPS_ACC7(1, 0, 1)];
        double wgrady2 = zvel0[OPS_ACC7(0, 1, 0)] + zvel0[OPS_ACC7(1, 1, 0)] +
                         zvel0[OPS_ACC7(0, 1, 1)] + zvel0[OPS_ACC7(1, 1, 1)];
        double wgradz1 = zvel0[OPS_ACC7(0, 0, 0)] + zvel0[OPS_ACC7(1, 0, 0)] +
                         zvel0[OPS_ACC7(0, 1, 0)] + zvel0[OPS_ACC7(1, 1, 0)];
        double wgradz2 = zvel0[OPS_ACC7(0, 0, 1)] + zvel0[OPS_ACC7(1, 0, 1)] +
                         zvel0[OPS_ACC7(0, 1, 1)] + zvel0[OPS_ACC7(1, 1, 1)];

        div = xarea[OPS_ACC9(0, 0, 0)] * (ugradx2 - ugradx1) +
              yarea[OPS_ACC10(0, 0, 0)] * (vgrady2 - vgrady1) +
              zarea[OPS_ACC11(0, 0, 0)] * (wgradz2 - wgradz1);

        double xx = 0.25 * (ugradx2 - ugradx1) / (celldx[OPS_ACC2(0, 0, 0)]);
        double yy = 0.25 * (vgrady2 - vgrady1) / (celldy[OPS_ACC3(0, 0, 0)]);
        double zz = 0.25 * (wgradz2 - wgradz1) / (celldz[OPS_ACC8(0, 0, 0)]);
        double xy = 0.25 * (ugrady2 - ugrady1) / (celldy[OPS_ACC3(0, 0, 0)]) +
                    0.25 * (vgradx2 - vgradx1) / (celldx[OPS_ACC2(0, 0, 0)]);
        double xz = 0.25 * (ugradz2 - ugradz1) / (celldz[OPS_ACC8(0, 0, 0)]) +
                    0.25 * (wgradx2 - wgradx1) / (celldx[OPS_ACC2(0, 0, 0)]);
        double yz = 0.25 * (vgradz2 - vgradz1) / (celldz[OPS_ACC8(0, 0, 0)]) +
                    0.25 * (wgrady2 - wgrady1) / (celldy[OPS_ACC3(0, 0, 0)]);

        pgradx = (pressure[OPS_ACC4(1, 0, 0)] - pressure[OPS_ACC4(-1, 0, 0)]) /
                 (celldx[OPS_ACC2(0, 0, 0)] + celldx[OPS_ACC2(1, 0, 0)]);
        pgrady = (pressure[OPS_ACC4(0, 1, 0)] - pressure[OPS_ACC4(0, -1, 0)]) /
                 (celldy[OPS_ACC3(0, 0, 0)] + celldy[OPS_ACC3(0, 1, 0)]);
        pgradz = (pressure[OPS_ACC4(0, 0, 1)] - pressure[OPS_ACC4(0, 0, -1)]) /
                 (celldz[OPS_ACC8(0, 0, 0)] + celldz[OPS_ACC8(0, 0, 1)]);

        pgradx2 = pgradx * pgradx;
        pgrady2 = pgrady * pgrady;
        pgradz2 = pgradz * pgradz;
        limiter =
            (xx * pgradx2 + yy * pgrady2 + zz * pgradz2 + xy * pgradx * pgrady +
             xz * pgradx * pgradz + yz * pgrady * pgradz) /
            MAX(pgradx2 + pgrady2 + pgradz2, 1.0e-16);

        if ((limiter > 0.0) || (div >= 0.0)) {
          viscosity[OPS_ACC6(0, 0, 0)] = 0.0;
        } else {
          pgradx = SIGN(MAX(1.0e-16, fabs(pgradx)), pgradx);
          pgrady = SIGN(MAX(1.0e-16, fabs(pgrady)), pgrady);
          pgradz = SIGN(MAX(1.0e-16, fabs(pgradz)), pgradz);
          pgrad = sqrt(pgradx * pgradx + pgrady * pgrady + pgradz * pgradz);
          xgrad = fabs(celldx[OPS_ACC2(0, 0, 0)] * pgrad / pgradx);
          ygrad = fabs(celldy[OPS_ACC3(0, 0, 0)] * pgrad / pgrady);
          zgrad = fabs(celldz[OPS_ACC8(0, 0, 0)] * pgrad / pgradz);
          grad = MIN(xgrad, MIN(ygrad, zgrad));
          grad2 = grad * grad;

          viscosity[OPS_ACC6(0, 0, 0)] =
              2.0 * (density0[OPS_ACC5(0, 0, 0)]) * grad2 * limiter * limiter;
        }
      }
    }
  }
  if (OPS_diags > 1) {
    ops_timers_core(&c2, &t2);
    OPS_kernels[45].time += t2 - t1;
  }
  ops_set_dirtybit_host(args, 12);
  ops_set_halo_dirtybit3(&args[6], range);

  if (OPS_diags > 1) {
    // Update kernel record
    ops_timers_core(&c1, &t1);
    OPS_kernels[45].mpi_time += t1 - t2;
    OPS_kernels[45].transfer += ops_compute_transfer(dim, start, end, &arg0);
    OPS_kernels[45].transfer += ops_compute_transfer(dim, start, end, &arg1);
    OPS_kernels[45].transfer += ops_compute_transfer(dim, start, end, &arg2);
    OPS_kernels[45].transfer += ops_compute_transfer(dim, start, end, &arg3);
    OPS_kernels[45].transfer += ops_compute_transfer(dim, start, end, &arg4);
    OPS_kernels[45].transfer += ops_compute_transfer(dim, start, end, &arg5);
    OPS_kernels[45].transfer += ops_compute_transfer(dim, start, end, &arg6);
    OPS_kernels[45].transfer += ops_compute_transfer(dim, start, end, &arg7);
    OPS_kernels[45].transfer += ops_compute_transfer(dim, start, end, &arg8);
    OPS_kernels[45].transfer += ops_compute_transfer(dim, start, end, &arg9);
    OPS_kernels[45].transfer += ops_compute_transfer(dim, start, end, &arg10);
    OPS_kernels[45].transfer += ops_compute_transfer(dim, start, end, &arg11);
  }
}
#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4
#undef OPS_ACC5
#undef OPS_ACC6
#undef OPS_ACC7
#undef OPS_ACC8
#undef OPS_ACC9
#undef OPS_ACC10
#undef OPS_ACC11

void ops_par_loop_viscosity_kernel(char const *name, ops_block block, int dim,
                                   int *range, ops_arg arg0, ops_arg arg1,
                                   ops_arg arg2, ops_arg arg3, ops_arg arg4,
                                   ops_arg arg5, ops_arg arg6, ops_arg arg7,
                                   ops_arg arg8, ops_arg arg9, ops_arg arg10,
                                   ops_arg arg11) {
  ops_kernel_descriptor *desc =
      (ops_kernel_descriptor *)malloc(sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->index = 45;
#ifdef OPS_MPI
  sub_block_list sb = OPS_sub_block_list[block->index];
  if (!sb->owned)
    return;
  for (int n = 0; n < 3; n++) {
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
  for (int i = 0; i < 6; i++) {
    desc->range[i] = range[i];
  }
#endif // OPS_MPI
  desc->nargs = 12;
  desc->args = (ops_arg *)malloc(12 * sizeof(ops_arg));
  desc->args[0] = arg0;
  desc->args[1] = arg1;
  desc->args[2] = arg2;
  desc->args[3] = arg3;
  desc->args[4] = arg4;
  desc->args[5] = arg5;
  desc->args[6] = arg6;
  desc->args[7] = arg7;
  desc->args[8] = arg8;
  desc->args[9] = arg9;
  desc->args[10] = arg10;
  desc->args[11] = arg11;
  desc->function = ops_par_loop_viscosity_kernel_execute;
  ops_enqueue_kernel(desc);
}
