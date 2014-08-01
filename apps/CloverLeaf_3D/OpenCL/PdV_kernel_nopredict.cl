//
// auto-generated by ops.py on 2014-08-01 17:05
//


#ifdef OCL_FMA
#pragma OPENCL FP_CONTRACT ON
#else
#pragma OPENCL FP_CONTRACT OFF
#endif
#pragma OPENCL EXTENSION cl_khr_fp64:enable

#include "user_types.h"
#include "ops_opencl_reduction.h"

#ifndef MIN
#define MIN(a,b) ((a<b) ? (a) : (b))
#endif
#ifndef MAX
#define MAX(a,b) ((a>b) ? (a) : (b))
#endif
#ifndef SIGN
#define SIGN(a,b) ((b<0.0) ? (a*(-1)) : (a))
#endif
#define OPS_READ 0
#define OPS_WRITE 1
#define OPS_RW 2
#define OPS_INC 3
#define OPS_MIN 4
#define OPS_MAX 5
#define ZERO_double 0.0;
#define INFINITY_double INFINITY;
#define ZERO_float 0.0f;
#define INFINITY_float INFINITY;
#define ZERO_int 0;
#define INFINITY_int INFINITY;
#define ZERO_uint 0;
#define INFINITY_uint INFINITY;
#define ZERO_ll 0;
#define INFINITY_ll INFINITY;
#define ZERO_ull 0;
#define INFINITY_ull INFINITY;
#define ZERO_bool 0;
#define OPS_ACC0(x,y,z) (x+xdim0_PdV_kernel_nopredict*(y)+xdim0_PdV_kernel_nopredict*ydim0_PdV_kernel_nopredict*(z))
#define OPS_ACC1(x,y,z) (x+xdim1_PdV_kernel_nopredict*(y)+xdim1_PdV_kernel_nopredict*ydim1_PdV_kernel_nopredict*(z))
#define OPS_ACC2(x,y,z) (x+xdim2_PdV_kernel_nopredict*(y)+xdim2_PdV_kernel_nopredict*ydim2_PdV_kernel_nopredict*(z))
#define OPS_ACC3(x,y,z) (x+xdim3_PdV_kernel_nopredict*(y)+xdim3_PdV_kernel_nopredict*ydim3_PdV_kernel_nopredict*(z))
#define OPS_ACC4(x,y,z) (x+xdim4_PdV_kernel_nopredict*(y)+xdim4_PdV_kernel_nopredict*ydim4_PdV_kernel_nopredict*(z))
#define OPS_ACC5(x,y,z) (x+xdim5_PdV_kernel_nopredict*(y)+xdim5_PdV_kernel_nopredict*ydim5_PdV_kernel_nopredict*(z))
#define OPS_ACC6(x,y,z) (x+xdim6_PdV_kernel_nopredict*(y)+xdim6_PdV_kernel_nopredict*ydim6_PdV_kernel_nopredict*(z))
#define OPS_ACC7(x,y,z) (x+xdim7_PdV_kernel_nopredict*(y)+xdim7_PdV_kernel_nopredict*ydim7_PdV_kernel_nopredict*(z))
#define OPS_ACC8(x,y,z) (x+xdim8_PdV_kernel_nopredict*(y)+xdim8_PdV_kernel_nopredict*ydim8_PdV_kernel_nopredict*(z))
#define OPS_ACC9(x,y,z) (x+xdim9_PdV_kernel_nopredict*(y)+xdim9_PdV_kernel_nopredict*ydim9_PdV_kernel_nopredict*(z))
#define OPS_ACC10(x,y,z) (x+xdim10_PdV_kernel_nopredict*(y)+xdim10_PdV_kernel_nopredict*ydim10_PdV_kernel_nopredict*(z))
#define OPS_ACC11(x,y,z) (x+xdim11_PdV_kernel_nopredict*(y)+xdim11_PdV_kernel_nopredict*ydim11_PdV_kernel_nopredict*(z))
#define OPS_ACC12(x,y,z) (x+xdim12_PdV_kernel_nopredict*(y)+xdim12_PdV_kernel_nopredict*ydim12_PdV_kernel_nopredict*(z))
#define OPS_ACC13(x,y,z) (x+xdim13_PdV_kernel_nopredict*(y)+xdim13_PdV_kernel_nopredict*ydim13_PdV_kernel_nopredict*(z))
#define OPS_ACC14(x,y,z) (x+xdim14_PdV_kernel_nopredict*(y)+xdim14_PdV_kernel_nopredict*ydim14_PdV_kernel_nopredict*(z))
#define OPS_ACC15(x,y,z) (x+xdim15_PdV_kernel_nopredict*(y)+xdim15_PdV_kernel_nopredict*ydim15_PdV_kernel_nopredict*(z))
#define OPS_ACC16(x,y,z) (x+xdim16_PdV_kernel_nopredict*(y)+xdim16_PdV_kernel_nopredict*ydim16_PdV_kernel_nopredict*(z))


