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

#define OPS_ACC0(x,y) (x+xdim0_viscosity_kernel*(y))
#define OPS_ACC1(x,y) (x+xdim1_viscosity_kernel*(y))
#define OPS_ACC2(x,y) (x+xdim2_viscosity_kernel*(y))
#define OPS_ACC3(x,y) (x+xdim3_viscosity_kernel*(y))
#define OPS_ACC4(x,y) (x+xdim4_viscosity_kernel*(y))
#define OPS_ACC5(x,y) (x+xdim5_viscosity_kernel*(y))
#define OPS_ACC6(x,y) (x+xdim6_viscosity_kernel*(y))


//user function

void viscosity_kernel(  __global double *xvel0,  __global double *yvel0,
                        __global double *celldx,  __global double *celldy,
                        __global double *pressure,  __global double *density0,
                       __global double *viscosity,
  int xdim0_viscosity_kernel,
  int xdim1_viscosity_kernel,
  int xdim2_viscosity_kernel,
  int xdim3_viscosity_kernel,
  int xdim4_viscosity_kernel,
  int xdim5_viscosity_kernel,
  int xdim6_viscosity_kernel)
  {

  double ugrad, vgrad,
         grad2,
         pgradx,pgrady,
         pgradx2,pgrady2,
         grad,
         ygrad, xgrad,
         div,
         strain2,
         limiter,
         pgrad;


  ugrad = (xvel0[OPS_ACC0(1,0)] + xvel0[OPS_ACC0(1,1)]) - (xvel0[OPS_ACC0(0,0)] + xvel0[OPS_ACC0(0,1)]);
  vgrad = (yvel0[OPS_ACC1(0,1)] + yvel0[OPS_ACC1(1,1)]) - (yvel0[OPS_ACC1(0,0)] + yvel0[OPS_ACC1(1,0)]);

  div = (celldx[OPS_ACC2(0,0)])*(ugrad) + (celldy[OPS_ACC2(0,0)])*(vgrad);

  strain2 = 0.5*(xvel0[OPS_ACC0(0,1)] + xvel0[OPS_ACC0(1,1)] - xvel0[OPS_ACC0(0,0)] - xvel0[OPS_ACC0(1,0)])/(celldy[OPS_ACC3(0,0)]) +
            0.5*(yvel0[OPS_ACC1(1,0)] + yvel0[OPS_ACC1(1,1)] - yvel0[OPS_ACC1(0,0)] - yvel0[OPS_ACC1(0,1)])/(celldx[OPS_ACC2(0,0)]);


  pgradx  = (pressure[OPS_ACC4(1,0)] - pressure[OPS_ACC4(-1,0)])/(celldx[OPS_ACC2(0,0)]+ celldx[OPS_ACC2(1,0)]);
  pgrady = (pressure[OPS_ACC4(0,1)] - pressure[OPS_ACC4(0,-1)])/(celldy[OPS_ACC3(0,0)]+ celldy[OPS_ACC3(0,1)]);

  pgradx2 = pgradx * pgradx;
  pgrady2 = pgrady * pgrady;

  limiter = ((0.5*(ugrad)/celldx[OPS_ACC2(0,0)]) * pgradx2 +
             (0.5*(vgrad)/celldy[OPS_ACC3(0,0)]) * pgrady2 +
              strain2 * pgradx * pgrady)/ MAX(pgradx2 + pgrady2 , 1.0e-16);

  if( (limiter > 0.0) || (div >= 0.0)) {
        viscosity[OPS_ACC6(0,0)] = 0.0;
  }
  else {
    pgradx = SIGN( MAX(1.0e-16, fabs(pgradx)), pgradx);
    pgrady = SIGN( MAX(1.0e-16, fabs(pgrady)), pgrady);
    pgrad = sqrt(pgradx*pgradx + pgrady*pgrady);
    xgrad = fabs(celldx[OPS_ACC2(0,0)] * pgrad/pgradx);
    ygrad = fabs(celldy[OPS_ACC3(0,0)] * pgrad/pgrady);
    grad  = MIN(xgrad,ygrad);
    grad2 = grad*grad;

    viscosity[OPS_ACC6(0,0)] = 2.0 * (density0[OPS_ACC5(0,0)]) * grad2 * limiter * limiter;
  }
}



 #undef OPS_ACC0
 #undef OPS_ACC1
 #undef OPS_ACC2
 #undef OPS_ACC3
 #undef OPS_ACC4
 #undef OPS_ACC5
 #undef OPS_ACC6


 __kernel void ops_viscosity_kernel(
 __global double* arg0,
 __global double* arg1,
 __global double* arg2,
 __global double* arg3,
 __global double* arg4,
 __global double* arg5,
 __global double* arg6,
 int xdim0_viscosity_kernel,
 int xdim1_viscosity_kernel,
 int xdim2_viscosity_kernel,
 int xdim3_viscosity_kernel,
 int xdim4_viscosity_kernel,
 int xdim5_viscosity_kernel,
 int xdim6_viscosity_kernel,
 const int base0,
 const int base1,
 const int base2,
 const int base3,
 const int base4,
 const int base5,
 const int base6,
 int size0,
 int size1 ){


   int idx_y = get_global_id(1);
   int idx_x = get_global_id(0);

   if (idx_x < size0 && idx_y < size1) {
     viscosity_kernel(&arg0[base0 + idx_x * 1 + idx_y * 1 * xdim0_viscosity_kernel],
                      &arg1[base1 + idx_x * 1 + idx_y * 1 * xdim1_viscosity_kernel],
                      &arg2[base2 + idx_x * 1 + idx_y * 0 * xdim2_viscosity_kernel],
                      &arg3[base3 + idx_x * 0 + idx_y * 1 * xdim3_viscosity_kernel],
                      &arg4[base4 + idx_x * 1 + idx_y * 1 * xdim4_viscosity_kernel],
                      &arg5[base5 + idx_x * 1 + idx_y * 1 * xdim5_viscosity_kernel],
                      &arg6[base6 + idx_x * 1 + idx_y * 1 * xdim6_viscosity_kernel],
                      
                      xdim0_viscosity_kernel,
                      xdim1_viscosity_kernel,
                      xdim2_viscosity_kernel,
                      xdim3_viscosity_kernel,
                      xdim4_viscosity_kernel,
                      xdim5_viscosity_kernel,
                      xdim6_viscosity_kernel);
   }

 }
