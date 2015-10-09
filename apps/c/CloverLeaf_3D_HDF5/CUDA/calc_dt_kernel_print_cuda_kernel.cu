//
// auto-generated by ops.py
//
__constant__ int xdim0_calc_dt_kernel_print;
int xdim0_calc_dt_kernel_print_h = -1;
__constant__ int ydim0_calc_dt_kernel_print;
int ydim0_calc_dt_kernel_print_h = -1;
__constant__ int xdim1_calc_dt_kernel_print;
int xdim1_calc_dt_kernel_print_h = -1;
__constant__ int ydim1_calc_dt_kernel_print;
int ydim1_calc_dt_kernel_print_h = -1;
__constant__ int xdim2_calc_dt_kernel_print;
int xdim2_calc_dt_kernel_print_h = -1;
__constant__ int ydim2_calc_dt_kernel_print;
int ydim2_calc_dt_kernel_print_h = -1;
__constant__ int xdim3_calc_dt_kernel_print;
int xdim3_calc_dt_kernel_print_h = -1;
__constant__ int ydim3_calc_dt_kernel_print;
int ydim3_calc_dt_kernel_print_h = -1;
__constant__ int xdim4_calc_dt_kernel_print;
int xdim4_calc_dt_kernel_print_h = -1;
__constant__ int ydim4_calc_dt_kernel_print;
int ydim4_calc_dt_kernel_print_h = -1;
__constant__ int xdim5_calc_dt_kernel_print;
int xdim5_calc_dt_kernel_print_h = -1;
__constant__ int ydim5_calc_dt_kernel_print;
int ydim5_calc_dt_kernel_print_h = -1;
__constant__ int xdim6_calc_dt_kernel_print;
int xdim6_calc_dt_kernel_print_h = -1;
__constant__ int ydim6_calc_dt_kernel_print;
int ydim6_calc_dt_kernel_print_h = -1;

#define OPS_ACC0(x,y,z) (x+xdim0_calc_dt_kernel_print*(y)+xdim0_calc_dt_kernel_print*ydim0_calc_dt_kernel_print*(z))
#define OPS_ACC1(x,y,z) (x+xdim1_calc_dt_kernel_print*(y)+xdim1_calc_dt_kernel_print*ydim1_calc_dt_kernel_print*(z))
#define OPS_ACC2(x,y,z) (x+xdim2_calc_dt_kernel_print*(y)+xdim2_calc_dt_kernel_print*ydim2_calc_dt_kernel_print*(z))
#define OPS_ACC3(x,y,z) (x+xdim3_calc_dt_kernel_print*(y)+xdim3_calc_dt_kernel_print*ydim3_calc_dt_kernel_print*(z))
#define OPS_ACC4(x,y,z) (x+xdim4_calc_dt_kernel_print*(y)+xdim4_calc_dt_kernel_print*ydim4_calc_dt_kernel_print*(z))
#define OPS_ACC5(x,y,z) (x+xdim5_calc_dt_kernel_print*(y)+xdim5_calc_dt_kernel_print*ydim5_calc_dt_kernel_print*(z))
#define OPS_ACC6(x,y,z) (x+xdim6_calc_dt_kernel_print*(y)+xdim6_calc_dt_kernel_print*ydim6_calc_dt_kernel_print*(z))

//user function
__device__

