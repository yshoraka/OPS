//
// auto-generated by ops.py on 2014-05-28 14:33
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

void ops_par_loop_calc_dt_kernel(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg );

void ops_par_loop_calc_dt_kernel_min(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg );

void ops_par_loop_calc_dt_kernel_get(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg );

void ops_par_loop_calc_dt_kernel_print(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg );



#include "data.h"
#include "definitions.h"

//#include "calc_dt_kernel.h"

void calc_dt(double* local_dt, char* local_control,
             double* xl_pos, double* yl_pos, int* jldt, int* kldt, double *zl_pos, int *lldt)
{
  int small;
  double jk_control = 1.1;

  *local_dt = g_big;
  small = 0;

  int dtl_control;

  int x_min = field.x_min;
  int x_max = field.x_max;
  int y_min = field.y_min;
  int y_max = field.y_max;
  int z_min = field.z_min;
  int z_max = field.z_max;

  int rangexyz_inner[] = {x_min,x_max,y_min,y_max,z_min,z_max};

  ops_par_loop_calc_dt_kernel("calc_dt_kernel", clover_grid, 3, rangexyz_inner,
               ops_arg_dat(celldx, S3D_000_P100_STRID3D_X, "double", OPS_READ),
               ops_arg_dat(celldy, S3D_000_0P10_STRID3D_Y, "double", OPS_READ),
               ops_arg_dat(soundspeed, S3D_000, "double", OPS_READ),
               ops_arg_dat(viscosity, S3D_000, "double", OPS_READ),
               ops_arg_dat(density0, S3D_000, "double", OPS_READ),
               ops_arg_dat(xvel0, S3D_000_fP1P1P1, "double", OPS_READ),
               ops_arg_dat(xarea, S3D_000_P100, "double", OPS_READ),
               ops_arg_dat(volume, S3D_000, "double", OPS_READ),
               ops_arg_dat(yvel0, S3D_000_fP1P1P1, "double", OPS_READ),
               ops_arg_dat(yarea, S3D_000_0P10, "double", OPS_READ),
               ops_arg_dat(work_array1, S3D_000, "double", OPS_WRITE),
               ops_arg_dat(celldz, S3D_000_00P1_STRID3D_Z, "double", OPS_READ),
               ops_arg_dat(zvel0, S3D_000_fP1P1P1, "double", OPS_READ),
               ops_arg_dat(zarea, S3D_000_00P1, "double", OPS_READ));

  ops_par_loop_calc_dt_kernel_min("calc_dt_kernel_min", clover_grid, 3, rangexyz_inner,
               ops_arg_dat(work_array1, S3D_000, "double", OPS_READ),
               ops_arg_gbl(local_dt, 1, "double", OPS_MIN));


  dtl_control = 10.01 * (jk_control - (int)(jk_control));
  jk_control = jk_control - (jk_control - (int)(jk_control));


  *jldt = ((int)jk_control)%(x_max-2);
  *kldt = 1 + (jk_control/(x_max-2));
  *lldt = 1 + (jk_control/(x_max-2));

  int rangexyz_getpoint[] = {*jldt-1+2,*jldt+2,*kldt-1+2,*kldt+2,*lldt-1+2,*lldt+2};

  if(*local_dt < dtmin) small = 1;

  ops_par_loop_calc_dt_kernel_get("calc_dt_kernel_getx", clover_grid, 3, rangexyz_getpoint,
               ops_arg_dat(cellx, S3D_000_STRID3D_X, "double", OPS_READ),
               ops_arg_dat(celly, S3D_000_STRID3D_Y, "double", OPS_READ),
               ops_arg_gbl(xl_pos, 1, "double", OPS_INC),
               ops_arg_gbl(yl_pos, 1, "double", OPS_INC),
               ops_arg_dat(cellz, S3D_000_STRID3D_Z, "double", OPS_READ),
               ops_arg_gbl(zl_pos, 1, "double", OPS_INC));

  if(small != 0) {
    ops_printf("Timestep information:\n");
    ops_printf("j, k                 : %d, %d\n",*jldt,*kldt);
    ops_printf("x, y                 : %lf, %lf\n",*xl_pos,*xl_pos);
    ops_printf("timestep : %lf\n",*local_dt);

  ops_par_loop_calc_dt_kernel_print("calc_dt_kernel_print", clover_grid, 3, rangexyz_getpoint,
               ops_arg_dat(xvel0, S3D_000_fP1P1P1, "double", OPS_READ),
               ops_arg_dat(yvel0, S3D_000_fP1P1P1, "double", OPS_READ),
               ops_arg_dat(zvel0, S3D_000_fP1P1P1, "double", OPS_READ),
               ops_arg_dat(density0, S3D_000, "double", OPS_READ),
               ops_arg_dat(energy0, S3D_000, "double", OPS_READ),
               ops_arg_dat(pressure, S3D_000, "double", OPS_READ),
               ops_arg_dat(soundspeed, S3D_000, "double", OPS_READ));
  }

  if(dtl_control == 1) sprintf(local_control, "sound");
  if(dtl_control == 2) sprintf(local_control, "xvel");
  if(dtl_control == 3) sprintf(local_control, "yvel");
  if(dtl_control == 4) sprintf(local_control, "div");

}