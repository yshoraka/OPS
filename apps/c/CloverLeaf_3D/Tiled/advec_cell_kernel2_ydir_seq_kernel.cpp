//
// auto-generated by ops.py
//
#define OPS_ACC0(x,y,z) (n_x*1+n_y*xdim0_advec_cell_kernel2_ydir*1+n_z*xdim0_advec_cell_kernel2_ydir*ydim0_advec_cell_kernel2_ydir*1+x+xdim0_advec_cell_kernel2_ydir*(y)+xdim0_advec_cell_kernel2_ydir*ydim0_advec_cell_kernel2_ydir*(z))
#define OPS_ACC1(x,y,z) (n_x*1+n_y*xdim1_advec_cell_kernel2_ydir*1+n_z*xdim1_advec_cell_kernel2_ydir*ydim1_advec_cell_kernel2_ydir*1+x+xdim1_advec_cell_kernel2_ydir*(y)+xdim1_advec_cell_kernel2_ydir*ydim1_advec_cell_kernel2_ydir*(z))
#define OPS_ACC2(x,y,z) (n_x*1+n_y*xdim2_advec_cell_kernel2_ydir*1+n_z*xdim2_advec_cell_kernel2_ydir*ydim2_advec_cell_kernel2_ydir*1+x+xdim2_advec_cell_kernel2_ydir*(y)+xdim2_advec_cell_kernel2_ydir*ydim2_advec_cell_kernel2_ydir*(z))
#define OPS_ACC3(x,y,z) (n_x*1+n_y*xdim3_advec_cell_kernel2_ydir*1+n_z*xdim3_advec_cell_kernel2_ydir*ydim3_advec_cell_kernel2_ydir*1+x+xdim3_advec_cell_kernel2_ydir*(y)+xdim3_advec_cell_kernel2_ydir*ydim3_advec_cell_kernel2_ydir*(z))
#define OPS_ACC4(x,y,z) (n_x*1+n_y*xdim4_advec_cell_kernel2_ydir*1+n_z*xdim4_advec_cell_kernel2_ydir*ydim4_advec_cell_kernel2_ydir*1+x+xdim4_advec_cell_kernel2_ydir*(y)+xdim4_advec_cell_kernel2_ydir*ydim4_advec_cell_kernel2_ydir*(z))


//user function

// host stub function
void ops_par_loop_advec_cell_kernel2_ydir_execute(ops_kernel_descriptor *desc) {
  ops_block block = desc->block;
  int dim = desc->dim;
  int *range = desc->range;
  ops_arg arg0 = desc->args[0];
  ops_arg arg1 = desc->args[1];
  ops_arg arg2 = desc->args[2];
  ops_arg arg3 = desc->args[3];
  ops_arg arg4 = desc->args[4];

  //Timing
  double t1,t2,c1,c2;

  ops_arg args[5] = { arg0, arg1, arg2, arg3, arg4};



  #ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args,5,range,12)) return;
  #endif

  if (OPS_diags > 1) {
    OPS_kernels[12].count++;
    ops_timers_core(&c2,&t2);
  }

  //compute locally allocated range for the sub-block
  int start[3];
  int end[3];

  for ( int n=0; n<3; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }

  #ifdef OPS_DEBUG
  ops_register_args(args, "advec_cell_kernel2_ydir");
  #endif



  //set up initial pointers and exchange halos if necessary
  int base0 = args[0].dat->base_offset;
  double * __restrict__ pre_vol = (double *)(args[0].data + base0);

  int base1 = args[1].dat->base_offset;
  double * __restrict__ post_vol = (double *)(args[1].data + base1);

  int base2 = args[2].dat->base_offset;
  const double * __restrict__ volume = (double *)(args[2].data + base2);

  int base3 = args[3].dat->base_offset;
  const double * __restrict__ vol_flux_y = (double *)(args[3].data + base3);

  int base4 = args[4].dat->base_offset;
  const double * __restrict__ vol_flux_x = (double *)(args[4].data + base4);


  //initialize global variable with the dimension of dats
  int xdim0_advec_cell_kernel2_ydir = args[0].dat->size[0];
  int ydim0_advec_cell_kernel2_ydir = args[0].dat->size[1];
  int xdim1_advec_cell_kernel2_ydir = args[1].dat->size[0];
  int ydim1_advec_cell_kernel2_ydir = args[1].dat->size[1];
  int xdim2_advec_cell_kernel2_ydir = args[2].dat->size[0];
  int ydim2_advec_cell_kernel2_ydir = args[2].dat->size[1];
  int xdim3_advec_cell_kernel2_ydir = args[3].dat->size[0];
  int ydim3_advec_cell_kernel2_ydir = args[3].dat->size[1];
  int xdim4_advec_cell_kernel2_ydir = args[4].dat->size[0];
  int ydim4_advec_cell_kernel2_ydir = args[4].dat->size[1];

  if (OPS_diags > 1) {
    ops_timers_core(&c1,&t1);
    OPS_kernels[12].mpi_time += t1-t2;
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
        

  pre_vol[OPS_ACC0(0,0,0)] = volume[OPS_ACC2(0,0,0)] + vol_flux_y[OPS_ACC3(0,1,0)] - vol_flux_y[OPS_ACC3(0,0,0)]
                                                     + vol_flux_x[OPS_ACC4(1,0,0)] - vol_flux_x[OPS_ACC4(0,0,0)];
  post_vol[OPS_ACC1(0,0,0)]= pre_vol[OPS_ACC0(0,0,0)]-(vol_flux_y[OPS_ACC3(0,1,0)] - vol_flux_y[OPS_ACC3(0,0,0)]);


      }
    }
  }
  if (OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    OPS_kernels[12].time += t2-t1;
  }

  if (OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&c1,&t1);
    OPS_kernels[12].mpi_time += t1-t2;
    OPS_kernels[12].transfer += ops_compute_transfer(dim, start, end, &arg0);
    OPS_kernels[12].transfer += ops_compute_transfer(dim, start, end, &arg1);
    OPS_kernels[12].transfer += ops_compute_transfer(dim, start, end, &arg2);
    OPS_kernels[12].transfer += ops_compute_transfer(dim, start, end, &arg3);
    OPS_kernels[12].transfer += ops_compute_transfer(dim, start, end, &arg4);
  }
}
#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4


void ops_par_loop_advec_cell_kernel2_ydir(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)malloc(sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->index = 12;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 12;
  for ( int i=0; i<6; i++ ){
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
  }
  desc->nargs = 5;
  desc->args = (ops_arg*)malloc(5*sizeof(ops_arg));
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
  desc->function = ops_par_loop_advec_cell_kernel2_ydir_execute;
  if (OPS_diags > 1) {
    ops_timing_realloc(12,"advec_cell_kernel2_ydir");
  }
  ops_enqueue_kernel(desc);
  }
