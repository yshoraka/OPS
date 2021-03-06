//
// auto-generated by ops.py
//
__constant__ int xdim0_viscosity_kernel;
int xdim0_viscosity_kernel_h = -1;
int ydim0_viscosity_kernel_h = -1;
__constant__ int xdim1_viscosity_kernel;
int xdim1_viscosity_kernel_h = -1;
int ydim1_viscosity_kernel_h = -1;
__constant__ int xdim2_viscosity_kernel;
int xdim2_viscosity_kernel_h = -1;
int ydim2_viscosity_kernel_h = -1;
__constant__ int xdim3_viscosity_kernel;
int xdim3_viscosity_kernel_h = -1;
int ydim3_viscosity_kernel_h = -1;
__constant__ int xdim4_viscosity_kernel;
int xdim4_viscosity_kernel_h = -1;
int ydim4_viscosity_kernel_h = -1;
__constant__ int xdim5_viscosity_kernel;
int xdim5_viscosity_kernel_h = -1;
int ydim5_viscosity_kernel_h = -1;
__constant__ int xdim6_viscosity_kernel;
int xdim6_viscosity_kernel_h = -1;
int ydim6_viscosity_kernel_h = -1;

#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4
#undef OPS_ACC5
#undef OPS_ACC6

#define OPS_ACC0(x, y) (x + xdim0_viscosity_kernel * (y))
#define OPS_ACC1(x, y) (x + xdim1_viscosity_kernel * (y))
#define OPS_ACC2(x, y) (x + xdim2_viscosity_kernel * (y))
#define OPS_ACC3(x, y) (x + xdim3_viscosity_kernel * (y))
#define OPS_ACC4(x, y) (x + xdim4_viscosity_kernel * (y))
#define OPS_ACC5(x, y) (x + xdim5_viscosity_kernel * (y))
#define OPS_ACC6(x, y) (x + xdim6_viscosity_kernel * (y))

// user function
__device__

    void
    viscosity_kernel_gpu(const double *xvel0, const double *yvel0,
                         const double *celldx, const double *celldy,
                         const double *pressure, const double *density0,
                         double *viscosity) {

  double ugrad, vgrad, grad2, pgradx, pgrady, pgradx2, pgrady2, grad, ygrad,
      xgrad, div, strain2, limiter, pgrad;

  ugrad = (xvel0[OPS_ACC0(1, 0)] + xvel0[OPS_ACC0(1, 1)]) -
          (xvel0[OPS_ACC0(0, 0)] + xvel0[OPS_ACC0(0, 1)]);
  vgrad = (yvel0[OPS_ACC1(0, 1)] + yvel0[OPS_ACC1(1, 1)]) -
          (yvel0[OPS_ACC1(0, 0)] + yvel0[OPS_ACC1(1, 0)]);

  div = (celldx[OPS_ACC2(0, 0)]) * (ugrad) + (celldy[OPS_ACC3(0, 0)]) * (vgrad);

  strain2 = 0.5 * (xvel0[OPS_ACC0(0, 1)] + xvel0[OPS_ACC0(1, 1)] -
                   xvel0[OPS_ACC0(0, 0)] - xvel0[OPS_ACC0(1, 0)]) /
                (celldy[OPS_ACC3(0, 0)]) +
            0.5 * (yvel0[OPS_ACC1(1, 0)] + yvel0[OPS_ACC1(1, 1)] -
                   yvel0[OPS_ACC1(0, 0)] - yvel0[OPS_ACC1(0, 1)]) /
                (celldx[OPS_ACC2(0, 0)]);

  pgradx = (pressure[OPS_ACC4(1, 0)] - pressure[OPS_ACC4(-1, 0)]) /
           (celldx[OPS_ACC2(0, 0)] + celldx[OPS_ACC2(1, 0)]);
  pgrady = (pressure[OPS_ACC4(0, 1)] - pressure[OPS_ACC4(0, -1)]) /
           (celldy[OPS_ACC3(0, 0)] + celldy[OPS_ACC3(0, 1)]);

  pgradx2 = pgradx * pgradx;
  pgrady2 = pgrady * pgrady;

  limiter = ((0.5 * (ugrad) / celldx[OPS_ACC2(0, 0)]) * pgradx2 +
             (0.5 * (vgrad) / celldy[OPS_ACC3(0, 0)]) * pgrady2 +
             strain2 * pgradx * pgrady) /
            MAX(pgradx2 + pgrady2, 1.0e-16);

  if ((limiter > 0.0) || (div >= 0.0)) {
    viscosity[OPS_ACC6(0, 0)] = 0.0;
  } else {
    pgradx = SIGN(MAX(1.0e-16, fabs(pgradx)), pgradx);
    pgrady = SIGN(MAX(1.0e-16, fabs(pgrady)), pgrady);
    pgrad = sqrt(pgradx * pgradx + pgrady * pgrady);
    xgrad = fabs(celldx[OPS_ACC2(0, 0)] * pgrad / pgradx);
    ygrad = fabs(celldy[OPS_ACC3(0, 0)] * pgrad / pgrady);
    grad = MIN(xgrad, ygrad);
    grad2 = grad * grad;

    viscosity[OPS_ACC6(0, 0)] =
        2.0 * (density0[OPS_ACC5(0, 0)]) * grad2 * limiter * limiter;
  }
}

