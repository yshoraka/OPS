//
// auto-generated by ops.py on 2014-08-01 17:05
//



#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define OPS_3D
#include  "ops_lib_cpp.h"

//
// ops_par_loop declarations
//

void ops_par_loop_ideal_gas_kernel(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg );



#include "data.h"
#include "definitions.h"

//#include "ideal_gas_kernel.h"

void ideal_gas(int predict)
{

  int x_min = field.x_min;
  int x_max = field.x_max;
  int y_min = field.y_min;
  int y_max = field.y_max;
  int z_min = field.z_min;
  int z_max = field.z_max;

  int rangexyz_inner[] = {x_min,x_max,y_min,y_max,z_min,z_max};

  if(predict != TRUE) {
    ops_par_loop_ideal_gas_kernel("ideal_gas_kernel", clover_grid, 3, rangexyz_inner,
                 ops_arg_dat(density0, S3D_000, "double", OPS_READ),
                 ops_arg_dat(energy0, S3D_000, "double", OPS_READ),
                 ops_arg_dat(pressure, S3D_000, "double", OPS_WRITE),
                 ops_arg_dat(soundspeed, S3D_000, "double", OPS_WRITE));
  }
  else {
    ops_par_loop_ideal_gas_kernel("ideal_gas_kernel", clover_grid, 3, rangexyz_inner,
                 ops_arg_dat(density1, S3D_000, "double", OPS_READ),
                 ops_arg_dat(energy1, S3D_000, "double", OPS_READ),
                 ops_arg_dat(pressure, S3D_000, "double", OPS_WRITE),
                 ops_arg_dat(soundspeed, S3D_000, "double", OPS_WRITE));
  }
}
