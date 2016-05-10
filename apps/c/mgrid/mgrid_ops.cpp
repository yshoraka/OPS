//
// auto-generated by ops.py//




#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include  "ops_lib_cpp.h"

//
// ops_par_loop declarations
//

void ops_par_loop_mgrid_populate_kernel_1(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg );

void ops_par_loop_mgrid_prolong_kernel(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg,
  ops_arg );

void ops_par_loop_mgrid_prolong_kernel(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg,
  ops_arg );

void ops_par_loop_mgrid_populate_kernel_3(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg );

void ops_par_loop_mgrid_restrict_kernel(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg,
  ops_arg );

void ops_par_loop_mgrid_restrict_kernel(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg,
  ops_arg );



//#include "mgrid_populate_kernel.h"

int main(int argc, char **argv)
{


  ops_init(argc,argv,2);

  ops_block grid0 = ops_decl_block(2, "grid0");


  int s2D_00[]         = {0,0};
  int s2D_00_M10_P10[]         = {0,0,-1,0,1,0};
  ops_stencil S2D_00 = ops_decl_stencil( 2, 1, s2D_00, "00");


  int d_p[2] = {0,0};

  int d_m[2] = {0,0};
  int size4[2] = {24, 24};
  int size0[2] = {12, 12};
  int size1[2] = {6, 6};
  int size2[2] = {4, 4};

  int size3[2] = {6, 6};

  int stride0[2] = {1, 1};
  int stride1[2] = {2, 2};
  int stride2[2] = {3, 3};
  int stride3[2] = {4, 4};


  ops_stencil S2D_RESTRICT_00 = ops_decl_restrict_stencil( 2, 1, s2D_00, stride1, "RESTRICT_00");

  ops_stencil S2D_PROLONG_00 = ops_decl_prolong_stencil( 2, 1, s2D_00, stride1, "PROLONG_00");
  ops_stencil S2D_PROLONG_00_M10_P10 = ops_decl_prolong_stencil( 2, 3, s2D_00_M10_P10, stride1, "PROLONG_00_M10_P10");
  ops_stencil S2D_RESTRICT_00_M10_P10 = ops_decl_restrict_stencil( 2, 3, s2D_00_M10_P10, stride1, "RESTRICT_00_M10_P10");

  int base[2] = {0,0};
  double* temp = NULL;

  ops_dat data0 = ops_decl_dat(grid0, 1, size0, base, d_m, d_p, stride1 , temp, "double", "data0");
  ops_dat data1 = ops_decl_dat(grid0, 1, size1, base, d_m, d_p, stride3 , temp, "double", "data1");

  ops_dat data5 = ops_decl_dat(grid0, 1, size4, base, d_m, d_p, stride0, temp, "double", "data3");
  ops_dat data6 = ops_decl_dat(grid0, 1, size0, base, d_m, d_p, stride1 , temp, "double", "data0");

  ops_dat data3 = ops_decl_dat(grid0, 1, size1, base, d_m, d_p, stride3 , temp, "double", "data3");


  ops_partition("");



  double ct0, ct1, et0, et1;
  ops_timers_core(&ct0, &et0);

  int iter_range[] = {1,12,1,12};
  int iter_range_large[] = {1,24,1,24};
  int iter_range_small[] = {1,6,1,6};
  int iter_range_tiny[] = {1,4,1,4};

  ops_par_loop_mgrid_populate_kernel_1("mgrid_populate_kernel_1", grid0, 2, iter_range_small,
               ops_arg_dat(data1, 1, S2D_00, "double", OPS_WRITE),
               ops_arg_idx());

  ops_print_dat_to_txtfile(data1, "data.txt");


  ops_par_loop_mgrid_prolong_kernel("mgrid_prolong_kernel", grid0, 2, iter_range,
               ops_arg_dat(data1, 1, S2D_PROLONG_00_M10_P10, "double", OPS_READ),
               ops_arg_dat(data0, 1, S2D_00, "double", OPS_WRITE),
               ops_arg_idx());

  ops_par_loop_mgrid_prolong_kernel("mgrid_prolong_kernel", grid0, 2, iter_range_large,
               ops_arg_dat(data0, 1, S2D_PROLONG_00_M10_P10, "double", OPS_READ),
               ops_arg_dat(data5, 1, S2D_00, "double", OPS_WRITE),
               ops_arg_idx());

  ops_print_dat_to_txtfile(data0, "data.txt");
  ops_print_dat_to_txtfile(data5, "data.txt");

  ops_par_loop_mgrid_populate_kernel_3("mgrid_populate_kernel_1", grid0, 2, iter_range_large,
               ops_arg_dat(data5, 1, S2D_00, "double", OPS_WRITE),
               ops_arg_idx());

  ops_par_loop_mgrid_restrict_kernel("mgrid_restrict_kernel", grid0, 2, iter_range,
               ops_arg_dat(data5, 1, S2D_RESTRICT_00_M10_P10, "double", OPS_READ),
               ops_arg_dat(data6, 1, S2D_00, "double", OPS_WRITE),
               ops_arg_idx());
  ops_par_loop_mgrid_restrict_kernel("mgrid_restrict_kernel", grid0, 2, iter_range_small,
               ops_arg_dat(data6, 1, S2D_RESTRICT_00_M10_P10, "double", OPS_READ),
               ops_arg_dat(data3, 1, S2D_00, "double", OPS_WRITE),
               ops_arg_idx());


  ops_print_dat_to_txtfile(data5, "data.txt");
  ops_print_dat_to_txtfile(data6, "data.txt");
  ops_print_dat_to_txtfile(data3, "data.txt");


  ops_timers_core(&ct1, &et1);
  ops_timing_output(stdout);

  ops_printf("\nTotal Wall time %lf\n",et1-et0);

}