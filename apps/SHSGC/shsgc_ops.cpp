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

void ops_par_loop_initialize_kernel(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg );

void ops_par_loop_save_kernel(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg );

void ops_par_loop_zerores_kernel(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg,
  ops_arg );

void ops_par_loop_drhoudx_kernel(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg );

void ops_par_loop_drhouupdx_kernel(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg );

void ops_par_loop_drhoEpudx_kernel(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg );

void ops_par_loop_updateRK3_kernel(char const *, ops_block, int , int*,
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

void ops_par_loop_Riemann_kernel(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg );

void ops_par_loop_limiter_kernel(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg,
  ops_arg );

void ops_par_loop_tvd_kernel(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg );

void ops_par_loop_vars_kernel(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg );

void ops_par_loop_calupwindeff_kernel(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg );

void ops_par_loop_fact_kernel(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg );

void ops_par_loop_update_kernel(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg );





ops_block shsgc_grid;

ops_dat x;
ops_dat rho_old, rho_new, rho_res;
ops_dat rhou_old, rhou_new, rhou_res;
ops_dat rhov_old, rhov_new;
ops_dat rhoE_old, rhoE_new, rhoE_res;
ops_dat rhoin;
ops_dat r, al, alam, gt, tht, ep2, cmp, cf, eff, s;


ops_stencil S1D_0, S1D_01, S1D_0M1;
ops_stencil S1D_0M1M2P1P2;



int nxp = 204;
int nyp = 5;
int xhalo = 2;
int yhalo = 2;
double xmin = -5.0;
double ymin = 0;
double xmax = 5.0;
double ymax = 0.5;
double dx = (xmax-xmin)/(nxp-(1 + 2*xhalo));
double dy = (ymax-ymin)/(nyp-1);
double pl = 10.333f;
double pr = 1.0f;
double rhol = 3.857143;
double rhor = 1.0f;
double ul = 2.6293690 ;
double ur = 0.0f;
double gam = 1.4;
double gam1=gam - 1.0;
double eps = 0.2;
double lambda = 5.0;
double a1[3];
double a2[3];
double dt=0.0002;
double del2 = 1e-8;
double akap2 = 0.40;
double tvdsmu = 0.25f;
double con = pow (tvdsmu,2.f);

FILE *fp;


//#include "initialize_kernel.h"
//#include "save_kernel.h"
//#include "zerores_kernel.h"
//#include "drhoudx_kernel.h"
//#include "drhouupdx_kernel.h"
//#include "drhoEpudx_kernel.h"
//#include "updateRK3_kernel.h"
//#include "Riemann_kernel.h"
//#include "limiter_kernel.h"
//#include "tvd_kernel.h"
//#include "vars_kernel.h"
//#include "calupwindeff_kernel.h"
//#include "fact_kernel.h"
//#include "update_kernel.h"


int main(int argc, char **argv) {

  double totaltime =0.0f;


  a1[0] = 2.0/3.0;
  a1[1] = 5.0/12.0;
  a1[2] = 3.0/5.0;
  a2[0] = 1.0/4.0;
  a2[1] = 3.0/20.0;
  a2[2] = 3.0/5.0;



  ops_init(argc,argv,1);



  shsgc_grid = ops_decl_block(1, "shsgc grid");




  int d_p[1] = {0};
  int d_m[1] = {0};
  int size[1] = {nxp};
  int base[1] = {0};
  double* temp = NULL;

  x = ops_decl_dat(shsgc_grid, 1, size, base, d_m, d_p, temp, "double", "x");

  rho_old = ops_decl_dat(shsgc_grid, 1, size, base, d_m, d_p, temp, "double", "rho_old");
  rho_new = ops_decl_dat(shsgc_grid, 1, size, base, d_m, d_p, temp, "double", "rho_new");
  rho_res = ops_decl_dat(shsgc_grid, 1, size, base, d_m, d_p, temp, "double", "rho_res");

  rhou_old = ops_decl_dat(shsgc_grid, 1, size, base, d_m, d_p, temp, "double", "rhou_old");
  rhou_new = ops_decl_dat(shsgc_grid, 1, size, base, d_m, d_p, temp, "double", "rhou_new");
  rhou_res = ops_decl_dat(shsgc_grid, 1, size, base, d_m, d_p, temp, "double", "rhou_res");

  rhov_old = ops_decl_dat(shsgc_grid, 1, size, base, d_m, d_p, temp, "double", "rhov_old");
  rhov_new = ops_decl_dat(shsgc_grid, 1, size, base, d_m, d_p, temp, "double", "rhov_new");

  rhoE_old = ops_decl_dat(shsgc_grid, 1, size, base, d_m, d_p, temp, "double", "rhoE_old");
  rhoE_new = ops_decl_dat(shsgc_grid, 1, size, base, d_m, d_p, temp, "double", "rhoE_new");
  rhoE_res = ops_decl_dat(shsgc_grid, 1, size, base, d_m, d_p, temp, "double", "rhoE_res");

  rhoin = ops_decl_dat(shsgc_grid, 1, size, base, d_m, d_p, temp, "double", "rhoin");

  r     =  ops_decl_dat(shsgc_grid, 9, size, base, d_m, d_p, temp, "double", "r");
  al    = ops_decl_dat(shsgc_grid, 3, size, base, d_m, d_p, temp, "double", "al");
  alam  = ops_decl_dat(shsgc_grid, 3, size, base, d_m, d_p, temp, "double", "alam");
  gt    = ops_decl_dat(shsgc_grid, 3, size, base, d_m, d_p, temp, "double", "gt");
  tht   = ops_decl_dat(shsgc_grid, 3, size, base, d_m, d_p, temp, "double", "tht");
  ep2   = ops_decl_dat(shsgc_grid, 3, size, base, d_m, d_p, temp, "double", "ep2");
  cmp   = ops_decl_dat(shsgc_grid, 3, size, base, d_m, d_p, temp, "double", "cmp");
  cf    = ops_decl_dat(shsgc_grid, 3, size, base, d_m, d_p, temp, "double", "cf");
  eff   = ops_decl_dat(shsgc_grid, 3, size, base, d_m, d_p, temp, "double", "eff");
  s     = ops_decl_dat(shsgc_grid, 3, size, base, d_m, d_p, temp, "double", "s");



  int s1D_0[]   = {0};
  S1D_0         = ops_decl_stencil( 1, 1, s1D_0, "0");
  int s1D_0M1M2P1P2[] = {0,-1,-2,1,2};
  S1D_0M1M2P1P2 = ops_decl_stencil( 5, 1, s1D_0M1M2P1P2, "0,-1,-2,1,2");

  int s1D_01[]   = {0,1};
  S1D_01         = ops_decl_stencil( 2, 1, s1D_01, "0,1");

  int s1D_0M1[]   = {0,-1};
  S1D_0M1         = ops_decl_stencil( 2, 1, s1D_01, "0,-1");

  ops_partition("1D_BLOCK_DECOMPOSE");






  int nxp_range[] = {0,nxp};
  ops_par_loop_initialize_kernel("initialize_kernel", shsgc_grid, 1, nxp_range,
               ops_arg_dat(x, 1, S1D_0, "double", OPS_WRITE),
               ops_arg_dat(rho_new, 1, S1D_0, "double", OPS_WRITE),
               ops_arg_dat(rhou_new, 1, S1D_0, "double", OPS_WRITE),
               ops_arg_dat(rhoE_new, 1, S1D_0, "double", OPS_WRITE),
               ops_arg_dat(rhoin, 1, S1D_0, "double", OPS_WRITE),
               ops_arg_idx());






  double ct0, ct1, et0, et1;
  ops_timers_core(&ct0, &et0);

  int niter = 9005;
  for (int iter = 0; iter <niter;  iter++){

    ops_par_loop_save_kernel("save_kernel", shsgc_grid, 1, nxp_range,
                 ops_arg_dat(rho_old, 1, S1D_0, "double", OPS_WRITE),
                 ops_arg_dat(rhou_old, 1, S1D_0, "double", OPS_WRITE),
                 ops_arg_dat(rhoE_old, 1, S1D_0, "double", OPS_WRITE),
                 ops_arg_dat(rho_new, 1, S1D_0, "double", OPS_READ),
                 ops_arg_dat(rhou_new, 1, S1D_0, "double", OPS_READ),
                 ops_arg_dat(rhoE_new, 1, S1D_0, "double", OPS_READ));

    for (int nrk=0; nrk <3; nrk++){

      ops_par_loop_zerores_kernel("zerores_kernel", shsgc_grid, 1, nxp_range,
                   ops_arg_dat(rho_res, 1, S1D_0, "double", OPS_WRITE),
                   ops_arg_dat(rhou_res, 1, S1D_0, "double", OPS_WRITE),
                   ops_arg_dat(rhoE_res, 1, S1D_0, "double", OPS_WRITE));



      int nxp_range_1[] = {2,nxp-2};
      ops_par_loop_drhoudx_kernel("drhoudx_kernel", shsgc_grid, 1, nxp_range_1,
                   ops_arg_dat(rhou_new, 1, S1D_0M1M2P1P2, "double", OPS_READ),
                   ops_arg_dat(rho_res, 1, S1D_0, "double", OPS_WRITE));

      ops_par_loop_drhouupdx_kernel("drhouupdx_kernel", shsgc_grid, 1, nxp_range_1,
                   ops_arg_dat(rhou_new, 1, S1D_0M1M2P1P2, "double", OPS_READ),
                   ops_arg_dat(rho_new, 1, S1D_0M1M2P1P2, "double", OPS_READ),
                   ops_arg_dat(rhoE_new, 1, S1D_0M1M2P1P2, "double", OPS_READ),
                   ops_arg_dat(rhou_res, 1, S1D_0, "double", OPS_WRITE));

      ops_par_loop_drhoEpudx_kernel("drhoEpudx_kernel", shsgc_grid, 1, nxp_range_1,
                   ops_arg_dat(rhou_new, 1, S1D_0M1M2P1P2, "double", OPS_READ),
                   ops_arg_dat(rho_new, 1, S1D_0M1M2P1P2, "double", OPS_READ),
                   ops_arg_dat(rhoE_new, 1, S1D_0M1M2P1P2, "double", OPS_READ),
                   ops_arg_dat(rhoE_res, 1, S1D_0, "double", OPS_WRITE));

      int nxp_range_2[] = {3,nxp-2};
      ops_par_loop_updateRK3_kernel("updateRK3_kernel", shsgc_grid, 1, nxp_range_2,
                   ops_arg_dat(rho_new, 1, S1D_0, "double", OPS_WRITE),
                   ops_arg_dat(rhou_new, 1, S1D_0, "double", OPS_WRITE),
                   ops_arg_dat(rhoE_new, 1, S1D_0, "double", OPS_WRITE),
                   ops_arg_dat(rho_old, 1, S1D_0, "double", OPS_RW),
                   ops_arg_dat(rhou_old, 1, S1D_0, "double", OPS_RW),
                   ops_arg_dat(rhoE_old, 1, S1D_0, "double", OPS_RW),
                   ops_arg_dat(rho_res, 1, S1D_0, "double", OPS_READ),
                   ops_arg_dat(rhou_res, 1, S1D_0, "double", OPS_READ),
                   ops_arg_dat(rhoE_res, 1, S1D_0, "double", OPS_READ),
                   ops_arg_gbl(&a1[nrk], 1, "double", OPS_READ),
                   ops_arg_gbl(&a2[nrk], 1, "double", OPS_READ));
    }






    int nxp_range_3[] = {0,nxp-1};
    ops_par_loop_Riemann_kernel("Riemann_kernel", shsgc_grid, 1, nxp_range_3,
                 ops_arg_dat(rho_new, 1, S1D_01, "double", OPS_READ),
                 ops_arg_dat(rhou_new, 1, S1D_01, "double", OPS_READ),
                 ops_arg_dat(rhoE_new, 1, S1D_01, "double", OPS_READ),
                 ops_arg_dat(alam, 3, S1D_01, "double", OPS_WRITE),
                 ops_arg_dat(r, 9, S1D_01, "double", OPS_WRITE),
                 ops_arg_dat(al, 3, S1D_01, "double", OPS_WRITE));


    int nxp_range_4[] = {1,nxp};
    ops_par_loop_limiter_kernel("limiter_kernel", shsgc_grid, 1, nxp_range_4,
                 ops_arg_dat(al, 3, S1D_0M1, "double", OPS_READ),
                 ops_arg_dat(tht, 3, S1D_0, "double", OPS_WRITE),
                 ops_arg_dat(gt, 3, S1D_0, "double", OPS_WRITE));


    ops_par_loop_tvd_kernel("tvd_kernel", shsgc_grid, 1, nxp_range_3,
                 ops_arg_dat(tht, 3, S1D_0M1, "double", OPS_READ),
                 ops_arg_dat(ep2, 3, S1D_0, "double", OPS_WRITE));

    ops_par_loop_vars_kernel("vars_kernel", shsgc_grid, 1, nxp_range_3,
                 ops_arg_dat(alam, 3, S1D_0, "double", OPS_READ),
                 ops_arg_dat(al, 3, S1D_0, "double", OPS_READ),
                 ops_arg_dat(gt, 3, S1D_01, "double", OPS_READ),
                 ops_arg_dat(cmp, 3, S1D_0, "double", OPS_WRITE),
                 ops_arg_dat(cf, 3, S1D_0, "double", OPS_WRITE));



    ops_par_loop_calupwindeff_kernel("calupwindeff_kernel", shsgc_grid, 1, nxp_range_3,
                 ops_arg_dat(cmp, 3, S1D_0, "double", OPS_READ),
                 ops_arg_dat(gt, 3, S1D_01, "double", OPS_READ),
                 ops_arg_dat(cf, 3, S1D_0, "double", OPS_READ),
                 ops_arg_dat(al, 3, S1D_0, "double", OPS_READ),
                 ops_arg_dat(ep2, 3, S1D_0, "double", OPS_READ),
                 ops_arg_dat(r, 9, S1D_0, "double", OPS_READ),
                 ops_arg_dat(eff, 3, S1D_0, "double", OPS_WRITE));


    ops_par_loop_fact_kernel("fact_kernel", shsgc_grid, 1, nxp_range_4,
                 ops_arg_dat(eff, 3, S1D_0M1, "double", OPS_READ),
                 ops_arg_dat(s, 3, S1D_0, "double", OPS_WRITE));


    int nxp_range_5[] = {3,nxp-3};
    ops_par_loop_update_kernel("update_kernel", shsgc_grid, 1, nxp_range_5,
                 ops_arg_dat(rho_new, 1, S1D_0, "double", OPS_RW),
                 ops_arg_dat(rhou_new, 1, S1D_0, "double", OPS_RW),
                 ops_arg_dat(rhoE_new, 1, S1D_0, "double", OPS_RW),
                 ops_arg_dat(s, 3, S1D_0, "double", OPS_READ));

    totaltime = totaltime + dt;
    printf("%d \t %f\n", iter, totaltime);

  }

  ops_timers_core(&ct1, &et1);
  ops_printf("\nTotal Wall time %lf\n",et1-et0);


  ops_print_dat_to_txtfile(rhou_new, "shsgc.dat");

  ops_exit();

}