void calc_dt_kernel_print(const double *xvel0, const double *yvel0, const double *zvel0,
                        const double *density0, const double *energy0,
                        const double *pressure, const double *soundspeed, double *output) {
  output[0] = xvel0[OPS_ACC0(0,0,0)];
  output[1] = yvel0[OPS_ACC1(0,0,0)];
  output[2] = zvel0[OPS_ACC2(0,0,0)];
  output[3] = xvel0[OPS_ACC0(1,0,0)];
  output[4] = yvel0[OPS_ACC1(1,0,0)];
  output[5] = zvel0[OPS_ACC2(0,0,0)];
  output[6] = xvel0[OPS_ACC0(1,1,0)];
  output[7] = yvel0[OPS_ACC1(1,1,0)];
  output[8] = zvel0[OPS_ACC2(0,0,0)];
  output[9] = xvel0[OPS_ACC0(0,1,0)];
  output[10] = yvel0[OPS_ACC1(0,1,0)];
  output[11] = zvel0[OPS_ACC2(0,0,0)];
  output[12] = xvel0[OPS_ACC0(0,0,1)];
  output[13] = yvel0[OPS_ACC1(0,0,1)];
  output[14] = zvel0[OPS_ACC2(0,0,1)];
  output[15] = xvel0[OPS_ACC0(1,0,1)];
  output[16] = yvel0[OPS_ACC1(1,0,1)];
  output[17] = zvel0[OPS_ACC2(0,0,1)];
  output[18] = xvel0[OPS_ACC0(1,1,1)];
  output[19] = yvel0[OPS_ACC1(1,1,1)];
  output[20] = zvel0[OPS_ACC2(0,0,1)];
  output[21] = xvel0[OPS_ACC0(0,1,1)];
  output[22] = yvel0[OPS_ACC1(0,1,1)];
  output[23] = zvel0[OPS_ACC2(0,0,1)];
  output[24] = density0[OPS_ACC3(0,0,0)];
  output[25] = energy0[OPS_ACC4(0,0,0)];
  output[26] = pressure[OPS_ACC5(0,0,0)];
  output[27] = soundspeed[OPS_ACC6(0,0,0)];

}



#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4
#undef OPS_ACC5
#undef OPS_ACC6


__global__ void ops_calc_dt_kernel_print(
const double* __restrict arg0,
const double* __restrict arg1,
const double* __restrict arg2,
const double* __restrict arg3,
const double* __restrict arg4,
const double* __restrict arg5,
const double* __restrict arg6,
double* __restrict arg7,
int size0,
int size1,
int size2 ){

  double arg7_l[28];
  for (int d=0; d<28; d++) arg7_l[d] = ZERO_double;

  int idx_z = blockDim.z * blockIdx.z + threadIdx.z;
  int idx_y = blockDim.y * blockIdx.y + threadIdx.y;
  int idx_x = blockDim.x * blockIdx.x + threadIdx.x;

  arg0 += idx_x * 1*1 + idx_y * 1*1 * xdim0_calc_dt_kernel_print + idx_z * 1*1 * xdim0_calc_dt_kernel_print * ydim0_calc_dt_kernel_print;
  arg1 += idx_x * 1*1 + idx_y * 1*1 * xdim1_calc_dt_kernel_print + idx_z * 1*1 * xdim1_calc_dt_kernel_print * ydim1_calc_dt_kernel_print;
  arg2 += idx_x * 1*1 + idx_y * 1*1 * xdim2_calc_dt_kernel_print + idx_z * 1*1 * xdim2_calc_dt_kernel_print * ydim2_calc_dt_kernel_print;
  arg3 += idx_x * 1*1 + idx_y * 1*1 * xdim3_calc_dt_kernel_print + idx_z * 1*1 * xdim3_calc_dt_kernel_print * ydim3_calc_dt_kernel_print;
  arg4 += idx_x * 1*1 + idx_y * 1*1 * xdim4_calc_dt_kernel_print + idx_z * 1*1 * xdim4_calc_dt_kernel_print * ydim4_calc_dt_kernel_print;
  arg5 += idx_x * 1*1 + idx_y * 1*1 * xdim5_calc_dt_kernel_print + idx_z * 1*1 * xdim5_calc_dt_kernel_print * ydim5_calc_dt_kernel_print;
  arg6 += idx_x * 1*1 + idx_y * 1*1 * xdim6_calc_dt_kernel_print + idx_z * 1*1 * xdim6_calc_dt_kernel_print * ydim6_calc_dt_kernel_print;

  if (idx_x < size0 && idx_y < size1 && idx_z < size2) {
    calc_dt_kernel_print(arg0, arg1, arg2, arg3,
                   arg4, arg5, arg6, arg7_l);
  }
  for (int d=0; d<28; d++)
    ops_reduction_cuda<OPS_INC>(&arg7[d+(blockIdx.x + blockIdx.y*gridDim.x + blockIdx.z*gridDim.x*gridDim.y)*28],arg7_l[d]);

}

