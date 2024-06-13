/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * springMassTakeStep.c
 *
 * Code generation for function 'springMassTakeStep'
 *
 */

/* Include files */
#include "springMassTakeStep.h"
#include "rt_nonfinite.h"
#include "springMassTakeStep_emxutil.h"
#include "springMassTakeStep_types.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Declarations */
static double rt_powd_snf(double u0, double u1);

/* Function Definitions */
static double rt_powd_snf(double u0, double u1)
{
  double y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = rtNaN;
  } else {
    double d;
    double d1;
    d = fabs(u0);
    d1 = fabs(u1);
    if (rtIsInf(u1)) {
      if (d == 1.0) {
        y = 1.0;
      } else if (d > 1.0) {
        if (u1 > 0.0) {
          y = rtInf;
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = rtInf;
      }
    } else if (d1 == 0.0) {
      y = 1.0;
    } else if (d1 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = rtNaN;
    } else {
      y = pow(u0, u1);
    }
  }
  return y;
}

void springMassTakeStep(double xi, double vi, double ti, double dt, double g,
                        double *xf, double *vf)
{
  static const double x[21] = {0.2,
                               0.075,
                               0.225,
                               0.97777777777777775,
                               -3.7333333333333334,
                               3.5555555555555554,
                               2.9525986892242035,
                               -11.595793324188385,
                               9.8228928516994358,
                               -0.29080932784636487,
                               2.8462752525252526,
                               -10.757575757575758,
                               8.9064227177434727,
                               0.27840909090909088,
                               -0.2735313036020583,
                               0.091145833333333329,
                               0.0,
                               0.44923629829290207,
                               0.65104166666666663,
                               -0.322376179245283,
                               0.13095238095238096};
  static const double b[7] = {0.0012326388888888888,
                              0.0,
                              -0.0042527702905061394,
                              0.036979166666666667,
                              -0.05086379716981132,
                              0.0419047619047619,
                              -0.025};
  static const double b_b[7] = {-2.859375,
                                0.0,
                                4.0431266846361185,
                                -3.90625,
                                2.7939268867924527,
                                -1.5714285714285714,
                                1.5};
  static const double c_b[7] = {3.0833333333333335,
                                0.0,
                                -6.2893081761006293,
                                10.416666666666666,
                                -6.8773584905660377,
                                3.6666666666666665,
                                -4.0};
  static const double d_b[7] = {-1.1328125,
                                0.0,
                                2.6954177897574123,
                                -5.859375,
                                3.7610554245283021,
                                -1.9642857142857142,
                                2.5};
  emxArray_real_T *b_x;
  emxArray_real_T *tout;
  emxArray_real_T *yout;
  double f[14];
  double f0[2];
  double tspan[2];
  double absh;
  double absx;
  double c;
  double c_df_workspace_ODEFunction_work;
  double d2;
  double hmax;
  double initCond_idx_0;
  double initCond_idx_1;
  double t;
  double tdir;
  double tfinal;
  double *tout_data;
  double *yout_data;
  int Bcolidx;
  int exponent;
  int i;
  int i1;
  int iac;
  int j;
  int ncols;
  int nout;
  int outidx;
  bool Done;
  bool MinStepExit;
  emxInit_real_T(&tout);
  /*  Function springMassTakeStep acts as a wrapper for the ODE solving
   * function, step. */
  /*  It takes the same input parameters as springMassStep, but only outputs the
   * final  */
  /*  position and velocity.  */
  /*  Set spring equilibrium position  */
  /*  Set spring, mass, damper constants */
  /*  Scale acceleration g like a gravity force */
  c_df_workspace_ODEFunction_work = 10.0 * g;
  /*  Solve ODE for displacement at ti + dt */
  initCond_idx_0 = xi;
  initCond_idx_1 = vi;
  tspan[1] = ti + dt;
  tfinal = tspan[1];
  f0[1] =
      (c_df_workspace_ODEFunction_work / 10.0 - 100.0 * (xi - 1.0)) - 2.5 * vi;
  i = tout->size[0] * tout->size[1];
  tout->size[0] = 1;
  tout->size[1] = 200;
  emxEnsureCapacity_real_T(tout, i);
  tout_data = tout->data;
  for (i = 0; i < 200; i++) {
    tout_data[i] = 0.0;
  }
  emxInit_real_T(&yout);
  i = yout->size[0] * yout->size[1];
  yout->size[0] = 2;
  yout->size[1] = 200;
  emxEnsureCapacity_real_T(yout, i);
  yout_data = yout->data;
  for (i = 0; i < 400; i++) {
    yout_data[i] = 0.0;
  }
  nout = 0;
  yout_data[0] = xi;
  yout_data[1] = vi;
  tdir = tspan[1] - ti;
  c = fabs(tdir);
  absx = fabs(ti);
  hmax = fmin(
      c, fmax(0.1 * c, 3.5527136788005009E-15 * fmax(absx, fabs(tspan[1]))));
  if ((!rtIsInf(absx)) && (!rtIsNaN(absx))) {
    if (absx <= 2.2250738585072014E-308) {
      d2 = 4.94065645841247E-324;
    } else {
      frexp(absx, &ncols);
      d2 = ldexp(1.0, ncols - 53);
    }
  } else {
    d2 = rtNaN;
  }
  absh = fmin(hmax, c);
  c = 0.0;
  absx = fabs(vi / fmax(fabs(xi), 0.001));
  if (rtIsNaN(absx) || (absx > 0.0)) {
    c = absx;
  }
  absx = fabs(f0[1] / fmax(fabs(vi), 0.001));
  if (rtIsNaN(absx) || (absx > c)) {
    c = absx;
  }
  absx = c / 0.20095091452076641;
  if (absh * absx > 1.0) {
    absh = 1.0 / absx;
  }
  absh = fmax(absh, 16.0 * d2);
  t = ti;
  memset(&f[0], 0, 14U * sizeof(double));
  f[0] = vi;
  f[1] = f0[1];
  if (!rtIsNaN(tdir)) {
    if (tdir < 0.0) {
      tdir = -1.0;
    } else {
      tdir = (tdir > 0.0);
    }
  }
  MinStepExit = false;
  Done = false;
  int exitg1;
  do {
    double ynew[2];
    double d;
    double d1;
    double err;
    double h_tmp;
    double hmin;
    double mxerr;
    double tnew;
    bool NoFailedAttempts;
    exitg1 = 0;
    absx = fabs(t);
    if ((!rtIsInf(absx)) && (!rtIsNaN(absx))) {
      if (absx <= 2.2250738585072014E-308) {
        d2 = 4.94065645841247E-324;
      } else {
        frexp(absx, &exponent);
        d2 = ldexp(1.0, exponent - 53);
      }
    } else {
      d2 = rtNaN;
    }
    hmin = 16.0 * d2;
    absh = fmin(hmax, fmax(hmin, absh));
    absx = tdir * absh;
    d = tfinal - t;
    d1 = fabs(d);
    if (1.1 * absh >= d1) {
      absx = d;
      absh = d1;
      Done = true;
    }
    NoFailedAttempts = true;
    int exitg2;
    do {
      exitg2 = 0;
      Bcolidx = 0;
      for (j = 0; j < 5; j++) {
        Bcolidx += j;
        tspan[0] = initCond_idx_0;
        tspan[1] = initCond_idx_1;
        if (!(absx == 0.0)) {
          i = (j << 1) + 1;
          for (iac = 1; iac <= i; iac += 2) {
            c = absx * x[Bcolidx + ((iac - 1) >> 1)];
            i1 = iac + 1;
            for (outidx = iac; outidx <= i1; outidx++) {
              ncols = outidx - iac;
              tspan[ncols] += f[outidx - 1] * c;
            }
          }
        }
        ncols = (j + 1) << 1;
        f[ncols] = tspan[1];
        f[ncols + 1] = (c_df_workspace_ODEFunction_work / 10.0 -
                        100.0 * (tspan[0] - 1.0)) -
                       2.5 * tspan[1];
      }
      tnew = t + absx;
      ynew[0] = initCond_idx_0;
      ynew[1] = initCond_idx_1;
      if (!(absx == 0.0)) {
        for (iac = 0; iac <= 10; iac += 2) {
          c = absx * x[(Bcolidx + (iac >> 1)) + 5];
          i = iac + 2;
          for (outidx = iac + 1; outidx <= i; outidx++) {
            ncols = (outidx - iac) - 1;
            ynew[ncols] += f[outidx - 1] * c;
          }
        }
      }
      tspan[0] = ynew[1];
      tspan[1] =
          (c_df_workspace_ODEFunction_work / 10.0 - 100.0 * (ynew[0] - 1.0)) -
          2.5 * ynew[1];
      for (i = 0; i < 2; i++) {
        f[i + 12] = tspan[i];
        d = 0.0;
        for (i1 = 0; i1 < 7; i1++) {
          d += f[i + (i1 << 1)] * b[i1];
        }
        tspan[i] = d;
      }
      if (Done) {
        tnew = tfinal;
      }
      h_tmp = tnew - t;
      mxerr = 0.0;
      absx = fabs(tspan[0]);
      c = fabs(initCond_idx_0);
      d2 = fabs(ynew[0]);
      if ((c > d2) || rtIsNaN(d2)) {
        if (c > 0.001) {
          absx /= c;
        } else {
          absx /= 0.001;
        }
      } else if (d2 > 0.001) {
        absx /= d2;
      } else {
        absx /= 0.001;
      }
      if ((absx > 0.0) || rtIsNaN(absx)) {
        mxerr = absx;
      }
      absx = fabs(tspan[1]);
      c = fabs(initCond_idx_1);
      d2 = fabs(ynew[1]);
      if ((c > d2) || rtIsNaN(d2)) {
        if (c > 0.001) {
          absx /= c;
        } else {
          absx /= 0.001;
        }
      } else if (d2 > 0.001) {
        absx /= d2;
      } else {
        absx /= 0.001;
      }
      if ((absx > mxerr) || rtIsNaN(absx)) {
        mxerr = absx;
      }
      err = absh * mxerr;
      if (!(err <= 0.001)) {
        if (absh <= hmin) {
          MinStepExit = true;
          exitg2 = 1;
        } else {
          if (NoFailedAttempts) {
            NoFailedAttempts = false;
            absh = fmax(hmin,
                        absh * fmax(0.1, 0.8 * rt_powd_snf(0.001 / err, 0.2)));
          } else {
            absh = fmax(hmin, 0.5 * absh);
          }
          absx = tdir * absh;
          Done = false;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);
    if (MinStepExit) {
      exitg1 = 1;
    } else {
      double youtnew[8];
      double toutnew[4];
      double tref[3];
      double fhBI3[2];
      double fhBI4[2];
      double b_d2;
      outidx = nout + 1;
      d = t + h_tmp * 0.25;
      tref[0] = d;
      toutnew[0] = d;
      d = t + h_tmp * 0.5;
      tref[1] = d;
      toutnew[1] = d;
      d = t + h_tmp * 0.75;
      tref[2] = d;
      toutnew[2] = d;
      toutnew[3] = tnew;
      for (i = 0; i < 2; i++) {
        tspan[i] = f[i] * h_tmp;
        d = 0.0;
        d1 = 0.0;
        absx = 0.0;
        for (i1 = 0; i1 < 7; i1++) {
          c = f[i + (i1 << 1)];
          d += c * (h_tmp * b_b[i1]);
          d1 += c * (h_tmp * c_b[i1]);
          absx += c * (h_tmp * d_b[i1]);
        }
        fhBI4[i] = absx;
        fhBI3[i] = d1;
        f0[i] = d;
      }
      d = fhBI4[0];
      d1 = fhBI4[1];
      absx = fhBI3[0];
      c = fhBI3[1];
      d2 = f0[0];
      mxerr = f0[1];
      hmin = tspan[0];
      b_d2 = tspan[1];
      for (j = 0; j < 3; j++) {
        double s;
        s = (tref[j] - t) / h_tmp;
        ncols = j << 1;
        youtnew[ncols] =
            (((d * s + absx) * s + d2) * s + hmin) * s + initCond_idx_0;
        youtnew[ncols + 1] =
            (((d1 * s + c) * s + mxerr) * s + b_d2) * s + initCond_idx_1;
      }
      youtnew[6] = ynew[0];
      youtnew[7] = ynew[1];
      nout += 4;
      if (nout + 1 > tout->size[1]) {
        ncols = tout->size[1];
        i = tout->size[0] * tout->size[1];
        tout->size[0] = 1;
        tout->size[1] += 200;
        emxEnsureCapacity_real_T(tout, i);
        tout_data = tout->data;
        Bcolidx = yout->size[1];
        i = yout->size[0] * yout->size[1];
        yout->size[0] = 2;
        yout->size[1] += 200;
        emxEnsureCapacity_real_T(yout, i);
        yout_data = yout->data;
        for (j = 0; j < 200; j++) {
          tout_data[ncols + j] = 0.0;
          iac = Bcolidx + j;
          yout_data[2 * iac] = 0.0;
          yout_data[2 * iac + 1] = 0.0;
        }
      }
      for (Bcolidx = 0; Bcolidx < 4; Bcolidx++) {
        ncols = Bcolidx + outidx;
        tout_data[ncols] = toutnew[Bcolidx];
        iac = Bcolidx << 1;
        yout_data[2 * ncols] = youtnew[iac];
        yout_data[2 * ncols + 1] = youtnew[iac + 1];
      }
      if (Done) {
        exitg1 = 1;
      } else {
        if (NoFailedAttempts) {
          absx = 1.25 * rt_powd_snf(err / 0.001, 0.2);
          if (absx > 0.2) {
            absh /= absx;
          } else {
            absh *= 5.0;
          }
        }
        t = tnew;
        initCond_idx_0 = ynew[0];
        f[0] = f[12];
        initCond_idx_1 = ynew[1];
        f[1] = f[13];
      }
    }
  } while (exitg1 == 0);
  emxFree_real_T(&tout);
  emxInit_real_T(&b_x);
  if (nout + 1 < 1) {
    ncols = -1;
  } else {
    ncols = nout;
  }
  i = b_x->size[0] * b_x->size[1];
  b_x->size[0] = ncols + 1;
  b_x->size[1] = 2;
  emxEnsureCapacity_real_T(b_x, i);
  tout_data = b_x->data;
  for (i = 0; i < 2; i++) {
    for (i1 = 0; i1 <= ncols; i1++) {
      tout_data[i1 + b_x->size[0] * i] = yout_data[i + 2 * i1];
    }
  }
  emxFree_real_T(&yout);
  *xf = tout_data[b_x->size[0] - 1];
  *vf = tout_data[(b_x->size[0] + b_x->size[0]) - 1];
  emxFree_real_T(&b_x);
}

/* End of code generation (springMassTakeStep.c) */