//user function
void PdV_kernel_nopredict(const __global double * restrict xarea, const __global double * restrict xvel0, const __global double * restrict xvel1, 
const __global double * restrict yarea, const __global double * restrict yvel0, const __global double * restrict yvel1, __global double * restrict volume_change, 
const __global double * restrict volume, const __global double * restrict pressure, const __global double * restrict density0, __global double * restrict density1, 
const __global double * restrict viscosity, const __global double * restrict energy0, __global double * restrict energy1, const __global double * restrict zarea, 
const __global double * restrict zvel0, const __global double * restrict zvel1, 
  const double dt)

  {


  double recip_volume, energy_change, min_cell_volume;
  double right_flux, left_flux, top_flux, bottom_flux, back_flux, front_flux, total_flux;

  left_flux = ( xarea[OPS_ACC0(0,0,0)] * ( xvel0[OPS_ACC1(0,0,0)] + xvel0[OPS_ACC1(0,1,0)] +
                                           xvel0[OPS_ACC1(0,0,1)] + xvel0[OPS_ACC1(0,1,1)] +
                                           xvel1[OPS_ACC2(0,0,0)] + xvel1[OPS_ACC2(0,1,0)] +
                                           xvel1[OPS_ACC2(0,0,1)] + xvel1[OPS_ACC2(0,1,1)] ) ) * 0.125 * dt;
  right_flux = ( xarea[OPS_ACC0(1,0,0)] * ( xvel0[OPS_ACC1(1,0,0)] + xvel0[OPS_ACC1(1,1,0)] +
                                            xvel0[OPS_ACC1(1,0,1)] + xvel0[OPS_ACC1(1,1,1)] +
                                            xvel1[OPS_ACC2(1,0,0)] + xvel1[OPS_ACC2(1,1,0)] +
                                            xvel1[OPS_ACC2(1,0,1)] + xvel1[OPS_ACC2(1,1,1)] ) ) * 0.125 * dt;

  bottom_flux = ( yarea[OPS_ACC3(0,0,0)] * ( yvel0[OPS_ACC4(0,0,0)] + yvel0[OPS_ACC4(1,0,0)] +
                                             yvel0[OPS_ACC4(0,0,1)] + yvel0[OPS_ACC4(1,0,1)] +
                                             yvel1[OPS_ACC5(0,0,0)] + yvel1[OPS_ACC5(1,0,0)] +
                                             yvel1[OPS_ACC5(0,0,1)] + yvel1[OPS_ACC5(1,0,1)] ) ) * 0.125* dt;
  top_flux = ( yarea[OPS_ACC3(0,1,0)] * ( yvel0[OPS_ACC4(0,1,0)] + yvel0[OPS_ACC4(1,1,0)] +
                                          yvel0[OPS_ACC4(0,1,1)] + yvel0[OPS_ACC4(1,1,1)] +
                                          yvel1[OPS_ACC5(0,1,0)] + yvel1[OPS_ACC5(1,1,0)] +
                                          yvel1[OPS_ACC5(0,1,1)] + yvel1[OPS_ACC5(1,1,1)]) ) * 0.125 * dt;

  back_flux = ( zarea[OPS_ACC14(0,0,0)] * ( zvel0[OPS_ACC15(0,0,0)] + zvel0[OPS_ACC15(1,0,0)] +
                                            zvel0[OPS_ACC15(0,1,0)] + zvel0[OPS_ACC15(1,1,0)] +
                                            zvel1[OPS_ACC16(0,0,0)] + zvel1[OPS_ACC16(1,0,0)] +
                                            zvel1[OPS_ACC16(0,1,0)] + zvel1[OPS_ACC16(1,1,0)] ) ) * 0.125* dt;
  front_flux = ( zarea[OPS_ACC14(0,0,1)] * ( zvel0[OPS_ACC15(0,0,1)] + zvel0[OPS_ACC15(1,0,1)] +
                                             zvel0[OPS_ACC15(0,1,1)] + zvel0[OPS_ACC15(1,1,1)] +
                                             zvel1[OPS_ACC16(0,0,1)] + zvel1[OPS_ACC16(1,0,1)] +
                                             zvel1[OPS_ACC16(0,1,1)] + zvel1[OPS_ACC16(1,1,1)]) ) * 0.125 * dt;

  total_flux = right_flux - left_flux + top_flux - bottom_flux + front_flux - back_flux;

  volume_change[OPS_ACC6(0,0,0)] = (volume[OPS_ACC7(0,0,0)])/(volume[OPS_ACC7(0,0,0)] + total_flux);

  min_cell_volume = MIN( volume[OPS_ACC7(0,0,0)] + right_flux - left_flux + top_flux - bottom_flux + front_flux - back_flux,
                    MIN( volume[OPS_ACC7(0,0,0)] + right_flux - left_flux + top_flux - bottom_flux ,
                    MIN(volume[OPS_ACC7(0,0,0)] + right_flux - left_flux,
                        volume[OPS_ACC7(0,0,0)] + top_flux - bottom_flux) ));

  recip_volume = 1.0/volume[OPS_ACC7(0,0,0)];

  energy_change = ( pressure[OPS_ACC8(0,0,0)]/density0[OPS_ACC9(0,0,0)] +
                    viscosity[OPS_ACC11(0,0,0)]/density0[OPS_ACC9(0,0,0)] ) * total_flux * recip_volume;
  energy1[OPS_ACC13(0,0,0)] = energy0[OPS_ACC12(0,0,0)] - energy_change;
  density1[OPS_ACC10(0,0,0)] = density0[OPS_ACC9(0,0,0)] * volume_change[OPS_ACC6(0,0,0)];

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
 #undef OPS_ACC11
 #undef OPS_ACC12
 #undef OPS_ACC13
 #undef OPS_ACC14
 #undef OPS_ACC15
 #undef OPS_ACC16


 __kernel void ops_PdV_kernel_nopredict(
 __global const double* restrict arg0,
 __global const double* restrict arg1,
 __global const double* restrict arg2,
 __global const double* restrict arg3,
 __global const double* restrict arg4,
 __global const double* restrict arg5,
 __global double* restrict arg6,
 __global const double* restrict arg7,
 __global const double* restrict arg8,
 __global const double* restrict arg9,
 __global double* restrict arg10,
 __global const double* restrict arg11,
 __global const double* restrict arg12,
 __global double* restrict arg13,
 __global const double* restrict arg14,
 __global const double* restrict arg15,
 __global const double* restrict arg16,
 __global const double * restrict dt,
 const int base0,
 const int base1,
 const int base2,
 const int base3,
 const int base4,
 const int base5,
 const int base6,
 const int base7,
 const int base8,
 const int base9,
 const int base10,
 const int base11,
 const int base12,
 const int base13,
 const int base14,
 const int base15,
 const int base16,
 const int size0,
 const int size1,
 const int size2 ){


   int idx_z = get_global_id(2);
   int idx_y = get_global_id(1);
   int idx_x = get_global_id(0);

   if (idx_x < size0 && idx_y < size1 && idx_z < size2) {
     PdV_kernel_nopredict(&arg0[base0 + idx_x * 1 + idx_y * 1 * xdim0_PdV_kernel_nopredict + idx_z * 1 * xdim0_PdV_kernel_nopredict * ydim0_PdV_kernel_nopredict],
                &arg1[base1 + idx_x * 1 + idx_y * 1 * xdim1_PdV_kernel_nopredict + idx_z * 1 * xdim1_PdV_kernel_nopredict * ydim1_PdV_kernel_nopredict],
                &arg2[base2 + idx_x * 1 + idx_y * 1 * xdim2_PdV_kernel_nopredict + idx_z * 1 * xdim2_PdV_kernel_nopredict * ydim2_PdV_kernel_nopredict],
                &arg3[base3 + idx_x * 1 + idx_y * 1 * xdim3_PdV_kernel_nopredict + idx_z * 1 * xdim3_PdV_kernel_nopredict * ydim3_PdV_kernel_nopredict],
                &arg4[base4 + idx_x * 1 + idx_y * 1 * xdim4_PdV_kernel_nopredict + idx_z * 1 * xdim4_PdV_kernel_nopredict * ydim4_PdV_kernel_nopredict],
                &arg5[base5 + idx_x * 1 + idx_y * 1 * xdim5_PdV_kernel_nopredict + idx_z * 1 * xdim5_PdV_kernel_nopredict * ydim5_PdV_kernel_nopredict],
                &arg6[base6 + idx_x * 1 + idx_y * 1 * xdim6_PdV_kernel_nopredict + idx_z * 1 * xdim6_PdV_kernel_nopredict * ydim6_PdV_kernel_nopredict],
                &arg7[base7 + idx_x * 1 + idx_y * 1 * xdim7_PdV_kernel_nopredict + idx_z * 1 * xdim7_PdV_kernel_nopredict * ydim7_PdV_kernel_nopredict],
                &arg8[base8 + idx_x * 1 + idx_y * 1 * xdim8_PdV_kernel_nopredict + idx_z * 1 * xdim8_PdV_kernel_nopredict * ydim8_PdV_kernel_nopredict],
                &arg9[base9 + idx_x * 1 + idx_y * 1 * xdim9_PdV_kernel_nopredict + idx_z * 1 * xdim9_PdV_kernel_nopredict * ydim9_PdV_kernel_nopredict],
                &arg10[base10 + idx_x * 1 + idx_y * 1 * xdim10_PdV_kernel_nopredict + idx_z * 1 * xdim10_PdV_kernel_nopredict * ydim10_PdV_kernel_nopredict],
                &arg11[base11 + idx_x * 1 + idx_y * 1 * xdim11_PdV_kernel_nopredict + idx_z * 1 * xdim11_PdV_kernel_nopredict * ydim11_PdV_kernel_nopredict],
                &arg12[base12 + idx_x * 1 + idx_y * 1 * xdim12_PdV_kernel_nopredict + idx_z * 1 * xdim12_PdV_kernel_nopredict * ydim12_PdV_kernel_nopredict],
                &arg13[base13 + idx_x * 1 + idx_y * 1 * xdim13_PdV_kernel_nopredict + idx_z * 1 * xdim13_PdV_kernel_nopredict * ydim13_PdV_kernel_nopredict],
                &arg14[base14 + idx_x * 1 + idx_y * 1 * xdim14_PdV_kernel_nopredict + idx_z * 1 * xdim14_PdV_kernel_nopredict * ydim14_PdV_kernel_nopredict],
                &arg15[base15 + idx_x * 1 + idx_y * 1 * xdim15_PdV_kernel_nopredict + idx_z * 1 * xdim15_PdV_kernel_nopredict * ydim15_PdV_kernel_nopredict],
                &arg16[base16 + idx_x * 1 + idx_y * 1 * xdim16_PdV_kernel_nopredict + idx_z * 1 * xdim16_PdV_kernel_nopredict * ydim16_PdV_kernel_nopredict],
                *dt);
   }

 }
