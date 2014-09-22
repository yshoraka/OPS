//
// auto-generated by ops.py//




#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "ops_seq_mgrid.h"

//#include "mgrid_populate_kernel.h"
void ops_par_loop_mgrid_prolong_kernel(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2);

void ops_par_loop_mgrid_populate_kernel_1(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1);

void ops_par_loop_mgrid_populate_kernel_2(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1);

int main(int argc, char **argv)
{


  ops_init(argc,argv,2);

  ops_block grid0 = ops_decl_block(2, "grid0");


  int s2D_00[]         = {0,0};
  ops_stencil S2D_00 = ops_decl_stencil( 2, 1, s2D_00, "00");


  int d_p[2] = {2,2};
  int d_m[2] = {-2,-2};
  int size0[2] = {12, 12};
  int size1[2] = {6, 6};
  int size2[2] = {4, 4};
  
  int stride0[2] = {1, 1};
  int stride1[2] = {2, 2};
  int stride2[2] = {3, 3};
  
  int base[2] = {0,0};
  double* temp = NULL;

  ops_dat data0 = ops_decl_dat(grid0, 1, size0, base, d_m, d_p, stride0 , temp, "double", "data0");
  ops_dat data1 = ops_decl_dat(grid0, 1, size1, base, d_m, d_p, stride1 , temp, "double", "data1");
  ops_dat data2 = ops_decl_dat(grid0, 1, size2, base, d_m, d_p, stride2 , temp, "double", "data2");
  
  ops_partition("");


  double ct0, ct1, et0, et1;
  ops_timers_core(&ct0, &et0);

  int iter_range[] = {0,12,0,12};
  int iter_range_small[] = {0,6,0,6};
  int iter_range_tiny[] = {0,4,0,4};




  ops_par_loop_mgrid_populate_kernel_1("mgrid_populate_kernel_1", grid0, 2, iter_range_small,
               ops_arg_dat(data1, S2D_00, "double", OPS_WRITE),
               ops_arg_idx());
  
  ops_par_loop_mgrid_populate_kernel_2("mgrid_populate_kernel_2", grid0, 2, iter_range_tiny,
               ops_arg_dat(data2, S2D_00, "double", OPS_WRITE),
               ops_arg_idx());

  ops_par_loop_mgrid_prolong_kernel("mgrid_prolong_kernel", grid0, 2, iter_range,
               ops_arg_dat(data1, S2D_00, "double", OPS_READ),
               //ops_arg_dat(data2, S2D_00, "double", OPS_READ),
               ops_arg_dat(data0, S2D_00, "double", OPS_WRITE),
               ops_arg_idx());
  
  ops_print_dat_to_txtfile(data1, "data.txt");
  //ops_print_dat_to_txtfile(data2, "data.txt");
  ops_print_dat_to_txtfile(data0, "data.txt");






  ops_timers_core(&ct1, &et1);
  ops_timing_output();

  ops_printf("\nTotal Wall time %lf\n",et1-et0);

  ops_exit();
}
