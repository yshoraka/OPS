//
// auto-generated by ops.py
//
#define OPS_ACC0(x,y) (n_x*1+n_y*xdim0_calc_dt_kernel*0+x+xdim0_calc_dt_kernel*(y))
#define OPS_ACC1(x,y) (n_x*0+n_y*xdim1_calc_dt_kernel*1+x+xdim1_calc_dt_kernel*(y))
#define OPS_ACC2(x,y) (n_x*1+n_y*xdim2_calc_dt_kernel*1+x+xdim2_calc_dt_kernel*(y))
#define OPS_ACC3(x,y) (n_x*1+n_y*xdim3_calc_dt_kernel*1+x+xdim3_calc_dt_kernel*(y))
#define OPS_ACC4(x,y) (n_x*1+n_y*xdim4_calc_dt_kernel*1+x+xdim4_calc_dt_kernel*(y))
#define OPS_ACC5(x,y) (n_x*1+n_y*xdim5_calc_dt_kernel*1+x+xdim5_calc_dt_kernel*(y))
#define OPS_ACC6(x,y) (n_x*1+n_y*xdim6_calc_dt_kernel*1+x+xdim6_calc_dt_kernel*(y))
#define OPS_ACC7(x,y) (n_x*1+n_y*xdim7_calc_dt_kernel*1+x+xdim7_calc_dt_kernel*(y))
#define OPS_ACC8(x,y) (n_x*1+n_y*xdim8_calc_dt_kernel*1+x+xdim8_calc_dt_kernel*(y))
#define OPS_ACC9(x,y) (n_x*1+n_y*xdim9_calc_dt_kernel*1+x+xdim9_calc_dt_kernel*(y))
#define OPS_ACC10(x,y) (n_x*1+n_y*xdim10_calc_dt_kernel*1+x+xdim10_calc_dt_kernel*(y))


//user function

