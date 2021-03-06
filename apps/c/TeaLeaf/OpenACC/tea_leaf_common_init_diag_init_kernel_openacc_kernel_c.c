//
// auto-generated by ops.py
//
#include "./OpenACC/tea_leaf_common.h"

#define OPS_GPU

int xdim0_tea_leaf_common_init_diag_init_kernel;
int xdim1_tea_leaf_common_init_diag_init_kernel;
int xdim2_tea_leaf_common_init_diag_init_kernel;


#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2


#define OPS_ACC0(x,y) (x+xdim0_tea_leaf_common_init_diag_init_kernel*(y))
#define OPS_ACC1(x,y) (x+xdim1_tea_leaf_common_init_diag_init_kernel*(y))
#define OPS_ACC2(x,y) (x+xdim2_tea_leaf_common_init_diag_init_kernel*(y))

//user function
inline
void tea_leaf_common_init_diag_init_kernel(double *Mi, const double *Kx, const double *Ky,
	const double *rx, const double *ry) {
	Mi[OPS_ACC0(0,0)] = 1.0/(1.0
			+(*ry)*(Ky[OPS_ACC2(0,1)] + Ky[OPS_ACC2(0,0)])
			+(*rx)*(Kx[OPS_ACC1(1,0)] + Kx[OPS_ACC1(0,0)]));
}


#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2



void tea_leaf_common_init_diag_init_kernel_c_wrapper(
  double *p_a0,
  double *p_a1,
  double *p_a2,
  double p_a3,
  double p_a4,
  int x_size, int y_size) {
  #ifdef OPS_GPU
  #pragma acc parallel deviceptr(p_a0,p_a1,p_a2)
  #pragma acc loop
  #endif
  for ( int n_y=0; n_y<y_size; n_y++ ){
    #ifdef OPS_GPU
    #pragma acc loop
    #endif
    for ( int n_x=0; n_x<x_size; n_x++ ){
      tea_leaf_common_init_diag_init_kernel(  p_a0 + n_x*1*1 + n_y*xdim0_tea_leaf_common_init_diag_init_kernel*1*1,
           p_a1 + n_x*1*1 + n_y*xdim1_tea_leaf_common_init_diag_init_kernel*1*1, p_a2 + n_x*1*1 + n_y*xdim2_tea_leaf_common_init_diag_init_kernel*1*1,
           &p_a3, &p_a4 );

    }
  }
}
