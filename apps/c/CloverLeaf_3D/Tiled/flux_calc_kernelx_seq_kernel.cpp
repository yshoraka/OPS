//
// auto-generated by ops.py
//
#define OPS_ACC0(x,y,z) (n_x*1+n_y*xdim0_flux_calc_kernelx*1+n_z*xdim0_flux_calc_kernelx*ydim0_flux_calc_kernelx*1+x+xdim0_flux_calc_kernelx*(y)+xdim0_flux_calc_kernelx*ydim0_flux_calc_kernelx*(z))
#define OPS_ACC1(x,y,z) (n_x*1+n_y*xdim1_flux_calc_kernelx*1+n_z*xdim1_flux_calc_kernelx*ydim1_flux_calc_kernelx*1+x+xdim1_flux_calc_kernelx*(y)+xdim1_flux_calc_kernelx*ydim1_flux_calc_kernelx*(z))
#define OPS_ACC2(x,y,z) (n_x*1+n_y*xdim2_flux_calc_kernelx*1+n_z*xdim2_flux_calc_kernelx*ydim2_flux_calc_kernelx*1+x+xdim2_flux_calc_kernelx*(y)+xdim2_flux_calc_kernelx*ydim2_flux_calc_kernelx*(z))
#define OPS_ACC3(x,y,z) (n_x*1+n_y*xdim3_flux_calc_kernelx*1+n_z*xdim3_flux_calc_kernelx*ydim3_flux_calc_kernelx*1+x+xdim3_flux_calc_kernelx*(y)+xdim3_flux_calc_kernelx*ydim3_flux_calc_kernelx*(z))


//user function

// host stub function
void ops_par_loop_flux_calc_kernelx_execute(ops_kernel_descriptor *desc) {
  ops_block block = desc->block;
  int dim = desc->dim;
  int *range = desc->range;
  ops_arg arg0 = desc->args[0];
  ops_arg arg1 = desc->args[1];
  ops_arg arg2 = desc->args[2];
  ops_arg arg3 = desc->args[3];

  //Timing
  double t1,t2,c1,c2;

  ops_arg args[4] = { arg0, arg1, arg2, arg3};



  #ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args,4,range,42)) return;
  #endif

  if (OPS_diags > 1) {
    OPS_kernels[42].count++;
    ops_timers_core(&c2,&t2);
  }

  //compute locally allocated range for the sub-block
  int start[3];
  int end[3];

  for ( int n=0; n<3; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }

  #ifdef OPS_DEBUG
  ops_register_args(args, "flux_calc_kernelx");
  #endif



  //set up initial pointers and exchange halos if necessary
  int base0 = args[0].dat->base_offset;
  double * __restrict__ vol_flux_x = (double *)(args[0].data + base0);

  int base1 = args[1].dat->base_offset;
  const double * __restrict__ xarea = (double *)(args[1].data + base1);

  int base2 = args[2].dat->base_offset;
  const double * __restrict__ xvel0 = (double *)(args[2].data + base2);

  int base3 = args[3].dat->base_offset;
  const double * __restrict__ xvel1 = (double *)(args[3].data + base3);


  //initialize global variable with the dimension of dats
  int xdim0_flux_calc_kernelx = args[0].dat->size[0];
  int ydim0_flux_calc_kernelx = args[0].dat->size[1];
  int xdim1_flux_calc_kernelx = args[1].dat->size[0];
  int ydim1_flux_calc_kernelx = args[1].dat->size[1];
  int xdim2_flux_calc_kernelx = args[2].dat->size[0];
  int ydim2_flux_calc_kernelx = args[2].dat->size[1];
  int xdim3_flux_calc_kernelx = args[3].dat->size[0];
  int ydim3_flux_calc_kernelx = args[3].dat->size[1];

  if (OPS_diags > 1) {
    ops_timers_core(&c1,&t1);
    OPS_kernels[42].mpi_time += t1-t2;
  }

  #pragma omp parallel for collapse(2)
  for ( int n_z=start[2]; n_z<end[2]; n_z++ ){
    for ( int n_y=start[1]; n_y<end[1]; n_y++ ){
      #ifdef intel
      #pragma omp simd
      #else
      #pragma simd
      #endif
      for ( int n_x=start[0]; n_x<end[0]; n_x++ ){
        

  vol_flux_x[OPS_ACC0(0,0,0)] = 0.125 * dt * (xarea[OPS_ACC1(0,0,0)]) *
  ( xvel0[OPS_ACC2(0,0,0)] + xvel0[OPS_ACC2(0,1,0)] + xvel0[OPS_ACC2(0,0,1)] + xvel0[OPS_ACC2(0,1,1)] +
    xvel1[OPS_ACC3(0,0,0)] + xvel1[OPS_ACC3(0,1,0)] + xvel1[OPS_ACC3(0,0,1)] + xvel1[OPS_ACC3(0,1,1)]);

      }
    }
  }
  if (OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    OPS_kernels[42].time += t2-t1;
  }

  if (OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&c1,&t1);
    OPS_kernels[42].mpi_time += t1-t2;
    OPS_kernels[42].transfer += ops_compute_transfer(dim, start, end, &arg0);
    OPS_kernels[42].transfer += ops_compute_transfer(dim, start, end, &arg1);
    OPS_kernels[42].transfer += ops_compute_transfer(dim, start, end, &arg2);
    OPS_kernels[42].transfer += ops_compute_transfer(dim, start, end, &arg3);
  }
}
#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3


void ops_par_loop_flux_calc_kernelx(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)malloc(sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->index = 42;
  for ( int i=0; i<6; i++ ){
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
  }
  desc->nargs = 4;
  desc->args = (ops_arg*)malloc(4*sizeof(ops_arg));
  desc->args[0] = arg0;
  desc->args[1] = arg1;
  desc->args[2] = arg2;
  desc->args[3] = arg3;
  desc->function = ops_par_loop_flux_calc_kernelx_execute;
  if (OPS_diags > 1) {
    ops_timing_realloc(42,"flux_calc_kernelx");
  }
  ops_enqueue_kernel(desc);
  }