// host stub function
void ops_par_loop_calc_dt_kernel_execute(ops_kernel_descriptor *desc) {
  ops_block block = desc->block;
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

  //Timing
  double t1,t2,c1,c2;

  ops_arg args[11] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10};



  #ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args,11,range,27)) return;
  #endif

  if (OPS_diags > 1) {
    OPS_kernels[27].count++;
    ops_timers_core(&c2,&t2);
  }

  //compute locally allocated range for the sub-block
  int start[2];
  int end[2];

  for ( int n=0; n<2; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }

  #ifdef OPS_DEBUG
  ops_register_args(args, "calc_dt_kernel");
  #endif



  //set up initial pointers and exchange halos if necessary
  int base0 = args[0].dat->base_offset;
  const double * __restrict__ celldx = (double *)(args[0].data + base0);

  int base1 = args[1].dat->base_offset;
  const double * __restrict__ celldy = (double *)(args[1].data + base1);

  int base2 = args[2].dat->base_offset;
  const double * __restrict__ soundspeed = (double *)(args[2].data + base2);

  int base3 = args[3].dat->base_offset;
  const double * __restrict__ viscosity = (double *)(args[3].data + base3);

  int base4 = args[4].dat->base_offset;
  const double * __restrict__ density0 = (double *)(args[4].data + base4);

  int base5 = args[5].dat->base_offset;
  const double * __restrict__ xvel0 = (double *)(args[5].data + base5);

  int base6 = args[6].dat->base_offset;
  const double * __restrict__ xarea = (double *)(args[6].data + base6);

  int base7 = args[7].dat->base_offset;
  const double * __restrict__ volume = (double *)(args[7].data + base7);

  int base8 = args[8].dat->base_offset;
  const double * __restrict__ yvel0 = (double *)(args[8].data + base8);

  int base9 = args[9].dat->base_offset;
  const double * __restrict__ yarea = (double *)(args[9].data + base9);

  int base10 = args[10].dat->base_offset;
  double * __restrict__ dt_min = (double *)(args[10].data + base10);


  //initialize global variable with the dimension of dats
  int xdim0_calc_dt_kernel = args[0].dat->size[0];
  int xdim1_calc_dt_kernel = args[1].dat->size[0];
  int xdim2_calc_dt_kernel = args[2].dat->size[0];
  int xdim3_calc_dt_kernel = args[3].dat->size[0];
  int xdim4_calc_dt_kernel = args[4].dat->size[0];
  int xdim5_calc_dt_kernel = args[5].dat->size[0];
  int xdim6_calc_dt_kernel = args[6].dat->size[0];
  int xdim7_calc_dt_kernel = args[7].dat->size[0];
  int xdim8_calc_dt_kernel = args[8].dat->size[0];
  int xdim9_calc_dt_kernel = args[9].dat->size[0];
  int xdim10_calc_dt_kernel = args[10].dat->size[0];

  if (OPS_diags > 1) {
    ops_timers_core(&c1,&t1);
    OPS_kernels[27].mpi_time += t1-t2;
  }

  #pragma omp parallel for
  for ( int n_y=start[1]; n_y<end[1]; n_y++ ){
    #ifdef intel
    #pragma omp simd
    #else
    #pragma simd
    #endif
    for ( int n_x=start[0]; n_x<end[0]; n_x++ ){
      

  double div, dsx, dsy, dtut, dtvt, dtct, dtdivt, cc, dv1, dv2;

  dsx = celldx[OPS_ACC0(0,0)];
  dsy = celldy[OPS_ACC1(0,0)];

  cc = soundspeed[OPS_ACC2(0,0)] * soundspeed[OPS_ACC2(0,0)];
  cc = cc + 2.0 * viscosity[OPS_ACC3(0,0)]/density0[OPS_ACC4(0,0)];
  cc = MAX(sqrt(cc),g_small);

  dtct = dtc_safe * MIN(dsx,dsy)/cc;

  div=0.0;


  dv1 = (xvel0[OPS_ACC5(0,0)] + xvel0[OPS_ACC5(0,1)]) * xarea[OPS_ACC6(0,0)];
  dv2 = (xvel0[OPS_ACC5(1,0)] + xvel0[OPS_ACC5(1,1)]) * xarea[OPS_ACC6(1,0)];

  div = div + dv2 - dv1;

  dtut = dtu_safe * 2.0 * volume[OPS_ACC7(0,0)]/MAX(MAX(fabs(dv1), fabs(dv2)), g_small * volume[OPS_ACC7(0,0)]);

  dv1 = (yvel0[OPS_ACC8(0,0)] + yvel0[OPS_ACC8(1,0)]) * yarea[OPS_ACC9(0,0)];
  dv2 = (yvel0[OPS_ACC8(0,1)] + yvel0[OPS_ACC8(1,1)]) * yarea[OPS_ACC9(0,1)];

  div = div + dv2 - dv1;

  dtvt = dtv_safe * 2.0 * volume[OPS_ACC7(0,0)]/MAX(MAX(fabs(dv1),fabs(dv2)), g_small * volume[OPS_ACC7(0,0)]);

  div = div/(2.0 * volume[OPS_ACC7(0,0)]);

  if(div < -g_small)
    dtdivt = dtdiv_safe * (-1.0/div);
  else
    dtdivt = g_big;

  dt_min[OPS_ACC10(0,0)] = MIN(MIN(dtct, dtut), MIN(dtvt, dtdivt));



    }
  }
  if (OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    OPS_kernels[27].time += t2-t1;
  }

  if (OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&c1,&t1);
    OPS_kernels[27].mpi_time += t1-t2;
    OPS_kernels[27].transfer += ops_compute_transfer(dim, start, end, &arg0);
    OPS_kernels[27].transfer += ops_compute_transfer(dim, start, end, &arg1);
    OPS_kernels[27].transfer += ops_compute_transfer(dim, start, end, &arg2);
    OPS_kernels[27].transfer += ops_compute_transfer(dim, start, end, &arg3);
    OPS_kernels[27].transfer += ops_compute_transfer(dim, start, end, &arg4);
    OPS_kernels[27].transfer += ops_compute_transfer(dim, start, end, &arg5);
    OPS_kernels[27].transfer += ops_compute_transfer(dim, start, end, &arg6);
    OPS_kernels[27].transfer += ops_compute_transfer(dim, start, end, &arg7);
    OPS_kernels[27].transfer += ops_compute_transfer(dim, start, end, &arg8);
    OPS_kernels[27].transfer += ops_compute_transfer(dim, start, end, &arg9);
    OPS_kernels[27].transfer += ops_compute_transfer(dim, start, end, &arg10);
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


void ops_par_loop_calc_dt_kernel(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5, ops_arg arg6, ops_arg arg7,
 ops_arg arg8, ops_arg arg9, ops_arg arg10) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)malloc(sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->index = 27;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 27;
  for ( int i=0; i<4; i++ ){
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
  }
  desc->nargs = 11;
  desc->args = (ops_arg*)malloc(11*sizeof(ops_arg));
  desc->args[0] = arg0;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg0.dat->index;
  desc->args[1] = arg1;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg1.dat->index;
  desc->args[2] = arg2;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg2.dat->index;
  desc->args[3] = arg3;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg3.dat->index;
  desc->args[4] = arg4;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg4.dat->index;
  desc->args[5] = arg5;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg5.dat->index;
  desc->args[6] = arg6;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg6.dat->index;
  desc->args[7] = arg7;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg7.dat->index;
  desc->args[8] = arg8;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg8.dat->index;
  desc->args[9] = arg9;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg9.dat->index;
  desc->args[10] = arg10;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg10.dat->index;
  desc->function = ops_par_loop_calc_dt_kernel_execute;
  if (OPS_diags > 1) {
    ops_timing_realloc(27,"calc_dt_kernel");
  }
  ops_enqueue_kernel(desc);
  }
