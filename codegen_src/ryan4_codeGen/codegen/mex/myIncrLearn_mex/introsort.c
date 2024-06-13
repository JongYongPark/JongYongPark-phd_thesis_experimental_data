/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * introsort.c
 *
 * Code generation for function 'introsort'
 *
 */

/* Include files */
#include "introsort.h"
#include "cellstr_sort.h"
#include "heapsort.h"
#include "insertionsort.h"
#include "myIncrLearn_mex_data.h"
#include "myIncrLearn_mex_types.h"
#include "rt_nonfinite.h"

/* Type Definitions */
#ifndef typedef_struct_T
#define typedef_struct_T
typedef struct {
  int32_T xstart;
  int32_T xend;
  int32_T depth;
} struct_T;
#endif /* typedef_struct_T */

/* Variable Definitions */
static emlrtRSInfo ib_emlrtRSI = {
    34,          /* lineNo */
    "introsort", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\introsort.m" /* pathName */
};

static emlrtRSInfo md_emlrtRSI = {
    42,          /* lineNo */
    "introsort", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\introsort.m" /* pathName */
};

static emlrtRSInfo nd_emlrtRSI = {
    44,          /* lineNo */
    "introsort", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\introsort.m" /* pathName */
};

static emlrtRSInfo od_emlrtRSI = {
    47,          /* lineNo */
    "introsort", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\introsort.m" /* pathName */
};

static emlrtRSInfo pd_emlrtRSI = {
    49,          /* lineNo */
    "introsort", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\introsort.m" /* pathName */
};

static emlrtRSInfo qd_emlrtRSI = {
    51,          /* lineNo */
    "introsort", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\introsort.m" /* pathName */
};

static emlrtRSInfo rd_emlrtRSI = {
    55,          /* lineNo */
    "introsort", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\introsort.m" /* pathName */
};

static emlrtRSInfo sd_emlrtRSI = {
    58,          /* lineNo */
    "introsort", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\introsort.m" /* pathName */
};

static emlrtRSInfo td_emlrtRSI = {
    41,          /* lineNo */
    "introsort", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\introsort.m" /* pathName */
};

static emlrtRSInfo ce_emlrtRSI = {
    13,              /* lineNo */
    "sortpartition", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\private\\sortpartition.m" /* pathName */
};

static emlrtRSInfo de_emlrtRSI = {
    18,              /* lineNo */
    "sortpartition", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\private\\sortpartition.m" /* pathName */
};

static emlrtRSInfo ee_emlrtRSI = {
    23,              /* lineNo */
    "sortpartition", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\private\\sortpartition.m" /* pathName */
};

static emlrtRSInfo fe_emlrtRSI = {
    36,              /* lineNo */
    "sortpartition", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\private\\sortpartition.m" /* pathName */
};

static emlrtRSInfo ge_emlrtRSI = {
    40,              /* lineNo */
    "sortpartition", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\private\\sortpartition.m" /* pathName */
};

static emlrtRTEInfo r_emlrtRTEI = {
    62,           /* lineNo */
    39,           /* colNo */
    "stack/push", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\stack.m" /* pName */
};

static emlrtDCInfo f_emlrtDCI = {
    48,            /* lineNo */
    48,            /* colNo */
    "stack/stack", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\stack.m", /* pName */
    4                    /* checkKind */
};