// host stub function
void ops_par_loop_calc_dt_kernel_print(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5, ops_arg arg6, ops_arg arg7) {

  //Timing
  double t1,t2,c1,c2;

  ops_arg args[8] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7};


  #ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args,8,range,40)) return;
  #endif

  if (OPS_diags > 1) {
    ops_timing_realloc(40,"calc_dt_kernel_print");
    OPS_kernels[40].count++;
    ops_timers_core(&c1,&t1);
  }

  //compute locally allocated range for the sub-block
  int start[3];
  int end[3];
  #ifdef OPS_MPI
  sub_block_list sb = OPS_sub_block_list[block->index];
  if (!sb->owned) return;
  for ( int n=0; n<3; n++ ){
    start[n] = sb->decomp_disp[n];end[n] = sb->decomp_disp[n]+sb->decomp_size[n];
    if (start[n] >= range[2*n]) {
      start[n] = 0;
    }
    else {
      start[n] = range[2*n] - start[n];
    }
    if (sb->id_m[n]==MPI_PROC_NULL && range[2*n] < 0) start[n] = range[2*n];
    if (end[n] >= range[2*n+1]) {
      end[n] = range[2*n+1] - sb->decomp_disp[n];
    }
    else {
      end[n] = sb->decomp_size[n];
    }
    if (sb->id_p[n]==MPI_PROC_NULL && (range[2*n+1] > sb->decomp_disp[n]+sb->decomp_size[n]))
      end[n] += (range[2*n+1]-sb->decomp_disp[n]-sb->decomp_size[n]);
  }
  #else //OPS_MPI
  for ( int n=0; n<3; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }
  #endif //OPS_MPI

  int x_size = MAX(0,end[0]-start[0]);
  int y_size = MAX(0,end[1]-start[1]);
  int z_size = MAX(0,end[2]-start[2]);

  int xdim0 = args[0].dat->size[0];
  int ydim0 = args[0].dat->size[1];
  int xdim1 = args[1].dat->size[0];
  int ydim1 = args[1].dat->size[1];
  int xdim2 = args[2].dat->size[0];
  int ydim2 = args[2].dat->size[1];
  int xdim3 = args[3].dat->size[0];
  int ydim3 = args[3].dat->size[1];
  int xdim4 = args[4].dat->size[0];
  int ydim4 = args[4].dat->size[1];
  int xdim5 = args[5].dat->size[0];
  int ydim5 = args[5].dat->size[1];
  int xdim6 = args[6].dat->size[0];
  int ydim6 = args[6].dat->size[1];

  if (xdim0 != xdim0_calc_dt_kernel_print_h || ydim0 != ydim0_calc_dt_kernel_print_h || xdim1 != xdim1_calc_dt_kernel_print_h || ydim1 != ydim1_calc_dt_kernel_print_h || xdim2 != xdim2_calc_dt_kernel_print_h || ydim2 != ydim2_calc_dt_kernel_print_h || xdim3 != xdim3_calc_dt_kernel_print_h || ydim3 != ydim3_calc_dt_kernel_print_h || xdim4 != xdim4_calc_dt_kernel_print_h || ydim4 != ydim4_calc_dt_kernel_print_h || xdim5 != xdim5_calc_dt_kernel_print_h || ydim5 != ydim5_calc_dt_kernel_print_h || xdim6 != xdim6_calc_dt_kernel_print_h || ydim6 != ydim6_calc_dt_kernel_print_h) {
    cudaMemcpyToSymbol( xdim0_calc_dt_kernel_print, &xdim0, sizeof(int) );
    xdim0_calc_dt_kernel_print_h = xdim0;
    cudaMemcpyToSymbol( ydim0_calc_dt_kernel_print, &ydim0, sizeof(int) );
    ydim0_calc_dt_kernel_print_h = ydim0;
    cudaMemcpyToSymbol( xdim1_calc_dt_kernel_print, &xdim1, sizeof(int) );
    xdim1_calc_dt_kernel_print_h = xdim1;
    cudaMemcpyToSymbol( ydim1_calc_dt_kernel_print, &ydim1, sizeof(int) );
    ydim1_calc_dt_kernel_print_h = ydim1;
    cudaMemcpyToSymbol( xdim2_calc_dt_kernel_print, &xdim2, sizeof(int) );
    xdim2_calc_dt_kernel_print_h = xdim2;
    cudaMemcpyToSymbol( ydim2_calc_dt_kernel_print, &ydim2, sizeof(int) );
    ydim2_calc_dt_kernel_print_h = ydim2;
    cudaMemcpyToSymbol( xdim3_calc_dt_kernel_print, &xdim3, sizeof(int) );
    xdim3_calc_dt_kernel_print_h = xdim3;
    cudaMemcpyToSymbol( ydim3_calc_dt_kernel_print, &ydim3, sizeof(int) );
    ydim3_calc_dt_kernel_print_h = ydim3;
    cudaMemcpyToSymbol( xdim4_calc_dt_kernel_print, &xdim4, sizeof(int) );
    xdim4_calc_dt_kernel_print_h = xdim4;
    cudaMemcpyToSymbol( ydim4_calc_dt_kernel_print, &ydim4, sizeof(int) );
    ydim4_calc_dt_kernel_print_h = ydim4;
    cudaMemcpyToSymbol( xdim5_calc_dt_kernel_print, &xdim5, sizeof(int) );
    xdim5_calc_dt_kernel_print_h = xdim5;
    cudaMemcpyToSymbol( ydim5_calc_dt_kernel_print, &ydim5, sizeof(int) );
    ydim5_calc_dt_kernel_print_h = ydim5;
    cudaMemcpyToSymbol( xdim6_calc_dt_kernel_print, &xdim6, sizeof(int) );
    xdim6_calc_dt_kernel_print_h = xdim6;
    cudaMemcpyToSymbol( ydim6_calc_dt_kernel_print, &ydim6, sizeof(int) );
    ydim6_calc_dt_kernel_print_h = ydim6;
  }


  #ifdef OPS_MPI
  double *arg7h = (double *)(((ops_reduction)args[7].data)->data + ((ops_reduction)args[7].data)->size * block->index);
  #else //OPS_MPI
  double *arg7h = (double *)(((ops_reduction)args[7].data)->data);
  #endif //OPS_MPI

  dim3 grid( (x_size-1)/OPS_block_size_x+ 1, (y_size-1)/OPS_block_size_y + 1, z_size);
  dim3 tblock(OPS_block_size_x,OPS_block_size_y,1);

  int nblocks = ((x_size-1)/OPS_block_size_x+ 1)*((y_size-1)/OPS_block_size_y + 1)*z_size;
  int maxblocks = nblocks;
  int reduct_bytes = 0;
  int reduct_size = 0;

  reduct_bytes += ROUND_UP(maxblocks*28*sizeof(double));
  reduct_size = MAX(reduct_size,sizeof(double)*28);

  reallocReductArrays(reduct_bytes);
  reduct_bytes = 0;

  arg7.data = OPS_reduct_h + reduct_bytes;
  arg7.data_d = OPS_reduct_d + reduct_bytes;
  for (int b=0; b<maxblocks; b++)
  for (int d=0; d<28; d++) ((double *)arg7.data)[d+b*28] = ZERO_double;
  reduct_bytes += ROUND_UP(maxblocks*28*sizeof(double));


  mvReductArraysToDevice(reduct_bytes);
  int dat0 = args[0].dat->elem_size;
  int dat1 = args[1].dat->elem_size;
  int dat2 = args[2].dat->elem_size;
  int dat3 = args[3].dat->elem_size;
  int dat4 = args[4].dat->elem_size;
  int dat5 = args[5].dat->elem_size;
  int dat6 = args[6].dat->elem_size;

  char *p_a[8];

  //set up initial pointers
  int d_m[OPS_MAX_DIM];
  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[0].dat->d_m[d] + OPS_sub_dat_list[args[0].dat->index]->d_im[d];
  #else //OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[0].dat->d_m[d];
  #endif //OPS_MPI
  int base0 = dat0 * 1 *
  (start[0] * args[0].stencil->stride[0] - args[0].dat->base[0] - d_m[0]);
  base0 = base0+ dat0 *
    args[0].dat->size[0] *
    (start[1] * args[0].stencil->stride[1] - args[0].dat->base[1] - d_m[1]);
  base0 = base0+ dat0 *
    args[0].dat->size[0] *
    args[0].dat->size[1] *
    (start[2] * args[0].stencil->stride[2] - args[0].dat->base[2] - d_m[2]);
  p_a[0] = (char *)args[0].data_d + base0;

  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[1].dat->d_m[d] + OPS_sub_dat_list[args[1].dat->index]->d_im[d];
  #else //OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[1].dat->d_m[d];
  #endif //OPS_MPI
  int base1 = dat1 * 1 *
  (start[0] * args[1].stencil->stride[0] - args[1].dat->base[0] - d_m[0]);
  base1 = base1+ dat1 *
    args[1].dat->size[0] *
    (start[1] * args[1].stencil->stride[1] - args[1].dat->base[1] - d_m[1]);
  base1 = base1+ dat1 *
    args[1].dat->size[0] *
    args[1].dat->size[1] *
    (start[2] * args[1].stencil->stride[2] - args[1].dat->base[2] - d_m[2]);
  p_a[1] = (char *)args[1].data_d + base1;

  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[2].dat->d_m[d] + OPS_sub_dat_list[args[2].dat->index]->d_im[d];
  #else //OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[2].dat->d_m[d];
  #endif //OPS_MPI
  int base2 = dat2 * 1 *
  (start[0] * args[2].stencil->stride[0] - args[2].dat->base[0] - d_m[0]);
  base2 = base2+ dat2 *
    args[2].dat->size[0] *
    (start[1] * args[2].stencil->stride[1] - args[2].dat->base[1] - d_m[1]);
  base2 = base2+ dat2 *
    args[2].dat->size[0] *
    args[2].dat->size[1] *
    (start[2] * args[2].stencil->stride[2] - args[2].dat->base[2] - d_m[2]);
  p_a[2] = (char *)args[2].data_d + base2;

  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[3].dat->d_m[d] + OPS_sub_dat_list[args[3].dat->index]->d_im[d];
  #else //OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[3].dat->d_m[d];
  #endif //OPS_MPI
  int base3 = dat3 * 1 *
  (start[0] * args[3].stencil->stride[0] - args[3].dat->base[0] - d_m[0]);
  base3 = base3+ dat3 *
    args[3].dat->size[0] *
    (start[1] * args[3].stencil->stride[1] - args[3].dat->base[1] - d_m[1]);
  base3 = base3+ dat3 *
    args[3].dat->size[0] *
    args[3].dat->size[1] *
    (start[2] * args[3].stencil->stride[2] - args[3].dat->base[2] - d_m[2]);
  p_a[3] = (char *)args[3].data_d + base3;

  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[4].dat->d_m[d] + OPS_sub_dat_list[args[4].dat->index]->d_im[d];
  #else //OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[4].dat->d_m[d];
  #endif //OPS_MPI
  int base4 = dat4 * 1 *
  (start[0] * args[4].stencil->stride[0] - args[4].dat->base[0] - d_m[0]);
  base4 = base4+ dat4 *
    args[4].dat->size[0] *
    (start[1] * args[4].stencil->stride[1] - args[4].dat->base[1] - d_m[1]);
  base4 = base4+ dat4 *
    args[4].dat->size[0] *
    args[4].dat->size[1] *
    (start[2] * args[4].stencil->stride[2] - args[4].dat->base[2] - d_m[2]);
  p_a[4] = (char *)args[4].data_d + base4;

  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[5].dat->d_m[d] + OPS_sub_dat_list[args[5].dat->index]->d_im[d];
  #else //OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[5].dat->d_m[d];
  #endif //OPS_MPI
  int base5 = dat5 * 1 *
  (start[0] * args[5].stencil->stride[0] - args[5].dat->base[0] - d_m[0]);
  base5 = base5+ dat5 *
    args[5].dat->size[0] *
    (start[1] * args[5].stencil->stride[1] - args[5].dat->base[1] - d_m[1]);
  base5 = base5+ dat5 *
    args[5].dat->size[0] *
    args[5].dat->size[1] *
    (start[2] * args[5].stencil->stride[2] - args[5].dat->base[2] - d_m[2]);
  p_a[5] = (char *)args[5].data_d + base5;

  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[6].dat->d_m[d] + OPS_sub_dat_list[args[6].dat->index]->d_im[d];
  #else //OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[6].dat->d_m[d];
  #endif //OPS_MPI
  int base6 = dat6 * 1 *
  (start[0] * args[6].stencil->stride[0] - args[6].dat->base[0] - d_m[0]);
  base6 = base6+ dat6 *
    args[6].dat->size[0] *
    (start[1] * args[6].stencil->stride[1] - args[6].dat->base[1] - d_m[1]);
  base6 = base6+ dat6 *
    args[6].dat->size[0] *
    args[6].dat->size[1] *
    (start[2] * args[6].stencil->stride[2] - args[6].dat->base[2] - d_m[2]);
  p_a[6] = (char *)args[6].data_d + base6;


  ops_H_D_exchanges_device(args, 8);
  ops_halo_exchanges(args,8,range);

  if (OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    OPS_kernels[40].mpi_time += t2-t1;
  }

  int nshared = 0;
  int nthread = OPS_block_size_x*OPS_block_size_y;

  nshared = MAX(nshared,sizeof(double)*28);

  nshared = MAX(nshared*nthread,reduct_size*nthread);

  //call kernel wrapper function, passing in pointers to data
  ops_calc_dt_kernel_print<<<grid, tblock, nshared >>> (  (double *)p_a[0], (double *)p_a[1],
           (double *)p_a[2], (double *)p_a[3],
           (double *)p_a[4], (double *)p_a[5],
           (double *)p_a[6], (double *)arg7.data_d,x_size, y_size, z_size);

  mvReductArraysToHost(reduct_bytes);
  for ( int b=0; b<maxblocks; b++ ){
    for ( int d=0; d<28; d++ ){
      arg7h[d] = arg7h[d] + ((double *)arg7.data)[d+b*28];
    }
  }
  arg7.data = (char *)arg7h;

  if (OPS_diags>1) {
    cutilSafeCall(cudaDeviceSynchronize());
    ops_timers_core(&c1,&t1);
    OPS_kernels[40].time += t1-t2;
  }

  ops_set_dirtybit_device(args, 8);

  if (OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&c2,&t2);
    OPS_kernels[40].mpi_time += t2-t1;
    OPS_kernels[40].transfer += ops_compute_transfer(dim, range, &arg0);
    OPS_kernels[40].transfer += ops_compute_transfer(dim, range, &arg1);
    OPS_kernels[40].transfer += ops_compute_transfer(dim, range, &arg2);
    OPS_kernels[40].transfer += ops_compute_transfer(dim, range, &arg3);
    OPS_kernels[40].transfer += ops_compute_transfer(dim, range, &arg4);
    OPS_kernels[40].transfer += ops_compute_transfer(dim, range, &arg5);
    OPS_kernels[40].transfer += ops_compute_transfer(dim, range, &arg6);
  }
}
