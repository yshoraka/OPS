//
// auto-generated by ops.py
//

#ifdef OCL_FMA
#pragma OPENCL FP_CONTRACT ON
#else
#pragma OPENCL FP_CONTRACT OFF
#endif
#pragma OPENCL EXTENSION cl_khr_fp64 : enable

#include "ops_opencl_reduction.h"
#include "user_types.h"

#ifndef MIN
#define MIN(a, b) ((a < b) ? (a) : (b))
#endif
#ifndef MAX
#define MAX(a, b) ((a > b) ? (a) : (b))
#endif
#ifndef SIGN
#define SIGN(a, b) ((b < 0.0) ? (a * (-1)) : (a))
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

#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3

#define OPS_ACC0(x, y) (x + xdim0_ideal_gas_kernel * (y))
#define OPS_ACC1(x, y) (x + xdim1_ideal_gas_kernel * (y))
#define OPS_ACC2(x, y) (x + xdim2_ideal_gas_kernel * (y))
#define OPS_ACC3(x, y) (x + xdim3_ideal_gas_kernel * (y))

// user function
void ideal_gas_kernel(const __global double *restrict density,
                      const __global double *restrict energy,
                      __global double *restrict pressure,
                      __global double *restrict soundspeed)

{

  double sound_speed_squared, v, pressurebyenergy, pressurebyvolume;

  v = 1.0 / density[OPS_ACC0(0, 0)];
  pressure[OPS_ACC2(0, 0)] =
      (1.4 - 1.0) * density[OPS_ACC0(0, 0)] * energy[OPS_ACC1(0, 0)];
  pressurebyenergy = (1.4 - 1.0) * density[OPS_ACC0(0, 0)];
  pressurebyvolume = -1 * density[OPS_ACC0(0, 0)] * pressure[OPS_ACC2(0, 0)];
  sound_speed_squared =
      v * v * (pressure[OPS_ACC2(0, 0)] * pressurebyenergy - pressurebyvolume);
  soundspeed[OPS_ACC3(0, 0)] = sqrt(sound_speed_squared);
}

__kernel void ops_ideal_gas_kernel(__global const double *restrict arg0,
                                   __global const double *restrict arg1,
                                   __global double *restrict arg2,
                                   __global double *restrict arg3,
                                   const int base0, const int base1,
                                   const int base2, const int base3,
                                   const int size0, const int size1) {

  int idx_y = get_global_id(1);
  int idx_x = get_global_id(0);

  if (idx_x < size0 && idx_y < size1) {
    ideal_gas_kernel(
        &arg0[base0 + idx_x * 1 * 1 + idx_y * 1 * 1 * xdim0_ideal_gas_kernel],
        &arg1[base1 + idx_x * 1 * 1 + idx_y * 1 * 1 * xdim1_ideal_gas_kernel],
        &arg2[base2 + idx_x * 1 * 1 + idx_y * 1 * 1 * xdim2_ideal_gas_kernel],
        &arg3[base3 + idx_x * 1 * 1 + idx_y * 1 * 1 * xdim3_ideal_gas_kernel]);
  }
}