/* Function Definitions */
void b_introsort(const emlrtStack *sp, emxArray_int32_T *x, int32_T xend,
                 const emxArray_cell_wrap_1 *cmp_workspace_c)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  struct_T frame;
  int32_T pmax;
  int32_T *x_data;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  x_data = x->data;
  if (xend > 1) {
    if (xend <= 32) {
      st.site = &ib_emlrtRSI;
      insertionsort(&st, x, 1, xend, cmp_workspace_c);
    } else {
      struct_T st_d_data[120];
      int32_T MAXDEPTH;
      int32_T pmin;
      int32_T pow2p;
      int32_T st_n;
      int32_T t;
      int32_T unnamed_idx_0;
      boolean_T exitg1;
      pmax = 31;
      pmin = 0;
      exitg1 = false;
      while ((!exitg1) && (pmax - pmin > 1)) {
        t = (pmin + pmax) >> 1;
        pow2p = 1 << t;
        if (pow2p == xend) {
          pmax = t;
          exitg1 = true;
        } else if (pow2p > xend) {
          pmax = t;
        } else {
          pmin = t;
        }
      }
      MAXDEPTH = (pmax - 1) << 1;
      frame.xstart = 1;
      frame.xend = xend;
      frame.depth = 0;
      st.site = &td_emlrtRSI;
      unnamed_idx_0 = MAXDEPTH << 1;
      if (unnamed_idx_0 < 0) {
        emlrtNonNegativeCheckR2012b(unnamed_idx_0, &f_emlrtDCI, &st);
      }
      for (pmax = 0; pmax < unnamed_idx_0; pmax++) {
        st_d_data[pmax] = frame;
      }
      st.site = &md_emlrtRSI;
      if (unnamed_idx_0 <= 0) {
        emlrtErrorWithMessageIdR2018a(&st, &r_emlrtRTEI,
                                      "Coder:toolbox:StackPushLimit",
                                      "Coder:toolbox:StackPushLimit", 0);
      }
      st_d_data[0] = frame;
      st_n = 1;
      while (st_n > 0) {
        st.site = &nd_emlrtRSI;
        frame = st_d_data[st_n - 1];
        st_n--;
        pmax = frame.xend - frame.xstart;
        if (pmax + 1 <= 32) {
          st.site = &od_emlrtRSI;
          insertionsort(&st, x, frame.xstart, frame.xend, cmp_workspace_c);
          x_data = x->data;
        } else if (frame.depth == MAXDEPTH) {
          st.site = &pd_emlrtRSI;
          b_heapsort(&st, x, frame.xstart, frame.xend, cmp_workspace_c);
          x_data = x->data;
        } else {
          boolean_T varargout_1;
          st.site = &qd_emlrtRSI;
          pmax = (frame.xstart + pmax / 2) - 1;
          b_st.site = &ce_emlrtRSI;
          c_st.site = &gb_emlrtRSI;
          varargout_1 = cellstr_sort_anonFcn1(
              &c_st, cmp_workspace_c, x_data[pmax], x_data[frame.xstart - 1]);
          if (varargout_1) {
            t = x_data[frame.xstart - 1];
            x_data[frame.xstart - 1] = x_data[pmax];
            x_data[pmax] = t;
          }
          b_st.site = &de_emlrtRSI;
          c_st.site = &gb_emlrtRSI;
          varargout_1 = cellstr_sort_anonFcn1(&c_st, cmp_workspace_c,
                                              x_data[frame.xend - 1],
                                              x_data[frame.xstart - 1]);
          if (varargout_1) {
            t = x_data[frame.xstart - 1];
            x_data[frame.xstart - 1] = x_data[frame.xend - 1];
            x_data[frame.xend - 1] = t;
          }
          b_st.site = &ee_emlrtRSI;
          c_st.site = &gb_emlrtRSI;
          varargout_1 = cellstr_sort_anonFcn1(
              &c_st, cmp_workspace_c, x_data[frame.xend - 1], x_data[pmax]);
          if (varargout_1) {
            t = x_data[pmax];
            x_data[pmax] = x_data[frame.xend - 1];
            x_data[frame.xend - 1] = t;
          }
          pow2p = x_data[pmax];
          x_data[pmax] = x_data[frame.xend - 2];
          x_data[frame.xend - 2] = pow2p;
          pmax = frame.xstart - 1;
          pmin = frame.xend - 2;
          int32_T exitg2;
          do {
            int32_T exitg3;
            exitg2 = 0;
            pmax++;
            do {
              exitg3 = 0;
              b_st.site = &fe_emlrtRSI;
              c_st.site = &gb_emlrtRSI;
              varargout_1 = cellstr_sort_anonFcn1(&c_st, cmp_workspace_c,
                                                  x_data[pmax], pow2p);
              if (varargout_1) {
                pmax++;
              } else {
                exitg3 = 1;
              }
            } while (exitg3 == 0);
            pmin--;
            do {
              exitg3 = 0;
              b_st.site = &ge_emlrtRSI;
              c_st.site = &gb_emlrtRSI;
              varargout_1 = cellstr_sort_anonFcn1(&c_st, cmp_workspace_c, pow2p,
                                                  x_data[pmin]);
              if (varargout_1) {
                pmin--;
              } else {
                exitg3 = 1;
              }
            } while (exitg3 == 0);
            if (pmax + 1 >= pmin + 1) {
              exitg2 = 1;
            } else {
              t = x_data[pmax];
              x_data[pmax] = x_data[pmin];
              x_data[pmin] = t;
            }
          } while (exitg2 == 0);
          x_data[frame.xend - 2] = x_data[pmax];
          x_data[pmax] = pow2p;
          if (pmax + 2 < frame.xend) {
            st.site = &rd_emlrtRSI;
            if (st_n >= unnamed_idx_0) {
              emlrtErrorWithMessageIdR2018a(&st, &r_emlrtRTEI,
                                            "Coder:toolbox:StackPushLimit",
                                            "Coder:toolbox:StackPushLimit", 0);
            }
            st_d_data[st_n].xstart = pmax + 2;
            st_d_data[st_n].xend = frame.xend;
            st_d_data[st_n].depth = frame.depth + 1;
            st_n++;
          }
          if (frame.xstart < pmax + 1) {
            st.site = &sd_emlrtRSI;
            if (st_n >= unnamed_idx_0) {
              emlrtErrorWithMessageIdR2018a(&st, &r_emlrtRTEI,
                                            "Coder:toolbox:StackPushLimit",
                                            "Coder:toolbox:StackPushLimit", 0);
            }
            st_d_data[st_n].xstart = frame.xstart;
            st_d_data[st_n].xend = pmax + 1;
            st_d_data[st_n].depth = frame.depth + 1;
            st_n++;
          }
        }
      }
    }
  }
}

void introsort(const emlrtStack *sp, const cell_wrap_1 cmp_workspace_c[2],
               int32_T x[2])
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  x[0] = 1;
  x[1] = 2;
  st.site = &ib_emlrtRSI;
  b_insertionsort(&st, x, cmp_workspace_c);
}

/* End of code generation (introsort.c) */