#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4
#undef OPS_ACC5
#undef OPS_ACC6

__global__ void ops_viscosity_kernel(
    const double *__restrict arg0, const double *__restrict arg1,
    const double *__restrict arg2, const double *__restrict arg3,
    const double *__restrict arg4, const double *__restrict arg5,
    double *__restrict arg6, int size0, int size1) {

  int idx_y = blockDim.y * blockIdx.y + threadIdx.y;
  int idx_x = blockDim.x * blockIdx.x + threadIdx.x;

  arg0 += idx_x * 1 * 1 + idx_y * 1 * 1 * xdim0_viscosity_kernel;
  arg1 += idx_x * 1 * 1 + idx_y * 1 * 1 * xdim1_viscosity_kernel;
  arg2 += idx_x * 1 * 1 + idx_y * 0 * 1 * xdim2_viscosity_kernel;
  arg3 += idx_x * 0 * 1 + idx_y * 1 * 1 * xdim3_viscosity_kernel;
  arg4 += idx_x * 1 * 1 + idx_y * 1 * 1 * xdim4_viscosity_kernel;
  arg5 += idx_x * 1 * 1 + idx_y * 1 * 1 * xdim5_viscosity_kernel;
  arg6 += idx_x * 1 * 1 + idx_y * 1 * 1 * xdim6_viscosity_kernel;

  if (idx_x < size0 && idx_y < size1) {
    viscosity_kernel_gpu(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
  }
}

// host stub function
void ops_par_loop_viscosity_kernel(char const *name, ops_block block, int dim,
                                   int *range, ops_arg arg0, ops_arg arg1,
                                   ops_arg arg2, ops_arg arg3, ops_arg arg4,
                                   ops_arg arg5, ops_arg arg6) {

  // Timing
  double t1, t2, c1, c2;

  ops_arg args[7] = {arg0, arg1, arg2, arg3, arg4, arg5, arg6};

#ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args, 7, range, 34))
    return;
#endif

  if (OPS_diags > 1) {
    ops_timing_realloc(34, "viscosity_kernel");
    OPS_kernels[34].count++;
    ops_timers_core(&c1, &t1);
  }

  // compute locally allocated range for the sub-block
  int start[2];
  int end[2];
#ifdef OPS_MPI
  sub_block_list sb = OPS_sub_block_list[block->index];
  if (!sb->owned)
    return;
  for (int n = 0; n < 2; n++) {
    start[n] = sb->decomp_disp[n];
    end[n] = sb->decomp_disp[n] + sb->decomp_size[n];
    if (start[n] >= range[2 * n]) {
      start[n] = 0;
    } else {
      start[n] = range[2 * n] - start[n];
    }
    if (sb->id_m[n] == MPI_PROC_NULL && range[2 * n] < 0)
      start[n] = range[2 * n];
    if (end[n] >= range[2 * n + 1]) {
      end[n] = range[2 * n + 1] - sb->decomp_disp[n];
    } else {
      end[n] = sb->decomp_size[n];
    }
    if (sb->id_p[n] == MPI_PROC_NULL &&
        (range[2 * n + 1] > sb->decomp_disp[n] + sb->decomp_size[n]))
      end[n] += (range[2 * n + 1] - sb->decomp_disp[n] - sb->decomp_size[n]);
  }
#else
  for (int n = 0; n < 2; n++) {
    start[n] = range[2 * n];
    end[n] = range[2 * n + 1];
  }
#endif

  int x_size = MAX(0, end[0] - start[0]);
  int y_size = MAX(0, end[1] - start[1]);

  int xdim0 = args[0].dat->size[0];
  int xdim1 = args[1].dat->size[0];
  int xdim2 = args[2].dat->size[0];
  int xdim3 = args[3].dat->size[0];
  int xdim4 = args[4].dat->size[0];
  int xdim5 = args[5].dat->size[0];
  int xdim6 = args[6].dat->size[0];

  if (xdim0 != xdim0_viscosity_kernel_h || xdim1 != xdim1_viscosity_kernel_h ||
      xdim2 != xdim2_viscosity_kernel_h || xdim3 != xdim3_viscosity_kernel_h ||
      xdim4 != xdim4_viscosity_kernel_h || xdim5 != xdim5_viscosity_kernel_h ||
      xdim6 != xdim6_viscosity_kernel_h) {
    cudaMemcpyToSymbol(xdim0_viscosity_kernel, &xdim0, sizeof(int));
    xdim0_viscosity_kernel_h = xdim0;
    cudaMemcpyToSymbol(xdim1_viscosity_kernel, &xdim1, sizeof(int));
    xdim1_viscosity_kernel_h = xdim1;
    cudaMemcpyToSymbol(xdim2_viscosity_kernel, &xdim2, sizeof(int));
    xdim2_viscosity_kernel_h = xdim2;
    cudaMemcpyToSymbol(xdim3_viscosity_kernel, &xdim3, sizeof(int));
    xdim3_viscosity_kernel_h = xdim3;
    cudaMemcpyToSymbol(xdim4_viscosity_kernel, &xdim4, sizeof(int));
    xdim4_viscosity_kernel_h = xdim4;
    cudaMemcpyToSymbol(xdim5_viscosity_kernel, &xdim5, sizeof(int));
    xdim5_viscosity_kernel_h = xdim5;
    cudaMemcpyToSymbol(xdim6_viscosity_kernel, &xdim6, sizeof(int));
    xdim6_viscosity_kernel_h = xdim6;
  }

  dim3 grid((x_size - 1) / OPS_block_size_x + 1,
            (y_size - 1) / OPS_block_size_y + 1, 1);
  dim3 tblock(OPS_block_size_x, OPS_block_size_y, 1);

  int dat0 = args[0].dat->elem_size;
  int dat1 = args[1].dat->elem_size;
  int dat2 = args[2].dat->elem_size;
  int dat3 = args[3].dat->elem_size;
  int dat4 = args[4].dat->elem_size;
  int dat5 = args[5].dat->elem_size;
  int dat6 = args[6].dat->elem_size;

  char *p_a[7];

  // set up initial pointers
  int d_m[OPS_MAX_DIM];
#ifdef OPS_MPI
  for (int d = 0; d < dim; d++)
    d_m[d] =
        args[0].dat->d_m[d] + OPS_sub_dat_list[args[0].dat->index]->d_im[d];
#else
  for (int d = 0; d < dim; d++)
    d_m[d] = args[0].dat->d_m[d];
#endif
  int base0 = dat0 * 1 * (start[0] * args[0].stencil->stride[0] -
                          args[0].dat->base[0] - d_m[0]);
  base0 = base0 +
          dat0 * args[0].dat->size[0] * (start[1] * args[0].stencil->stride[1] -
                                         args[0].dat->base[1] - d_m[1]);
  p_a[0] = (char *)args[0].data_d + base0;

#ifdef OPS_MPI
  for (int d = 0; d < dim; d++)
    d_m[d] =
        args[1].dat->d_m[d] + OPS_sub_dat_list[args[1].dat->index]->d_im[d];
#else
  for (int d = 0; d < dim; d++)
    d_m[d] = args[1].dat->d_m[d];
#endif
  int base1 = dat1 * 1 * (start[0] * args[1].stencil->stride[0] -
                          args[1].dat->base[0] - d_m[0]);
  base1 = base1 +
          dat1 * args[1].dat->size[0] * (start[1] * args[1].stencil->stride[1] -
                                         args[1].dat->base[1] - d_m[1]);
  p_a[1] = (char *)args[1].data_d + base1;

#ifdef OPS_MPI
  for (int d = 0; d < dim; d++)
    d_m[d] =
        args[2].dat->d_m[d] + OPS_sub_dat_list[args[2].dat->index]->d_im[d];
#else
  for (int d = 0; d < dim; d++)
    d_m[d] = args[2].dat->d_m[d];
#endif
  int base2 = dat2 * 1 * (start[0] * args[2].stencil->stride[0] -
                          args[2].dat->base[0] - d_m[0]);
  base2 = base2 +
          dat2 * args[2].dat->size[0] * (start[1] * args[2].stencil->stride[1] -
                                         args[2].dat->base[1] - d_m[1]);
  p_a[2] = (char *)args[2].data_d + base2;

#ifdef OPS_MPI
  for (int d = 0; d < dim; d++)
    d_m[d] =
        args[3].dat->d_m[d] + OPS_sub_dat_list[args[3].dat->index]->d_im[d];
#else
  for (int d = 0; d < dim; d++)
    d_m[d] = args[3].dat->d_m[d];
#endif
  int base3 = dat3 * 1 * (start[0] * args[3].stencil->stride[0] -
                          args[3].dat->base[0] - d_m[0]);
  base3 = base3 +
          dat3 * args[3].dat->size[0] * (start[1] * args[3].stencil->stride[1] -
                                         args[3].dat->base[1] - d_m[1]);
  p_a[3] = (char *)args[3].data_d + base3;

#ifdef OPS_MPI
  for (int d = 0; d < dim; d++)
    d_m[d] =
        args[4].dat->d_m[d] + OPS_sub_dat_list[args[4].dat->index]->d_im[d];
#else
  for (int d = 0; d < dim; d++)
    d_m[d] = args[4].dat->d_m[d];
#endif
  int base4 = dat4 * 1 * (start[0] * args[4].stencil->stride[0] -
                          args[4].dat->base[0] - d_m[0]);
  base4 = base4 +
          dat4 * args[4].dat->size[0] * (start[1] * args[4].stencil->stride[1] -
                                         args[4].dat->base[1] - d_m[1]);
  p_a[4] = (char *)args[4].data_d + base4;

#ifdef OPS_MPI
  for (int d = 0; d < dim; d++)
    d_m[d] =
        args[5].dat->d_m[d] + OPS_sub_dat_list[args[5].dat->index]->d_im[d];
#else
  for (int d = 0; d < dim; d++)
    d_m[d] = args[5].dat->d_m[d];
#endif
  int base5 = dat5 * 1 * (start[0] * args[5].stencil->stride[0] -
                          args[5].dat->base[0] - d_m[0]);
  base5 = base5 +
          dat5 * args[5].dat->size[0] * (start[1] * args[5].stencil->stride[1] -
                                         args[5].dat->base[1] - d_m[1]);
  p_a[5] = (char *)args[5].data_d + base5;

#ifdef OPS_MPI
  for (int d = 0; d < dim; d++)
    d_m[d] =
        args[6].dat->d_m[d] + OPS_sub_dat_list[args[6].dat->index]->d_im[d];
#else
  for (int d = 0; d < dim; d++)
    d_m[d] = args[6].dat->d_m[d];
#endif
  int base6 = dat6 * 1 * (start[0] * args[6].stencil->stride[0] -
                          args[6].dat->base[0] - d_m[0]);
  base6 = base6 +
          dat6 * args[6].dat->size[0] * (start[1] * args[6].stencil->stride[1] -
                                         args[6].dat->base[1] - d_m[1]);
  p_a[6] = (char *)args[6].data_d + base6;

  ops_H_D_exchanges_device(args, 7);
  ops_halo_exchanges(args, 7, range);

  if (OPS_diags > 1) {
    ops_timers_core(&c2, &t2);
    OPS_kernels[34].mpi_time += t2 - t1;
  }

  // call kernel wrapper function, passing in pointers to data
  ops_viscosity_kernel<<<grid, tblock>>>(
      (double *)p_a[0], (double *)p_a[1], (double *)p_a[2], (double *)p_a[3],
      (double *)p_a[4], (double *)p_a[5], (double *)p_a[6], x_size, y_size);

  if (OPS_diags > 1) {
    cutilSafeCall(cudaDeviceSynchronize());
    ops_timers_core(&c1, &t1);
    OPS_kernels[34].time += t1 - t2;
  }

  ops_set_dirtybit_device(args, 7);
  ops_set_halo_dirtybit3(&args[6], range);

  if (OPS_diags > 1) {
    // Update kernel record
    ops_timers_core(&c2, &t2);
    OPS_kernels[34].mpi_time += t2 - t1;
    OPS_kernels[34].transfer += ops_compute_transfer(dim, start, end, &arg0);
    OPS_kernels[34].transfer += ops_compute_transfer(dim, start, end, &arg1);
    OPS_kernels[34].transfer += ops_compute_transfer(dim, start, end, &arg2);
    OPS_kernels[34].transfer += ops_compute_transfer(dim, start, end, &arg3);
    OPS_kernels[34].transfer += ops_compute_transfer(dim, start, end, &arg4);
    OPS_kernels[34].transfer += ops_compute_transfer(dim, start, end, &arg5);
    OPS_kernels[34].transfer += ops_compute_transfer(dim, start, end, &arg6);
  }
}
