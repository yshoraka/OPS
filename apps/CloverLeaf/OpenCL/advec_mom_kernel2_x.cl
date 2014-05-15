//
// auto-generated by ops.py on 2014-05-15 17:08
//

#include "user_types.h"

#ifndef MIN
#define MIN(a,b) ((a<b) ? (a) : (b))
#endif
#ifndef MAX
#define MAX(a,b) ((a>b) ? (a) : (b))
#endif
#ifndef SIGN
#define SIGN(a,b) ((b<0.0) ? (a*(-1)) : (a))
#endif

#pragma OPENCL EXTENSION cl_khr_fp64:enable

#define OPS_ACC0(x,y) (x+xdim0_advec_mom_kernel2_x*(y))
#define OPS_ACC1(x,y) (x+xdim1_advec_mom_kernel2_x*(y))
#define OPS_ACC2(x,y) (x+xdim2_advec_mom_kernel2_x*(y))
#define OPS_ACC3(x,y) (x+xdim3_advec_mom_kernel2_x*(y))


//user function

inline void advec_mom_kernel2_x(__global double *vel1,  __global double *node_mass_post,
                         __global double *node_mass_pre,  __global double *mom_flux,
  int xdim0_advec_mom_kernel2_x,
  int xdim1_advec_mom_kernel2_x,
  int xdim2_advec_mom_kernel2_x,
  int xdim3_advec_mom_kernel2_x)
  {

  vel1[OPS_ACC0(0,0)] = ( vel1[OPS_ACC0(0,0)] * node_mass_pre[OPS_ACC2(0,0)]  +
    mom_flux[OPS_ACC3(-1,0)] - mom_flux[OPS_ACC3(0,0)] ) / node_mass_post[OPS_ACC1(0,0)];

}



 #undef OPS_ACC0
 #undef OPS_ACC1
 #undef OPS_ACC2
 #undef OPS_ACC3


 __kernel void ops_advec_mom_kernel2_x(
 __global double* arg0,
 __global double* arg1,
 __global double* arg2,
 __global double* arg3,
 int xdim0_advec_mom_kernel2_x,
 int xdim1_advec_mom_kernel2_x,
 int xdim2_advec_mom_kernel2_x,
 int xdim3_advec_mom_kernel2_x,
 const int base0,
 const int base1,
 const int base2,
 const int base3,
 int size0,
 int size1 ){


   int idx_y = get_global_id(1);
   int idx_x = get_global_id(0);

   if (idx_x < size0 && idx_y < size1) {
     advec_mom_kernel2_x(&arg0[base0 + idx_x * 1 + idx_y * 1 * xdim0_advec_mom_kernel2_x],
                      &arg1[base1 + idx_x * 1 + idx_y * 1 * xdim1_advec_mom_kernel2_x],
                      &arg2[base2 + idx_x * 1 + idx_y * 1 * xdim2_advec_mom_kernel2_x],
                      &arg3[base3 + idx_x * 1 + idx_y * 1 * xdim3_advec_mom_kernel2_x],
                      
                      xdim0_advec_mom_kernel2_x,
                      xdim1_advec_mom_kernel2_x,
                      xdim2_advec_mom_kernel2_x,
                      xdim3_advec_mom_kernel2_x);
   }

 }
