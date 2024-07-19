/* Include files */

#include "flightControlSystem_sfun.h"
#include "c5_flightControlSystem.h"
#include <string.h>
#include "mwmathutil.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(S);
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

/* Forward Declarations */

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static emlrtMCInfo c5_emlrtMCI = { 87, /* lineNo */
  33,                                  /* colNo */
  "eml_int_forloop_overflow_check",    /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pName */
};

static emlrtMCInfo c5_b_emlrtMCI = { 111,/* lineNo */
  5,                                   /* colNo */
  "svd",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m"/* pName */
};

static emlrtMCInfo c5_c_emlrtMCI = { 45,/* lineNo */
  13,                                  /* colNo */
  "infocheck",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\infocheck.m"/* pName */
};

static emlrtMCInfo c5_d_emlrtMCI = { 48,/* lineNo */
  13,                                  /* colNo */
  "infocheck",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\infocheck.m"/* pName */
};

static emlrtMCInfo c5_e_emlrtMCI = { 13,/* lineNo */
  9,                                   /* colNo */
  "sqrt",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m"/* pName */
};

static emlrtMCInfo c5_f_emlrtMCI = { 293,/* lineNo */
  13,                                  /* colNo */
  "xzsvdc",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pName */
};

static emlrtMCInfo c5_g_emlrtMCI = { 14,/* lineNo */
  37,                                  /* colNo */
  "validatefinite",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validatefinite.m"/* pName */
};

static emlrtMCInfo c5_h_emlrtMCI = { 14,/* lineNo */
  37,                                  /* colNo */
  "validatenonnegative",               /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validatenonnegative.m"/* pName */
};

static emlrtMCInfo c5_i_emlrtMCI = { 82,/* lineNo */
  5,                                   /* colNo */
  "power",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pName */
};

static emlrtMCInfo c5_j_emlrtMCI = { 13,/* lineNo */
  13,                                  /* colNo */
  "toLogicalCheck",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\toLogicalCheck.m"/* pName */
};

static emlrtMCInfo c5_k_emlrtMCI = { 13,/* lineNo */
  37,                                  /* colNo */
  "validateinteger",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validateinteger.m"/* pName */
};

static emlrtMCInfo c5_l_emlrtMCI = { 14,/* lineNo */
  37,                                  /* colNo */
  "validatenonnan",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validatenonnan.m"/* pName */
};

static emlrtMCInfo c5_m_emlrtMCI = { 14,/* lineNo */
  37,                                  /* colNo */
  "validatepositive",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validatepositive.m"/* pName */
};

static emlrtMCInfo c5_n_emlrtMCI = { 249,/* lineNo */
  1,                                   /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtMCInfo c5_o_emlrtMCI = { 122,/* lineNo */
  5,                                   /* colNo */
  "indexShapeCheck",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\indexShapeCheck.m"/* pName */
};

static emlrtMCInfo c5_p_emlrtMCI = { 28,/* lineNo */
  19,                                  /* colNo */
  "sub2ind",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sub2ind.m"/* pName */
};

static emlrtMCInfo c5_q_emlrtMCI = { 18,/* lineNo */
  23,                                  /* colNo */
  "sub2ind",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sub2ind.m"/* pName */
};

static emlrtMCInfo c5_r_emlrtMCI = { 14,/* lineNo */
  9,                                   /* colNo */
  "log",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elfun\\log.m"/* pName */
};

static emlrtMCInfo c5_s_emlrtMCI = { 225,/* lineNo */
  23,                                  /* colNo */
  "ixfun",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\ixfun.m"/* pName */
};

static emlrtMCInfo c5_t_emlrtMCI = { 13,/* lineNo */
  27,                                  /* colNo */
  "assertCompatibleDims",              /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\assertCompatibleDims.m"/* pName */
};

static emlrtMCInfo c5_u_emlrtMCI = { 57,/* lineNo */
  5,                                   /* colNo */
  "repmat",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pName */
};

static emlrtMCInfo c5_v_emlrtMCI = { 58,/* lineNo */
  23,                                  /* colNo */
  "assertValidSizeArg",                /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\assertValidSizeArg.m"/* pName */
};

static emlrtMCInfo c5_w_emlrtMCI = { 64,/* lineNo */
  15,                                  /* colNo */
  "assertValidSizeArg",                /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\assertValidSizeArg.m"/* pName */
};

static emlrtMCInfo c5_x_emlrtMCI = { 1499,/* lineNo */
  5,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtMCInfo c5_y_emlrtMCI = { 21,/* lineNo */
  15,                                  /* colNo */
  "ind2sub",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\ind2sub.m"/* pName */
};

static emlrtMCInfo c5_ab_emlrtMCI = { 288,/* lineNo */
  27,                                  /* colNo */
  "cat",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pName */
};

static emlrtMCInfo c5_bb_emlrtMCI = { 46,/* lineNo */
  23,                                  /* colNo */
  "sumprod",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumprod.m"/* pName */
};

static emlrtMCInfo c5_cb_emlrtMCI = { 81,/* lineNo */
  27,                                  /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtMCInfo c5_db_emlrtMCI = { 296,/* lineNo */
  1,                                   /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtMCInfo c5_eb_emlrtMCI = { 392,/* lineNo */
  1,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtMCInfo c5_fb_emlrtMCI = { 13,/* lineNo */
  37,                                  /* colNo */
  "validatenonempty",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validatenonempty.m"/* pName */
};

static emlrtMCInfo c5_gb_emlrtMCI = { 18,/* lineNo */
  23,                                  /* colNo */
  "validatencols",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validatencols.m"/* pName */
};

static emlrtMCInfo c5_hb_emlrtMCI = { 64,/* lineNo */
  1,                                   /* colNo */
  "chradiiphcode",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pName */
};

static emlrtMCInfo c5_ib_emlrtMCI = { 72,/* lineNo */
  1,                                   /* colNo */
  "chradiiphcode",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pName */
};

static emlrtMCInfo c5_jb_emlrtMCI = { 47,/* lineNo */
  19,                                  /* colNo */
  "allOrAny",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny.m"/* pName */
};

static emlrtRSInfo c5_emlrtRSI = { 7,  /* lineNo */
  "Image Processing System/Circle Flag",/* fcnName */
  "#flightControlSystem:2925"          /* pathName */
};

static emlrtRSInfo c5_b_emlrtRSI = { 10,/* lineNo */
  "Image Processing System/Circle Flag",/* fcnName */
  "#flightControlSystem:2925"          /* pathName */
};

static emlrtRSInfo c5_c_emlrtRSI = { 13,/* lineNo */
  "Image Processing System/Circle Flag",/* fcnName */
  "#flightControlSystem:2925"          /* pathName */
};

static emlrtRSInfo c5_d_emlrtRSI = { 24,/* lineNo */
  "Image Processing System/Circle Flag",/* fcnName */
  "#flightControlSystem:2925"          /* pathName */
};

static emlrtRSInfo c5_e_emlrtRSI = { 25,/* lineNo */
  "Image Processing System/Circle Flag",/* fcnName */
  "#flightControlSystem:2925"          /* pathName */
};

static emlrtRSInfo c5_f_emlrtRSI = { 26,/* lineNo */
  "Image Processing System/Circle Flag",/* fcnName */
  "#flightControlSystem:2925"          /* pathName */
};

static emlrtRSInfo c5_g_emlrtRSI = { 32,/* lineNo */
  "Image Processing System/Circle Flag",/* fcnName */
  "#flightControlSystem:2925"          /* pathName */
};

static emlrtRSInfo c5_h_emlrtRSI = { 14,/* lineNo */
  "imgaussfilt",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imgaussfilt.m"/* pathName */
};

static emlrtRSInfo c5_i_emlrtRSI = { 23,/* lineNo */
  "imgaussfilt",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imgaussfilt.m"/* pathName */
};

static emlrtRSInfo c5_j_emlrtRSI = { 24,/* lineNo */
  "imgaussfilt",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imgaussfilt.m"/* pathName */
};

static emlrtRSInfo c5_k_emlrtRSI = { 59,/* lineNo */
  "imfilter",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo c5_l_emlrtRSI = { 63,/* lineNo */
  "imfilter",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo c5_m_emlrtRSI = { 68,/* lineNo */
  "imfilter",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo c5_n_emlrtRSI = { 71,/* lineNo */
  "imfilter",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo c5_o_emlrtRSI = { 72,/* lineNo */
  "imfilter",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo c5_p_emlrtRSI = { 88,/* lineNo */
  "imfilter",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo c5_q_emlrtRSI = { 92,/* lineNo */
  "imfilter",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo c5_r_emlrtRSI = { 109,/* lineNo */
  "imfilter",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo c5_s_emlrtRSI = { 121,/* lineNo */
  "imfilter",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo c5_t_emlrtRSI = { 711,/* lineNo */
  "imfilter",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo c5_u_emlrtRSI = { 36,/* lineNo */
  "svd",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\matfun\\svd.m"/* pathName */
};

static emlrtRSInfo c5_v_emlrtRSI = { 20,/* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pathName */
};

static emlrtRSInfo c5_w_emlrtRSI = { 52,/* lineNo */
  "svd",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m"/* pathName */
};

static emlrtRSInfo c5_x_emlrtRSI = { 89,/* lineNo */
  "svd",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m"/* pathName */
};

static emlrtRSInfo c5_y_emlrtRSI = { 81,/* lineNo */
  "svd",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m"/* pathName */
};

static emlrtRSInfo c5_ab_emlrtRSI = { 209,/* lineNo */
  "xgesdd",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgesdd.m"/* pathName */
};

static emlrtRSInfo c5_bb_emlrtRSI = { 204,/* lineNo */
  "xgesvd",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgesvd.m"/* pathName */
};

static emlrtRSInfo c5_cb_emlrtRSI = { 31,/* lineNo */
  "xgesvd",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgesvd.m"/* pathName */
};

static emlrtRSInfo c5_db_emlrtRSI = { 452,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRSInfo c5_eb_emlrtRSI = { 431,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRSInfo c5_fb_emlrtRSI = { 418,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRSInfo c5_gb_emlrtRSI = { 415,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRSInfo c5_hb_emlrtRSI = { 404,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRSInfo c5_ib_emlrtRSI = { 377,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRSInfo c5_jb_emlrtRSI = { 375,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRSInfo c5_kb_emlrtRSI = { 358,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRSInfo c5_lb_emlrtRSI = { 275,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRSInfo c5_mb_emlrtRSI = { 264,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRSInfo c5_nb_emlrtRSI = { 239,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRSInfo c5_ob_emlrtRSI = { 218,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRSInfo c5_pb_emlrtRSI = { 208,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRSInfo c5_qb_emlrtRSI = { 144,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRSInfo c5_rb_emlrtRSI = { 138,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRSInfo c5_sb_emlrtRSI = { 118,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRSInfo c5_tb_emlrtRSI = { 106,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRSInfo c5_ub_emlrtRSI = { 101,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRSInfo c5_vb_emlrtRSI = { 23,/* lineNo */
  "xnrm2",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xnrm2.m"/* pathName */
};

static emlrtRSInfo c5_wb_emlrtRSI = { 38,/* lineNo */
  "xnrm2",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xnrm2.m"/* pathName */
};

static emlrtRSInfo c5_xb_emlrtRSI = { 21,/* lineNo */
  "scaleVectorByRecip",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\scaleVectorByRecip.m"/* pathName */
};

static emlrtRSInfo c5_yb_emlrtRSI = { 23,/* lineNo */
  "scaleVectorByRecip",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\scaleVectorByRecip.m"/* pathName */
};

static emlrtRSInfo c5_ac_emlrtRSI = { 31,/* lineNo */
  "xscal",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xscal.m"/* pathName */
};

static emlrtRSInfo c5_bc_emlrtRSI = { 18,/* lineNo */
  "xscal",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xscal.m"/* pathName */
};

static emlrtRSInfo c5_cc_emlrtRSI = { 32,/* lineNo */
  "xdotc",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xdotc.m"/* pathName */
};

static emlrtRSInfo c5_dc_emlrtRSI = { 35,/* lineNo */
  "xdot",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xdot.m"/* pathName */
};

static emlrtRSInfo c5_ec_emlrtRSI = { 15,/* lineNo */
  "xdot",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xdot.m"/* pathName */
};

static emlrtRSInfo c5_fc_emlrtRSI = { 42,/* lineNo */
  "xdotx",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xdotx.m"/* pathName */
};

static emlrtRSInfo c5_gc_emlrtRSI = { 23,/* lineNo */
  "xrotg",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xrotg.m"/* pathName */
};

static emlrtRSInfo c5_hc_emlrtRSI = { 32,/* lineNo */
  "xrotg",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xrotg.m"/* pathName */
};

static emlrtRSInfo c5_ic_emlrtRSI = { 32,/* lineNo */
  "xrotg",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xrotg.m"/* pathName */
};

static emlrtRSInfo c5_jc_emlrtRSI = { 877,/* lineNo */
  "imfilter",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo c5_kc_emlrtRSI = { 950,/* lineNo */
  "imfilter",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo c5_lc_emlrtRSI = { 1021,/* lineNo */
  "imfilter",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo c5_mc_emlrtRSI = { 1049,/* lineNo */
  "imfilter",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo c5_nc_emlrtRSI = { 1061,/* lineNo */
  "imfilter",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfilter.m"/* pathName */
};

static emlrtRSInfo c5_oc_emlrtRSI = { 70,/* lineNo */
  "imbinarize",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imbinarize.m"/* pathName */
};

static emlrtRSInfo c5_pc_emlrtRSI = { 102,/* lineNo */
  "imbinarize",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imbinarize.m"/* pathName */
};

static emlrtRSInfo c5_qc_emlrtRSI = { 41,/* lineNo */
  "im2uint8",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\im2uint8.m"/* pathName */
};

static emlrtRSInfo c5_rc_emlrtRSI = { 197,/* lineNo */
  "im2uint8",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\im2uint8.m"/* pathName */
};

static emlrtRSInfo c5_sc_emlrtRSI = { 19,/* lineNo */
  "grayto8",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\grayto8.m"/* pathName */
};

static emlrtRSInfo c5_tc_emlrtRSI = { 133,/* lineNo */
  "imhist",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imhist.m"/* pathName */
};

static emlrtRSInfo c5_uc_emlrtRSI = { 207,/* lineNo */
  "imhist",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imhist.m"/* pathName */
};

static emlrtRSInfo c5_vc_emlrtRSI = { 170,/* lineNo */
  "imhist",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imhist.m"/* pathName */
};

static emlrtRSInfo c5_wc_emlrtRSI = { 14,/* lineNo */
  "warning",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\warning.m"/* pathName */
};

static emlrtRSInfo c5_xc_emlrtRSI = { 37,/* lineNo */
  "otsuthresh",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\otsuthresh.m"/* pathName */
};

static emlrtRSInfo c5_yc_emlrtRSI = { 85,/* lineNo */
  "otsuthresh",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\otsuthresh.m"/* pathName */
};

static emlrtRSInfo c5_ad_emlrtRSI = { 93,/* lineNo */
  "validateattributes",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\lang\\validateattributes.m"/* pathName */
};

static emlrtRSInfo c5_bd_emlrtRSI = { 44,/* lineNo */
  "mpower",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\matfun\\mpower.m"/* pathName */
};

static emlrtRSInfo c5_cd_emlrtRSI = { 71,/* lineNo */
  "power",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pathName */
};

static emlrtRSInfo c5_dd_emlrtRSI = { 119,/* lineNo */
  "edge",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\edge.m"/* pathName */
};

static emlrtRSInfo c5_ed_emlrtRSI = { 135,/* lineNo */
  "edge",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\edge.m"/* pathName */
};

static emlrtRSInfo c5_fd_emlrtRSI = { 141,/* lineNo */
  "edge",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\edge.m"/* pathName */
};

static emlrtRSInfo c5_gd_emlrtRSI = { 745,/* lineNo */
  "edge",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\edge.m"/* pathName */
};

static emlrtRSInfo c5_hd_emlrtRSI = { 746,/* lineNo */
  "edge",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\edge.m"/* pathName */
};

static emlrtRSInfo c5_id_emlrtRSI = { 751,/* lineNo */
  "edge",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\edge.m"/* pathName */
};

static emlrtRSInfo c5_jd_emlrtRSI = { 752,/* lineNo */
  "edge",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\edge.m"/* pathName */
};

static emlrtRSInfo c5_kd_emlrtRSI = { 761,/* lineNo */
  "edge",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\edge.m"/* pathName */
};

static emlrtRSInfo c5_ld_emlrtRSI = { 456,/* lineNo */
  "imhist",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imhist.m"/* pathName */
};

static emlrtRSInfo c5_md_emlrtRSI = { 801,/* lineNo */
  "edge",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\edge.m"/* pathName */
};

static emlrtRSInfo c5_nd_emlrtRSI = { 807,/* lineNo */
  "edge",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\edge.m"/* pathName */
};

static emlrtRSInfo c5_od_emlrtRSI = { 911,/* lineNo */
  "edge",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\edge.m"/* pathName */
};

static emlrtRSInfo c5_pd_emlrtRSI = { 40,/* lineNo */
  "imreconstruct",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imreconstruct.m"/* pathName */
};

static emlrtRSInfo c5_qd_emlrtRSI = { 80,/* lineNo */
  "imreconstruct",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imreconstruct.m"/* pathName */
};

static emlrtRSInfo c5_rd_emlrtRSI = { 27,/* lineNo */
  "getBinaryConnectivityMatrix",       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\getBinaryConnectivityMatrix.m"/* pathName */
};

static emlrtRSInfo c5_sd_emlrtRSI = { 69,/* lineNo */
  "imfindcircles",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pathName */
};

static emlrtRSInfo c5_td_emlrtRSI = { 51,/* lineNo */
  "imfindcircles",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pathName */
};

static emlrtRSInfo c5_ud_emlrtRSI = { 43,/* lineNo */
  "imfindcircles",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pathName */
};

static emlrtRSInfo c5_vd_emlrtRSI = { 33,/* lineNo */
  "imfindcircles",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pathName */
};

static emlrtRSInfo c5_wd_emlrtRSI = { 16,/* lineNo */
  "imfindcircles",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pathName */
};

static emlrtRSInfo c5_xd_emlrtRSI = { 6,/* lineNo */
  "imfindcircles",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pathName */
};

static emlrtRSInfo c5_yd_emlrtRSI = { 103,/* lineNo */
  "imfindcircles",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pathName */
};

static emlrtRSInfo c5_ae_emlrtRSI = { 6,/* lineNo */
  "chaccum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c5_be_emlrtRSI = { 24,/* lineNo */
  "chaccum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c5_ce_emlrtRSI = { 28,/* lineNo */
  "chaccum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c5_de_emlrtRSI = { 31,/* lineNo */
  "chaccum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c5_ee_emlrtRSI = { 32,/* lineNo */
  "chaccum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c5_fe_emlrtRSI = { 36,/* lineNo */
  "chaccum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c5_ge_emlrtRSI = { 58,/* lineNo */
  "chaccum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c5_he_emlrtRSI = { 64,/* lineNo */
  "chaccum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c5_ie_emlrtRSI = { 65,/* lineNo */
  "chaccum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c5_je_emlrtRSI = { 78,/* lineNo */
  "chaccum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c5_ke_emlrtRSI = { 139,/* lineNo */
  "chaccum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c5_le_emlrtRSI = { 243,/* lineNo */
  "chaccum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c5_me_emlrtRSI = { 205,/* lineNo */
  "chaccum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c5_ne_emlrtRSI = { 163,/* lineNo */
  "chaccum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c5_oe_emlrtRSI = { 164,/* lineNo */
  "chaccum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c5_pe_emlrtRSI = { 179,/* lineNo */
  "chaccum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c5_qe_emlrtRSI = { 184,/* lineNo */
  "chaccum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c5_re_emlrtRSI = { 43,/* lineNo */
  "graythresh",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\graythresh.m"/* pathName */
};

static emlrtRSInfo c5_se_emlrtRSI = { 45,/* lineNo */
  "graythresh",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\graythresh.m"/* pathName */
};

static emlrtRSInfo c5_te_emlrtRSI = { 48,/* lineNo */
  "graythresh",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\graythresh.m"/* pathName */
};

static emlrtRSInfo c5_ue_emlrtRSI = { 35,/* lineNo */
  "find",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo c5_ve_emlrtRSI = { 138,/* lineNo */
  "find",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo c5_we_emlrtRSI = { 255,/* lineNo */
  "find",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo c5_xe_emlrtRSI = { 254,/* lineNo */
  "find",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo c5_ye_emlrtRSI = { 253,/* lineNo */
  "find",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo c5_af_emlrtRSI = { 42,/* lineNo */
  "indexShapeCheck",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\indexShapeCheck.m"/* pathName */
};

static emlrtRSInfo c5_bf_emlrtRSI = { 16,/* lineNo */
  "sub2ind",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m"/* pathName */
};

static emlrtRSInfo c5_cf_emlrtRSI = { 125,/* lineNo */
  "colon",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pathName */
};

static emlrtRSInfo c5_df_emlrtRSI = { 328,/* lineNo */
  "colon",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pathName */
};

static emlrtRSInfo c5_ef_emlrtRSI = { 17,/* lineNo */
  "log",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elfun\\log.m"/* pathName */
};

static emlrtRSInfo c5_ff_emlrtRSI = { 33,/* lineNo */
  "applyScalarFunctionInPlace",        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\applyScalarFunctionInPlace.m"/* pathName */
};

static emlrtRSInfo c5_gf_emlrtRSI = { 10,/* lineNo */
  "exp",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elfun\\exp.m"/* pathName */
};

static emlrtRSInfo c5_hf_emlrtRSI = { 34,/* lineNo */
  "rdivide_helper",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\rdivide_helper.m"/* pathName */
};

static emlrtRSInfo c5_if_emlrtRSI = { 53,/* lineNo */
  "div",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\div.m"/* pathName */
};

static emlrtRSInfo c5_jf_emlrtRSI = { 84,/* lineNo */
  "div",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\div.m"/* pathName */
};

static emlrtRSInfo c5_kf_emlrtRSI = { 57,/* lineNo */
  "ixfun",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\ixfun.m"/* pathName */
};

static emlrtRSInfo c5_lf_emlrtRSI = { 102,/* lineNo */
  "ixfun",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\ixfun.m"/* pathName */
};

static emlrtRSInfo c5_mf_emlrtRSI = { 236,/* lineNo */
  "ixfun",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\ixfun.m"/* pathName */
};

static emlrtRSInfo c5_nf_emlrtRSI = { 301,/* lineNo */
  "ixfun",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\ixfun.m"/* pathName */
};

static emlrtRSInfo c5_of_emlrtRSI = { 28,/* lineNo */
  "colon",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pathName */
};

static emlrtRSInfo c5_pf_emlrtRSI = { 150,/* lineNo */
  "chaccum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c5_qf_emlrtRSI = { 29,/* lineNo */
  "chcenters",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pathName */
};

static emlrtRSInfo c5_rf_emlrtRSI = { 34,/* lineNo */
  "chcenters",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pathName */
};

static emlrtRSInfo c5_sf_emlrtRSI = { 35,/* lineNo */
  "chcenters",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pathName */
};

static emlrtRSInfo c5_tf_emlrtRSI = { 36,/* lineNo */
  "chcenters",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pathName */
};

static emlrtRSInfo c5_uf_emlrtRSI = { 48,/* lineNo */
  "chcenters",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pathName */
};

static emlrtRSInfo c5_vf_emlrtRSI = { 53,/* lineNo */
  "chcenters",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pathName */
};

static emlrtRSInfo c5_wf_emlrtRSI = { 55,/* lineNo */
  "chcenters",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pathName */
};

static emlrtRSInfo c5_xf_emlrtRSI = { 62,/* lineNo */
  "medfilt2",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\medfilt2.m"/* pathName */
};

static emlrtRSInfo c5_yf_emlrtRSI = { 25,/* lineNo */
  "ordfilt2",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\ordfilt2.m"/* pathName */
};

static emlrtRSInfo c5_ag_emlrtRSI = { 155,/* lineNo */
  "ordfilt2",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\ordfilt2.m"/* pathName */
};

static emlrtRSInfo c5_bg_emlrtRSI = { 179,/* lineNo */
  "ordfilt2",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\ordfilt2.m"/* pathName */
};

static emlrtRSInfo c5_cg_emlrtRSI = { 66,/* lineNo */
  "imhmax",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\imhmax.m"/* pathName */
};

static emlrtRSInfo c5_dg_emlrtRSI = { 10,/* lineNo */
  "imreconstruct",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imreconstruct.m"/* pathName */
};

static emlrtRSInfo c5_eg_emlrtRSI = { 14,/* lineNo */
  "imreconstruct",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imreconstruct.m"/* pathName */
};

static emlrtRSInfo c5_fg_emlrtRSI = { 14,/* lineNo */
  "imregionalmax",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imregionalmax.m"/* pathName */
};

static emlrtRSInfo c5_gg_emlrtRSI = { 35,/* lineNo */
  "imregionalmax",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imregionalmax.m"/* pathName */
};

static emlrtRSInfo c5_hg_emlrtRSI = { 37,/* lineNo */
  "imregionalmax",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imregionalmax.m"/* pathName */
};

static emlrtRSInfo c5_ig_emlrtRSI = { 41,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c5_jg_emlrtRSI = { 107,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c5_kg_emlrtRSI = { 109,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c5_lg_emlrtRSI = { 314,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c5_mg_emlrtRSI = { 316,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c5_ng_emlrtRSI = { 378,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c5_og_emlrtRSI = { 26,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pathName */
};

static emlrtRSInfo c5_pg_emlrtRSI = { 101,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pathName */
};

static emlrtRSInfo c5_qg_emlrtRSI = { 100,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pathName */
};

static emlrtRSInfo c5_rg_emlrtRSI = { 93,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pathName */
};

static emlrtRSInfo c5_sg_emlrtRSI = { 85,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pathName */
};

static emlrtRSInfo c5_tg_emlrtRSI = { 84,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pathName */
};

static emlrtRSInfo c5_ug_emlrtRSI = { 83,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pathName */
};

static emlrtRSInfo c5_vg_emlrtRSI = { 71,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pathName */
};

static emlrtRSInfo c5_wg_emlrtRSI = { 58,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pathName */
};

static emlrtRSInfo c5_xg_emlrtRSI = { 39,/* lineNo */
  "bwconncomp",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pathName */
};

static emlrtRSInfo c5_yg_emlrtRSI = { 51,/* lineNo */
  "intermediateLabelRuns",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pathName */
};

static emlrtRSInfo c5_ah_emlrtRSI = { 114,/* lineNo */
  "intermediateLabelRuns",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pathName */
};

static emlrtRSInfo c5_bh_emlrtRSI = { 149,/* lineNo */
  "intermediateLabelRuns",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pathName */
};

static emlrtRSInfo c5_ch_emlrtRSI = { 150,/* lineNo */
  "intermediateLabelRuns",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pathName */
};

static emlrtRSInfo c5_dh_emlrtRSI = { 153,/* lineNo */
  "intermediateLabelRuns",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pathName */
};

static emlrtRSInfo c5_eh_emlrtRSI = { 20,/* lineNo */
  "sum",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\datafun\\sum.m"/* pathName */
};

static emlrtRSInfo c5_fh_emlrtRSI = { 99,/* lineNo */
  "sumprod",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumprod.m"/* pathName */
};

static emlrtRSInfo c5_gh_emlrtRSI = { 86,/* lineNo */
  "combineVectorElements",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combineVectorElements.m"/* pathName */
};

static emlrtRSInfo c5_hh_emlrtRSI = { 107,/* lineNo */
  "blockedSummation",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\blockedSummation.m"/* pathName */
};

static emlrtRSInfo c5_ih_emlrtRSI = { 22,/* lineNo */
  "sumMatrixIncludeNaN",               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMatrixIncludeNaN.m"/* pathName */
};

static emlrtRSInfo c5_jh_emlrtRSI = { 42,/* lineNo */
  "sumMatrixIncludeNaN",               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMatrixIncludeNaN.m"/* pathName */
};

static emlrtRSInfo c5_kh_emlrtRSI = { 57,/* lineNo */
  "sumMatrixIncludeNaN",               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMatrixIncludeNaN.m"/* pathName */
};

static emlrtRSInfo c5_lh_emlrtRSI = { 178,/* lineNo */
  "sumMatrixIncludeNaN",               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMatrixIncludeNaN.m"/* pathName */
};

static emlrtRSInfo c5_mh_emlrtRSI = { 189,/* lineNo */
  "sumMatrixIncludeNaN",               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMatrixIncludeNaN.m"/* pathName */
};

static emlrtRSInfo c5_nh_emlrtRSI = { 210,/* lineNo */
  "sumMatrixIncludeNaN",               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMatrixIncludeNaN.m"/* pathName */
};

static emlrtRSInfo c5_oh_emlrtRSI = { 14,/* lineNo */
  "cumsum",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\datafun\\cumsum.m"/* pathName */
};

static emlrtRSInfo c5_ph_emlrtRSI = { 16,/* lineNo */
  "cumop",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\cumop.m"/* pathName */
};

static emlrtRSInfo c5_qh_emlrtRSI = { 32,/* lineNo */
  "useConstantDim",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\useConstantDim.m"/* pathName */
};

static emlrtRSInfo c5_rh_emlrtRSI = { 100,/* lineNo */
  "cumop",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\cumop.m"/* pathName */
};

static emlrtRSInfo c5_sh_emlrtRSI = { 125,/* lineNo */
  "cumop",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\cumop.m"/* pathName */
};

static emlrtRSInfo c5_th_emlrtRSI = { 290,/* lineNo */
  "cumop",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\cumop.m"/* pathName */
};

static emlrtRSInfo c5_uh_emlrtRSI = { 38,/* lineNo */
  "repmat",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pathName */
};

static emlrtRSInfo c5_vh_emlrtRSI = { 149,/* lineNo */
  "repmat",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pathName */
};

static emlrtRSInfo c5_wh_emlrtRSI = { 1511,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c5_xh_emlrtRSI = { 1696,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c5_yh_emlrtRSI = { 2068,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c5_ai_emlrtRSI = { 485,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c5_bi_emlrtRSI = { 1381,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c5_ci_emlrtRSI = { 1372,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c5_di_emlrtRSI = { 1367,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c5_ei_emlrtRSI = { 1364,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c5_fi_emlrtRSI = { 1001,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c5_gi_emlrtRSI = { 999,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c5_hi_emlrtRSI = { 19,/* lineNo */
  "ind2sub",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elmat\\ind2sub.m"/* pathName */
};

static emlrtRSInfo c5_ii_emlrtRSI = { 39,/* lineNo */
  "cat",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pathName */
};

static emlrtRSInfo c5_ji_emlrtRSI = { 113,/* lineNo */
  "cat",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pathName */
};

static emlrtRSInfo c5_ki_emlrtRSI = { 1350,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c5_li_emlrtRSI = { 22,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pathName */
};

static emlrtRSInfo c5_mi_emlrtRSI = { 26,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pathName */
};

static emlrtRSInfo c5_ni_emlrtRSI = { 273,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pathName */
};

static emlrtRSInfo c5_oi_emlrtRSI = { 274,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pathName */
};

static emlrtRSInfo c5_pi_emlrtRSI = { 16,/* lineNo */
  "round",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elfun\\round.m"/* pathName */
};

static emlrtRSInfo c5_qi_emlrtRSI = { 37,/* lineNo */
  "sort",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\datafun\\sort.m"/* pathName */
};

static emlrtRSInfo c5_ri_emlrtRSI = { 72,/* lineNo */
  "sort",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pathName */
};

static emlrtRSInfo c5_si_emlrtRSI = { 104,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c5_ti_emlrtRSI = { 105,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c5_ui_emlrtRSI = { 301,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c5_vi_emlrtRSI = { 309,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c5_wi_emlrtRSI = { 310,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c5_xi_emlrtRSI = { 318,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c5_yi_emlrtRSI = { 326,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c5_aj_emlrtRSI = { 333,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c5_bj_emlrtRSI = { 381,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c5_cj_emlrtRSI = { 409,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c5_dj_emlrtRSI = { 416,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c5_ej_emlrtRSI = { 576,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c5_fj_emlrtRSI = { 578,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c5_gj_emlrtRSI = { 606,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c5_hj_emlrtRSI = { 488,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c5_ij_emlrtRSI = { 495,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c5_jj_emlrtRSI = { 496,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c5_kj_emlrtRSI = { 503,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c5_lj_emlrtRSI = { 550,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c5_mj_emlrtRSI = { 519,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c5_nj_emlrtRSI = { 347,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c5_oj_emlrtRSI = { 356,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo c5_pj_emlrtRSI = { 39,/* lineNo */
  "find",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo c5_qj_emlrtRSI = { 144,/* lineNo */
  "find",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo c5_rj_emlrtRSI = { 382,/* lineNo */
  "find",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo c5_sj_emlrtRSI = { 402,/* lineNo */
  "find",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo c5_tj_emlrtRSI = { 76,/* lineNo */
  "repmat",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pathName */
};

static emlrtRSInfo c5_uj_emlrtRSI = { 6,/* lineNo */
  "chradiiphcode",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pathName */
};

static emlrtRSInfo c5_vj_emlrtRSI = { 14,/* lineNo */
  "chradiiphcode",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pathName */
};

static emlrtRSInfo c5_wj_emlrtRSI = { 15,/* lineNo */
  "chradiiphcode",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pathName */
};

static emlrtRSInfo c5_xj_emlrtRSI = { 16,/* lineNo */
  "chradiiphcode",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pathName */
};

static emlrtRSInfo c5_yj_emlrtRSI = { 32,/* lineNo */
  "chradiiphcode",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pathName */
};

static emlrtRSInfo c5_ak_emlrtRSI = { 34,/* lineNo */
  "chradiiphcode",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pathName */
};

static emlrtRSInfo c5_bk_emlrtRSI = { 35,/* lineNo */
  "chradiiphcode",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pathName */
};

static emlrtRSInfo c5_ck_emlrtRSI = { 44,/* lineNo */
  "chradiiphcode",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pathName */
};

static emlrtRSInfo c5_dk_emlrtRSI = { 58,/* lineNo */
  "chradiiphcode",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pathName */
};

static emlrtRSInfo c5_ek_emlrtRSI = { 72,/* lineNo */
  "chradiiphcode",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pathName */
};

static emlrtRSInfo c5_fk_emlrtRSI = { 73,/* lineNo */
  "chradiiphcode",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pathName */
};

static emlrtRSInfo c5_gk_emlrtRSI = { 13,/* lineNo */
  "all",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\ops\\all.m"/* pathName */
};

static emlrtRSInfo c5_hk_emlrtRSI = { 143,/* lineNo */
  "allOrAny",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny.m"/* pathName */
};

static emlrtRSInfo c5_ik_emlrtRSI = { 9,/* lineNo */
  "angle",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elfun\\angle.m"/* pathName */
};

static emlrtRSInfo c5_jk_emlrtRSI = { 74,/* lineNo */
  "applyScalarFunction",               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\applyScalarFunction.m"/* pathName */
};

static emlrtRSInfo c5_kk_emlrtRSI = { 41,/* lineNo */
  "cat",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pathName */
};

static emlrtRSInfo c5_lk_emlrtRSI = { 35,/* lineNo */
  "fprintf",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\iofun\\fprintf.m"/* pathName */
};

static emlrtRSInfo c5_mk_emlrtRSI = { 66,/* lineNo */
  "fprintf",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\iofun\\fprintf.m"/* pathName */
};

static emlrtRTEInfo c5_emlrtRTEI = { 19,/* lineNo */
  5,                                   /* colNo */
  "Image Processing System/Circle Flag",/* fName */
  "#flightControlSystem:2925"          /* pName */
};

static emlrtRTEInfo c5_b_emlrtRTEI = { 20,/* lineNo */
  5,                                   /* colNo */
  "Image Processing System/Circle Flag",/* fName */
  "#flightControlSystem:2925"          /* pName */
};

static emlrtRTEInfo c5_c_emlrtRTEI = { 125,/* lineNo */
  9,                                   /* colNo */
  "cat",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pName */
};

static emlrtRTEInfo c5_d_emlrtRTEI = { 128,/* lineNo */
  30,                                  /* colNo */
  "cat",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pName */
};

static emlrtRTEInfo c5_e_emlrtRTEI = { 25,/* lineNo */
  9,                                   /* colNo */
  "Image Processing System/Circle Flag",/* fName */
  "#flightControlSystem:2925"          /* pName */
};

static emlrtRTEInfo c5_f_emlrtRTEI = { 26,/* lineNo */
  18,                                  /* colNo */
  "Image Processing System/Circle Flag",/* fName */
  "#flightControlSystem:2925"          /* pName */
};

static emlrtRTEInfo c5_g_emlrtRTEI = { 26,/* lineNo */
  25,                                  /* colNo */
  "Image Processing System/Circle Flag",/* fName */
  "#flightControlSystem:2925"          /* pName */
};

static emlrtRTEInfo c5_h_emlrtRTEI = { 41,/* lineNo */
  5,                                   /* colNo */
  "cat",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pName */
};

static emlrtRTEInfo c5_i_emlrtRTEI = { 26,/* lineNo */
  9,                                   /* colNo */
  "Image Processing System/Circle Flag",/* fName */
  "#flightControlSystem:2925"          /* pName */
};

static emlrtRTEInfo c5_j_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "imgaussfilt",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imgaussfilt.m"/* pName */
};

static emlrtRTEInfo c5_k_emlrtRTEI = { 776,/* lineNo */
  9,                                   /* colNo */
  "edge",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\edge.m"/* pName */
};

static emlrtRTEInfo c5_l_emlrtRTEI = { 777,/* lineNo */
  37,                                  /* colNo */
  "edge",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\edge.m"/* pName */
};

static emlrtRTEInfo c5_m_emlrtRTEI = { 76,/* lineNo */
  9,                                   /* colNo */
  "eml_mtimes_helper",                 /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m"/* pName */
};

static emlrtRTEInfo c5_n_emlrtRTEI = { 777,/* lineNo */
  9,                                   /* colNo */
  "edge",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\edge.m"/* pName */
};

static emlrtRTEInfo c5_o_emlrtRTEI = { 773,/* lineNo */
  9,                                   /* colNo */
  "edge",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\edge.m"/* pName */
};

static emlrtRTEInfo c5_p_emlrtRTEI = { 774,/* lineNo */
  9,                                   /* colNo */
  "edge",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\edge.m"/* pName */
};

static emlrtRTEInfo c5_q_emlrtRTEI = { 117,/* lineNo */
  9,                                   /* colNo */
  "imfindcircles",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pName */
};

static emlrtRTEInfo c5_r_emlrtRTEI = { 8,/* lineNo */
  1,                                   /* colNo */
  "imfindcircles",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pName */
};

static emlrtRTEInfo c5_s_emlrtRTEI = { 9,/* lineNo */
  1,                                   /* colNo */
  "imfindcircles",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pName */
};

static emlrtRTEInfo c5_t_emlrtRTEI = { 128,/* lineNo */
  57,                                  /* colNo */
  "allOrAny",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny.m"/* pName */
};

static emlrtRTEInfo c5_u_emlrtRTEI = { 43,/* lineNo */
  6,                                   /* colNo */
  "imfindcircles",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pName */
};

static emlrtRTEInfo c5_v_emlrtRTEI = { 51,/* lineNo */
  21,                                  /* colNo */
  "imfindcircles",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pName */
};

static emlrtRTEInfo c5_w_emlrtRTEI = { 369,/* lineNo */
  24,                                  /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c5_x_emlrtRTEI = { 39,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c5_y_emlrtRTEI = { 51,/* lineNo */
  5,                                   /* colNo */
  "imfindcircles",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pName */
};

static emlrtRTEInfo c5_ab_emlrtRTEI = { 52,/* lineNo */
  5,                                   /* colNo */
  "imfindcircles",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pName */
};

static emlrtRTEInfo c5_bb_emlrtRTEI = { 69,/* lineNo */
  21,                                  /* colNo */
  "imfindcircles",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pName */
};

static emlrtRTEInfo c5_cb_emlrtRTEI = { 57,/* lineNo */
  9,                                   /* colNo */
  "imfindcircles",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pName */
};

static emlrtRTEInfo c5_db_emlrtRTEI = { 36,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c5_eb_emlrtRTEI = { 37,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c5_fb_emlrtRTEI = { 32,/* lineNo */
  35,                                  /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c5_gb_emlrtRTEI = { 32,/* lineNo */
  39,                                  /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c5_hb_emlrtRTEI = { 16,/* lineNo */
  1,                                   /* colNo */
  "sub2ind",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m"/* pName */
};

static emlrtRTEInfo c5_ib_emlrtRTEI = { 32,/* lineNo */
  1,                                   /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c5_jb_emlrtRTEI = { 38,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c5_kb_emlrtRTEI = { 36,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c5_lb_emlrtRTEI = { 61,/* lineNo */
  13,                                  /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c5_mb_emlrtRTEI = { 58,/* lineNo */
  13,                                  /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c5_nb_emlrtRTEI = { 59,/* lineNo */
  20,                                  /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c5_ob_emlrtRTEI = { 59,/* lineNo */
  13,                                  /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c5_pb_emlrtRTEI = { 63,/* lineNo */
  31,                                  /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c5_qb_emlrtRTEI = { 64,/* lineNo */
  16,                                  /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c5_rb_emlrtRTEI = { 65,/* lineNo */
  9,                                   /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c5_sb_emlrtRTEI = { 320,/* lineNo */
  20,                                  /* colNo */
  "colon",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pName */
};

static emlrtRTEInfo c5_tb_emlrtRTEI = { 78,/* lineNo */
  23,                                  /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c5_ub_emlrtRTEI = { 79,/* lineNo */
  31,                                  /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c5_vb_emlrtRTEI = { 80,/* lineNo */
  31,                                  /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c5_wb_emlrtRTEI = { 81,/* lineNo */
  33,                                  /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c5_xb_emlrtRTEI = { 93,/* lineNo */
  25,                                  /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c5_yb_emlrtRTEI = { 94,/* lineNo */
  25,                                  /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c5_ac_emlrtRTEI = { 96,/* lineNo */
  24,                                  /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c5_bc_emlrtRTEI = { 97,/* lineNo */
  29,                                  /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c5_cc_emlrtRTEI = { 100,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c5_dc_emlrtRTEI = { 123,/* lineNo */
  29,                                  /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c5_ec_emlrtRTEI = { 124,/* lineNo */
  29,                                  /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c5_fc_emlrtRTEI = { 125,/* lineNo */
  28,                                  /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c5_gc_emlrtRTEI = { 195,/* lineNo */
  24,                                  /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c5_hc_emlrtRTEI = { 197,/* lineNo */
  24,                                  /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c5_ic_emlrtRTEI = { 253,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c5_jc_emlrtRTEI = { 254,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c5_kc_emlrtRTEI = { 33,/* lineNo */
  1,                                   /* colNo */
  "sub2ind",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sub2ind.m"/* pName */
};

static emlrtRTEInfo c5_lc_emlrtRTEI = { 35,/* lineNo */
  23,                                  /* colNo */
  "sub2ind",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sub2ind.m"/* pName */
};

static emlrtRTEInfo c5_mc_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "log",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elfun\\log.m"/* pName */
};

static emlrtRTEInfo c5_nc_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "exp",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elfun\\exp.m"/* pName */
};

static emlrtRTEInfo c5_oc_emlrtRTEI = { 10,/* lineNo */
  1,                                   /* colNo */
  "chcenters",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c5_pc_emlrtRTEI = { 11,/* lineNo */
  1,                                   /* colNo */
  "chcenters",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c5_qc_emlrtRTEI = { 40,/* lineNo */
  5,                                   /* colNo */
  "chcenters",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c5_rc_emlrtRTEI = { 42,/* lineNo */
  21,                                  /* colNo */
  "chcenters",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c5_sc_emlrtRTEI = { 48,/* lineNo */
  13,                                  /* colNo */
  "chcenters",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c5_tc_emlrtRTEI = { 26,/* lineNo */
  13,                                  /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtRTEInfo c5_uc_emlrtRTEI = { 53,/* lineNo */
  44,                                  /* colNo */
  "chcenters",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c5_vc_emlrtRTEI = { 53,/* lineNo */
  64,                                  /* colNo */
  "chcenters",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c5_wc_emlrtRTEI = { 53,/* lineNo */
  18,                                  /* colNo */
  "chcenters",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c5_xc_emlrtRTEI = { 53,/* lineNo */
  9,                                   /* colNo */
  "chcenters",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c5_yc_emlrtRTEI = { 55,/* lineNo */
  33,                                  /* colNo */
  "chcenters",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c5_ad_emlrtRTEI = { 38,/* lineNo */
  5,                                   /* colNo */
  "sort",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\datafun\\sort.m"/* pName */
};

static emlrtRTEInfo c5_bd_emlrtRTEI = { 55,/* lineNo */
  10,                                  /* colNo */
  "chcenters",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c5_cd_emlrtRTEI = { 56,/* lineNo */
  19,                                  /* colNo */
  "chcenters",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c5_dd_emlrtRTEI = { 56,/* lineNo */
  9,                                   /* colNo */
  "chcenters",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c5_ed_emlrtRTEI = { 41,/* lineNo */
  1,                                   /* colNo */
  "repmat",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pName */
};

static emlrtRTEInfo c5_fd_emlrtRTEI = { 1511,/* lineNo */
  9,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c5_gd_emlrtRTEI = { 1968,/* lineNo */
  5,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c5_hd_emlrtRTEI = { 1972,/* lineNo */
  5,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c5_id_emlrtRTEI = { 1991,/* lineNo */
  5,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c5_jd_emlrtRTEI = { 1995,/* lineNo */
  5,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c5_kd_emlrtRTEI = { 2012,/* lineNo */
  13,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c5_ld_emlrtRTEI = { 2063,/* lineNo */
  5,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c5_md_emlrtRTEI = { 2068,/* lineNo */
  1,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c5_nd_emlrtRTEI = { 477,/* lineNo */
  17,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c5_od_emlrtRTEI = { 478,/* lineNo */
  17,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c5_pd_emlrtRTEI = { 17,/* lineNo */
  25,                                  /* colNo */
  "cumop",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\cumop.m"/* pName */
};

static emlrtRTEInfo c5_qd_emlrtRTEI = { 485,/* lineNo */
  13,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c5_rd_emlrtRTEI = { 488,/* lineNo */
  21,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c5_sd_emlrtRTEI = { 48,/* lineNo */
  27,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c5_td_emlrtRTEI = { 49,/* lineNo */
  25,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c5_ud_emlrtRTEI = { 50,/* lineNo */
  28,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c5_vd_emlrtRTEI = { 55,/* lineNo */
  1,                                   /* colNo */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c5_wd_emlrtRTEI = { 37,/* lineNo */
  5,                                   /* colNo */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c5_xd_emlrtRTEI = { 38,/* lineNo */
  5,                                   /* colNo */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c5_yd_emlrtRTEI = { 39,/* lineNo */
  5,                                   /* colNo */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c5_ae_emlrtRTEI = { 40,/* lineNo */
  5,                                   /* colNo */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c5_be_emlrtRTEI = { 53,/* lineNo */
  35,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c5_ce_emlrtRTEI = { 69,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c5_de_emlrtRTEI = { 83,/* lineNo */
  32,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c5_ee_emlrtRTEI = { 84,/* lineNo */
  46,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c5_fe_emlrtRTEI = { 84,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c5_ge_emlrtRTEI = { 100,/* lineNo */
  23,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c5_he_emlrtRTEI = { 101,/* lineNo */
  46,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c5_ie_emlrtRTEI = { 101,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c5_je_emlrtRTEI = { 103,/* lineNo */
  5,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c5_ke_emlrtRTEI = { 46,/* lineNo */
  5,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c5_le_emlrtRTEI = { 47,/* lineNo */
  5,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c5_me_emlrtRTEI = { 48,/* lineNo */
  5,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c5_ne_emlrtRTEI = { 26,/* lineNo */
  20,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c5_oe_emlrtRTEI = { 26,/* lineNo */
  37,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c5_pe_emlrtRTEI = { 26,/* lineNo */
  54,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c5_qe_emlrtRTEI = { 32,/* lineNo */
  9,                                   /* colNo */
  "useConstantDim",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\useConstantDim.m"/* pName */
};

static emlrtRTEInfo c5_re_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "repmat",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pName */
};

static emlrtRTEInfo c5_se_emlrtRTEI = { 102,/* lineNo */
  25,                                  /* colNo */
  "repmat",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pName */
};

static emlrtRTEInfo c5_te_emlrtRTEI = { 157,/* lineNo */
  25,                                  /* colNo */
  "repmat",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pName */
};

static emlrtRTEInfo c5_ue_emlrtRTEI = { 1359,/* lineNo */
  5,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c5_ve_emlrtRTEI = { 16,/* lineNo */
  5,                                   /* colNo */
  "round",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elfun\\round.m"/* pName */
};

static emlrtRTEInfo c5_we_emlrtRTEI = { 1,/* lineNo */
  20,                                  /* colNo */
  "sort",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pName */
};

static emlrtRTEInfo c5_xe_emlrtRTEI = { 561,/* lineNo */
  20,                                  /* colNo */
  "sortIdx",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pName */
};

static emlrtRTEInfo c5_ye_emlrtRTEI = { 471,/* lineNo */
  32,                                  /* colNo */
  "sortIdx",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pName */
};

static emlrtRTEInfo c5_af_emlrtRTEI = { 509,/* lineNo */
  32,                                  /* colNo */
  "sortIdx",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pName */
};

static emlrtRTEInfo c5_bf_emlrtRTEI = { 72,/* lineNo */
  30,                                  /* colNo */
  "chradiiphcode",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pName */
};

static emlrtRTEInfo c5_cf_emlrtRTEI = { 73,/* lineNo */
  9,                                   /* colNo */
  "chradiiphcode",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pName */
};

static emlrtRTEInfo c5_df_emlrtRTEI = { 14,/* lineNo */
  62,                                  /* colNo */
  "chradiiphcode",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pName */
};

static emlrtRTEInfo c5_ef_emlrtRTEI = { 14,/* lineNo */
  82,                                  /* colNo */
  "chradiiphcode",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pName */
};

static emlrtRTEInfo c5_ff_emlrtRTEI = { 14,/* lineNo */
  18,                                  /* colNo */
  "chradiiphcode",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pName */
};

static emlrtRTEInfo c5_gf_emlrtRTEI = { 30,/* lineNo */
  21,                                  /* colNo */
  "applyScalarFunction",               /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\applyScalarFunction.m"/* pName */
};

static emlrtRTEInfo c5_hf_emlrtRTEI = { 15,/* lineNo */
  7,                                   /* colNo */
  "chradiiphcode",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pName */
};

static emlrtRTEInfo c5_if_emlrtRTEI = { 15,/* lineNo */
  1,                                   /* colNo */
  "chradiiphcode",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pName */
};

static emlrtRTEInfo c5_jf_emlrtRTEI = { 257,/* lineNo */
  9,                                   /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c5_kf_emlrtRTEI = { 255,/* lineNo */
  9,                                   /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c5_lf_emlrtRTEI = { 13,/* lineNo */
  37,                                  /* colNo */
  "log",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elfun\\log.m"/* pName */
};

static emlrtRTEInfo c5_mf_emlrtRTEI = { 998,/* lineNo */
  21,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c5_nf_emlrtRTEI = { 1003,/* lineNo */
  13,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c5_of_emlrtRTEI = { 999,/* lineNo */
  41,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c5_pf_emlrtRTEI = { 13,/* lineNo */
  1,                                   /* colNo */
  "ind2sub",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\ind2sub.m"/* pName */
};

static emlrtRTEInfo c5_qf_emlrtRTEI = { 25,/* lineNo */
  5,                                   /* colNo */
  "ind2sub",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\ind2sub.m"/* pName */
};

static emlrtRTEInfo c5_rf_emlrtRTEI = { 26,/* lineNo */
  5,                                   /* colNo */
  "ind2sub",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\ind2sub.m"/* pName */
};

static emlrtRTEInfo c5_sf_emlrtRTEI = { 21,/* lineNo */
  5,                                   /* colNo */
  "ind2sub",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elmat\\ind2sub.m"/* pName */
};

static emlrtRTEInfo c5_tf_emlrtRTEI = { 121,/* lineNo */
  9,                                   /* colNo */
  "cat",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pName */
};

static emlrtRTEInfo c5_uf_emlrtRTEI = { 39,/* lineNo */
  5,                                   /* colNo */
  "cat",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pName */
};

static emlrtRTEInfo c5_vf_emlrtRTEI = { 1001,/* lineNo */
  13,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c5_wf_emlrtRTEI = { 1349,/* lineNo */
  57,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c5_xf_emlrtRTEI = { 1349,/* lineNo */
  47,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c5_yf_emlrtRTEI = { 1350,/* lineNo */
  33,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c5_ag_emlrtRTEI = { 1351,/* lineNo */
  27,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c5_bg_emlrtRTEI = { 1371,/* lineNo */
  9,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c5_cg_emlrtRTEI = { 1381,/* lineNo */
  21,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c5_dg_emlrtRTEI = { 61,/* lineNo */
  5,                                   /* colNo */
  "sortIdx",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pName */
};

static emlrtRTEInfo c5_eg_emlrtRTEI = { 296,/* lineNo */
  1,                                   /* colNo */
  "sortIdx",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pName */
};

static emlrtRTEInfo c5_fg_emlrtRTEI = { 298,/* lineNo */
  24,                                  /* colNo */
  "sortIdx",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pName */
};

static emlrtRTEInfo c5_gg_emlrtRTEI = { 54,/* lineNo */
  9,                                   /* colNo */
  "div",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\div.m"/* pName */
};

static emlrtRTEInfo c5_hg_emlrtRTEI = { 24,/* lineNo */
  10,                                  /* colNo */
  "Image Processing System/Circle Flag",/* fName */
  "#flightControlSystem:2925"          /* pName */
};

static emlrtRTEInfo c5_ig_emlrtRTEI = { 24,/* lineNo */
  23,                                  /* colNo */
  "Image Processing System/Circle Flag",/* fName */
  "#flightControlSystem:2925"          /* pName */
};

static emlrtRTEInfo c5_jg_emlrtRTEI = { 26,/* lineNo */
  17,                                  /* colNo */
  "Image Processing System/Circle Flag",/* fName */
  "#flightControlSystem:2925"          /* pName */
};

static emlrtRTEInfo c5_kg_emlrtRTEI = { 116,/* lineNo */
  1,                                   /* colNo */
  "cat",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pName */
};

static emlrtRTEInfo c5_lg_emlrtRTEI = { 1,/* lineNo */
  43,                                  /* colNo */
  "imfindcircles",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pName */
};

static emlrtRTEInfo c5_mg_emlrtRTEI = { 31,/* lineNo */
  6,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c5_ng_emlrtRTEI = { 79,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c5_og_emlrtRTEI = { 80,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c5_pg_emlrtRTEI = { 81,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c5_qg_emlrtRTEI = { 93,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c5_rg_emlrtRTEI = { 94,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c5_sg_emlrtRTEI = { 96,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c5_tg_emlrtRTEI = { 97,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c5_ug_emlrtRTEI = { 123,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c5_vg_emlrtRTEI = { 124,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c5_wg_emlrtRTEI = { 125,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c5_xg_emlrtRTEI = { 78,/* lineNo */
  17,                                  /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c5_yg_emlrtRTEI = { 1,/* lineNo */
  39,                                  /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c5_ah_emlrtRTEI = { 32,/* lineNo */
  8,                                   /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c5_bh_emlrtRTEI = { 16,/* lineNo */
  14,                                  /* colNo */
  "sub2ind",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m"/* pName */
};

static emlrtRTEInfo c5_ch_emlrtRTEI = { 36,/* lineNo */
  1,                                   /* colNo */
  "chcenters",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c5_dh_emlrtRTEI = { 1,/* lineNo */
  30,                                  /* colNo */
  "chcenters",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c5_eh_emlrtRTEI = { 53,/* lineNo */
  21,                                  /* colNo */
  "chcenters",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c5_fh_emlrtRTEI = { 53,/* lineNo */
  58,                                  /* colNo */
  "chcenters",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c5_gh_emlrtRTEI = { 35,/* lineNo */
  13,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c5_hh_emlrtRTEI = { 109,/* lineNo */
  2,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c5_ih_emlrtRTEI = { 1947,/* lineNo */
  5,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c5_jh_emlrtRTEI = { 402,/* lineNo */
  13,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c5_kh_emlrtRTEI = { 415,/* lineNo */
  17,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c5_lh_emlrtRTEI = { 416,/* lineNo */
  17,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c5_mh_emlrtRTEI = { 1,/* lineNo */
  15,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c5_nh_emlrtRTEI = { 53,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c5_oh_emlrtRTEI = { 51,/* lineNo */
  48,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c5_ph_emlrtRTEI = { 51,/* lineNo */
  57,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c5_qh_emlrtRTEI = { 51,/* lineNo */
  64,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c5_rh_emlrtRTEI = { 114,/* lineNo */
  55,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c5_sh_emlrtRTEI = { 14,/* lineNo */
  30,                                  /* colNo */
  "chradiiphcode",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pName */
};

static emlrtRTEInfo c5_th_emlrtRTEI = { 14,/* lineNo */
  76,                                  /* colNo */
  "chradiiphcode",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pName */
};

static emlrtRTEInfo c5_uh_emlrtRTEI = { 999,/* lineNo */
  17,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c5_vh_emlrtRTEI = { 998,/* lineNo */
  13,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c5_wh_emlrtRTEI = { 1001,/* lineNo */
  34,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c5_xh_emlrtRTEI = { 298,/* lineNo */
  1,                                   /* colNo */
  "sortIdx",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pName */
};

static emlrtBCInfo c5_emlrtBCI = { 1,  /* iFirst */
  19200,                               /* iLast */
  1055,                                /* lineNo */
  48,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imhist.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_b_emlrtBCI = { 1,/* iFirst */
  19200,                               /* iLast */
  1056,                                /* lineNo */
  48,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imhist.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_c_emlrtBCI = { 1,/* iFirst */
  19200,                               /* iLast */
  1057,                                /* lineNo */
  48,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imhist.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_d_emlrtBCI = { 1,/* iFirst */
  19200,                               /* iLast */
  1058,                                /* lineNo */
  48,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imhist.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_e_emlrtBCI = { 0,/* iFirst */
  2,                                   /* iLast */
  24,                                  /* lineNo */
  70,                                  /* colNo */
  "radiusRanges",                      /* aName */
  "Image Processing System/Circle Flag",/* fName */
  "#flightControlSystem:2925",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_emlrtDCI = { 24, /* lineNo */
  70,                                  /* colNo */
  "Image Processing System/Circle Flag",/* fName */
  "#flightControlSystem:2925",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_f_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  156,                                 /* lineNo */
  36,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_g_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  156,                                 /* lineNo */
  47,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_h_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  806,                                 /* lineNo */
  31,                                  /* colNo */
  "",                                  /* aName */
  "edge",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\edge.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_i_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  801,                                 /* lineNo */
  70,                                  /* colNo */
  "",                                  /* aName */
  "edge",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\edge.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_j_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  145,                                 /* lineNo */
  28,                                  /* colNo */
  "",                                  /* aName */
  "edge",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\edge.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_k_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  144,                                 /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "edge",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\edge.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_l_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  52,                                  /* lineNo */
  23,                                  /* colNo */
  "",                                  /* aName */
  "imfindcircles",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfindcircles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_m_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  53,                                  /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "imfindcircles",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfindcircles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c5_emlrtECI = { -1, /* nDims */
  64,                                  /* lineNo */
  9,                                   /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c5_yh_emlrtRTEI = { 77,/* lineNo */
  9,                                   /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtBCInfo c5_n_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  59,                                  /* lineNo */
  40,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_o_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  28,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_p_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  18,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_q_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  86,                                  /* lineNo */
  28,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_r_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  86,                                  /* lineNo */
  18,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_s_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  32,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_t_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  20,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_u_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  104,                                 /* lineNo */
  80,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_v_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  104,                                 /* lineNo */
  110,                                 /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_w_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  104,                                 /* lineNo */
  57,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_x_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  104,                                 /* lineNo */
  44,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_y_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  130,                                 /* lineNo */
  29,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ab_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  104,                                 /* lineNo */
  16,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_bb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  104,                                 /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_cb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  130,                                 /* lineNo */
  45,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_db_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  130,                                 /* lineNo */
  50,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_eb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  105,                                 /* lineNo */
  80,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_fb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  105,                                 /* lineNo */
  110,                                 /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_gb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  132,                                 /* lineNo */
  64,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_hb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  132,                                 /* lineNo */
  69,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ib_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  132,                                 /* lineNo */
  24,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_jb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  133,                                 /* lineNo */
  64,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_kb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  133,                                 /* lineNo */
  69,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_lb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  133,                                 /* lineNo */
  24,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_mb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  105,                                 /* lineNo */
  57,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_nb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  134,                                 /* lineNo */
  38,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ob_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  134,                                 /* lineNo */
  43,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_pb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  134,                                 /* lineNo */
  23,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_qb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  105,                                 /* lineNo */
  44,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_rb_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  151,                                 /* lineNo */
  32,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_sb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  151,                                 /* lineNo */
  35,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_tb_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  151,                                 /* lineNo */
  40,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ub_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  151,                                 /* lineNo */
  43,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_vb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  151,                                 /* lineNo */
  53,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_wb_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  151,                                 /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c5_xb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  151,                                 /* lineNo */
  12,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_yb_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  151,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c5_ac_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  151,                                 /* lineNo */
  20,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_bc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  105,                                 /* lineNo */
  16,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_cc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  105,                                 /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_dc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  107,                                 /* lineNo */
  34,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ec_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  107,                                 /* lineNo */
  15,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_fc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  107,                                 /* lineNo */
  20,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_gc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  38,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_hc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  43,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ic_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  61,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_jc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  66,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_kc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  84,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_lc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  89,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_mc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  107,                                 /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_nc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  112,                                 /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_oc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  20,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_pc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_qc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  111,                                 /* lineNo */
  23,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_rc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  111,                                 /* lineNo */
  29,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_sc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  112,                                 /* lineNo */
  30,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_tc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "chcenters",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chcenters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c5_b_emlrtECI = { -1,/* nDims */
  42,                                  /* lineNo */
  9,                                   /* colNo */
  "chcenters",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c5_ai_emlrtRTEI = { 46,/* lineNo */
  15,                                  /* colNo */
  "chcenters",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtBCInfo c5_uc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  47,                                  /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "chcenters",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chcenters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_vc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "chcenters",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chcenters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_wc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  47,                                  /* lineNo */
  51,                                  /* colNo */
  "",                                  /* aName */
  "chcenters",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chcenters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_xc_emlrtBCI = { 1,/* iFirst */
  19200,                               /* iLast */
  53,                                  /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "chcenters",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chcenters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_yc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  56,                                  /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "chcenters",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chcenters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ad_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  488,                                 /* lineNo */
  73,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_bd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  488,                                 /* lineNo */
  59,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_cd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  2124,                                /* lineNo */
  56,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_dd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  2126,                                /* lineNo */
  42,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ed_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  2127,                                /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_fd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  2127,                                /* lineNo */
  55,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_gd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  488,                                 /* lineNo */
  68,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_hd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  488,                                 /* lineNo */
  82,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_id_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  488,                                 /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_jd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  51,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_kd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  37,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo c5_bi_emlrtRTEI = { 102,/* lineNo */
  9,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtBCInfo c5_ld_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  233,                                 /* lineNo */
  15,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_md_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  75,                                  /* lineNo */
  18,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_nd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  234,                                 /* lineNo */
  16,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_od_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  22,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_b_emlrtDCI = { 69,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_pd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  60,                                  /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_qd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  34,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_rd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  238,                                 /* lineNo */
  16,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_sd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  86,                                  /* lineNo */
  34,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_td_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  66,                                  /* lineNo */
  44,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ud_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  66,                                  /* lineNo */
  60,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_vd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  66,                                  /* lineNo */
  22,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_wd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  62,                                  /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_xd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  130,                                 /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_yd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  134,                                 /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ae_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  95,                                  /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_be_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  95,                                  /* lineNo */
  41,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ce_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  95,                                  /* lineNo */
  66,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_de_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  95,                                  /* lineNo */
  80,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ee_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  99,                                  /* lineNo */
  37,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_fe_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  41,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ge_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  63,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_he_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  58,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ie_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  37,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_je_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  73,                                  /* lineNo */
  52,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ke_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  76,                                  /* lineNo */
  46,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_le_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  76,                                  /* lineNo */
  62,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_me_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  76,                                  /* lineNo */
  76,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ne_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  76,                                  /* lineNo */
  23,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_oe_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  181,                                 /* lineNo */
  23,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_pe_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  182,                                 /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_qe_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  182,                                 /* lineNo */
  34,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_re_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  182,                                 /* lineNo */
  12,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_se_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  183,                                 /* lineNo */
  19,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_c_emlrtDCI = { 83,/* lineNo */
  38,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo c5_d_emlrtDCI = { 83,/* lineNo */
  38,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  4                                    /* checkKind */
};

static emlrtBCInfo c5_te_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  170,                                 /* lineNo */
  12,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ue_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  167,                                 /* lineNo */
  12,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ve_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  171,                                 /* lineNo */
  12,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_we_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  168,                                 /* lineNo */
  12,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_xe_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  82,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ye_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  90,                                  /* lineNo */
  52,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_af_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  93,                                  /* lineNo */
  31,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_bf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  93,                                  /* lineNo */
  41,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_cf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  46,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_df_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  60,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ef_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  94,                                  /* lineNo */
  63,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ff_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  94,                                  /* lineNo */
  22,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_gf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  95,                                  /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_hf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  95,                                  /* lineNo */
  36,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_e_emlrtDCI = { 48,/* lineNo */
  33,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  4                                    /* checkKind */
};

static emlrtBCInfo c5_if_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_jf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  14,                                  /* lineNo */
  72,                                  /* colNo */
  "",                                  /* aName */
  "chradiiphcode",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_kf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  14,                                  /* lineNo */
  92,                                  /* colNo */
  "",                                  /* aName */
  "chradiiphcode",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_lf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  72,                                  /* lineNo */
  40,                                  /* colNo */
  "",                                  /* aName */
  "chradiiphcode",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_mf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  73,                                  /* lineNo */
  19,                                  /* colNo */
  "",                                  /* aName */
  "chradiiphcode",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_nf_emlrtBCI = { 1,/* iFirst */
  19200,                               /* iLast */
  14,                                  /* lineNo */
  30,                                  /* colNo */
  "",                                  /* aName */
  "chradiiphcode",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c5_c_emlrtECI = { 1,/* nDims */
  1381,                                /* lineNo */
  21,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtBCInfo c5_of_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1373,                                /* lineNo */
  30,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_pf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1352,                                /* lineNo */
  19,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_qf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1349,                                /* lineNo */
  15,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_rf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1003,                                /* lineNo */
  19,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_sf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1381,                                /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_tf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1001,                                /* lineNo */
  19,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_uf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1385,                                /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_vf_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  1352,                                /* lineNo */
  45,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_wf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1352,                                /* lineNo */
  47,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_xf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1352,                                /* lineNo */
  54,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_yf_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1352,                                /* lineNo */
  34,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ag_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  998,                                 /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_bg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1349,                                /* lineNo */
  57,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_cg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  999,                                 /* lineNo */
  41,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_dg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1371,                                /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_eg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1371,                                /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_fg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1350,                                /* lineNo */
  33,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_gg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1351,                                /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_hg_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  1001,                                /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRSInfo c5_nk_emlrtRSI = { 56,/* lineNo */
  "chcenters",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pathName */
};

static emlrtRSInfo c5_ok_emlrtRSI = { 40,/* lineNo */
  "chcenters",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pathName */
};

static emlrtRSInfo c5_pk_emlrtRSI = { 11,/* lineNo */
  "chcenters",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pathName */
};

static emlrtRSInfo c5_qk_emlrtRSI = { 10,/* lineNo */
  "chcenters",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pathName */
};

static emlrtRSInfo c5_rk_emlrtRSI = { 57,/* lineNo */
  "imfindcircles",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pathName */
};

static emlrtRSInfo c5_sk_emlrtRSI = { 52,/* lineNo */
  "imfindcircles",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pathName */
};

static emlrtRSInfo c5_tk_emlrtRSI = { 9,/* lineNo */
  "imfindcircles",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pathName */
};

static emlrtRSInfo c5_uk_emlrtRSI = { 8,/* lineNo */
  "imfindcircles",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pathName */
};

static emlrtRSInfo c5_vk_emlrtRSI = { 125,/* lineNo */
  "chaccum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c5_wk_emlrtRSI = { 41,/* lineNo */
  "repmat",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pathName */
};

static emlrtRSInfo c5_xk_emlrtRSI = { 97,/* lineNo */
  "chaccum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c5_yk_emlrtRSI = { 35,/* lineNo */
  "sub2ind",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sub2ind.m"/* pathName */
};

static emlrtRSInfo c5_al_emlrtRSI = { 33,/* lineNo */
  "sub2ind",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sub2ind.m"/* pathName */
};

static emlrtRSInfo c5_bl_emlrtRSI = { 124,/* lineNo */
  "chaccum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c5_cl_emlrtRSI = { 123,/* lineNo */
  "chaccum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c5_dl_emlrtRSI = { 1371,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo c5_el_emlrtRSI = { 81,/* lineNo */
  "chaccum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c5_fl_emlrtRSI = { 80,/* lineNo */
  "chaccum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c5_gl_emlrtRSI = { 79,/* lineNo */
  "chaccum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c5_hl_emlrtRSI = { 94,/* lineNo */
  "chaccum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c5_il_emlrtRSI = { 93,/* lineNo */
  "chaccum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c5_jl_emlrtRSI = { 96,/* lineNo */
  "chaccum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo c5_kl_emlrtRSI = { 102,/* lineNo */
  "repmat",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pathName */
};

static char_T c5_cv[39] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'c', 'a', 't',
  'e', 'n', 'a', 't', 'e', ':', 'm', 'a', 't', 'r', 'i', 'x', 'D', 'i', 'm', 'e',
  'n', 's', 'i', 'o', 'n', 'M', 'i', 's', 'm', 'a', 't', 'c', 'h' };

static char_T c5_cv1[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
  'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n', 'E',
  'r', 'r', 'o', 'r' };

static real_T c5_dv[81] = { 0.00076344732860875273, 0.0018314149348447177,
  0.0034215335484046407, 0.0049783019377569017, 0.0056411551396688174,
  0.0049783019377569017, 0.0034215335484046407, 0.0018314149348447177,
  0.00076344732860875273, 0.0018314149348447177, 0.0043933360402013547,
  0.00820783229674747, 0.011942325524393562, 0.013532427693987039,
  0.011942325524393562, 0.00820783229674747, 0.0043933360402013547,
  0.0018314149348447177, 0.0034215335484046407, 0.00820783229674747,
  0.015334249507680094, 0.022311201383287918, 0.025281903333535138,
  0.022311201383287918, 0.015334249507680094, 0.00820783229674747,
  0.0034215335484046407, 0.0049783019377569017, 0.011942325524393562,
  0.022311201383287918, 0.03246260646250166, 0.036784952295500911,
  0.03246260646250166, 0.022311201383287918, 0.011942325524393562,
  0.0049783019377569017, 0.0056411551396688174, 0.013532427693987039,
  0.025281903333535138, 0.036784952295500911, 0.041682811789783857,
  0.036784952295500911, 0.025281903333535138, 0.013532427693987039,
  0.0056411551396688174, 0.0049783019377569017, 0.011942325524393562,
  0.022311201383287918, 0.03246260646250166, 0.036784952295500911,
  0.03246260646250166, 0.022311201383287918, 0.011942325524393562,
  0.0049783019377569017, 0.0034215335484046407, 0.00820783229674747,
  0.015334249507680094, 0.022311201383287918, 0.025281903333535138,
  0.022311201383287918, 0.015334249507680094, 0.00820783229674747,
  0.0034215335484046407, 0.0018314149348447177, 0.0043933360402013547,
  0.00820783229674747, 0.011942325524393562, 0.013532427693987039,
  0.011942325524393562, 0.00820783229674747, 0.0043933360402013547,
  0.0018314149348447177, 0.00076344732860875273, 0.0018314149348447177,
  0.0034215335484046407, 0.0049783019377569017, 0.0056411551396688174,
  0.0049783019377569017, 0.0034215335484046407, 0.0018314149348447177,
  0.00076344732860875273 };

static char_T c5_cv2[46] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
  'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't', 't', 'r',
  'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'F', 'i',
  'n', 'i', 't', 'e' };

static int32_T c5_iv[320] = { 1, 1, 1, 1, 1, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
  11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
  31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
  51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70,
  71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90,
  91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107,
  108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 120, 120, 120,
  120, 120, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17,
  18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37,
  38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57,
  58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77,
  78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97,
  98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113,
  114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129,
  130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145,
  146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160 };

static real_T c5_dv1[13] = { 0.0020299751839417137, 0.0102182810143517,
  0.058116735860084034, 0.19634433732941292, 0.37823877042972087,
  0.35505190018248872, 0.0, -0.35505190018248872, -0.37823877042972087,
  -0.19634433732941292, -0.058116735860084034, -0.0102182810143517,
  -0.0020299751839417137 };

static real_T c5_dv2[12] = { 0.0020299751839417137, 0.0102182810143517,
  0.058116735860084034, 0.19634433732941292, 0.37823877042972087,
  0.35505190018248872, -0.35505190018248872, -0.37823877042972087,
  -0.19634433732941292, -0.058116735860084034, -0.0102182810143517,
  -0.0020299751839417137 };

static boolean_T c5_bv[13] = { true, true, true, true, true, true, false, true,
  true, true, true, true, true };

static creal_T c5_dc = { 0.0,          /* re */
  0.0                                  /* im */
};

static char_T c5_cv3[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'b', 'u', 'i', 'l',
  't', 'i', 'n', 's', ':', 'A', 's', 's', 'e', 'r', 't', 'i', 'o', 'n', 'F', 'a',
  'i', 'l', 'e', 'd' };

static char_T c5_cv4[29] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm', 'b',
  'e', 'r', ' ', '2', ',', ' ', 'R', 'A', 'D', 'I', 'U', 'S', '_', 'R', 'A', 'N',
  'G', 'E', ',' };

static char_T c5_cv5[46] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
  'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't', 't', 'r',
  'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'N', 'o',
  'n', 'N', 'a', 'N' };

static char_T c5_cv6[47] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
  'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't', 't', 'r',
  'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'I', 'n',
  't', 'e', 'g', 'e', 'r' };

static int32_T c5_iv1[324] = { 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
  15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34,
  35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54,
  55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74,
  75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94,
  95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111,
  112, 113, 114, 115, 116, 117, 118, 119, 120, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18,
  19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38,
  39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58,
  59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78,
  79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98,
  99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114,
  115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130,
  131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146,
  147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 160 };

static char_T c5_cv7[15] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'm', 'a',
  'x', 's', 'i', 'z', 'e' };

static char_T c5_cv8[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
  'A', 'B', ':', 'p', 'm', 'a', 'x', 's', 'i', 'z', 'e' };

static char_T c5_cv9[28] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
  'A', 'B', ':', 'N', 'o', 'n', 'I', 'n', 't', 'e', 'g', 'e', 'r', 'I', 'n', 'p',
  'u', 't' };

static char_T c5_cv10[39] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'i', 'm', 'f',
  'i', 'n', 'd', 'c', 'i', 'r', 'c', 'l', 'e', 's', ':', 'i', 'n', 'v', 'a', 'l',
  'i', 'd', 'R', 'a', 'd', 'i', 'u', 's', 'R', 'a', 'n', 'g', 'e' };

/* Function Declarations */
static void initialize_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance);
static void initialize_params_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance);
static void mdl_start_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance);
static void mdl_terminate_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance);
static void mdl_setup_runtime_resources_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance);
static void mdl_cleanup_runtime_resources_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance);
static void enable_c5_flightControlSystem(SFc5_flightControlSystemInstanceStruct
  *chartInstance);
static void disable_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance);
static void sf_gateway_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance);
static void ext_mode_exec_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance);
static void c5_update_jit_animation_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance);
static void c5_do_animation_call_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance);
static void set_sim_state_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance, const mxArray *c5_st);
static void c5_imgaussfilt(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, real_T c5_b_A[19200], real_T c5_B[19200]);
static void c5_svd(SFc5_flightControlSystemInstanceStruct *chartInstance, const
                   emlrtStack *c5_sp, real_T c5_U[81], real_T c5_S[81], real_T
                   c5_V[81]);
static void c5_check_forloop_overflow_error
  (SFc5_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c5_sp);
static real_T c5_otsuthresh(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, real_T c5_counts[256]);
static void c5_edge(SFc5_flightControlSystemInstanceStruct *chartInstance, const
                    emlrtStack *c5_sp, boolean_T c5_varargin_1[19200], boolean_T
                    c5_varargout_1[19200]);
static void c5_imfilter(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, real32_T c5_varargin_1[19200], real32_T c5_b[19200]);
static void c5_warning(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp);
static void c5_imfindcircles(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, boolean_T c5_varargin_1[19200],
  real_T c5_b_varargin_2[2], c5_coder_array_real_T_2D *c5_centers,
  c5_coder_array_real_T_2D *c5_r_estimated);
static void c5_b_warning(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, const mxArray *c5_varargin_6);
static void c5_chaccum(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, boolean_T c5_varargin_1[19200], real_T
  c5_varargin_2_data[], creal_T c5_c_accumMatrix[19200], real32_T
  c5_b_gradientImg[19200]);
static void c5_parseInputs(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, boolean_T c5_varargin_1[19200], real_T
  c5_varargin_2_data[], boolean_T c5_b_A[19200], real_T c5_radiusRange_data[],
  int32_T c5_radiusRange_size[2]);
static boolean_T c5_all(SFc5_flightControlSystemInstanceStruct *chartInstance,
  real_T c5_a_data[]);
static void c5_b_imfilter(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, real32_T c5_varargin_1[19200], real32_T c5_b[19200]);
static void c5_c_imfilter(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, real32_T c5_varargin_1[19200], real32_T c5_b[19200]);
static void c5_d_imfilter(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, real32_T c5_varargin_1[19200], real32_T c5_b[19200]);
static real_T c5_graythresh(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, real32_T c5_I[19200]);
static void c5_eml_find(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, boolean_T c5_b_x[19200], c5_coder_array_int32_T *c5_i,
  c5_coder_array_int32_T *c5_j);
static void c5_indexShapeCheck(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, int32_T c5_matrixSize, int32_T
  c5_indexSize[2]);
static void c5_sub2ind(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, c5_coder_array_real_T *c5_varargin_1,
  c5_coder_array_real_T *c5_b_varargin_2, c5_coder_array_int32_T *c5_idx);
static boolean_T c5_allinrange(SFc5_flightControlSystemInstanceStruct
  *chartInstance, c5_coder_array_real_T *c5_b_x, int32_T c5_hi);
static void c5_eml_float_colon(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, real_T c5_c_a, real_T c5_b, real_T
  c5_y_data[], int32_T c5_y_size[2]);
static void c5_log(SFc5_flightControlSystemInstanceStruct *chartInstance, const
                   emlrtStack *c5_sp, real_T c5_x_data[], int32_T c5_x_size[2],
                   real_T c5_b_x_data[], int32_T c5_b_x_size[2]);
static void c5_exp(SFc5_flightControlSystemInstanceStruct *chartInstance, const
                   emlrtStack *c5_sp, creal_T c5_x_data[], int32_T c5_x_size[2],
                   creal_T c5_b_x_data[], int32_T c5_b_x_size[2]);
static void c5_chcenters(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, creal_T c5_varargin_1[19200],
  c5_coder_array_real_T_2D *c5_centers, c5_coder_array_real_T_2D *c5_metric);
static void c5_validateattributes(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, real_T c5_c_a[19200]);
static void c5_regionprops(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, boolean_T c5_varargin_1[19200], real_T
  c5_b_varargin_2[19200], c5_coder_array_sOA5t73y81YtFHGIDxk *c5_outstats);
static void c5_bwconncomp(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, boolean_T c5_varargin_1[19200],
  c5_s_jsRMsmv0Wf6iHXg8PgCG1G *c5_CC);
static real_T c5_sumColumnB(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_int32_T *c5_b_x,
  int32_T c5_vlen);
static real_T c5_sumColumnB4(SFc5_flightControlSystemInstanceStruct
  *chartInstance, c5_coder_array_int32_T *c5_b_x, int32_T c5_vstart);
static real_T c5_b_sumColumnB(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_int32_T *c5_b_x,
  int32_T c5_vlen, int32_T c5_vstart);
static void c5_useConstantDim(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_int32_T
  *c5_b_varargin_2, int32_T c5_varargin_3, c5_coder_array_int32_T
  *c5_varargout_1);
static void c5_repmat(SFc5_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c5_sp, c5_cell_wrap_51 c5_c_a[1], real_T
                      c5_b_varargin_2, c5_coder_array_cell_wrap_51_2D *c5_b);
static void c5_assertValidSizeArg(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, real_T c5_varargin_1);
static void c5_ComputeWeightedCentroid(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, real_T c5_I[19200],
  c5_coder_array_s_R6Og1x0kmqQXSF9Pw *c5_stats, c5_sHtk0WM4OMtyqkehwQYcq2
  c5_statsAlreadyComputed, c5_coder_array_s_R6Og1x0kmqQXSF9Pw *c5_b_stats,
  c5_sHtk0WM4OMtyqkehwQYcq2 *c5_b_statsAlreadyComputed);
static real_T c5_sum(SFc5_flightControlSystemInstanceStruct *chartInstance,
                     const emlrtStack *c5_sp, c5_coder_array_real_T *c5_b_x);
static real_T c5_c_sumColumnB(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_real_T *c5_b_x,
  int32_T c5_vlen);
static real_T c5_b_sumColumnB4(SFc5_flightControlSystemInstanceStruct
  *chartInstance, c5_coder_array_real_T *c5_b_x, int32_T c5_vstart);
static real_T c5_d_sumColumnB(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_real_T *c5_b_x,
  int32_T c5_vlen, int32_T c5_vstart);
static void c5_round(SFc5_flightControlSystemInstanceStruct *chartInstance,
                     const emlrtStack *c5_sp, c5_coder_array_real_T *c5_b_x,
                     c5_coder_array_real_T *c5_y);
static void c5_sort(SFc5_flightControlSystemInstanceStruct *chartInstance, const
                    emlrtStack *c5_sp, c5_coder_array_real_T_2D *c5_b_x,
                    c5_coder_array_real_T_2D *c5_c_x, c5_coder_array_int32_T_2D *
                    c5_idx);
static void c5_merge_pow2_block(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_int32_T_2D *c5_idx,
  c5_coder_array_real_T_2D *c5_b_x, int32_T c5_offset, c5_coder_array_int32_T_2D
  *c5_b_idx, c5_coder_array_real_T_2D *c5_c_x);
static void c5_merge_block(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, c5_coder_array_int32_T_2D *c5_idx,
  c5_coder_array_real_T_2D *c5_b_x, int32_T c5_offset, int32_T c5_n, int32_T
  c5_preSortLevel, c5_coder_array_int32_T *c5_iwork, c5_coder_array_real_T
  *c5_xwork, c5_coder_array_int32_T_2D *c5_b_idx, c5_coder_array_real_T_2D
  *c5_c_x, c5_coder_array_int32_T *c5_b_iwork, c5_coder_array_real_T *c5_b_xwork);
static void c5_merge(SFc5_flightControlSystemInstanceStruct *chartInstance,
                     const emlrtStack *c5_sp, c5_coder_array_int32_T_2D *c5_idx,
                     c5_coder_array_real_T_2D *c5_b_x, int32_T c5_offset,
                     int32_T c5_np, int32_T c5_nq, c5_coder_array_int32_T
                     *c5_iwork, c5_coder_array_real_T *c5_xwork,
                     c5_coder_array_int32_T_2D *c5_b_idx,
                     c5_coder_array_real_T_2D *c5_c_x, c5_coder_array_int32_T
                     *c5_b_iwork, c5_coder_array_real_T *c5_b_xwork);
static void c5_chradiiphcode(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_real_T_2D
  *c5_varargin_1, creal_T c5_b_varargin_2[19200], real_T c5_varargin_3_data[],
  c5_coder_array_real_T *c5_r_estimated);
static boolean_T c5_b_all(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, c5_coder_array_boolean_T *c5_b_x);
static real_T c5_emlrt_marshallIn(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c5_a__output_of_feval_, const char_T
  *c5_identifier);
static real_T c5_b_emlrt_marshallIn(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c5_e_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_slStringInitializeDynamicBuffers
  (SFc5_flightControlSystemInstanceStruct *chartInstance);
static void c5_chart_data_browse_helper(SFc5_flightControlSystemInstanceStruct
  *chartInstance, int32_T c5_ssIdNumber, const mxArray **c5_mxData, uint8_T
  *c5_isValueTooBig);
static const mxArray *c5_feval(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, const mxArray *c5_input0, const
  mxArray *c5_input1);
static void c5_b_feval(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, const mxArray *c5_input0, const mxArray *c5_input1);
static const mxArray *c5_sprintf(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, const mxArray *c5_input0);
static const mxArray *c5_c_feval(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, const mxArray *c5_input0, const
  mxArray *c5_input1, const mxArray *c5_input2, const mxArray *c5_input3, const
  mxArray *c5_input4, const mxArray *c5_input5, const mxArray *c5_input6, const
  mxArray *c5_input7);
static void c5_d_feval(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, const mxArray *c5_input0, const mxArray *c5_input1);
static const mxArray *c5_e_feval(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, const mxArray *c5_input0, const
  mxArray *c5_input1, const mxArray *c5_input2);
static void c5_b_parseInputs(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, real_T c5_varargin_2_data[], real_T
  c5_radiusRange_data[], int32_T c5_radiusRange_size[2]);
static void c5_b_log(SFc5_flightControlSystemInstanceStruct *chartInstance,
                     const emlrtStack *c5_sp, real_T c5_x_data[], int32_T
                     c5_x_size[2]);
static void c5_b_exp(SFc5_flightControlSystemInstanceStruct *chartInstance,
                     const emlrtStack *c5_sp, creal_T c5_x_data[], int32_T
                     c5_x_size[2]);
static void c5_b_ComputeWeightedCentroid(SFc5_flightControlSystemInstanceStruct *
  chartInstance, const emlrtStack *c5_sp, real_T c5_I[19200],
  c5_coder_array_s_R6Og1x0kmqQXSF9Pw *c5_stats, c5_sHtk0WM4OMtyqkehwQYcq2
  *c5_statsAlreadyComputed);
static void c5_b_sort(SFc5_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c5_sp, c5_coder_array_real_T_2D *c5_b_x,
                      c5_coder_array_int32_T_2D *c5_idx);
static void c5_b_merge_pow2_block(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_int32_T_2D *c5_idx,
  c5_coder_array_real_T_2D *c5_b_x, int32_T c5_offset);
static void c5_b_merge_block(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_int32_T_2D *c5_idx,
  c5_coder_array_real_T_2D *c5_b_x, int32_T c5_offset, int32_T c5_n, int32_T
  c5_preSortLevel, c5_coder_array_int32_T *c5_iwork, c5_coder_array_real_T
  *c5_xwork);
static void c5_b_merge(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, c5_coder_array_int32_T_2D *c5_idx,
  c5_coder_array_real_T_2D *c5_b_x, int32_T c5_offset, int32_T c5_np, int32_T
  c5_nq, c5_coder_array_int32_T *c5_iwork, c5_coder_array_real_T *c5_xwork);
static void c5_binary_expand_op(SFc5_flightControlSystemInstanceStruct
  *chartInstance, creal_T c5_in1_data[], int32_T c5_in1_size[2], real_T
  c5_in2_data[], int32_T c5_in2_size[2]);
static real_T c5_binary_expand_op_1(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, emlrtRSInfo c5_in1,
  c5_coder_array_real_T *c5_in2, c5_coder_array_real_T *c5_in3);
static void c5_array_real_T_2D_SetSize(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_real_T_2D
  *c5_coderArray, const emlrtRTEInfo *c5_srcLocation, int32_T c5_size0, int32_T
  c5_size1);
static void c5_array_creal_T_SetSize(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_creal_T *c5_coderArray,
  const emlrtRTEInfo *c5_srcLocation, int32_T c5_size0);
static void c5_array_boolean_T_2D_SetSize(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_boolean_T_2D
  *c5_coderArray, const emlrtRTEInfo *c5_srcLocation, int32_T c5_size0, int32_T
  c5_size1);
static void c5_array_int32_T_SetSize(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_int32_T *c5_coderArray,
  const emlrtRTEInfo *c5_srcLocation, int32_T c5_size0);
static void c5_array_real_T_SetSize(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_real_T *c5_coderArray,
  const emlrtRTEInfo *c5_srcLocation, int32_T c5_size0);
static void c5_array_real32_T_2D_SetSize(SFc5_flightControlSystemInstanceStruct *
  chartInstance, const emlrtStack *c5_sp, c5_coder_array_real32_T_2D
  *c5_coderArray, const emlrtRTEInfo *c5_srcLocation, int32_T c5_size0, int32_T
  c5_size1);
static void c5_array_creal_T_2D_SetSize(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_creal_T_2D
  *c5_coderArray, const emlrtRTEInfo *c5_srcLocation, int32_T c5_size0, int32_T
  c5_size1);
static void c5_array_boolean_T_SetSize(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_boolean_T
  *c5_coderArray, const emlrtRTEInfo *c5_srcLocation, int32_T c5_size0);
static void c5_array_sOA5t73y81YtFHGIDxk0fKF_S
  (SFc5_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c5_sp, c5_coder_array_sOA5t73y81YtFHGIDxk *c5_coderArray, const emlrtRTEInfo
   *c5_srcLocation, int32_T c5_size0);
static void c5_array_s_R6Og1x0kmqQXSF9Pwa49FD_
  (SFc5_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c5_sp, c5_coder_array_s_R6Og1x0kmqQXSF9Pw *c5_coderArray, const emlrtRTEInfo
   *c5_srcLocation, int32_T c5_size0);
static void c5_array_real_T_Destructor(SFc5_flightControlSystemInstanceStruct
  *chartInstance, c5_coder_array_real_T *c5_coderArray);
static void c5_b_array_s_R6Og1x0kmqQXSF9Pwa49FD_
  (SFc5_flightControlSystemInstanceStruct *chartInstance,
   c5_s_R6Og1x0kmqQXSF9Pwa49FD *c5_pStruct);
static void c5_array_real_T_2D_Destructor(SFc5_flightControlSystemInstanceStruct
  *chartInstance, c5_coder_array_real_T_2D *c5_coderArray);
static void c5_c_array_s_R6Og1x0kmqQXSF9Pwa49FD_
  (SFc5_flightControlSystemInstanceStruct *chartInstance,
   c5_s_R6Og1x0kmqQXSF9Pwa49FD *c5_pStruct);
static void c5_array_boolean_T_0x0_Constructor
  (SFc5_flightControlSystemInstanceStruct *chartInstance,
   c5_coder_array_boolean_T_0x0 *c5_pArray);
static void c5_array_real_T_Constructor(SFc5_flightControlSystemInstanceStruct
  *chartInstance, c5_coder_array_real_T *c5_coderArray);
static void c5_array_real_T_2D_Constructor
  (SFc5_flightControlSystemInstanceStruct *chartInstance,
   c5_coder_array_real_T_2D *c5_coderArray);
static void c5_array_real_T_1x0_Constructor
  (SFc5_flightControlSystemInstanceStruct *chartInstance,
   c5_coder_array_real_T_1x0 *c5_pArray);
static void c5_array_cell_wrap_51_2D_SetSize
  (SFc5_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c5_sp, c5_coder_array_cell_wrap_51_2D *c5_coderArray, const emlrtRTEInfo
   *c5_srcLocation, int32_T c5_size0, int32_T c5_size1);
static void c5_array_cell_wrap_51_Destructor
  (SFc5_flightControlSystemInstanceStruct *chartInstance, c5_cell_wrap_51
   *c5_pStruct);
static void c5_array_cell_wrap_51_Constructor
  (SFc5_flightControlSystemInstanceStruct *chartInstance, c5_cell_wrap_51
   *c5_pStruct);
static void c5_array_int32_T_2D_SetSize(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_int32_T_2D
  *c5_coderArray, const emlrtRTEInfo *c5_srcLocation, int32_T c5_size0, int32_T
  c5_size1);
static void c5_array_cell_wrap_60_2s_Construct
  (SFc5_flightControlSystemInstanceStruct *chartInstance, c5_cell_wrap_60
   c5_pMatrix[2]);
static void c5_array_cell_wrap_60_Constructor
  (SFc5_flightControlSystemInstanceStruct *chartInstance, c5_cell_wrap_60
   *c5_pStruct);
static void c5_array_cell_wrap_60_2s_Destructo
  (SFc5_flightControlSystemInstanceStruct *chartInstance, c5_cell_wrap_60
   c5_pMatrix[2]);
static void c5_array_cell_wrap_60_Destructor
  (SFc5_flightControlSystemInstanceStruct *chartInstance, c5_cell_wrap_60
   *c5_pStruct);
static void c5_array_boolean_T_2D_Constructor
  (SFc5_flightControlSystemInstanceStruct *chartInstance,
   c5_coder_array_boolean_T_2D *c5_coderArray);
static void c5_array_int32_T_Constructor(SFc5_flightControlSystemInstanceStruct *
  chartInstance, c5_coder_array_int32_T *c5_coderArray);
static void c5_array_creal_T_Constructor(SFc5_flightControlSystemInstanceStruct *
  chartInstance, c5_coder_array_creal_T *c5_coderArray);
static void c5_array_boolean_T_2D_Destructor
  (SFc5_flightControlSystemInstanceStruct *chartInstance,
   c5_coder_array_boolean_T_2D *c5_coderArray);
static void c5_array_int32_T_Destructor(SFc5_flightControlSystemInstanceStruct
  *chartInstance, c5_coder_array_int32_T *c5_coderArray);
static void c5_array_creal_T_Destructor(SFc5_flightControlSystemInstanceStruct
  *chartInstance, c5_coder_array_creal_T *c5_coderArray);
static void c5_array_real32_T_2D_Constructor
  (SFc5_flightControlSystemInstanceStruct *chartInstance,
   c5_coder_array_real32_T_2D *c5_coderArray);
static void c5_array_creal_T_2D_Constructor
  (SFc5_flightControlSystemInstanceStruct *chartInstance,
   c5_coder_array_creal_T_2D *c5_coderArray);
static void c5_array_real32_T_2D_Destructor
  (SFc5_flightControlSystemInstanceStruct *chartInstance,
   c5_coder_array_real32_T_2D *c5_coderArray);
static void c5_array_creal_T_2D_Destructor
  (SFc5_flightControlSystemInstanceStruct *chartInstance,
   c5_coder_array_creal_T_2D *c5_coderArray);
static void c5_array_sOA5t73y81YtFHGIDxk0fKF_C
  (SFc5_flightControlSystemInstanceStruct *chartInstance,
   c5_coder_array_sOA5t73y81YtFHGIDxk *c5_coderArray);
static void c5_array_int32_T_2D_Constructor
  (SFc5_flightControlSystemInstanceStruct *chartInstance,
   c5_coder_array_int32_T_2D *c5_coderArray);
static void c5_array_sOA5t73y81YtFHGIDxk0fKF_D
  (SFc5_flightControlSystemInstanceStruct *chartInstance,
   c5_coder_array_sOA5t73y81YtFHGIDxk *c5_coderArray);
static void c5_array_int32_T_2D_Destructor
  (SFc5_flightControlSystemInstanceStruct *chartInstance,
   c5_coder_array_int32_T_2D *c5_coderArray);
static void c5_d_array_s_R6Og1x0kmqQXSF9Pwa49FD_
  (SFc5_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c5_sp, c5_s_R6Og1x0kmqQXSF9Pwa49FD *c5_dst, const
   c5_s_R6Og1x0kmqQXSF9Pwa49FD *c5_src, const emlrtRTEInfo *c5_srcLocation);
static void c5_array_real_T_1x2s_Copy(SFc5_flightControlSystemInstanceStruct
  *chartInstance, real_T c5_dst[2], const real_T c5_src[2]);
static void c5_array_real_T_1x4s_Copy(SFc5_flightControlSystemInstanceStruct
  *chartInstance, real_T c5_dst[4], const real_T c5_src[4]);
static void c5_array_boolean_T_0x0_Copy(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_boolean_T_0x0 *c5_dst,
  const c5_coder_array_boolean_T_0x0 *c5_src, const emlrtRTEInfo *c5_srcLocation);
static void c5_array_boolean_T_0x0_SetSize
  (SFc5_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c5_sp, int32_T c5_size[2], const emlrtRTEInfo *c5_srcLocation, int32_T
   c5_size0, int32_T c5_size1);
static void c5_array_real_T_8x2s_Copy(SFc5_flightControlSystemInstanceStruct
  *chartInstance, real_T c5_dst[16], const real_T c5_src[16]);
static void c5_array_real_T_Copy(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_real_T *c5_dst, const
  c5_coder_array_real_T *c5_src, const emlrtRTEInfo *c5_srcLocation);
static void c5_array_real_T_2D_Copy(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_real_T_2D *c5_dst,
  const c5_coder_array_real_T_2D *c5_src, const emlrtRTEInfo *c5_srcLocation);
static void c5_array_real_T_1x0_Copy(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_real_T_1x0 *c5_dst,
  const c5_coder_array_real_T_1x0 *c5_src, const emlrtRTEInfo *c5_srcLocation);
static void c5_array_real_T_1x0_SetSize(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, int32_T c5_size[2], const
  emlrtRTEInfo *c5_srcLocation, int32_T c5_size0, int32_T c5_size1);
static void c5_array_s_jsRMsmv0Wf6iHXg8PgCG1G_
  (SFc5_flightControlSystemInstanceStruct *chartInstance,
   c5_s_jsRMsmv0Wf6iHXg8PgCG1G *c5_pStruct);
static void c5_array_cell_wrap_51_2D_Construct
  (SFc5_flightControlSystemInstanceStruct *chartInstance,
   c5_coder_array_cell_wrap_51_2D *c5_coderArray);
static void c5_e_array_s_R6Og1x0kmqQXSF9Pwa49FD_
  (SFc5_flightControlSystemInstanceStruct *chartInstance,
   c5_coder_array_s_R6Og1x0kmqQXSF9Pw *c5_coderArray);
static void c5_array_boolean_T_Constructor
  (SFc5_flightControlSystemInstanceStruct *chartInstance,
   c5_coder_array_boolean_T *c5_coderArray);
static void c5_b_array_s_jsRMsmv0Wf6iHXg8PgCG1G_
  (SFc5_flightControlSystemInstanceStruct *chartInstance,
   c5_s_jsRMsmv0Wf6iHXg8PgCG1G *c5_pStruct);
static void c5_array_cell_wrap_51_2D_Destructo
  (SFc5_flightControlSystemInstanceStruct *chartInstance,
   c5_coder_array_cell_wrap_51_2D *c5_coderArray);
static void c5_f_array_s_R6Og1x0kmqQXSF9Pwa49FD_
  (SFc5_flightControlSystemInstanceStruct *chartInstance,
   c5_coder_array_s_R6Og1x0kmqQXSF9Pw *c5_coderArray);
static void c5_array_boolean_T_Destructor(SFc5_flightControlSystemInstanceStruct
  *chartInstance, c5_coder_array_boolean_T *c5_coderArray);
static void c5_array_cell_wrap_51_Copy(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_cell_wrap_51 *c5_dst, const
  c5_cell_wrap_51 *c5_src, const emlrtRTEInfo *c5_srcLocation);
static void c5_array_cell_wrap_51_1s_Construct
  (SFc5_flightControlSystemInstanceStruct *chartInstance, c5_cell_wrap_51
   c5_pMatrix[1]);
static void c5_array_cell_wrap_51_1s_Destructo
  (SFc5_flightControlSystemInstanceStruct *chartInstance, c5_cell_wrap_51
   c5_pMatrix[1]);
static void c5_array_cell_wrap_51_2s_Construct
  (SFc5_flightControlSystemInstanceStruct *chartInstance, c5_cell_wrap_51
   c5_pMatrix[2]);
static void c5_array_cell_wrap_51_2s_Destructo
  (SFc5_flightControlSystemInstanceStruct *chartInstance, c5_cell_wrap_51
   c5_pMatrix[2]);
static int32_T c5_div_nzp_s32(SFc5_flightControlSystemInstanceStruct
  *chartInstance, int32_T c5_numerator, int32_T c5_denominator, int32_T
  c5_EMLOvCount_src_loc, uint32_T c5_ssid_src_loc, int32_T c5_offset_src_loc,
  int32_T c5_length_src_loc);
static void init_dsm_address_info(SFc5_flightControlSystemInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc5_flightControlSystemInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance)
{
  emlrtStack c5_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  c5_st.tls = chartInstance->c5_fEmlrtCtx;
  emlrtLicenseCheckR2022a(&c5_st, "EMLRT:runTime:MexFunctionNeedsLicense",
    "image_toolbox", 2);
  sim_mode_is_external(chartInstance->S);
  chartInstance->c5_doneDoubleBufferReInit = false;
  chartInstance->c5_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void initialize_params_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_start_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
}

static void mdl_terminate_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_setup_runtime_resources_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance)
{
  static const int32_T c5_postfixPredicateTree[2] = { 0, -1 };

  static const int32_T c5_condTxtEndIdx[1] = { 931 };

  static const int32_T c5_condTxtStartIdx[1] = { 915 };

  static const uint32_T c5_decisionTxtEndIdx = 0U;
  static const uint32_T c5_decisionTxtStartIdx = 0U;
  setDataBrowseFcn(chartInstance->S, (void *)&c5_chart_data_browse_helper);
  chartInstance->c5_RuntimeVar = sfListenerCacheSimStruct(chartInstance->S);
  sfListenerInitializeRuntimeVars(chartInstance->c5_RuntimeVar,
    &chartInstance->c5_IsDebuggerActive,
    &chartInstance->c5_IsSequenceViewerPresent, 0, 0,
    &chartInstance->c5_mlFcnLineNumber, &chartInstance->c5_IsHeatMapPresent, 0);
  sfSetAnimationVectors(chartInstance->S, &chartInstance->c5_JITStateAnimation[0],
                        &chartInstance->c5_JITTransitionAnimation[0]);
  covrtCreateStateflowInstanceData(chartInstance->c5_covrtInstance, 1U, 0U, 1U,
    39U);
  covrtChartInitFcn(chartInstance->c5_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c5_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c5_decisionTxtStartIdx, &c5_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c5_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c5_covrtInstance, "", 4U, 0U, 1U, 0U, 2U, 0U,
                  0U, 0U, 1U, 0U, 1U, 1U);
  covrtEmlFcnInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 0U,
                     "c5_flightControlSystem", 0, -1, 1071);
  covrtEmlIfInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 0U, 87, 105, -1,
                    138, false);
  covrtEmlIfInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 1U, 911, 931, 1013,
                    1067, false);
  covrtEmlForInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 0U, 599, 629, 865);
  covrtEmlMCDCInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 0U, 914, 931, 1U,
                      0U, &c5_condTxtStartIdx[0], &c5_condTxtEndIdx[0], 2U,
                      &c5_postfixPredicateTree[0], false);
  covrtEmlRelationalInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 0U, 90, 105,
    -1, 0U);
}

static void mdl_cleanup_runtime_resources_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c5_RuntimeVar);
  covrtDeleteStateflowInstanceData(chartInstance->c5_covrtInstance);
}

static void enable_c5_flightControlSystem(SFc5_flightControlSystemInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void sf_gateway_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance)
{
  static char_T c5_b_cv1[18] = { 'c', 'i', 'r', 'c', 'l', 'e', ' ', 'd', 'e',
    't', 'e', 'c', 't', 'e', 'd', '.', '\\', 'n' };

  static char_T c5_b_cv[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  c5_cell_wrap_0 c5_radiusRanges[3];
  c5_cell_wrap_0 c5_r;
  c5_cell_wrap_0 c5_r1;
  c5_cell_wrap_0 c5_r2;
  c5_cell_wrap_60 c5_reshapes[2];
  c5_coder_array_real_T_2D c5_b_varargin_2;
  c5_coder_array_real_T_2D c5_centers;
  c5_coder_array_real_T_2D c5_centersTemp;
  c5_coder_array_real_T_2D c5_radii;
  c5_coder_array_real_T_2D c5_radiiTemp;
  c5_coder_array_real_T_2D c5_result;
  emlrtStack c5_b_st;
  emlrtStack c5_c_st;
  emlrtStack c5_d_st;
  emlrtStack c5_e_st;
  emlrtStack c5_f_st;
  emlrtStack c5_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  const mxArray *c5_b_y = NULL;
  const mxArray *c5_c_y = NULL;
  const mxArray *c5_d_y = NULL;
  const mxArray *c5_e_y = NULL;
  const mxArray *c5_f_y = NULL;
  const mxArray *c5_g_y = NULL;
  const mxArray *c5_h_y = NULL;
  const mxArray *c5_i_y = NULL;
  const mxArray *c5_j_y = NULL;
  const mxArray *c5_k_y = NULL;
  const mxArray *c5_l_y = NULL;
  real_T c5_localBins1[256];
  real_T c5_localBins2[256];
  real_T c5_localBins3[256];
  real_T c5_y[256];
  real_T c5_b_radiusRanges[2];
  real_T c5_T;
  real_T c5_b_number;
  real_T c5_b_out;
  real_T c5_d_i;
  real_T c5_e_u;
  real_T c5_f_i;
  real_T c5_t;
  int32_T c5_input_sizes[2];
  int32_T c5_sizes[2];
  int32_T c5_arg;
  int32_T c5_b_arg;
  int32_T c5_b_c;
  int32_T c5_b_expected;
  int32_T c5_b_i;
  int32_T c5_b_loop_ub;
  int32_T c5_b_varargin_1;
  int32_T c5_c;
  int32_T c5_c_a;
  int32_T c5_c_c;
  int32_T c5_c_i;
  int32_T c5_c_loop_ub;
  int32_T c5_c_result;
  int32_T c5_d_a;
  int32_T c5_d_c;
  int32_T c5_d_loop_ub;
  int32_T c5_e_a;
  int32_T c5_e_c;
  int32_T c5_e_i;
  int32_T c5_e_loop_ub;
  int32_T c5_expected;
  int32_T c5_f_a;
  int32_T c5_f_c;
  int32_T c5_f_loop_ub;
  int32_T c5_g_a;
  int32_T c5_g_c;
  int32_T c5_g_loop_ub;
  int32_T c5_h_a;
  int32_T c5_h_c;
  int32_T c5_h_loop_ub;
  int32_T c5_h_result;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i10;
  int32_T c5_i11;
  int32_T c5_i12;
  int32_T c5_i13;
  int32_T c5_i14;
  int32_T c5_i15;
  int32_T c5_i16;
  int32_T c5_i17;
  int32_T c5_i18;
  int32_T c5_i19;
  int32_T c5_i2;
  int32_T c5_i20;
  int32_T c5_i21;
  int32_T c5_i22;
  int32_T c5_i23;
  int32_T c5_i24;
  int32_T c5_i25;
  int32_T c5_i26;
  int32_T c5_i27;
  int32_T c5_i28;
  int32_T c5_i29;
  int32_T c5_i3;
  int32_T c5_i30;
  int32_T c5_i31;
  int32_T c5_i32;
  int32_T c5_i33;
  int32_T c5_i34;
  int32_T c5_i35;
  int32_T c5_i36;
  int32_T c5_i37;
  int32_T c5_i4;
  int32_T c5_i5;
  int32_T c5_i6;
  int32_T c5_i7;
  int32_T c5_i8;
  int32_T c5_i9;
  int32_T c5_i_a;
  int32_T c5_i_c;
  int32_T c5_i_loop_ub;
  int32_T c5_idx;
  int32_T c5_idx1;
  int32_T c5_idx2;
  int32_T c5_idx3;
  int32_T c5_idx4;
  int32_T c5_j_a;
  int32_T c5_j_c;
  int32_T c5_j_loop_ub;
  int32_T c5_j_result;
  int32_T c5_k_a;
  int32_T c5_k_loop_ub;
  int32_T c5_l_a;
  int32_T c5_l_loop_ub;
  int32_T c5_loop_ub;
  int32_T c5_m_loop_ub;
  int32_T c5_m_result;
  int32_T c5_n_loop_ub;
  int32_T c5_o_loop_ub;
  int32_T c5_p_loop_ub;
  int32_T c5_q_loop_ub;
  int32_T c5_r_loop_ub;
  int32_T c5_r_result;
  int32_T c5_s_loop_ub;
  int32_T c5_t_result;
  int32_T c5_varargin_1;
  boolean_T c5_BW3[19200];
  boolean_T c5_b_edges[19200];
  boolean_T c5_edges[19200];
  boolean_T c5_b;
  boolean_T c5_b1;
  boolean_T c5_b10;
  boolean_T c5_b11;
  boolean_T c5_b12;
  boolean_T c5_b13;
  boolean_T c5_b14;
  boolean_T c5_b15;
  boolean_T c5_b16;
  boolean_T c5_b17;
  boolean_T c5_b18;
  boolean_T c5_b19;
  boolean_T c5_b2;
  boolean_T c5_b20;
  boolean_T c5_b21;
  boolean_T c5_b22;
  boolean_T c5_b23;
  boolean_T c5_b24;
  boolean_T c5_b25;
  boolean_T c5_b26;
  boolean_T c5_b27;
  boolean_T c5_b3;
  boolean_T c5_b4;
  boolean_T c5_b5;
  boolean_T c5_b6;
  boolean_T c5_b7;
  boolean_T c5_b8;
  boolean_T c5_b9;
  boolean_T c5_b_empty_non_axis_sizes;
  boolean_T c5_b_result;
  boolean_T c5_c_empty_non_axis_sizes;
  boolean_T c5_d_empty_non_axis_sizes;
  boolean_T c5_d_result;
  boolean_T c5_e_empty_non_axis_sizes;
  boolean_T c5_e_result;
  boolean_T c5_empty_non_axis_sizes;
  boolean_T c5_f_empty_non_axis_sizes;
  boolean_T c5_f_result;
  boolean_T c5_g_result;
  boolean_T c5_i_result;
  boolean_T c5_k_result;
  boolean_T c5_l_result;
  boolean_T c5_n_result;
  boolean_T c5_o_result;
  boolean_T c5_p_result;
  boolean_T c5_q_result;
  boolean_T c5_s_result;
  boolean_T c5_u_result;
  c5_st.tls = chartInstance->c5_fEmlrtCtx;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_c_st.prev = &c5_b_st;
  c5_c_st.tls = c5_b_st.tls;
  c5_d_st.prev = &c5_c_st;
  c5_d_st.tls = c5_c_st.tls;
  c5_e_st.prev = &c5_d_st;
  c5_e_st.tls = c5_d_st.tls;
  c5_f_st.prev = &c5_e_st;
  c5_f_st.tls = c5_e_st.tls;
  for (c5_i = 0; c5_i < 19200; c5_i++) {
    covrtSigUpdateFcn(chartInstance->c5_covrtInstance, 0U,
                      (*chartInstance->c5_d_u)[c5_i]);
  }

  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c5_JITTransitionAnimation[0] = 0U;
  chartInstance->c5_sfEvent = CALL_EVENT;
  for (c5_i1 = 0; c5_i1 < 19200; c5_i1++) {
    chartInstance->c5_u[c5_i1] = (*chartInstance->c5_d_u)[c5_i1];
  }

  covrtEmlFcnEval(chartInstance->c5_covrtInstance, 4U, 0, 0);
  covrtEmlIfEval(chartInstance->c5_covrtInstance, 4U, 0, 0,
                 covrtRelationalopUpdateFcn(chartInstance->c5_covrtInstance, 4U,
    0U, 0U, 1.0, 3.0, -1, 0U, 0));
  for (c5_i2 = 0; c5_i2 < 19200; c5_i2++) {
    chartInstance->c5_b_u[c5_i2] = chartInstance->c5_u[c5_i2];
  }

  c5_b_st.site = &c5_emlrtRSI;
  c5_imgaussfilt(chartInstance, &c5_b_st, chartInstance->c5_b_u,
                 chartInstance->c5_u);
  c5_b_st.site = &c5_b_emlrtRSI;
  c5_c_st.site = &c5_oc_emlrtRSI;
  c5_d_st.site = &c5_pc_emlrtRSI;
  c5_e_st.site = &c5_qc_emlrtRSI;
  c5_f_st.site = &c5_rc_emlrtRSI;
  grayto8_real64(&chartInstance->c5_u[0], &chartInstance->c5_c_u[0], 19200.0);
  c5_d_st.site = &c5_pc_emlrtRSI;
  c5_e_st.site = &c5_tc_emlrtRSI;
  c5_f_st.site = &c5_vc_emlrtRSI;
  c5_b_out = 1.0;
  getnumcores(&c5_b_out);
  c5_f_st.site = &c5_uc_emlrtRSI;
  for (c5_i3 = 0; c5_i3 < 256; c5_i3++) {
    c5_y[c5_i3] = 0.0;
  }

  for (c5_i4 = 0; c5_i4 < 256; c5_i4++) {
    c5_localBins1[c5_i4] = 0.0;
  }

  for (c5_i5 = 0; c5_i5 < 256; c5_i5++) {
    c5_localBins2[c5_i5] = 0.0;
  }

  for (c5_i6 = 0; c5_i6 < 256; c5_i6++) {
    c5_localBins3[c5_i6] = 0.0;
  }

  for (c5_b_i = 4; c5_b_i <= 19200; c5_b_i += 4) {
    c5_i7 = c5_b_i - 3;
    if ((c5_i7 < 1) || (c5_i7 > 19200)) {
      emlrtDynamicBoundsCheckR2012b(c5_i7, 1, 19200, &c5_emlrtBCI, &c5_f_st);
    }

    c5_idx1 = chartInstance->c5_c_u[c5_i7 - 1];
    c5_i8 = c5_b_i - 2;
    if ((c5_i8 < 1) || (c5_i8 > 19200)) {
      emlrtDynamicBoundsCheckR2012b(c5_i8, 1, 19200, &c5_b_emlrtBCI, &c5_f_st);
    }

    c5_idx2 = chartInstance->c5_c_u[c5_i8 - 1];
    c5_i10 = c5_b_i - 1;
    if ((c5_i10 < 1) || (c5_i10 > 19200)) {
      emlrtDynamicBoundsCheckR2012b(c5_i10, 1, 19200, &c5_c_emlrtBCI, &c5_f_st);
    }

    c5_idx3 = chartInstance->c5_c_u[c5_i10 - 1];
    if ((c5_b_i < 1) || (c5_b_i > 19200)) {
      emlrtDynamicBoundsCheckR2012b(c5_b_i, 1, 19200, &c5_d_emlrtBCI, &c5_f_st);
    }

    c5_idx4 = chartInstance->c5_c_u[c5_b_i - 1];
    c5_e_a = c5_idx1 + 1;
    c5_c_c = c5_e_a - 1;
    c5_f_a = c5_idx1 + 1;
    c5_d_c = c5_f_a - 1;
    c5_localBins1[c5_c_c] = c5_localBins1[c5_d_c] + 1.0;
    c5_g_a = c5_idx2 + 1;
    c5_e_c = c5_g_a - 1;
    c5_h_a = c5_idx2 + 1;
    c5_f_c = c5_h_a - 1;
    c5_localBins2[c5_e_c] = c5_localBins2[c5_f_c] + 1.0;
    c5_i_a = c5_idx3 + 1;
    c5_g_c = c5_i_a - 1;
    c5_j_a = c5_idx3 + 1;
    c5_h_c = c5_j_a - 1;
    c5_localBins3[c5_g_c] = c5_localBins3[c5_h_c] + 1.0;
    c5_k_a = c5_idx4 + 1;
    c5_i_c = c5_k_a - 1;
    c5_l_a = c5_idx4 + 1;
    c5_j_c = c5_l_a - 1;
    c5_y[c5_i_c] = c5_y[c5_j_c] + 1.0;
  }

  while (c5_b_i - 3 <= 19200) {
    c5_idx = chartInstance->c5_c_u[c5_b_i - 4];
    c5_c_a = c5_idx + 1;
    c5_c = c5_c_a - 1;
    c5_d_a = c5_idx + 1;
    c5_b_c = c5_d_a - 1;
    c5_y[c5_c] = c5_y[c5_b_c] + 1.0;
    c5_b_i++;
  }

  for (c5_c_i = 0; c5_c_i < 256; c5_c_i++) {
    c5_d_i = (real_T)c5_c_i + 1.0;
    c5_y[(int32_T)c5_d_i - 1] = ((c5_y[(int32_T)c5_d_i - 1] + c5_localBins1
      [(int32_T)c5_d_i - 1]) + c5_localBins2[(int32_T)c5_d_i - 1]) +
      c5_localBins3[(int32_T)c5_d_i - 1];
  }

  c5_d_st.site = &c5_pc_emlrtRSI;
  c5_t = c5_otsuthresh(chartInstance, &c5_d_st, c5_y);
  c5_T = c5_t;
  for (c5_i9 = 0; c5_i9 < 19200; c5_i9++) {
    c5_BW3[c5_i9] = (chartInstance->c5_u[c5_i9] > c5_T);
  }

  c5_b_st.site = &c5_c_emlrtRSI;
  c5_edge(chartInstance, &c5_b_st, c5_BW3, c5_edges);
  for (c5_i11 = 0; c5_i11 < 2; c5_i11++) {
    c5_r.f1[c5_i11] = 10.0 + 15.0 * (real_T)c5_i11;
  }

  for (c5_i12 = 0; c5_i12 < 2; c5_i12++) {
    c5_r1.f1[c5_i12] = 15.0 + 20.0 * (real_T)c5_i12;
  }

  for (c5_i13 = 0; c5_i13 < 2; c5_i13++) {
    c5_r2.f1[c5_i13] = 20.0 + 30.0 * (real_T)c5_i13;
  }

  c5_radiusRanges[0] = c5_r;
  c5_radiusRanges[1] = c5_r1;
  c5_radiusRanges[2] = c5_r2;
  c5_array_real_T_2D_Constructor(chartInstance, &c5_centers);
  c5_array_real_T_2D_SetSize(chartInstance, &c5_st, &c5_centers, &c5_emlrtRTEI,
    0, 0);
  c5_array_real_T_2D_Constructor(chartInstance, &c5_radii);
  c5_array_real_T_2D_SetSize(chartInstance, &c5_st, &c5_radii, &c5_b_emlrtRTEI,
    0, 0);
  c5_array_real_T_2D_Constructor(chartInstance, &c5_centersTemp);
  c5_array_real_T_2D_Constructor(chartInstance, &c5_radiiTemp);
  c5_array_real_T_2D_Constructor(chartInstance, &c5_result);
  c5_array_cell_wrap_60_2s_Construct(chartInstance, c5_reshapes);
  c5_array_real_T_2D_Constructor(chartInstance, &c5_b_varargin_2);
  for (c5_e_i = 0; c5_e_i < 3; c5_e_i++) {
    c5_f_i = 1.0 + (real_T)c5_e_i;
    covrtEmlForEval(chartInstance->c5_covrtInstance, 4U, 0, 0, 1);
    if (c5_f_i != (real_T)(int32_T)muDoubleScalarFloor(c5_f_i)) {
      emlrtIntegerCheckR2012b(c5_f_i, &c5_emlrtDCI, &c5_st);
    }

    c5_i14 = (int32_T)c5_f_i - 1;
    if ((c5_i14 < 0) || (c5_i14 > 2)) {
      emlrtDynamicBoundsCheckR2012b(c5_i14, 0, 2, &c5_e_emlrtBCI, &c5_st);
    }

    c5_b_st.site = &c5_d_emlrtRSI;
    for (c5_i15 = 0; c5_i15 < 19200; c5_i15++) {
      c5_b_edges[c5_i15] = c5_edges[c5_i15];
    }

    for (c5_i16 = 0; c5_i16 < 2; c5_i16++) {
      c5_b_radiusRanges[c5_i16] = c5_radiusRanges[c5_i14].f1[c5_i16];
    }

    c5_imfindcircles(chartInstance, &c5_b_st, c5_b_edges, c5_b_radiusRanges,
                     &c5_centersTemp, &c5_radiiTemp);
    c5_b_st.site = &c5_e_emlrtRSI;
    c5_c_st.site = &c5_kk_emlrtRSI;
    c5_sizes[0] = 0;
    c5_b2 = (c5_centers.size[0] == 0);
    c5_b3 = (c5_centers.size[1] == 0);
    c5_b_result = (c5_b2 || c5_b3);
    if (!c5_b_result) {
      c5_c_result = c5_centers.size[1];
    } else {
      c5_b4 = (c5_centersTemp.size[0] == 0);
      c5_b5 = (c5_centersTemp.size[1] == 0);
      c5_d_result = (c5_b4 || c5_b5);
      if (!c5_d_result) {
        c5_c_result = c5_centersTemp.size[1];
      } else {
        if (c5_centers.size[1] > 0) {
          c5_c_result = c5_centers.size[1];
        } else {
          c5_c_result = 0;
        }

        if (c5_centersTemp.size[1] > c5_c_result) {
          c5_c_result = c5_centersTemp.size[1];
        }
      }
    }

    c5_sizes[1] = c5_c_result;
    c5_d_st.site = &c5_ji_emlrtRSI;
    c5_expected = c5_sizes[1];
    if (c5_centers.size[1] == c5_expected) {
      c5_b7 = true;
    } else {
      c5_b6 = (c5_centers.size[0] == 0);
      c5_b8 = (c5_centers.size[1] == 0);
      c5_e_result = (c5_b6 || c5_b8);
      if (c5_e_result) {
        c5_b7 = true;
      } else {
        c5_b7 = false;
      }
    }

    if (!c5_b7) {
      c5_e_y = NULL;
      sf_mex_assign(&c5_e_y, sf_mex_create("y", c5_cv, 10, 0U, 1, 0U, 2, 1, 39),
                    false);
      c5_f_y = NULL;
      sf_mex_assign(&c5_f_y, sf_mex_create("y", c5_cv, 10, 0U, 1, 0U, 2, 1, 39),
                    false);
      sf_mex_call(&c5_d_st, &c5_ab_emlrtMCI, "error", 0U, 2U, 14, c5_e_y, 14,
                  sf_mex_call(&c5_d_st, NULL, "getString", 1U, 1U, 14,
        sf_mex_call(&c5_d_st, NULL, "message", 1U, 1U, 14, c5_f_y)));
    }

    if (c5_centersTemp.size[1] == c5_expected) {
      c5_b7 = true;
    } else {
      c5_b9 = (c5_centersTemp.size[0] == 0);
      c5_b10 = (c5_centersTemp.size[1] == 0);
      c5_f_result = (c5_b9 || c5_b10);
      if (c5_f_result) {
        c5_b7 = true;
      } else {
        c5_b7 = false;
      }
    }

    if (!c5_b7) {
      c5_g_y = NULL;
      sf_mex_assign(&c5_g_y, sf_mex_create("y", c5_cv, 10, 0U, 1, 0U, 2, 1, 39),
                    false);
      c5_h_y = NULL;
      sf_mex_assign(&c5_h_y, sf_mex_create("y", c5_cv, 10, 0U, 1, 0U, 2, 1, 39),
                    false);
      sf_mex_call(&c5_d_st, &c5_ab_emlrtMCI, "error", 0U, 2U, 14, c5_g_y, 14,
                  sf_mex_call(&c5_d_st, NULL, "getString", 1U, 1U, 14,
        sf_mex_call(&c5_d_st, NULL, "message", 1U, 1U, 14, c5_h_y)));
    }

    c5_varargin_1 = c5_sizes[1];
    c5_arg = c5_varargin_1;
    c5_g_result = (c5_arg == 0);
    if (c5_g_result) {
      c5_empty_non_axis_sizes = true;
    } else {
      c5_empty_non_axis_sizes = false;
    }

    for (c5_i17 = 0; c5_i17 < 2; c5_i17++) {
      c5_input_sizes[c5_i17] = c5_sizes[c5_i17];
    }

    c5_b_empty_non_axis_sizes = c5_empty_non_axis_sizes;
    if (c5_b_empty_non_axis_sizes) {
      c5_h_result = c5_centers.size[0];
    } else {
      c5_b11 = (c5_centers.size[0] == 0);
      c5_b12 = (c5_centers.size[1] == 0);
      c5_i_result = (c5_b11 || c5_b12);
      if (!c5_i_result) {
        c5_h_result = c5_centers.size[0];
      } else {
        c5_h_result = 0;
      }
    }

    c5_input_sizes[0] = c5_h_result;
    c5_array_real_T_2D_SetSize(chartInstance, &c5_c_st, &c5_reshapes[0].f1,
      &c5_c_emlrtRTEI, c5_input_sizes[0], c5_input_sizes[1]);
    c5_loop_ub = c5_input_sizes[0] * c5_input_sizes[1] - 1;
    for (c5_i18 = 0; c5_i18 <= c5_loop_ub; c5_i18++) {
      c5_reshapes[0].f1.vector.data[c5_i18] = c5_centers.vector.data[c5_i18];
    }

    c5_c_empty_non_axis_sizes = c5_empty_non_axis_sizes;
    if (c5_c_empty_non_axis_sizes) {
      c5_j_result = c5_centersTemp.size[0];
    } else {
      c5_b13 = (c5_centersTemp.size[0] == 0);
      c5_b14 = (c5_centersTemp.size[1] == 0);
      c5_k_result = (c5_b13 || c5_b14);
      if (!c5_k_result) {
        c5_j_result = c5_centersTemp.size[0];
      } else {
        c5_j_result = 0;
      }
    }

    c5_sizes[0] = c5_j_result;
    c5_array_real_T_2D_SetSize(chartInstance, &c5_c_st, &c5_reshapes[1].f1,
      &c5_c_emlrtRTEI, c5_sizes[0], c5_sizes[1]);
    c5_b_loop_ub = c5_sizes[0] * c5_sizes[1] - 1;
    for (c5_i19 = 0; c5_i19 <= c5_b_loop_ub; c5_i19++) {
      c5_reshapes[1].f1.vector.data[c5_i19] = c5_centersTemp.vector.data[c5_i19];
    }

    c5_array_real_T_2D_SetSize(chartInstance, &c5_c_st, &c5_centersTemp,
      &c5_d_emlrtRTEI, c5_reshapes[0].f1.size[0], c5_reshapes[0].f1.size[1]);
    c5_c_loop_ub = c5_reshapes[0].f1.size[0] * c5_reshapes[0].f1.size[1] - 1;
    for (c5_i20 = 0; c5_i20 <= c5_c_loop_ub; c5_i20++) {
      c5_centersTemp.vector.data[c5_i20] = c5_reshapes[0].f1.vector.data[c5_i20];
    }

    c5_array_real_T_2D_SetSize(chartInstance, &c5_c_st, &c5_b_varargin_2,
      &c5_d_emlrtRTEI, c5_reshapes[1].f1.size[0], c5_reshapes[1].f1.size[1]);
    c5_d_loop_ub = c5_reshapes[1].f1.size[0] * c5_reshapes[1].f1.size[1] - 1;
    for (c5_i21 = 0; c5_i21 <= c5_d_loop_ub; c5_i21++) {
      c5_b_varargin_2.vector.data[c5_i21] = c5_reshapes[1].f1.vector.data[c5_i21];
    }

    c5_array_real_T_2D_SetSize(chartInstance, &c5_c_st, &c5_centers,
      &c5_e_emlrtRTEI, c5_centersTemp.size[0] + c5_b_varargin_2.size[0],
      c5_centersTemp.size[1]);
    c5_e_loop_ub = c5_centersTemp.size[1] - 1;
    for (c5_i22 = 0; c5_i22 <= c5_e_loop_ub; c5_i22++) {
      c5_g_loop_ub = c5_centersTemp.size[0] - 1;
      for (c5_i24 = 0; c5_i24 <= c5_g_loop_ub; c5_i24++) {
        c5_centers.vector.data[c5_i24 + c5_centers.size[0] * c5_i22] =
          c5_centersTemp.vector.data[c5_i24 + c5_centersTemp.size[0] * c5_i22];
      }
    }

    c5_f_loop_ub = c5_b_varargin_2.size[1] - 1;
    for (c5_i23 = 0; c5_i23 <= c5_f_loop_ub; c5_i23++) {
      c5_h_loop_ub = c5_b_varargin_2.size[0] - 1;
      for (c5_i25 = 0; c5_i25 <= c5_h_loop_ub; c5_i25++) {
        c5_centers.vector.data[(c5_i25 + c5_centersTemp.size[0]) +
          c5_centers.size[0] * c5_i23] = c5_b_varargin_2.vector.data[c5_i25 +
          c5_b_varargin_2.size[0] * c5_i23];
      }
    }

    c5_b_st.site = &c5_f_emlrtRSI;
    c5_array_real_T_2D_SetSize(chartInstance, &c5_b_st, &c5_centersTemp,
      &c5_f_emlrtRTEI, c5_radii.size[0], c5_radii.size[1]);
    c5_i_loop_ub = c5_radii.size[0] * c5_radii.size[1] - 1;
    for (c5_i26 = 0; c5_i26 <= c5_i_loop_ub; c5_i26++) {
      c5_centersTemp.vector.data[c5_i26] = c5_radii.vector.data[c5_i26];
    }

    c5_array_real_T_2D_SetSize(chartInstance, &c5_b_st, &c5_b_varargin_2,
      &c5_g_emlrtRTEI, c5_radiiTemp.size[0], c5_radiiTemp.size[1]);
    c5_j_loop_ub = c5_radiiTemp.size[0] * c5_radiiTemp.size[1] - 1;
    for (c5_i27 = 0; c5_i27 <= c5_j_loop_ub; c5_i27++) {
      c5_b_varargin_2.vector.data[c5_i27] = c5_radiiTemp.vector.data[c5_i27];
    }

    c5_c_st.site = &c5_kk_emlrtRSI;
    c5_sizes[0] = 0;
    c5_b15 = (c5_centersTemp.size[0] == 0);
    c5_b16 = (c5_centersTemp.size[1] == 0);
    c5_l_result = (c5_b15 || c5_b16);
    if (!c5_l_result) {
      c5_m_result = c5_centersTemp.size[1];
    } else {
      c5_b17 = (c5_b_varargin_2.size[0] == 0);
      c5_b18 = (c5_b_varargin_2.size[1] == 0);
      c5_n_result = (c5_b17 || c5_b18);
      if (!c5_n_result) {
        c5_m_result = c5_b_varargin_2.size[1];
      } else {
        if (c5_centersTemp.size[1] > 0) {
          c5_m_result = c5_centersTemp.size[1];
        } else {
          c5_m_result = 0;
        }

        if (c5_b_varargin_2.size[1] > c5_m_result) {
          c5_m_result = c5_b_varargin_2.size[1];
        }
      }
    }

    c5_sizes[1] = c5_m_result;
    c5_d_st.site = &c5_ji_emlrtRSI;
    c5_b_expected = c5_sizes[1];
    if (c5_centersTemp.size[1] == c5_b_expected) {
      c5_b20 = true;
    } else {
      c5_b19 = (c5_centersTemp.size[0] == 0);
      c5_b21 = (c5_centersTemp.size[1] == 0);
      c5_o_result = (c5_b19 || c5_b21);
      if (c5_o_result) {
        c5_b20 = true;
      } else {
        c5_b20 = false;
      }
    }

    if (!c5_b20) {
      c5_i_y = NULL;
      sf_mex_assign(&c5_i_y, sf_mex_create("y", c5_cv, 10, 0U, 1, 0U, 2, 1, 39),
                    false);
      c5_j_y = NULL;
      sf_mex_assign(&c5_j_y, sf_mex_create("y", c5_cv, 10, 0U, 1, 0U, 2, 1, 39),
                    false);
      sf_mex_call(&c5_d_st, &c5_ab_emlrtMCI, "error", 0U, 2U, 14, c5_i_y, 14,
                  sf_mex_call(&c5_d_st, NULL, "getString", 1U, 1U, 14,
        sf_mex_call(&c5_d_st, NULL, "message", 1U, 1U, 14, c5_j_y)));
    }

    if (c5_b_varargin_2.size[1] == c5_b_expected) {
      c5_b20 = true;
    } else {
      c5_b22 = (c5_b_varargin_2.size[0] == 0);
      c5_b23 = (c5_b_varargin_2.size[1] == 0);
      c5_p_result = (c5_b22 || c5_b23);
      if (c5_p_result) {
        c5_b20 = true;
      } else {
        c5_b20 = false;
      }
    }

    if (!c5_b20) {
      c5_k_y = NULL;
      sf_mex_assign(&c5_k_y, sf_mex_create("y", c5_cv, 10, 0U, 1, 0U, 2, 1, 39),
                    false);
      c5_l_y = NULL;
      sf_mex_assign(&c5_l_y, sf_mex_create("y", c5_cv, 10, 0U, 1, 0U, 2, 1, 39),
                    false);
      sf_mex_call(&c5_d_st, &c5_ab_emlrtMCI, "error", 0U, 2U, 14, c5_k_y, 14,
                  sf_mex_call(&c5_d_st, NULL, "getString", 1U, 1U, 14,
        sf_mex_call(&c5_d_st, NULL, "message", 1U, 1U, 14, c5_l_y)));
    }

    c5_b_varargin_1 = c5_sizes[1];
    c5_b_arg = c5_b_varargin_1;
    c5_q_result = (c5_b_arg == 0);
    if (c5_q_result) {
      c5_d_empty_non_axis_sizes = true;
    } else {
      c5_d_empty_non_axis_sizes = false;
    }

    for (c5_i28 = 0; c5_i28 < 2; c5_i28++) {
      c5_input_sizes[c5_i28] = c5_sizes[c5_i28];
    }

    c5_e_empty_non_axis_sizes = c5_d_empty_non_axis_sizes;
    if (c5_e_empty_non_axis_sizes) {
      c5_r_result = c5_centersTemp.size[0];
    } else {
      c5_b24 = (c5_centersTemp.size[0] == 0);
      c5_b25 = (c5_centersTemp.size[1] == 0);
      c5_s_result = (c5_b24 || c5_b25);
      if (!c5_s_result) {
        c5_r_result = c5_centersTemp.size[0];
      } else {
        c5_r_result = 0;
      }
    }

    c5_input_sizes[0] = c5_r_result;
    c5_array_real_T_2D_SetSize(chartInstance, &c5_c_st, &c5_reshapes[0].f1,
      &c5_c_emlrtRTEI, c5_input_sizes[0], c5_input_sizes[1]);
    c5_k_loop_ub = c5_input_sizes[0] * c5_input_sizes[1] - 1;
    for (c5_i29 = 0; c5_i29 <= c5_k_loop_ub; c5_i29++) {
      c5_reshapes[0].f1.vector.data[c5_i29] = c5_centersTemp.vector.data[c5_i29];
    }

    c5_f_empty_non_axis_sizes = c5_d_empty_non_axis_sizes;
    if (c5_f_empty_non_axis_sizes) {
      c5_t_result = c5_b_varargin_2.size[0];
    } else {
      c5_b26 = (c5_b_varargin_2.size[0] == 0);
      c5_b27 = (c5_b_varargin_2.size[1] == 0);
      c5_u_result = (c5_b26 || c5_b27);
      if (!c5_u_result) {
        c5_t_result = c5_b_varargin_2.size[0];
      } else {
        c5_t_result = 0;
      }
    }

    c5_sizes[0] = c5_t_result;
    c5_array_real_T_2D_SetSize(chartInstance, &c5_c_st, &c5_reshapes[1].f1,
      &c5_c_emlrtRTEI, c5_sizes[0], c5_sizes[1]);
    c5_l_loop_ub = c5_sizes[0] * c5_sizes[1] - 1;
    for (c5_i30 = 0; c5_i30 <= c5_l_loop_ub; c5_i30++) {
      c5_reshapes[1].f1.vector.data[c5_i30] = c5_b_varargin_2.vector.data[c5_i30];
    }

    c5_array_real_T_2D_SetSize(chartInstance, &c5_c_st, &c5_centersTemp,
      &c5_d_emlrtRTEI, c5_reshapes[0].f1.size[0], c5_reshapes[0].f1.size[1]);
    c5_m_loop_ub = c5_reshapes[0].f1.size[0] * c5_reshapes[0].f1.size[1] - 1;
    for (c5_i31 = 0; c5_i31 <= c5_m_loop_ub; c5_i31++) {
      c5_centersTemp.vector.data[c5_i31] = c5_reshapes[0].f1.vector.data[c5_i31];
    }

    c5_array_real_T_2D_SetSize(chartInstance, &c5_c_st, &c5_b_varargin_2,
      &c5_d_emlrtRTEI, c5_reshapes[1].f1.size[0], c5_reshapes[1].f1.size[1]);
    c5_n_loop_ub = c5_reshapes[1].f1.size[0] * c5_reshapes[1].f1.size[1] - 1;
    for (c5_i32 = 0; c5_i32 <= c5_n_loop_ub; c5_i32++) {
      c5_b_varargin_2.vector.data[c5_i32] = c5_reshapes[1].f1.vector.data[c5_i32];
    }

    c5_array_real_T_2D_SetSize(chartInstance, &c5_c_st, &c5_result,
      &c5_h_emlrtRTEI, c5_centersTemp.size[0] + c5_b_varargin_2.size[0],
      c5_centersTemp.size[1]);
    c5_o_loop_ub = c5_centersTemp.size[1] - 1;
    for (c5_i33 = 0; c5_i33 <= c5_o_loop_ub; c5_i33++) {
      c5_q_loop_ub = c5_centersTemp.size[0] - 1;
      for (c5_i35 = 0; c5_i35 <= c5_q_loop_ub; c5_i35++) {
        c5_result.vector.data[c5_i35 + c5_result.size[0] * c5_i33] =
          c5_centersTemp.vector.data[c5_i35 + c5_centersTemp.size[0] * c5_i33];
      }
    }

    c5_p_loop_ub = c5_b_varargin_2.size[1] - 1;
    for (c5_i34 = 0; c5_i34 <= c5_p_loop_ub; c5_i34++) {
      c5_r_loop_ub = c5_b_varargin_2.size[0] - 1;
      for (c5_i36 = 0; c5_i36 <= c5_r_loop_ub; c5_i36++) {
        c5_result.vector.data[(c5_i36 + c5_centersTemp.size[0]) +
          c5_result.size[0] * c5_i34] = c5_b_varargin_2.vector.data[c5_i36 +
          c5_b_varargin_2.size[0] * c5_i34];
      }
    }

    c5_array_real_T_2D_SetSize(chartInstance, &c5_st, &c5_radii, &c5_i_emlrtRTEI,
      c5_result.size[0], c5_result.size[1]);
    c5_s_loop_ub = c5_result.size[0] * c5_result.size[1] - 1;
    for (c5_i37 = 0; c5_i37 <= c5_s_loop_ub; c5_i37++) {
      c5_radii.vector.data[c5_i37] = c5_result.vector.data[c5_i37];
    }

    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  c5_array_real_T_2D_Destructor(chartInstance, &c5_b_varargin_2);
  c5_array_cell_wrap_60_2s_Destructo(chartInstance, c5_reshapes);
  c5_array_real_T_2D_Destructor(chartInstance, &c5_result);
  c5_array_real_T_2D_Destructor(chartInstance, &c5_radiiTemp);
  c5_array_real_T_2D_Destructor(chartInstance, &c5_centersTemp);
  c5_array_real_T_2D_Destructor(chartInstance, &c5_radii);
  covrtEmlForEval(chartInstance->c5_covrtInstance, 4U, 0, 0, 0);
  c5_b = (c5_centers.size[0] == 0);
  c5_b1 = (c5_centers.size[1] == 0);
  c5_array_real_T_2D_Destructor(chartInstance, &c5_centers);
  if (covrtEmlIfEval(chartInstance->c5_covrtInstance, 4U, 0, 1, covrtEmlMcdcEval
                     (chartInstance->c5_covrtInstance, 4U, 0, 0,
                      !covrtEmlCondEval(chartInstance->c5_covrtInstance, 4U, 0,
         0, c5_b || c5_b1)))) {
    c5_b_number = 2.0;
    c5_b_st.site = &c5_g_emlrtRSI;
    c5_c_st.site = &c5_lk_emlrtRSI;
    c5_b_y = NULL;
    sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1, 7),
                  false);
    c5_e_u = 1.0;
    c5_c_y = NULL;
    sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_e_u, 0, 0U, 0, 0U, 0), false);
    c5_d_y = NULL;
    sf_mex_assign(&c5_d_y, sf_mex_create("y", c5_b_cv1, 10, 0U, 1, 0U, 2, 1, 18),
                  false);
    c5_d_st.site = &c5_mk_emlrtRSI;
    c5_emlrt_marshallIn(chartInstance, c5_e_feval(chartInstance, &c5_d_st,
      c5_b_y, c5_c_y, c5_d_y), "<output of feval>");
  } else {
    c5_b_number = 1.0;
  }

  *chartInstance->c5_number = c5_b_number;
  covrtSigUpdateFcn(chartInstance->c5_covrtInstance, 1U,
                    *chartInstance->c5_number);
}

static void ext_mode_exec_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c5_update_jit_animation_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c5_do_animation_call_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance)
{
  const mxArray *c5_b_y = NULL;
  const mxArray *c5_st = NULL;
  const mxArray *c5_y = NULL;
  c5_st = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_createcellmatrix(1, 1), false);
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", chartInstance->c5_number, 0, 0U, 0,
    0U, 0), false);
  sf_mex_setcell(c5_y, 0, c5_b_y);
  sf_mex_assign(&c5_st, c5_y, false);
  return c5_st;
}

static void set_sim_state_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance, const mxArray *c5_st)
{
  const mxArray *c5_e_u;
  chartInstance->c5_doneDoubleBufferReInit = true;
  c5_e_u = sf_mex_dup(c5_st);
  *chartInstance->c5_number = c5_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c5_e_u, 0)), "number");
  sf_mex_destroy(&c5_e_u);
  sf_mex_destroy(&c5_st);
}

static void c5_imgaussfilt(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, real_T c5_b_A[19200], real_T c5_B[19200])
{
  static int32_T c5_idxA[336] = { 1, 1, 1, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
    12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
    31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49,
    50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68,
    69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87,
    88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105,
    106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120,
    120, 120, 120, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
    2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22,
    23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41,
    42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60,
    61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
    80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98,
    99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113,
    114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128,
    129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143,
    144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158,
    159, 160, 160, 160, 160, 160 };

  static char_T c5_b_cv[4] = { 's', 'q', 'r', 't' };

  static char_T c5_b_cv1[4] = { 's', 'q', 'r', 't' };

  emlrtStack c5_b_st;
  emlrtStack c5_c_st;
  emlrtStack c5_d_st;
  emlrtStack c5_st;
  const mxArray *c5_b_y = NULL;
  const mxArray *c5_c_y = NULL;
  const mxArray *c5_d_y = NULL;
  const mxArray *c5_f_y = NULL;
  const mxArray *c5_h_y = NULL;
  const mxArray *c5_y = NULL;
  real_T c5_a__1[81];
  real_T c5_a__2[81];
  real_T c5_b_s[81];
  real_T c5_c_s[9];
  real_T c5_hcol[9];
  real_T c5_hrow[9];
  real_T c5_nonzero_h_data[9];
  real_T c5_connDimsT[2];
  real_T c5_outSizeT[2];
  real_T c5_padSizeT[2];
  real_T c5_startT[2];
  real_T c5_b_numKernElem;
  real_T c5_b_x;
  real_T c5_c_j;
  real_T c5_c_x;
  real_T c5_d_b;
  real_T c5_d_j;
  real_T c5_d_x;
  real_T c5_e_b;
  real_T c5_e_i;
  real_T c5_e_x;
  real_T c5_e_y;
  real_T c5_ex;
  real_T c5_f_i;
  real_T c5_f_x;
  real_T c5_g_x;
  real_T c5_g_y;
  real_T c5_h_x;
  real_T c5_i_x;
  real_T c5_maxval;
  real_T c5_numKernElem;
  real_T c5_rank;
  real_T c5_tol;
  int32_T c5_nonzero_h_size[1];
  int32_T c5_b_end;
  int32_T c5_b_i;
  int32_T c5_b_j;
  int32_T c5_b_k;
  int32_T c5_b_partialTrueCount;
  int32_T c5_b_trueCount;
  int32_T c5_c_b;
  int32_T c5_c_i;
  int32_T c5_c_k;
  int32_T c5_d_i;
  int32_T c5_d_k;
  int32_T c5_e_k;
  int32_T c5_end;
  int32_T c5_f_k;
  int32_T c5_first;
  int32_T c5_g_i;
  int32_T c5_g_k;
  int32_T c5_h_i;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i10;
  int32_T c5_i11;
  int32_T c5_i12;
  int32_T c5_i13;
  int32_T c5_i14;
  int32_T c5_i15;
  int32_T c5_i16;
  int32_T c5_i17;
  int32_T c5_i18;
  int32_T c5_i19;
  int32_T c5_i2;
  int32_T c5_i20;
  int32_T c5_i21;
  int32_T c5_i22;
  int32_T c5_i23;
  int32_T c5_i24;
  int32_T c5_i25;
  int32_T c5_i26;
  int32_T c5_i27;
  int32_T c5_i28;
  int32_T c5_i29;
  int32_T c5_i3;
  int32_T c5_i30;
  int32_T c5_i31;
  int32_T c5_i32;
  int32_T c5_i4;
  int32_T c5_i5;
  int32_T c5_i6;
  int32_T c5_i7;
  int32_T c5_i8;
  int32_T c5_i9;
  int32_T c5_i_i;
  int32_T c5_idx;
  int32_T c5_ix;
  int32_T c5_j;
  int32_T c5_j_i;
  int32_T c5_k;
  int32_T c5_k_i;
  int32_T c5_l_i;
  int32_T c5_nz;
  int32_T c5_partialTrueCount;
  int32_T c5_trueCount;
  int32_T c5_xoffset;
  boolean_T c5_b_conn[81];
  boolean_T c5_conn[9];
  boolean_T c5_b;
  boolean_T c5_b_b;
  boolean_T c5_b_densityFlag;
  boolean_T c5_b_modeFlag;
  boolean_T c5_b_p;
  boolean_T c5_b_tooBig;
  boolean_T c5_c_modeFlag;
  boolean_T c5_c_p;
  boolean_T c5_c_tooBig;
  boolean_T c5_d_modeFlag;
  boolean_T c5_d_p;
  boolean_T c5_densityFlag;
  boolean_T c5_e_modeFlag;
  boolean_T c5_e_p;
  boolean_T c5_exitg1;
  boolean_T c5_f_modeFlag;
  boolean_T c5_f_p;
  boolean_T c5_g_modeFlag;
  boolean_T c5_h_modeFlag;
  boolean_T c5_i_modeFlag;
  boolean_T c5_modeFlag;
  boolean_T c5_p;
  boolean_T c5_separable;
  boolean_T c5_tooBig;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_c_st.prev = &c5_b_st;
  c5_c_st.tls = c5_b_st.tls;
  c5_d_st.prev = &c5_c_st;
  c5_d_st.tls = c5_c_st.tls;
  c5_st.site = &c5_h_emlrtRSI;
  c5_b_st.site = &c5_i_emlrtRSI;
  c5_b_st.site = &c5_j_emlrtRSI;
  c5_c_st.site = &c5_k_emlrtRSI;
  c5_d_st.site = &c5_t_emlrtRSI;
  c5_svd(chartInstance, &c5_d_st, c5_a__1, c5_b_s, c5_a__2);
  c5_k = 0;
  for (c5_b_k = 0; c5_b_k < 9; c5_b_k++) {
    c5_c_s[c5_b_k] = c5_b_s[c5_k];
    c5_k += 10;
  }

  c5_b_x = c5_c_s[0];
  c5_c_x = c5_b_x;
  c5_b = muDoubleScalarIsNaN(c5_c_x);
  c5_p = !c5_b;
  if (c5_p) {
    c5_idx = 1;
  } else {
    c5_idx = 0;
    c5_c_k = 2;
    c5_exitg1 = false;
    while ((!c5_exitg1) && (c5_c_k < 10)) {
      c5_d_x = c5_c_s[c5_c_k - 1];
      c5_e_x = c5_d_x;
      c5_b_b = muDoubleScalarIsNaN(c5_e_x);
      c5_b_p = !c5_b_b;
      if (c5_b_p) {
        c5_idx = c5_c_k;
        c5_exitg1 = true;
      } else {
        c5_c_k++;
      }
    }
  }

  if (c5_idx == 0) {
    c5_maxval = c5_c_s[0];
  } else {
    c5_first = c5_idx - 1;
    c5_ex = c5_c_s[c5_first];
    c5_i = c5_first;
    for (c5_d_k = c5_i + 2; c5_d_k < 10; c5_d_k++) {
      if (c5_ex < c5_c_s[c5_d_k - 1]) {
        c5_ex = c5_c_s[c5_d_k - 1];
      }
    }

    c5_maxval = c5_ex;
  }

  c5_tol = 9.0 * c5_maxval * 2.2204460492503131E-16;
  for (c5_i1 = 0; c5_i1 < 9; c5_i1++) {
    c5_conn[c5_i1] = (c5_c_s[c5_i1] > c5_tol);
  }

  c5_nz = (int32_T)c5_conn[0];
  for (c5_e_k = 0; c5_e_k < 8; c5_e_k++) {
    c5_xoffset = c5_e_k;
    c5_ix = c5_xoffset;
    c5_c_b = (int32_T)c5_conn[c5_ix + 1];
    c5_nz += (c5_c_b != 0);
  }

  c5_rank = (real_T)c5_nz;
  if (c5_rank == 1.0) {
    c5_separable = true;
  } else {
    c5_separable = false;
  }

  if (c5_separable) {
    c5_c_st.site = &c5_l_emlrtRSI;
    c5_d_st.site = &c5_jc_emlrtRSI;
    for (c5_b_j = 0; c5_b_j < 168; c5_b_j++) {
      c5_d_j = (real_T)c5_b_j + 1.0;
      for (c5_c_i = 0; c5_c_i < 128; c5_c_i++) {
        c5_f_i = (real_T)c5_c_i + 1.0;
        if ((c5_idxA[(int32_T)c5_f_i - 1] < 1) || (c5_idxA[(int32_T)c5_f_i - 1] >
             120)) {
          emlrtDynamicBoundsCheckR2012b(c5_idxA[(int32_T)c5_f_i - 1], 1, 120,
            &c5_f_emlrtBCI, &c5_d_st);
        }

        c5_i4 = c5_idxA[(int32_T)c5_d_j + 167];
        if ((c5_i4 < 1) || (c5_i4 > 160)) {
          emlrtDynamicBoundsCheckR2012b(c5_i4, 1, 160, &c5_g_emlrtBCI, &c5_d_st);
        }

        chartInstance->c5_d_aTmp[((int32_T)c5_f_i + (((int32_T)c5_d_j - 1) << 7))
          - 1] = c5_b_A[(c5_idxA[(int32_T)c5_f_i - 1] + 120 * (c5_i4 - 1)) - 1];
      }
    }

    c5_c_st.site = &c5_m_emlrtRSI;
    c5_svd(chartInstance, &c5_c_st, c5_a__1, c5_b_s, c5_a__2);
    c5_f_k = 0;
    for (c5_g_k = 0; c5_g_k < 9; c5_g_k++) {
      c5_c_s[c5_g_k] = c5_b_s[c5_f_k];
      c5_f_k += 10;
    }

    for (c5_i2 = 0; c5_i2 < 9; c5_i2++) {
      c5_hcol[c5_i2] = c5_a__1[c5_i2];
    }

    c5_c_st.site = &c5_n_emlrtRSI;
    c5_f_x = c5_c_s[0];
    c5_d_b = c5_f_x;
    c5_g_x = c5_d_b;
    if (c5_g_x < 0.0) {
      c5_c_p = true;
    } else {
      c5_c_p = false;
    }

    c5_d_p = c5_c_p;
    if (c5_d_p) {
      c5_y = NULL;
      sf_mex_assign(&c5_y, sf_mex_create("y", c5_cv1, 10, 0U, 1, 0U, 2, 1, 30),
                    false);
      c5_b_y = NULL;
      sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_cv1, 10, 0U, 1, 0U, 2, 1, 30),
                    false);
      c5_c_y = NULL;
      sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1, 4),
                    false);
      sf_mex_call(&c5_c_st, &c5_e_emlrtMCI, "error", 0U, 2U, 14, c5_y, 14,
                  sf_mex_call(&c5_c_st, NULL, "getString", 1U, 1U, 14,
        sf_mex_call(&c5_c_st, NULL, "message", 1U, 2U, 14, c5_b_y, 14, c5_c_y)));
    }

    c5_d_b = muDoubleScalarSqrt(c5_d_b);
    for (c5_i12 = 0; c5_i12 < 9; c5_i12++) {
      c5_hcol[c5_i12] *= c5_d_b;
    }

    for (c5_i14 = 0; c5_i14 < 9; c5_i14++) {
      c5_hrow[c5_i14] = c5_a__2[c5_i14];
    }

    c5_c_st.site = &c5_o_emlrtRSI;
    c5_h_x = c5_c_s[0];
    c5_e_b = c5_h_x;
    c5_i_x = c5_e_b;
    if (c5_i_x < 0.0) {
      c5_e_p = true;
    } else {
      c5_e_p = false;
    }

    c5_f_p = c5_e_p;
    if (c5_f_p) {
      c5_d_y = NULL;
      sf_mex_assign(&c5_d_y, sf_mex_create("y", c5_cv1, 10, 0U, 1, 0U, 2, 1, 30),
                    false);
      c5_f_y = NULL;
      sf_mex_assign(&c5_f_y, sf_mex_create("y", c5_cv1, 10, 0U, 1, 0U, 2, 1, 30),
                    false);
      c5_h_y = NULL;
      sf_mex_assign(&c5_h_y, sf_mex_create("y", c5_b_cv1, 10, 0U, 1, 0U, 2, 1, 4),
                    false);
      sf_mex_call(&c5_c_st, &c5_e_emlrtMCI, "error", 0U, 2U, 14, c5_d_y, 14,
                  sf_mex_call(&c5_c_st, NULL, "getString", 1U, 1U, 14,
        sf_mex_call(&c5_c_st, NULL, "message", 1U, 2U, 14, c5_f_y, 14, c5_h_y)));
    }

    c5_e_b = muDoubleScalarSqrt(c5_e_b);
    c5_e_y = c5_e_b;
    c5_g_y = c5_e_y;
    for (c5_i15 = 0; c5_i15 < 9; c5_i15++) {
      c5_hrow[c5_i15] *= c5_g_y;
    }

    c5_c_st.site = &c5_p_emlrtRSI;
    for (c5_i16 = 0; c5_i16 < 9; c5_i16++) {
      c5_conn[c5_i16] = (c5_hrow[c5_i16] != 0.0);
    }

    for (c5_i17 = 0; c5_i17 < 9; c5_i17++) {
      c5_c_s[c5_i17] = c5_hrow[c5_i17];
    }

    c5_end = 9;
    c5_trueCount = 0;
    for (c5_g_i = 0; c5_g_i < c5_end; c5_g_i++) {
      if (c5_conn[c5_g_i]) {
        c5_trueCount++;
      }
    }

    c5_nonzero_h_size[0] = c5_trueCount;
    c5_partialTrueCount = 0;
    for (c5_h_i = 0; c5_h_i < c5_end; c5_h_i++) {
      if (c5_conn[c5_h_i]) {
        c5_nonzero_h_data[c5_partialTrueCount] = c5_c_s[c5_h_i];
        c5_partialTrueCount++;
      }
    }

    c5_densityFlag = false;
    if ((real_T)c5_nonzero_h_size[0] / 9.0 > 0.05) {
      c5_densityFlag = true;
    }

    c5_b_tooBig = true;
    for (c5_i_i = 0; c5_i_i < 2; c5_i_i++) {
      c5_b_tooBig = false;
    }

    if (c5_densityFlag && (!c5_b_tooBig)) {
      c5_d_modeFlag = true;
    } else {
      c5_d_modeFlag = false;
    }

    if (c5_d_modeFlag) {
      c5_e_modeFlag = true;
    } else {
      c5_e_modeFlag = false;
    }

    c5_f_modeFlag = c5_e_modeFlag;
    if (c5_f_modeFlag) {
      for (c5_i18 = 0; c5_i18 < 2; c5_i18++) {
        c5_padSizeT[c5_i18] = 128.0 + 40.0 * (real_T)c5_i18;
      }

      for (c5_i20 = 0; c5_i20 < 2; c5_i20++) {
        c5_outSizeT[c5_i20] = 128.0 + 32.0 * (real_T)c5_i20;
      }

      for (c5_i22 = 0; c5_i22 < 2; c5_i22++) {
        c5_connDimsT[c5_i22] = 1.0 + 8.0 * (real_T)c5_i22;
      }

      ippfilter_real64(&chartInstance->c5_d_aTmp[0], &chartInstance->c5_b_bTmp[0],
                       &c5_outSizeT[0], 2.0, &c5_padSizeT[0], &c5_hrow[0],
                       &c5_connDimsT[0], false);
    } else {
      c5_numKernElem = (real_T)c5_nonzero_h_size[0];
      for (c5_i19 = 0; c5_i19 < 2; c5_i19++) {
        c5_padSizeT[c5_i19] = 128.0 + 40.0 * (real_T)c5_i19;
      }

      for (c5_i21 = 0; c5_i21 < 2; c5_i21++) {
        c5_outSizeT[c5_i21] = 128.0 + 32.0 * (real_T)c5_i21;
      }

      for (c5_i23 = 0; c5_i23 < 2; c5_i23++) {
        c5_connDimsT[c5_i23] = 1.0 + 8.0 * (real_T)c5_i23;
      }

      for (c5_i24 = 0; c5_i24 < 2; c5_i24++) {
        c5_startT[c5_i24] = 4.0 * (real_T)c5_i24;
      }

      imfilter_real64(&chartInstance->c5_d_aTmp[0], &chartInstance->c5_b_bTmp[0],
                      2.0, &c5_outSizeT[0], 2.0, &c5_padSizeT[0],
                      &c5_nonzero_h_data[0], c5_numKernElem, &c5_conn[0], 2.0,
                      &c5_connDimsT[0], &c5_startT[0], 2.0, true, false);
    }

    c5_c_st.site = &c5_q_emlrtRSI;
    for (c5_i25 = 0; c5_i25 < 9; c5_i25++) {
      c5_conn[c5_i25] = (c5_hcol[c5_i25] != 0.0);
    }

    c5_b_end = 9;
    c5_b_trueCount = 0;
    for (c5_j_i = 0; c5_j_i < c5_b_end; c5_j_i++) {
      if (c5_conn[c5_j_i]) {
        c5_b_trueCount++;
      }
    }

    c5_nonzero_h_size[0] = c5_b_trueCount;
    c5_b_partialTrueCount = 0;
    for (c5_k_i = 0; c5_k_i < c5_b_end; c5_k_i++) {
      if (c5_conn[c5_k_i]) {
        c5_nonzero_h_data[c5_b_partialTrueCount] = c5_hcol[c5_k_i];
        c5_b_partialTrueCount++;
      }
    }

    c5_b_densityFlag = false;
    if ((real_T)c5_nonzero_h_size[0] / 9.0 > 0.05) {
      c5_b_densityFlag = true;
    }

    c5_c_tooBig = true;
    for (c5_l_i = 0; c5_l_i < 2; c5_l_i++) {
      c5_c_tooBig = false;
    }

    if (c5_b_densityFlag && (!c5_c_tooBig)) {
      c5_g_modeFlag = true;
    } else {
      c5_g_modeFlag = false;
    }

    if (c5_g_modeFlag) {
      c5_h_modeFlag = true;
    } else {
      c5_h_modeFlag = false;
    }

    c5_i_modeFlag = c5_h_modeFlag;
    if (c5_i_modeFlag) {
      for (c5_i26 = 0; c5_i26 < 2; c5_i26++) {
        c5_padSizeT[c5_i26] = 128.0 + 32.0 * (real_T)c5_i26;
      }

      for (c5_i28 = 0; c5_i28 < 2; c5_i28++) {
        c5_outSizeT[c5_i28] = 120.0 + 40.0 * (real_T)c5_i28;
      }

      for (c5_i30 = 0; c5_i30 < 2; c5_i30++) {
        c5_connDimsT[c5_i30] = 9.0 + -8.0 * (real_T)c5_i30;
      }

      ippfilter_real64(&chartInstance->c5_b_bTmp[0], &c5_B[0], &c5_outSizeT[0],
                       2.0, &c5_padSizeT[0], &c5_hcol[0], &c5_connDimsT[0],
                       false);
    } else {
      c5_b_numKernElem = (real_T)c5_nonzero_h_size[0];
      for (c5_i27 = 0; c5_i27 < 2; c5_i27++) {
        c5_padSizeT[c5_i27] = 128.0 + 32.0 * (real_T)c5_i27;
      }

      for (c5_i29 = 0; c5_i29 < 2; c5_i29++) {
        c5_outSizeT[c5_i29] = 120.0 + 40.0 * (real_T)c5_i29;
      }

      for (c5_i31 = 0; c5_i31 < 2; c5_i31++) {
        c5_connDimsT[c5_i31] = 9.0 + -8.0 * (real_T)c5_i31;
      }

      for (c5_i32 = 0; c5_i32 < 2; c5_i32++) {
        c5_startT[c5_i32] = 4.0 + -4.0 * (real_T)c5_i32;
      }

      imfilter_real64(&chartInstance->c5_b_bTmp[0], &c5_B[0], 2.0, &c5_outSizeT
                      [0], 2.0, &c5_padSizeT[0], &c5_nonzero_h_data[0],
                      c5_b_numKernElem, &c5_conn[0], 2.0, &c5_connDimsT[0],
                      &c5_startT[0], 2.0, true, false);
    }
  } else {
    c5_c_st.site = &c5_r_emlrtRSI;
    c5_d_st.site = &c5_jc_emlrtRSI;
    for (c5_j = 0; c5_j < 168; c5_j++) {
      c5_c_j = (real_T)c5_j + 1.0;
      for (c5_b_i = 0; c5_b_i < 128; c5_b_i++) {
        c5_e_i = (real_T)c5_b_i + 1.0;
        if ((c5_idxA[(int32_T)c5_e_i - 1] < 1) || (c5_idxA[(int32_T)c5_e_i - 1] >
             120)) {
          emlrtDynamicBoundsCheckR2012b(c5_idxA[(int32_T)c5_e_i - 1], 1, 120,
            &c5_f_emlrtBCI, &c5_d_st);
        }

        c5_i3 = c5_idxA[(int32_T)c5_c_j + 167];
        if ((c5_i3 < 1) || (c5_i3 > 160)) {
          emlrtDynamicBoundsCheckR2012b(c5_i3, 1, 160, &c5_g_emlrtBCI, &c5_d_st);
        }

        chartInstance->c5_d_aTmp[((int32_T)c5_e_i + (((int32_T)c5_c_j - 1) << 7))
          - 1] = c5_b_A[(c5_idxA[(int32_T)c5_e_i - 1] + 120 * (c5_i3 - 1)) - 1];
      }
    }

    c5_c_st.site = &c5_s_emlrtRSI;
    c5_tooBig = true;
    for (c5_d_i = 0; c5_d_i < 2; c5_d_i++) {
      c5_tooBig = false;
    }

    if (!c5_tooBig) {
      c5_modeFlag = true;
    } else {
      c5_modeFlag = false;
    }

    if (c5_modeFlag) {
      c5_b_modeFlag = true;
    } else {
      c5_b_modeFlag = false;
    }

    c5_c_modeFlag = c5_b_modeFlag;
    if (c5_c_modeFlag) {
      for (c5_i6 = 0; c5_i6 < 2; c5_i6++) {
        c5_padSizeT[c5_i6] = 128.0 + 40.0 * (real_T)c5_i6;
      }

      for (c5_i8 = 0; c5_i8 < 2; c5_i8++) {
        c5_outSizeT[c5_i8] = 120.0 + 40.0 * (real_T)c5_i8;
      }

      for (c5_i10 = 0; c5_i10 < 2; c5_i10++) {
        c5_connDimsT[c5_i10] = 9.0;
      }

      ippfilter_real64(&chartInstance->c5_d_aTmp[0], &c5_B[0], &c5_outSizeT[0],
                       2.0, &c5_padSizeT[0], &c5_dv[0], &c5_connDimsT[0], false);
    } else {
      for (c5_i5 = 0; c5_i5 < 81; c5_i5++) {
        c5_b_conn[c5_i5] = true;
      }

      for (c5_i7 = 0; c5_i7 < 2; c5_i7++) {
        c5_padSizeT[c5_i7] = 128.0 + 40.0 * (real_T)c5_i7;
      }

      for (c5_i9 = 0; c5_i9 < 2; c5_i9++) {
        c5_outSizeT[c5_i9] = 120.0 + 40.0 * (real_T)c5_i9;
      }

      for (c5_i11 = 0; c5_i11 < 2; c5_i11++) {
        c5_connDimsT[c5_i11] = 9.0;
      }

      for (c5_i13 = 0; c5_i13 < 2; c5_i13++) {
        c5_startT[c5_i13] = 4.0;
      }

      imfilter_real64(&chartInstance->c5_d_aTmp[0], &c5_B[0], 2.0, &c5_outSizeT
                      [0], 2.0, &c5_padSizeT[0], &c5_dv[0], 81.0, &c5_b_conn[0],
                      2.0, &c5_connDimsT[0], &c5_startT[0], 2.0, true, false);
    }
  }
}

static void c5_svd(SFc5_flightControlSystemInstanceStruct *chartInstance, const
                   emlrtStack *c5_sp, real_T c5_U[81], real_T c5_S[81], real_T
                   c5_V[81])
{
  static char_T c5_b_cv[33] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'L', 'A', 'P', 'A', 'C', 'K', 'C', 'a', 'l', 'l', 'E',
    'r', 'r', 'o', 'r', 'I', 'n', 'f', 'o' };

  static char_T c5_b_cv4[33] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'L', 'A', 'P', 'A', 'C', 'K', 'C', 'a', 'l', 'l',
    'E', 'r', 'r', 'o', 'r', 'I', 'n', 'f', 'o' };

  static char_T c5_b_cv3[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 's', 'v', 'd', '_', 'N', 'o', 'C', 'o', 'n', 'v', 'e',
    'r', 'g', 'e', 'n', 'c', 'e' };

  static char_T c5_b_cv2[14] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_', 'd',
    'g', 'e', 's', 'd', 'd' };

  static char_T c5_b_cv6[14] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_', 'd',
    'g', 'e', 's', 'v', 'd' };

  static char_T c5_b_cv1[12] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o',
    'm', 'e', 'm' };

  static char_T c5_b_cv5[12] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o',
    'm', 'e', 'm' };

  ptrdiff_t c5_b_info_t;
  ptrdiff_t c5_b_lda_t;
  ptrdiff_t c5_b_ldu_t;
  ptrdiff_t c5_b_ldv_t;
  ptrdiff_t c5_b_m_t;
  ptrdiff_t c5_b_n_t;
  ptrdiff_t c5_info_t;
  ptrdiff_t c5_lda_t;
  ptrdiff_t c5_ldu_t;
  ptrdiff_t c5_ldv_t;
  ptrdiff_t c5_m_t;
  ptrdiff_t c5_n_t;
  emlrtStack c5_b_st;
  emlrtStack c5_c_st;
  emlrtStack c5_d_st;
  emlrtStack c5_e_st;
  emlrtStack c5_st;
  const mxArray *c5_b_y = NULL;
  const mxArray *c5_c_y = NULL;
  const mxArray *c5_d_y = NULL;
  const mxArray *c5_e_y = NULL;
  const mxArray *c5_f_y = NULL;
  const mxArray *c5_g_y = NULL;
  const mxArray *c5_h_y = NULL;
  const mxArray *c5_i_y = NULL;
  const mxArray *c5_j_y = NULL;
  const mxArray *c5_k_y = NULL;
  const mxArray *c5_l_y = NULL;
  const mxArray *c5_m_y = NULL;
  const mxArray *c5_n_y = NULL;
  const mxArray *c5_y = NULL;
  real_T c5_Vt[81];
  real_T c5_b_A[81];
  real_T c5_b_S[9];
  real_T c5_superb[8];
  int32_T c5_b_info;
  int32_T c5_b_k;
  int32_T c5_c_info;
  int32_T c5_d_info;
  int32_T c5_e_info;
  int32_T c5_f_info;
  int32_T c5_g_info;
  int32_T c5_h_info;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i10;
  int32_T c5_i2;
  int32_T c5_i3;
  int32_T c5_i4;
  int32_T c5_i5;
  int32_T c5_i6;
  int32_T c5_i7;
  int32_T c5_i8;
  int32_T c5_i9;
  int32_T c5_info;
  int32_T c5_k;
  boolean_T c5_b_p;
  boolean_T c5_p;
  (void)chartInstance;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_c_st.prev = &c5_b_st;
  c5_c_st.tls = c5_b_st.tls;
  c5_d_st.prev = &c5_c_st;
  c5_d_st.tls = c5_c_st.tls;
  c5_e_st.prev = &c5_d_st;
  c5_e_st.tls = c5_d_st.tls;
  c5_st.site = &c5_u_emlrtRSI;
  c5_b_st.site = &c5_w_emlrtRSI;
  c5_c_st.site = &c5_y_emlrtRSI;
  for (c5_i = 0; c5_i < 81; c5_i++) {
    c5_b_A[c5_i] = c5_dv[c5_i];
  }

  c5_m_t = (ptrdiff_t)9;
  c5_n_t = (ptrdiff_t)9;
  c5_lda_t = (ptrdiff_t)9;
  c5_ldu_t = (ptrdiff_t)9;
  c5_ldv_t = (ptrdiff_t)9;
  c5_info_t = LAPACKE_dgesdd(102, 'A', c5_m_t, c5_n_t, &c5_b_A[0], c5_lda_t,
    &c5_b_S[0], &c5_U[0], c5_ldu_t, &c5_Vt[0], c5_ldv_t);
  c5_info = (int32_T)c5_info_t;
  c5_d_st.site = &c5_ab_emlrtRSI;
  c5_b_info = c5_info;
  c5_c_info = c5_b_info;
  c5_p = (c5_c_info < 0);
  if (c5_p) {
    if (c5_b_info == -1010) {
      c5_b_y = NULL;
      sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_b_cv1, 10, 0U, 1, 0U, 2, 1,
        12), false);
      c5_d_y = NULL;
      sf_mex_assign(&c5_d_y, sf_mex_create("y", c5_b_cv1, 10, 0U, 1, 0U, 2, 1,
        12), false);
      sf_mex_call(&c5_d_st, &c5_c_emlrtMCI, "error", 0U, 2U, 14, c5_b_y, 14,
                  sf_mex_call(&c5_d_st, NULL, "getString", 1U, 1U, 14,
        sf_mex_call(&c5_d_st, NULL, "message", 1U, 1U, 14, c5_d_y)));
    } else {
      c5_y = NULL;
      sf_mex_assign(&c5_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1, 33),
                    false);
      c5_c_y = NULL;
      sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1, 33),
                    false);
      c5_e_y = NULL;
      sf_mex_assign(&c5_e_y, sf_mex_create("y", c5_b_cv2, 10, 0U, 1, 0U, 2, 1,
        14), false);
      c5_f_y = NULL;
      sf_mex_assign(&c5_f_y, sf_mex_create("y", &c5_b_info, 6, 0U, 0, 0U, 0),
                    false);
      sf_mex_call(&c5_d_st, &c5_d_emlrtMCI, "error", 0U, 2U, 14, c5_y, 14,
                  sf_mex_call(&c5_d_st, NULL, "getString", 1U, 1U, 14,
        sf_mex_call(&c5_d_st, NULL, "message", 1U, 3U, 14, c5_c_y, 14, c5_e_y,
                    14, c5_f_y)));
    }
  }

  c5_d_info = c5_info;
  if (c5_info > 0) {
    c5_c_st.site = &c5_x_emlrtRSI;
    c5_d_st.site = &c5_cb_emlrtRSI;
    for (c5_i3 = 0; c5_i3 < 81; c5_i3++) {
      c5_b_A[c5_i3] = c5_dv[c5_i3];
    }

    c5_b_m_t = (ptrdiff_t)9;
    c5_b_n_t = (ptrdiff_t)9;
    c5_b_lda_t = (ptrdiff_t)9;
    c5_b_ldu_t = (ptrdiff_t)9;
    c5_b_ldv_t = (ptrdiff_t)9;
    c5_b_info_t = LAPACKE_dgesvd(102, 'A', 'A', c5_b_m_t, c5_b_n_t, &c5_b_A[0],
      c5_b_lda_t, &c5_b_S[0], &c5_U[0], c5_b_ldu_t, &c5_Vt[0], c5_b_ldv_t,
      &c5_superb[0]);
    c5_e_info = (int32_T)c5_b_info_t;
    c5_i7 = 0;
    for (c5_i8 = 0; c5_i8 < 9; c5_i8++) {
      c5_i9 = 0;
      for (c5_i10 = 0; c5_i10 < 9; c5_i10++) {
        c5_V[c5_i10 + c5_i7] = c5_Vt[c5_i9 + c5_i8];
        c5_i9 += 9;
      }

      c5_i7 += 9;
    }

    c5_e_st.site = &c5_bb_emlrtRSI;
    c5_f_info = c5_e_info;
    c5_g_info = c5_f_info;
    c5_b_p = (c5_g_info < 0);
    if (c5_b_p) {
      if (c5_f_info == -1010) {
        c5_j_y = NULL;
        sf_mex_assign(&c5_j_y, sf_mex_create("y", c5_b_cv5, 10, 0U, 1, 0U, 2, 1,
          12), false);
        c5_l_y = NULL;
        sf_mex_assign(&c5_l_y, sf_mex_create("y", c5_b_cv5, 10, 0U, 1, 0U, 2, 1,
          12), false);
        sf_mex_call(&c5_e_st, &c5_c_emlrtMCI, "error", 0U, 2U, 14, c5_j_y, 14,
                    sf_mex_call(&c5_e_st, NULL, "getString", 1U, 1U, 14,
          sf_mex_call(&c5_e_st, NULL, "message", 1U, 1U, 14, c5_l_y)));
      } else {
        c5_i_y = NULL;
        sf_mex_assign(&c5_i_y, sf_mex_create("y", c5_b_cv4, 10, 0U, 1, 0U, 2, 1,
          33), false);
        c5_k_y = NULL;
        sf_mex_assign(&c5_k_y, sf_mex_create("y", c5_b_cv4, 10, 0U, 1, 0U, 2, 1,
          33), false);
        c5_m_y = NULL;
        sf_mex_assign(&c5_m_y, sf_mex_create("y", c5_b_cv6, 10, 0U, 1, 0U, 2, 1,
          14), false);
        c5_n_y = NULL;
        sf_mex_assign(&c5_n_y, sf_mex_create("y", &c5_f_info, 6, 0U, 0, 0U, 0),
                      false);
        sf_mex_call(&c5_e_st, &c5_d_emlrtMCI, "error", 0U, 2U, 14, c5_i_y, 14,
                    sf_mex_call(&c5_e_st, NULL, "getString", 1U, 1U, 14,
          sf_mex_call(&c5_e_st, NULL, "message", 1U, 3U, 14, c5_k_y, 14, c5_m_y,
                      14, c5_n_y)));
      }
    }

    c5_h_info = c5_e_info;
    c5_d_info = c5_h_info;
  } else {
    c5_i1 = 0;
    for (c5_i2 = 0; c5_i2 < 9; c5_i2++) {
      c5_i4 = 0;
      for (c5_i5 = 0; c5_i5 < 9; c5_i5++) {
        c5_V[c5_i5 + c5_i1] = c5_Vt[c5_i4 + c5_i2];
        c5_i4 += 9;
      }

      c5_i1 += 9;
    }
  }

  if (c5_d_info > 0) {
    c5_g_y = NULL;
    sf_mex_assign(&c5_g_y, sf_mex_create("y", c5_b_cv3, 10, 0U, 1, 0U, 2, 1, 30),
                  false);
    c5_h_y = NULL;
    sf_mex_assign(&c5_h_y, sf_mex_create("y", c5_b_cv3, 10, 0U, 1, 0U, 2, 1, 30),
                  false);
    sf_mex_call(&c5_b_st, &c5_b_emlrtMCI, "error", 0U, 2U, 14, c5_g_y, 14,
                sf_mex_call(&c5_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c5_b_st, NULL, "message", 1U, 1U, 14, c5_h_y)));
  }

  for (c5_i6 = 0; c5_i6 < 81; c5_i6++) {
    c5_S[c5_i6] = 0.0;
  }

  c5_k = 0;
  for (c5_b_k = 0; c5_b_k < 9; c5_b_k++) {
    c5_S[c5_k] = c5_b_S[c5_b_k];
    c5_k += 10;
  }
}

static void c5_check_forloop_overflow_error
  (SFc5_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c5_sp)
{
  static char_T c5_b_cv[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  static char_T c5_b_cv1[5] = { 'i', 'n', 't', '3', '2' };

  const mxArray *c5_b_y = NULL;
  const mxArray *c5_c_y = NULL;
  const mxArray *c5_y = NULL;
  (void)chartInstance;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1, 34),
                false);
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1, 34),
                false);
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_b_cv1, 10, 0U, 1, 0U, 2, 1, 5),
                false);
  sf_mex_call(c5_sp, &c5_emlrtMCI, "error", 0U, 2U, 14, c5_y, 14, sf_mex_call
              (c5_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call(c5_sp, NULL,
    "message", 1U, 2U, 14, c5_b_y, 14, c5_c_y)));
}

static real_T c5_otsuthresh(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, real_T c5_counts[256])
{
  static char_T c5_b_cv[32] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'o', 't', 's',
    'u', 't', 'h', 'r', 'e', 's', 'h', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e',
    'd', 'F', 'i', 'n', 'i', 't', 'e' };

  static char_T c5_b_cv1[6] = { 'C', 'O', 'U', 'N', 'T', 'S' };

  emlrtStack c5_b_st;
  emlrtStack c5_st;
  const mxArray *c5_b_y = NULL;
  const mxArray *c5_c_y = NULL;
  const mxArray *c5_y = NULL;
  real_T c5_mu[256];
  real_T c5_omega[256];
  real_T c5_b_k;
  real_T c5_b_p;
  real_T c5_b_x;
  real_T c5_c;
  real_T c5_c_a;
  real_T c5_c_x;
  real_T c5_d_a;
  real_T c5_d_k;
  real_T c5_d_x;
  real_T c5_e_a;
  real_T c5_e_x;
  real_T c5_f_a;
  real_T c5_f_x;
  real_T c5_g_a;
  real_T c5_g_x;
  real_T c5_idx;
  real_T c5_maxval;
  real_T c5_mu_t;
  real_T c5_num_elems;
  real_T c5_num_maxval;
  real_T c5_sigma_b_squared;
  real_T c5_t;
  int32_T c5_c_k;
  int32_T c5_e_k;
  int32_T c5_f_k;
  int32_T c5_k;
  boolean_T c5_b;
  boolean_T c5_b1;
  boolean_T c5_b2;
  boolean_T c5_b3;
  boolean_T c5_b4;
  boolean_T c5_b_b;
  boolean_T c5_c_b;
  boolean_T c5_d_b;
  boolean_T c5_e_b;
  boolean_T c5_exitg1;
  boolean_T c5_f_b;
  boolean_T c5_isfinite_maxval;
  boolean_T c5_p;
  (void)chartInstance;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_st.site = &c5_xc_emlrtRSI;
  c5_b_st.site = &c5_ad_emlrtRSI;
  c5_p = true;
  c5_k = 0;
  c5_exitg1 = false;
  while ((!c5_exitg1) && (c5_k < 256)) {
    c5_b_k = (real_T)c5_k + 1.0;
    c5_b_x = c5_counts[(int32_T)c5_b_k - 1];
    c5_c_x = c5_b_x;
    c5_b_b = muDoubleScalarIsInf(c5_c_x);
    c5_b1 = !c5_b_b;
    c5_d_x = c5_b_x;
    c5_c_b = muDoubleScalarIsNaN(c5_d_x);
    c5_b2 = !c5_c_b;
    c5_d_b = (c5_b1 && c5_b2);
    if (c5_d_b) {
      c5_k++;
    } else {
      c5_p = false;
      c5_exitg1 = true;
    }
  }

  if (c5_p) {
    c5_b = true;
  } else {
    c5_b = false;
  }

  if (!c5_b) {
    c5_y = NULL;
    sf_mex_assign(&c5_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1, 32),
                  false);
    c5_b_y = NULL;
    sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_cv2, 10, 0U, 1, 0U, 2, 1, 46),
                  false);
    c5_c_y = NULL;
    sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_b_cv1, 10, 0U, 1, 0U, 2, 1, 6),
                  false);
    sf_mex_call(&c5_b_st, &c5_g_emlrtMCI, "error", 0U, 2U, 14, c5_y, 14,
                sf_mex_call(&c5_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c5_b_st, NULL, "message", 1U, 2U, 14, c5_b_y, 14, c5_c_y)));
  }

  c5_b_st.site = &c5_ad_emlrtRSI;
  c5_num_elems = 0.0;
  for (c5_c_k = 0; c5_c_k < 256; c5_c_k++) {
    c5_d_k = (real_T)c5_c_k + 1.0;
    c5_num_elems += c5_counts[(int32_T)c5_d_k - 1];
  }

  c5_omega[0] = c5_counts[0] / c5_num_elems;
  c5_mu[0] = c5_omega[0];
  for (c5_e_k = 0; c5_e_k < 255; c5_e_k++) {
    c5_d_k = (real_T)c5_e_k + 2.0;
    c5_b_p = c5_counts[(int32_T)c5_d_k - 1] / c5_num_elems;
    c5_omega[(int32_T)c5_d_k - 1] = c5_omega[(int32_T)(c5_d_k - 1.0) - 1] +
      c5_b_p;
    c5_mu[(int32_T)c5_d_k - 1] = c5_mu[(int32_T)(c5_d_k - 1.0) - 1] + c5_b_p *
      c5_d_k;
  }

  c5_mu_t = c5_mu[255];
  c5_maxval = rtMinusInf;
  c5_idx = 0.0;
  c5_num_maxval = 0.0;
  for (c5_f_k = 0; c5_f_k < 255; c5_f_k++) {
    c5_d_k = (real_T)c5_f_k + 1.0;
    c5_st.site = &c5_yc_emlrtRSI;
    c5_c_a = c5_mu_t * c5_omega[(int32_T)c5_d_k - 1] - c5_mu[(int32_T)c5_d_k - 1];
    c5_b_st.site = &c5_bd_emlrtRSI;
    c5_d_a = c5_c_a;
    c5_e_a = c5_d_a;
    c5_f_a = c5_e_a;
    c5_g_a = c5_f_a;
    c5_c = c5_g_a * c5_g_a;
    c5_sigma_b_squared = c5_c / (c5_omega[(int32_T)c5_d_k - 1] * (1.0 -
      c5_omega[(int32_T)c5_d_k - 1]));
    if (c5_sigma_b_squared > c5_maxval) {
      c5_maxval = c5_sigma_b_squared;
      c5_idx = c5_d_k;
      c5_num_maxval = 1.0;
    } else if (c5_sigma_b_squared == c5_maxval) {
      c5_idx += c5_d_k;
      c5_num_maxval++;
    }
  }

  c5_e_x = c5_maxval;
  c5_f_x = c5_e_x;
  c5_e_b = muDoubleScalarIsInf(c5_f_x);
  c5_b3 = !c5_e_b;
  c5_g_x = c5_e_x;
  c5_f_b = muDoubleScalarIsNaN(c5_g_x);
  c5_b4 = !c5_f_b;
  c5_isfinite_maxval = (c5_b3 && c5_b4);
  if (c5_isfinite_maxval) {
    c5_idx /= c5_num_maxval;
    c5_t = (c5_idx - 1.0) / 255.0;
  } else {
    c5_t = 0.0;
  }

  return c5_t;
}

static void c5_edge(SFc5_flightControlSystemInstanceStruct *chartInstance, const
                    emlrtStack *c5_sp, boolean_T c5_varargin_1[19200], boolean_T
                    c5_varargout_1[19200])
{
  static real_T c5_b_kernel[13] = { 3.4813359214923059E-5,
    0.00054457256285105158, 0.0051667606200595222, 0.029732654490475543,
    0.10377716120747747, 0.21969625200024598, 0.28209557151935094,
    0.21969625200024598, 0.10377716120747747, 0.029732654490475543,
    0.0051667606200595222, 0.00054457256285105158, 3.4813359214923059E-5 };

  static real_T c5_kernel[13] = { 3.4813359214923059E-5, 0.00054457256285105158,
    0.0051667606200595222, 0.029732654490475543, 0.10377716120747747,
    0.21969625200024598, 0.28209557151935094, 0.21969625200024598,
    0.10377716120747747, 0.029732654490475543, 0.0051667606200595222,
    0.00054457256285105158, 3.4813359214923059E-5 };

  static int32_T c5_idxA[344] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
    15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33,
    34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52,
    53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71,
    72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90,
    91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107,
    108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1,
    1, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
    21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39,
    40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58,
    59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77,
    78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96,
    97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112,
    113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127,
    128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142,
    143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157,
    158, 159, 160, 160, 160, 160, 160, 160, 160 };

  emlrtStack c5_b_st;
  emlrtStack c5_c_st;
  emlrtStack c5_d_st;
  emlrtStack c5_st;
  real_T c5_counts[64];
  real_T c5_connDimsT[2];
  real_T c5_outSizeT[2];
  real_T c5_padSizeT[2];
  real_T c5_startT[2];
  real_T c5_b_data[1];
  real_T c5_highThresh_data[1];
  real_T c5_lowThresh_data[1];
  real_T c5_b_idx;
  real_T c5_b_j;
  real_T c5_b_lowThresh;
  real_T c5_b_out;
  real_T c5_b_sum;
  real_T c5_d_i;
  real_T c5_d_j;
  real_T c5_f_j;
  real_T c5_g_i;
  real_T c5_highThresh;
  real_T c5_highThreshTemp;
  real_T c5_j_i;
  real_T c5_l_i;
  real_T c5_lowThresh;
  int32_T c5_highThresh_size[1];
  int32_T c5_lowThresh_size[1];
  int32_T c5_b_c;
  int32_T c5_b_i;
  int32_T c5_c;
  int32_T c5_c_i;
  int32_T c5_c_j;
  int32_T c5_e_i;
  int32_T c5_e_j;
  int32_T c5_f_i;
  int32_T c5_h_i;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i10;
  int32_T c5_i11;
  int32_T c5_i12;
  int32_T c5_i13;
  int32_T c5_i14;
  int32_T c5_i15;
  int32_T c5_i16;
  int32_T c5_i17;
  int32_T c5_i18;
  int32_T c5_i19;
  int32_T c5_i2;
  int32_T c5_i20;
  int32_T c5_i21;
  int32_T c5_i22;
  int32_T c5_i23;
  int32_T c5_i24;
  int32_T c5_i25;
  int32_T c5_i26;
  int32_T c5_i27;
  int32_T c5_i28;
  int32_T c5_i29;
  int32_T c5_i3;
  int32_T c5_i30;
  int32_T c5_i31;
  int32_T c5_i32;
  int32_T c5_i33;
  int32_T c5_i34;
  int32_T c5_i35;
  int32_T c5_i36;
  int32_T c5_i37;
  int32_T c5_i38;
  int32_T c5_i39;
  int32_T c5_i4;
  int32_T c5_i40;
  int32_T c5_i5;
  int32_T c5_i6;
  int32_T c5_i7;
  int32_T c5_i8;
  int32_T c5_i9;
  int32_T c5_i_i;
  int32_T c5_idx;
  int32_T c5_j;
  int32_T c5_k_i;
  int32_T c5_loop_ub;
  real32_T c5_magGrad[19200];
  real32_T c5_b;
  real32_T c5_b_b;
  real32_T c5_b_r;
  real32_T c5_b_varargin_1;
  real32_T c5_b_varargin_2;
  real32_T c5_b_x;
  real32_T c5_b_x1;
  real32_T c5_b_x2;
  real32_T c5_b_y;
  real32_T c5_c_a;
  real32_T c5_c_b;
  real32_T c5_c_x;
  real32_T c5_c_y;
  real32_T c5_d_a;
  real32_T c5_d_b;
  real32_T c5_d_idx;
  real32_T c5_d_x;
  real32_T c5_d_y;
  real32_T c5_e_a;
  real32_T c5_e_x;
  real32_T c5_e_y;
  real32_T c5_f_a;
  real32_T c5_f_x;
  real32_T c5_f_y;
  real32_T c5_g_a;
  real32_T c5_g_b;
  real32_T c5_g_x;
  real32_T c5_g_y;
  real32_T c5_h_a;
  real32_T c5_h_x;
  real32_T c5_h_y;
  real32_T c5_i_a;
  real32_T c5_i_x;
  real32_T c5_i_y;
  real32_T c5_j_x;
  real32_T c5_j_y;
  real32_T c5_k_x;
  real32_T c5_k_y;
  real32_T c5_l_x;
  real32_T c5_magmax;
  real32_T c5_r;
  real32_T c5_x1;
  real32_T c5_x2;
  real32_T c5_y;
  int8_T c5_c_idx;
  boolean_T c5_E[19200];
  boolean_T c5_conn[13];
  boolean_T c5_b_modeFlag;
  boolean_T c5_b_tooBig;
  boolean_T c5_c_modeFlag;
  boolean_T c5_c_tooBig;
  boolean_T c5_d_modeFlag;
  boolean_T c5_e_b;
  boolean_T c5_e_modeFlag;
  boolean_T c5_f_b;
  boolean_T c5_f_modeFlag;
  boolean_T c5_g_modeFlag;
  boolean_T c5_h_modeFlag;
  boolean_T c5_i_modeFlag;
  boolean_T c5_modeFlag;
  boolean_T c5_nanFlag;
  boolean_T c5_tooBig;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_c_st.prev = &c5_b_st;
  c5_c_st.tls = c5_b_st.tls;
  c5_d_st.prev = &c5_c_st;
  c5_d_st.tls = c5_c_st.tls;
  for (c5_i = 0; c5_i < 19200; c5_i++) {
    chartInstance->c5_a[c5_i] = (real32_T)c5_varargin_1[c5_i];
  }

  c5_st.site = &c5_dd_emlrtRSI;
  c5_b_st.site = &c5_gd_emlrtRSI;
  c5_c_st.site = &c5_r_emlrtRSI;
  c5_d_st.site = &c5_jc_emlrtRSI;
  for (c5_j = 0; c5_j < 160; c5_j++) {
    c5_b_j = (real_T)c5_j + 1.0;
    for (c5_b_i = 0; c5_b_i < 132; c5_b_i++) {
      c5_d_i = (real_T)c5_b_i + 1.0;
      if ((c5_iv[(int32_T)c5_d_i - 1] < 1) || (c5_iv[(int32_T)c5_d_i - 1] > 120))
      {
        emlrtDynamicBoundsCheckR2012b(c5_iv[(int32_T)c5_d_i - 1], 1, 120,
          &c5_f_emlrtBCI, &c5_d_st);
      }

      c5_i1 = c5_iv[(int32_T)c5_b_j + 159];
      if ((c5_i1 < 1) || (c5_i1 > 160)) {
        emlrtDynamicBoundsCheckR2012b(c5_i1, 1, 160, &c5_g_emlrtBCI, &c5_d_st);
      }

      chartInstance->c5_aTmp[((int32_T)c5_d_i + 132 * ((int32_T)c5_b_j - 1)) - 1]
        = chartInstance->c5_a[(c5_iv[(int32_T)c5_d_i - 1] + 120 * (c5_i1 - 1)) -
        1];
    }
  }

  c5_c_st.site = &c5_s_emlrtRSI;
  c5_d_st.site = &c5_kc_emlrtRSI;
  c5_tooBig = true;
  for (c5_c_i = 0; c5_c_i < 2; c5_c_i++) {
    c5_tooBig = false;
  }

  if (!c5_tooBig) {
    c5_modeFlag = true;
  } else {
    c5_modeFlag = false;
  }

  if (c5_modeFlag) {
    c5_b_modeFlag = true;
  } else {
    c5_b_modeFlag = false;
  }

  c5_c_modeFlag = c5_b_modeFlag;
  if (c5_c_modeFlag) {
    for (c5_i3 = 0; c5_i3 < 2; c5_i3++) {
      c5_padSizeT[c5_i3] = 132.0 + 28.0 * (real_T)c5_i3;
    }

    for (c5_i5 = 0; c5_i5 < 2; c5_i5++) {
      c5_outSizeT[c5_i5] = 120.0 + 40.0 * (real_T)c5_i5;
    }

    for (c5_i7 = 0; c5_i7 < 2; c5_i7++) {
      c5_connDimsT[c5_i7] = 13.0 + -12.0 * (real_T)c5_i7;
    }

    ippfilter_real32(&chartInstance->c5_aTmp[0], &chartInstance->c5_bTmp[0],
                     &c5_outSizeT[0], 2.0, &c5_padSizeT[0], &c5_kernel[0],
                     &c5_connDimsT[0], true);
  } else {
    for (c5_i2 = 0; c5_i2 < 13; c5_i2++) {
      c5_conn[c5_i2] = true;
    }

    for (c5_i4 = 0; c5_i4 < 2; c5_i4++) {
      c5_padSizeT[c5_i4] = 132.0 + 28.0 * (real_T)c5_i4;
    }

    for (c5_i6 = 0; c5_i6 < 2; c5_i6++) {
      c5_outSizeT[c5_i6] = 120.0 + 40.0 * (real_T)c5_i6;
    }

    for (c5_i8 = 0; c5_i8 < 2; c5_i8++) {
      c5_connDimsT[c5_i8] = 13.0 + -12.0 * (real_T)c5_i8;
    }

    for (c5_i9 = 0; c5_i9 < 2; c5_i9++) {
      c5_startT[c5_i9] = 6.0 + -6.0 * (real_T)c5_i9;
    }

    imfilter_real32(&chartInstance->c5_aTmp[0], &chartInstance->c5_bTmp[0], 2.0,
                    &c5_outSizeT[0], 2.0, &c5_padSizeT[0], &c5_kernel[0], 13.0,
                    &c5_conn[0], 2.0, &c5_connDimsT[0], &c5_startT[0], 2.0, true,
                    true);
  }

  c5_b_st.site = &c5_hd_emlrtRSI;
  c5_c_st.site = &c5_r_emlrtRSI;
  c5_d_st.site = &c5_jc_emlrtRSI;
  for (c5_c_j = 0; c5_c_j < 172; c5_c_j++) {
    c5_d_j = (real_T)c5_c_j + 1.0;
    for (c5_e_i = 0; c5_e_i < 120; c5_e_i++) {
      c5_g_i = (real_T)c5_e_i + 1.0;
      if ((c5_idxA[(int32_T)c5_g_i - 1] < 1) || (c5_idxA[(int32_T)c5_g_i - 1] >
           120)) {
        emlrtDynamicBoundsCheckR2012b(c5_idxA[(int32_T)c5_g_i - 1], 1, 120,
          &c5_f_emlrtBCI, &c5_d_st);
      }

      c5_i10 = c5_idxA[(int32_T)c5_d_j + 171];
      if ((c5_i10 < 1) || (c5_i10 > 160)) {
        emlrtDynamicBoundsCheckR2012b(c5_i10, 1, 160, &c5_g_emlrtBCI, &c5_d_st);
      }

      chartInstance->c5_b_aTmp[((int32_T)c5_g_i + 120 * ((int32_T)c5_d_j - 1)) -
        1] = chartInstance->c5_bTmp[(c5_idxA[(int32_T)c5_g_i - 1] + 120 *
        (c5_i10 - 1)) - 1];
    }
  }

  c5_c_st.site = &c5_s_emlrtRSI;
  c5_d_st.site = &c5_kc_emlrtRSI;
  c5_b_tooBig = true;
  for (c5_f_i = 0; c5_f_i < 2; c5_f_i++) {
    c5_b_tooBig = false;
  }

  if (!c5_b_tooBig) {
    c5_d_modeFlag = true;
  } else {
    c5_d_modeFlag = false;
  }

  if (c5_d_modeFlag) {
    c5_e_modeFlag = true;
  } else {
    c5_e_modeFlag = false;
  }

  c5_f_modeFlag = c5_e_modeFlag;
  if (c5_f_modeFlag) {
    for (c5_i12 = 0; c5_i12 < 2; c5_i12++) {
      c5_padSizeT[c5_i12] = 120.0 + 52.0 * (real_T)c5_i12;
    }

    for (c5_i14 = 0; c5_i14 < 2; c5_i14++) {
      c5_outSizeT[c5_i14] = 120.0 + 40.0 * (real_T)c5_i14;
    }

    for (c5_i16 = 0; c5_i16 < 2; c5_i16++) {
      c5_connDimsT[c5_i16] = 1.0 + 12.0 * (real_T)c5_i16;
    }

    ippfilter_real32(&chartInstance->c5_b_aTmp[0], &chartInstance->c5_bTmp[0],
                     &c5_outSizeT[0], 2.0, &c5_padSizeT[0], &c5_dv1[0],
                     &c5_connDimsT[0], true);
  } else {
    for (c5_i11 = 0; c5_i11 < 2; c5_i11++) {
      c5_padSizeT[c5_i11] = 120.0 + 52.0 * (real_T)c5_i11;
    }

    for (c5_i13 = 0; c5_i13 < 2; c5_i13++) {
      c5_outSizeT[c5_i13] = 120.0 + 40.0 * (real_T)c5_i13;
    }

    for (c5_i15 = 0; c5_i15 < 2; c5_i15++) {
      c5_connDimsT[c5_i15] = 1.0 + 12.0 * (real_T)c5_i15;
    }

    for (c5_i17 = 0; c5_i17 < 2; c5_i17++) {
      c5_startT[c5_i17] = 6.0 * (real_T)c5_i17;
    }

    imfilter_real32(&chartInstance->c5_b_aTmp[0], &chartInstance->c5_bTmp[0],
                    2.0, &c5_outSizeT[0], 2.0, &c5_padSizeT[0], &c5_dv2[0], 12.0,
                    &c5_bv[0], 2.0, &c5_connDimsT[0], &c5_startT[0], 2.0, true,
                    true);
  }

  c5_b_st.site = &c5_id_emlrtRSI;
  c5_c_st.site = &c5_r_emlrtRSI;
  c5_d_st.site = &c5_jc_emlrtRSI;
  for (c5_e_j = 0; c5_e_j < 172; c5_e_j++) {
    c5_f_j = (real_T)c5_e_j + 1.0;
    for (c5_h_i = 0; c5_h_i < 120; c5_h_i++) {
      c5_j_i = (real_T)c5_h_i + 1.0;
      if ((c5_idxA[(int32_T)c5_j_i - 1] < 1) || (c5_idxA[(int32_T)c5_j_i - 1] >
           120)) {
        emlrtDynamicBoundsCheckR2012b(c5_idxA[(int32_T)c5_j_i - 1], 1, 120,
          &c5_f_emlrtBCI, &c5_d_st);
      }

      c5_i18 = c5_idxA[(int32_T)c5_f_j + 171];
      if ((c5_i18 < 1) || (c5_i18 > 160)) {
        emlrtDynamicBoundsCheckR2012b(c5_i18, 1, 160, &c5_g_emlrtBCI, &c5_d_st);
      }

      chartInstance->c5_b_aTmp[((int32_T)c5_j_i + 120 * ((int32_T)c5_f_j - 1)) -
        1] = chartInstance->c5_a[(c5_idxA[(int32_T)c5_j_i - 1] + 120 * (c5_i18 -
        1)) - 1];
    }
  }

  c5_c_st.site = &c5_s_emlrtRSI;
  c5_d_st.site = &c5_kc_emlrtRSI;
  c5_c_tooBig = true;
  for (c5_i_i = 0; c5_i_i < 2; c5_i_i++) {
    c5_c_tooBig = false;
  }

  if (!c5_c_tooBig) {
    c5_g_modeFlag = true;
  } else {
    c5_g_modeFlag = false;
  }

  if (c5_g_modeFlag) {
    c5_h_modeFlag = true;
  } else {
    c5_h_modeFlag = false;
  }

  c5_i_modeFlag = c5_h_modeFlag;
  if (c5_i_modeFlag) {
    for (c5_i20 = 0; c5_i20 < 2; c5_i20++) {
      c5_padSizeT[c5_i20] = 120.0 + 52.0 * (real_T)c5_i20;
    }

    for (c5_i22 = 0; c5_i22 < 2; c5_i22++) {
      c5_outSizeT[c5_i22] = 120.0 + 40.0 * (real_T)c5_i22;
    }

    for (c5_i24 = 0; c5_i24 < 2; c5_i24++) {
      c5_connDimsT[c5_i24] = 1.0 + 12.0 * (real_T)c5_i24;
    }

    ippfilter_real32(&chartInstance->c5_b_aTmp[0], &chartInstance->c5_a[0],
                     &c5_outSizeT[0], 2.0, &c5_padSizeT[0], &c5_b_kernel[0],
                     &c5_connDimsT[0], true);
  } else {
    for (c5_i19 = 0; c5_i19 < 13; c5_i19++) {
      c5_conn[c5_i19] = true;
    }

    for (c5_i21 = 0; c5_i21 < 2; c5_i21++) {
      c5_padSizeT[c5_i21] = 120.0 + 52.0 * (real_T)c5_i21;
    }

    for (c5_i23 = 0; c5_i23 < 2; c5_i23++) {
      c5_outSizeT[c5_i23] = 120.0 + 40.0 * (real_T)c5_i23;
    }

    for (c5_i25 = 0; c5_i25 < 2; c5_i25++) {
      c5_connDimsT[c5_i25] = 1.0 + 12.0 * (real_T)c5_i25;
    }

    for (c5_i26 = 0; c5_i26 < 2; c5_i26++) {
      c5_startT[c5_i26] = 6.0 * (real_T)c5_i26;
    }

    imfilter_real32(&chartInstance->c5_b_aTmp[0], &chartInstance->c5_a[0], 2.0,
                    &c5_outSizeT[0], 2.0, &c5_padSizeT[0], &c5_kernel[0], 13.0,
                    &c5_conn[0], 2.0, &c5_connDimsT[0], &c5_startT[0], 2.0, true,
                    true);
  }

  for (c5_i27 = 0; c5_i27 < 19200; c5_i27++) {
    chartInstance->c5_b_a[c5_i27] = chartInstance->c5_a[c5_i27];
  }

  c5_b_st.site = &c5_jd_emlrtRSI;
  c5_imfilter(chartInstance, &c5_b_st, chartInstance->c5_b_a,
              chartInstance->c5_a);
  c5_b_x = chartInstance->c5_bTmp[0];
  c5_y = chartInstance->c5_a[0];
  c5_c_a = c5_b_x;
  c5_b = c5_y;
  c5_c_x = c5_c_a;
  c5_b_y = c5_b;
  c5_x1 = c5_c_x;
  c5_x2 = c5_b_y;
  c5_d_a = c5_x1;
  c5_b_b = c5_x2;
  c5_r = muSingleScalarHypot(c5_d_a, c5_b_b);
  c5_magGrad[0] = c5_r;
  c5_magmax = c5_magGrad[0];
  for (c5_idx = 0; c5_idx < 19199; c5_idx++) {
    c5_b_idx = (real_T)c5_idx + 2.0;
    c5_d_x = chartInstance->c5_bTmp[(int32_T)c5_b_idx - 1];
    c5_e_y = chartInstance->c5_a[(int32_T)c5_b_idx - 1];
    c5_e_a = c5_d_x;
    c5_c_b = c5_e_y;
    c5_e_x = c5_e_a;
    c5_f_y = c5_c_b;
    c5_b_x1 = c5_e_x;
    c5_b_x2 = c5_f_y;
    c5_f_a = c5_b_x1;
    c5_d_b = c5_b_x2;
    c5_b_r = muSingleScalarHypot(c5_f_a, c5_d_b);
    c5_magGrad[(int32_T)c5_b_idx - 1] = c5_b_r;
    c5_b_varargin_1 = c5_magGrad[(int32_T)c5_b_idx - 1];
    c5_b_varargin_2 = c5_magmax;
    c5_g_x = c5_b_varargin_1;
    c5_g_y = c5_b_varargin_2;
    c5_h_x = c5_g_x;
    c5_h_y = c5_g_y;
    c5_i_x = c5_h_x;
    c5_i_y = c5_h_y;
    c5_g_a = c5_i_x;
    c5_g_b = c5_i_y;
    c5_k_x = c5_g_a;
    c5_j_y = c5_g_b;
    c5_l_x = c5_k_x;
    c5_k_y = c5_j_y;
    c5_magmax = muSingleScalarMax(c5_l_x, c5_k_y);
  }

  if (c5_magmax > 0.0F) {
    c5_c_y = c5_magmax;
    c5_d_y = c5_c_y;
    for (c5_i28 = 0; c5_i28 < 19200; c5_i28++) {
      c5_magGrad[c5_i28] /= c5_d_y;
    }
  }

  c5_st.site = &c5_ed_emlrtRSI;
  c5_b_st.site = &c5_kd_emlrtRSI;
  c5_c_st.site = &c5_tc_emlrtRSI;
  c5_d_st.site = &c5_vc_emlrtRSI;
  c5_b_out = 1.0;
  getnumcores(&c5_b_out);
  for (c5_i29 = 0; c5_i29 < 64; c5_i29++) {
    c5_counts[c5_i29] = 0.0;
  }

  c5_nanFlag = false;
  for (c5_k_i = 0; c5_k_i < 19200; c5_k_i++) {
    c5_l_i = (real_T)c5_k_i + 1.0;
    c5_f_x = c5_magGrad[(int32_T)c5_l_i - 1];
    c5_e_b = muSingleScalarIsNaN(c5_f_x);
    if (c5_e_b) {
      c5_nanFlag = true;
      c5_d_idx = 0.0F;
    } else {
      c5_d_idx = c5_magGrad[(int32_T)c5_l_i - 1] * 63.0F + 0.5F;
    }

    if (c5_d_idx > 63.0F) {
      c5_counts[63]++;
    } else {
      c5_j_x = c5_magGrad[(int32_T)c5_l_i - 1];
      c5_f_b = muSingleScalarIsInf(c5_j_x);
      if (c5_f_b) {
        c5_counts[63]++;
      } else {
        c5_h_a = c5_d_idx;
        c5_c = (int32_T)c5_h_a;
        c5_i_a = c5_d_idx;
        c5_b_c = (int32_T)c5_i_a;
        c5_counts[c5_c] = c5_counts[c5_b_c] + 1.0;
      }
    }
  }

  if (c5_nanFlag) {
    c5_d_st.site = &c5_ld_emlrtRSI;
    c5_warning(chartInstance, &c5_d_st);
  }

  c5_b_sum = 0.0;
  c5_c_idx = 1;
  while ((!(c5_b_sum > 13440.0)) && ((real_T)c5_c_idx <= 64.0)) {
    c5_b_sum += c5_counts[c5_c_idx - 1];
    c5_i31 = c5_c_idx + 1;
    if (c5_i31 > 127) {
      c5_i31 = 127;
    } else if (c5_i31 < -128) {
      c5_i31 = -128;
    }

    c5_c_idx = (int8_T)c5_i31;
  }

  c5_i30 = c5_c_idx - 1;
  if (c5_i30 > 127) {
    c5_i30 = 127;
  } else if (c5_i30 < -128) {
    c5_i30 = -128;
  }

  c5_highThreshTemp = (real_T)(int8_T)c5_i30 / 64.0;
  if (((real_T)c5_c_idx > 64.0) && (!(c5_b_sum > 13440.0))) {
    c5_highThresh_size[0] = 0;
    c5_lowThresh_size[0] = 0;
  } else {
    c5_highThresh_size[0] = 1;
    c5_highThresh_data[0] = c5_highThreshTemp;
    c5_loop_ub = c5_highThresh_size[0] - 1;
    for (c5_i32 = 0; c5_i32 <= c5_loop_ub; c5_i32++) {
      c5_b_data[c5_i32] = c5_highThresh_data[c5_i32];
    }

    c5_b_data[0] *= 0.4;
    c5_lowThresh_size[0] = 1;
    c5_lowThresh_data[0] = c5_b_data[0];
  }

  c5_st.site = &c5_fd_emlrtRSI;
  c5_i33 = 1;
  if ((c5_i33 < 1) || (c5_i33 > c5_lowThresh_size[0])) {
    emlrtDynamicBoundsCheckR2012b(c5_i33, 1, c5_lowThresh_size[0],
      &c5_i_emlrtBCI, &c5_st);
  }

  c5_b_st.site = &c5_md_emlrtRSI;
  c5_lowThresh = c5_lowThresh_data[0];
  c5_c_st.site = &c5_od_emlrtRSI;
  c5_b_lowThresh = c5_lowThresh;
  for (c5_i34 = 0; c5_i34 < 19200; c5_i34++) {
    c5_E[c5_i34] = false;
  }

  for (c5_i35 = 0; c5_i35 < 2; c5_i35++) {
    c5_connDimsT[c5_i35] = 120.0 + 40.0 * (real_T)c5_i35;
  }

  cannythresholding_real32_tbb(&chartInstance->c5_bTmp[0], &chartInstance->c5_a
    [0], &c5_magGrad[0], &c5_connDimsT[0], c5_b_lowThresh, &c5_E[0]);
  c5_i36 = 1;
  if ((c5_i36 < 1) || (c5_i36 > c5_highThresh_size[0])) {
    emlrtDynamicBoundsCheckR2012b(c5_i36, 1, c5_highThresh_size[0],
      &c5_h_emlrtBCI, &c5_st);
  }

  c5_highThresh = c5_highThresh_data[0];
  for (c5_i37 = 0; c5_i37 < 19200; c5_i37++) {
    c5_varargout_1[c5_i37] = ((real_T)c5_magGrad[c5_i37] > c5_highThresh);
  }

  c5_b_st.site = &c5_nd_emlrtRSI;
  c5_c_st.site = &c5_pd_emlrtRSI;
  c5_c_st.site = &c5_qd_emlrtRSI;
  for (c5_i38 = 0; c5_i38 < 2; c5_i38++) {
    c5_connDimsT[c5_i38] = 120.0 + 40.0 * (real_T)c5_i38;
  }

  ippreconstruct_uint8((uint8_T *)&c5_varargout_1[0], (uint8_T *)&c5_E[0],
                       &c5_connDimsT[0], 2.0);
  c5_i39 = 1;
  if ((c5_i39 < 1) || (c5_i39 > c5_lowThresh_size[0])) {
    emlrtDynamicBoundsCheckR2012b(c5_i39, 1, c5_lowThresh_size[0],
      &c5_k_emlrtBCI, (emlrtConstCTX)c5_sp);
  }

  c5_i40 = 1;
  if ((c5_i40 < 1) || (c5_i40 > c5_highThresh_size[0])) {
    emlrtDynamicBoundsCheckR2012b(c5_i40, 1, c5_highThresh_size[0],
      &c5_j_emlrtBCI, (emlrtConstCTX)c5_sp);
  }
}

static void c5_imfilter(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, real32_T c5_varargin_1[19200], real32_T c5_b[19200])
{
  emlrtStack c5_b_st;
  emlrtStack c5_st;
  real_T c5_connDimsT[2];
  real_T c5_outSizeT[2];
  real_T c5_padSizeT[2];
  real_T c5_startT[2];
  real_T c5_b_j;
  real_T c5_c_i;
  int32_T c5_b_i;
  int32_T c5_d_i;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i2;
  int32_T c5_i3;
  int32_T c5_i4;
  int32_T c5_i5;
  int32_T c5_i6;
  int32_T c5_i7;
  int32_T c5_j;
  boolean_T c5_b_modeFlag;
  boolean_T c5_c_modeFlag;
  boolean_T c5_modeFlag;
  boolean_T c5_tooBig;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_st.site = &c5_r_emlrtRSI;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_b_st.site = &c5_jc_emlrtRSI;
  for (c5_j = 0; c5_j < 160; c5_j++) {
    c5_b_j = (real_T)c5_j + 1.0;
    for (c5_i = 0; c5_i < 132; c5_i++) {
      c5_c_i = (real_T)c5_i + 1.0;
      if ((c5_iv[(int32_T)c5_c_i - 1] < 1) || (c5_iv[(int32_T)c5_c_i - 1] > 120))
      {
        emlrtDynamicBoundsCheckR2012b(c5_iv[(int32_T)c5_c_i - 1], 1, 120,
          &c5_f_emlrtBCI, &c5_b_st);
      }

      c5_d_i = c5_iv[(int32_T)c5_b_j + 159];
      if ((c5_d_i < 1) || (c5_d_i > 160)) {
        emlrtDynamicBoundsCheckR2012b(c5_d_i, 1, 160, &c5_g_emlrtBCI, &c5_b_st);
      }

      chartInstance->c5_c_aTmp[((int32_T)c5_c_i + 132 * ((int32_T)c5_b_j - 1)) -
        1] = c5_varargin_1[(c5_iv[(int32_T)c5_c_i - 1] + 120 * (c5_d_i - 1)) - 1];
    }
  }

  c5_st.site = &c5_s_emlrtRSI;
  c5_tooBig = true;
  for (c5_b_i = 0; c5_b_i < 2; c5_b_i++) {
    c5_tooBig = false;
  }

  if (!c5_tooBig) {
    c5_modeFlag = true;
  } else {
    c5_modeFlag = false;
  }

  if (c5_modeFlag) {
    c5_b_modeFlag = true;
  } else {
    c5_b_modeFlag = false;
  }

  c5_c_modeFlag = c5_b_modeFlag;
  if (c5_c_modeFlag) {
    for (c5_i2 = 0; c5_i2 < 2; c5_i2++) {
      c5_padSizeT[c5_i2] = 132.0 + 28.0 * (real_T)c5_i2;
    }

    for (c5_i4 = 0; c5_i4 < 2; c5_i4++) {
      c5_outSizeT[c5_i4] = 120.0 + 40.0 * (real_T)c5_i4;
    }

    for (c5_i6 = 0; c5_i6 < 2; c5_i6++) {
      c5_connDimsT[c5_i6] = 13.0 + -12.0 * (real_T)c5_i6;
    }

    ippfilter_real32(&chartInstance->c5_c_aTmp[0], &c5_b[0], &c5_outSizeT[0],
                     2.0, &c5_padSizeT[0], &c5_dv1[0], &c5_connDimsT[0], true);
  } else {
    for (c5_i1 = 0; c5_i1 < 2; c5_i1++) {
      c5_padSizeT[c5_i1] = 132.0 + 28.0 * (real_T)c5_i1;
    }

    for (c5_i3 = 0; c5_i3 < 2; c5_i3++) {
      c5_outSizeT[c5_i3] = 120.0 + 40.0 * (real_T)c5_i3;
    }

    for (c5_i5 = 0; c5_i5 < 2; c5_i5++) {
      c5_connDimsT[c5_i5] = 13.0 + -12.0 * (real_T)c5_i5;
    }

    for (c5_i7 = 0; c5_i7 < 2; c5_i7++) {
      c5_startT[c5_i7] = 6.0 + -6.0 * (real_T)c5_i7;
    }

    imfilter_real32(&chartInstance->c5_c_aTmp[0], &c5_b[0], 2.0, &c5_outSizeT[0],
                    2.0, &c5_padSizeT[0], &c5_dv2[0], 12.0, &c5_bv[0], 2.0,
                    &c5_connDimsT[0], &c5_startT[0], 2.0, true, true);
  }
}

static void c5_warning(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp)
{
  static char_T c5_msgID[27] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'i', 'm',
    'h', 'i', 's', 't', 'c', ':', 'i', 'n', 'p', 'u', 't', 'H', 'a', 's', 'N',
    'a', 'N', 's' };

  static char_T c5_b_cv[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  static char_T c5_b_cv1[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  emlrtStack c5_st;
  const mxArray *c5_b_y = NULL;
  const mxArray *c5_c_y = NULL;
  const mxArray *c5_y = NULL;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1, 7),
                false);
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_b_cv1, 10, 0U, 1, 0U, 2, 1, 7),
                false);
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_msgID, 10, 0U, 1, 0U, 2, 1, 27),
                false);
  c5_st.site = &c5_wc_emlrtRSI;
  c5_b_feval(chartInstance, &c5_st, c5_y, c5_feval(chartInstance, &c5_st, c5_b_y,
              c5_c_y));
}

static void c5_imfindcircles(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, boolean_T c5_varargin_1[19200],
  real_T c5_b_varargin_2[2], c5_coder_array_real_T_2D *c5_centers,
  c5_coder_array_real_T_2D *c5_r_estimated)
{
  static char_T c5_b_cv3[119] = { '\\', 't', '[', 'C', 'E', 'N', 'T', 'E', 'R',
    'S', '1', ',', ' ', 'R', 'A', 'D', 'I', 'I', '1', ',', ' ', 'M', 'E', 'T',
    'R', 'I', 'C', '1', ']', ' ', '=', ' ', 'I', 'M', 'F', 'I', 'N', 'D', 'C',
    'I', 'R', 'C', 'L', 'E', 'S', '(', 'A', ',', ' ', '[', '2', '0', ' ', '6',
    '0', ']', ')', ';', '\\', 'n', '\\', 't', '[', 'C', 'E', 'N', 'T', 'E', 'R',
    'S', '2', ',', ' ', 'R', 'A', 'D', 'I', 'I', '2', ',', ' ', 'M', 'E', 'T',
    'R', 'I', 'C', '2', ']', ' ', '=', ' ', 'I', 'M', 'F', 'I', 'N', 'D', 'C',
    'I', 'R', 'C', 'L', 'E', 'S', '(', 'A', ',', ' ', '[', '6', '1', ' ', '1',
    '0', '0', ']', ')', ';' };

  static char_T c5_b_cv[36] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'i', 'm', 'f',
    'i', 'n', 'd', 'c', 'i', 'r', 'c', 'l', 'e', 's', ':', 'e', 'x', 'p', 'e',
    'c', 't', 'e', 'd', 'I', 'n', 't', 'e', 'g', 'e', 'r' };

  static char_T c5_b_cv1[35] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'i', 'm',
    'f', 'i', 'n', 'd', 'c', 'i', 'r', 'c', 'l', 'e', 's', ':', 'e', 'x', 'p',
    'e', 'c', 't', 'e', 'd', 'N', 'o', 'n', 'N', 'a', 'N' };

  static char_T c5_b_cv2[35] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'i', 'm',
    'f', 'i', 'n', 'd', 'c', 'i', 'r', 'c', 'l', 'e', 's', ':', 'e', 'x', 'p',
    'e', 'c', 't', 'e', 'd', 'F', 'i', 'n', 'i', 't', 'e' };

  c5_coder_array_boolean_T_2D c5_p_x;
  c5_coder_array_creal_T c5_m_x;
  c5_coder_array_int32_T c5_ii;
  c5_coder_array_real_T c5_idx2Keep;
  c5_coder_array_real_T_2D c5_b_centers;
  c5_coder_array_real_T_2D c5_metric;
  emlrtStack c5_b_st;
  emlrtStack c5_c_st;
  emlrtStack c5_d_st;
  emlrtStack c5_e_st;
  emlrtStack c5_st;
  const mxArray *c5_b_y = NULL;
  const mxArray *c5_c_y = NULL;
  const mxArray *c5_e_y = NULL;
  const mxArray *c5_f_y = NULL;
  const mxArray *c5_g_y = NULL;
  const mxArray *c5_h_y = NULL;
  const mxArray *c5_i_y = NULL;
  const mxArray *c5_j_y = NULL;
  const mxArray *c5_k_y = NULL;
  const mxArray *c5_m_y = NULL;
  const mxArray *c5_n_y = NULL;
  const mxArray *c5_y = NULL;
  creal_T c5_o_x;
  real_T c5_radiusRange_data[2];
  real_T c5_b_k;
  real_T c5_b_x;
  real_T c5_c_x;
  real_T c5_d_k;
  real_T c5_d_x;
  real_T c5_d_y;
  real_T c5_e_x;
  real_T c5_f_k;
  real_T c5_f_x;
  real_T c5_g_x;
  real_T c5_h_k;
  real_T c5_h_x;
  real_T c5_i_x;
  real_T c5_j_x;
  real_T c5_k_x;
  real_T c5_l_x;
  int32_T c5_b_iv[2];
  int32_T c5_b_ii;
  int32_T c5_b_loop_ub;
  int32_T c5_b_metric;
  int32_T c5_b_nx;
  int32_T c5_c_centers;
  int32_T c5_c_ii;
  int32_T c5_c_k;
  int32_T c5_c_loop_ub;
  int32_T c5_d_loop_ub;
  int32_T c5_e_k;
  int32_T c5_e_loop_ub;
  int32_T c5_f_loop_ub;
  int32_T c5_g_k;
  int32_T c5_g_loop_ub;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i10;
  int32_T c5_i11;
  int32_T c5_i12;
  int32_T c5_i13;
  int32_T c5_i2;
  int32_T c5_i3;
  int32_T c5_i4;
  int32_T c5_i5;
  int32_T c5_i6;
  int32_T c5_i7;
  int32_T c5_i8;
  int32_T c5_i9;
  int32_T c5_i_k;
  int32_T c5_idx;
  int32_T c5_j_b;
  int32_T c5_k;
  int32_T c5_k_b;
  int32_T c5_loop_ub;
  int32_T c5_nx;
  boolean_T c5_b;
  boolean_T c5_b1;
  boolean_T c5_b10;
  boolean_T c5_b11;
  boolean_T c5_b12;
  boolean_T c5_b13;
  boolean_T c5_b14;
  boolean_T c5_b2;
  boolean_T c5_b3;
  boolean_T c5_b4;
  boolean_T c5_b5;
  boolean_T c5_b6;
  boolean_T c5_b7;
  boolean_T c5_b8;
  boolean_T c5_b9;
  boolean_T c5_b_b;
  boolean_T c5_b_p;
  boolean_T c5_c_b;
  boolean_T c5_c_p;
  boolean_T c5_d_b;
  boolean_T c5_d_p;
  boolean_T c5_e_b;
  boolean_T c5_e_p;
  boolean_T c5_exitg1;
  boolean_T c5_f_b;
  boolean_T c5_f_p;
  boolean_T c5_g_b;
  boolean_T c5_h_b;
  boolean_T c5_i_b;
  boolean_T c5_l_y;
  boolean_T c5_n_x;
  boolean_T c5_overflow;
  boolean_T c5_p;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_c_st.prev = &c5_b_st;
  c5_c_st.tls = c5_b_st.tls;
  c5_d_st.prev = &c5_c_st;
  c5_d_st.tls = c5_c_st.tls;
  c5_e_st.prev = &c5_d_st;
  c5_e_st.tls = c5_d_st.tls;
  c5_st.site = &c5_xd_emlrtRSI;
  c5_b_st.site = &c5_yd_emlrtRSI;
  c5_c_st.site = &c5_ad_emlrtRSI;
  c5_p = true;
  c5_k = 0;
  c5_exitg1 = false;
  while ((!c5_exitg1) && (c5_k < 2)) {
    c5_b_k = (real_T)c5_k + 1.0;
    c5_b_x = c5_b_varargin_2[(int32_T)c5_b_k - 1];
    c5_c_x = c5_b_x;
    c5_d_x = c5_c_x;
    c5_b_b = muDoubleScalarIsInf(c5_d_x);
    c5_b1 = !c5_b_b;
    c5_e_x = c5_c_x;
    c5_c_b = muDoubleScalarIsNaN(c5_e_x);
    c5_b2 = !c5_c_b;
    c5_d_b = (c5_b1 && c5_b2);
    if (c5_d_b) {
      c5_f_x = c5_b_x;
      c5_h_x = c5_f_x;
      c5_d_y = c5_h_x;
      c5_d_y = muDoubleScalarFloor(c5_d_y);
      if (c5_d_y == c5_b_x) {
        c5_c_p = true;
      } else {
        c5_c_p = false;
      }
    } else {
      c5_c_p = false;
    }

    c5_d_p = c5_c_p;
    if (c5_d_p) {
      c5_k++;
    } else {
      c5_p = false;
      c5_exitg1 = true;
    }
  }

  if (c5_p) {
    c5_b = true;
  } else {
    c5_b = false;
  }

  if (!c5_b) {
    c5_y = NULL;
    sf_mex_assign(&c5_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1, 36),
                  false);
    c5_b_y = NULL;
    sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_cv6, 10, 0U, 1, 0U, 2, 1, 47),
                  false);
    c5_c_y = NULL;
    sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_cv4, 10, 0U, 1, 0U, 2, 1, 29),
                  false);
    sf_mex_call(&c5_c_st, &c5_k_emlrtMCI, "error", 0U, 2U, 14, c5_y, 14,
                sf_mex_call(&c5_c_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c5_c_st, NULL, "message", 1U, 2U, 14, c5_b_y, 14, c5_c_y)));
  }

  c5_c_st.site = &c5_ad_emlrtRSI;
  c5_b_p = true;
  c5_c_k = 0;
  c5_exitg1 = false;
  while ((!c5_exitg1) && (c5_c_k < 2)) {
    c5_d_k = (real_T)c5_c_k + 1.0;
    c5_g_x = c5_b_varargin_2[(int32_T)c5_d_k - 1];
    c5_i_x = c5_g_x;
    c5_e_b = muDoubleScalarIsNaN(c5_i_x);
    c5_e_p = !c5_e_b;
    if (c5_e_p) {
      c5_c_k++;
    } else {
      c5_b_p = false;
      c5_exitg1 = true;
    }
  }

  if (c5_b_p) {
    c5_b3 = true;
  } else {
    c5_b3 = false;
  }

  if (!c5_b3) {
    c5_e_y = NULL;
    sf_mex_assign(&c5_e_y, sf_mex_create("y", c5_b_cv1, 10, 0U, 1, 0U, 2, 1, 35),
                  false);
    c5_f_y = NULL;
    sf_mex_assign(&c5_f_y, sf_mex_create("y", c5_cv5, 10, 0U, 1, 0U, 2, 1, 46),
                  false);
    c5_g_y = NULL;
    sf_mex_assign(&c5_g_y, sf_mex_create("y", c5_cv4, 10, 0U, 1, 0U, 2, 1, 29),
                  false);
    sf_mex_call(&c5_c_st, &c5_l_emlrtMCI, "error", 0U, 2U, 14, c5_e_y, 14,
                sf_mex_call(&c5_c_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c5_c_st, NULL, "message", 1U, 2U, 14, c5_f_y, 14, c5_g_y)));
  }

  c5_c_st.site = &c5_ad_emlrtRSI;
  c5_c_st.site = &c5_ad_emlrtRSI;
  c5_f_p = true;
  c5_e_k = 0;
  c5_exitg1 = false;
  while ((!c5_exitg1) && (c5_e_k < 2)) {
    c5_f_k = (real_T)c5_e_k + 1.0;
    c5_j_x = c5_b_varargin_2[(int32_T)c5_f_k - 1];
    c5_k_x = c5_j_x;
    c5_f_b = muDoubleScalarIsInf(c5_k_x);
    c5_b5 = !c5_f_b;
    c5_l_x = c5_j_x;
    c5_g_b = muDoubleScalarIsNaN(c5_l_x);
    c5_b6 = !c5_g_b;
    c5_h_b = (c5_b5 && c5_b6);
    if (c5_h_b) {
      c5_e_k++;
    } else {
      c5_f_p = false;
      c5_exitg1 = true;
    }
  }

  if (c5_f_p) {
    c5_b4 = true;
  } else {
    c5_b4 = false;
  }

  if (!c5_b4) {
    c5_h_y = NULL;
    sf_mex_assign(&c5_h_y, sf_mex_create("y", c5_b_cv2, 10, 0U, 1, 0U, 2, 1, 35),
                  false);
    c5_i_y = NULL;
    sf_mex_assign(&c5_i_y, sf_mex_create("y", c5_cv2, 10, 0U, 1, 0U, 2, 1, 46),
                  false);
    c5_j_y = NULL;
    sf_mex_assign(&c5_j_y, sf_mex_create("y", c5_cv4, 10, 0U, 1, 0U, 2, 1, 29),
                  false);
    sf_mex_call(&c5_c_st, &c5_g_emlrtMCI, "error", 0U, 2U, 14, c5_h_y, 14,
                sf_mex_call(&c5_c_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c5_c_st, NULL, "message", 1U, 2U, 14, c5_i_y, 14, c5_j_y)));
  }

  for (c5_i = 0; c5_i < 2; c5_i++) {
    c5_radiusRange_data[c5_i] = c5_b_varargin_2[c5_i];
  }

  c5_st.site = &c5_uk_emlrtRSI;
  c5_array_real_T_2D_SetSize(chartInstance, &c5_st, c5_centers, &c5_r_emlrtRTEI,
    0, 0);
  c5_st.site = &c5_tk_emlrtRSI;
  c5_array_real_T_2D_SetSize(chartInstance, &c5_st, c5_r_estimated,
    &c5_s_emlrtRTEI, 0, 0);
  if (c5_radiusRange_data[1] > 3.0 * c5_radiusRange_data[0]) {
    c5_k_y = NULL;
    sf_mex_assign(&c5_k_y, sf_mex_create("y", c5_b_cv3, 10, 0U, 1, 0U, 2, 1, 119),
                  false);
    c5_st.site = &c5_wd_emlrtRSI;
    c5_b_warning(chartInstance, &c5_st, c5_sprintf(chartInstance, &c5_st, c5_k_y));
  }

  c5_st.site = &c5_vd_emlrtRSI;
  c5_chaccum(chartInstance, &c5_st, c5_varargin_1, c5_radiusRange_data,
             chartInstance->c5_accumMatrix, chartInstance->c5_gradientImg);
  for (c5_i1 = 0; c5_i1 < 19200; c5_i1++) {
    chartInstance->c5_x[c5_i1] = chartInstance->c5_accumMatrix[c5_i1];
  }

  c5_array_creal_T_Constructor(chartInstance, &c5_m_x);
  c5_array_creal_T_SetSize(chartInstance, c5_sp, &c5_m_x, &c5_t_emlrtRTEI, 19200);
  for (c5_i2 = 0; c5_i2 < 19200; c5_i2++) {
    c5_m_x.vector.data[c5_i2] = chartInstance->c5_x[c5_i2];
  }

  c5_l_y = false;
  c5_g_k = 0;
  c5_exitg1 = false;
  while ((!c5_exitg1) && (c5_g_k < 19200)) {
    c5_h_k = (real_T)c5_g_k + 1.0;
    c5_n_x = ((c5_m_x.vector.data[(int32_T)c5_h_k - 1].re == c5_dc.re) &&
              (c5_m_x.vector.data[(int32_T)c5_h_k - 1].im == c5_dc.im));
    if (c5_n_x) {
      c5_b7 = true;
    } else {
      c5_o_x = c5_m_x.vector.data[(int32_T)c5_h_k - 1];
      c5_b8 = muDoubleScalarIsNaN(c5_o_x.re);
      c5_b9 = muDoubleScalarIsNaN(c5_o_x.im);
      c5_i_b = (c5_b8 || c5_b9);
      if (c5_i_b) {
        c5_b7 = true;
      } else {
        c5_b7 = false;
      }
    }

    if (!c5_b7) {
      c5_l_y = true;
      c5_exitg1 = true;
    } else {
      c5_g_k++;
    }
  }

  c5_array_creal_T_Destructor(chartInstance, &c5_m_x);
  c5_array_real_T_Constructor(chartInstance, &c5_idx2Keep);
  c5_array_real_T_2D_Constructor(chartInstance, &c5_b_centers);
  c5_array_real_T_2D_Constructor(chartInstance, &c5_metric);
  c5_array_boolean_T_2D_Constructor(chartInstance, &c5_p_x);
  c5_array_int32_T_Constructor(chartInstance, &c5_ii);
  if (!c5_l_y) {
  } else {
    c5_st.site = &c5_ud_emlrtRSI;
    for (c5_i3 = 0; c5_i3 < 19200; c5_i3++) {
      chartInstance->c5_b_accumMatrix[c5_i3] = chartInstance->
        c5_accumMatrix[c5_i3];
    }

    c5_chcenters(chartInstance, &c5_st, chartInstance->c5_b_accumMatrix,
                 &c5_b_centers, &c5_metric);
    c5_st.site = &c5_ud_emlrtRSI;
    c5_array_real_T_2D_SetSize(chartInstance, &c5_st, c5_centers,
      &c5_u_emlrtRTEI, c5_b_centers.size[0], c5_b_centers.size[1]);
    c5_loop_ub = c5_b_centers.size[0] * c5_b_centers.size[1] - 1;
    for (c5_i4 = 0; c5_i4 <= c5_loop_ub; c5_i4++) {
      c5_centers->vector.data[c5_i4] = c5_b_centers.vector.data[c5_i4];
    }

    c5_b10 = (c5_b_centers.size[0] == 0);
    c5_b11 = (c5_b_centers.size[1] == 0);
    if (c5_b10 || c5_b11) {
    } else {
      c5_st.site = &c5_td_emlrtRSI;
      c5_b_st.site = &c5_td_emlrtRSI;
      c5_array_boolean_T_2D_SetSize(chartInstance, &c5_b_st, &c5_p_x,
        &c5_v_emlrtRTEI, c5_metric.size[0], c5_metric.size[1]);
      c5_b_loop_ub = c5_metric.size[0] * c5_metric.size[1] - 1;
      for (c5_i5 = 0; c5_i5 <= c5_b_loop_ub; c5_i5++) {
        c5_p_x.vector.data[c5_i5] = (c5_metric.vector.data[c5_i5] >=
          0.099999999999999978);
      }

      c5_b_st.site = &c5_pj_emlrtRSI;
      c5_nx = c5_p_x.size[0] * c5_p_x.size[1];
      c5_c_st.site = &c5_qj_emlrtRSI;
      c5_i_k = c5_nx;
      c5_b_nx = c5_nx;
      c5_idx = 0;
      c5_array_int32_T_SetSize(chartInstance, &c5_c_st, &c5_ii, &c5_w_emlrtRTEI,
        c5_i_k);
      c5_d_st.site = &c5_rj_emlrtRSI;
      c5_j_b = c5_b_nx;
      c5_k_b = c5_j_b;
      if (c5_k_b < 1) {
        c5_overflow = false;
      } else {
        c5_overflow = (c5_k_b > 2147483646);
      }

      if (c5_overflow) {
        c5_e_st.site = &c5_v_emlrtRSI;
        c5_check_forloop_overflow_error(chartInstance, &c5_e_st);
      }

      c5_b_ii = 1;
      c5_exitg1 = false;
      while ((!c5_exitg1) && (c5_b_ii - 1 <= c5_b_nx - 1)) {
        c5_c_ii = c5_b_ii;
        if (c5_p_x.vector.data[c5_c_ii - 1]) {
          c5_idx++;
          c5_ii.vector.data[c5_idx - 1] = c5_c_ii;
          if (c5_idx >= c5_i_k) {
            c5_exitg1 = true;
          } else {
            c5_b_ii++;
          }
        } else {
          c5_b_ii++;
        }
      }

      if (c5_idx > c5_i_k) {
        c5_m_y = NULL;
        sf_mex_assign(&c5_m_y, sf_mex_create("y", c5_cv3, 10, 0U, 1, 0U, 2, 1,
          30), false);
        c5_n_y = NULL;
        sf_mex_assign(&c5_n_y, sf_mex_create("y", c5_cv3, 10, 0U, 1, 0U, 2, 1,
          30), false);
        sf_mex_call(&c5_c_st, &c5_eb_emlrtMCI, "error", 0U, 2U, 14, c5_m_y, 14,
                    sf_mex_call(&c5_c_st, NULL, "getString", 1U, 1U, 14,
          sf_mex_call(&c5_c_st, NULL, "message", 1U, 1U, 14, c5_n_y)));
      }

      if (c5_i_k == 1) {
        if (c5_idx == 0) {
          c5_array_int32_T_SetSize(chartInstance, &c5_c_st, &c5_ii,
            &c5_x_emlrtRTEI, 0);
        }
      } else {
        c5_b12 = (c5_idx < 1);
        if (c5_b12) {
          c5_i6 = 0;
        } else {
          c5_i6 = c5_idx;
        }

        c5_b_iv[0] = 1;
        c5_b_iv[1] = c5_i6;
        c5_d_st.site = &c5_sj_emlrtRSI;
        c5_indexShapeCheck(chartInstance, &c5_d_st, c5_ii.size[0], c5_b_iv);
        c5_array_int32_T_SetSize(chartInstance, &c5_c_st, &c5_ii,
          &c5_x_emlrtRTEI, c5_i6);
      }

      c5_array_real_T_SetSize(chartInstance, &c5_st, &c5_idx2Keep,
        &c5_y_emlrtRTEI, c5_ii.size[0]);
      c5_c_loop_ub = c5_ii.size[0] - 1;
      for (c5_i7 = 0; c5_i7 <= c5_c_loop_ub; c5_i7++) {
        c5_idx2Keep.vector.data[c5_i7] = (real_T)c5_ii.vector.data[c5_i7];
      }

      c5_c_centers = c5_b_centers.size[0];
      c5_st.site = &c5_sk_emlrtRSI;
      c5_array_real_T_2D_SetSize(chartInstance, &c5_st, c5_centers,
        &c5_ab_emlrtRTEI, c5_idx2Keep.size[0], c5_b_centers.size[1]);
      c5_d_loop_ub = c5_b_centers.size[1] - 1;
      for (c5_i8 = 0; c5_i8 <= c5_d_loop_ub; c5_i8++) {
        c5_e_loop_ub = c5_idx2Keep.size[0] - 1;
        for (c5_i9 = 0; c5_i9 <= c5_e_loop_ub; c5_i9++) {
          c5_i11 = (int32_T)c5_idx2Keep.vector.data[c5_i9];
          if ((c5_i11 < 1) || (c5_i11 > c5_c_centers)) {
            emlrtDynamicBoundsCheckR2012b(c5_i11, 1, c5_c_centers,
              &c5_l_emlrtBCI, (emlrtConstCTX)c5_sp);
          }

          c5_centers->vector.data[c5_i9 + c5_centers->size[0] * c5_i8] =
            c5_b_centers.vector.data[(c5_i11 + c5_b_centers.size[0] * c5_i8) - 1];
        }
      }

      c5_b_metric = c5_metric.size[0];
      c5_f_loop_ub = c5_idx2Keep.size[0] - 1;
      for (c5_i10 = 0; c5_i10 <= c5_f_loop_ub; c5_i10++) {
        c5_i12 = (int32_T)c5_idx2Keep.vector.data[c5_i10];
        if ((c5_i12 < 1) || (c5_i12 > c5_b_metric)) {
          emlrtDynamicBoundsCheckR2012b(c5_i12, 1, c5_b_metric, &c5_m_emlrtBCI,
            (emlrtConstCTX)c5_sp);
        }
      }

      c5_b13 = (c5_centers->size[0] == 0);
      c5_b14 = (c5_centers->size[1] == 0);
      if (c5_b13 || c5_b14) {
        c5_st.site = &c5_rk_emlrtRSI;
        c5_array_real_T_2D_SetSize(chartInstance, &c5_st, c5_centers,
          &c5_cb_emlrtRTEI, 0, 0);
      } else {
        c5_st.site = &c5_sd_emlrtRSI;
        c5_chradiiphcode(chartInstance, &c5_st, c5_centers,
                         chartInstance->c5_accumMatrix, c5_radiusRange_data,
                         &c5_idx2Keep);
        c5_st.site = &c5_sd_emlrtRSI;
        c5_array_real_T_2D_SetSize(chartInstance, &c5_st, c5_r_estimated,
          &c5_bb_emlrtRTEI, c5_idx2Keep.size[0], 1);
        c5_g_loop_ub = c5_idx2Keep.size[0] - 1;
        for (c5_i13 = 0; c5_i13 <= c5_g_loop_ub; c5_i13++) {
          c5_r_estimated->vector.data[c5_i13] = c5_idx2Keep.vector.data[c5_i13];
        }
      }
    }
  }

  c5_array_int32_T_Destructor(chartInstance, &c5_ii);
  c5_array_boolean_T_2D_Destructor(chartInstance, &c5_p_x);
  c5_array_real_T_2D_Destructor(chartInstance, &c5_metric);
  c5_array_real_T_2D_Destructor(chartInstance, &c5_b_centers);
  c5_array_real_T_Destructor(chartInstance, &c5_idx2Keep);
}

static void c5_b_warning(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, const mxArray *c5_varargin_6)
{
  static char_T c5_msgID[44] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'i', 'm',
    'f', 'i', 'n', 'd', 'c', 'i', 'r', 'c', 'l', 'e', 's', ':', 'w', 'a', 'r',
    'n', 'F', 'o', 'r', 'L', 'a', 'r', 'g', 'e', 'R', 'a', 'd', 'i', 'u', 's',
    'R', 'a', 'n', 'g', 'e' };

  static char_T c5_varargin_3[19] = { '(', 'R', 'm', 'a', 'x', ' ', '-', ' ',
    'R', 'm', 'i', 'n', ')', ' ', '<', ' ', '1', '0', '0' };

  static char_T c5_b_varargin_2[13] = { 'R', 'm', 'a', 'x', ' ', '<', ' ', '3',
    '*', 'R', 'm', 'i', 'n' };

  static char_T c5_varargin_1[13] = { 'I', 'M', 'F', 'I', 'N', 'D', 'C', 'I',
    'R', 'C', 'L', 'E', 'S' };

  static char_T c5_varargin_4[8] = { '[', '2', '0', ' ', '1', '0', '0', ']' };

  static char_T c5_b_cv[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  static char_T c5_b_cv1[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  emlrtStack c5_st;
  const mxArray *c5_b_y = NULL;
  const mxArray *c5_c_y = NULL;
  const mxArray *c5_d_y = NULL;
  const mxArray *c5_e_y = NULL;
  const mxArray *c5_f_y = NULL;
  const mxArray *c5_g_y = NULL;
  const mxArray *c5_h_y = NULL;
  const mxArray *c5_y = NULL;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1, 7),
                false);
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_b_cv1, 10, 0U, 1, 0U, 2, 1, 7),
                false);
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_msgID, 10, 0U, 1, 0U, 2, 1, 44),
                false);
  c5_d_y = NULL;
  sf_mex_assign(&c5_d_y, sf_mex_create("y", c5_varargin_1, 10, 0U, 1, 0U, 2, 1,
    13), false);
  c5_e_y = NULL;
  sf_mex_assign(&c5_e_y, sf_mex_create("y", c5_b_varargin_2, 10, 0U, 1, 0U, 2, 1,
    13), false);
  c5_f_y = NULL;
  sf_mex_assign(&c5_f_y, sf_mex_create("y", c5_varargin_3, 10, 0U, 1, 0U, 2, 1,
    19), false);
  c5_g_y = NULL;
  sf_mex_assign(&c5_g_y, sf_mex_create("y", c5_varargin_4, 10, 0U, 1, 0U, 2, 1,
    8), false);
  c5_h_y = NULL;
  sf_mex_assign(&c5_h_y, sf_mex_create("y", c5_varargin_1, 10, 0U, 1, 0U, 2, 1,
    13), false);
  c5_st.site = &c5_wc_emlrtRSI;
  c5_d_feval(chartInstance, &c5_st, c5_y, c5_c_feval(chartInstance, &c5_st,
              c5_b_y, c5_c_y, c5_d_y, c5_e_y, c5_f_y, c5_g_y, c5_h_y, sf_mex_dup
              (c5_varargin_6)));
  sf_mex_destroy(&c5_varargin_6);
}

static void c5_chaccum(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, boolean_T c5_varargin_1[19200], real_T
  c5_varargin_2_data[], creal_T c5_c_accumMatrix[19200], real32_T
  c5_b_gradientImg[19200])
{
  static creal_T c5_b_dc = { 0.0,      /* re */
    1.0                                /* im */
  };

  static char_T c5_b_cv[30] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'i', 'z',
    'e', 'D', 'i', 'm', 'e', 'n', 's', 'i', 'o', 'n', 's', 'M', 'u', 's', 't',
    'M', 'a', 't', 'c', 'h' };

  c5_coder_array_boolean_T_2D c5_inside;
  c5_coder_array_creal_T c5_wkeep;
  c5_coder_array_creal_T_2D c5_w;
  c5_coder_array_int32_T c5_ii;
  c5_coder_array_int32_T c5_jj;
  c5_coder_array_int32_T c5_r;
  c5_coder_array_int32_T c5_xckeep;
  c5_coder_array_int32_T c5_yckeep;
  c5_coder_array_real32_T_2D c5_xc;
  c5_coder_array_real32_T_2D c5_yc;
  c5_coder_array_real_T c5_Ex;
  c5_coder_array_real_T c5_Ex_chunk;
  c5_coder_array_real_T c5_Ey;
  c5_coder_array_real_T c5_Ey_chunk;
  c5_coder_array_real_T c5_b_varargin_2;
  c5_coder_array_real_T c5_idxE;
  c5_coder_array_real_T c5_idxE_chunk;
  c5_coder_array_real_T c5_ndx;
  c5_coder_array_real_T_2D c5_r1;
  emlrtStack c5_b_st;
  emlrtStack c5_c_st;
  emlrtStack c5_d_st;
  emlrtStack c5_e_st;
  emlrtStack c5_st;
  const mxArray *c5_d_y = NULL;
  const mxArray *c5_e_y = NULL;
  creal_T c5_Opca_data[81];
  creal_T c5_y_data[81];
  creal_T c5_dc1;
  real_T c5_lnR_data[81];
  real_T c5_radiusRange_data[81];
  real_T c5_b_dv[2];
  real_T c5_radiusRangeIn_data[2];
  real_T c5_a1;
  real_T c5_ab_x;
  real_T c5_ai;
  real_T c5_apnd;
  real_T c5_ar;
  real_T c5_b1;
  real_T c5_b_d;
  real_T c5_b_idx1;
  real_T c5_b_idx2;
  real_T c5_b_k;
  real_T c5_b_lnR;
  real_T c5_b_s;
  real_T c5_b_varargin_1;
  real_T c5_bb_x;
  real_T c5_bi;
  real_T c5_bim;
  real_T c5_br;
  real_T c5_brm;
  real_T c5_c;
  real_T c5_c_i;
  real_T c5_c_idx;
  real_T c5_c_varargin_2;
  real_T c5_cb_x;
  real_T c5_cdiff;
  real_T c5_d;
  real_T c5_d_b;
  real_T c5_d_lnR;
  real_T c5_db_x;
  real_T c5_dim1;
  real_T c5_dim2;
  real_T c5_e_a;
  real_T c5_e_b;
  real_T c5_e_lnR;
  real_T c5_eb_x;
  real_T c5_edgeThresh;
  real_T c5_f_a;
  real_T c5_f_lnR;
  real_T c5_f_y;
  real_T c5_fb_x;
  real_T c5_g_a;
  real_T c5_g_y;
  real_T c5_gb_x;
  real_T c5_h_a;
  real_T c5_h_x;
  real_T c5_h_y;
  real_T c5_hb_x;
  real_T c5_i_a;
  real_T c5_i_x;
  real_T c5_i_y;
  real_T c5_ib_x;
  real_T c5_j_a;
  real_T c5_j_b;
  real_T c5_j_x;
  real_T c5_j_y;
  real_T c5_jb_x;
  real_T c5_k_a;
  real_T c5_k_b;
  real_T c5_k_x;
  real_T c5_k_y;
  real_T c5_kd;
  real_T c5_l_x;
  real_T c5_l_y;
  real_T c5_lenE;
  real_T c5_lnR;
  real_T c5_m_a;
  real_T c5_m_x;
  real_T c5_m_y;
  real_T c5_minval;
  real_T c5_n_a;
  real_T c5_n_x;
  real_T c5_n_y;
  real_T c5_ndbl;
  real_T c5_ni;
  real_T c5_nr;
  real_T c5_o_x;
  real_T c5_p_b;
  real_T c5_p_x;
  real_T c5_q_b;
  real_T c5_q_x;
  real_T c5_r_b;
  real_T c5_r_x;
  real_T c5_s_x;
  real_T c5_sgnbi;
  real_T c5_sgnbr;
  real_T c5_sizeChunk;
  real_T c5_t_x;
  real_T c5_thresh;
  real_T c5_u_x;
  real_T c5_v_x;
  real_T c5_w_x;
  real_T c5_x_x;
  real_T c5_xcStep;
  real_T c5_y_x;
  int32_T c5_tmp_data[81];
  int32_T c5_Opca_size[2];
  int32_T c5_b_iv[2];
  int32_T c5_b_iv1[2];
  int32_T c5_lnR_size[2];
  int32_T c5_radiusRangeIn_size[2];
  int32_T c5_radiusRange_size[2];
  int32_T c5_y_size[2];
  int32_T c5_rows_to_keep_size[1];
  int32_T c5_tmp_size[1];
  int32_T c5_b_i;
  int32_T c5_b_idx;
  int32_T c5_b_loop_ub;
  int32_T c5_c_idx1;
  int32_T c5_c_idx2;
  int32_T c5_c_k;
  int32_T c5_c_lnR;
  int32_T c5_c_loop_ub;
  int32_T c5_d_idx;
  int32_T c5_d_k;
  int32_T c5_d_loop_ub;
  int32_T c5_e_idx;
  int32_T c5_e_k;
  int32_T c5_e_loop_ub;
  int32_T c5_f_k;
  int32_T c5_f_loop_ub;
  int32_T c5_first;
  int32_T c5_g_k;
  int32_T c5_g_loop_ub;
  int32_T c5_h_k;
  int32_T c5_h_loop_ub;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i10;
  int32_T c5_i100;
  int32_T c5_i101;
  int32_T c5_i102;
  int32_T c5_i103;
  int32_T c5_i104;
  int32_T c5_i105;
  int32_T c5_i106;
  int32_T c5_i107;
  int32_T c5_i108;
  int32_T c5_i109;
  int32_T c5_i11;
  int32_T c5_i110;
  int32_T c5_i111;
  int32_T c5_i112;
  int32_T c5_i113;
  int32_T c5_i114;
  int32_T c5_i115;
  int32_T c5_i116;
  int32_T c5_i117;
  int32_T c5_i118;
  int32_T c5_i119;
  int32_T c5_i12;
  int32_T c5_i120;
  int32_T c5_i121;
  int32_T c5_i122;
  int32_T c5_i123;
  int32_T c5_i124;
  int32_T c5_i125;
  int32_T c5_i126;
  int32_T c5_i127;
  int32_T c5_i128;
  int32_T c5_i129;
  int32_T c5_i13;
  int32_T c5_i130;
  int32_T c5_i131;
  int32_T c5_i132;
  int32_T c5_i133;
  int32_T c5_i134;
  int32_T c5_i135;
  int32_T c5_i136;
  int32_T c5_i137;
  int32_T c5_i138;
  int32_T c5_i139;
  int32_T c5_i14;
  int32_T c5_i140;
  int32_T c5_i141;
  int32_T c5_i142;
  int32_T c5_i143;
  int32_T c5_i144;
  int32_T c5_i145;
  int32_T c5_i146;
  int32_T c5_i147;
  int32_T c5_i148;
  int32_T c5_i149;
  int32_T c5_i15;
  int32_T c5_i150;
  int32_T c5_i151;
  int32_T c5_i152;
  int32_T c5_i153;
  int32_T c5_i154;
  int32_T c5_i155;
  int32_T c5_i156;
  int32_T c5_i16;
  int32_T c5_i17;
  int32_T c5_i18;
  int32_T c5_i19;
  int32_T c5_i2;
  int32_T c5_i20;
  int32_T c5_i21;
  int32_T c5_i22;
  int32_T c5_i23;
  int32_T c5_i24;
  int32_T c5_i25;
  int32_T c5_i26;
  int32_T c5_i27;
  int32_T c5_i28;
  int32_T c5_i29;
  int32_T c5_i3;
  int32_T c5_i30;
  int32_T c5_i31;
  int32_T c5_i32;
  int32_T c5_i33;
  int32_T c5_i34;
  int32_T c5_i35;
  int32_T c5_i36;
  int32_T c5_i37;
  int32_T c5_i38;
  int32_T c5_i39;
  int32_T c5_i4;
  int32_T c5_i40;
  int32_T c5_i41;
  int32_T c5_i42;
  int32_T c5_i43;
  int32_T c5_i44;
  int32_T c5_i45;
  int32_T c5_i46;
  int32_T c5_i47;
  int32_T c5_i48;
  int32_T c5_i49;
  int32_T c5_i5;
  int32_T c5_i50;
  int32_T c5_i51;
  int32_T c5_i52;
  int32_T c5_i53;
  int32_T c5_i54;
  int32_T c5_i55;
  int32_T c5_i56;
  int32_T c5_i57;
  int32_T c5_i58;
  int32_T c5_i59;
  int32_T c5_i6;
  int32_T c5_i60;
  int32_T c5_i61;
  int32_T c5_i62;
  int32_T c5_i63;
  int32_T c5_i64;
  int32_T c5_i65;
  int32_T c5_i66;
  int32_T c5_i67;
  int32_T c5_i68;
  int32_T c5_i69;
  int32_T c5_i7;
  int32_T c5_i70;
  int32_T c5_i71;
  int32_T c5_i72;
  int32_T c5_i73;
  int32_T c5_i74;
  int32_T c5_i75;
  int32_T c5_i76;
  int32_T c5_i77;
  int32_T c5_i78;
  int32_T c5_i79;
  int32_T c5_i8;
  int32_T c5_i80;
  int32_T c5_i81;
  int32_T c5_i82;
  int32_T c5_i83;
  int32_T c5_i84;
  int32_T c5_i85;
  int32_T c5_i86;
  int32_T c5_i87;
  int32_T c5_i88;
  int32_T c5_i89;
  int32_T c5_i9;
  int32_T c5_i90;
  int32_T c5_i91;
  int32_T c5_i92;
  int32_T c5_i93;
  int32_T c5_i94;
  int32_T c5_i95;
  int32_T c5_i96;
  int32_T c5_i97;
  int32_T c5_i98;
  int32_T c5_i99;
  int32_T c5_i_loop_ub;
  int32_T c5_idx;
  int32_T c5_idx1;
  int32_T c5_idx2;
  int32_T c5_idxEdge;
  int32_T c5_idxkeep;
  int32_T c5_j_loop_ub;
  int32_T c5_k;
  int32_T c5_k_loop_ub;
  int32_T c5_l_a;
  int32_T c5_l_loop_ub;
  int32_T c5_loop_ub;
  int32_T c5_m_loop_ub;
  int32_T c5_n;
  int32_T c5_n_loop_ub;
  int32_T c5_nm1;
  int32_T c5_nm1d2;
  int32_T c5_o_loop_ub;
  int32_T c5_p_loop_ub;
  int32_T c5_q_loop_ub;
  int32_T c5_r_loop_ub;
  int32_T c5_s_b;
  int32_T c5_s_y;
  int32_T c5_sxk;
  int32_T c5_syk;
  int32_T c5_szxc;
  int32_T c5_t_b;
  int32_T c5_u_b;
  int32_T c5_w_b;
  int32_T c5_x_b;
  real32_T c5_Gmax;
  real32_T c5_b_b;
  real32_T c5_b_y;
  real32_T c5_b_z;
  real32_T c5_c_a;
  real32_T c5_c_x;
  real32_T c5_c_y;
  real32_T c5_c_z;
  real32_T c5_d_a;
  real32_T c5_d_x;
  real32_T c5_e_x;
  real32_T c5_ex;
  real32_T c5_f_x;
  real32_T c5_g_x;
  real32_T c5_kb_x;
  real32_T c5_lb_x;
  real32_T c5_mb_x;
  real32_T c5_nb_x;
  real32_T c5_o_y;
  real32_T c5_ob_x;
  real32_T c5_p_y;
  real32_T c5_pb_x;
  real32_T c5_q_y;
  real32_T c5_qb_x;
  real32_T c5_r_y;
  real32_T c5_rb_x;
  real32_T c5_t;
  real32_T c5_t_y;
  real32_T c5_u_y;
  real32_T c5_v_b;
  real32_T c5_v_y;
  real32_T c5_w_y;
  real32_T c5_x1;
  real32_T c5_x2;
  real32_T c5_y;
  real32_T c5_y_b;
  real32_T c5_z;
  boolean_T c5_b_A[19200];
  boolean_T c5_b_x[19200];
  boolean_T c5_rows_to_keep_data[19200];
  boolean_T c5_x_data[19200];
  boolean_T c5_ab_b;
  boolean_T c5_b;
  boolean_T c5_b2;
  boolean_T c5_b3;
  boolean_T c5_b4;
  boolean_T c5_b5;
  boolean_T c5_b_b1;
  boolean_T c5_b_dimagree;
  boolean_T c5_b_overflow;
  boolean_T c5_b_p;
  boolean_T c5_c_A;
  boolean_T c5_c_b;
  boolean_T c5_dimagree;
  boolean_T c5_exitg1;
  boolean_T c5_f_b;
  boolean_T c5_flat;
  boolean_T c5_g_b;
  boolean_T c5_guard1;
  boolean_T c5_guard2;
  boolean_T c5_guard3;
  boolean_T c5_h_b;
  boolean_T c5_i_b;
  boolean_T c5_l_b;
  boolean_T c5_m_b;
  boolean_T c5_n_b;
  boolean_T c5_o_b;
  boolean_T c5_overflow;
  boolean_T c5_p;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_c_st.prev = &c5_b_st;
  c5_c_st.tls = c5_b_st.tls;
  c5_d_st.prev = &c5_c_st;
  c5_d_st.tls = c5_c_st.tls;
  c5_e_st.prev = &c5_d_st;
  c5_e_st.tls = c5_d_st.tls;
  for (c5_i = 0; c5_i < 19200; c5_i++) {
    c5_b_A[c5_i] = c5_varargin_1[c5_i];
  }

  c5_st.site = &c5_ae_emlrtRSI;
  c5_b_parseInputs(chartInstance, &c5_st, c5_varargin_2_data,
                   c5_radiusRangeIn_data, c5_radiusRangeIn_size);
  c5_c_A = c5_b_A[0];
  for (c5_i1 = 0; c5_i1 < 19200; c5_i1++) {
    c5_b_x[c5_i1] = ((int32_T)c5_b_A[c5_i1] == (int32_T)c5_c_A);
  }

  for (c5_i2 = 0; c5_i2 < 19200; c5_i2++) {
    c5_x_data[c5_i2] = c5_b_x[c5_i2];
  }

  c5_flat = true;
  c5_k = 0;
  c5_exitg1 = false;
  while ((!c5_exitg1) && (c5_k < 19200)) {
    c5_b_k = (real_T)c5_k + 1.0;
    if (!c5_x_data[(int32_T)c5_b_k - 1]) {
      c5_flat = false;
      c5_exitg1 = true;
    } else {
      c5_k++;
    }
  }

  if (c5_flat) {
    for (c5_i3 = 0; c5_i3 < 19200; c5_i3++) {
      c5_c_accumMatrix[c5_i3].re = 0.0;
      c5_c_accumMatrix[c5_i3].im = 0.0;
    }

    for (c5_i5 = 0; c5_i5 < 19200; c5_i5++) {
      c5_b_gradientImg[c5_i5] = 0.0F;
    }
  } else {
    c5_st.site = &c5_be_emlrtRSI;
    for (c5_i4 = 0; c5_i4 < 19200; c5_i4++) {
      chartInstance->c5_s[c5_i4] = (real32_T)c5_b_A[c5_i4];
    }

    c5_b_st.site = &c5_me_emlrtRSI;
    c5_b_imfilter(chartInstance, &c5_b_st, chartInstance->c5_s,
                  chartInstance->c5_A);
    c5_st.site = &c5_ce_emlrtRSI;
    c5_b_st.site = &c5_ne_emlrtRSI;
    c5_c_imfilter(chartInstance, &c5_b_st, chartInstance->c5_A,
                  chartInstance->c5_Gx);
    c5_b_st.site = &c5_oe_emlrtRSI;
    c5_d_imfilter(chartInstance, &c5_b_st, chartInstance->c5_A,
                  chartInstance->c5_Gy);
    for (c5_c_k = 0; c5_c_k < 19200; c5_c_k++) {
      c5_d_k = c5_c_k;
      c5_c_x = chartInstance->c5_Gx[c5_d_k];
      c5_y = chartInstance->c5_Gy[c5_d_k];
      c5_x1 = c5_c_x;
      c5_x2 = c5_y;
      c5_c_a = c5_x1;
      c5_b_b = c5_x2;
      c5_z = muSingleScalarHypot(c5_c_a, c5_b_b);
      c5_b_gradientImg[c5_d_k] = c5_z;
    }

    c5_st.site = &c5_de_emlrtRSI;
    for (c5_i6 = 0; c5_i6 < 19200; c5_i6++) {
      chartInstance->c5_s[c5_i6] = c5_b_gradientImg[c5_i6];
    }

    c5_d_x = chartInstance->c5_s[0];
    c5_e_x = c5_d_x;
    c5_b = muSingleScalarIsNaN(c5_e_x);
    c5_p = !c5_b;
    if (c5_p) {
      c5_idx = 1;
    } else {
      c5_idx = 0;
      c5_e_k = 2;
      c5_exitg1 = false;
      while ((!c5_exitg1) && (c5_e_k < 19201)) {
        c5_f_x = chartInstance->c5_s[c5_e_k - 1];
        c5_g_x = c5_f_x;
        c5_c_b = muSingleScalarIsNaN(c5_g_x);
        c5_b_p = !c5_c_b;
        if (c5_b_p) {
          c5_idx = c5_e_k;
          c5_exitg1 = true;
        } else {
          c5_e_k++;
        }
      }
    }

    if (c5_idx == 0) {
      c5_Gmax = chartInstance->c5_s[0];
    } else {
      c5_first = c5_idx - 1;
      c5_ex = chartInstance->c5_s[c5_first];
      c5_i7 = c5_first;
      for (c5_f_k = c5_i7 + 2; c5_f_k < 19201; c5_f_k++) {
        if (c5_ex < chartInstance->c5_s[c5_f_k - 1]) {
          c5_ex = chartInstance->c5_s[c5_f_k - 1];
        }
      }

      c5_Gmax = c5_ex;
    }

    c5_b_y = c5_Gmax;
    c5_c_y = c5_b_y;
    for (c5_i8 = 0; c5_i8 < 19200; c5_i8++) {
      chartInstance->c5_s[c5_i8] = c5_b_gradientImg[c5_i8] / c5_c_y;
    }

    c5_b_st.site = &c5_pe_emlrtRSI;
    c5_edgeThresh = c5_graythresh(chartInstance, &c5_b_st, chartInstance->c5_s);
    c5_d_a = c5_Gmax;
    c5_d_b = c5_edgeThresh;
    c5_t = c5_d_a * (real32_T)c5_d_b;
    c5_b_st.site = &c5_qe_emlrtRSI;
    for (c5_i9 = 0; c5_i9 < 19200; c5_i9++) {
      c5_b_x[c5_i9] = (c5_b_gradientImg[c5_i9] > c5_t);
    }

    c5_array_int32_T_Constructor(chartInstance, &c5_ii);
    c5_array_int32_T_Constructor(chartInstance, &c5_jj);
    c5_c_st.site = &c5_ue_emlrtRSI;
    c5_eml_find(chartInstance, &c5_c_st, c5_b_x, &c5_ii, &c5_jj);
    c5_array_real_T_Constructor(chartInstance, &c5_Ey);
    c5_array_real_T_SetSize(chartInstance, &c5_b_st, &c5_Ey, &c5_db_emlrtRTEI,
      c5_ii.size[0]);
    c5_loop_ub = c5_ii.size[0] - 1;
    for (c5_i10 = 0; c5_i10 <= c5_loop_ub; c5_i10++) {
      c5_Ey.vector.data[c5_i10] = (real_T)c5_ii.vector.data[c5_i10];
    }

    c5_array_int32_T_Destructor(chartInstance, &c5_ii);
    c5_array_real_T_Constructor(chartInstance, &c5_Ex);
    c5_array_real_T_SetSize(chartInstance, &c5_b_st, &c5_Ex, &c5_eb_emlrtRTEI,
      c5_jj.size[0]);
    c5_b_loop_ub = c5_jj.size[0] - 1;
    for (c5_i11 = 0; c5_i11 <= c5_b_loop_ub; c5_i11++) {
      c5_Ex.vector.data[c5_i11] = (real_T)c5_jj.vector.data[c5_i11];
    }

    c5_array_int32_T_Destructor(chartInstance, &c5_jj);
    c5_array_real_T_Constructor(chartInstance, &c5_ndx);
    c5_st.site = &c5_ee_emlrtRSI;
    c5_b_st.site = &c5_ee_emlrtRSI;
    c5_array_real_T_SetSize(chartInstance, &c5_b_st, &c5_ndx, &c5_fb_emlrtRTEI,
      c5_Ey.size[0]);
    c5_c_loop_ub = c5_Ey.size[0] - 1;
    for (c5_i12 = 0; c5_i12 <= c5_c_loop_ub; c5_i12++) {
      c5_ndx.vector.data[c5_i12] = c5_Ey.vector.data[c5_i12];
    }

    c5_array_real_T_Constructor(chartInstance, &c5_b_varargin_2);
    c5_b_st.site = &c5_ee_emlrtRSI;
    c5_array_real_T_SetSize(chartInstance, &c5_b_st, &c5_b_varargin_2,
      &c5_gb_emlrtRTEI, c5_Ex.size[0]);
    c5_d_loop_ub = c5_Ex.size[0] - 1;
    for (c5_i13 = 0; c5_i13 <= c5_d_loop_ub; c5_i13++) {
      c5_b_varargin_2.vector.data[c5_i13] = c5_Ex.vector.data[c5_i13];
    }

    c5_array_int32_T_Constructor(chartInstance, &c5_r);
    c5_b_st.site = &c5_bf_emlrtRSI;
    c5_sub2ind(chartInstance, &c5_b_st, &c5_ndx, &c5_b_varargin_2, &c5_r);
    c5_array_real_T_Destructor(chartInstance, &c5_b_varargin_2);
    c5_array_real_T_SetSize(chartInstance, &c5_st, &c5_ndx, &c5_hb_emlrtRTEI,
      c5_r.size[0]);
    c5_e_loop_ub = c5_r.size[0] - 1;
    for (c5_i14 = 0; c5_i14 <= c5_e_loop_ub; c5_i14++) {
      c5_ndx.vector.data[c5_i14] = (real_T)c5_r.vector.data[c5_i14];
    }

    c5_array_int32_T_Destructor(chartInstance, &c5_r);
    c5_array_real_T_Constructor(chartInstance, &c5_idxE);
    c5_st.site = &c5_ee_emlrtRSI;
    c5_array_real_T_SetSize(chartInstance, &c5_st, &c5_idxE, &c5_ib_emlrtRTEI,
      c5_ndx.size[0]);
    c5_f_loop_ub = c5_ndx.size[0] - 1;
    for (c5_i15 = 0; c5_i15 <= c5_f_loop_ub; c5_i15++) {
      c5_idxE.vector.data[c5_i15] = c5_ndx.vector.data[c5_i15];
    }

    c5_array_real_T_Destructor(chartInstance, &c5_ndx);
    if ((real_T)c5_radiusRangeIn_size[1] > 1.0) {
      c5_st.site = &c5_fe_emlrtRSI;
      c5_e_a = c5_radiusRangeIn_data[0];
      c5_e_b = c5_radiusRangeIn_data[1];
      c5_h_x = c5_e_a;
      c5_f_b = muDoubleScalarIsNaN(c5_h_x);
      c5_guard1 = false;
      c5_guard2 = false;
      c5_guard3 = false;
      if (c5_f_b) {
        c5_guard2 = true;
      } else {
        c5_i_x = c5_e_b;
        c5_g_b = muDoubleScalarIsNaN(c5_i_x);
        if (c5_g_b) {
          c5_guard2 = true;
        } else if (c5_e_b < c5_e_a) {
          c5_radiusRange_size[1] = 0;
        } else {
          c5_j_x = c5_e_a;
          c5_h_b = muDoubleScalarIsInf(c5_j_x);
          if (c5_h_b) {
            c5_guard3 = true;
          } else {
            c5_k_x = c5_e_b;
            c5_i_b = muDoubleScalarIsInf(c5_k_x);
            if (c5_i_b) {
              c5_guard3 = true;
            } else {
              c5_guard1 = true;
            }
          }
        }
      }

      if (c5_guard3) {
        if (c5_e_a == c5_e_b) {
          c5_radiusRange_size[1] = 1;
          c5_radiusRange_data[0] = rtNaN;
        } else {
          c5_guard1 = true;
        }
      }

      if (c5_guard2) {
        c5_radiusRange_size[1] = 1;
        c5_radiusRange_data[0] = rtNaN;
      }

      if (c5_guard1) {
        c5_b_st.site = &c5_cf_emlrtRSI;
        c5_eml_float_colon(chartInstance, &c5_b_st, c5_e_a, c5_e_b,
                           c5_radiusRange_data, c5_radiusRange_size);
      }
    } else {
      c5_radiusRange_size[1] = 1;
      c5_radiusRange_data[0] = c5_radiusRangeIn_data[0];
    }

    if ((real_T)c5_radiusRange_size[1] > 1.0) {
      c5_lnR_size[0] = 1;
      c5_lnR_size[1] = c5_radiusRange_size[1];
      c5_g_loop_ub = c5_radiusRange_size[1] - 1;
      for (c5_i16 = 0; c5_i16 <= c5_g_loop_ub; c5_i16++) {
        c5_lnR_data[c5_i16] = c5_radiusRange_data[c5_i16];
      }

      c5_st.site = &c5_ge_emlrtRSI;
      c5_b_log(chartInstance, &c5_st, c5_lnR_data, c5_lnR_size);
      c5_lnR = c5_lnR_data[0];
      c5_b_lnR = (real_T)c5_lnR_size[1];
      c5_c_lnR = c5_lnR_size[1];
      c5_i19 = (int32_T)c5_b_lnR;
      if ((c5_i19 < 1) || (c5_i19 > c5_c_lnR)) {
        emlrtDynamicBoundsCheckR2012b(c5_i19, 1, c5_c_lnR, &c5_n_emlrtBCI,
          (emlrtConstCTX)c5_sp);
      }

      c5_d_lnR = c5_lnR_data[c5_i19 - 1];
      c5_e_lnR = c5_lnR_data[0];
      c5_f_lnR = c5_d_lnR - c5_e_lnR;
      c5_i21 = c5_lnR_size[1];
      c5_j_loop_ub = c5_i21 - 1;
      for (c5_i22 = 0; c5_i22 <= c5_j_loop_ub; c5_i22++) {
        c5_lnR_data[c5_i22] = (c5_lnR_data[c5_i22] - c5_lnR) / c5_f_lnR;
      }

      c5_i23 = c5_lnR_size[1];
      c5_i24 = c5_i23;
      c5_k_loop_ub = c5_i24 - 1;
      for (c5_i25 = 0; c5_i25 <= c5_k_loop_ub; c5_i25++) {
        c5_lnR_data[c5_i25] *= 2.0;
      }

      c5_i27 = c5_lnR_size[1];
      c5_i28 = c5_i27;
      c5_m_loop_ub = c5_i28 - 1;
      for (c5_i29 = 0; c5_i29 <= c5_m_loop_ub; c5_i29++) {
        c5_lnR_data[c5_i29] *= 3.1415926535897931;
      }

      c5_i31 = c5_lnR_size[1];
      c5_lnR_size[0] = 1;
      c5_i32 = c5_i31;
      c5_o_loop_ub = c5_i32 - 1;
      for (c5_i33 = 0; c5_i33 <= c5_o_loop_ub; c5_i33++) {
        c5_lnR_data[c5_i33] -= 3.1415926535897931;
      }
    } else {
      c5_lnR_size[0] = 1;
      c5_lnR_size[1] = 1;
      c5_lnR_data[0] = 0.0;
    }

    for (c5_i17 = 0; c5_i17 < 2; c5_i17++) {
      c5_b_dv[c5_i17] = (real_T)c5_lnR_size[c5_i17];
    }

    c5_Opca_size[0] = 1;
    c5_Opca_size[1] = (int32_T)c5_b_dv[1];
    c5_tmp_size[0] = c5_Opca_size[1];
    c5_h_loop_ub = c5_Opca_size[1] - 1;
    for (c5_i18 = 0; c5_i18 <= c5_h_loop_ub; c5_i18++) {
      c5_tmp_data[c5_i18] = c5_i18;
    }

    c5_y_size[0] = 1;
    c5_y_size[1] = c5_lnR_size[1];
    c5_i_loop_ub = c5_lnR_size[1] - 1;
    for (c5_i20 = 0; c5_i20 <= c5_i_loop_ub; c5_i20++) {
      c5_y_data[c5_i20].re = c5_lnR_data[c5_i20] * c5_b_dc.re;
      c5_y_data[c5_i20].im = c5_lnR_data[c5_i20] * c5_b_dc.im;
    }

    c5_st.site = &c5_he_emlrtRSI;
    c5_b_exp(chartInstance, &c5_st, c5_y_data, c5_y_size);
    c5_b_iv[0] = 1;
    c5_b_iv[1] = c5_tmp_size[0];
    emlrtSubAssignSizeCheckR2012b(&c5_b_iv[0], 2, &c5_y_size[0], 2, &c5_emlrtECI,
      (void *)c5_sp);
    c5_b_iv1[1] = c5_tmp_size[0];
    c5_l_loop_ub = c5_b_iv1[1] - 1;
    for (c5_i26 = 0; c5_i26 <= c5_l_loop_ub; c5_i26++) {
      c5_Opca_data[c5_tmp_data[c5_i26]] = c5_y_data[c5_i26];
    }

    c5_lnR_size[0] = 1;
    c5_lnR_size[1] = c5_radiusRange_size[1];
    c5_n_loop_ub = c5_radiusRange_size[1] - 1;
    for (c5_i30 = 0; c5_i30 <= c5_n_loop_ub; c5_i30++) {
      c5_lnR_data[c5_i30] = 6.2831853071795862 * c5_radiusRange_data[c5_i30];
    }

    c5_st.site = &c5_ie_emlrtRSI;
    c5_b_st.site = &c5_hf_emlrtRSI;
    c5_c_st.site = &c5_if_emlrtRSI;
    c5_sxk = c5_Opca_size[1];
    c5_syk = c5_lnR_size[1];
    if ((c5_sxk == 1) || (c5_syk == 1) || (c5_sxk == c5_syk)) {
      c5_dimagree = true;
    } else {
      c5_dimagree = false;
    }

    c5_b_dimagree = c5_dimagree;
    if (!c5_b_dimagree) {
      c5_d_y = NULL;
      sf_mex_assign(&c5_d_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1, 30),
                    false);
      c5_e_y = NULL;
      sf_mex_assign(&c5_e_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1, 30),
                    false);
      sf_mex_call(&c5_c_st, &c5_t_emlrtMCI, "error", 0U, 2U, 14, c5_d_y, 14,
                  sf_mex_call(&c5_c_st, NULL, "getString", 1U, 1U, 14,
        sf_mex_call(&c5_c_st, NULL, "message", 1U, 1U, 14, c5_e_y)));
    }

    if (c5_Opca_size[1] == c5_lnR_size[1]) {
      c5_i34 = c5_Opca_size[1];
      c5_p_loop_ub = c5_i34 - 1;
      for (c5_i35 = 0; c5_i35 <= c5_p_loop_ub; c5_i35++) {
        c5_ar = c5_Opca_data[c5_i35].re;
        c5_ai = c5_Opca_data[c5_i35].im;
        c5_br = c5_lnR_data[c5_i35];
        c5_bi = 0.0;
        if (c5_bi == 0.0) {
          if (c5_ai == 0.0) {
            c5_dc1.re = c5_ar / c5_br;
            c5_dc1.im = 0.0;
          } else if (c5_ar == 0.0) {
            c5_dc1.re = 0.0;
            c5_dc1.im = c5_ai / c5_br;
          } else {
            c5_dc1.re = c5_ar / c5_br;
            c5_dc1.im = c5_ai / c5_br;
          }
        } else if (c5_br == 0.0) {
          if (c5_ar == 0.0) {
            c5_dc1.re = c5_ai / c5_bi;
            c5_dc1.im = 0.0;
          } else if (c5_ai == 0.0) {
            c5_dc1.re = 0.0;
            c5_dc1.im = -(c5_ar / c5_bi);
          } else {
            c5_dc1.re = c5_ai / c5_bi;
            c5_dc1.im = -(c5_ar / c5_bi);
          }
        } else {
          c5_brm = muDoubleScalarAbs(c5_br);
          c5_bim = muDoubleScalarAbs(c5_bi);
          if (c5_brm > c5_bim) {
            c5_b_s = c5_bi / c5_br;
            c5_d = c5_br + c5_b_s * c5_bi;
            c5_nr = c5_ar + c5_b_s * c5_ai;
            c5_ni = c5_ai - c5_b_s * c5_ar;
            c5_dc1.re = c5_nr / c5_d;
            c5_dc1.im = c5_ni / c5_d;
          } else if (c5_bim == c5_brm) {
            if (c5_br > 0.0) {
              c5_sgnbr = 0.5;
            } else {
              c5_sgnbr = -0.5;
            }

            if (c5_bi > 0.0) {
              c5_sgnbi = 0.5;
            } else {
              c5_sgnbi = -0.5;
            }

            c5_nr = c5_ar * c5_sgnbr + c5_ai * c5_sgnbi;
            c5_ni = c5_ai * c5_sgnbr - c5_ar * c5_sgnbi;
            c5_dc1.re = c5_nr / c5_brm;
            c5_dc1.im = c5_ni / c5_brm;
          } else {
            c5_b_s = c5_br / c5_bi;
            c5_d = c5_bi + c5_b_s * c5_br;
            c5_nr = c5_b_s * c5_ar + c5_ai;
            c5_ni = c5_b_s * c5_ai - c5_ar;
            c5_dc1.re = c5_nr / c5_d;
            c5_dc1.im = c5_ni / c5_d;
          }
        }

        c5_Opca_data[c5_i35] = c5_dc1;
      }
    } else {
      c5_binary_expand_op(chartInstance, c5_Opca_data, c5_Opca_size, c5_lnR_data,
                          c5_lnR_size);
    }

    c5_l_x = 1.0E+6 / (real_T)c5_radiusRange_size[1];
    c5_m_x = c5_l_x;
    c5_xcStep = c5_m_x;
    c5_xcStep = muDoubleScalarFloor(c5_xcStep);
    c5_lenE = (real_T)c5_Ex.size[0];
    for (c5_i36 = 0; c5_i36 < 19200; c5_i36++) {
      c5_c_accumMatrix[c5_i36].re = 0.0;
      c5_c_accumMatrix[c5_i36].im = 0.0;
    }

    c5_i37 = (int32_T)((c5_lenE + (c5_xcStep - 1.0)) / c5_xcStep);
    emlrtForLoopVectorCheckR2021a(1.0, c5_xcStep, c5_lenE, mxDOUBLE_CLASS,
      c5_i37, &c5_yh_emlrtRTEI, (emlrtConstCTX)c5_sp);
    c5_array_real_T_Constructor(chartInstance, &c5_Ex_chunk);
    c5_array_real_T_Constructor(chartInstance, &c5_Ey_chunk);
    c5_array_real_T_Constructor(chartInstance, &c5_idxE_chunk);
    c5_array_real32_T_2D_Constructor(chartInstance, &c5_xc);
    c5_array_real32_T_2D_Constructor(chartInstance, &c5_yc);
    c5_array_creal_T_2D_Constructor(chartInstance, &c5_w);
    c5_array_boolean_T_2D_Constructor(chartInstance, &c5_inside);
    c5_array_int32_T_Constructor(chartInstance, &c5_xckeep);
    c5_array_int32_T_Constructor(chartInstance, &c5_yckeep);
    c5_array_creal_T_Constructor(chartInstance, &c5_wkeep);
    c5_array_real_T_2D_Constructor(chartInstance, &c5_r1);
    for (c5_b_i = 0; c5_b_i < c5_i37; c5_b_i++) {
      c5_c_i = (real_T)c5_b_i * c5_xcStep + 1.0;
      c5_b_varargin_1 = (c5_c_i + c5_xcStep) - 1.0;
      c5_c_varargin_2 = c5_lenE;
      c5_n_x = c5_b_varargin_1;
      c5_f_y = c5_c_varargin_2;
      c5_o_x = c5_n_x;
      c5_g_y = c5_f_y;
      c5_p_x = c5_o_x;
      c5_h_y = c5_g_y;
      c5_f_a = c5_p_x;
      c5_j_b = c5_h_y;
      c5_q_x = c5_f_a;
      c5_i_y = c5_j_b;
      c5_r_x = c5_q_x;
      c5_j_y = c5_i_y;
      c5_minval = muDoubleScalarMin(c5_r_x, c5_j_y);
      c5_st.site = &c5_je_emlrtRSI;
      c5_g_a = c5_c_i;
      c5_b_d = c5_minval;
      c5_b_st.site = &c5_of_emlrtRSI;
      c5_h_a = c5_g_a;
      c5_k_b = c5_b_d;
      c5_s_x = c5_h_a;
      c5_l_b = muDoubleScalarIsNaN(c5_s_x);
      c5_guard1 = false;
      c5_guard2 = false;
      c5_guard3 = false;
      if (c5_l_b) {
        c5_guard2 = true;
      } else {
        c5_t_x = c5_k_b;
        c5_m_b = muDoubleScalarIsNaN(c5_t_x);
        if (c5_m_b) {
          c5_guard2 = true;
        } else if (c5_k_b < c5_h_a) {
          c5_array_real_T_2D_SetSize(chartInstance, &c5_b_st, &c5_r1,
            &c5_tb_emlrtRTEI, 1, 0);
        } else {
          c5_u_x = c5_h_a;
          c5_n_b = muDoubleScalarIsInf(c5_u_x);
          if (c5_n_b) {
            c5_guard3 = true;
          } else {
            c5_v_x = c5_k_b;
            c5_o_b = muDoubleScalarIsInf(c5_v_x);
            if (c5_o_b) {
              c5_guard3 = true;
            } else {
              c5_guard1 = true;
            }
          }
        }
      }

      if (c5_guard3) {
        if (c5_h_a == c5_k_b) {
          c5_array_real_T_2D_SetSize(chartInstance, &c5_b_st, &c5_r1,
            &c5_tb_emlrtRTEI, 1, 1);
          c5_r1.vector.data[0] = rtNaN;
        } else {
          c5_guard1 = true;
        }
      }

      if (c5_guard2) {
        c5_array_real_T_2D_SetSize(chartInstance, &c5_b_st, &c5_r1,
          &c5_tb_emlrtRTEI, 1, 1);
        c5_r1.vector.data[0] = rtNaN;
      }

      if (c5_guard1) {
        c5_w_x = c5_h_a;
        c5_x_x = c5_w_x;
        c5_k_y = c5_x_x;
        c5_k_y = muDoubleScalarFloor(c5_k_y);
        if (c5_k_y == c5_h_a) {
          c5_array_real_T_2D_SetSize(chartInstance, &c5_b_st, &c5_r1,
            &c5_tb_emlrtRTEI, 1, (int32_T)(c5_k_b - c5_h_a) + 1);
          c5_q_loop_ub = (int32_T)(c5_k_b - c5_h_a);
          for (c5_i38 = 0; c5_i38 <= c5_q_loop_ub; c5_i38++) {
            c5_r1.vector.data[c5_i38] = c5_h_a + (real_T)c5_i38;
          }
        } else {
          c5_c_st.site = &c5_cf_emlrtRSI;
          c5_i_a = c5_h_a;
          c5_p_b = c5_k_b;
          c5_j_a = c5_i_a;
          c5_q_b = c5_p_b;
          c5_a1 = c5_j_a;
          c5_y_x = (c5_q_b - c5_j_a) + 0.5;
          c5_ab_x = c5_y_x;
          c5_ndbl = c5_ab_x;
          c5_ndbl = muDoubleScalarFloor(c5_ndbl);
          c5_apnd = c5_j_a + c5_ndbl;
          c5_cdiff = c5_apnd - c5_q_b;
          c5_k_a = c5_j_a;
          c5_r_b = c5_q_b;
          c5_bb_x = c5_k_a;
          c5_cb_x = c5_bb_x;
          c5_db_x = c5_cb_x;
          c5_l_y = muDoubleScalarAbs(c5_db_x);
          c5_eb_x = c5_r_b;
          c5_fb_x = c5_eb_x;
          c5_gb_x = c5_fb_x;
          c5_m_y = muDoubleScalarAbs(c5_gb_x);
          c5_c = muDoubleScalarMax(c5_l_y, c5_m_y);
          c5_thresh = 4.4408920985006262E-16 * c5_c;
          c5_hb_x = c5_cdiff;
          c5_ib_x = c5_hb_x;
          c5_jb_x = c5_ib_x;
          c5_n_y = muDoubleScalarAbs(c5_jb_x);
          if (c5_n_y < c5_thresh) {
            c5_ndbl++;
            c5_b1 = c5_q_b;
          } else if (c5_cdiff > 0.0) {
            c5_b1 = c5_j_a + (c5_ndbl - 1.0);
          } else {
            c5_ndbl++;
            c5_b1 = c5_apnd;
          }

          if (c5_ndbl >= 0.0) {
            c5_n = (int32_T)muDoubleScalarFloor(c5_ndbl);
          } else {
            c5_n = 0;
          }

          c5_array_real_T_2D_SetSize(chartInstance, &c5_c_st, &c5_r1,
            &c5_sb_emlrtRTEI, 1, c5_n);
          if (c5_n > 0) {
            c5_r1.vector.data[0] = c5_a1;
            if (c5_n > 1) {
              c5_r1.vector.data[c5_n - 1] = c5_b1;
              c5_nm1 = c5_n - 1;
              c5_l_a = c5_nm1;
              c5_nm1d2 = (uint16_T)((uint32_T)(uint16_T)c5_l_a >> 1);
              c5_i61 = c5_nm1d2 - 2;
              c5_d_st.site = &c5_df_emlrtRSI;
              c5_u_b = c5_i61 + 1;
              c5_w_b = c5_u_b;
              if (c5_w_b < 1) {
                c5_b_overflow = false;
              } else {
                c5_b_overflow = (c5_w_b > 2147483646);
              }

              if (c5_b_overflow) {
                c5_e_st.site = &c5_v_emlrtRSI;
                c5_check_forloop_overflow_error(chartInstance, &c5_e_st);
              }

              for (c5_g_k = 0; c5_g_k <= c5_i61; c5_g_k++) {
                c5_h_k = c5_g_k + 1;
                c5_kd = (real_T)c5_h_k;
                c5_r1.vector.data[c5_h_k] = c5_a1 + c5_kd;
                c5_r1.vector.data[(c5_n - c5_h_k) - 1] = c5_b1 - c5_kd;
              }

              c5_x_b = c5_nm1d2;
              c5_s_y = c5_x_b << 1;
              if (c5_s_y == c5_nm1) {
                c5_r1.vector.data[c5_nm1d2] = (c5_a1 + c5_b1) / 2.0;
              } else {
                c5_kd = (real_T)c5_nm1d2;
                c5_r1.vector.data[c5_nm1d2] = c5_a1 + c5_kd;
                c5_r1.vector.data[c5_nm1d2 + 1] = c5_b1 - c5_kd;
              }
            }
          }
        }
      }

      c5_sizeChunk = (real_T)c5_r1.size[1];
      c5_st.site = &c5_gl_emlrtRSI;
      c5_array_real_T_SetSize(chartInstance, &c5_st, &c5_Ex_chunk,
        &c5_ub_emlrtRTEI, (int32_T)c5_sizeChunk);
      c5_st.site = &c5_fl_emlrtRSI;
      c5_array_real_T_SetSize(chartInstance, &c5_st, &c5_Ey_chunk,
        &c5_vb_emlrtRTEI, (int32_T)c5_sizeChunk);
      c5_st.site = &c5_el_emlrtRSI;
      c5_array_real_T_SetSize(chartInstance, &c5_st, &c5_idxE_chunk,
        &c5_wb_emlrtRTEI, (int32_T)c5_sizeChunk);
      c5_idxEdge = (int32_T)c5_c_i;
      c5_i39 = (int32_T)c5_sizeChunk - 1;
      for (c5_b_idx = 0; c5_b_idx <= c5_i39; c5_b_idx++) {
        c5_c_idx = (real_T)c5_b_idx + 1.0;
        c5_i40 = c5_Ex.size[0];
        if ((c5_idxEdge < 1) || (c5_idxEdge > c5_i40)) {
          emlrtDynamicBoundsCheckR2012b(c5_idxEdge, 1, c5_i40, &c5_o_emlrtBCI,
            (emlrtConstCTX)c5_sp);
        }

        c5_i41 = c5_Ex_chunk.size[0];
        c5_i42 = (int32_T)c5_c_idx;
        if ((c5_i42 < 1) || (c5_i42 > c5_i41)) {
          emlrtDynamicBoundsCheckR2012b(c5_i42, 1, c5_i41, &c5_p_emlrtBCI,
            (emlrtConstCTX)c5_sp);
        }

        c5_Ex_chunk.vector.data[c5_i42 - 1] = c5_Ex.vector.data[c5_idxEdge - 1];
        c5_i43 = c5_Ey.size[0];
        if ((c5_idxEdge < 1) || (c5_idxEdge > c5_i43)) {
          emlrtDynamicBoundsCheckR2012b(c5_idxEdge, 1, c5_i43, &c5_q_emlrtBCI,
            (emlrtConstCTX)c5_sp);
        }

        c5_i45 = c5_Ey_chunk.size[0];
        c5_i46 = (int32_T)c5_c_idx;
        if ((c5_i46 < 1) || (c5_i46 > c5_i45)) {
          emlrtDynamicBoundsCheckR2012b(c5_i46, 1, c5_i45, &c5_r_emlrtBCI,
            (emlrtConstCTX)c5_sp);
        }

        c5_Ey_chunk.vector.data[c5_i46 - 1] = c5_Ey.vector.data[c5_idxEdge - 1];
        c5_i48 = c5_idxE.size[0];
        if ((c5_idxEdge < 1) || (c5_idxEdge > c5_i48)) {
          emlrtDynamicBoundsCheckR2012b(c5_idxEdge, 1, c5_i48, &c5_s_emlrtBCI,
            (emlrtConstCTX)c5_sp);
        }

        c5_i50 = c5_idxE_chunk.size[0];
        c5_i51 = (int32_T)c5_c_idx;
        if ((c5_i51 < 1) || (c5_i51 > c5_i50)) {
          emlrtDynamicBoundsCheckR2012b(c5_i51, 1, c5_i50, &c5_t_emlrtBCI,
            (emlrtConstCTX)c5_sp);
        }

        c5_idxE_chunk.vector.data[c5_i51 - 1] = c5_idxE.vector.data[c5_idxEdge -
          1];
        c5_idxEdge++;
      }

      c5_dim1 = (real_T)c5_idxE_chunk.size[0];
      c5_dim2 = (real_T)c5_radiusRange_size[1];
      c5_st.site = &c5_il_emlrtRSI;
      c5_array_real32_T_2D_SetSize(chartInstance, &c5_st, &c5_xc,
        &c5_xb_emlrtRTEI, (int32_T)c5_dim1, (int32_T)c5_dim2);
      c5_st.site = &c5_hl_emlrtRSI;
      c5_array_real32_T_2D_SetSize(chartInstance, &c5_st, &c5_yc,
        &c5_yb_emlrtRTEI, (int32_T)c5_dim1, (int32_T)c5_dim2);
      c5_st.site = &c5_jl_emlrtRSI;
      c5_array_creal_T_2D_SetSize(chartInstance, &c5_st, &c5_w, &c5_ac_emlrtRTEI,
        (int32_T)c5_dim1, (int32_T)c5_dim2);
      c5_st.site = &c5_xk_emlrtRSI;
      c5_array_boolean_T_2D_SetSize(chartInstance, &c5_st, &c5_inside,
        &c5_bc_emlrtRTEI, (int32_T)c5_dim1, (int32_T)c5_dim2);
      c5_rows_to_keep_size[0] = (int32_T)c5_dim1;
      c5_r_loop_ub = (int32_T)c5_dim1 - 1;
      for (c5_i44 = 0; c5_i44 <= c5_r_loop_ub; c5_i44++) {
        c5_rows_to_keep_data[c5_i44] = false;
      }

      c5_i47 = (int32_T)c5_dim2 - 1;
      for (c5_idx2 = 0; c5_idx2 <= c5_i47; c5_idx2++) {
        c5_b_idx2 = (real_T)c5_idx2 + 1.0;
        c5_i49 = (int32_T)c5_dim1 - 1;
        for (c5_idx1 = 0; c5_idx1 <= c5_i49; c5_idx1++) {
          c5_b_idx1 = (real_T)c5_idx1 + 1.0;
          c5_i52 = c5_idxE_chunk.size[0];
          c5_i53 = (int32_T)c5_b_idx1;
          if ((c5_i53 < 1) || (c5_i53 > c5_i52)) {
            emlrtDynamicBoundsCheckR2012b(c5_i53, 1, c5_i52, &c5_u_emlrtBCI,
              (emlrtConstCTX)c5_sp);
          }

          c5_kb_x = chartInstance->c5_Gx[(int32_T)
            c5_idxE_chunk.vector.data[c5_i53 - 1] - 1];
          c5_i55 = c5_idxE_chunk.size[0];
          c5_i56 = (int32_T)c5_b_idx1;
          if ((c5_i56 < 1) || (c5_i56 > c5_i55)) {
            emlrtDynamicBoundsCheckR2012b(c5_i56, 1, c5_i55, &c5_v_emlrtBCI,
              (emlrtConstCTX)c5_sp);
          }

          c5_o_y = c5_b_gradientImg[(int32_T)c5_idxE_chunk.vector.data[c5_i56 -
            1] - 1];
          c5_lb_x = c5_kb_x;
          c5_p_y = c5_o_y;
          c5_b_z = c5_lb_x / c5_p_y;
          c5_i60 = (int32_T)c5_b_idx2;
          if ((c5_i60 < 1) || (c5_i60 > c5_radiusRange_size[1])) {
            emlrtDynamicBoundsCheckR2012b(c5_i60, 1, c5_radiusRange_size[1],
              &c5_w_emlrtBCI, (emlrtConstCTX)c5_sp);
          }

          c5_m_a = -c5_radiusRange_data[c5_i60 - 1];
          c5_v_b = c5_b_z;
          c5_q_y = (real32_T)c5_m_a * c5_v_b;
          c5_i64 = c5_Ex_chunk.size[0];
          c5_i66 = (int32_T)c5_b_idx1;
          if ((c5_i66 < 1) || (c5_i66 > c5_i64)) {
            emlrtDynamicBoundsCheckR2012b(c5_i66, 1, c5_i64, &c5_x_emlrtBCI,
              (emlrtConstCTX)c5_sp);
          }

          c5_mb_x = (real32_T)c5_Ex_chunk.vector.data[c5_i66 - 1] + c5_q_y;
          c5_nb_x = c5_mb_x;
          c5_r_y = c5_nb_x;
          c5_r_y = muSingleScalarRound(c5_r_y);
          c5_i73 = c5_xc.size[0];
          c5_i75 = (int32_T)c5_b_idx1;
          if ((c5_i75 < 1) || (c5_i75 > c5_i73)) {
            emlrtDynamicBoundsCheckR2012b(c5_i75, 1, c5_i73, &c5_ab_emlrtBCI,
              (emlrtConstCTX)c5_sp);
          }

          c5_i79 = c5_xc.size[1];
          c5_i80 = (int32_T)c5_b_idx2;
          if ((c5_i80 < 1) || (c5_i80 > c5_i79)) {
            emlrtDynamicBoundsCheckR2012b(c5_i80, 1, c5_i79, &c5_bb_emlrtBCI,
              (emlrtConstCTX)c5_sp);
          }

          c5_xc.vector.data[(c5_i75 + c5_xc.size[0] * (c5_i80 - 1)) - 1] =
            c5_r_y;
          c5_i83 = c5_idxE_chunk.size[0];
          c5_i85 = (int32_T)c5_b_idx1;
          if ((c5_i85 < 1) || (c5_i85 > c5_i83)) {
            emlrtDynamicBoundsCheckR2012b(c5_i85, 1, c5_i83, &c5_eb_emlrtBCI,
              (emlrtConstCTX)c5_sp);
          }

          c5_ob_x = chartInstance->c5_Gy[(int32_T)
            c5_idxE_chunk.vector.data[c5_i85 - 1] - 1];
          c5_i89 = c5_idxE_chunk.size[0];
          c5_i91 = (int32_T)c5_b_idx1;
          if ((c5_i91 < 1) || (c5_i91 > c5_i89)) {
            emlrtDynamicBoundsCheckR2012b(c5_i91, 1, c5_i89, &c5_fb_emlrtBCI,
              (emlrtConstCTX)c5_sp);
          }

          c5_t_y = c5_b_gradientImg[(int32_T)c5_idxE_chunk.vector.data[c5_i91 -
            1] - 1];
          c5_pb_x = c5_ob_x;
          c5_u_y = c5_t_y;
          c5_c_z = c5_pb_x / c5_u_y;
          c5_i96 = (int32_T)c5_b_idx2;
          if ((c5_i96 < 1) || (c5_i96 > c5_radiusRange_size[1])) {
            emlrtDynamicBoundsCheckR2012b(c5_i96, 1, c5_radiusRange_size[1],
              &c5_mb_emlrtBCI, (emlrtConstCTX)c5_sp);
          }

          c5_n_a = -c5_radiusRange_data[c5_i96 - 1];
          c5_y_b = c5_c_z;
          c5_v_y = (real32_T)c5_n_a * c5_y_b;
          c5_i102 = c5_Ey_chunk.size[0];
          c5_i104 = (int32_T)c5_b_idx1;
          if ((c5_i104 < 1) || (c5_i104 > c5_i102)) {
            emlrtDynamicBoundsCheckR2012b(c5_i104, 1, c5_i102, &c5_qb_emlrtBCI,
              (emlrtConstCTX)c5_sp);
          }

          c5_qb_x = (real32_T)c5_Ey_chunk.vector.data[c5_i104 - 1] + c5_v_y;
          c5_rb_x = c5_qb_x;
          c5_w_y = c5_rb_x;
          c5_w_y = muSingleScalarRound(c5_w_y);
          c5_i111 = c5_yc.size[0];
          c5_i112 = (int32_T)c5_b_idx1;
          if ((c5_i112 < 1) || (c5_i112 > c5_i111)) {
            emlrtDynamicBoundsCheckR2012b(c5_i112, 1, c5_i111, &c5_bc_emlrtBCI,
              (emlrtConstCTX)c5_sp);
          }

          c5_i116 = c5_yc.size[1];
          c5_i118 = (int32_T)c5_b_idx2;
          if ((c5_i118 < 1) || (c5_i118 > c5_i116)) {
            emlrtDynamicBoundsCheckR2012b(c5_i118, 1, c5_i116, &c5_cc_emlrtBCI,
              (emlrtConstCTX)c5_sp);
          }

          c5_yc.vector.data[(c5_i112 + c5_yc.size[0] * (c5_i118 - 1)) - 1] =
            c5_w_y;
          c5_i121 = c5_w.size[0];
          c5_i122 = (int32_T)c5_b_idx1;
          if ((c5_i122 < 1) || (c5_i122 > c5_i121)) {
            emlrtDynamicBoundsCheckR2012b(c5_i122, 1, c5_i121, &c5_ec_emlrtBCI,
              (emlrtConstCTX)c5_sp);
          }

          c5_i124 = c5_w.size[1];
          c5_i125 = (int32_T)c5_b_idx2;
          if ((c5_i125 < 1) || (c5_i125 > c5_i124)) {
            emlrtDynamicBoundsCheckR2012b(c5_i125, 1, c5_i124, &c5_fc_emlrtBCI,
              (emlrtConstCTX)c5_sp);
          }

          c5_i126 = (int32_T)c5_b_idx2;
          if ((c5_i126 < 1) || (c5_i126 > c5_Opca_size[1])) {
            emlrtDynamicBoundsCheckR2012b(c5_i126, 1, c5_Opca_size[1],
              &c5_dc_emlrtBCI, (emlrtConstCTX)c5_sp);
          }

          c5_w.vector.data[(c5_i122 + c5_w.size[0] * (c5_i125 - 1)) - 1].re =
            c5_Opca_data[c5_i126 - 1].re;
          c5_i127 = (int32_T)c5_b_idx2;
          if ((c5_i127 < 1) || (c5_i127 > c5_Opca_size[1])) {
            emlrtDynamicBoundsCheckR2012b(c5_i127, 1, c5_Opca_size[1],
              &c5_dc_emlrtBCI, (emlrtConstCTX)c5_sp);
          }

          c5_i128 = c5_w.size[0];
          c5_i129 = (int32_T)c5_b_idx1;
          if ((c5_i129 < 1) || (c5_i129 > c5_i128)) {
            emlrtDynamicBoundsCheckR2012b(c5_i129, 1, c5_i128, &c5_ec_emlrtBCI,
              (emlrtConstCTX)c5_sp);
          }

          c5_i130 = c5_w.size[1];
          c5_i131 = (int32_T)c5_b_idx2;
          if ((c5_i131 < 1) || (c5_i131 > c5_i130)) {
            emlrtDynamicBoundsCheckR2012b(c5_i131, 1, c5_i130, &c5_fc_emlrtBCI,
              (emlrtConstCTX)c5_sp);
          }

          c5_w.vector.data[(c5_i129 + c5_w.size[0] * (c5_i131 - 1)) - 1].im =
            c5_Opca_data[c5_i127 - 1].im;
          c5_i132 = c5_xc.size[0];
          c5_i133 = (int32_T)c5_b_idx1;
          if ((c5_i133 < 1) || (c5_i133 > c5_i132)) {
            emlrtDynamicBoundsCheckR2012b(c5_i133, 1, c5_i132, &c5_gc_emlrtBCI,
              (emlrtConstCTX)c5_sp);
          }

          c5_i134 = c5_xc.size[1];
          c5_i135 = (int32_T)c5_b_idx2;
          if ((c5_i135 < 1) || (c5_i135 > c5_i134)) {
            emlrtDynamicBoundsCheckR2012b(c5_i135, 1, c5_i134, &c5_hc_emlrtBCI,
              (emlrtConstCTX)c5_sp);
          }

          c5_ab_b = (c5_xc.vector.data[(c5_i133 + c5_xc.size[0] * (c5_i135 - 1))
                     - 1] >= 1.0F);
          c5_i136 = c5_xc.size[0];
          c5_i137 = (int32_T)c5_b_idx1;
          if ((c5_i137 < 1) || (c5_i137 > c5_i136)) {
            emlrtDynamicBoundsCheckR2012b(c5_i137, 1, c5_i136, &c5_ic_emlrtBCI,
              (emlrtConstCTX)c5_sp);
          }

          c5_i138 = c5_xc.size[1];
          c5_i139 = (int32_T)c5_b_idx2;
          if ((c5_i139 < 1) || (c5_i139 > c5_i138)) {
            emlrtDynamicBoundsCheckR2012b(c5_i139, 1, c5_i138, &c5_jc_emlrtBCI,
              (emlrtConstCTX)c5_sp);
          }

          c5_b_b1 = (c5_xc.vector.data[(c5_i137 + c5_xc.size[0] * (c5_i139 - 1))
                     - 1] <= 160.0F);
          c5_b2 = (c5_ab_b && c5_b_b1);
          c5_i140 = c5_yc.size[0];
          c5_i141 = (int32_T)c5_b_idx1;
          if ((c5_i141 < 1) || (c5_i141 > c5_i140)) {
            emlrtDynamicBoundsCheckR2012b(c5_i141, 1, c5_i140, &c5_kc_emlrtBCI,
              (emlrtConstCTX)c5_sp);
          }

          c5_i142 = c5_yc.size[1];
          c5_i143 = (int32_T)c5_b_idx2;
          if ((c5_i143 < 1) || (c5_i143 > c5_i142)) {
            emlrtDynamicBoundsCheckR2012b(c5_i143, 1, c5_i142, &c5_lc_emlrtBCI,
              (emlrtConstCTX)c5_sp);
          }

          c5_b3 = (c5_yc.vector.data[(c5_i141 + c5_yc.size[0] * (c5_i143 - 1)) -
                   1] >= 1.0F);
          c5_b4 = (c5_b2 && c5_b3);
          c5_i144 = c5_yc.size[0];
          c5_i145 = (int32_T)c5_b_idx1;
          if ((c5_i145 < 1) || (c5_i145 > c5_i144)) {
            emlrtDynamicBoundsCheckR2012b(c5_i145, 1, c5_i144, &c5_mc_emlrtBCI,
              (emlrtConstCTX)c5_sp);
          }

          c5_i146 = c5_yc.size[1];
          c5_i147 = (int32_T)c5_b_idx2;
          if ((c5_i147 < 1) || (c5_i147 > c5_i146)) {
            emlrtDynamicBoundsCheckR2012b(c5_i147, 1, c5_i146, &c5_nc_emlrtBCI,
              (emlrtConstCTX)c5_sp);
          }

          c5_b5 = (c5_yc.vector.data[(c5_i145 + c5_yc.size[0] * (c5_i147 - 1)) -
                   1] <= 120.0F);
          c5_i148 = c5_inside.size[0];
          c5_i149 = (int32_T)c5_b_idx1;
          if ((c5_i149 < 1) || (c5_i149 > c5_i148)) {
            emlrtDynamicBoundsCheckR2012b(c5_i149, 1, c5_i148, &c5_oc_emlrtBCI,
              (emlrtConstCTX)c5_sp);
          }

          c5_i150 = c5_inside.size[1];
          c5_i151 = (int32_T)c5_b_idx2;
          if ((c5_i151 < 1) || (c5_i151 > c5_i150)) {
            emlrtDynamicBoundsCheckR2012b(c5_i151, 1, c5_i150, &c5_pc_emlrtBCI,
              (emlrtConstCTX)c5_sp);
          }

          c5_inside.vector.data[(c5_i149 + c5_inside.size[0] * (c5_i151 - 1)) -
            1] = (c5_b4 && c5_b5);
          c5_i152 = c5_inside.size[0];
          c5_i153 = (int32_T)c5_b_idx1;
          if ((c5_i153 < 1) || (c5_i153 > c5_i152)) {
            emlrtDynamicBoundsCheckR2012b(c5_i153, 1, c5_i152, &c5_qc_emlrtBCI,
              (emlrtConstCTX)c5_sp);
          }

          c5_i154 = c5_inside.size[1];
          c5_i155 = (int32_T)c5_b_idx2;
          if ((c5_i155 < 1) || (c5_i155 > c5_i154)) {
            emlrtDynamicBoundsCheckR2012b(c5_i155, 1, c5_i154, &c5_rc_emlrtBCI,
              (emlrtConstCTX)c5_sp);
          }

          if (c5_inside.vector.data[(c5_i153 + c5_inside.size[0] * (c5_i155 - 1))
              - 1]) {
            c5_i156 = (int32_T)c5_b_idx1;
            if ((c5_i156 < 1) || (c5_i156 > c5_rows_to_keep_size[0])) {
              emlrtDynamicBoundsCheckR2012b(c5_i156, 1, c5_rows_to_keep_size[0],
                &c5_sc_emlrtBCI, (emlrtConstCTX)c5_sp);
            }

            c5_rows_to_keep_data[c5_i156 - 1] = true;
          }
        }
      }

      c5_dim1 = (real_T)c5_idxE_chunk.size[0];
      c5_dim2 = (real_T)c5_radiusRange_size[1];
      c5_st.site = &c5_cl_emlrtRSI;
      c5_array_int32_T_SetSize(chartInstance, &c5_st, &c5_xckeep,
        &c5_dc_emlrtRTEI, c5_xc.size[0] * c5_xc.size[1]);
      c5_st.site = &c5_bl_emlrtRSI;
      c5_array_int32_T_SetSize(chartInstance, &c5_st, &c5_yckeep,
        &c5_ec_emlrtRTEI, c5_yc.size[0] * c5_yc.size[1]);
      c5_st.site = &c5_vk_emlrtRSI;
      c5_array_creal_T_SetSize(chartInstance, &c5_st, &c5_wkeep,
        &c5_fc_emlrtRTEI, c5_w.size[0] * c5_w.size[1]);
      c5_idxkeep = 0;
      c5_i54 = (int32_T)c5_dim2 - 1;
      for (c5_c_idx2 = 0; c5_c_idx2 <= c5_i54; c5_c_idx2++) {
        c5_b_idx2 = (real_T)c5_c_idx2 + 1.0;
        c5_i57 = (int32_T)c5_dim1 - 1;
        for (c5_c_idx1 = 0; c5_c_idx1 <= c5_i57; c5_c_idx1++) {
          c5_b_idx1 = (real_T)c5_c_idx1 + 1.0;
          c5_i59 = (int32_T)c5_b_idx1;
          if ((c5_i59 < 1) || (c5_i59 > c5_rows_to_keep_size[0])) {
            emlrtDynamicBoundsCheckR2012b(c5_i59, 1, c5_rows_to_keep_size[0],
              &c5_y_emlrtBCI, (emlrtConstCTX)c5_sp);
          }

          if (c5_rows_to_keep_data[c5_i59 - 1]) {
            c5_i62 = c5_inside.size[0];
            c5_i63 = (int32_T)c5_b_idx1;
            if ((c5_i63 < 1) || (c5_i63 > c5_i62)) {
              emlrtDynamicBoundsCheckR2012b(c5_i63, 1, c5_i62, &c5_cb_emlrtBCI,
                (emlrtConstCTX)c5_sp);
            }

            c5_i65 = c5_inside.size[1];
            c5_i68 = (int32_T)c5_b_idx2;
            if ((c5_i68 < 1) || (c5_i68 > c5_i65)) {
              emlrtDynamicBoundsCheckR2012b(c5_i68, 1, c5_i65, &c5_db_emlrtBCI,
                (emlrtConstCTX)c5_sp);
            }

            if (c5_inside.vector.data[(c5_i63 + c5_inside.size[0] * (c5_i68 - 1))
                - 1]) {
              c5_idxkeep++;
              c5_i71 = c5_xc.size[0];
              c5_i72 = (int32_T)c5_b_idx1;
              if ((c5_i72 < 1) || (c5_i72 > c5_i71)) {
                emlrtDynamicBoundsCheckR2012b(c5_i72, 1, c5_i71, &c5_gb_emlrtBCI,
                  (emlrtConstCTX)c5_sp);
              }

              c5_i76 = c5_xc.size[1];
              c5_i78 = (int32_T)c5_b_idx2;
              if ((c5_i78 < 1) || (c5_i78 > c5_i76)) {
                emlrtDynamicBoundsCheckR2012b(c5_i78, 1, c5_i76, &c5_hb_emlrtBCI,
                  (emlrtConstCTX)c5_sp);
              }

              c5_i82 = c5_xckeep.size[0];
              if ((c5_idxkeep < 1) || (c5_idxkeep > c5_i82)) {
                emlrtDynamicBoundsCheckR2012b(c5_idxkeep, 1, c5_i82,
                  &c5_ib_emlrtBCI, (emlrtConstCTX)c5_sp);
              }

              c5_xckeep.vector.data[c5_idxkeep - 1] = (int32_T)
                c5_xc.vector.data[(c5_i72 + c5_xc.size[0] * (c5_i78 - 1)) - 1];
              c5_i86 = c5_yc.size[0];
              c5_i87 = (int32_T)c5_b_idx1;
              if ((c5_i87 < 1) || (c5_i87 > c5_i86)) {
                emlrtDynamicBoundsCheckR2012b(c5_i87, 1, c5_i86, &c5_jb_emlrtBCI,
                  (emlrtConstCTX)c5_sp);
              }

              c5_i90 = c5_yc.size[1];
              c5_i93 = (int32_T)c5_b_idx2;
              if ((c5_i93 < 1) || (c5_i93 > c5_i90)) {
                emlrtDynamicBoundsCheckR2012b(c5_i93, 1, c5_i90, &c5_kb_emlrtBCI,
                  (emlrtConstCTX)c5_sp);
              }

              c5_i95 = c5_yckeep.size[0];
              if ((c5_idxkeep < 1) || (c5_idxkeep > c5_i95)) {
                emlrtDynamicBoundsCheckR2012b(c5_idxkeep, 1, c5_i95,
                  &c5_lb_emlrtBCI, (emlrtConstCTX)c5_sp);
              }

              c5_yckeep.vector.data[c5_idxkeep - 1] = (int32_T)
                c5_yc.vector.data[(c5_i87 + c5_yc.size[0] * (c5_i93 - 1)) - 1];
              c5_i98 = c5_wkeep.size[0];
              if ((c5_idxkeep < 1) || (c5_idxkeep > c5_i98)) {
                emlrtDynamicBoundsCheckR2012b(c5_idxkeep, 1, c5_i98,
                  &c5_pb_emlrtBCI, (emlrtConstCTX)c5_sp);
              }

              c5_i100 = c5_w.size[0];
              c5_i101 = (int32_T)c5_b_idx1;
              if ((c5_i101 < 1) || (c5_i101 > c5_i100)) {
                emlrtDynamicBoundsCheckR2012b(c5_i101, 1, c5_i100,
                  &c5_nb_emlrtBCI, (emlrtConstCTX)c5_sp);
              }

              c5_i105 = c5_w.size[1];
              c5_i106 = (int32_T)c5_b_idx2;
              if ((c5_i106 < 1) || (c5_i106 > c5_i105)) {
                emlrtDynamicBoundsCheckR2012b(c5_i106, 1, c5_i105,
                  &c5_ob_emlrtBCI, (emlrtConstCTX)c5_sp);
              }

              c5_wkeep.vector.data[c5_idxkeep - 1].re = c5_w.vector.data
                [(c5_i101 + c5_w.size[0] * (c5_i106 - 1)) - 1].re;
              c5_i109 = c5_w.size[0];
              c5_i110 = (int32_T)c5_b_idx1;
              if ((c5_i110 < 1) || (c5_i110 > c5_i109)) {
                emlrtDynamicBoundsCheckR2012b(c5_i110, 1, c5_i109,
                  &c5_nb_emlrtBCI, (emlrtConstCTX)c5_sp);
              }

              c5_i114 = c5_w.size[1];
              c5_i115 = (int32_T)c5_b_idx2;
              if ((c5_i115 < 1) || (c5_i115 > c5_i114)) {
                emlrtDynamicBoundsCheckR2012b(c5_i115, 1, c5_i114,
                  &c5_ob_emlrtBCI, (emlrtConstCTX)c5_sp);
              }

              c5_i119 = c5_wkeep.size[0];
              if ((c5_idxkeep < 1) || (c5_idxkeep > c5_i119)) {
                emlrtDynamicBoundsCheckR2012b(c5_idxkeep, 1, c5_i119,
                  &c5_pb_emlrtBCI, (emlrtConstCTX)c5_sp);
              }

              c5_wkeep.vector.data[c5_idxkeep - 1].im = c5_w.vector.data
                [(c5_i110 + c5_w.size[0] * (c5_i115 - 1)) - 1].im;
            }
          }
        }
      }

      c5_st.site = &c5_ke_emlrtRSI;
      c5_szxc = c5_idxkeep;
      for (c5_i58 = 0; c5_i58 < 19200; c5_i58++) {
        chartInstance->c5_out[c5_i58].re = 0.0;
        chartInstance->c5_out[c5_i58].im = 0.0;
      }

      c5_b_st.site = &c5_pf_emlrtRSI;
      c5_s_b = c5_szxc;
      c5_t_b = c5_s_b;
      if (c5_t_b < 1) {
        c5_overflow = false;
      } else {
        c5_overflow = (c5_t_b > 2147483646);
      }

      if (c5_overflow) {
        c5_c_st.site = &c5_v_emlrtRSI;
        c5_check_forloop_overflow_error(chartInstance, &c5_c_st);
      }

      for (c5_d_idx = 0; c5_d_idx < c5_szxc; c5_d_idx++) {
        c5_e_idx = c5_d_idx + 1;
        c5_i69 = c5_yckeep.size[0];
        if ((c5_e_idx < 1) || (c5_e_idx > c5_i69)) {
          emlrtDynamicBoundsCheckR2012b(c5_e_idx, 1, c5_i69, &c5_xb_emlrtBCI,
            &c5_st);
        }

        c5_i70 = c5_yckeep.vector.data[c5_e_idx - 1];
        if ((c5_i70 < 1) || (c5_i70 > 120)) {
          emlrtDynamicBoundsCheckR2012b(c5_i70, 1, 120, &c5_wb_emlrtBCI, &c5_st);
        }

        c5_i74 = c5_xckeep.size[0];
        if ((c5_e_idx < 1) || (c5_e_idx > c5_i74)) {
          emlrtDynamicBoundsCheckR2012b(c5_e_idx, 1, c5_i74, &c5_ac_emlrtBCI,
            &c5_st);
        }

        c5_i77 = c5_xckeep.vector.data[c5_e_idx - 1];
        if ((c5_i77 < 1) || (c5_i77 > 160)) {
          emlrtDynamicBoundsCheckR2012b(c5_i77, 1, 160, &c5_yb_emlrtBCI, &c5_st);
        }

        c5_i81 = c5_yckeep.size[0];
        if ((c5_e_idx < 1) || (c5_e_idx > c5_i81)) {
          emlrtDynamicBoundsCheckR2012b(c5_e_idx, 1, c5_i81, &c5_sb_emlrtBCI,
            &c5_st);
        }

        c5_i84 = c5_yckeep.vector.data[c5_e_idx - 1];
        if ((c5_i84 < 1) || (c5_i84 > 120)) {
          emlrtDynamicBoundsCheckR2012b(c5_i84, 1, 120, &c5_rb_emlrtBCI, &c5_st);
        }

        c5_i88 = c5_xckeep.size[0];
        if ((c5_e_idx < 1) || (c5_e_idx > c5_i88)) {
          emlrtDynamicBoundsCheckR2012b(c5_e_idx, 1, c5_i88, &c5_ub_emlrtBCI,
            &c5_st);
        }

        c5_i92 = c5_xckeep.vector.data[c5_e_idx - 1];
        if ((c5_i92 < 1) || (c5_i92 > 160)) {
          emlrtDynamicBoundsCheckR2012b(c5_i92, 1, 160, &c5_tb_emlrtBCI, &c5_st);
        }

        c5_i94 = c5_wkeep.size[0];
        if ((c5_e_idx < 1) || (c5_e_idx > c5_i94)) {
          emlrtDynamicBoundsCheckR2012b(c5_e_idx, 1, c5_i94, &c5_vb_emlrtBCI,
            &c5_st);
        }

        chartInstance->c5_out[(c5_i70 + 120 * (c5_i77 - 1)) - 1].re =
          chartInstance->c5_out[(c5_i84 + 120 * (c5_i92 - 1)) - 1].re +
          c5_wkeep.vector.data[c5_e_idx - 1].re;
        c5_i97 = c5_yckeep.size[0];
        if ((c5_e_idx < 1) || (c5_e_idx > c5_i97)) {
          emlrtDynamicBoundsCheckR2012b(c5_e_idx, 1, c5_i97, &c5_sb_emlrtBCI,
            &c5_st);
        }

        c5_i99 = c5_yckeep.vector.data[c5_e_idx - 1];
        if ((c5_i99 < 1) || (c5_i99 > 120)) {
          emlrtDynamicBoundsCheckR2012b(c5_i99, 1, 120, &c5_rb_emlrtBCI, &c5_st);
        }

        c5_i103 = c5_xckeep.size[0];
        if ((c5_e_idx < 1) || (c5_e_idx > c5_i103)) {
          emlrtDynamicBoundsCheckR2012b(c5_e_idx, 1, c5_i103, &c5_ub_emlrtBCI,
            &c5_st);
        }

        c5_i107 = c5_xckeep.vector.data[c5_e_idx - 1];
        if ((c5_i107 < 1) || (c5_i107 > 160)) {
          emlrtDynamicBoundsCheckR2012b(c5_i107, 1, 160, &c5_tb_emlrtBCI, &c5_st);
        }

        c5_i108 = c5_wkeep.size[0];
        if ((c5_e_idx < 1) || (c5_e_idx > c5_i108)) {
          emlrtDynamicBoundsCheckR2012b(c5_e_idx, 1, c5_i108, &c5_vb_emlrtBCI,
            &c5_st);
        }

        c5_i113 = c5_yckeep.size[0];
        if ((c5_e_idx < 1) || (c5_e_idx > c5_i113)) {
          emlrtDynamicBoundsCheckR2012b(c5_e_idx, 1, c5_i113, &c5_xb_emlrtBCI,
            &c5_st);
        }

        c5_i117 = c5_yckeep.vector.data[c5_e_idx - 1];
        if ((c5_i117 < 1) || (c5_i117 > 120)) {
          emlrtDynamicBoundsCheckR2012b(c5_i117, 1, 120, &c5_wb_emlrtBCI, &c5_st);
        }

        c5_i120 = c5_xckeep.size[0];
        if ((c5_e_idx < 1) || (c5_e_idx > c5_i120)) {
          emlrtDynamicBoundsCheckR2012b(c5_e_idx, 1, c5_i120, &c5_ac_emlrtBCI,
            &c5_st);
        }

        c5_i123 = c5_xckeep.vector.data[c5_e_idx - 1];
        if ((c5_i123 < 1) || (c5_i123 > 160)) {
          emlrtDynamicBoundsCheckR2012b(c5_i123, 1, 160, &c5_yb_emlrtBCI, &c5_st);
        }

        chartInstance->c5_out[(c5_i117 + 120 * (c5_i123 - 1)) - 1].im =
          chartInstance->c5_out[(c5_i99 + 120 * (c5_i107 - 1)) - 1].im +
          c5_wkeep.vector.data[c5_e_idx - 1].im;
      }

      for (c5_i67 = 0; c5_i67 < 19200; c5_i67++) {
        c5_c_accumMatrix[c5_i67].re += chartInstance->c5_out[c5_i67].re;
        c5_c_accumMatrix[c5_i67].im += chartInstance->c5_out[c5_i67].im;
      }
    }

    c5_array_real_T_Destructor(chartInstance, &c5_Ex);
    c5_array_real_T_Destructor(chartInstance, &c5_Ey);
    c5_array_real_T_2D_Destructor(chartInstance, &c5_r1);
    c5_array_creal_T_Destructor(chartInstance, &c5_wkeep);
    c5_array_int32_T_Destructor(chartInstance, &c5_yckeep);
    c5_array_int32_T_Destructor(chartInstance, &c5_xckeep);
    c5_array_boolean_T_2D_Destructor(chartInstance, &c5_inside);
    c5_array_creal_T_2D_Destructor(chartInstance, &c5_w);
    c5_array_real32_T_2D_Destructor(chartInstance, &c5_yc);
    c5_array_real32_T_2D_Destructor(chartInstance, &c5_xc);
    c5_array_real_T_Destructor(chartInstance, &c5_idxE_chunk);
    c5_array_real_T_Destructor(chartInstance, &c5_Ey_chunk);
    c5_array_real_T_Destructor(chartInstance, &c5_Ex_chunk);
    c5_array_real_T_Destructor(chartInstance, &c5_idxE);
  }
}

static void c5_parseInputs(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, boolean_T c5_varargin_1[19200], real_T
  c5_varargin_2_data[], boolean_T c5_b_A[19200], real_T c5_radiusRange_data[],
  int32_T c5_radiusRange_size[2])
{
  int32_T c5_i;
  for (c5_i = 0; c5_i < 19200; c5_i++) {
    c5_b_A[c5_i] = c5_varargin_1[c5_i];
  }

  c5_b_parseInputs(chartInstance, c5_sp, c5_varargin_2_data, c5_radiusRange_data,
                   c5_radiusRange_size);
}

static boolean_T c5_all(SFc5_flightControlSystemInstanceStruct *chartInstance,
  real_T c5_a_data[])
{
  real_T c5_b_k;
  real_T c5_b_x;
  real_T c5_c_x;
  real_T c5_d_x;
  real_T c5_e_x;
  real_T c5_f_x;
  real_T c5_g_x;
  real_T c5_y;
  int32_T c5_k;
  boolean_T c5_b;
  boolean_T c5_b1;
  boolean_T c5_b_b;
  boolean_T c5_b_p;
  boolean_T c5_c_b;
  boolean_T c5_c_p;
  boolean_T c5_d_b;
  boolean_T c5_exitg1;
  boolean_T c5_p;
  (void)chartInstance;
  c5_p = true;
  c5_k = 0;
  c5_exitg1 = false;
  while ((!c5_exitg1) && (c5_k < 2)) {
    c5_b_k = (real_T)c5_k + 1.0;
    c5_b_x = c5_a_data[(int32_T)c5_b_k - 1];
    c5_c_x = c5_b_x;
    c5_d_x = c5_c_x;
    c5_b = muDoubleScalarIsInf(c5_d_x);
    c5_b_b = !c5_b;
    c5_e_x = c5_c_x;
    c5_c_b = muDoubleScalarIsNaN(c5_e_x);
    c5_b1 = !c5_c_b;
    c5_d_b = (c5_b_b && c5_b1);
    if (c5_d_b) {
      c5_f_x = c5_b_x;
      c5_g_x = c5_f_x;
      c5_y = c5_g_x;
      c5_y = muDoubleScalarFloor(c5_y);
      if (c5_y == c5_b_x) {
        c5_b_p = true;
      } else {
        c5_b_p = false;
      }
    } else {
      c5_b_p = false;
    }

    c5_c_p = c5_b_p;
    if (c5_c_p) {
      c5_k++;
    } else {
      c5_p = false;
      c5_exitg1 = true;
    }
  }

  return c5_p;
}

static void c5_b_imfilter(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, real32_T c5_varargin_1[19200], real32_T c5_b[19200])
{
  static real_T c5_kernel[25] = { 0.014418818362460822, 0.028084023356349175,
    0.0350727008055935, 0.028084023356349175, 0.014418818362460822,
    0.028084023356349175, 0.054700208300935887, 0.068312293270780214,
    0.054700208300935887, 0.028084023356349175, 0.0350727008055935,
    0.068312293270780214, 0.085311730190125085, 0.068312293270780214,
    0.0350727008055935, 0.028084023356349175, 0.054700208300935887,
    0.068312293270780214, 0.054700208300935887, 0.028084023356349175,
    0.014418818362460822, 0.028084023356349175, 0.0350727008055935,
    0.028084023356349175, 0.014418818362460822 };

  static real_T c5_nonZeroKernel[25] = { 0.014418818362460822,
    0.028084023356349175, 0.0350727008055935, 0.028084023356349175,
    0.014418818362460822, 0.028084023356349175, 0.054700208300935887,
    0.068312293270780214, 0.054700208300935887, 0.028084023356349175,
    0.0350727008055935, 0.068312293270780214, 0.085311730190125085,
    0.068312293270780214, 0.0350727008055935, 0.028084023356349175,
    0.054700208300935887, 0.068312293270780214, 0.054700208300935887,
    0.028084023356349175, 0.014418818362460822, 0.028084023356349175,
    0.0350727008055935, 0.028084023356349175, 0.014418818362460822 };

  static int32_T c5_idxA[328] = { 1, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,
    13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
    32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
    51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69,
    70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88,
    89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105,
    106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120,
    120, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 2, 3, 4, 5, 6,
    7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26,
    27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45,
    46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64,
    65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83,
    84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101,
    102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116,
    117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131,
    132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146,
    147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 160,
    160 };

  emlrtStack c5_b_st;
  emlrtStack c5_st;
  real_T c5_connDimsT[2];
  real_T c5_outSizeT[2];
  real_T c5_padSizeT[2];
  real_T c5_startT[2];
  real_T c5_b_j;
  real_T c5_c_i;
  int32_T c5_b_i;
  int32_T c5_d_i;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i2;
  int32_T c5_i3;
  int32_T c5_i4;
  int32_T c5_i5;
  int32_T c5_i6;
  int32_T c5_i7;
  int32_T c5_i8;
  int32_T c5_j;
  boolean_T c5_conn[25];
  boolean_T c5_b_modeFlag;
  boolean_T c5_c_modeFlag;
  boolean_T c5_modeFlag;
  boolean_T c5_tooBig;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_st.site = &c5_r_emlrtRSI;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_b_st.site = &c5_jc_emlrtRSI;
  for (c5_j = 0; c5_j < 164; c5_j++) {
    c5_b_j = (real_T)c5_j + 1.0;
    for (c5_i = 0; c5_i < 124; c5_i++) {
      c5_c_i = (real_T)c5_i + 1.0;
      if ((c5_idxA[(int32_T)c5_c_i - 1] < 1) || (c5_idxA[(int32_T)c5_c_i - 1] >
           120)) {
        emlrtDynamicBoundsCheckR2012b(c5_idxA[(int32_T)c5_c_i - 1], 1, 120,
          &c5_f_emlrtBCI, &c5_b_st);
      }

      c5_d_i = c5_idxA[(int32_T)c5_b_j + 163];
      if ((c5_d_i < 1) || (c5_d_i > 160)) {
        emlrtDynamicBoundsCheckR2012b(c5_d_i, 1, 160, &c5_g_emlrtBCI, &c5_b_st);
      }

      chartInstance->c5_e_aTmp[((int32_T)c5_c_i + 124 * ((int32_T)c5_b_j - 1)) -
        1] = c5_varargin_1[(c5_idxA[(int32_T)c5_c_i - 1] + 120 * (c5_d_i - 1)) -
        1];
    }
  }

  c5_st.site = &c5_s_emlrtRSI;
  c5_tooBig = true;
  for (c5_b_i = 0; c5_b_i < 2; c5_b_i++) {
    c5_tooBig = false;
  }

  if (!c5_tooBig) {
    c5_modeFlag = true;
  } else {
    c5_modeFlag = false;
  }

  if (c5_modeFlag) {
    c5_b_modeFlag = true;
  } else {
    c5_b_modeFlag = false;
  }

  c5_c_modeFlag = c5_b_modeFlag;
  if (c5_c_modeFlag) {
    for (c5_i2 = 0; c5_i2 < 2; c5_i2++) {
      c5_padSizeT[c5_i2] = 124.0 + 40.0 * (real_T)c5_i2;
    }

    for (c5_i4 = 0; c5_i4 < 2; c5_i4++) {
      c5_outSizeT[c5_i4] = 120.0 + 40.0 * (real_T)c5_i4;
    }

    for (c5_i6 = 0; c5_i6 < 2; c5_i6++) {
      c5_connDimsT[c5_i6] = 5.0;
    }

    ippfilter_real32(&chartInstance->c5_e_aTmp[0], &c5_b[0], &c5_outSizeT[0],
                     2.0, &c5_padSizeT[0], &c5_kernel[0], &c5_connDimsT[0],
                     false);
  } else {
    for (c5_i1 = 0; c5_i1 < 25; c5_i1++) {
      c5_conn[c5_i1] = true;
    }

    for (c5_i3 = 0; c5_i3 < 2; c5_i3++) {
      c5_padSizeT[c5_i3] = 124.0 + 40.0 * (real_T)c5_i3;
    }

    for (c5_i5 = 0; c5_i5 < 2; c5_i5++) {
      c5_outSizeT[c5_i5] = 120.0 + 40.0 * (real_T)c5_i5;
    }

    for (c5_i7 = 0; c5_i7 < 2; c5_i7++) {
      c5_connDimsT[c5_i7] = 5.0;
    }

    for (c5_i8 = 0; c5_i8 < 2; c5_i8++) {
      c5_startT[c5_i8] = 2.0;
    }

    imfilter_real32(&chartInstance->c5_e_aTmp[0], &c5_b[0], 2.0, &c5_outSizeT[0],
                    2.0, &c5_padSizeT[0], &c5_nonZeroKernel[0], 25.0, &c5_conn[0],
                    2.0, &c5_connDimsT[0], &c5_startT[0], 2.0, true, false);
  }
}

static void c5_c_imfilter(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, real32_T c5_varargin_1[19200], real32_T c5_b[19200])
{
  static real_T c5_kernel[9] = { -1.0, -2.0, -1.0, -0.0, -0.0, -0.0, 1.0, 2.0,
    1.0 };

  static real_T c5_nonZeroKernel[6] = { -1.0, -2.0, -1.0, 1.0, 2.0, 1.0 };

  static boolean_T c5_conn[9] = { true, true, true, false, false, false, true,
    true, true };

  emlrtStack c5_b_st;
  emlrtStack c5_st;
  real_T c5_connDimsT[2];
  real_T c5_outSizeT[2];
  real_T c5_padSizeT[2];
  real_T c5_startT[2];
  real_T c5_b_j;
  real_T c5_c_i;
  int32_T c5_b_i;
  int32_T c5_d_i;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i2;
  int32_T c5_i3;
  int32_T c5_i4;
  int32_T c5_i5;
  int32_T c5_i6;
  int32_T c5_i7;
  int32_T c5_j;
  boolean_T c5_b_modeFlag;
  boolean_T c5_c_modeFlag;
  boolean_T c5_modeFlag;
  boolean_T c5_tooBig;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_st.site = &c5_r_emlrtRSI;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_b_st.site = &c5_jc_emlrtRSI;
  for (c5_j = 0; c5_j < 162; c5_j++) {
    c5_b_j = (real_T)c5_j + 1.0;
    for (c5_i = 0; c5_i < 122; c5_i++) {
      c5_c_i = (real_T)c5_i + 1.0;
      if ((c5_iv1[(int32_T)c5_c_i - 1] < 1) || (c5_iv1[(int32_T)c5_c_i - 1] >
           120)) {
        emlrtDynamicBoundsCheckR2012b(c5_iv1[(int32_T)c5_c_i - 1], 1, 120,
          &c5_f_emlrtBCI, &c5_b_st);
      }

      c5_d_i = c5_iv1[(int32_T)c5_b_j + 161];
      if ((c5_d_i < 1) || (c5_d_i > 160)) {
        emlrtDynamicBoundsCheckR2012b(c5_d_i, 1, 160, &c5_g_emlrtBCI, &c5_b_st);
      }

      chartInstance->c5_g_aTmp[((int32_T)c5_c_i + 122 * ((int32_T)c5_b_j - 1)) -
        1] = c5_varargin_1[(c5_iv1[(int32_T)c5_c_i - 1] + 120 * (c5_d_i - 1)) -
        1];
    }
  }

  c5_st.site = &c5_s_emlrtRSI;
  c5_tooBig = true;
  for (c5_b_i = 0; c5_b_i < 2; c5_b_i++) {
    c5_tooBig = false;
  }

  if (!c5_tooBig) {
    c5_modeFlag = true;
  } else {
    c5_modeFlag = false;
  }

  if (c5_modeFlag) {
    c5_b_modeFlag = true;
  } else {
    c5_b_modeFlag = false;
  }

  c5_c_modeFlag = c5_b_modeFlag;
  if (c5_c_modeFlag) {
    for (c5_i2 = 0; c5_i2 < 2; c5_i2++) {
      c5_padSizeT[c5_i2] = 122.0 + 40.0 * (real_T)c5_i2;
    }

    for (c5_i4 = 0; c5_i4 < 2; c5_i4++) {
      c5_outSizeT[c5_i4] = 120.0 + 40.0 * (real_T)c5_i4;
    }

    for (c5_i6 = 0; c5_i6 < 2; c5_i6++) {
      c5_connDimsT[c5_i6] = 3.0;
    }

    ippfilter_real32(&chartInstance->c5_g_aTmp[0], &c5_b[0], &c5_outSizeT[0],
                     2.0, &c5_padSizeT[0], &c5_kernel[0], &c5_connDimsT[0], true);
  } else {
    for (c5_i1 = 0; c5_i1 < 2; c5_i1++) {
      c5_padSizeT[c5_i1] = 122.0 + 40.0 * (real_T)c5_i1;
    }

    for (c5_i3 = 0; c5_i3 < 2; c5_i3++) {
      c5_outSizeT[c5_i3] = 120.0 + 40.0 * (real_T)c5_i3;
    }

    for (c5_i5 = 0; c5_i5 < 2; c5_i5++) {
      c5_connDimsT[c5_i5] = 3.0;
    }

    for (c5_i7 = 0; c5_i7 < 2; c5_i7++) {
      c5_startT[c5_i7] = 1.0;
    }

    imfilter_real32(&chartInstance->c5_g_aTmp[0], &c5_b[0], 2.0, &c5_outSizeT[0],
                    2.0, &c5_padSizeT[0], &c5_nonZeroKernel[0], 6.0, &c5_conn[0],
                    2.0, &c5_connDimsT[0], &c5_startT[0], 2.0, true, true);
  }
}

static void c5_d_imfilter(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, real32_T c5_varargin_1[19200], real32_T c5_b[19200])
{
  static real_T c5_kernel[9] = { -1.0, -0.0, 1.0, -2.0, -0.0, 2.0, -1.0, -0.0,
    1.0 };

  static real_T c5_nonZeroKernel[6] = { -1.0, 1.0, -2.0, 2.0, -1.0, 1.0 };

  static boolean_T c5_conn[9] = { true, false, true, true, false, true, true,
    false, true };

  emlrtStack c5_b_st;
  emlrtStack c5_st;
  real_T c5_connDimsT[2];
  real_T c5_outSizeT[2];
  real_T c5_padSizeT[2];
  real_T c5_startT[2];
  real_T c5_b_j;
  real_T c5_c_i;
  int32_T c5_b_i;
  int32_T c5_d_i;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i2;
  int32_T c5_i3;
  int32_T c5_i4;
  int32_T c5_i5;
  int32_T c5_i6;
  int32_T c5_i7;
  int32_T c5_j;
  boolean_T c5_b_modeFlag;
  boolean_T c5_c_modeFlag;
  boolean_T c5_modeFlag;
  boolean_T c5_tooBig;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_st.site = &c5_r_emlrtRSI;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_b_st.site = &c5_jc_emlrtRSI;
  for (c5_j = 0; c5_j < 162; c5_j++) {
    c5_b_j = (real_T)c5_j + 1.0;
    for (c5_i = 0; c5_i < 122; c5_i++) {
      c5_c_i = (real_T)c5_i + 1.0;
      if ((c5_iv1[(int32_T)c5_c_i - 1] < 1) || (c5_iv1[(int32_T)c5_c_i - 1] >
           120)) {
        emlrtDynamicBoundsCheckR2012b(c5_iv1[(int32_T)c5_c_i - 1], 1, 120,
          &c5_f_emlrtBCI, &c5_b_st);
      }

      c5_d_i = c5_iv1[(int32_T)c5_b_j + 161];
      if ((c5_d_i < 1) || (c5_d_i > 160)) {
        emlrtDynamicBoundsCheckR2012b(c5_d_i, 1, 160, &c5_g_emlrtBCI, &c5_b_st);
      }

      chartInstance->c5_f_aTmp[((int32_T)c5_c_i + 122 * ((int32_T)c5_b_j - 1)) -
        1] = c5_varargin_1[(c5_iv1[(int32_T)c5_c_i - 1] + 120 * (c5_d_i - 1)) -
        1];
    }
  }

  c5_st.site = &c5_s_emlrtRSI;
  c5_tooBig = true;
  for (c5_b_i = 0; c5_b_i < 2; c5_b_i++) {
    c5_tooBig = false;
  }

  if (!c5_tooBig) {
    c5_modeFlag = true;
  } else {
    c5_modeFlag = false;
  }

  if (c5_modeFlag) {
    c5_b_modeFlag = true;
  } else {
    c5_b_modeFlag = false;
  }

  c5_c_modeFlag = c5_b_modeFlag;
  if (c5_c_modeFlag) {
    for (c5_i2 = 0; c5_i2 < 2; c5_i2++) {
      c5_padSizeT[c5_i2] = 122.0 + 40.0 * (real_T)c5_i2;
    }

    for (c5_i4 = 0; c5_i4 < 2; c5_i4++) {
      c5_outSizeT[c5_i4] = 120.0 + 40.0 * (real_T)c5_i4;
    }

    for (c5_i6 = 0; c5_i6 < 2; c5_i6++) {
      c5_connDimsT[c5_i6] = 3.0;
    }

    ippfilter_real32(&chartInstance->c5_f_aTmp[0], &c5_b[0], &c5_outSizeT[0],
                     2.0, &c5_padSizeT[0], &c5_kernel[0], &c5_connDimsT[0], true);
  } else {
    for (c5_i1 = 0; c5_i1 < 2; c5_i1++) {
      c5_padSizeT[c5_i1] = 122.0 + 40.0 * (real_T)c5_i1;
    }

    for (c5_i3 = 0; c5_i3 < 2; c5_i3++) {
      c5_outSizeT[c5_i3] = 120.0 + 40.0 * (real_T)c5_i3;
    }

    for (c5_i5 = 0; c5_i5 < 2; c5_i5++) {
      c5_connDimsT[c5_i5] = 3.0;
    }

    for (c5_i7 = 0; c5_i7 < 2; c5_i7++) {
      c5_startT[c5_i7] = 1.0;
    }

    imfilter_real32(&chartInstance->c5_f_aTmp[0], &c5_b[0], 2.0, &c5_outSizeT[0],
                    2.0, &c5_padSizeT[0], &c5_nonZeroKernel[0], 6.0, &c5_conn[0],
                    2.0, &c5_connDimsT[0], &c5_startT[0], 2.0, true, true);
  }
}

static real_T c5_graythresh(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, real32_T c5_I[19200])
{
  emlrtStack c5_b_st;
  emlrtStack c5_c_st;
  emlrtStack c5_st;
  real_T c5_counts[256];
  real_T c5_localBins1[256];
  real_T c5_localBins2[256];
  real_T c5_localBins3[256];
  real_T c5_b_out;
  real_T c5_d_i;
  int32_T c5_b_c;
  int32_T c5_b_i;
  int32_T c5_c;
  int32_T c5_c_a;
  int32_T c5_c_c;
  int32_T c5_c_i;
  int32_T c5_d_a;
  int32_T c5_d_c;
  int32_T c5_e_a;
  int32_T c5_e_c;
  int32_T c5_f_a;
  int32_T c5_f_c;
  int32_T c5_g_a;
  int32_T c5_g_c;
  int32_T c5_h_a;
  int32_T c5_h_c;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i2;
  int32_T c5_i3;
  int32_T c5_i4;
  int32_T c5_i5;
  int32_T c5_i6;
  int32_T c5_i7;
  int32_T c5_i_a;
  int32_T c5_i_c;
  int32_T c5_idx;
  int32_T c5_idx1;
  int32_T c5_idx2;
  int32_T c5_idx3;
  int32_T c5_idx4;
  int32_T c5_j_a;
  int32_T c5_j_c;
  int32_T c5_k_a;
  int32_T c5_l_a;
  uint8_T c5_b_I[19200];
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_st.site = &c5_re_emlrtRSI;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_c_st.prev = &c5_b_st;
  c5_c_st.tls = c5_b_st.tls;
  for (c5_i = 0; c5_i < 19200; c5_i++) {
    chartInstance->c5_img[c5_i] = c5_I[c5_i];
  }

  c5_b_st.site = &c5_qc_emlrtRSI;
  c5_c_st.site = &c5_rc_emlrtRSI;
  grayto8_real32(&chartInstance->c5_img[0], &c5_b_I[0], 19200.0);
  c5_st.site = &c5_se_emlrtRSI;
  c5_b_st.site = &c5_tc_emlrtRSI;
  c5_c_st.site = &c5_vc_emlrtRSI;
  c5_b_out = 1.0;
  getnumcores(&c5_b_out);
  c5_c_st.site = &c5_uc_emlrtRSI;
  for (c5_i1 = 0; c5_i1 < 256; c5_i1++) {
    c5_counts[c5_i1] = 0.0;
  }

  for (c5_i2 = 0; c5_i2 < 256; c5_i2++) {
    c5_localBins1[c5_i2] = 0.0;
  }

  for (c5_i3 = 0; c5_i3 < 256; c5_i3++) {
    c5_localBins2[c5_i3] = 0.0;
  }

  for (c5_i4 = 0; c5_i4 < 256; c5_i4++) {
    c5_localBins3[c5_i4] = 0.0;
  }

  for (c5_b_i = 4; c5_b_i <= 19200; c5_b_i += 4) {
    c5_i5 = c5_b_i - 3;
    if ((c5_i5 < 1) || (c5_i5 > 19200)) {
      emlrtDynamicBoundsCheckR2012b(c5_i5, 1, 19200, &c5_emlrtBCI, &c5_c_st);
    }

    c5_idx1 = c5_b_I[c5_i5 - 1];
    c5_i6 = c5_b_i - 2;
    if ((c5_i6 < 1) || (c5_i6 > 19200)) {
      emlrtDynamicBoundsCheckR2012b(c5_i6, 1, 19200, &c5_b_emlrtBCI, &c5_c_st);
    }

    c5_idx2 = c5_b_I[c5_i6 - 1];
    c5_i7 = c5_b_i - 1;
    if ((c5_i7 < 1) || (c5_i7 > 19200)) {
      emlrtDynamicBoundsCheckR2012b(c5_i7, 1, 19200, &c5_c_emlrtBCI, &c5_c_st);
    }

    c5_idx3 = c5_b_I[c5_i7 - 1];
    if ((c5_b_i < 1) || (c5_b_i > 19200)) {
      emlrtDynamicBoundsCheckR2012b(c5_b_i, 1, 19200, &c5_d_emlrtBCI, &c5_c_st);
    }

    c5_idx4 = c5_b_I[c5_b_i - 1];
    c5_e_a = c5_idx1 + 1;
    c5_c_c = c5_e_a - 1;
    c5_f_a = c5_idx1 + 1;
    c5_d_c = c5_f_a - 1;
    c5_localBins1[c5_c_c] = c5_localBins1[c5_d_c] + 1.0;
    c5_g_a = c5_idx2 + 1;
    c5_e_c = c5_g_a - 1;
    c5_h_a = c5_idx2 + 1;
    c5_f_c = c5_h_a - 1;
    c5_localBins2[c5_e_c] = c5_localBins2[c5_f_c] + 1.0;
    c5_i_a = c5_idx3 + 1;
    c5_g_c = c5_i_a - 1;
    c5_j_a = c5_idx3 + 1;
    c5_h_c = c5_j_a - 1;
    c5_localBins3[c5_g_c] = c5_localBins3[c5_h_c] + 1.0;
    c5_k_a = c5_idx4 + 1;
    c5_i_c = c5_k_a - 1;
    c5_l_a = c5_idx4 + 1;
    c5_j_c = c5_l_a - 1;
    c5_counts[c5_i_c] = c5_counts[c5_j_c] + 1.0;
  }

  while (c5_b_i - 3 <= 19200) {
    c5_idx = c5_b_I[c5_b_i - 4];
    c5_c_a = c5_idx + 1;
    c5_c = c5_c_a - 1;
    c5_d_a = c5_idx + 1;
    c5_b_c = c5_d_a - 1;
    c5_counts[c5_c] = c5_counts[c5_b_c] + 1.0;
    c5_b_i++;
  }

  for (c5_c_i = 0; c5_c_i < 256; c5_c_i++) {
    c5_d_i = (real_T)c5_c_i + 1.0;
    c5_counts[(int32_T)c5_d_i - 1] = ((c5_counts[(int32_T)c5_d_i - 1] +
      c5_localBins1[(int32_T)c5_d_i - 1]) + c5_localBins2[(int32_T)c5_d_i - 1])
      + c5_localBins3[(int32_T)c5_d_i - 1];
  }

  c5_st.site = &c5_te_emlrtRSI;
  return c5_otsuthresh(chartInstance, &c5_st, c5_counts);
}

static void c5_eml_find(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, boolean_T c5_b_x[19200], c5_coder_array_int32_T *c5_i,
  c5_coder_array_int32_T *c5_j)
{
  emlrtStack c5_b_st;
  emlrtStack c5_st;
  int32_T c5_b_iv[2];
  int32_T c5_b_iv1[2];
  int32_T c5_iv2[2];
  int32_T c5_b_i;
  int32_T c5_i1;
  int32_T c5_i2;
  int32_T c5_idx;
  int32_T c5_ii;
  int32_T c5_jj;
  boolean_T c5_b;
  boolean_T c5_b1;
  boolean_T c5_b2;
  boolean_T c5_exitg1;
  boolean_T c5_guard1;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_st.site = &c5_ve_emlrtRSI;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_idx = 0;
  c5_array_int32_T_SetSize(chartInstance, &c5_st, c5_i, &c5_gc_emlrtRTEI, 19200);
  c5_array_int32_T_SetSize(chartInstance, &c5_st, c5_j, &c5_hc_emlrtRTEI, 19200);
  c5_ii = 1;
  c5_jj = 1;
  c5_exitg1 = false;
  while ((!c5_exitg1) && (c5_jj <= 160)) {
    c5_guard1 = false;
    if (c5_b_x[(c5_ii + 120 * (c5_jj - 1)) - 1]) {
      c5_idx++;
      c5_i->vector.data[c5_idx - 1] = c5_ii;
      c5_j->vector.data[c5_idx - 1] = c5_jj;
      if (c5_idx >= 19200) {
        c5_exitg1 = true;
      } else {
        c5_guard1 = true;
      }
    } else {
      c5_guard1 = true;
    }

    if (c5_guard1) {
      c5_ii++;
      if (c5_ii > 120) {
        c5_ii = 1;
        c5_jj++;
      }
    }
  }

  c5_b = (c5_idx < 1);
  if (c5_b) {
    c5_b_i = 0;
  } else {
    c5_b_i = c5_idx;
  }

  c5_b_iv[0] = 1;
  c5_b_iv[1] = c5_b_i;
  c5_b_st.site = &c5_ye_emlrtRSI;
  c5_indexShapeCheck(chartInstance, &c5_b_st, 19200, c5_b_iv);
  c5_array_int32_T_SetSize(chartInstance, &c5_st, c5_i, &c5_ic_emlrtRTEI, c5_b_i);
  c5_b1 = (c5_idx < 1);
  if (c5_b1) {
    c5_i1 = 0;
  } else {
    c5_i1 = c5_idx;
  }

  c5_b_iv1[0] = 1;
  c5_b_iv1[1] = c5_i1;
  c5_b_st.site = &c5_xe_emlrtRSI;
  c5_indexShapeCheck(chartInstance, &c5_b_st, 19200, c5_b_iv1);
  c5_array_int32_T_SetSize(chartInstance, &c5_st, c5_j, &c5_jc_emlrtRTEI, c5_i1);
  c5_b2 = (c5_idx < 1);
  if (c5_b2) {
    c5_i2 = 0;
  } else {
    c5_i2 = c5_idx;
  }

  c5_iv2[0] = 1;
  c5_iv2[1] = c5_i2;
  c5_b_st.site = &c5_we_emlrtRSI;
  c5_indexShapeCheck(chartInstance, &c5_b_st, 19200, c5_iv2);
}

static void c5_indexShapeCheck(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, int32_T c5_matrixSize, int32_T
  c5_indexSize[2])
{
  static char_T c5_b_cv[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'F', 'E', ':', 'P',
    'o', 't', 'e', 'n', 't', 'i', 'a', 'l', 'V', 'e', 'c', 't', 'o', 'r', 'V',
    'e', 'c', 't', 'o', 'r' };

  emlrtStack c5_st;
  const mxArray *c5_b_y = NULL;
  const mxArray *c5_y = NULL;
  int32_T c5_size1;
  boolean_T c5_b;
  boolean_T c5_b_b;
  boolean_T c5_b_c;
  boolean_T c5_c;
  boolean_T c5_nonSingletonDimFound;
  (void)chartInstance;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_size1 = c5_matrixSize;
  if (c5_size1 != 1) {
    c5_b = false;
  } else {
    c5_b = true;
  }

  if (c5_b) {
    c5_nonSingletonDimFound = false;
    if (c5_indexSize[1] != 1) {
      c5_nonSingletonDimFound = true;
    }

    c5_b_b = c5_nonSingletonDimFound;
    if (c5_b_b) {
      c5_c = true;
    } else {
      c5_c = false;
    }
  } else {
    c5_c = false;
  }

  c5_st.site = &c5_af_emlrtRSI;
  c5_b_c = c5_c;
  if (c5_b_c) {
    c5_y = NULL;
    sf_mex_assign(&c5_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1, 30),
                  false);
    c5_b_y = NULL;
    sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1, 30),
                  false);
    sf_mex_call(&c5_st, &c5_o_emlrtMCI, "error", 0U, 2U, 14, c5_y, 14,
                sf_mex_call(&c5_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c5_st, NULL, "message", 1U, 1U, 14, c5_b_y)));
  }
}

static void c5_sub2ind(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, c5_coder_array_real_T *c5_varargin_1,
  c5_coder_array_real_T *c5_b_varargin_2, c5_coder_array_int32_T *c5_idx)
{
  static char_T c5_b_cv1[34] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'u',
    'b', '2', 'i', 'n', 'd', ':', 'S', 'u', 'b', 's', 'c', 'r', 'i', 'p', 't',
    'V', 'e', 'c', 't', 'o', 'r', 'S', 'i', 'z', 'e' };

  static char_T c5_b_cv[30] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'u', 'b',
    '2', 'i', 'n', 'd', ':', 'I', 'n', 'd', 'e', 'x', 'O', 'u', 't', 'O', 'f',
    'R', 'a', 'n', 'g', 'e' };

  c5_coder_array_int32_T c5_b;
  emlrtStack c5_st;
  const mxArray *c5_b_y = NULL;
  const mxArray *c5_c_y = NULL;
  const mxArray *c5_d_y = NULL;
  const mxArray *c5_e_y = NULL;
  const mxArray *c5_f_y = NULL;
  const mxArray *c5_y = NULL;
  real_T c5_b_varargin_1[2];
  real_T c5_c_varargin_2[2];
  real_T c5_b_k;
  real_T c5_x1;
  real_T c5_x2;
  int32_T c5_b_loop_ub;
  int32_T c5_c_loop_ub;
  int32_T c5_d_loop_ub;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i2;
  int32_T c5_i3;
  int32_T c5_k;
  int32_T c5_loop_ub;
  boolean_T c5_b_p;
  boolean_T c5_c_p;
  boolean_T c5_exitg1;
  boolean_T c5_p;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  if (!c5_allinrange(chartInstance, c5_varargin_1, 120)) {
    c5_y = NULL;
    sf_mex_assign(&c5_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1, 30),
                  false);
    c5_b_y = NULL;
    sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1, 30),
                  false);
    sf_mex_call(c5_sp, &c5_p_emlrtMCI, "error", 0U, 2U, 14, c5_y, 14,
                sf_mex_call(c5_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c5_sp, NULL, "message", 1U, 1U, 14, c5_b_y)));
  }

  c5_b_varargin_1[0] = (real_T)c5_varargin_1->size[0];
  c5_b_varargin_1[1] = 1.0;
  c5_c_varargin_2[0] = (real_T)c5_b_varargin_2->size[0];
  c5_c_varargin_2[1] = 1.0;
  c5_p = false;
  c5_b_p = true;
  c5_k = 0;
  c5_exitg1 = false;
  while ((!c5_exitg1) && (c5_k < 2)) {
    c5_b_k = (real_T)c5_k + 1.0;
    c5_x1 = c5_b_varargin_1[(int32_T)c5_b_k - 1];
    c5_x2 = c5_c_varargin_2[(int32_T)c5_b_k - 1];
    c5_c_p = (c5_x1 == c5_x2);
    if (!c5_c_p) {
      c5_b_p = false;
      c5_exitg1 = true;
    } else {
      c5_k++;
    }
  }

  if (c5_b_p) {
    c5_p = true;
  }

  if (!c5_p) {
    c5_c_y = NULL;
    sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_b_cv1, 10, 0U, 1, 0U, 2, 1, 34),
                  false);
    c5_e_y = NULL;
    sf_mex_assign(&c5_e_y, sf_mex_create("y", c5_b_cv1, 10, 0U, 1, 0U, 2, 1, 34),
                  false);
    sf_mex_call(c5_sp, &c5_q_emlrtMCI, "error", 0U, 2U, 14, c5_c_y, 14,
                sf_mex_call(c5_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c5_sp, NULL, "message", 1U, 1U, 14, c5_e_y)));
  }

  if (!c5_allinrange(chartInstance, c5_b_varargin_2, 160)) {
    c5_d_y = NULL;
    sf_mex_assign(&c5_d_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1, 30),
                  false);
    c5_f_y = NULL;
    sf_mex_assign(&c5_f_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1, 30),
                  false);
    sf_mex_call(c5_sp, &c5_p_emlrtMCI, "error", 0U, 2U, 14, c5_d_y, 14,
                sf_mex_call(c5_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c5_sp, NULL, "message", 1U, 1U, 14, c5_f_y)));
  }

  c5_st.site = &c5_al_emlrtRSI;
  c5_array_int32_T_SetSize(chartInstance, &c5_st, c5_idx, &c5_kc_emlrtRTEI,
    c5_varargin_1->size[0]);
  c5_loop_ub = c5_varargin_1->size[0] - 1;
  for (c5_i = 0; c5_i <= c5_loop_ub; c5_i++) {
    c5_idx->vector.data[c5_i] = (int32_T)c5_varargin_1->vector.data[c5_i];
  }

  c5_array_int32_T_Constructor(chartInstance, &c5_b);
  c5_st.site = &c5_yk_emlrtRSI;
  c5_array_int32_T_SetSize(chartInstance, &c5_st, &c5_b, &c5_lc_emlrtRTEI,
    c5_b_varargin_2->size[0]);
  c5_b_loop_ub = c5_b_varargin_2->size[0] - 1;
  for (c5_i1 = 0; c5_i1 <= c5_b_loop_ub; c5_i1++) {
    c5_b.vector.data[c5_i1] = (int32_T)c5_b_varargin_2->vector.data[c5_i1] - 1;
  }

  c5_c_loop_ub = c5_b.size[0] - 1;
  for (c5_i2 = 0; c5_i2 <= c5_c_loop_ub; c5_i2++) {
    c5_b.vector.data[c5_i2] *= 120;
  }

  c5_d_loop_ub = c5_idx->size[0] - 1;
  for (c5_i3 = 0; c5_i3 <= c5_d_loop_ub; c5_i3++) {
    c5_idx->vector.data[c5_i3] += c5_b.vector.data[c5_i3];
  }

  c5_array_int32_T_Destructor(chartInstance, &c5_b);
}

static boolean_T c5_allinrange(SFc5_flightControlSystemInstanceStruct
  *chartInstance, c5_coder_array_real_T *c5_b_x, int32_T c5_hi)
{
  real_T c5_b_k;
  real_T c5_d;
  int32_T c5_exitg1;
  int32_T c5_i;
  int32_T c5_k;
  boolean_T c5_b;
  boolean_T c5_p;
  (void)chartInstance;
  c5_d = (real_T)c5_b_x->size[0];
  c5_i = (int32_T)c5_d - 1;
  c5_k = 0;
  do {
    c5_exitg1 = 0;
    if (c5_k <= c5_i) {
      c5_b_k = (real_T)c5_k + 1.0;
      if ((c5_b_x->vector.data[(int32_T)c5_b_k - 1] >= 1.0) &&
          (c5_b_x->vector.data[(int32_T)c5_b_k - 1] <= (real_T)c5_hi)) {
        c5_b = true;
      } else {
        c5_b = false;
      }

      if (!c5_b) {
        c5_p = false;
        c5_exitg1 = 1;
      } else {
        c5_k++;
      }
    } else {
      c5_p = true;
      c5_exitg1 = 1;
    }
  } while (c5_exitg1 == 0);

  return c5_p;
}

static void c5_eml_float_colon(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, real_T c5_c_a, real_T c5_b, real_T
  c5_y_data[], int32_T c5_y_size[2])
{
  emlrtStack c5_b_st;
  emlrtStack c5_st;
  real_T c5_a1;
  real_T c5_apnd;
  real_T c5_b1;
  real_T c5_b_b;
  real_T c5_b_x;
  real_T c5_b_y;
  real_T c5_c;
  real_T c5_c_b;
  real_T c5_c_x;
  real_T c5_c_y;
  real_T c5_cdiff;
  real_T c5_d_a;
  real_T c5_d_x;
  real_T c5_e_a;
  real_T c5_e_x;
  real_T c5_f_x;
  real_T c5_g_x;
  real_T c5_h_x;
  real_T c5_i_x;
  real_T c5_j_x;
  real_T c5_k_x;
  real_T c5_kd;
  real_T c5_l_x;
  real_T c5_ndbl;
  real_T c5_thresh;
  real_T c5_y;
  int32_T c5_b_k;
  int32_T c5_d_b;
  int32_T c5_d_y;
  int32_T c5_e_b;
  int32_T c5_f_a;
  int32_T c5_f_b;
  int32_T c5_i;
  int32_T c5_k;
  int32_T c5_n;
  int32_T c5_nm1;
  int32_T c5_nm1d2;
  boolean_T c5_overflow;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_d_a = c5_c_a;
  c5_b_b = c5_b;
  c5_a1 = c5_d_a;
  c5_b_x = (c5_b_b - c5_d_a) / 0.5 + 0.5;
  c5_c_x = c5_b_x;
  c5_ndbl = c5_c_x;
  c5_ndbl = muDoubleScalarFloor(c5_ndbl);
  c5_apnd = c5_d_a + c5_ndbl * 0.5;
  c5_cdiff = c5_apnd - c5_b_b;
  c5_e_a = c5_d_a;
  c5_c_b = c5_b_b;
  c5_d_x = c5_e_a;
  c5_e_x = c5_d_x;
  c5_f_x = c5_e_x;
  c5_y = muDoubleScalarAbs(c5_f_x);
  c5_g_x = c5_c_b;
  c5_h_x = c5_g_x;
  c5_i_x = c5_h_x;
  c5_b_y = muDoubleScalarAbs(c5_i_x);
  c5_c = muDoubleScalarMax(c5_y, c5_b_y);
  c5_thresh = 4.4408920985006262E-16 * c5_c;
  c5_j_x = c5_cdiff;
  c5_k_x = c5_j_x;
  c5_l_x = c5_k_x;
  c5_c_y = muDoubleScalarAbs(c5_l_x);
  if (c5_c_y < c5_thresh) {
    c5_ndbl++;
    c5_b1 = c5_b_b;
  } else if (c5_cdiff > 0.0) {
    c5_b1 = c5_d_a + (c5_ndbl - 1.0) * 0.5;
  } else {
    c5_ndbl++;
    c5_b1 = c5_apnd;
  }

  if (c5_ndbl >= 0.0) {
    c5_n = (int32_T)muDoubleScalarFloor(c5_ndbl);
  } else {
    c5_n = 0;
  }

  c5_y_size[0] = 1;
  c5_y_size[1] = c5_n;
  if (c5_n > 0) {
    c5_y_data[0] = c5_a1;
    if (c5_n > 1) {
      c5_y_data[c5_n - 1] = c5_b1;
      c5_nm1 = c5_n - 1;
      c5_f_a = c5_nm1;
      c5_nm1d2 = (uint16_T)((uint32_T)(uint16_T)c5_f_a >> 1);
      c5_i = c5_nm1d2 - 2;
      c5_st.site = &c5_df_emlrtRSI;
      c5_d_b = c5_i + 1;
      c5_e_b = c5_d_b;
      if (c5_e_b < 1) {
        c5_overflow = false;
      } else {
        c5_overflow = (c5_e_b > 2147483646);
      }

      if (c5_overflow) {
        c5_b_st.site = &c5_v_emlrtRSI;
        c5_check_forloop_overflow_error(chartInstance, &c5_b_st);
      }

      for (c5_k = 0; c5_k <= c5_i; c5_k++) {
        c5_b_k = c5_k + 1;
        c5_kd = (real_T)c5_b_k * 0.5;
        c5_y_data[c5_b_k] = c5_a1 + c5_kd;
        c5_y_data[(c5_n - c5_b_k) - 1] = c5_b1 - c5_kd;
      }

      c5_f_b = c5_nm1d2;
      c5_d_y = c5_f_b << 1;
      if (c5_d_y == c5_nm1) {
        c5_y_data[c5_nm1d2] = (c5_a1 + c5_b1) / 2.0;
      } else {
        c5_kd = (real_T)c5_nm1d2 * 0.5;
        c5_y_data[c5_nm1d2] = c5_a1 + c5_kd;
        c5_y_data[c5_nm1d2 + 1] = c5_b1 - c5_kd;
      }
    }
  }
}

static void c5_log(SFc5_flightControlSystemInstanceStruct *chartInstance, const
                   emlrtStack *c5_sp, real_T c5_x_data[], int32_T c5_x_size[2],
                   real_T c5_b_x_data[], int32_T c5_b_x_size[2])
{
  int32_T c5_i;
  int32_T c5_loop_ub;
  c5_b_x_size[0] = 1;
  c5_b_x_size[1] = c5_x_size[1];
  c5_loop_ub = c5_x_size[1] - 1;
  for (c5_i = 0; c5_i <= c5_loop_ub; c5_i++) {
    c5_b_x_data[c5_i] = c5_x_data[c5_i];
  }

  c5_b_log(chartInstance, c5_sp, c5_b_x_data, c5_b_x_size);
}

static void c5_exp(SFc5_flightControlSystemInstanceStruct *chartInstance, const
                   emlrtStack *c5_sp, creal_T c5_x_data[], int32_T c5_x_size[2],
                   creal_T c5_b_x_data[], int32_T c5_b_x_size[2])
{
  int32_T c5_i;
  int32_T c5_loop_ub;
  c5_b_x_size[0] = 1;
  c5_b_x_size[1] = c5_x_size[1];
  c5_loop_ub = c5_x_size[1] - 1;
  for (c5_i = 0; c5_i <= c5_loop_ub; c5_i++) {
    c5_b_x_data[c5_i] = c5_x_data[c5_i];
  }

  c5_b_exp(chartInstance, c5_sp, c5_b_x_data, c5_b_x_size);
}

static void c5_chcenters(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, creal_T c5_varargin_1[19200],
  c5_coder_array_real_T_2D *c5_centers, c5_coder_array_real_T_2D *c5_metric)
{
  static int32_T c5_offsets[25] = { -250, -249, -248, -247, -246, -126, -125,
    -124, -123, -122, -2, -1, 0, 1, 2, 122, 123, 124, 125, 126, 246, 247, 248,
    249, 250 };

  static char_T c5_b_cv[35] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'i', 'm', 'r',
    'e', 'g', 'i', 'o', 'n', 'a', 'l', 'm', 'a', 'x', ':', 'e', 'x', 'p', 'e',
    'c', 't', 'e', 'd', 'N', 'o', 'n', 'N', 'a', 'N' };

  static char_T c5_b_cv3[25] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'u',
    'b', 's', 'd', 'e', 'l', 'd', 'i', 'm', 'm', 'i', 's', 'm', 'a', 't', 'c',
    'h' };

  static char_T c5_b_cv2[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o',
    'l', 'o', 'g', 'i', 'c', 'a', 'l', 'n', 'a', 'n' };

  static char_T c5_b_cv1[18] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm',
    'b', 'e', 'r', ' ', '1', ',', ' ', 'I', ',' };

  c5_coder_array_int32_T c5_r;
  c5_coder_array_int32_T_2D c5_iidx;
  c5_coder_array_real_T c5_b_centers;
  c5_coder_array_real_T c5_b_varargin_2;
  c5_coder_array_real_T c5_c_centers;
  c5_coder_array_real_T c5_ndx;
  c5_coder_array_real_T_2D c5_e_centers;
  c5_coder_array_real_T_2D c5_f_x;
  c5_coder_array_real_T_2D c5_j_x;
  c5_coder_array_real_T_2D c5_sortIdx;
  c5_coder_array_sOA5t73y81YtFHGIDxk c5_b_s;
  emlrtStack c5_b_st;
  emlrtStack c5_c_st;
  emlrtStack c5_d_st;
  emlrtStack c5_st;
  const mxArray *c5_b_y = NULL;
  const mxArray *c5_c_y = NULL;
  const mxArray *c5_d_y = NULL;
  const mxArray *c5_e_y = NULL;
  const mxArray *c5_f_y = NULL;
  const mxArray *c5_h_y = NULL;
  const mxArray *c5_i_y = NULL;
  const mxArray *c5_j_y = NULL;
  const mxArray *c5_k_y = NULL;
  creal_T c5_b_x;
  real_T c5_domainSizeT[2];
  real_T c5_sizeB[2];
  real_T c5_startIdxT[2];
  real_T c5_b;
  real_T c5_b_accumMatrixRe;
  real_T c5_b_idx;
  real_T c5_c_a;
  real_T c5_c_j;
  real_T c5_c_x;
  real_T c5_d;
  real_T c5_d1;
  real_T c5_d_a;
  real_T c5_d_i;
  real_T c5_d_k;
  real_T c5_d_x;
  real_T c5_e_a;
  real_T c5_e_x;
  real_T c5_f_a;
  real_T c5_f_k;
  real_T c5_g_a;
  real_T c5_g_x;
  real_T c5_h_k;
  real_T c5_h_x;
  real_T c5_x1;
  real_T c5_x2;
  real_T c5_y;
  int32_T c5_b_iv[2];
  int32_T c5_b_iv1[2];
  int32_T c5_tmp_data[2];
  int32_T c5_b_sortIdx[1];
  int32_T c5_b_c;
  int32_T c5_b_i;
  int32_T c5_b_j;
  int32_T c5_b_k;
  int32_T c5_b_loop_ub;
  int32_T c5_c;
  int32_T c5_c_c;
  int32_T c5_c_i;
  int32_T c5_c_idx;
  int32_T c5_c_k;
  int32_T c5_c_loop_ub;
  int32_T c5_d_c;
  int32_T c5_d_centers;
  int32_T c5_d_idx;
  int32_T c5_d_j;
  int32_T c5_d_loop_ub;
  int32_T c5_e_i;
  int32_T c5_e_idx;
  int32_T c5_e_j;
  int32_T c5_e_k;
  int32_T c5_e_loop_ub;
  int32_T c5_f_i;
  int32_T c5_f_idx;
  int32_T c5_f_j;
  int32_T c5_f_loop_ub;
  int32_T c5_g_b;
  int32_T c5_g_i;
  int32_T c5_g_idx;
  int32_T c5_g_j;
  int32_T c5_g_k;
  int32_T c5_g_loop_ub;
  int32_T c5_g_y;
  int32_T c5_h_a;
  int32_T c5_h_b;
  int32_T c5_h_i;
  int32_T c5_h_j;
  int32_T c5_h_loop_ub;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i10;
  int32_T c5_i11;
  int32_T c5_i12;
  int32_T c5_i13;
  int32_T c5_i14;
  int32_T c5_i15;
  int32_T c5_i16;
  int32_T c5_i17;
  int32_T c5_i18;
  int32_T c5_i19;
  int32_T c5_i2;
  int32_T c5_i20;
  int32_T c5_i21;
  int32_T c5_i22;
  int32_T c5_i23;
  int32_T c5_i24;
  int32_T c5_i25;
  int32_T c5_i26;
  int32_T c5_i27;
  int32_T c5_i28;
  int32_T c5_i29;
  int32_T c5_i3;
  int32_T c5_i30;
  int32_T c5_i31;
  int32_T c5_i32;
  int32_T c5_i33;
  int32_T c5_i34;
  int32_T c5_i35;
  int32_T c5_i36;
  int32_T c5_i37;
  int32_T c5_i38;
  int32_T c5_i39;
  int32_T c5_i4;
  int32_T c5_i40;
  int32_T c5_i41;
  int32_T c5_i42;
  int32_T c5_i43;
  int32_T c5_i44;
  int32_T c5_i45;
  int32_T c5_i5;
  int32_T c5_i6;
  int32_T c5_i7;
  int32_T c5_i8;
  int32_T c5_i9;
  int32_T c5_i_a;
  int32_T c5_i_loop_ub;
  int32_T c5_i_x;
  int32_T c5_idx;
  int32_T c5_j;
  int32_T c5_j_loop_ub;
  int32_T c5_k;
  int32_T c5_k_loop_ub;
  int32_T c5_l_loop_ub;
  int32_T c5_loop_ub;
  int32_T c5_m_loop_ub;
  int32_T c5_n;
  int32_T c5_nrows;
  int32_T c5_nrowx;
  boolean_T c5_bw[19200];
  boolean_T c5_x_data[19200];
  boolean_T c5_conn[9];
  boolean_T c5_b1;
  boolean_T c5_b2;
  boolean_T c5_b_b;
  boolean_T c5_b_p;
  boolean_T c5_c_b;
  boolean_T c5_c_p;
  boolean_T c5_d_b;
  boolean_T c5_e_b;
  boolean_T c5_exitg1;
  boolean_T c5_f_b;
  boolean_T c5_flat;
  boolean_T c5_guard1;
  boolean_T c5_overflow;
  boolean_T c5_p;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_c_st.prev = &c5_b_st;
  c5_c_st.tls = c5_b_st.tls;
  c5_d_st.prev = &c5_c_st;
  c5_d_st.tls = c5_c_st.tls;
  c5_st.site = &c5_qk_emlrtRSI;
  c5_array_real_T_2D_SetSize(chartInstance, &c5_st, c5_centers, &c5_oc_emlrtRTEI,
    0, 0);
  c5_st.site = &c5_pk_emlrtRSI;
  c5_array_real_T_2D_SetSize(chartInstance, &c5_st, c5_metric, &c5_pc_emlrtRTEI,
    0, 0);
  for (c5_k = 0; c5_k < 19200; c5_k++) {
    c5_b_k = c5_k;
    c5_b_x = c5_varargin_1[c5_b_k];
    c5_x1 = c5_b_x.re;
    c5_x2 = c5_b_x.im;
    c5_c_a = c5_x1;
    c5_b = c5_x2;
    c5_y = muDoubleScalarHypot(c5_c_a, c5_b);
    chartInstance->c5_accumMatrixRe[c5_b_k] = c5_y;
  }

  c5_b_accumMatrixRe = chartInstance->c5_accumMatrixRe[0];
  for (c5_i = 0; c5_i < 19200; c5_i++) {
    c5_bw[c5_i] = (chartInstance->c5_accumMatrixRe[c5_i] == c5_b_accumMatrixRe);
  }

  for (c5_i1 = 0; c5_i1 < 19200; c5_i1++) {
    c5_x_data[c5_i1] = c5_bw[c5_i1];
  }

  c5_flat = true;
  c5_c_k = 0;
  c5_exitg1 = false;
  while ((!c5_exitg1) && (c5_c_k < 19200)) {
    c5_d_k = (real_T)c5_c_k + 1.0;
    if (!c5_x_data[(int32_T)c5_d_k - 1]) {
      c5_flat = false;
      c5_exitg1 = true;
    } else {
      c5_c_k++;
    }
  }

  if (!c5_flat) {
    c5_st.site = &c5_qf_emlrtRSI;
    c5_b_st.site = &c5_xf_emlrtRSI;
    c5_c_st.site = &c5_yf_emlrtRSI;
    for (c5_j = 0; c5_j < 2; c5_j++) {
      c5_c_j = (real_T)c5_j + 1.0;
      for (c5_b_i = 0; c5_b_i < 124; c5_b_i++) {
        c5_d_i = (real_T)c5_b_i + 1.0;
        chartInstance->c5_Apad[((int32_T)c5_d_i + 124 * ((int32_T)c5_c_j - 1)) -
          1] = 0.0;
      }
    }

    for (c5_b_j = 0; c5_b_j < 2; c5_b_j++) {
      for (c5_c_i = 0; c5_c_i < 124; c5_c_i++) {
        c5_d_i = (real_T)c5_c_i + 1.0;
        chartInstance->c5_Apad[((int32_T)c5_d_i + 124 * (c5_b_j + 162)) - 1] =
          0.0;
      }
    }

    for (c5_d_j = 0; c5_d_j < 160; c5_d_j++) {
      c5_c_j = (real_T)c5_d_j + 1.0;
      for (c5_e_i = 0; c5_e_i < 2; c5_e_i++) {
        c5_d_i = (real_T)c5_e_i + 1.0;
        c5_d_a = c5_c_j;
        c5_c = (int32_T)c5_d_a;
        chartInstance->c5_Apad[((int32_T)c5_d_i + 124 * (c5_c + 1)) - 1] = 0.0;
      }
    }

    for (c5_e_j = 0; c5_e_j < 160; c5_e_j++) {
      c5_c_j = (real_T)c5_e_j + 1.0;
      for (c5_f_i = 0; c5_f_i < 2; c5_f_i++) {
        c5_e_a = c5_c_j;
        c5_b_c = (int32_T)c5_e_a;
        chartInstance->c5_Apad[(c5_f_i + 124 * (c5_b_c + 1)) + 122] = 0.0;
      }
    }

    for (c5_f_j = 0; c5_f_j < 160; c5_f_j++) {
      c5_c_j = (real_T)c5_f_j + 1.0;
      for (c5_g_i = 0; c5_g_i < 120; c5_g_i++) {
        c5_d_i = (real_T)c5_g_i + 1.0;
        c5_f_a = c5_d_i;
        c5_c_c = (int32_T)c5_f_a;
        c5_g_a = c5_c_j;
        c5_d_c = (int32_T)c5_g_a;
        chartInstance->c5_Apad[(c5_c_c + 124 * (c5_d_c + 1)) + 1] =
          chartInstance->c5_accumMatrixRe[((int32_T)c5_d_i + 120 * ((int32_T)
          c5_c_j - 1)) - 1];
      }
    }

    c5_c_st.site = &c5_ag_emlrtRSI;
    c5_d_st.site = &c5_bg_emlrtRSI;
    for (c5_i2 = 0; c5_i2 < 2; c5_i2++) {
      c5_domainSizeT[c5_i2] = 5.0;
    }

    for (c5_i3 = 0; c5_i3 < 2; c5_i3++) {
      c5_startIdxT[c5_i3] = 2.0;
    }

    for (c5_i4 = 0; c5_i4 < 2; c5_i4++) {
      c5_sizeB[c5_i4] = 120.0 + 40.0 * (real_T)c5_i4;
    }

    ordfilt2_real64(&chartInstance->c5_Apad[0], 124.0, &c5_startIdxT[0],
                    &c5_offsets[0], 25.0, &c5_domainSizeT[0], 12.0,
                    &chartInstance->c5_Hd[0], &c5_sizeB[0], true);
    c5_st.site = &c5_rf_emlrtRSI;
    c5_b_st.site = &c5_cg_emlrtRSI;
    for (c5_i5 = 0; c5_i5 < 19200; c5_i5++) {
      chartInstance->c5_marker[c5_i5] = chartInstance->c5_Hd[c5_i5] -
        0.099999999999999964;
    }

    c5_c_st.site = &c5_dg_emlrtRSI;
    c5_validateattributes(chartInstance, &c5_c_st, chartInstance->c5_marker);
    c5_c_st.site = &c5_eg_emlrtRSI;
    c5_validateattributes(chartInstance, &c5_c_st, chartInstance->c5_Hd);
    c5_c_st.site = &c5_qd_emlrtRSI;
    for (c5_i6 = 0; c5_i6 < 19200; c5_i6++) {
      chartInstance->c5_mask[c5_i6] = chartInstance->c5_Hd[c5_i6];
    }

    for (c5_i7 = 0; c5_i7 < 19200; c5_i7++) {
      chartInstance->c5_Hd[c5_i7] = chartInstance->c5_marker[c5_i7];
    }

    for (c5_i8 = 0; c5_i8 < 2; c5_i8++) {
      c5_domainSizeT[c5_i8] = 120.0 + 40.0 * (real_T)c5_i8;
    }

    ippreconstruct_real64(&chartInstance->c5_Hd[0], &chartInstance->c5_mask[0],
                          &c5_domainSizeT[0], 2.0);
    c5_st.site = &c5_sf_emlrtRSI;
    c5_b_st.site = &c5_fg_emlrtRSI;
    c5_c_st.site = &c5_ad_emlrtRSI;
    c5_p = true;
    c5_e_k = 0;
    c5_exitg1 = false;
    while ((!c5_exitg1) && (c5_e_k < 19200)) {
      c5_f_k = (real_T)c5_e_k + 1.0;
      c5_c_x = chartInstance->c5_Hd[(int32_T)c5_f_k - 1];
      c5_d_x = c5_c_x;
      c5_c_b = muDoubleScalarIsNaN(c5_d_x);
      c5_b_p = !c5_c_b;
      if (c5_b_p) {
        c5_e_k++;
      } else {
        c5_p = false;
        c5_exitg1 = true;
      }
    }

    if (c5_p) {
      c5_b_b = true;
    } else {
      c5_b_b = false;
    }

    if (!c5_b_b) {
      c5_b_y = NULL;
      sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1, 35),
                    false);
      c5_c_y = NULL;
      sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_cv5, 10, 0U, 1, 0U, 2, 1, 46),
                    false);
      c5_d_y = NULL;
      sf_mex_assign(&c5_d_y, sf_mex_create("y", c5_b_cv1, 10, 0U, 1, 0U, 2, 1,
        18), false);
      sf_mex_call(&c5_c_st, &c5_l_emlrtMCI, "error", 0U, 2U, 14, c5_b_y, 14,
                  sf_mex_call(&c5_c_st, NULL, "getString", 1U, 1U, 14,
        sf_mex_call(&c5_c_st, NULL, "message", 1U, 2U, 14, c5_c_y, 14, c5_d_y)));
    }

    c5_b_st.site = &c5_gg_emlrtRSI;
    for (c5_g_k = 0; c5_g_k < 19200; c5_g_k++) {
      c5_h_k = (real_T)c5_g_k + 1.0;
      c5_e_x = chartInstance->c5_Hd[(int32_T)c5_h_k - 1];
      c5_d_b = muDoubleScalarIsNaN(c5_e_x);
      if (c5_d_b) {
        c5_e_y = NULL;
        sf_mex_assign(&c5_e_y, sf_mex_create("y", c5_b_cv2, 10, 0U, 1, 0U, 2, 1,
          19), false);
        c5_f_y = NULL;
        sf_mex_assign(&c5_f_y, sf_mex_create("y", c5_b_cv2, 10, 0U, 1, 0U, 2, 1,
          19), false);
        sf_mex_call(&c5_b_st, &c5_j_emlrtMCI, "error", 0U, 2U, 14, c5_e_y, 14,
                    sf_mex_call(&c5_b_st, NULL, "getString", 1U, 1U, 14,
          sf_mex_call(&c5_b_st, NULL, "message", 1U, 1U, 14, c5_f_y)));
      }
    }

    c5_b_st.site = &c5_hg_emlrtRSI;
    for (c5_i9 = 0; c5_i9 < 9; c5_i9++) {
      c5_conn[c5_i9] = true;
    }

    for (c5_i10 = 0; c5_i10 < 2; c5_i10++) {
      c5_domainSizeT[c5_i10] = 120.0 + 40.0 * (real_T)c5_i10;
    }

    for (c5_i11 = 0; c5_i11 < 2; c5_i11++) {
      c5_startIdxT[c5_i11] = 3.0;
    }

    imregionalmax_real64(&chartInstance->c5_Hd[0], &c5_bw[0], 2.0,
                         &c5_domainSizeT[0], &c5_conn[0], 2.0, &c5_startIdxT[0]);
    c5_array_sOA5t73y81YtFHGIDxk0fKF_C(chartInstance, &c5_b_s);
    c5_st.site = &c5_tf_emlrtRSI;
    c5_regionprops(chartInstance, &c5_st, c5_bw, chartInstance->c5_accumMatrixRe,
                   &c5_b_s);
    if (c5_b_s.size[0] != 0) {
      c5_st.site = &c5_ok_emlrtRSI;
      c5_array_real_T_2D_SetSize(chartInstance, &c5_st, c5_centers,
        &c5_qc_emlrtRTEI, c5_b_s.size[0], 2);
      c5_d = (real_T)c5_b_s.size[0];
      c5_i12 = (int32_T)c5_d - 1;
      for (c5_idx = 0; c5_idx <= c5_i12; c5_idx++) {
        c5_b_idx = (real_T)c5_idx + 1.0;
        c5_i14 = c5_centers->size[0];
        c5_i15 = (int32_T)c5_b_idx;
        if ((c5_i15 < 1) || (c5_i15 > c5_i14)) {
          emlrtDynamicBoundsCheckR2012b(c5_i15, 1, c5_i14, &c5_tc_emlrtBCI,
            (emlrtConstCTX)c5_sp);
        }

        c5_i16 = c5_i15;
        for (c5_i17 = 0; c5_i17 < 2; c5_i17++) {
          c5_tmp_data[c5_i17] = c5_i17;
        }

        for (c5_i20 = 0; c5_i20 < 2; c5_i20++) {
          c5_b_iv[c5_i20] = 1 + c5_i20;
        }

        for (c5_i21 = 0; c5_i21 < 2; c5_i21++) {
          c5_b_iv1[c5_i21] = 1 + c5_i21;
        }

        emlrtSubAssignSizeCheckR2012b(&c5_b_iv[0], 2, &c5_b_iv1[0], 2,
          &c5_b_emlrtECI, (void *)c5_sp);
        c5_i22 = c5_i16 - 1;
        for (c5_i23 = 0; c5_i23 < 2; c5_i23++) {
          c5_i27 = c5_b_s.size[0];
          c5_i28 = (int32_T)c5_b_idx;
          if ((c5_i28 < 1) || (c5_i28 > c5_i27)) {
            emlrtDynamicBoundsCheckR2012b(c5_i28, 1, c5_i27, &c5_vc_emlrtBCI,
              (emlrtConstCTX)c5_sp);
          }

          c5_centers->vector.data[c5_i22 + c5_centers->size[0] *
            c5_tmp_data[c5_i23]] = c5_b_s.vector.data[c5_i28 - 1].
            WeightedCentroid[c5_i23];
        }
      }

      c5_d1 = (real_T)c5_centers->size[0];
      c5_i13 = (int32_T)-((-1.0 - c5_d1) + 1.0);
      emlrtForLoopVectorCheckR2021a(c5_d1, -1.0, 1.0, mxDOUBLE_CLASS, c5_i13,
        &c5_ai_emlrtRTEI, (emlrtConstCTX)c5_sp);
      c5_array_real_T_2D_Constructor(chartInstance, &c5_f_x);
      for (c5_c_idx = 0; c5_c_idx < c5_i13; c5_c_idx++) {
        c5_b_idx = c5_d1 - (real_T)c5_c_idx;
        c5_i18 = c5_centers->size[0];
        c5_i19 = (int32_T)c5_b_idx;
        if ((c5_i19 < 1) || (c5_i19 > c5_i18)) {
          emlrtDynamicBoundsCheckR2012b(c5_i19, 1, c5_i18, &c5_uc_emlrtBCI,
            (emlrtConstCTX)c5_sp);
        }

        c5_g_x = c5_centers->vector.data[c5_i19 - 1];
        c5_e_b = muDoubleScalarIsNaN(c5_g_x);
        c5_guard1 = false;
        if (c5_e_b) {
          c5_guard1 = true;
        } else {
          c5_i25 = c5_centers->size[0];
          c5_i26 = (int32_T)c5_b_idx;
          if ((c5_i26 < 1) || (c5_i26 > c5_i25)) {
            emlrtDynamicBoundsCheckR2012b(c5_i26, 1, c5_i25, &c5_wc_emlrtBCI,
              (emlrtConstCTX)c5_sp);
          }

          c5_h_x = c5_centers->vector.data[(c5_i26 + c5_centers->size[0]) - 1];
          c5_f_b = muDoubleScalarIsNaN(c5_h_x);
          if (c5_f_b) {
            c5_guard1 = true;
          }
        }

        if (c5_guard1) {
          c5_st.site = &c5_uf_emlrtRSI;
          c5_b_st.site = &c5_uf_emlrtRSI;
          c5_array_real_T_2D_SetSize(chartInstance, &c5_b_st, &c5_f_x,
            &c5_sc_emlrtRTEI, c5_centers->size[0], c5_centers->size[1]);
          c5_b_loop_ub = c5_centers->size[0] * c5_centers->size[1] - 1;
          for (c5_i29 = 0; c5_i29 <= c5_b_loop_ub; c5_i29++) {
            c5_f_x.vector.data[c5_i29] = c5_centers->vector.data[c5_i29];
          }

          c5_d_idx = (int32_T)c5_b_idx;
          c5_b_st.site = &c5_li_emlrtRSI;
          c5_e_idx = c5_d_idx;
          c5_f_idx = c5_e_idx;
          c5_n = c5_f_x.size[0];
          c5_c_p = true;
          if (c5_f_idx > c5_n) {
            c5_c_p = false;
          } else {
            c5_i_x = c5_f_idx;
            c5_g_y = c5_i_x;
            if (c5_f_idx != c5_g_y) {
              c5_c_p = false;
            }
          }

          if (!c5_c_p) {
            c5_h_y = NULL;
            sf_mex_assign(&c5_h_y, sf_mex_create("y", c5_b_cv3, 10, 0U, 1, 0U, 2,
              1, 25), false);
            c5_i_y = NULL;
            sf_mex_assign(&c5_i_y, sf_mex_create("y", c5_b_cv3, 10, 0U, 1, 0U, 2,
              1, 25), false);
            sf_mex_call(&c5_b_st, &c5_cb_emlrtMCI, "error", 0U, 2U, 14, c5_h_y,
                        14, sf_mex_call(&c5_b_st, NULL, "getString", 1U, 1U, 14,
              sf_mex_call(&c5_b_st, NULL, "message", 1U, 1U, 14, c5_i_y)));
          }

          c5_b_st.site = &c5_mi_emlrtRSI;
          c5_g_idx = c5_d_idx;
          c5_nrowx = c5_f_x.size[0];
          c5_nrows = c5_nrowx - 1;
          c5_c_st.site = &c5_ni_emlrtRSI;
          for (c5_g_j = 0; c5_g_j < 2; c5_g_j++) {
            c5_h_j = c5_g_j;
            c5_c_st.site = &c5_oi_emlrtRSI;
            c5_h_a = c5_g_idx;
            c5_g_b = c5_nrows;
            c5_i_a = c5_h_a;
            c5_h_b = c5_g_b;
            if (c5_i_a > c5_h_b) {
              c5_overflow = false;
            } else {
              c5_overflow = (c5_h_b > 2147483646);
            }

            if (c5_overflow) {
              c5_d_st.site = &c5_v_emlrtRSI;
              c5_check_forloop_overflow_error(chartInstance, &c5_d_st);
            }

            for (c5_h_i = c5_g_idx; c5_h_i <= c5_nrows; c5_h_i++) {
              c5_f_x.vector.data[(c5_h_i + c5_f_x.size[0] * c5_h_j) - 1] =
                c5_f_x.vector.data[c5_h_i + c5_f_x.size[0] * c5_h_j];
            }
          }

          if (c5_nrows > c5_nrowx) {
            c5_j_y = NULL;
            sf_mex_assign(&c5_j_y, sf_mex_create("y", c5_cv3, 10, 0U, 1, 0U, 2,
              1, 30), false);
            c5_k_y = NULL;
            sf_mex_assign(&c5_k_y, sf_mex_create("y", c5_cv3, 10, 0U, 1, 0U, 2,
              1, 30), false);
            sf_mex_call(&c5_b_st, &c5_db_emlrtMCI, "error", 0U, 2U, 14, c5_j_y,
                        14, sf_mex_call(&c5_b_st, NULL, "getString", 1U, 1U, 14,
              sf_mex_call(&c5_b_st, NULL, "message", 1U, 1U, 14, c5_k_y)));
          }

          c5_b2 = (c5_nrows < 1);
          if (c5_b2) {
            c5_i34 = -1;
          } else {
            c5_i34 = c5_nrows - 1;
          }

          for (c5_i36 = 0; c5_i36 < 2; c5_i36++) {
            c5_g_loop_ub = c5_i34;
            for (c5_i37 = 0; c5_i37 <= c5_g_loop_ub; c5_i37++) {
              c5_f_x.vector.data[c5_i37 + (c5_i34 + 1) * c5_i36] =
                c5_f_x.vector.data[c5_i37 + c5_f_x.size[0] * c5_i36];
            }
          }

          c5_array_real_T_2D_SetSize(chartInstance, &c5_b_st, &c5_f_x,
            &c5_tc_emlrtRTEI, c5_i34 + 1, 2);
          c5_st.site = &c5_uf_emlrtRSI;
          c5_array_real_T_2D_SetSize(chartInstance, &c5_st, c5_centers,
            &c5_sc_emlrtRTEI, c5_f_x.size[0], 2);
          c5_h_loop_ub = (c5_f_x.size[0] << 1) - 1;
          for (c5_i38 = 0; c5_i38 <= c5_h_loop_ub; c5_i38++) {
            c5_centers->vector.data[c5_i38] = c5_f_x.vector.data[c5_i38];
          }
        }
      }

      c5_array_real_T_2D_Destructor(chartInstance, &c5_f_x);
      c5_b1 = (c5_centers->size[0] == 0);
      if (!c5_b1) {
        c5_array_real_T_Constructor(chartInstance, &c5_ndx);
        c5_st.site = &c5_vf_emlrtRSI;
        c5_array_real_T_Constructor(chartInstance, &c5_b_centers);
        c5_b_st.site = &c5_vf_emlrtRSI;
        c5_array_real_T_SetSize(chartInstance, &c5_b_st, &c5_b_centers,
          &c5_uc_emlrtRTEI, c5_centers->size[0]);
        c5_loop_ub = c5_centers->size[0] - 1;
        for (c5_i24 = 0; c5_i24 <= c5_loop_ub; c5_i24++) {
          c5_b_centers.vector.data[c5_i24] = c5_centers->vector.data[c5_i24 +
            c5_centers->size[0]];
        }

        c5_b_st.site = &c5_vf_emlrtRSI;
        c5_round(chartInstance, &c5_b_st, &c5_b_centers, &c5_ndx);
        c5_array_real_T_Destructor(chartInstance, &c5_b_centers);
        c5_array_real_T_Constructor(chartInstance, &c5_c_centers);
        c5_b_st.site = &c5_vf_emlrtRSI;
        c5_array_real_T_SetSize(chartInstance, &c5_b_st, &c5_c_centers,
          &c5_vc_emlrtRTEI, c5_centers->size[0]);
        c5_c_loop_ub = c5_centers->size[0] - 1;
        for (c5_i30 = 0; c5_i30 <= c5_c_loop_ub; c5_i30++) {
          c5_c_centers.vector.data[c5_i30] = c5_centers->vector.data[c5_i30];
        }

        c5_array_real_T_Constructor(chartInstance, &c5_b_varargin_2);
        c5_b_st.site = &c5_vf_emlrtRSI;
        c5_round(chartInstance, &c5_b_st, &c5_c_centers, &c5_b_varargin_2);
        c5_array_real_T_Destructor(chartInstance, &c5_c_centers);
        c5_array_int32_T_Constructor(chartInstance, &c5_r);
        c5_b_st.site = &c5_bf_emlrtRSI;
        c5_sub2ind(chartInstance, &c5_b_st, &c5_ndx, &c5_b_varargin_2, &c5_r);
        c5_array_real_T_SetSize(chartInstance, &c5_st, &c5_ndx, &c5_hb_emlrtRTEI,
          c5_r.size[0]);
        c5_d_loop_ub = c5_r.size[0] - 1;
        for (c5_i31 = 0; c5_i31 <= c5_d_loop_ub; c5_i31++) {
          c5_ndx.vector.data[c5_i31] = (real_T)c5_r.vector.data[c5_i31];
        }

        c5_array_int32_T_Destructor(chartInstance, &c5_r);
        c5_st.site = &c5_vf_emlrtRSI;
        c5_array_real_T_SetSize(chartInstance, &c5_st, &c5_b_varargin_2,
          &c5_wc_emlrtRTEI, c5_ndx.size[0]);
        c5_e_loop_ub = c5_ndx.size[0] - 1;
        for (c5_i32 = 0; c5_i32 <= c5_e_loop_ub; c5_i32++) {
          c5_i33 = (int32_T)c5_ndx.vector.data[c5_i32];
          if ((c5_i33 < 1) || (c5_i33 > 19200)) {
            emlrtDynamicBoundsCheckR2012b(c5_i33, 1, 19200, &c5_xc_emlrtBCI,
              (emlrtConstCTX)c5_sp);
          }

          c5_b_varargin_2.vector.data[c5_i32] = chartInstance->c5_Hd[c5_i33 - 1];
        }

        c5_array_real_T_Destructor(chartInstance, &c5_ndx);
        c5_st.site = &c5_vf_emlrtRSI;
        c5_array_real_T_2D_SetSize(chartInstance, &c5_st, c5_metric,
          &c5_xc_emlrtRTEI, c5_b_varargin_2.size[0], 1);
        c5_f_loop_ub = c5_b_varargin_2.size[0] - 1;
        for (c5_i35 = 0; c5_i35 <= c5_f_loop_ub; c5_i35++) {
          c5_metric->vector.data[c5_i35] = c5_b_varargin_2.vector.data[c5_i35];
        }

        c5_array_real_T_Destructor(chartInstance, &c5_b_varargin_2);
        c5_st.site = &c5_wf_emlrtRSI;
        c5_array_real_T_2D_Constructor(chartInstance, &c5_j_x);
        c5_b_st.site = &c5_wf_emlrtRSI;
        c5_array_real_T_2D_SetSize(chartInstance, &c5_b_st, &c5_j_x,
          &c5_yc_emlrtRTEI, c5_metric->size[0], c5_metric->size[1]);
        c5_i_loop_ub = c5_metric->size[0] * c5_metric->size[1] - 1;
        for (c5_i39 = 0; c5_i39 <= c5_i_loop_ub; c5_i39++) {
          c5_j_x.vector.data[c5_i39] = c5_metric->vector.data[c5_i39];
        }

        c5_array_int32_T_2D_Constructor(chartInstance, &c5_iidx);
        c5_b_st.site = &c5_qi_emlrtRSI;
        c5_b_sort(chartInstance, &c5_b_st, &c5_j_x, &c5_iidx);
        c5_array_real_T_2D_Constructor(chartInstance, &c5_sortIdx);
        c5_array_real_T_2D_SetSize(chartInstance, &c5_st, &c5_sortIdx,
          &c5_ad_emlrtRTEI, c5_iidx.size[0], 1);
        c5_j_loop_ub = c5_iidx.size[0] - 1;
        for (c5_i40 = 0; c5_i40 <= c5_j_loop_ub; c5_i40++) {
          c5_sortIdx.vector.data[c5_i40] = (real_T)c5_iidx.vector.data[c5_i40];
        }

        c5_array_int32_T_2D_Destructor(chartInstance, &c5_iidx);
        c5_st.site = &c5_wf_emlrtRSI;
        c5_array_real_T_2D_SetSize(chartInstance, &c5_st, c5_metric,
          &c5_bd_emlrtRTEI, c5_j_x.size[0], 1);
        c5_k_loop_ub = c5_j_x.size[0] - 1;
        for (c5_i41 = 0; c5_i41 <= c5_k_loop_ub; c5_i41++) {
          c5_metric->vector.data[c5_i41] = c5_j_x.vector.data[c5_i41];
        }

        c5_array_real_T_2D_Destructor(chartInstance, &c5_j_x);
        c5_d_centers = c5_centers->size[0];
        c5_b_sortIdx[0] = c5_sortIdx.size[0];
        c5_array_real_T_2D_Constructor(chartInstance, &c5_e_centers);
        c5_st.site = &c5_nk_emlrtRSI;
        c5_array_real_T_2D_SetSize(chartInstance, &c5_st, &c5_e_centers,
          &c5_cd_emlrtRTEI, c5_b_sortIdx[0], 2);
        for (c5_i42 = 0; c5_i42 < 2; c5_i42++) {
          c5_l_loop_ub = c5_b_sortIdx[0] - 1;
          for (c5_i43 = 0; c5_i43 <= c5_l_loop_ub; c5_i43++) {
            c5_i44 = (int32_T)c5_sortIdx.vector.data[c5_i43];
            if ((c5_i44 < 1) || (c5_i44 > c5_d_centers)) {
              emlrtDynamicBoundsCheckR2012b(c5_i44, 1, c5_d_centers,
                &c5_yc_emlrtBCI, (emlrtConstCTX)c5_sp);
            }

            c5_e_centers.vector.data[c5_i43 + c5_e_centers.size[0] * c5_i42] =
              c5_centers->vector.data[(c5_i44 + c5_centers->size[0] * c5_i42) -
              1];
          }
        }

        c5_array_real_T_2D_Destructor(chartInstance, &c5_sortIdx);
        c5_st.site = &c5_nk_emlrtRSI;
        c5_array_real_T_2D_SetSize(chartInstance, &c5_st, c5_centers,
          &c5_dd_emlrtRTEI, c5_e_centers.size[0], c5_e_centers.size[1]);
        c5_m_loop_ub = c5_e_centers.size[0] * c5_e_centers.size[1] - 1;
        for (c5_i45 = 0; c5_i45 <= c5_m_loop_ub; c5_i45++) {
          c5_centers->vector.data[c5_i45] = c5_e_centers.vector.data[c5_i45];
        }

        c5_array_real_T_2D_Destructor(chartInstance, &c5_e_centers);
      }
    }

    c5_array_sOA5t73y81YtFHGIDxk0fKF_D(chartInstance, &c5_b_s);
  }
}

static void c5_validateattributes(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, real_T c5_c_a[19200])
{
  static char_T c5_b_cv[35] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'i', 'm', 'r',
    'e', 'c', 'o', 'n', 's', 't', 'r', 'u', 'c', 't', ':', 'e', 'x', 'p', 'e',
    'c', 't', 'e', 'd', 'N', 'o', 'n', 'N', 'a', 'N' };

  static char_T c5_b_cv1[5] = { 'i', 'n', 'p', 'u', 't' };

  emlrtStack c5_st;
  const mxArray *c5_b_y = NULL;
  const mxArray *c5_c_y = NULL;
  const mxArray *c5_y = NULL;
  real_T c5_b_k;
  real_T c5_b_x;
  real_T c5_c_x;
  int32_T c5_k;
  boolean_T c5_b;
  boolean_T c5_b_b;
  boolean_T c5_b_p;
  boolean_T c5_exitg1;
  boolean_T c5_p;
  (void)chartInstance;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_st.site = &c5_ad_emlrtRSI;
  c5_p = true;
  c5_k = 0;
  c5_exitg1 = false;
  while ((!c5_exitg1) && (c5_k < 19200)) {
    c5_b_k = (real_T)c5_k + 1.0;
    c5_b_x = c5_c_a[(int32_T)c5_b_k - 1];
    c5_c_x = c5_b_x;
    c5_b_b = muDoubleScalarIsNaN(c5_c_x);
    c5_b_p = !c5_b_b;
    if (c5_b_p) {
      c5_k++;
    } else {
      c5_p = false;
      c5_exitg1 = true;
    }
  }

  if (c5_p) {
    c5_b = true;
  } else {
    c5_b = false;
  }

  if (!c5_b) {
    c5_y = NULL;
    sf_mex_assign(&c5_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1, 35),
                  false);
    c5_b_y = NULL;
    sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_cv5, 10, 0U, 1, 0U, 2, 1, 46),
                  false);
    c5_c_y = NULL;
    sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_b_cv1, 10, 0U, 1, 0U, 2, 1, 5),
                  false);
    sf_mex_call(&c5_st, &c5_l_emlrtMCI, "error", 0U, 2U, 14, c5_y, 14,
                sf_mex_call(&c5_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c5_st, NULL, "message", 1U, 2U, 14, c5_b_y, 14, c5_c_y)));
  }
}

static void c5_regionprops(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, boolean_T c5_varargin_1[19200], real_T
  c5_b_varargin_2[19200], c5_coder_array_sOA5t73y81YtFHGIDxk *c5_outstats)
{
  static char_T c5_b_cv[31] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'r', 'e', 'g',
    'i', 'o', 'n', 'p', 'r', 'o', 'p', 's', ':', 's', 'i', 'z', 'e', 'M', 'i',
    's', 'm', 'a', 't', 'c', 'h' };

  c5_coder_array_boolean_T c5_tile;
  c5_coder_array_int32_T c5_b_regionLengths;
  c5_coder_array_int32_T c5_idxCount;
  c5_coder_array_int32_T c5_regionLengths;
  c5_coder_array_real_T c5_regionIndices;
  c5_coder_array_s_R6Og1x0kmqQXSF9Pw c5_stats;
  c5_sHtk0WM4OMtyqkehwQYcq2 c5_statsAlreadyComputed;
  c5_sOA5t73y81YtFHGIDxk0fKF c5_b_s;
  c5_s_R6Og1x0kmqQXSF9Pwa49FD c5_statsOneObj;
  c5_s_jsRMsmv0Wf6iHXg8PgCG1G c5_CC;
  emlrtStack c5_b_st;
  emlrtStack c5_c_st;
  emlrtStack c5_d_st;
  emlrtStack c5_st;
  const mxArray *c5_b_y = NULL;
  const mxArray *c5_c_y = NULL;
  const mxArray *c5_d_y = NULL;
  const mxArray *c5_y = NULL;
  real_T c5_imageSize[2];
  real_T c5_b_k;
  real_T c5_b_numObjs;
  real_T c5_b_vIdx;
  real_T c5_c_numObjs;
  real_T c5_c_varargin_1;
  real_T c5_d;
  real_T c5_d1;
  real_T c5_d_k;
  real_T c5_d_numObjs;
  real_T c5_d_varargin_1;
  real_T c5_e_numObjs;
  real_T c5_f_k;
  real_T c5_numObjs;
  real_T c5_x1;
  real_T c5_x2;
  int32_T c5_b_outsize[2];
  int32_T c5_outsize[2];
  int32_T c5_b_loop_ub;
  int32_T c5_c_k;
  int32_T c5_c_loop_ub;
  int32_T c5_d_loop_ub;
  int32_T c5_dim;
  int32_T c5_e_k;
  int32_T c5_e_loop_ub;
  int32_T c5_f_loop_ub;
  int32_T c5_g_loop_ub;
  int32_T c5_h_loop_ub;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i10;
  int32_T c5_i11;
  int32_T c5_i12;
  int32_T c5_i13;
  int32_T c5_i14;
  int32_T c5_i15;
  int32_T c5_i16;
  int32_T c5_i17;
  int32_T c5_i18;
  int32_T c5_i19;
  int32_T c5_i2;
  int32_T c5_i20;
  int32_T c5_i21;
  int32_T c5_i22;
  int32_T c5_i23;
  int32_T c5_i24;
  int32_T c5_i25;
  int32_T c5_i26;
  int32_T c5_i27;
  int32_T c5_i28;
  int32_T c5_i29;
  int32_T c5_i3;
  int32_T c5_i30;
  int32_T c5_i31;
  int32_T c5_i32;
  int32_T c5_i33;
  int32_T c5_i34;
  int32_T c5_i35;
  int32_T c5_i36;
  int32_T c5_i37;
  int32_T c5_i38;
  int32_T c5_i39;
  int32_T c5_i4;
  int32_T c5_i40;
  int32_T c5_i41;
  int32_T c5_i42;
  int32_T c5_i43;
  int32_T c5_i5;
  int32_T c5_i6;
  int32_T c5_i7;
  int32_T c5_i8;
  int32_T c5_i9;
  int32_T c5_i_loop_ub;
  int32_T c5_k;
  int32_T c5_loop_ub;
  int32_T c5_vIdx;
  boolean_T c5_b_varargin_1[19200];
  boolean_T c5_b;
  boolean_T c5_b_p;
  boolean_T c5_c_p;
  boolean_T c5_exitg1;
  boolean_T c5_p;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_c_st.prev = &c5_b_st;
  c5_c_st.tls = c5_b_st.tls;
  c5_d_st.prev = &c5_c_st;
  c5_d_st.tls = c5_c_st.tls;
  c5_array_s_jsRMsmv0Wf6iHXg8PgCG1G_(chartInstance, &c5_CC);
  c5_st.site = &c5_ig_emlrtRSI;
  for (c5_i = 0; c5_i < 19200; c5_i++) {
    c5_b_varargin_1[c5_i] = c5_varargin_1[c5_i];
  }

  c5_bwconncomp(chartInstance, &c5_st, c5_b_varargin_1, &c5_CC);
  for (c5_i1 = 0; c5_i1 < 2; c5_i1++) {
    c5_imageSize[c5_i1] = c5_CC.ImageSize[c5_i1];
  }

  c5_numObjs = c5_CC.NumObjects;
  c5_st.site = &c5_jg_emlrtRSI;
  c5_b_numObjs = c5_numObjs;
  c5_p = false;
  c5_b_p = true;
  c5_k = 0;
  c5_exitg1 = false;
  while ((!c5_exitg1) && (c5_k < 2)) {
    c5_b_k = (real_T)c5_k + 1.0;
    c5_x1 = c5_imageSize[(int32_T)c5_b_k - 1];
    c5_x2 = 120.0 + 40.0 * (real_T)((int32_T)c5_b_k - 1);
    c5_c_p = (c5_x1 == c5_x2);
    if (!c5_c_p) {
      c5_b_p = false;
      c5_exitg1 = true;
    } else {
      c5_k++;
    }
  }

  if (c5_b_p) {
    c5_p = true;
  }

  if (!c5_p) {
    c5_y = NULL;
    sf_mex_assign(&c5_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1, 31),
                  false);
    c5_b_y = NULL;
    sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1, 31),
                  false);
    sf_mex_call(&c5_st, &c5_x_emlrtMCI, "error", 0U, 2U, 14, c5_y, 14,
                sf_mex_call(&c5_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c5_st, NULL, "message", 1U, 1U, 14, c5_b_y)));
  }

  c5_b_st.site = &c5_wh_emlrtRSI;
  c5_c_numObjs = c5_b_numObjs;
  c5_c_st.site = &c5_xh_emlrtRSI;
  c5_c_varargin_1 = c5_c_numObjs;
  c5_d_st.site = &c5_uh_emlrtRSI;
  c5_assertValidSizeArg(chartInstance, &c5_d_st, c5_c_varargin_1);
  c5_array_boolean_T_Constructor(chartInstance, &c5_tile);
  c5_array_boolean_T_SetSize(chartInstance, &c5_c_st, &c5_tile, &c5_ed_emlrtRTEI,
    (int32_T)c5_c_varargin_1);
  c5_loop_ub = (int32_T)c5_c_varargin_1 - 1;
  for (c5_i2 = 0; c5_i2 <= c5_loop_ub; c5_i2++) {
    c5_tile.vector.data[c5_i2] = false;
  }

  c5_outsize[0] = c5_tile.size[0];
  if (!((real_T)c5_outsize[0] == (real_T)c5_tile.size[0])) {
    c5_c_y = NULL;
    sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_cv7, 10, 0U, 1, 0U, 2, 1, 15),
                  false);
    sf_mex_call(&c5_c_st, &c5_u_emlrtMCI, "error", 0U, 1U, 14, c5_c_y);
  }

  for (c5_i3 = 0; c5_i3 < 2; c5_i3++) {
    c5_b_s.WeightedCentroid[c5_i3] = 0.0;
  }

  c5_array_sOA5t73y81YtFHGIDxk0fKF_S(chartInstance, &c5_c_st, c5_outstats,
    &c5_fd_emlrtRTEI, c5_outsize[0]);
  c5_b_loop_ub = c5_outsize[0] - 1;
  for (c5_i4 = 0; c5_i4 <= c5_b_loop_ub; c5_i4++) {
    c5_outstats->vector.data[c5_i4] = c5_b_s;
  }

  c5_st.site = &c5_kg_emlrtRSI;
  c5_d_numObjs = c5_numObjs;
  c5_statsAlreadyComputed.Area = false;
  c5_c_array_s_R6Og1x0kmqQXSF9Pwa49FD_(chartInstance, &c5_statsOneObj);
  c5_statsOneObj.Area = 0.0;
  c5_statsAlreadyComputed.Centroid = false;
  for (c5_i5 = 0; c5_i5 < 2; c5_i5++) {
    c5_statsOneObj.Centroid[c5_i5] = 0.0;
  }

  c5_statsAlreadyComputed.BoundingBox = false;
  for (c5_i6 = 0; c5_i6 < 4; c5_i6++) {
    c5_statsOneObj.BoundingBox[c5_i6] = 0.0;
  }

  c5_statsAlreadyComputed.MajorAxisLength = false;
  c5_statsOneObj.MajorAxisLength = 0.0;
  c5_statsAlreadyComputed.MinorAxisLength = false;
  c5_statsOneObj.MinorAxisLength = 0.0;
  c5_statsAlreadyComputed.Eccentricity = false;
  c5_statsOneObj.Eccentricity = 0.0;
  c5_statsAlreadyComputed.Orientation = false;
  c5_statsOneObj.Orientation = 0.0;
  c5_statsAlreadyComputed.Image = false;
  c5_statsOneObj.Image.size[0] = 0;
  c5_statsOneObj.Image.size[1] = 0;
  c5_statsAlreadyComputed.FilledImage = false;
  c5_statsOneObj.FilledImage.size[0] = 0;
  c5_statsOneObj.FilledImage.size[1] = 0;
  c5_statsAlreadyComputed.FilledArea = false;
  c5_statsOneObj.FilledArea = 0.0;
  c5_statsAlreadyComputed.EulerNumber = false;
  c5_statsOneObj.EulerNumber = 0.0;
  c5_statsAlreadyComputed.Extrema = false;
  for (c5_i7 = 0; c5_i7 < 16; c5_i7++) {
    c5_statsOneObj.Extrema[c5_i7] = 0.0;
  }

  c5_statsAlreadyComputed.EquivDiameter = false;
  c5_statsOneObj.EquivDiameter = 0.0;
  c5_statsAlreadyComputed.Extent = false;
  c5_statsOneObj.Extent = 0.0;
  c5_array_real_T_SetSize(chartInstance, &c5_st, &c5_statsOneObj.PixelIdxList,
    &c5_id_emlrtRTEI, 0);
  c5_statsAlreadyComputed.PixelList = false;
  c5_array_real_T_2D_SetSize(chartInstance, &c5_st, &c5_statsOneObj.PixelList,
    &c5_jd_emlrtRTEI, 0, 2);
  c5_statsAlreadyComputed.Perimeter = false;
  c5_statsOneObj.Perimeter = 0.0;
  c5_statsAlreadyComputed.Circularity = false;
  c5_statsOneObj.Circularity = 0.0;
  c5_statsAlreadyComputed.PixelValues = false;
  c5_array_real_T_SetSize(chartInstance, &c5_st, &c5_statsOneObj.PixelValues,
    &c5_kd_emlrtRTEI, 0);
  c5_statsAlreadyComputed.WeightedCentroid = false;
  for (c5_i8 = 0; c5_i8 < 2; c5_i8++) {
    c5_statsOneObj.WeightedCentroid[c5_i8] = 0.0;
  }

  c5_statsAlreadyComputed.MeanIntensity = false;
  c5_statsOneObj.MeanIntensity = 0.0;
  c5_statsAlreadyComputed.MinIntensity = false;
  c5_statsOneObj.MinIntensity = 0.0;
  c5_statsAlreadyComputed.MaxIntensity = false;
  c5_statsOneObj.MaxIntensity = 0.0;
  c5_statsAlreadyComputed.SubarrayIdx = false;
  c5_statsOneObj.SubarrayIdx.size[0] = 1;
  c5_statsOneObj.SubarrayIdx.size[1] = 0;
  for (c5_i9 = 0; c5_i9 < 2; c5_i9++) {
    c5_statsOneObj.SubarrayIdxLengths[c5_i9] = 0.0;
  }

  c5_b_st.site = &c5_yh_emlrtRSI;
  c5_d_varargin_1 = c5_d_numObjs;
  c5_c_st.site = &c5_uh_emlrtRSI;
  c5_assertValidSizeArg(chartInstance, &c5_c_st, c5_d_varargin_1);
  c5_array_boolean_T_SetSize(chartInstance, &c5_b_st, &c5_tile, &c5_ed_emlrtRTEI,
    (int32_T)c5_d_varargin_1);
  c5_c_loop_ub = (int32_T)c5_d_varargin_1 - 1;
  for (c5_i10 = 0; c5_i10 <= c5_c_loop_ub; c5_i10++) {
    c5_tile.vector.data[c5_i10] = false;
  }

  c5_b_outsize[0] = c5_tile.size[0];
  if (!((real_T)c5_b_outsize[0] == (real_T)c5_tile.size[0])) {
    c5_d_y = NULL;
    sf_mex_assign(&c5_d_y, sf_mex_create("y", c5_cv7, 10, 0U, 1, 0U, 2, 1, 15),
                  false);
    sf_mex_call(&c5_b_st, &c5_u_emlrtMCI, "error", 0U, 1U, 14, c5_d_y);
  }

  c5_array_boolean_T_Destructor(chartInstance, &c5_tile);
  c5_e_array_s_R6Og1x0kmqQXSF9Pwa49FD_(chartInstance, &c5_stats);
  c5_array_s_R6Og1x0kmqQXSF9Pwa49FD_(chartInstance, &c5_b_st, &c5_stats,
    &c5_md_emlrtRTEI, c5_b_outsize[0]);
  c5_d_loop_ub = c5_b_outsize[0] - 1;
  for (c5_i11 = 0; c5_i11 <= c5_d_loop_ub; c5_i11++) {
    c5_d_array_s_R6Og1x0kmqQXSF9Pwa49FD_(chartInstance, &c5_b_st,
      &c5_stats.vector.data[c5_i11], &c5_statsOneObj, &c5_md_emlrtRTEI);
  }

  c5_b_array_s_R6Og1x0kmqQXSF9Pwa49FD_(chartInstance, &c5_statsOneObj);
  c5_st.site = &c5_lg_emlrtRSI;
  c5_e_numObjs = c5_numObjs;
  c5_statsAlreadyComputed.PixelIdxList = true;
  if (c5_e_numObjs != 0.0) {
    c5_array_real_T_Constructor(chartInstance, &c5_regionIndices);
    c5_array_real_T_SetSize(chartInstance, &c5_st, &c5_regionIndices,
      &c5_nd_emlrtRTEI, c5_CC.RegionIndices.size[0]);
    c5_e_loop_ub = c5_CC.RegionIndices.size[0] - 1;
    for (c5_i13 = 0; c5_i13 <= c5_e_loop_ub; c5_i13++) {
      c5_regionIndices.vector.data[c5_i13] =
        c5_CC.RegionIndices.vector.data[c5_i13];
    }

    c5_array_int32_T_Constructor(chartInstance, &c5_regionLengths);
    c5_array_int32_T_SetSize(chartInstance, &c5_st, &c5_regionLengths,
      &c5_od_emlrtRTEI, c5_CC.RegionLengths.size[0]);
    c5_f_loop_ub = c5_CC.RegionLengths.size[0] - 1;
    for (c5_i15 = 0; c5_i15 <= c5_f_loop_ub; c5_i15++) {
      c5_regionLengths.vector.data[c5_i15] =
        c5_CC.RegionLengths.vector.data[c5_i15];
    }

    c5_b_st.site = &c5_ai_emlrtRSI;
    c5_c_st.site = &c5_oh_emlrtRSI;
    c5_dim = 2;
    if ((real_T)c5_regionLengths.size[0] != 1.0) {
      c5_dim = 1;
    }

    c5_array_int32_T_Constructor(chartInstance, &c5_b_regionLengths);
    c5_array_int32_T_SetSize(chartInstance, &c5_c_st, &c5_b_regionLengths,
      &c5_pd_emlrtRTEI, c5_regionLengths.size[0]);
    c5_g_loop_ub = c5_regionLengths.size[0] - 1;
    for (c5_i20 = 0; c5_i20 <= c5_g_loop_ub; c5_i20++) {
      c5_b_regionLengths.vector.data[c5_i20] =
        c5_regionLengths.vector.data[c5_i20];
    }

    c5_d_st.site = &c5_ph_emlrtRSI;
    c5_useConstantDim(chartInstance, &c5_d_st, &c5_b_regionLengths, c5_dim,
                      &c5_regionLengths);
    c5_array_int32_T_Destructor(chartInstance, &c5_b_regionLengths);
    c5_array_int32_T_Constructor(chartInstance, &c5_idxCount);
    c5_array_int32_T_SetSize(chartInstance, &c5_st, &c5_idxCount,
      &c5_qd_emlrtRTEI, 1 + c5_regionLengths.size[0]);
    c5_idxCount.vector.data[0] = 0;
    c5_h_loop_ub = c5_regionLengths.size[0] - 1;
    for (c5_i24 = 0; c5_i24 <= c5_h_loop_ub; c5_i24++) {
      c5_idxCount.vector.data[c5_i24 + 1] = c5_regionLengths.vector.data[c5_i24];
    }

    c5_array_int32_T_Destructor(chartInstance, &c5_regionLengths);
    c5_d1 = (real_T)c5_stats.size[0];
    c5_i27 = (int32_T)c5_d1 - 1;
    for (c5_e_k = 0; c5_e_k <= c5_i27; c5_e_k++) {
      c5_f_k = (real_T)c5_e_k + 1.0;
      c5_i29 = c5_idxCount.size[0];
      c5_i30 = (int32_T)c5_f_k;
      if ((c5_i30 < 1) || (c5_i30 > c5_i29)) {
        emlrtDynamicBoundsCheckR2012b(c5_i30, 1, c5_i29, &c5_gd_emlrtBCI, &c5_st);
      }

      c5_i31 = c5_idxCount.vector.data[c5_i30 - 1] + 1;
      c5_i32 = c5_idxCount.size[0];
      c5_i33 = (int32_T)(c5_f_k + 1.0);
      if ((c5_i33 < 1) || (c5_i33 > c5_i32)) {
        emlrtDynamicBoundsCheckR2012b(c5_i33, 1, c5_i32, &c5_hd_emlrtBCI, &c5_st);
      }

      c5_i34 = c5_idxCount.vector.data[c5_i33 - 1];
      c5_b = (c5_i31 > c5_i34);
      if (c5_b) {
        c5_i36 = 0;
        c5_i37 = -1;
      } else {
        c5_i35 = c5_regionIndices.size[0];
        if ((c5_i31 < 1) || (c5_i31 > c5_i35)) {
          emlrtDynamicBoundsCheckR2012b(c5_i31, 1, c5_i35, &c5_bd_emlrtBCI,
            &c5_st);
        }

        c5_i36 = c5_i31 - 1;
        c5_i39 = c5_regionIndices.size[0];
        if ((c5_i34 < 1) || (c5_i34 > c5_i39)) {
          emlrtDynamicBoundsCheckR2012b(c5_i34, 1, c5_i39, &c5_ad_emlrtBCI,
            &c5_st);
        }

        c5_i37 = c5_i34 - 1;
      }

      c5_i38 = c5_stats.size[0];
      c5_i40 = (int32_T)c5_f_k;
      if ((c5_i40 < 1) || (c5_i40 > c5_i38)) {
        emlrtDynamicBoundsCheckR2012b(c5_i40, 1, c5_i38, &c5_id_emlrtBCI, &c5_st);
      }

      c5_array_real_T_SetSize(chartInstance, &c5_st,
        &c5_stats.vector.data[c5_i40 - 1].PixelIdxList, &c5_rd_emlrtRTEI,
        (c5_i37 - c5_i36) + 1);
      c5_i_loop_ub = c5_i37 - c5_i36;
      for (c5_i41 = 0; c5_i41 <= c5_i_loop_ub; c5_i41++) {
        c5_i42 = c5_stats.size[0];
        c5_i43 = (int32_T)c5_f_k;
        if ((c5_i43 < 1) || (c5_i43 > c5_i42)) {
          emlrtDynamicBoundsCheckR2012b(c5_i43, 1, c5_i42, &c5_id_emlrtBCI,
            &c5_st);
        }

        c5_stats.vector.data[c5_i43 - 1].PixelIdxList.vector.data[c5_i41] =
          c5_regionIndices.vector.data[c5_i36 + c5_i41];
      }
    }

    c5_array_int32_T_Destructor(chartInstance, &c5_idxCount);
    c5_array_real_T_Destructor(chartInstance, &c5_regionIndices);
  }

  c5_b_array_s_jsRMsmv0Wf6iHXg8PgCG1G_(chartInstance, &c5_CC);
  c5_st.site = &c5_mg_emlrtRSI;
  for (c5_i12 = 0; c5_i12 < 19200; c5_i12++) {
    chartInstance->c5_varargin_2[c5_i12] = c5_b_varargin_2[c5_i12];
  }

  c5_b_ComputeWeightedCentroid(chartInstance, &c5_st,
    chartInstance->c5_varargin_2, &c5_stats, &c5_statsAlreadyComputed);
  c5_st.site = &c5_ng_emlrtRSI;
  c5_d = (real_T)c5_stats.size[0];
  c5_i14 = (int32_T)c5_d - 1;
  for (c5_c_k = 0; c5_c_k <= c5_i14; c5_c_k++) {
    c5_d_k = (real_T)c5_c_k + 1.0;
    c5_i16 = c5_stats.size[0];
    c5_i17 = (int32_T)c5_d_k;
    if ((c5_i17 < 1) || (c5_i17 > c5_i16)) {
      emlrtDynamicBoundsCheckR2012b(c5_i17, 1, c5_i16, &c5_cd_emlrtBCI, &c5_st);
    }

    c5_i18 = c5_outstats->size[0];
    c5_i19 = (int32_T)c5_d_k;
    if ((c5_i19 < 1) || (c5_i19 > c5_i18)) {
      emlrtDynamicBoundsCheckR2012b(c5_i19, 1, c5_i18, &c5_dd_emlrtBCI, &c5_st);
    }

    for (c5_vIdx = 0; c5_vIdx < 2; c5_vIdx++) {
      c5_b_vIdx = (real_T)c5_vIdx + 1.0;
      c5_i21 = c5_stats.size[0];
      c5_i22 = (int32_T)c5_d_k;
      if ((c5_i22 < 1) || (c5_i22 > c5_i21)) {
        emlrtDynamicBoundsCheckR2012b(c5_i22, 1, c5_i21, &c5_fd_emlrtBCI, &c5_st);
      }

      c5_i23 = c5_i22 - 1;
      c5_i25 = c5_outstats->size[0];
      c5_i26 = (int32_T)c5_d_k;
      if ((c5_i26 < 1) || (c5_i26 > c5_i25)) {
        emlrtDynamicBoundsCheckR2012b(c5_i26, 1, c5_i25, &c5_ed_emlrtBCI, &c5_st);
      }

      c5_i28 = c5_i26 - 1;
      c5_outstats->vector.data[c5_i28].WeightedCentroid[(int32_T)c5_b_vIdx - 1] =
        c5_stats.vector.data[c5_i23].WeightedCentroid[(int32_T)c5_b_vIdx - 1];
    }
  }

  c5_f_array_s_R6Og1x0kmqQXSF9Pwa49FD_(chartInstance, &c5_stats);
}

static void c5_bwconncomp(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, boolean_T c5_varargin_1[19200],
  c5_s_jsRMsmv0Wf6iHXg8PgCG1G *c5_CC)
{
  c5_cell_wrap_51 c5_rv[1];
  c5_cell_wrap_51 c5_r2;
  c5_coder_array_cell_wrap_51_2D c5_r1;
  c5_coder_array_int32_T c5_b_x;
  c5_coder_array_int32_T c5_c_x;
  c5_coder_array_int32_T c5_d_x;
  c5_coder_array_int32_T c5_endRow;
  c5_coder_array_int32_T c5_idxCount;
  c5_coder_array_int32_T c5_labelForEachRun;
  c5_coder_array_int32_T c5_labelsRenumbered;
  c5_coder_array_int32_T c5_startCol;
  c5_coder_array_int32_T c5_startRow;
  c5_coder_array_real_T c5_r;
  emlrtStack c5_b_st;
  emlrtStack c5_c_st;
  emlrtStack c5_d_st;
  emlrtStack c5_e_st;
  emlrtStack c5_f_st;
  emlrtStack c5_g_st;
  emlrtStack c5_h_st;
  emlrtStack c5_st;
  real_T c5_b_col;
  real_T c5_b_k;
  real_T c5_b_s;
  real_T c5_d;
  real_T c5_d1;
  real_T c5_d2;
  real_T c5_d_col;
  real_T c5_k_k;
  real_T c5_numComponents;
  real_T c5_y;
  int32_T c5_b_iv[1];
  int32_T c5_b;
  int32_T c5_b_b;
  int32_T c5_b_c;
  int32_T c5_b_dim;
  int32_T c5_b_loop_ub;
  int32_T c5_b_node;
  int32_T c5_b_p;
  int32_T c5_b_root_k;
  int32_T c5_b_root_p;
  int32_T c5_b_vlen;
  int32_T c5_c;
  int32_T c5_c_a;
  int32_T c5_c_b;
  int32_T c5_c_col;
  int32_T c5_c_k;
  int32_T c5_c_loop_ub;
  int32_T c5_c_p;
  int32_T c5_c_vlen;
  int32_T c5_col;
  int32_T c5_column_offset;
  int32_T c5_currentColumn;
  int32_T c5_d_a;
  int32_T c5_d_b;
  int32_T c5_d_k;
  int32_T c5_d_loop_ub;
  int32_T c5_d_vlen;
  int32_T c5_dim;
  int32_T c5_e_a;
  int32_T c5_e_b;
  int32_T c5_e_k;
  int32_T c5_e_loop_ub;
  int32_T c5_exitg1;
  int32_T c5_f_a;
  int32_T c5_f_b;
  int32_T c5_f_k;
  int32_T c5_f_loop_ub;
  int32_T c5_firstRunOnPreviousColumn;
  int32_T c5_firstRunOnThisColumn;
  int32_T c5_g_a;
  int32_T c5_g_b;
  int32_T c5_g_k;
  int32_T c5_g_loop_ub;
  int32_T c5_h_a;
  int32_T c5_h_b;
  int32_T c5_h_k;
  int32_T c5_h_loop_ub;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i10;
  int32_T c5_i11;
  int32_T c5_i12;
  int32_T c5_i13;
  int32_T c5_i14;
  int32_T c5_i15;
  int32_T c5_i16;
  int32_T c5_i17;
  int32_T c5_i18;
  int32_T c5_i19;
  int32_T c5_i2;
  int32_T c5_i20;
  int32_T c5_i21;
  int32_T c5_i22;
  int32_T c5_i23;
  int32_T c5_i24;
  int32_T c5_i25;
  int32_T c5_i26;
  int32_T c5_i27;
  int32_T c5_i28;
  int32_T c5_i29;
  int32_T c5_i3;
  int32_T c5_i30;
  int32_T c5_i31;
  int32_T c5_i32;
  int32_T c5_i33;
  int32_T c5_i34;
  int32_T c5_i35;
  int32_T c5_i36;
  int32_T c5_i37;
  int32_T c5_i38;
  int32_T c5_i39;
  int32_T c5_i4;
  int32_T c5_i40;
  int32_T c5_i41;
  int32_T c5_i42;
  int32_T c5_i43;
  int32_T c5_i44;
  int32_T c5_i45;
  int32_T c5_i46;
  int32_T c5_i47;
  int32_T c5_i48;
  int32_T c5_i49;
  int32_T c5_i5;
  int32_T c5_i50;
  int32_T c5_i51;
  int32_T c5_i52;
  int32_T c5_i53;
  int32_T c5_i54;
  int32_T c5_i55;
  int32_T c5_i56;
  int32_T c5_i57;
  int32_T c5_i58;
  int32_T c5_i59;
  int32_T c5_i6;
  int32_T c5_i60;
  int32_T c5_i61;
  int32_T c5_i62;
  int32_T c5_i63;
  int32_T c5_i64;
  int32_T c5_i65;
  int32_T c5_i66;
  int32_T c5_i67;
  int32_T c5_i68;
  int32_T c5_i69;
  int32_T c5_i7;
  int32_T c5_i70;
  int32_T c5_i71;
  int32_T c5_i72;
  int32_T c5_i73;
  int32_T c5_i74;
  int32_T c5_i75;
  int32_T c5_i76;
  int32_T c5_i77;
  int32_T c5_i78;
  int32_T c5_i79;
  int32_T c5_i8;
  int32_T c5_i80;
  int32_T c5_i81;
  int32_T c5_i82;
  int32_T c5_i83;
  int32_T c5_i9;
  int32_T c5_i_k;
  int32_T c5_i_loop_ub;
  int32_T c5_ib;
  int32_T c5_idx;
  int32_T c5_inb;
  int32_T c5_j_k;
  int32_T c5_j_loop_ub;
  int32_T c5_k;
  int32_T c5_k_loop_ub;
  int32_T c5_l_loop_ub;
  int32_T c5_lastRunOnPreviousColumn;
  int32_T c5_lidx;
  int32_T c5_loop_ub;
  int32_T c5_nextLabel;
  int32_T c5_nfb;
  int32_T c5_nleft;
  int32_T c5_node;
  int32_T c5_numRuns;
  int32_T c5_p;
  int32_T c5_root_k;
  int32_T c5_root_p;
  int32_T c5_row;
  int32_T c5_rowidx;
  int32_T c5_runCounter;
  int32_T c5_vlen;
  boolean_T c5_b_overflow;
  boolean_T c5_c_overflow;
  boolean_T c5_d_overflow;
  boolean_T c5_i_b;
  boolean_T c5_overflow;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_c_st.prev = &c5_b_st;
  c5_c_st.tls = c5_b_st.tls;
  c5_d_st.prev = &c5_c_st;
  c5_d_st.tls = c5_c_st.tls;
  c5_e_st.prev = &c5_d_st;
  c5_e_st.tls = c5_d_st.tls;
  c5_f_st.prev = &c5_e_st;
  c5_f_st.tls = c5_e_st.tls;
  c5_g_st.prev = &c5_f_st;
  c5_g_st.tls = c5_f_st.tls;
  c5_h_st.prev = &c5_g_st;
  c5_h_st.tls = c5_g_st.tls;
  c5_CC->Connectivity = 8.0;
  for (c5_i = 0; c5_i < 2; c5_i++) {
    c5_CC->ImageSize[c5_i] = 120.0 + 40.0 * (real_T)c5_i;
  }

  c5_st.site = &c5_og_emlrtRSI;
  c5_b_st.site = &c5_xg_emlrtRSI;
  c5_numRuns = 0;
  for (c5_col = 0; c5_col < 160; c5_col++) {
    c5_b_col = (real_T)c5_col + 1.0;
    if (c5_varargin_1[120 * ((int32_T)c5_b_col - 1)]) {
      c5_numRuns++;
    }

    for (c5_k = 0; c5_k < 119; c5_k++) {
      c5_b_k = (real_T)c5_k + 2.0;
      if (c5_varargin_1[((int32_T)c5_b_k + 120 * ((int32_T)c5_b_col - 1)) - 1] &&
          (!c5_varargin_1[((int32_T)(c5_b_k - 1.0) + 120 * ((int32_T)c5_b_col -
             1)) - 1])) {
        c5_numRuns++;
      }
    }
  }

  c5_array_int32_T_Constructor(chartInstance, &c5_startRow);
  c5_array_int32_T_Constructor(chartInstance, &c5_endRow);
  c5_array_int32_T_Constructor(chartInstance, &c5_startCol);
  c5_array_int32_T_Constructor(chartInstance, &c5_labelForEachRun);
  if (c5_numRuns == 0) {
    c5_array_int32_T_SetSize(chartInstance, &c5_b_st, &c5_startRow,
      &c5_wd_emlrtRTEI, 0);
    c5_array_int32_T_SetSize(chartInstance, &c5_b_st, &c5_endRow,
      &c5_xd_emlrtRTEI, 0);
    c5_array_int32_T_SetSize(chartInstance, &c5_b_st, &c5_startCol,
      &c5_yd_emlrtRTEI, 0);
    c5_array_int32_T_SetSize(chartInstance, &c5_b_st, &c5_labelForEachRun,
      &c5_ae_emlrtRTEI, 0);
    c5_numRuns = 0;
  } else {
    c5_d = (real_T)c5_numRuns;
    if (!(c5_d >= 0.0)) {
      emlrtNonNegativeCheckR2012b(c5_d, &c5_e_emlrtDCI, &c5_b_st);
    }

    c5_array_int32_T_SetSize(chartInstance, &c5_b_st, &c5_startRow,
      &c5_sd_emlrtRTEI, (int32_T)muDoubleScalarFloor(c5_d));
    c5_array_int32_T_SetSize(chartInstance, &c5_b_st, &c5_endRow,
      &c5_td_emlrtRTEI, c5_numRuns);
    c5_array_int32_T_SetSize(chartInstance, &c5_b_st, &c5_startCol,
      &c5_ud_emlrtRTEI, c5_numRuns);
    c5_c_st.site = &c5_yg_emlrtRSI;
    c5_runCounter = 1;
    for (c5_c_col = 0; c5_c_col < 160; c5_c_col++) {
      c5_d_col = (real_T)c5_c_col + 1.0;
      c5_row = 1;
      while (c5_row <= 120) {
        while ((c5_row <= 120) && (!c5_varargin_1[(c5_row + 120 * ((int32_T)
                  c5_d_col - 1)) - 1])) {
          c5_row++;
        }

        if ((c5_row <= 120) && c5_varargin_1[(c5_row + 120 * ((int32_T)c5_d_col
              - 1)) - 1]) {
          c5_i2 = c5_startCol.size[0];
          if ((c5_runCounter < 1) || (c5_runCounter > c5_i2)) {
            emlrtDynamicBoundsCheckR2012b(c5_runCounter, 1, c5_i2,
              &c5_ld_emlrtBCI, &c5_c_st);
          }

          c5_startCol.vector.data[c5_runCounter - 1] = (int32_T)c5_d_col;
          c5_i3 = c5_startRow.size[0];
          if ((c5_runCounter < 1) || (c5_runCounter > c5_i3)) {
            emlrtDynamicBoundsCheckR2012b(c5_runCounter, 1, c5_i3,
              &c5_nd_emlrtBCI, &c5_c_st);
          }

          c5_startRow.vector.data[c5_runCounter - 1] = c5_row;
          while ((c5_row <= 120) && c5_varargin_1[(c5_row + 120 * ((int32_T)
                   c5_d_col - 1)) - 1]) {
            c5_row++;
          }

          c5_i8 = c5_endRow.size[0];
          if ((c5_runCounter < 1) || (c5_runCounter > c5_i8)) {
            emlrtDynamicBoundsCheckR2012b(c5_runCounter, 1, c5_i8,
              &c5_rd_emlrtBCI, &c5_c_st);
          }

          c5_endRow.vector.data[c5_runCounter - 1] = c5_row - 1;
          c5_runCounter++;
        }
      }
    }

    c5_array_int32_T_SetSize(chartInstance, &c5_b_st, &c5_labelForEachRun,
      &c5_vd_emlrtRTEI, c5_numRuns);
    c5_loop_ub = c5_numRuns - 1;
    for (c5_i1 = 0; c5_i1 <= c5_loop_ub; c5_i1++) {
      c5_labelForEachRun.vector.data[c5_i1] = 0;
    }

    c5_c_k = 1;
    c5_currentColumn = 2;
    c5_nextLabel = 1;
    c5_firstRunOnPreviousColumn = -1;
    c5_lastRunOnPreviousColumn = 0;
    c5_firstRunOnThisColumn = 1;
    while (c5_c_k <= c5_numRuns) {
      c5_i4 = c5_startCol.size[0];
      if ((c5_c_k < 1) || (c5_c_k > c5_i4)) {
        emlrtDynamicBoundsCheckR2012b(c5_c_k, 1, c5_i4, &c5_md_emlrtBCI,
          &c5_b_st);
      }

      if (c5_startCol.vector.data[c5_c_k - 1] == c5_currentColumn) {
        c5_firstRunOnPreviousColumn = c5_firstRunOnThisColumn;
        c5_firstRunOnThisColumn = c5_c_k;
        c5_lastRunOnPreviousColumn = c5_c_k;
        c5_i13 = c5_startCol.size[0];
        if ((c5_c_k < 1) || (c5_c_k > c5_i13)) {
          emlrtDynamicBoundsCheckR2012b(c5_c_k, 1, c5_i13, &c5_qd_emlrtBCI,
            &c5_b_st);
        }

        c5_currentColumn = c5_startCol.vector.data[c5_c_k - 1] + 1;
      } else {
        c5_i7 = c5_startCol.size[0];
        if ((c5_c_k < 1) || (c5_c_k > c5_i7)) {
          emlrtDynamicBoundsCheckR2012b(c5_c_k, 1, c5_i7, &c5_od_emlrtBCI,
            &c5_b_st);
        }

        if (c5_startCol.vector.data[c5_c_k - 1] > c5_currentColumn) {
          c5_firstRunOnPreviousColumn = -1;
          c5_lastRunOnPreviousColumn = 0;
          c5_firstRunOnThisColumn = c5_c_k;
          c5_i16 = c5_startCol.size[0];
          if ((c5_c_k < 1) || (c5_c_k > c5_i16)) {
            emlrtDynamicBoundsCheckR2012b(c5_c_k, 1, c5_i16, &c5_sd_emlrtBCI,
              &c5_b_st);
          }

          c5_currentColumn = c5_startCol.vector.data[c5_c_k - 1] + 1;
        }
      }

      if (c5_firstRunOnPreviousColumn >= 0) {
        for (c5_p = c5_firstRunOnPreviousColumn; c5_p <
             c5_lastRunOnPreviousColumn; c5_p++) {
          c5_i20 = c5_endRow.size[0];
          if ((c5_c_k < 1) || (c5_c_k > c5_i20)) {
            emlrtDynamicBoundsCheckR2012b(c5_c_k, 1, c5_i20, &c5_ae_emlrtBCI,
              &c5_b_st);
          }

          c5_i22 = c5_startRow.size[0];
          if ((c5_p < 1) || (c5_p > c5_i22)) {
            emlrtDynamicBoundsCheckR2012b(c5_p, 1, c5_i22, &c5_be_emlrtBCI,
              &c5_b_st);
          }

          if (c5_endRow.vector.data[c5_c_k - 1] >= c5_startRow.vector.data[c5_p
              - 1] - 1) {
            c5_i24 = c5_startRow.size[0];
            if ((c5_c_k < 1) || (c5_c_k > c5_i24)) {
              emlrtDynamicBoundsCheckR2012b(c5_c_k, 1, c5_i24, &c5_ce_emlrtBCI,
                &c5_b_st);
            }

            c5_i26 = c5_endRow.size[0];
            if ((c5_p < 1) || (c5_p > c5_i26)) {
              emlrtDynamicBoundsCheckR2012b(c5_p, 1, c5_i26, &c5_de_emlrtBCI,
                &c5_b_st);
            }

            if (c5_startRow.vector.data[c5_c_k - 1] <=
                c5_endRow.vector.data[c5_p - 1] + 1) {
              c5_i28 = c5_labelForEachRun.size[0];
              if ((c5_c_k < 1) || (c5_c_k > c5_i28)) {
                emlrtDynamicBoundsCheckR2012b(c5_c_k, 1, c5_i28, &c5_ee_emlrtBCI,
                  &c5_b_st);
              }

              if (c5_labelForEachRun.vector.data[c5_c_k - 1] == 0) {
                c5_i31 = c5_labelForEachRun.size[0];
                if ((c5_p < 1) || (c5_p > c5_i31)) {
                  emlrtDynamicBoundsCheckR2012b(c5_p, 1, c5_i31, &c5_he_emlrtBCI,
                    &c5_b_st);
                }

                c5_i34 = c5_labelForEachRun.size[0];
                if ((c5_c_k < 1) || (c5_c_k > c5_i34)) {
                  emlrtDynamicBoundsCheckR2012b(c5_c_k, 1, c5_i34,
                    &c5_ie_emlrtBCI, &c5_b_st);
                }

                c5_labelForEachRun.vector.data[c5_c_k - 1] =
                  c5_labelForEachRun.vector.data[c5_p - 1];
                c5_nextLabel++;
              } else {
                c5_i30 = c5_labelForEachRun.size[0];
                if ((c5_c_k < 1) || (c5_c_k > c5_i30)) {
                  emlrtDynamicBoundsCheckR2012b(c5_c_k, 1, c5_i30,
                    &c5_fe_emlrtBCI, &c5_b_st);
                }

                c5_i33 = c5_labelForEachRun.size[0];
                if ((c5_p < 1) || (c5_p > c5_i33)) {
                  emlrtDynamicBoundsCheckR2012b(c5_p, 1, c5_i33, &c5_ge_emlrtBCI,
                    &c5_b_st);
                }

                if (c5_labelForEachRun.vector.data[c5_c_k - 1] !=
                    c5_labelForEachRun.vector.data[c5_p - 1]) {
                  c5_c_st.site = &c5_ah_emlrtRSI;
                  c5_g_k = c5_c_k;
                  c5_b_p = c5_p;
                  c5_d_st.site = &c5_bh_emlrtRSI;
                  c5_node = c5_g_k;
                  c5_root_k = c5_node;
                  do {
                    c5_exitg1 = 0;
                    c5_i36 = c5_labelForEachRun.size[0];
                    if ((c5_root_k < 1) || (c5_root_k > c5_i36)) {
                      emlrtDynamicBoundsCheckR2012b(c5_root_k, 1, c5_i36,
                        &c5_oe_emlrtBCI, &c5_d_st);
                    }

                    if (c5_root_k != c5_labelForEachRun.vector.data[c5_root_k -
                        1]) {
                      c5_i38 = c5_labelForEachRun.size[0];
                      c5_i39 = c5_labelForEachRun.size[0];
                      if ((c5_root_k < 1) || (c5_root_k > c5_i39)) {
                        emlrtDynamicBoundsCheckR2012b(c5_root_k, 1, c5_i39,
                          &c5_qe_emlrtBCI, &c5_d_st);
                      }

                      c5_i40 = c5_labelForEachRun.vector.data[c5_root_k - 1];
                      if ((c5_i40 < 1) || (c5_i40 > c5_i38)) {
                        emlrtDynamicBoundsCheckR2012b(c5_i40, 1, c5_i38,
                          &c5_pe_emlrtBCI, &c5_d_st);
                      }

                      c5_i42 = c5_labelForEachRun.size[0];
                      if ((c5_root_k < 1) || (c5_root_k > c5_i42)) {
                        emlrtDynamicBoundsCheckR2012b(c5_root_k, 1, c5_i42,
                          &c5_re_emlrtBCI, &c5_d_st);
                      }

                      c5_labelForEachRun.vector.data[c5_root_k - 1] =
                        c5_labelForEachRun.vector.data[c5_i40 - 1];
                      c5_i44 = c5_labelForEachRun.size[0];
                      if ((c5_root_k < 1) || (c5_root_k > c5_i44)) {
                        emlrtDynamicBoundsCheckR2012b(c5_root_k, 1, c5_i44,
                          &c5_se_emlrtBCI, &c5_d_st);
                      }

                      c5_root_k = c5_labelForEachRun.vector.data[c5_root_k - 1];
                    } else {
                      c5_exitg1 = 1;
                    }
                  } while (c5_exitg1 == 0);

                  c5_d_st.site = &c5_ch_emlrtRSI;
                  c5_b_node = c5_b_p;
                  c5_root_p = c5_b_node;
                  do {
                    c5_exitg1 = 0;
                    c5_i43 = c5_labelForEachRun.size[0];
                    if ((c5_root_p < 1) || (c5_root_p > c5_i43)) {
                      emlrtDynamicBoundsCheckR2012b(c5_root_p, 1, c5_i43,
                        &c5_oe_emlrtBCI, &c5_d_st);
                    }

                    if (c5_root_p != c5_labelForEachRun.vector.data[c5_root_p -
                        1]) {
                      c5_i45 = c5_labelForEachRun.size[0];
                      c5_i46 = c5_labelForEachRun.size[0];
                      if ((c5_root_p < 1) || (c5_root_p > c5_i46)) {
                        emlrtDynamicBoundsCheckR2012b(c5_root_p, 1, c5_i46,
                          &c5_qe_emlrtBCI, &c5_d_st);
                      }

                      c5_i47 = c5_labelForEachRun.vector.data[c5_root_p - 1];
                      if ((c5_i47 < 1) || (c5_i47 > c5_i45)) {
                        emlrtDynamicBoundsCheckR2012b(c5_i47, 1, c5_i45,
                          &c5_pe_emlrtBCI, &c5_d_st);
                      }

                      c5_i48 = c5_labelForEachRun.size[0];
                      if ((c5_root_p < 1) || (c5_root_p > c5_i48)) {
                        emlrtDynamicBoundsCheckR2012b(c5_root_p, 1, c5_i48,
                          &c5_re_emlrtBCI, &c5_d_st);
                      }

                      c5_labelForEachRun.vector.data[c5_root_p - 1] =
                        c5_labelForEachRun.vector.data[c5_i47 - 1];
                      c5_i52 = c5_labelForEachRun.size[0];
                      if ((c5_root_p < 1) || (c5_root_p > c5_i52)) {
                        emlrtDynamicBoundsCheckR2012b(c5_root_p, 1, c5_i52,
                          &c5_se_emlrtBCI, &c5_d_st);
                      }

                      c5_root_p = c5_labelForEachRun.vector.data[c5_root_p - 1];
                    } else {
                      c5_exitg1 = 1;
                    }
                  } while (c5_exitg1 == 0);

                  if (c5_root_k != c5_root_p) {
                    c5_d_st.site = &c5_dh_emlrtRSI;
                    c5_b_root_k = c5_root_k;
                    c5_b_root_p = c5_root_p;
                    c5_i_k = c5_g_k;
                    c5_c_p = c5_b_p;
                    if (c5_b_root_p < c5_b_root_k) {
                      c5_i51 = c5_labelForEachRun.size[0];
                      if ((c5_b_root_k < 1) || (c5_b_root_k > c5_i51)) {
                        emlrtDynamicBoundsCheckR2012b(c5_b_root_k, 1, c5_i51,
                          &c5_ue_emlrtBCI, &c5_d_st);
                      }

                      c5_labelForEachRun.vector.data[c5_b_root_k - 1] =
                        c5_b_root_p;
                      c5_i54 = c5_labelForEachRun.size[0];
                      if ((c5_i_k < 1) || (c5_i_k > c5_i54)) {
                        emlrtDynamicBoundsCheckR2012b(c5_i_k, 1, c5_i54,
                          &c5_we_emlrtBCI, &c5_d_st);
                      }

                      c5_labelForEachRun.vector.data[c5_i_k - 1] = c5_b_root_p;
                    } else {
                      c5_i50 = c5_labelForEachRun.size[0];
                      if ((c5_b_root_p < 1) || (c5_b_root_p > c5_i50)) {
                        emlrtDynamicBoundsCheckR2012b(c5_b_root_p, 1, c5_i50,
                          &c5_te_emlrtBCI, &c5_d_st);
                      }

                      c5_labelForEachRun.vector.data[c5_b_root_p - 1] =
                        c5_b_root_k;
                      c5_i53 = c5_labelForEachRun.size[0];
                      if ((c5_c_p < 1) || (c5_c_p > c5_i53)) {
                        emlrtDynamicBoundsCheckR2012b(c5_c_p, 1, c5_i53,
                          &c5_ve_emlrtBCI, &c5_d_st);
                      }

                      c5_labelForEachRun.vector.data[c5_c_p - 1] = c5_b_root_k;
                    }
                  }
                }
              }
            }
          }
        }
      }

      c5_i17 = c5_labelForEachRun.size[0];
      if ((c5_c_k < 1) || (c5_c_k > c5_i17)) {
        emlrtDynamicBoundsCheckR2012b(c5_c_k, 1, c5_i17, &c5_xd_emlrtBCI,
          &c5_b_st);
      }

      if (c5_labelForEachRun.vector.data[c5_c_k - 1] == 0) {
        c5_i21 = c5_labelForEachRun.size[0];
        if ((c5_c_k < 1) || (c5_c_k > c5_i21)) {
          emlrtDynamicBoundsCheckR2012b(c5_c_k, 1, c5_i21, &c5_yd_emlrtBCI,
            &c5_b_st);
        }

        c5_labelForEachRun.vector.data[c5_c_k - 1] = c5_nextLabel;
        c5_nextLabel++;
      }

      c5_c_k++;
    }
  }

  c5_array_real_T_Constructor(chartInstance, &c5_r);
  c5_array_cell_wrap_51_2D_Construct(chartInstance, &c5_r1);
  if (c5_numRuns == 0) {
    c5_d1 = 0.0;
    c5_array_real_T_SetSize(chartInstance, &c5_st, &c5_r, &c5_ke_emlrtRTEI, 0);
    c5_array_int32_T_SetSize(chartInstance, &c5_st, &c5_labelForEachRun,
      &c5_le_emlrtRTEI, 1);
    c5_labelForEachRun.vector.data[0] = 0;
    c5_array_cell_wrap_51_2D_SetSize(chartInstance, &c5_st, &c5_r1,
      &c5_me_emlrtRTEI, 1, 0);
  } else {
    c5_array_int32_T_Constructor(chartInstance, &c5_labelsRenumbered);
    c5_array_int32_T_SetSize(chartInstance, &c5_st, &c5_labelsRenumbered,
      &c5_be_emlrtRTEI, c5_labelForEachRun.size[0]);
    c5_numComponents = 0.0;
    c5_b_st.site = &c5_wg_emlrtRSI;
    c5_b = c5_numRuns;
    c5_b_b = c5_b;
    if (c5_b_b < 1) {
      c5_overflow = false;
    } else {
      c5_overflow = (c5_b_b > 2147483646);
    }

    if (c5_overflow) {
      c5_c_st.site = &c5_v_emlrtRSI;
      c5_check_forloop_overflow_error(chartInstance, &c5_c_st);
    }

    for (c5_d_k = 0; c5_d_k < c5_numRuns; c5_d_k++) {
      c5_e_k = c5_d_k + 1;
      c5_i6 = c5_labelForEachRun.size[0];
      if ((c5_e_k < 1) || (c5_e_k > c5_i6)) {
        emlrtDynamicBoundsCheckR2012b(c5_e_k, 1, c5_i6, &c5_pd_emlrtBCI, &c5_st);
      }

      if (c5_labelForEachRun.vector.data[c5_e_k - 1] == c5_e_k) {
        c5_numComponents++;
        c5_i11 = c5_labelsRenumbered.size[0];
        if ((c5_e_k < 1) || (c5_e_k > c5_i11)) {
          emlrtDynamicBoundsCheckR2012b(c5_e_k, 1, c5_i11, &c5_wd_emlrtBCI,
            &c5_st);
        }

        c5_labelsRenumbered.vector.data[c5_e_k - 1] = (int32_T)c5_numComponents;
      }

      c5_i10 = c5_labelsRenumbered.size[0];
      c5_i14 = c5_labelForEachRun.size[0];
      if ((c5_e_k < 1) || (c5_e_k > c5_i14)) {
        emlrtDynamicBoundsCheckR2012b(c5_e_k, 1, c5_i14, &c5_ud_emlrtBCI, &c5_st);
      }

      c5_i15 = c5_labelForEachRun.vector.data[c5_e_k - 1];
      if ((c5_i15 < 1) || (c5_i15 > c5_i10)) {
        emlrtDynamicBoundsCheckR2012b(c5_i15, 1, c5_i10, &c5_td_emlrtBCI, &c5_st);
      }

      c5_i19 = c5_labelsRenumbered.size[0];
      if ((c5_e_k < 1) || (c5_e_k > c5_i19)) {
        emlrtDynamicBoundsCheckR2012b(c5_e_k, 1, c5_i19, &c5_vd_emlrtBCI, &c5_st);
      }

      c5_labelsRenumbered.vector.data[c5_e_k - 1] =
        c5_labelsRenumbered.vector.data[c5_i15 - 1];
    }

    if (c5_numComponents != (real_T)(int32_T)muDoubleScalarFloor
        (c5_numComponents)) {
      emlrtIntegerCheckR2012b(c5_numComponents, &c5_b_emlrtDCI, &c5_st);
    }

    c5_array_int32_T_SetSize(chartInstance, &c5_st, &c5_labelForEachRun,
      &c5_ce_emlrtRTEI, (int32_T)c5_numComponents);
    if (c5_numComponents != (real_T)(int32_T)muDoubleScalarFloor
        (c5_numComponents)) {
      emlrtIntegerCheckR2012b(c5_numComponents, &c5_b_emlrtDCI, &c5_st);
    }

    c5_c_loop_ub = (int32_T)c5_numComponents - 1;
    for (c5_i9 = 0; c5_i9 <= c5_c_loop_ub; c5_i9++) {
      c5_labelForEachRun.vector.data[c5_i9] = 0;
    }

    c5_b_st.site = &c5_vg_emlrtRSI;
    c5_c_b = c5_numRuns;
    c5_d_b = c5_c_b;
    if (c5_d_b < 1) {
      c5_b_overflow = false;
    } else {
      c5_b_overflow = (c5_d_b > 2147483646);
    }

    if (c5_b_overflow) {
      c5_c_st.site = &c5_v_emlrtRSI;
      c5_check_forloop_overflow_error(chartInstance, &c5_c_st);
    }

    for (c5_f_k = 0; c5_f_k < c5_numRuns; c5_f_k++) {
      c5_e_k = c5_f_k + 1;
      c5_i23 = c5_labelsRenumbered.size[0];
      if ((c5_e_k < 1) || (c5_e_k > c5_i23)) {
        emlrtDynamicBoundsCheckR2012b(c5_e_k, 1, c5_i23, &c5_je_emlrtBCI, &c5_st);
      }

      c5_idx = c5_labelsRenumbered.vector.data[c5_e_k - 1];
      c5_i25 = c5_labelForEachRun.size[0];
      if ((c5_idx < 1) || (c5_idx > c5_i25)) {
        emlrtDynamicBoundsCheckR2012b(c5_idx, 1, c5_i25, &c5_ke_emlrtBCI, &c5_st);
      }

      c5_i27 = c5_endRow.size[0];
      if ((c5_e_k < 1) || (c5_e_k > c5_i27)) {
        emlrtDynamicBoundsCheckR2012b(c5_e_k, 1, c5_i27, &c5_le_emlrtBCI, &c5_st);
      }

      c5_i29 = c5_startRow.size[0];
      if ((c5_e_k < 1) || (c5_e_k > c5_i29)) {
        emlrtDynamicBoundsCheckR2012b(c5_e_k, 1, c5_i29, &c5_me_emlrtBCI, &c5_st);
      }

      c5_i32 = c5_labelForEachRun.size[0];
      if ((c5_idx < 1) || (c5_idx > c5_i32)) {
        emlrtDynamicBoundsCheckR2012b(c5_idx, 1, c5_i32, &c5_ne_emlrtBCI, &c5_st);
      }

      c5_labelForEachRun.vector.data[c5_idx - 1] =
        ((c5_labelForEachRun.vector.data[c5_idx - 1] +
          c5_endRow.vector.data[c5_e_k - 1]) - c5_startRow.vector.data[c5_e_k -
         1]) + 1;
    }

    c5_d1 = c5_numComponents;
    c5_b_st.site = &c5_ug_emlrtRSI;
    c5_c_st.site = &c5_eh_emlrtRSI;
    c5_d_st.site = &c5_fh_emlrtRSI;
    c5_vlen = c5_labelForEachRun.size[0];
    c5_e_st.site = &c5_gh_emlrtRSI;
    c5_b_vlen = c5_vlen;
    if ((c5_labelForEachRun.size[0] == 0) || (c5_b_vlen == 0)) {
      c5_y = 0.0;
    } else {
      c5_f_st.site = &c5_hh_emlrtRSI;
      c5_c_vlen = c5_b_vlen;
      c5_g_st.site = &c5_ih_emlrtRSI;
      c5_d_vlen = c5_c_vlen;
      if (c5_d_vlen < 4096) {
        c5_h_st.site = &c5_jh_emlrtRSI;
        c5_y = c5_sumColumnB(chartInstance, &c5_h_st, &c5_labelForEachRun,
                             c5_d_vlen);
      } else {
        c5_c_a = c5_d_vlen;
        c5_nfb = (int32_T)((uint32_T)c5_c_a >> 12);
        c5_inb = c5_nfb << 12;
        c5_lidx = c5_inb;
        c5_nleft = c5_d_vlen - c5_inb;
        c5_b_s = c5_sumColumnB4(chartInstance, &c5_labelForEachRun, 1);
        for (c5_ib = 2; c5_ib <= c5_nfb; c5_ib++) {
          c5_b_s += c5_sumColumnB4(chartInstance, &c5_labelForEachRun, 1 +
            ((c5_ib - 1) << 12));
        }

        if (c5_nleft > 0) {
          c5_h_st.site = &c5_kh_emlrtRSI;
          c5_b_s += c5_b_sumColumnB(chartInstance, &c5_h_st, &c5_labelForEachRun,
            c5_nleft, c5_lidx + 1);
        }

        c5_y = c5_b_s;
      }
    }

    if (!(c5_y >= 0.0)) {
      emlrtNonNegativeCheckR2012b(c5_y, &c5_d_emlrtDCI, &c5_st);
    }

    c5_d2 = c5_y;
    if (c5_d2 != (real_T)(int32_T)muDoubleScalarFloor(c5_d2)) {
      emlrtIntegerCheckR2012b(c5_d2, &c5_c_emlrtDCI, &c5_st);
    }

    c5_b_iv[0] = (int32_T)c5_d2;
    c5_array_real_T_SetSize(chartInstance, &c5_st, &c5_r, &c5_de_emlrtRTEI,
      c5_b_iv[0]);
    c5_array_int32_T_Constructor(chartInstance, &c5_b_x);
    c5_b_st.site = &c5_tg_emlrtRSI;
    c5_array_int32_T_SetSize(chartInstance, &c5_b_st, &c5_b_x, &c5_ee_emlrtRTEI,
      c5_labelForEachRun.size[0]);
    c5_f_loop_ub = c5_labelForEachRun.size[0] - 1;
    for (c5_i35 = 0; c5_i35 <= c5_f_loop_ub; c5_i35++) {
      c5_b_x.vector.data[c5_i35] = c5_labelForEachRun.vector.data[c5_i35];
    }

    c5_c_st.site = &c5_oh_emlrtRSI;
    c5_dim = 2;
    if ((real_T)c5_b_x.size[0] != 1.0) {
      c5_dim = 1;
    }

    c5_array_int32_T_Constructor(chartInstance, &c5_c_x);
    c5_array_int32_T_SetSize(chartInstance, &c5_c_st, &c5_c_x, &c5_pd_emlrtRTEI,
      c5_b_x.size[0]);
    c5_g_loop_ub = c5_b_x.size[0] - 1;
    for (c5_i37 = 0; c5_i37 <= c5_g_loop_ub; c5_i37++) {
      c5_c_x.vector.data[c5_i37] = c5_b_x.vector.data[c5_i37];
    }

    c5_d_st.site = &c5_ph_emlrtRSI;
    c5_useConstantDim(chartInstance, &c5_d_st, &c5_c_x, c5_dim, &c5_b_x);
    c5_array_int32_T_Destructor(chartInstance, &c5_c_x);
    c5_array_int32_T_Constructor(chartInstance, &c5_idxCount);
    c5_array_int32_T_SetSize(chartInstance, &c5_st, &c5_idxCount,
      &c5_fe_emlrtRTEI, 1 + c5_b_x.size[0]);
    c5_idxCount.vector.data[0] = 0;
    c5_h_loop_ub = c5_b_x.size[0] - 1;
    for (c5_i41 = 0; c5_i41 <= c5_h_loop_ub; c5_i41++) {
      c5_idxCount.vector.data[c5_i41 + 1] = c5_b_x.vector.data[c5_i41];
    }

    c5_b_st.site = &c5_sg_emlrtRSI;
    c5_e_b = c5_numRuns;
    c5_f_b = c5_e_b;
    if (c5_f_b < 1) {
      c5_c_overflow = false;
    } else {
      c5_c_overflow = (c5_f_b > 2147483646);
    }

    if (c5_c_overflow) {
      c5_c_st.site = &c5_v_emlrtRSI;
      c5_check_forloop_overflow_error(chartInstance, &c5_c_st);
    }

    for (c5_h_k = 0; c5_h_k < c5_numRuns; c5_h_k++) {
      c5_e_k = c5_h_k + 1;
      c5_i49 = c5_startCol.size[0];
      if ((c5_e_k < 1) || (c5_e_k > c5_i49)) {
        emlrtDynamicBoundsCheckR2012b(c5_e_k, 1, c5_i49, &c5_xe_emlrtBCI, &c5_st);
      }

      c5_d_a = c5_startCol.vector.data[c5_e_k - 1] - 1;
      c5_c = c5_d_a;
      c5_e_a = c5_c;
      c5_column_offset = c5_e_a * 120;
      c5_i55 = c5_labelsRenumbered.size[0];
      if ((c5_e_k < 1) || (c5_e_k > c5_i55)) {
        emlrtDynamicBoundsCheckR2012b(c5_e_k, 1, c5_i55, &c5_ye_emlrtBCI, &c5_st);
      }

      c5_idx = c5_labelsRenumbered.vector.data[c5_e_k - 1];
      c5_i57 = c5_startRow.size[0];
      if ((c5_e_k < 1) || (c5_e_k > c5_i57)) {
        emlrtDynamicBoundsCheckR2012b(c5_e_k, 1, c5_i57, &c5_af_emlrtBCI, &c5_st);
      }

      c5_i58 = c5_startRow.vector.data[c5_e_k - 1];
      c5_i59 = c5_endRow.size[0];
      if ((c5_e_k < 1) || (c5_e_k > c5_i59)) {
        emlrtDynamicBoundsCheckR2012b(c5_e_k, 1, c5_i59, &c5_bf_emlrtBCI, &c5_st);
      }

      c5_i60 = c5_endRow.vector.data[c5_e_k - 1];
      c5_b_st.site = &c5_rg_emlrtRSI;
      c5_f_a = c5_i58;
      c5_g_b = c5_i60;
      c5_g_a = c5_f_a;
      c5_h_b = c5_g_b;
      if (c5_g_a > c5_h_b) {
        c5_d_overflow = false;
      } else {
        c5_d_overflow = (c5_h_b > 2147483646);
      }

      if (c5_d_overflow) {
        c5_c_st.site = &c5_v_emlrtRSI;
        c5_check_forloop_overflow_error(chartInstance, &c5_c_st);
      }

      for (c5_rowidx = c5_i58; c5_rowidx <= c5_i60; c5_rowidx++) {
        c5_i64 = c5_idxCount.size[0];
        if ((c5_idx < 1) || (c5_idx > c5_i64)) {
          emlrtDynamicBoundsCheckR2012b(c5_idx, 1, c5_i64, &c5_ef_emlrtBCI,
            &c5_st);
        }

        c5_h_a = c5_idxCount.vector.data[c5_idx - 1] + 1;
        c5_b_c = c5_h_a;
        c5_i66 = c5_idxCount.size[0];
        if ((c5_idx < 1) || (c5_idx > c5_i66)) {
          emlrtDynamicBoundsCheckR2012b(c5_idx, 1, c5_i66, &c5_ff_emlrtBCI,
            &c5_st);
        }

        c5_idxCount.vector.data[c5_idx - 1] = c5_b_c;
        c5_i69 = c5_r.size[0];
        c5_i71 = c5_idxCount.size[0];
        if ((c5_idx < 1) || (c5_idx > c5_i71)) {
          emlrtDynamicBoundsCheckR2012b(c5_idx, 1, c5_i71, &c5_hf_emlrtBCI,
            &c5_st);
        }

        c5_i73 = c5_idxCount.vector.data[c5_idx - 1];
        if ((c5_i73 < 1) || (c5_i73 > c5_i69)) {
          emlrtDynamicBoundsCheckR2012b(c5_i73, 1, c5_i69, &c5_gf_emlrtBCI,
            &c5_st);
        }

        c5_r.vector.data[c5_i73 - 1] = (real_T)(c5_rowidx + c5_column_offset);
      }
    }

    c5_array_int32_T_Destructor(chartInstance, &c5_labelsRenumbered);
    c5_array_cell_wrap_51_Constructor(chartInstance, &c5_r2);
    c5_array_real_T_SetSize(chartInstance, &c5_st, &c5_r2.f1, &c5_ge_emlrtRTEI,
      0);
    c5_array_cell_wrap_51_1s_Construct(chartInstance, c5_rv);
    c5_array_cell_wrap_51_Copy(chartInstance, &c5_st, &c5_rv[0], &c5_r2,
      &c5_ge_emlrtRTEI);
    c5_array_cell_wrap_51_Destructor(chartInstance, &c5_r2);
    c5_b_st.site = &c5_qg_emlrtRSI;
    c5_repmat(chartInstance, &c5_b_st, c5_rv, c5_numComponents, &c5_r1);
    c5_array_cell_wrap_51_1s_Destructo(chartInstance, c5_rv);
    c5_b_st.site = &c5_pg_emlrtRSI;
    c5_array_int32_T_SetSize(chartInstance, &c5_b_st, &c5_b_x, &c5_he_emlrtRTEI,
      c5_labelForEachRun.size[0]);
    c5_i_loop_ub = c5_labelForEachRun.size[0] - 1;
    for (c5_i56 = 0; c5_i56 <= c5_i_loop_ub; c5_i56++) {
      c5_b_x.vector.data[c5_i56] = c5_labelForEachRun.vector.data[c5_i56];
    }

    c5_c_st.site = &c5_oh_emlrtRSI;
    c5_b_dim = 2;
    if ((real_T)c5_b_x.size[0] != 1.0) {
      c5_b_dim = 1;
    }

    c5_array_int32_T_Constructor(chartInstance, &c5_d_x);
    c5_array_int32_T_SetSize(chartInstance, &c5_c_st, &c5_d_x, &c5_pd_emlrtRTEI,
      c5_b_x.size[0]);
    c5_j_loop_ub = c5_b_x.size[0] - 1;
    for (c5_i61 = 0; c5_i61 <= c5_j_loop_ub; c5_i61++) {
      c5_d_x.vector.data[c5_i61] = c5_b_x.vector.data[c5_i61];
    }

    c5_d_st.site = &c5_ph_emlrtRSI;
    c5_useConstantDim(chartInstance, &c5_d_st, &c5_d_x, c5_b_dim, &c5_b_x);
    c5_array_int32_T_Destructor(chartInstance, &c5_d_x);
    c5_array_int32_T_SetSize(chartInstance, &c5_st, &c5_idxCount,
      &c5_ie_emlrtRTEI, 1 + c5_b_x.size[0]);
    c5_idxCount.vector.data[0] = 0;
    c5_k_loop_ub = c5_b_x.size[0] - 1;
    for (c5_i62 = 0; c5_i62 <= c5_k_loop_ub; c5_i62++) {
      c5_idxCount.vector.data[c5_i62 + 1] = c5_b_x.vector.data[c5_i62];
    }

    c5_array_int32_T_Destructor(chartInstance, &c5_b_x);
    c5_i63 = (int32_T)c5_numComponents;
    emlrtForLoopVectorCheckR2021a(1.0, 1.0, c5_numComponents, mxDOUBLE_CLASS,
      c5_i63, &c5_bi_emlrtRTEI, &c5_st);
    for (c5_j_k = 0; c5_j_k < c5_i63; c5_j_k++) {
      c5_k_k = (real_T)c5_j_k + 1.0;
      c5_i65 = c5_idxCount.size[0];
      c5_i67 = (int32_T)c5_k_k;
      if ((c5_i67 < 1) || (c5_i67 > c5_i65)) {
        emlrtDynamicBoundsCheckR2012b(c5_i67, 1, c5_i65, &c5_cf_emlrtBCI, &c5_st);
      }

      c5_i68 = c5_idxCount.vector.data[c5_i67 - 1] + 1;
      c5_i70 = c5_idxCount.size[0];
      c5_i72 = (int32_T)(c5_k_k + 1.0);
      if ((c5_i72 < 1) || (c5_i72 > c5_i70)) {
        emlrtDynamicBoundsCheckR2012b(c5_i72, 1, c5_i70, &c5_df_emlrtBCI, &c5_st);
      }

      c5_i74 = c5_idxCount.vector.data[c5_i72 - 1];
      c5_i_b = (c5_i68 > c5_i74);
      if (c5_i_b) {
        c5_i76 = 0;
        c5_i77 = -1;
      } else {
        c5_i75 = c5_r.size[0];
        if ((c5_i68 < 1) || (c5_i68 > c5_i75)) {
          emlrtDynamicBoundsCheckR2012b(c5_i68, 1, c5_i75, &c5_kd_emlrtBCI,
            &c5_st);
        }

        c5_i76 = c5_i68 - 1;
        c5_i79 = c5_r.size[0];
        if ((c5_i74 < 1) || (c5_i74 > c5_i79)) {
          emlrtDynamicBoundsCheckR2012b(c5_i74, 1, c5_i79, &c5_jd_emlrtBCI,
            &c5_st);
        }

        c5_i77 = c5_i74 - 1;
      }

      c5_i78 = c5_r1.size[1] - 1;
      c5_i80 = (int32_T)c5_k_k - 1;
      if ((c5_i80 < 0) || (c5_i80 > c5_i78)) {
        emlrtDynamicBoundsCheckR2012b(c5_i80, 0, c5_i78, &c5_if_emlrtBCI, &c5_st);
      }

      c5_array_real_T_SetSize(chartInstance, &c5_st,
        &c5_r1.vector.data[c5_r1.size[0] * c5_i80].f1, &c5_je_emlrtRTEI, (c5_i77
        - c5_i76) + 1);
      c5_l_loop_ub = c5_i77 - c5_i76;
      for (c5_i81 = 0; c5_i81 <= c5_l_loop_ub; c5_i81++) {
        c5_i82 = c5_r1.size[1] - 1;
        c5_i83 = (int32_T)c5_k_k - 1;
        if ((c5_i83 < 0) || (c5_i83 > c5_i82)) {
          emlrtDynamicBoundsCheckR2012b(c5_i83, 0, c5_i82, &c5_if_emlrtBCI,
            &c5_st);
        }

        c5_r1.vector.data[c5_i83].f1.vector.data[c5_i81] =
          c5_r.vector.data[c5_i76 + c5_i81];
      }
    }

    c5_array_int32_T_Destructor(chartInstance, &c5_idxCount);
  }

  c5_array_int32_T_Destructor(chartInstance, &c5_startCol);
  c5_array_int32_T_Destructor(chartInstance, &c5_endRow);
  c5_array_int32_T_Destructor(chartInstance, &c5_startRow);
  c5_CC->NumObjects = c5_d1;
  c5_st.site = &c5_og_emlrtRSI;
  c5_array_real_T_SetSize(chartInstance, &c5_st, &c5_CC->RegionIndices,
    &c5_ne_emlrtRTEI, c5_r.size[0]);
  c5_b_loop_ub = c5_r.size[0] - 1;
  for (c5_i5 = 0; c5_i5 <= c5_b_loop_ub; c5_i5++) {
    c5_CC->RegionIndices.vector.data[c5_i5] = c5_r.vector.data[c5_i5];
  }

  c5_array_real_T_Destructor(chartInstance, &c5_r);
  c5_st.site = &c5_og_emlrtRSI;
  c5_array_int32_T_SetSize(chartInstance, &c5_st, &c5_CC->RegionLengths,
    &c5_oe_emlrtRTEI, c5_labelForEachRun.size[0]);
  c5_d_loop_ub = c5_labelForEachRun.size[0] - 1;
  for (c5_i12 = 0; c5_i12 <= c5_d_loop_ub; c5_i12++) {
    c5_CC->RegionLengths.vector.data[c5_i12] =
      c5_labelForEachRun.vector.data[c5_i12];
  }

  c5_array_int32_T_Destructor(chartInstance, &c5_labelForEachRun);
  c5_st.site = &c5_og_emlrtRSI;
  c5_array_cell_wrap_51_2D_SetSize(chartInstance, &c5_st, &c5_CC->PixelIdxList,
    &c5_pe_emlrtRTEI, 1, c5_r1.size[1]);
  c5_e_loop_ub = c5_r1.size[1] - 1;
  for (c5_i18 = 0; c5_i18 <= c5_e_loop_ub; c5_i18++) {
    c5_st.site = &c5_og_emlrtRSI;
    c5_array_cell_wrap_51_Copy(chartInstance, &c5_st,
      &c5_CC->PixelIdxList.vector.data[c5_i18], &c5_r1.vector.data[c5_i18],
      &c5_pe_emlrtRTEI);
  }

  c5_array_cell_wrap_51_2D_Destructo(chartInstance, &c5_r1);
}

static real_T c5_sumColumnB(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_int32_T *c5_b_x,
  int32_T c5_vlen)
{
  emlrtStack c5_b_st;
  emlrtStack c5_c_st;
  emlrtStack c5_st;
  real_T c5_b_y;
  real_T c5_c_y;
  real_T c5_y;
  int32_T c5_b;
  int32_T c5_b_b;
  int32_T c5_b_k;
  int32_T c5_b_vlen;
  int32_T c5_b_vstart;
  int32_T c5_c_a;
  int32_T c5_c_b;
  int32_T c5_c_k;
  int32_T c5_c_vlen;
  int32_T c5_d_b;
  int32_T c5_d_k;
  int32_T c5_e_k;
  int32_T c5_f_k;
  int32_T c5_g_k;
  int32_T c5_h_k;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i2;
  int32_T c5_i_k;
  int32_T c5_inb;
  int32_T c5_k;
  int32_T c5_lidx;
  int32_T c5_nfb;
  int32_T c5_nleft;
  int32_T c5_vstart;
  boolean_T c5_b_overflow;
  boolean_T c5_overflow;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_c_st.prev = &c5_b_st;
  c5_c_st.tls = c5_b_st.tls;
  if (c5_vlen <= 1024) {
    c5_st.site = &c5_lh_emlrtRSI;
    c5_b_vlen = c5_vlen - 1;
    c5_y = (real_T)c5_b_x->vector.data[0];
    c5_i = c5_b_vlen;
    c5_b_st.site = &c5_nh_emlrtRSI;
    c5_b = c5_i;
    c5_b_b = c5_b;
    if (c5_b_b < 1) {
      c5_overflow = false;
    } else {
      c5_overflow = (c5_b_b > 2147483646);
    }

    if (c5_overflow) {
      c5_c_st.site = &c5_v_emlrtRSI;
      c5_check_forloop_overflow_error(chartInstance, &c5_c_st);
    }

    c5_i1 = (uint16_T)c5_i - 1;
    for (c5_f_k = 0; c5_f_k <= c5_i1; c5_f_k++) {
      c5_g_k = c5_f_k;
      c5_y += (real_T)c5_b_x->vector.data[c5_g_k + 1];
    }
  } else {
    c5_c_a = c5_vlen;
    c5_nfb = (int32_T)((uint32_T)c5_c_a >> 10);
    c5_inb = c5_nfb << 10;
    c5_y = (real_T)c5_b_x->vector.data[0];
    for (c5_k = 0; c5_k < 1023; c5_k++) {
      c5_c_k = c5_k;
      c5_y += (real_T)c5_b_x->vector.data[c5_c_k + 1];
    }

    for (c5_b_k = 2; c5_b_k <= c5_nfb; c5_b_k++) {
      c5_vstart = (c5_b_k - 1) << 10;
      c5_b_y = (real_T)c5_b_x->vector.data[c5_vstart];
      for (c5_d_k = 0; c5_d_k < 1023; c5_d_k++) {
        c5_e_k = c5_d_k;
        c5_b_y += (real_T)c5_b_x->vector.data[(c5_vstart + c5_e_k) + 1];
      }

      c5_y += c5_b_y;
    }

    if (c5_vlen > c5_inb) {
      c5_nleft = c5_vlen - c5_inb;
      c5_lidx = c5_inb;
      c5_st.site = &c5_mh_emlrtRSI;
      c5_c_vlen = c5_nleft - 1;
      c5_b_vstart = c5_lidx;
      c5_c_y = (real_T)c5_b_x->vector.data[c5_b_vstart];
      c5_i2 = c5_c_vlen;
      c5_b_st.site = &c5_nh_emlrtRSI;
      c5_c_b = c5_i2;
      c5_d_b = c5_c_b;
      if (c5_d_b < 1) {
        c5_b_overflow = false;
      } else {
        c5_b_overflow = (c5_d_b > 2147483646);
      }

      if (c5_b_overflow) {
        c5_c_st.site = &c5_v_emlrtRSI;
        c5_check_forloop_overflow_error(chartInstance, &c5_c_st);
      }

      for (c5_h_k = 0; c5_h_k < c5_i2; c5_h_k++) {
        c5_i_k = c5_h_k;
        c5_c_y += (real_T)c5_b_x->vector.data[(c5_b_vstart + c5_i_k) + 1];
      }

      c5_y += c5_c_y;
    }
  }

  return c5_y;
}

static real_T c5_sumColumnB4(SFc5_flightControlSystemInstanceStruct
  *chartInstance, c5_coder_array_int32_T *c5_b_x, int32_T c5_vstart)
{
  real_T c5_psum1;
  real_T c5_psum2;
  real_T c5_psum3;
  real_T c5_psum4;
  int32_T c5_b_k;
  int32_T c5_i2;
  int32_T c5_i3;
  int32_T c5_i4;
  int32_T c5_k;
  (void)chartInstance;
  c5_i2 = c5_vstart + 1023;
  c5_i3 = c5_vstart + 2047;
  c5_i4 = c5_vstart + 3071;
  c5_psum1 = (real_T)c5_b_x->vector.data[c5_vstart - 1];
  c5_psum2 = (real_T)c5_b_x->vector.data[c5_i2];
  c5_psum3 = (real_T)c5_b_x->vector.data[c5_i3];
  c5_psum4 = (real_T)c5_b_x->vector.data[c5_i4];
  for (c5_k = 0; c5_k < 1023; c5_k++) {
    c5_b_k = c5_k + 1;
    c5_psum1 += (real_T)c5_b_x->vector.data[(c5_vstart + c5_b_k) - 1];
    c5_psum2 += (real_T)c5_b_x->vector.data[c5_i2 + c5_b_k];
    c5_psum3 += (real_T)c5_b_x->vector.data[c5_i3 + c5_b_k];
    c5_psum4 += (real_T)c5_b_x->vector.data[c5_i4 + c5_b_k];
  }

  return (c5_psum1 + c5_psum2) + (c5_psum3 + c5_psum4);
}

static real_T c5_b_sumColumnB(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_int32_T *c5_b_x,
  int32_T c5_vlen, int32_T c5_vstart)
{
  emlrtStack c5_b_st;
  emlrtStack c5_c_st;
  emlrtStack c5_st;
  real_T c5_b_y;
  real_T c5_c_y;
  real_T c5_y;
  int32_T c5_b;
  int32_T c5_b_b;
  int32_T c5_b_k;
  int32_T c5_b_vlen;
  int32_T c5_b_vstart;
  int32_T c5_c_a;
  int32_T c5_c_b;
  int32_T c5_c_k;
  int32_T c5_c_vlen;
  int32_T c5_c_vstart;
  int32_T c5_d_b;
  int32_T c5_d_k;
  int32_T c5_d_vstart;
  int32_T c5_e_k;
  int32_T c5_e_vstart;
  int32_T c5_f_k;
  int32_T c5_g_k;
  int32_T c5_h_k;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i_k;
  int32_T c5_inb;
  int32_T c5_k;
  int32_T c5_lidx;
  int32_T c5_nfb;
  int32_T c5_nleft;
  boolean_T c5_b_overflow;
  boolean_T c5_overflow;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_c_st.prev = &c5_b_st;
  c5_c_st.tls = c5_b_st.tls;
  if (c5_vlen <= 1024) {
    c5_st.site = &c5_lh_emlrtRSI;
    c5_b_vlen = c5_vlen - 1;
    c5_b_vstart = c5_vstart - 1;
    c5_y = (real_T)c5_b_x->vector.data[c5_b_vstart];
    c5_i = c5_b_vlen;
    c5_b_st.site = &c5_nh_emlrtRSI;
    c5_b = c5_i;
    c5_b_b = c5_b;
    if (c5_b_b < 1) {
      c5_overflow = false;
    } else {
      c5_overflow = (c5_b_b > 2147483646);
    }

    if (c5_overflow) {
      c5_c_st.site = &c5_v_emlrtRSI;
      c5_check_forloop_overflow_error(chartInstance, &c5_c_st);
    }

    for (c5_f_k = 0; c5_f_k < c5_i; c5_f_k++) {
      c5_g_k = c5_f_k;
      c5_y += (real_T)c5_b_x->vector.data[(c5_b_vstart + c5_g_k) + 1];
    }
  } else {
    c5_c_a = c5_vlen;
    c5_nfb = (int32_T)((uint32_T)c5_c_a >> 10);
    c5_inb = c5_nfb << 10;
    c5_c_vstart = c5_vstart - 1;
    c5_y = (real_T)c5_b_x->vector.data[c5_c_vstart];
    for (c5_k = 0; c5_k < 1023; c5_k++) {
      c5_c_k = c5_k;
      c5_y += (real_T)c5_b_x->vector.data[(c5_c_vstart + c5_c_k) + 1];
    }

    for (c5_b_k = 2; c5_b_k <= c5_nfb; c5_b_k++) {
      c5_d_vstart = (c5_vstart + ((c5_b_k - 1) << 10)) - 1;
      c5_b_y = (real_T)c5_b_x->vector.data[c5_d_vstart];
      for (c5_d_k = 0; c5_d_k < 1023; c5_d_k++) {
        c5_e_k = c5_d_k;
        c5_b_y += (real_T)c5_b_x->vector.data[(c5_d_vstart + c5_e_k) + 1];
      }

      c5_y += c5_b_y;
    }

    if (c5_vlen > c5_inb) {
      c5_nleft = c5_vlen - c5_inb;
      c5_lidx = c5_vstart + c5_inb;
      c5_st.site = &c5_mh_emlrtRSI;
      c5_c_vlen = c5_nleft - 1;
      c5_e_vstart = c5_lidx - 1;
      c5_c_y = (real_T)c5_b_x->vector.data[c5_e_vstart];
      c5_i1 = c5_c_vlen;
      c5_b_st.site = &c5_nh_emlrtRSI;
      c5_c_b = c5_i1;
      c5_d_b = c5_c_b;
      if (c5_d_b < 1) {
        c5_b_overflow = false;
      } else {
        c5_b_overflow = (c5_d_b > 2147483646);
      }

      if (c5_b_overflow) {
        c5_c_st.site = &c5_v_emlrtRSI;
        c5_check_forloop_overflow_error(chartInstance, &c5_c_st);
      }

      for (c5_h_k = 0; c5_h_k < c5_i1; c5_h_k++) {
        c5_i_k = c5_h_k;
        c5_c_y += (real_T)c5_b_x->vector.data[(c5_e_vstart + c5_i_k) + 1];
      }

      c5_y += c5_c_y;
    }
  }

  return c5_y;
}

static void c5_useConstantDim(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_int32_T
  *c5_b_varargin_2, int32_T c5_varargin_3, c5_coder_array_int32_T
  *c5_varargout_1)
{
  emlrtStack c5_b_st;
  emlrtStack c5_c_st;
  emlrtStack c5_d_st;
  emlrtStack c5_e_st;
  emlrtStack c5_st;
  int32_T c5_b;
  int32_T c5_b_b;
  int32_T c5_b_k;
  int32_T c5_b_loop_ub;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i2;
  int32_T c5_k;
  int32_T c5_loop_ub;
  int32_T c5_nx;
  boolean_T c5_overflow;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_c_st.prev = &c5_b_st;
  c5_c_st.tls = c5_b_st.tls;
  c5_d_st.prev = &c5_c_st;
  c5_d_st.tls = c5_c_st.tls;
  c5_e_st.prev = &c5_d_st;
  c5_e_st.tls = c5_d_st.tls;
  if (c5_varargin_3 == 1) {
    c5_st.site = &c5_qh_emlrtRSI;
    c5_array_int32_T_SetSize(chartInstance, &c5_st, c5_varargout_1,
      &c5_qe_emlrtRTEI, c5_b_varargin_2->size[0]);
    c5_b_loop_ub = c5_b_varargin_2->size[0] - 1;
    for (c5_i1 = 0; c5_i1 <= c5_b_loop_ub; c5_i1++) {
      c5_varargout_1->vector.data[c5_i1] = c5_b_varargin_2->vector.data[c5_i1];
    }

    c5_b_st.site = &c5_rh_emlrtRSI;
    if (c5_varargout_1->size[0] != 0) {
      c5_c_st.site = &c5_sh_emlrtRSI;
      c5_nx = c5_varargout_1->size[0] - 1;
      if (!((real_T)c5_varargout_1->size[0] == 1.0)) {
        c5_i2 = c5_nx;
        c5_d_st.site = &c5_th_emlrtRSI;
        c5_b = c5_i2;
        c5_b_b = c5_b;
        if (c5_b_b < 1) {
          c5_overflow = false;
        } else {
          c5_overflow = (c5_b_b > 2147483646);
        }

        if (c5_overflow) {
          c5_e_st.site = &c5_v_emlrtRSI;
          c5_check_forloop_overflow_error(chartInstance, &c5_e_st);
        }

        for (c5_k = 0; c5_k < c5_i2; c5_k++) {
          c5_b_k = c5_k;
          c5_varargout_1->vector.data[c5_b_k + 1] += c5_varargout_1->
            vector.data[c5_b_k];
        }
      }
    }
  } else {
    c5_array_int32_T_SetSize(chartInstance, c5_sp, c5_varargout_1,
      &c5_qe_emlrtRTEI, c5_b_varargin_2->size[0]);
    c5_loop_ub = c5_b_varargin_2->size[0] - 1;
    for (c5_i = 0; c5_i <= c5_loop_ub; c5_i++) {
      c5_varargout_1->vector.data[c5_i] = c5_b_varargin_2->vector.data[c5_i];
    }
  }
}

static void c5_repmat(SFc5_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c5_sp, c5_cell_wrap_51 c5_c_a[1], real_T
                      c5_b_varargin_2, c5_coder_array_cell_wrap_51_2D *c5_b)
{
  c5_coder_array_boolean_T_2D c5_tile;
  c5_coder_array_cell_wrap_51_2D c5_r;
  emlrtStack c5_b_st;
  emlrtStack c5_st;
  const mxArray *c5_b_y = NULL;
  const mxArray *c5_c_y = NULL;
  const mxArray *c5_d_y = NULL;
  const mxArray *c5_e_y = NULL;
  const mxArray *c5_f_y = NULL;
  const mxArray *c5_g_y = NULL;
  const mxArray *c5_y = NULL;
  real_T c5_arg;
  real_T c5_b_arg;
  real_T c5_b_x;
  real_T c5_c_varargin_2;
  real_T c5_d_varargin_2;
  real_T c5_n;
  int32_T c5_outsize[2];
  int32_T c5_b_jtilecol;
  int32_T c5_b_loop_ub;
  int32_T c5_d_b;
  int32_T c5_e_b;
  int32_T c5_e_u;
  int32_T c5_f_u;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_ibtile;
  int32_T c5_jtilecol;
  int32_T c5_loop_ub;
  int32_T c5_ntilecols;
  boolean_T c5_b_b;
  boolean_T c5_b_p;
  boolean_T c5_c_b;
  boolean_T c5_c_p;
  boolean_T c5_overflow;
  boolean_T c5_p;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_st.site = &c5_uh_emlrtRSI;
  c5_c_varargin_2 = c5_b_varargin_2;
  c5_arg = c5_c_varargin_2;
  if (c5_arg != c5_arg) {
    c5_p = false;
  } else {
    c5_b_x = c5_arg;
    c5_b_b = muDoubleScalarIsInf(c5_b_x);
    if (c5_b_b) {
      c5_p = false;
    } else {
      c5_p = true;
    }
  }

  if (c5_p) {
    c5_b_arg = c5_c_varargin_2;
    if (c5_b_arg > 2.147483647E+9) {
      c5_b_p = false;
    } else {
      c5_b_p = true;
    }

    if (c5_b_p) {
      c5_c_b = true;
    } else {
      c5_c_b = false;
    }
  } else {
    c5_c_b = false;
  }

  if (!c5_c_b) {
    c5_y = NULL;
    sf_mex_assign(&c5_y, sf_mex_create("y", c5_cv9, 10, 0U, 1, 0U, 2, 1, 28),
                  false);
    c5_b_y = NULL;
    sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_cv9, 10, 0U, 1, 0U, 2, 1, 28),
                  false);
    c5_e_u = MIN_int32_T;
    c5_c_y = NULL;
    sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_e_u, 6, 0U, 0, 0U, 0), false);
    c5_f_u = MAX_int32_T;
    c5_f_y = NULL;
    sf_mex_assign(&c5_f_y, sf_mex_create("y", &c5_f_u, 6, 0U, 0, 0U, 0), false);
    sf_mex_call(&c5_st, &c5_v_emlrtMCI, "error", 0U, 2U, 14, c5_y, 14,
                sf_mex_call(&c5_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c5_st, NULL, "message", 1U, 3U, 14, c5_b_y, 14, c5_c_y, 14, c5_f_y)));
  }

  c5_d_varargin_2 = c5_c_varargin_2;
  if (c5_d_varargin_2 <= 0.0) {
    c5_n = 0.0;
  } else {
    c5_n = c5_d_varargin_2;
  }

  if (!(c5_n <= 2.147483647E+9)) {
    c5_d_y = NULL;
    sf_mex_assign(&c5_d_y, sf_mex_create("y", c5_cv8, 10, 0U, 1, 0U, 2, 1, 21),
                  false);
    c5_e_y = NULL;
    sf_mex_assign(&c5_e_y, sf_mex_create("y", c5_cv8, 10, 0U, 1, 0U, 2, 1, 21),
                  false);
    sf_mex_call(&c5_st, &c5_w_emlrtMCI, "error", 0U, 2U, 14, c5_d_y, 14,
                sf_mex_call(&c5_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c5_st, NULL, "message", 1U, 1U, 14, c5_e_y)));
  }

  c5_array_boolean_T_2D_Constructor(chartInstance, &c5_tile);
  c5_st.site = &c5_wk_emlrtRSI;
  c5_array_boolean_T_2D_SetSize(chartInstance, &c5_st, &c5_tile,
    &c5_ed_emlrtRTEI, 1, (int32_T)c5_b_varargin_2);
  c5_loop_ub = (int32_T)c5_b_varargin_2 - 1;
  for (c5_i = 0; c5_i <= c5_loop_ub; c5_i++) {
    c5_tile.vector.data[c5_i] = false;
  }

  c5_outsize[0] = 1;
  c5_outsize[1] = c5_tile.size[1];
  if (!((real_T)c5_outsize[1] == (real_T)c5_tile.size[1])) {
    c5_g_y = NULL;
    sf_mex_assign(&c5_g_y, sf_mex_create("y", c5_cv7, 10, 0U, 1, 0U, 2, 1, 15),
                  false);
    sf_mex_call(c5_sp, &c5_u_emlrtMCI, "error", 0U, 1U, 14, c5_g_y);
  }

  c5_array_cell_wrap_51_2D_Construct(chartInstance, &c5_r);
  c5_st.site = &c5_kl_emlrtRSI;
  c5_array_cell_wrap_51_2D_SetSize(chartInstance, &c5_st, &c5_r,
    &c5_re_emlrtRTEI, c5_outsize[0], c5_outsize[1]);
  c5_st.site = &c5_kl_emlrtRSI;
  c5_array_cell_wrap_51_2D_SetSize(chartInstance, &c5_st, c5_b, &c5_se_emlrtRTEI,
    1, c5_r.size[1]);
  c5_array_cell_wrap_51_2D_Destructo(chartInstance, &c5_r);
  if (c5_outsize[1] == 0) {
    c5_c_p = true;
  } else {
    c5_c_p = false;
  }

  if (!c5_c_p) {
    c5_ntilecols = c5_tile.size[1];
    c5_st.site = &c5_vh_emlrtRSI;
    c5_d_b = c5_ntilecols;
    c5_e_b = c5_d_b;
    if (c5_e_b < 1) {
      c5_overflow = false;
    } else {
      c5_overflow = (c5_e_b > 2147483646);
    }

    if (c5_overflow) {
      c5_b_st.site = &c5_v_emlrtRSI;
      c5_check_forloop_overflow_error(chartInstance, &c5_b_st);
    }

    for (c5_jtilecol = 0; c5_jtilecol < c5_ntilecols; c5_jtilecol++) {
      c5_b_jtilecol = c5_jtilecol;
      c5_ibtile = c5_b_jtilecol;
      c5_array_real_T_SetSize(chartInstance, c5_sp, &c5_b->vector.data
        [c5_b->size[0] * c5_ibtile].f1, &c5_te_emlrtRTEI, c5_c_a[0].f1.size[0]);
      c5_b_loop_ub = c5_c_a[0].f1.size[0] - 1;
      for (c5_i1 = 0; c5_i1 <= c5_b_loop_ub; c5_i1++) {
        c5_b->vector.data[c5_ibtile].f1.vector.data[c5_i1] = c5_c_a[0].
          f1.vector.data[c5_i1];
      }
    }
  }

  c5_array_boolean_T_2D_Destructor(chartInstance, &c5_tile);
}

static void c5_assertValidSizeArg(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, real_T c5_varargin_1)
{
  const mxArray *c5_b_y = NULL;
  const mxArray *c5_c_y = NULL;
  const mxArray *c5_d_y = NULL;
  const mxArray *c5_e_y = NULL;
  const mxArray *c5_f_y = NULL;
  const mxArray *c5_y = NULL;
  real_T c5_arg;
  real_T c5_b_arg;
  real_T c5_b_varargin_1;
  real_T c5_b_x;
  real_T c5_n;
  int32_T c5_e_u;
  int32_T c5_f_u;
  boolean_T c5_b;
  boolean_T c5_b_b;
  boolean_T c5_b_p;
  boolean_T c5_p;
  (void)chartInstance;
  c5_arg = c5_varargin_1;
  if (c5_arg != c5_arg) {
    c5_p = false;
  } else {
    c5_b_x = c5_arg;
    c5_b = muDoubleScalarIsInf(c5_b_x);
    if (c5_b) {
      c5_p = false;
    } else {
      c5_p = true;
    }
  }

  if (c5_p) {
    c5_b_arg = c5_varargin_1;
    if (c5_b_arg > 2.147483647E+9) {
      c5_b_p = false;
    } else {
      c5_b_p = true;
    }

    if (c5_b_p) {
      c5_b_b = true;
    } else {
      c5_b_b = false;
    }
  } else {
    c5_b_b = false;
  }

  if (!c5_b_b) {
    c5_y = NULL;
    sf_mex_assign(&c5_y, sf_mex_create("y", c5_cv9, 10, 0U, 1, 0U, 2, 1, 28),
                  false);
    c5_b_y = NULL;
    sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_cv9, 10, 0U, 1, 0U, 2, 1, 28),
                  false);
    c5_e_u = MIN_int32_T;
    c5_c_y = NULL;
    sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_e_u, 6, 0U, 0, 0U, 0), false);
    c5_f_u = MAX_int32_T;
    c5_f_y = NULL;
    sf_mex_assign(&c5_f_y, sf_mex_create("y", &c5_f_u, 6, 0U, 0, 0U, 0), false);
    sf_mex_call(c5_sp, &c5_v_emlrtMCI, "error", 0U, 2U, 14, c5_y, 14,
                sf_mex_call(c5_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c5_sp, NULL, "message", 1U, 3U, 14, c5_b_y, 14, c5_c_y, 14, c5_f_y)));
  }

  c5_b_varargin_1 = c5_varargin_1;
  if (c5_b_varargin_1 <= 0.0) {
    c5_n = 0.0;
  } else {
    c5_n = c5_b_varargin_1;
  }

  if (!(c5_n <= 2.147483647E+9)) {
    c5_d_y = NULL;
    sf_mex_assign(&c5_d_y, sf_mex_create("y", c5_cv8, 10, 0U, 1, 0U, 2, 1, 21),
                  false);
    c5_e_y = NULL;
    sf_mex_assign(&c5_e_y, sf_mex_create("y", c5_cv8, 10, 0U, 1, 0U, 2, 1, 21),
                  false);
    sf_mex_call(c5_sp, &c5_w_emlrtMCI, "error", 0U, 2U, 14, c5_d_y, 14,
                sf_mex_call(c5_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c5_sp, NULL, "message", 1U, 1U, 14, c5_e_y)));
  }
}

static void c5_ComputeWeightedCentroid(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, real_T c5_I[19200],
  c5_coder_array_s_R6Og1x0kmqQXSF9Pw *c5_stats, c5_sHtk0WM4OMtyqkehwQYcq2
  c5_statsAlreadyComputed, c5_coder_array_s_R6Og1x0kmqQXSF9Pw *c5_b_stats,
  c5_sHtk0WM4OMtyqkehwQYcq2 *c5_b_statsAlreadyComputed)
{
  real_T c5_b_I[19200];
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_loop_ub;
  c5_array_s_R6Og1x0kmqQXSF9Pwa49FD_(chartInstance, c5_sp, c5_b_stats,
    &c5_ue_emlrtRTEI, c5_stats->size[0]);
  c5_loop_ub = c5_stats->size[0] - 1;
  for (c5_i = 0; c5_i <= c5_loop_ub; c5_i++) {
    c5_d_array_s_R6Og1x0kmqQXSF9Pwa49FD_(chartInstance, c5_sp,
      &c5_b_stats->vector.data[c5_i], &c5_stats->vector.data[c5_i],
      &c5_ue_emlrtRTEI);
  }

  *c5_b_statsAlreadyComputed = c5_statsAlreadyComputed;
  for (c5_i1 = 0; c5_i1 < 19200; c5_i1++) {
    c5_b_I[c5_i1] = c5_I[c5_i1];
  }

  c5_b_ComputeWeightedCentroid(chartInstance, c5_sp, c5_b_I, c5_b_stats,
    c5_b_statsAlreadyComputed);
}

static real_T c5_sum(SFc5_flightControlSystemInstanceStruct *chartInstance,
                     const emlrtStack *c5_sp, c5_coder_array_real_T *c5_b_x)
{
  static char_T c5_b_cv[36] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c', 'o',
    'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  emlrtStack c5_b_st;
  emlrtStack c5_c_st;
  emlrtStack c5_d_st;
  emlrtStack c5_e_st;
  emlrtStack c5_f_st;
  emlrtStack c5_st;
  const mxArray *c5_b_y = NULL;
  const mxArray *c5_c_y = NULL;
  real_T c5_b_s;
  real_T c5_y;
  int32_T c5_b_vlen;
  int32_T c5_c_a;
  int32_T c5_c_vlen;
  int32_T c5_d_vlen;
  int32_T c5_ib;
  int32_T c5_inb;
  int32_T c5_lidx;
  int32_T c5_nfb;
  int32_T c5_nleft;
  int32_T c5_vlen;
  boolean_T c5_b;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_c_st.prev = &c5_b_st;
  c5_c_st.tls = c5_b_st.tls;
  c5_d_st.prev = &c5_c_st;
  c5_d_st.tls = c5_c_st.tls;
  c5_e_st.prev = &c5_d_st;
  c5_e_st.tls = c5_d_st.tls;
  c5_f_st.prev = &c5_e_st;
  c5_f_st.tls = c5_e_st.tls;
  c5_st.site = &c5_eh_emlrtRSI;
  if ((c5_b_x->size[0] == 1) || ((real_T)c5_b_x->size[0] != 1.0)) {
    c5_b = true;
  } else {
    c5_b = false;
  }

  if (!c5_b) {
    c5_b_y = NULL;
    sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1, 36),
                  false);
    c5_c_y = NULL;
    sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1, 36),
                  false);
    sf_mex_call(&c5_st, &c5_bb_emlrtMCI, "error", 0U, 2U, 14, c5_b_y, 14,
                sf_mex_call(&c5_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c5_st, NULL, "message", 1U, 1U, 14, c5_c_y)));
  }

  c5_b_st.site = &c5_fh_emlrtRSI;
  c5_vlen = c5_b_x->size[0];
  c5_c_st.site = &c5_gh_emlrtRSI;
  c5_b_vlen = c5_vlen;
  if ((c5_b_x->size[0] == 0) || (c5_b_vlen == 0)) {
    c5_y = 0.0;
  } else {
    c5_d_st.site = &c5_hh_emlrtRSI;
    c5_c_vlen = c5_b_vlen;
    c5_e_st.site = &c5_ih_emlrtRSI;
    c5_d_vlen = c5_c_vlen;
    if (c5_d_vlen < 4096) {
      c5_f_st.site = &c5_jh_emlrtRSI;
      c5_y = c5_c_sumColumnB(chartInstance, &c5_f_st, c5_b_x, c5_d_vlen);
    } else {
      c5_c_a = c5_d_vlen;
      c5_nfb = (int32_T)((uint32_T)c5_c_a >> 12);
      c5_inb = c5_nfb << 12;
      c5_lidx = c5_inb;
      c5_nleft = c5_d_vlen - c5_inb;
      c5_b_s = c5_b_sumColumnB4(chartInstance, c5_b_x, 1);
      for (c5_ib = 2; c5_ib <= c5_nfb; c5_ib++) {
        c5_b_s += c5_b_sumColumnB4(chartInstance, c5_b_x, 1 + ((c5_ib - 1) << 12));
      }

      if (c5_nleft > 0) {
        c5_f_st.site = &c5_kh_emlrtRSI;
        c5_b_s += c5_d_sumColumnB(chartInstance, &c5_f_st, c5_b_x, c5_nleft,
          c5_lidx + 1);
      }

      c5_y = c5_b_s;
    }
  }

  return c5_y;
}

static real_T c5_c_sumColumnB(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_real_T *c5_b_x,
  int32_T c5_vlen)
{
  emlrtStack c5_b_st;
  emlrtStack c5_c_st;
  emlrtStack c5_st;
  real_T c5_b_y;
  real_T c5_c_y;
  real_T c5_y;
  int32_T c5_b;
  int32_T c5_b_b;
  int32_T c5_b_k;
  int32_T c5_b_vlen;
  int32_T c5_b_vstart;
  int32_T c5_c_a;
  int32_T c5_c_b;
  int32_T c5_c_k;
  int32_T c5_c_vlen;
  int32_T c5_d_b;
  int32_T c5_d_k;
  int32_T c5_e_k;
  int32_T c5_f_k;
  int32_T c5_g_k;
  int32_T c5_h_k;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i2;
  int32_T c5_i_k;
  int32_T c5_inb;
  int32_T c5_k;
  int32_T c5_lidx;
  int32_T c5_nfb;
  int32_T c5_nleft;
  int32_T c5_vstart;
  boolean_T c5_b_overflow;
  boolean_T c5_overflow;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_c_st.prev = &c5_b_st;
  c5_c_st.tls = c5_b_st.tls;
  if (c5_vlen <= 1024) {
    c5_st.site = &c5_lh_emlrtRSI;
    c5_b_vlen = c5_vlen - 1;
    c5_y = c5_b_x->vector.data[0];
    c5_i = c5_b_vlen;
    c5_b_st.site = &c5_nh_emlrtRSI;
    c5_b = c5_i;
    c5_b_b = c5_b;
    if (c5_b_b < 1) {
      c5_overflow = false;
    } else {
      c5_overflow = (c5_b_b > 2147483646);
    }

    if (c5_overflow) {
      c5_c_st.site = &c5_v_emlrtRSI;
      c5_check_forloop_overflow_error(chartInstance, &c5_c_st);
    }

    c5_i1 = (uint16_T)c5_i - 1;
    for (c5_f_k = 0; c5_f_k <= c5_i1; c5_f_k++) {
      c5_g_k = c5_f_k;
      c5_y += c5_b_x->vector.data[c5_g_k + 1];
    }
  } else {
    c5_c_a = c5_vlen;
    c5_nfb = (int32_T)((uint32_T)c5_c_a >> 10);
    c5_inb = c5_nfb << 10;
    c5_y = c5_b_x->vector.data[0];
    for (c5_k = 0; c5_k < 1023; c5_k++) {
      c5_c_k = c5_k;
      c5_y += c5_b_x->vector.data[c5_c_k + 1];
    }

    for (c5_b_k = 2; c5_b_k <= c5_nfb; c5_b_k++) {
      c5_vstart = (c5_b_k - 1) << 10;
      c5_b_y = c5_b_x->vector.data[c5_vstart];
      for (c5_d_k = 0; c5_d_k < 1023; c5_d_k++) {
        c5_e_k = c5_d_k;
        c5_b_y += c5_b_x->vector.data[(c5_vstart + c5_e_k) + 1];
      }

      c5_y += c5_b_y;
    }

    if (c5_vlen > c5_inb) {
      c5_nleft = c5_vlen - c5_inb;
      c5_lidx = c5_inb;
      c5_st.site = &c5_mh_emlrtRSI;
      c5_c_vlen = c5_nleft - 1;
      c5_b_vstart = c5_lidx;
      c5_c_y = c5_b_x->vector.data[c5_b_vstart];
      c5_i2 = c5_c_vlen;
      c5_b_st.site = &c5_nh_emlrtRSI;
      c5_c_b = c5_i2;
      c5_d_b = c5_c_b;
      if (c5_d_b < 1) {
        c5_b_overflow = false;
      } else {
        c5_b_overflow = (c5_d_b > 2147483646);
      }

      if (c5_b_overflow) {
        c5_c_st.site = &c5_v_emlrtRSI;
        c5_check_forloop_overflow_error(chartInstance, &c5_c_st);
      }

      for (c5_h_k = 0; c5_h_k < c5_i2; c5_h_k++) {
        c5_i_k = c5_h_k;
        c5_c_y += c5_b_x->vector.data[(c5_b_vstart + c5_i_k) + 1];
      }

      c5_y += c5_c_y;
    }
  }

  return c5_y;
}

static real_T c5_b_sumColumnB4(SFc5_flightControlSystemInstanceStruct
  *chartInstance, c5_coder_array_real_T *c5_b_x, int32_T c5_vstart)
{
  real_T c5_psum1;
  real_T c5_psum2;
  real_T c5_psum3;
  real_T c5_psum4;
  int32_T c5_b_k;
  int32_T c5_i2;
  int32_T c5_i3;
  int32_T c5_i4;
  int32_T c5_k;
  (void)chartInstance;
  c5_i2 = c5_vstart + 1023;
  c5_i3 = c5_vstart + 2047;
  c5_i4 = c5_vstart + 3071;
  c5_psum1 = c5_b_x->vector.data[c5_vstart - 1];
  c5_psum2 = c5_b_x->vector.data[c5_i2];
  c5_psum3 = c5_b_x->vector.data[c5_i3];
  c5_psum4 = c5_b_x->vector.data[c5_i4];
  for (c5_k = 0; c5_k < 1023; c5_k++) {
    c5_b_k = c5_k + 1;
    c5_psum1 += c5_b_x->vector.data[(c5_vstart + c5_b_k) - 1];
    c5_psum2 += c5_b_x->vector.data[c5_i2 + c5_b_k];
    c5_psum3 += c5_b_x->vector.data[c5_i3 + c5_b_k];
    c5_psum4 += c5_b_x->vector.data[c5_i4 + c5_b_k];
  }

  return (c5_psum1 + c5_psum2) + (c5_psum3 + c5_psum4);
}

static real_T c5_d_sumColumnB(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_real_T *c5_b_x,
  int32_T c5_vlen, int32_T c5_vstart)
{
  emlrtStack c5_b_st;
  emlrtStack c5_c_st;
  emlrtStack c5_st;
  real_T c5_b_y;
  real_T c5_c_y;
  real_T c5_y;
  int32_T c5_b;
  int32_T c5_b_b;
  int32_T c5_b_k;
  int32_T c5_b_vlen;
  int32_T c5_b_vstart;
  int32_T c5_c_a;
  int32_T c5_c_b;
  int32_T c5_c_k;
  int32_T c5_c_vlen;
  int32_T c5_c_vstart;
  int32_T c5_d_b;
  int32_T c5_d_k;
  int32_T c5_d_vstart;
  int32_T c5_e_k;
  int32_T c5_e_vstart;
  int32_T c5_f_k;
  int32_T c5_g_k;
  int32_T c5_h_k;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i_k;
  int32_T c5_inb;
  int32_T c5_k;
  int32_T c5_lidx;
  int32_T c5_nfb;
  int32_T c5_nleft;
  boolean_T c5_b_overflow;
  boolean_T c5_overflow;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_c_st.prev = &c5_b_st;
  c5_c_st.tls = c5_b_st.tls;
  if (c5_vlen <= 1024) {
    c5_st.site = &c5_lh_emlrtRSI;
    c5_b_vlen = c5_vlen - 1;
    c5_b_vstart = c5_vstart - 1;
    c5_y = c5_b_x->vector.data[c5_b_vstart];
    c5_i = c5_b_vlen;
    c5_b_st.site = &c5_nh_emlrtRSI;
    c5_b = c5_i;
    c5_b_b = c5_b;
    if (c5_b_b < 1) {
      c5_overflow = false;
    } else {
      c5_overflow = (c5_b_b > 2147483646);
    }

    if (c5_overflow) {
      c5_c_st.site = &c5_v_emlrtRSI;
      c5_check_forloop_overflow_error(chartInstance, &c5_c_st);
    }

    for (c5_f_k = 0; c5_f_k < c5_i; c5_f_k++) {
      c5_g_k = c5_f_k;
      c5_y += c5_b_x->vector.data[(c5_b_vstart + c5_g_k) + 1];
    }
  } else {
    c5_c_a = c5_vlen;
    c5_nfb = (int32_T)((uint32_T)c5_c_a >> 10);
    c5_inb = c5_nfb << 10;
    c5_c_vstart = c5_vstart - 1;
    c5_y = c5_b_x->vector.data[c5_c_vstart];
    for (c5_k = 0; c5_k < 1023; c5_k++) {
      c5_c_k = c5_k;
      c5_y += c5_b_x->vector.data[(c5_c_vstart + c5_c_k) + 1];
    }

    for (c5_b_k = 2; c5_b_k <= c5_nfb; c5_b_k++) {
      c5_d_vstart = (c5_vstart + ((c5_b_k - 1) << 10)) - 1;
      c5_b_y = c5_b_x->vector.data[c5_d_vstart];
      for (c5_d_k = 0; c5_d_k < 1023; c5_d_k++) {
        c5_e_k = c5_d_k;
        c5_b_y += c5_b_x->vector.data[(c5_d_vstart + c5_e_k) + 1];
      }

      c5_y += c5_b_y;
    }

    if (c5_vlen > c5_inb) {
      c5_nleft = c5_vlen - c5_inb;
      c5_lidx = c5_vstart + c5_inb;
      c5_st.site = &c5_mh_emlrtRSI;
      c5_c_vlen = c5_nleft - 1;
      c5_e_vstart = c5_lidx - 1;
      c5_c_y = c5_b_x->vector.data[c5_e_vstart];
      c5_i1 = c5_c_vlen;
      c5_b_st.site = &c5_nh_emlrtRSI;
      c5_c_b = c5_i1;
      c5_d_b = c5_c_b;
      if (c5_d_b < 1) {
        c5_b_overflow = false;
      } else {
        c5_b_overflow = (c5_d_b > 2147483646);
      }

      if (c5_b_overflow) {
        c5_c_st.site = &c5_v_emlrtRSI;
        c5_check_forloop_overflow_error(chartInstance, &c5_c_st);
      }

      for (c5_h_k = 0; c5_h_k < c5_i1; c5_h_k++) {
        c5_i_k = c5_h_k;
        c5_c_y += c5_b_x->vector.data[(c5_e_vstart + c5_i_k) + 1];
      }

      c5_y += c5_c_y;
    }
  }

  return c5_y;
}

static void c5_round(SFc5_flightControlSystemInstanceStruct *chartInstance,
                     const emlrtStack *c5_sp, c5_coder_array_real_T *c5_b_x,
                     c5_coder_array_real_T *c5_y)
{
  emlrtStack c5_b_st;
  emlrtStack c5_c_st;
  emlrtStack c5_st;
  real_T c5_c_x;
  real_T c5_d_x;
  int32_T c5_b;
  int32_T c5_b_b;
  int32_T c5_b_k;
  int32_T c5_i;
  int32_T c5_k;
  int32_T c5_loop_ub;
  int32_T c5_nx;
  boolean_T c5_overflow;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_st.site = &c5_pi_emlrtRSI;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_c_st.prev = &c5_b_st;
  c5_c_st.tls = c5_b_st.tls;
  c5_array_real_T_SetSize(chartInstance, &c5_st, c5_y, &c5_ve_emlrtRTEI,
    c5_b_x->size[0]);
  c5_loop_ub = c5_b_x->size[0] - 1;
  for (c5_i = 0; c5_i <= c5_loop_ub; c5_i++) {
    c5_y->vector.data[c5_i] = c5_b_x->vector.data[c5_i];
  }

  c5_nx = c5_y->size[0];
  c5_b_st.site = &c5_ff_emlrtRSI;
  c5_b = c5_nx;
  c5_b_b = c5_b;
  if (c5_b_b < 1) {
    c5_overflow = false;
  } else {
    c5_overflow = (c5_b_b > 2147483646);
  }

  if (c5_overflow) {
    c5_c_st.site = &c5_v_emlrtRSI;
    c5_check_forloop_overflow_error(chartInstance, &c5_c_st);
  }

  for (c5_k = 0; c5_k < c5_nx; c5_k++) {
    c5_b_k = c5_k;
    c5_c_x = c5_y->vector.data[c5_b_k];
    c5_d_x = c5_c_x;
    c5_d_x = muDoubleScalarRound(c5_d_x);
    c5_y->vector.data[c5_b_k] = c5_d_x;
  }
}

static void c5_sort(SFc5_flightControlSystemInstanceStruct *chartInstance, const
                    emlrtStack *c5_sp, c5_coder_array_real_T_2D *c5_b_x,
                    c5_coder_array_real_T_2D *c5_c_x, c5_coder_array_int32_T_2D *
                    c5_idx)
{
  int32_T c5_i;
  int32_T c5_loop_ub;
  c5_array_real_T_2D_SetSize(chartInstance, c5_sp, c5_c_x, &c5_we_emlrtRTEI,
    c5_b_x->size[0], 1);
  c5_loop_ub = c5_b_x->size[0] - 1;
  for (c5_i = 0; c5_i <= c5_loop_ub; c5_i++) {
    c5_c_x->vector.data[c5_i] = c5_b_x->vector.data[c5_i];
  }

  c5_b_sort(chartInstance, c5_sp, c5_c_x, c5_idx);
}

static void c5_merge_pow2_block(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_int32_T_2D *c5_idx,
  c5_coder_array_real_T_2D *c5_b_x, int32_T c5_offset, c5_coder_array_int32_T_2D
  *c5_b_idx, c5_coder_array_real_T_2D *c5_c_x)
{
  int32_T c5_b_loop_ub;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_loop_ub;
  c5_array_int32_T_2D_SetSize(chartInstance, c5_sp, c5_b_idx, &c5_xe_emlrtRTEI,
    c5_idx->size[0], 1);
  c5_loop_ub = c5_idx->size[0] - 1;
  for (c5_i = 0; c5_i <= c5_loop_ub; c5_i++) {
    c5_b_idx->vector.data[c5_i] = c5_idx->vector.data[c5_i];
  }

  c5_array_real_T_2D_SetSize(chartInstance, c5_sp, c5_c_x, &c5_xe_emlrtRTEI,
    c5_b_x->size[0], 1);
  c5_b_loop_ub = c5_b_x->size[0] - 1;
  for (c5_i1 = 0; c5_i1 <= c5_b_loop_ub; c5_i1++) {
    c5_c_x->vector.data[c5_i1] = c5_b_x->vector.data[c5_i1];
  }

  c5_b_merge_pow2_block(chartInstance, c5_sp, c5_b_idx, c5_c_x, c5_offset);
}

static void c5_merge_block(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, c5_coder_array_int32_T_2D *c5_idx,
  c5_coder_array_real_T_2D *c5_b_x, int32_T c5_offset, int32_T c5_n, int32_T
  c5_preSortLevel, c5_coder_array_int32_T *c5_iwork, c5_coder_array_real_T
  *c5_xwork, c5_coder_array_int32_T_2D *c5_b_idx, c5_coder_array_real_T_2D
  *c5_c_x, c5_coder_array_int32_T *c5_b_iwork, c5_coder_array_real_T *c5_b_xwork)
{
  int32_T c5_b_loop_ub;
  int32_T c5_c_loop_ub;
  int32_T c5_d_loop_ub;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i2;
  int32_T c5_i3;
  int32_T c5_loop_ub;
  c5_array_int32_T_2D_SetSize(chartInstance, c5_sp, c5_b_idx, &c5_ye_emlrtRTEI,
    c5_idx->size[0], 1);
  c5_loop_ub = c5_idx->size[0] - 1;
  for (c5_i = 0; c5_i <= c5_loop_ub; c5_i++) {
    c5_b_idx->vector.data[c5_i] = c5_idx->vector.data[c5_i];
  }

  c5_array_real_T_2D_SetSize(chartInstance, c5_sp, c5_c_x, &c5_ye_emlrtRTEI,
    c5_b_x->size[0], 1);
  c5_b_loop_ub = c5_b_x->size[0] - 1;
  for (c5_i1 = 0; c5_i1 <= c5_b_loop_ub; c5_i1++) {
    c5_c_x->vector.data[c5_i1] = c5_b_x->vector.data[c5_i1];
  }

  c5_array_int32_T_SetSize(chartInstance, c5_sp, c5_b_iwork, &c5_ye_emlrtRTEI,
    c5_iwork->size[0]);
  c5_c_loop_ub = c5_iwork->size[0] - 1;
  for (c5_i2 = 0; c5_i2 <= c5_c_loop_ub; c5_i2++) {
    c5_b_iwork->vector.data[c5_i2] = c5_iwork->vector.data[c5_i2];
  }

  c5_array_real_T_SetSize(chartInstance, c5_sp, c5_b_xwork, &c5_ye_emlrtRTEI,
    c5_xwork->size[0]);
  c5_d_loop_ub = c5_xwork->size[0] - 1;
  for (c5_i3 = 0; c5_i3 <= c5_d_loop_ub; c5_i3++) {
    c5_b_xwork->vector.data[c5_i3] = c5_xwork->vector.data[c5_i3];
  }

  c5_b_merge_block(chartInstance, c5_sp, c5_b_idx, c5_c_x, c5_offset, c5_n,
                   c5_preSortLevel, c5_b_iwork, c5_b_xwork);
}

static void c5_merge(SFc5_flightControlSystemInstanceStruct *chartInstance,
                     const emlrtStack *c5_sp, c5_coder_array_int32_T_2D *c5_idx,
                     c5_coder_array_real_T_2D *c5_b_x, int32_T c5_offset,
                     int32_T c5_np, int32_T c5_nq, c5_coder_array_int32_T
                     *c5_iwork, c5_coder_array_real_T *c5_xwork,
                     c5_coder_array_int32_T_2D *c5_b_idx,
                     c5_coder_array_real_T_2D *c5_c_x, c5_coder_array_int32_T
                     *c5_b_iwork, c5_coder_array_real_T *c5_b_xwork)
{
  int32_T c5_b_loop_ub;
  int32_T c5_c_loop_ub;
  int32_T c5_d_loop_ub;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i2;
  int32_T c5_i3;
  int32_T c5_loop_ub;
  c5_array_int32_T_2D_SetSize(chartInstance, c5_sp, c5_b_idx, &c5_af_emlrtRTEI,
    c5_idx->size[0], 1);
  c5_loop_ub = c5_idx->size[0] - 1;
  for (c5_i = 0; c5_i <= c5_loop_ub; c5_i++) {
    c5_b_idx->vector.data[c5_i] = c5_idx->vector.data[c5_i];
  }

  c5_array_real_T_2D_SetSize(chartInstance, c5_sp, c5_c_x, &c5_af_emlrtRTEI,
    c5_b_x->size[0], 1);
  c5_b_loop_ub = c5_b_x->size[0] - 1;
  for (c5_i1 = 0; c5_i1 <= c5_b_loop_ub; c5_i1++) {
    c5_c_x->vector.data[c5_i1] = c5_b_x->vector.data[c5_i1];
  }

  c5_array_int32_T_SetSize(chartInstance, c5_sp, c5_b_iwork, &c5_af_emlrtRTEI,
    c5_iwork->size[0]);
  c5_c_loop_ub = c5_iwork->size[0] - 1;
  for (c5_i2 = 0; c5_i2 <= c5_c_loop_ub; c5_i2++) {
    c5_b_iwork->vector.data[c5_i2] = c5_iwork->vector.data[c5_i2];
  }

  c5_array_real_T_SetSize(chartInstance, c5_sp, c5_b_xwork, &c5_af_emlrtRTEI,
    c5_xwork->size[0]);
  c5_d_loop_ub = c5_xwork->size[0] - 1;
  for (c5_i3 = 0; c5_i3 <= c5_d_loop_ub; c5_i3++) {
    c5_b_xwork->vector.data[c5_i3] = c5_xwork->vector.data[c5_i3];
  }

  c5_b_merge(chartInstance, c5_sp, c5_b_idx, c5_c_x, c5_offset, c5_np, c5_nq,
             c5_b_iwork, c5_b_xwork);
}

static void c5_chradiiphcode(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_real_T_2D
  *c5_varargin_1, creal_T c5_b_varargin_2[19200], real_T c5_varargin_3_data[],
  c5_coder_array_real_T *c5_r_estimated)
{
  static char_T c5_b_cv1[48] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't',
    't', 'r', 'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e',
    'd', 'P', 'o', 's', 'i', 't', 'i', 'v', 'e' };

  static char_T c5_b_cv4[48] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't',
    't', 'r', 'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e',
    'd', 'N', 'o', 'n', 'e', 'm', 'p', 't', 'y' };

  static char_T c5_b_cv7[48] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't',
    't', 'r', 'i', 'b', 'u', 't', 'e', 's', 'i', 'n', 'c', 'o', 'r', 'r', 'e',
    'c', 't', 'N', 'u', 'm', 'c', 'o', 'l', 's' };

  static char_T c5_cv15[38] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'i', 'm', 'f',
    'i', 'n', 'd', 'c', 'i', 'r', 'c', 'l', 'e', 's', ':', 'o', 'u', 't', 'O',
    'f', 'B', 'o', 'u', 'n', 'd', 'C', 'e', 'n', 't', 'e', 'r', 's' };

  static char_T c5_b_cv[37] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'c', 'h', 'r',
    'a', 'd', 'i', 'i', 'p', 'h', 'c', 'o', 'd', 'e', ':', 'e', 'x', 'p', 'e',
    'c', 't', 'e', 'd', 'P', 'o', 's', 'i', 't', 'i', 'v', 'e' };

  static char_T c5_b_cv3[37] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'c', 'h',
    'r', 'a', 'd', 'i', 'i', 'p', 'h', 'c', 'o', 'd', 'e', ':', 'e', 'x', 'p',
    'e', 'c', 't', 'e', 'd', 'N', 'o', 'n', 'e', 'm', 'p', 't', 'y' };

  static char_T c5_b_cv5[37] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'c', 'h',
    'r', 'a', 'd', 'i', 'i', 'p', 'h', 'c', 'o', 'd', 'e', ':', 'i', 'n', 'c',
    'o', 'r', 'r', 'e', 'c', 't', 'N', 'u', 'm', 'c', 'o', 'l', 's' };

  static char_T c5_cv11[36] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'c', 'h', 'r',
    'a', 'd', 'i', 'i', 'p', 'h', 'c', 'o', 'd', 'e', ':', 'e', 'x', 'p', 'e',
    'c', 't', 'e', 'd', 'I', 'n', 't', 'e', 'g', 'e', 'r' };

  static char_T c5_b_cv9[35] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'c', 'h',
    'r', 'a', 'd', 'i', 'i', 'p', 'h', 'c', 'o', 'd', 'e', ':', 'e', 'x', 'p',
    'e', 'c', 't', 'e', 'd', 'N', 'o', 'n', 'N', 'a', 'N' };

  static char_T c5_cv13[35] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'c', 'h', 'r',
    'a', 'd', 'i', 'i', 'p', 'h', 'c', 'o', 'd', 'e', ':', 'e', 'x', 'p', 'e',
    'c', 't', 'e', 'd', 'F', 'i', 'n', 'i', 't', 'e' };

  static char_T c5_b_cv2[24] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm',
    'b', 'e', 'r', ' ', '1', ',', ' ', 'c', 'e', 'n', 't', 'e', 'r', 's', ',' };

  static char_T c5_b_cv6[24] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm',
    'b', 'e', 'r', ' ', '1', ',', ' ', 'c', 'e', 'n', 't', 'e', 'r', 's', ',' };

  static char_T c5_b_cv8[24] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm',
    'b', 'e', 'r', ' ', '1', ',', ' ', 'c', 'e', 'n', 't', 'e', 'r', 's', ',' };

  static char_T c5_b_cv10[18] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm',
    'b', 'e', 'r', ' ', '3', ',', ' ', 'R', ',' };

  static char_T c5_cv12[18] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm', 'b',
    'e', 'r', ' ', '3', ',', ' ', 'R', ',' };

  static char_T c5_cv14[18] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm', 'b',
    'e', 'r', ' ', '3', ',', ' ', 'R', ',' };

  c5_coder_array_boolean_T c5_b_varargin_1;
  c5_coder_array_boolean_T c5_c_varargin_1;
  c5_coder_array_creal_T c5_h_x;
  c5_coder_array_int32_T c5_r;
  c5_coder_array_real_T c5_c_varargin_2;
  c5_coder_array_real_T c5_d_varargin_1;
  c5_coder_array_real_T c5_e_varargin_1;
  c5_coder_array_real_T c5_ndx;
  emlrtStack c5_b_st;
  emlrtStack c5_c_st;
  emlrtStack c5_d_st;
  emlrtStack c5_st;
  const mxArray *c5_b_y = NULL;
  const mxArray *c5_c_y = NULL;
  const mxArray *c5_d_y = NULL;
  const mxArray *c5_e_y = NULL;
  const mxArray *c5_f_y = NULL;
  const mxArray *c5_g_y = NULL;
  const mxArray *c5_h_y = NULL;
  const mxArray *c5_i_y = NULL;
  const mxArray *c5_j_y = NULL;
  const mxArray *c5_k_y = NULL;
  const mxArray *c5_l_y = NULL;
  const mxArray *c5_m_y = NULL;
  const mxArray *c5_n_y = NULL;
  const mxArray *c5_o_y = NULL;
  const mxArray *c5_p_y = NULL;
  const mxArray *c5_q_y = NULL;
  const mxArray *c5_r_y = NULL;
  const mxArray *c5_s_y = NULL;
  const mxArray *c5_t_y = NULL;
  const mxArray *c5_u_y = NULL;
  const mxArray *c5_v_y = NULL;
  const mxArray *c5_w_y = NULL;
  const mxArray *c5_y = NULL;
  creal_T c5_i_x;
  real_T c5_tmp_data[81];
  real_T c5_b_dv[2];
  real_T c5_lnR_data[2];
  real_T c5_b_k;
  real_T c5_b_x;
  real_T c5_c_x;
  real_T c5_d;
  real_T c5_d_k;
  real_T c5_d_x;
  real_T c5_e_u;
  real_T c5_e_x;
  real_T c5_f_k;
  real_T c5_f_x;
  real_T c5_g_x;
  real_T c5_h_b;
  real_T c5_j_x;
  real_T c5_k_x;
  real_T c5_l_x;
  real_T c5_lnR;
  real_T c5_x_y;
  real_T c5_y_y;
  int32_T c5_tmp_size[2];
  int32_T c5_b_loop_ub;
  int32_T c5_b_nx;
  int32_T c5_c_k;
  int32_T c5_c_loop_ub;
  int32_T c5_d_loop_ub;
  int32_T c5_e_k;
  int32_T c5_e_loop_ub;
  int32_T c5_f_b;
  int32_T c5_f_loop_ub;
  int32_T c5_g_b;
  int32_T c5_g_k;
  int32_T c5_g_loop_ub;
  int32_T c5_h_k;
  int32_T c5_h_loop_ub;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i10;
  int32_T c5_i11;
  int32_T c5_i12;
  int32_T c5_i13;
  int32_T c5_i14;
  int32_T c5_i15;
  int32_T c5_i16;
  int32_T c5_i17;
  int32_T c5_i18;
  int32_T c5_i19;
  int32_T c5_i2;
  int32_T c5_i20;
  int32_T c5_i21;
  int32_T c5_i3;
  int32_T c5_i4;
  int32_T c5_i5;
  int32_T c5_i6;
  int32_T c5_i7;
  int32_T c5_i8;
  int32_T c5_i9;
  int32_T c5_i_b;
  int32_T c5_i_k;
  int32_T c5_i_loop_ub;
  int32_T c5_j_b;
  int32_T c5_j_k;
  int32_T c5_j_loop_ub;
  int32_T c5_k;
  int32_T c5_loop_ub;
  int32_T c5_nx;
  boolean_T c5_b;
  boolean_T c5_b1;
  boolean_T c5_b2;
  boolean_T c5_b3;
  boolean_T c5_b4;
  boolean_T c5_b5;
  boolean_T c5_b6;
  boolean_T c5_b7;
  boolean_T c5_b8;
  boolean_T c5_b_b;
  boolean_T c5_b_overflow;
  boolean_T c5_b_p;
  boolean_T c5_c_b;
  boolean_T c5_c_p;
  boolean_T c5_d_b;
  boolean_T c5_d_p;
  boolean_T c5_e_b;
  boolean_T c5_e_p;
  boolean_T c5_exitg1;
  boolean_T c5_overflow;
  boolean_T c5_p;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_c_st.prev = &c5_b_st;
  c5_c_st.tls = c5_b_st.tls;
  c5_d_st.prev = &c5_c_st;
  c5_d_st.tls = c5_c_st.tls;
  c5_st.site = &c5_uj_emlrtRSI;
  c5_b_st.site = &c5_yj_emlrtRSI;
  c5_c_st.site = &c5_ck_emlrtRSI;
  c5_d_st.site = &c5_ad_emlrtRSI;
  c5_p = true;
  c5_d = (real_T)(c5_varargin_1->size[0] * c5_varargin_1->size[1]);
  c5_i = (int32_T)c5_d - 1;
  c5_k = 0;
  c5_exitg1 = false;
  while ((!c5_exitg1) && (c5_k <= c5_i)) {
    c5_b_k = (real_T)c5_k + 1.0;
    c5_b_x = c5_varargin_1->vector.data[(int32_T)c5_b_k - 1];
    c5_b_p = !(c5_b_x <= 0.0);
    if (c5_b_p) {
      c5_k++;
    } else {
      c5_p = false;
      c5_exitg1 = true;
    }
  }

  if (c5_p) {
    c5_b = true;
  } else {
    c5_b = false;
  }

  if (!c5_b) {
    c5_y = NULL;
    sf_mex_assign(&c5_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1, 37),
                  false);
    c5_b_y = NULL;
    sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_b_cv1, 10, 0U, 1, 0U, 2, 1, 48),
                  false);
    c5_c_y = NULL;
    sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_b_cv2, 10, 0U, 1, 0U, 2, 1, 24),
                  false);
    sf_mex_call(&c5_d_st, &c5_m_emlrtMCI, "error", 0U, 2U, 14, c5_y, 14,
                sf_mex_call(&c5_d_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c5_d_st, NULL, "message", 1U, 2U, 14, c5_b_y, 14, c5_c_y)));
  }

  c5_d_st.site = &c5_ad_emlrtRSI;
  c5_b1 = (c5_varargin_1->size[0] == 0);
  c5_b2 = (c5_varargin_1->size[1] == 0);
  if ((!!c5_b1) || (!!c5_b2)) {
    c5_d_y = NULL;
    sf_mex_assign(&c5_d_y, sf_mex_create("y", c5_b_cv3, 10, 0U, 1, 0U, 2, 1, 37),
                  false);
    c5_e_y = NULL;
    sf_mex_assign(&c5_e_y, sf_mex_create("y", c5_b_cv4, 10, 0U, 1, 0U, 2, 1, 48),
                  false);
    c5_g_y = NULL;
    sf_mex_assign(&c5_g_y, sf_mex_create("y", c5_b_cv6, 10, 0U, 1, 0U, 2, 1, 24),
                  false);
    sf_mex_call(&c5_d_st, &c5_fb_emlrtMCI, "error", 0U, 2U, 14, c5_d_y, 14,
                sf_mex_call(&c5_d_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c5_d_st, NULL, "message", 1U, 2U, 14, c5_e_y, 14, c5_g_y)));
  }

  c5_d_st.site = &c5_ad_emlrtRSI;
  if (!((real_T)c5_varargin_1->size[1] == 2.0)) {
    c5_f_y = NULL;
    sf_mex_assign(&c5_f_y, sf_mex_create("y", c5_b_cv5, 10, 0U, 1, 0U, 2, 1, 37),
                  false);
    c5_h_y = NULL;
    sf_mex_assign(&c5_h_y, sf_mex_create("y", c5_b_cv7, 10, 0U, 1, 0U, 2, 1, 48),
                  false);
    c5_i_y = NULL;
    sf_mex_assign(&c5_i_y, sf_mex_create("y", c5_b_cv8, 10, 0U, 1, 0U, 2, 1, 24),
                  false);
    c5_e_u = 2.0;
    c5_j_y = NULL;
    sf_mex_assign(&c5_j_y, sf_mex_create("y", &c5_e_u, 0, 0U, 0, 0U, 0), false);
    sf_mex_call(&c5_d_st, &c5_gb_emlrtMCI, "error", 0U, 2U, 14, c5_f_y, 14,
                sf_mex_call(&c5_d_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c5_d_st, NULL, "message", 1U, 3U, 14, c5_h_y, 14, c5_i_y, 14, c5_j_y)));
  }

  c5_b_st.site = &c5_ak_emlrtRSI;
  c5_c_st.site = &c5_dk_emlrtRSI;
  c5_d_st.site = &c5_ad_emlrtRSI;
  c5_c_p = true;
  c5_c_k = 0;
  c5_exitg1 = false;
  while ((!c5_exitg1) && (c5_c_k < 2)) {
    c5_d_k = (real_T)c5_c_k + 1.0;
    c5_c_x = c5_varargin_3_data[(int32_T)c5_d_k - 1];
    c5_d_x = c5_c_x;
    c5_b_b = muDoubleScalarIsNaN(c5_d_x);
    c5_d_p = !c5_b_b;
    if (c5_d_p) {
      c5_c_k++;
    } else {
      c5_c_p = false;
      c5_exitg1 = true;
    }
  }

  if (c5_c_p) {
    c5_b3 = true;
  } else {
    c5_b3 = false;
  }

  if (!c5_b3) {
    c5_k_y = NULL;
    sf_mex_assign(&c5_k_y, sf_mex_create("y", c5_b_cv9, 10, 0U, 1, 0U, 2, 1, 35),
                  false);
    c5_l_y = NULL;
    sf_mex_assign(&c5_l_y, sf_mex_create("y", c5_cv5, 10, 0U, 1, 0U, 2, 1, 46),
                  false);
    c5_m_y = NULL;
    sf_mex_assign(&c5_m_y, sf_mex_create("y", c5_b_cv10, 10, 0U, 1, 0U, 2, 1, 18),
                  false);
    sf_mex_call(&c5_d_st, &c5_l_emlrtMCI, "error", 0U, 2U, 14, c5_k_y, 14,
                sf_mex_call(&c5_d_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c5_d_st, NULL, "message", 1U, 2U, 14, c5_l_y, 14, c5_m_y)));
  }

  c5_d_st.site = &c5_ad_emlrtRSI;
  if (c5_all(chartInstance, c5_varargin_3_data)) {
    c5_b4 = true;
  } else {
    c5_b4 = false;
  }

  if (!c5_b4) {
    c5_n_y = NULL;
    sf_mex_assign(&c5_n_y, sf_mex_create("y", c5_cv11, 10, 0U, 1, 0U, 2, 1, 36),
                  false);
    c5_o_y = NULL;
    sf_mex_assign(&c5_o_y, sf_mex_create("y", c5_cv6, 10, 0U, 1, 0U, 2, 1, 47),
                  false);
    c5_p_y = NULL;
    sf_mex_assign(&c5_p_y, sf_mex_create("y", c5_cv12, 10, 0U, 1, 0U, 2, 1, 18),
                  false);
    sf_mex_call(&c5_d_st, &c5_k_emlrtMCI, "error", 0U, 2U, 14, c5_n_y, 14,
                sf_mex_call(&c5_d_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c5_d_st, NULL, "message", 1U, 2U, 14, c5_o_y, 14, c5_p_y)));
  }

  c5_d_st.site = &c5_ad_emlrtRSI;
  c5_d_st.site = &c5_ad_emlrtRSI;
  c5_e_p = true;
  c5_e_k = 0;
  c5_exitg1 = false;
  while ((!c5_exitg1) && (c5_e_k < 2)) {
    c5_f_k = (real_T)c5_e_k + 1.0;
    c5_e_x = c5_varargin_3_data[(int32_T)c5_f_k - 1];
    c5_f_x = c5_e_x;
    c5_c_b = muDoubleScalarIsInf(c5_f_x);
    c5_b6 = !c5_c_b;
    c5_g_x = c5_e_x;
    c5_d_b = muDoubleScalarIsNaN(c5_g_x);
    c5_b7 = !c5_d_b;
    c5_e_b = (c5_b6 && c5_b7);
    if (c5_e_b) {
      c5_e_k++;
    } else {
      c5_e_p = false;
      c5_exitg1 = true;
    }
  }

  if (c5_e_p) {
    c5_b5 = true;
  } else {
    c5_b5 = false;
  }

  if (!c5_b5) {
    c5_q_y = NULL;
    sf_mex_assign(&c5_q_y, sf_mex_create("y", c5_cv13, 10, 0U, 1, 0U, 2, 1, 35),
                  false);
    c5_s_y = NULL;
    sf_mex_assign(&c5_s_y, sf_mex_create("y", c5_cv2, 10, 0U, 1, 0U, 2, 1, 46),
                  false);
    c5_u_y = NULL;
    sf_mex_assign(&c5_u_y, sf_mex_create("y", c5_cv14, 10, 0U, 1, 0U, 2, 1, 18),
                  false);
    sf_mex_call(&c5_d_st, &c5_g_emlrtMCI, "error", 0U, 2U, 14, c5_q_y, 14,
                sf_mex_call(&c5_d_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c5_d_st, NULL, "message", 1U, 2U, 14, c5_s_y, 14, c5_u_y)));
  }

  if (c5_varargin_3_data[0] >= c5_varargin_3_data[1]) {
    c5_r_y = NULL;
    sf_mex_assign(&c5_r_y, sf_mex_create("y", c5_cv10, 10, 0U, 1, 0U, 2, 1, 39),
                  false);
    c5_t_y = NULL;
    sf_mex_assign(&c5_t_y, sf_mex_create("y", c5_cv10, 10, 0U, 1, 0U, 2, 1, 39),
                  false);
    sf_mex_call(&c5_b_st, &c5_hb_emlrtMCI, "error", 0U, 2U, 14, c5_r_y, 14,
                sf_mex_call(&c5_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c5_b_st, NULL, "message", 1U, 1U, 14, c5_t_y)));
  }

  c5_b_st.site = &c5_bk_emlrtRSI;
  c5_i1 = c5_varargin_1->size[1];
  c5_i2 = 1;
  if ((c5_i2 < 1) || (c5_i2 > c5_i1)) {
    emlrtDynamicBoundsCheckR2012b(c5_i2, 1, c5_i1, &c5_lf_emlrtBCI, &c5_b_st);
  }

  c5_array_boolean_T_Constructor(chartInstance, &c5_b_varargin_1);
  c5_array_boolean_T_SetSize(chartInstance, &c5_b_st, &c5_b_varargin_1,
    &c5_bf_emlrtRTEI, c5_varargin_1->size[0]);
  c5_loop_ub = c5_varargin_1->size[0] - 1;
  for (c5_i3 = 0; c5_i3 <= c5_loop_ub; c5_i3++) {
    c5_b_varargin_1.vector.data[c5_i3] = (c5_varargin_1->vector.data[c5_i3] <=
      160.0);
  }

  c5_array_boolean_T_Constructor(chartInstance, &c5_c_varargin_1);
  c5_c_st.site = &c5_ek_emlrtRSI;
  if (c5_b_all(chartInstance, &c5_c_st, &c5_b_varargin_1)) {
    c5_i4 = c5_varargin_1->size[1];
    c5_i5 = 2;
    if ((c5_i5 < 1) || (c5_i5 > c5_i4)) {
      emlrtDynamicBoundsCheckR2012b(c5_i5, 1, c5_i4, &c5_mf_emlrtBCI, &c5_b_st);
    }

    c5_array_boolean_T_SetSize(chartInstance, &c5_b_st, &c5_c_varargin_1,
      &c5_cf_emlrtRTEI, c5_varargin_1->size[0]);
    c5_b_loop_ub = c5_varargin_1->size[0] - 1;
    for (c5_i7 = 0; c5_i7 <= c5_b_loop_ub; c5_i7++) {
      c5_c_varargin_1.vector.data[c5_i7] = (c5_varargin_1->vector.data[c5_i7 +
        c5_varargin_1->size[0]] <= 120.0);
    }

    c5_c_st.site = &c5_fk_emlrtRSI;
    if (c5_b_all(chartInstance, &c5_c_st, &c5_c_varargin_1)) {
      c5_b8 = true;
    } else {
      c5_b8 = false;
    }
  } else {
    c5_b8 = false;
  }

  c5_array_boolean_T_Destructor(chartInstance, &c5_c_varargin_1);
  c5_array_boolean_T_Destructor(chartInstance, &c5_b_varargin_1);
  if (!c5_b8) {
    c5_v_y = NULL;
    sf_mex_assign(&c5_v_y, sf_mex_create("y", c5_cv15, 10, 0U, 1, 0U, 2, 1, 38),
                  false);
    c5_w_y = NULL;
    sf_mex_assign(&c5_w_y, sf_mex_create("y", c5_cv15, 10, 0U, 1, 0U, 2, 1, 38),
                  false);
    sf_mex_call(&c5_b_st, &c5_ib_emlrtMCI, "error", 0U, 2U, 14, c5_v_y, 14,
                sf_mex_call(&c5_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c5_b_st, NULL, "message", 1U, 1U, 14, c5_w_y)));
  }

  c5_i6 = c5_varargin_1->size[1];
  c5_i8 = 2;
  if ((c5_i8 < 1) || (c5_i8 > c5_i6)) {
    emlrtDynamicBoundsCheckR2012b(c5_i8, 1, c5_i6, &c5_jf_emlrtBCI,
      (emlrtConstCTX)c5_sp);
  }

  c5_i9 = c5_varargin_1->size[1];
  c5_i10 = 1;
  if ((c5_i10 < 1) || (c5_i10 > c5_i9)) {
    emlrtDynamicBoundsCheckR2012b(c5_i10, 1, c5_i9, &c5_kf_emlrtBCI,
      (emlrtConstCTX)c5_sp);
  }

  c5_array_real_T_Constructor(chartInstance, &c5_ndx);
  c5_st.site = &c5_vj_emlrtRSI;
  c5_array_real_T_Constructor(chartInstance, &c5_d_varargin_1);
  c5_b_st.site = &c5_vj_emlrtRSI;
  c5_array_real_T_SetSize(chartInstance, &c5_b_st, &c5_d_varargin_1,
    &c5_df_emlrtRTEI, c5_varargin_1->size[0]);
  c5_c_loop_ub = c5_varargin_1->size[0] - 1;
  for (c5_i11 = 0; c5_i11 <= c5_c_loop_ub; c5_i11++) {
    c5_d_varargin_1.vector.data[c5_i11] = c5_varargin_1->vector.data[c5_i11 +
      c5_varargin_1->size[0]];
  }

  c5_b_st.site = &c5_vj_emlrtRSI;
  c5_round(chartInstance, &c5_b_st, &c5_d_varargin_1, &c5_ndx);
  c5_array_real_T_Destructor(chartInstance, &c5_d_varargin_1);
  c5_array_real_T_Constructor(chartInstance, &c5_e_varargin_1);
  c5_b_st.site = &c5_vj_emlrtRSI;
  c5_array_real_T_SetSize(chartInstance, &c5_b_st, &c5_e_varargin_1,
    &c5_ef_emlrtRTEI, c5_varargin_1->size[0]);
  c5_d_loop_ub = c5_varargin_1->size[0] - 1;
  for (c5_i12 = 0; c5_i12 <= c5_d_loop_ub; c5_i12++) {
    c5_e_varargin_1.vector.data[c5_i12] = c5_varargin_1->vector.data[c5_i12];
  }

  c5_array_real_T_Constructor(chartInstance, &c5_c_varargin_2);
  c5_b_st.site = &c5_vj_emlrtRSI;
  c5_round(chartInstance, &c5_b_st, &c5_e_varargin_1, &c5_c_varargin_2);
  c5_array_real_T_Destructor(chartInstance, &c5_e_varargin_1);
  c5_array_int32_T_Constructor(chartInstance, &c5_r);
  c5_b_st.site = &c5_bf_emlrtRSI;
  c5_sub2ind(chartInstance, &c5_b_st, &c5_ndx, &c5_c_varargin_2, &c5_r);
  c5_array_real_T_Destructor(chartInstance, &c5_c_varargin_2);
  c5_array_real_T_SetSize(chartInstance, &c5_st, &c5_ndx, &c5_hb_emlrtRTEI,
    c5_r.size[0]);
  c5_e_loop_ub = c5_r.size[0] - 1;
  for (c5_i13 = 0; c5_i13 <= c5_e_loop_ub; c5_i13++) {
    c5_ndx.vector.data[c5_i13] = (real_T)c5_r.vector.data[c5_i13];
  }

  c5_array_int32_T_Destructor(chartInstance, &c5_r);
  c5_st.site = &c5_vj_emlrtRSI;
  c5_array_creal_T_Constructor(chartInstance, &c5_h_x);
  c5_b_st.site = &c5_vj_emlrtRSI;
  c5_array_creal_T_SetSize(chartInstance, &c5_b_st, &c5_h_x, &c5_ff_emlrtRTEI,
    c5_ndx.size[0]);
  c5_f_loop_ub = c5_ndx.size[0] - 1;
  for (c5_i14 = 0; c5_i14 <= c5_f_loop_ub; c5_i14++) {
    c5_i15 = (int32_T)c5_ndx.vector.data[c5_i14];
    if ((c5_i15 < 1) || (c5_i15 > 19200)) {
      emlrtDynamicBoundsCheckR2012b(c5_i15, 1, 19200, &c5_nf_emlrtBCI, &c5_st);
    }

    c5_h_x.vector.data[c5_i14].re = c5_b_varargin_2[c5_i15 - 1].re;
    c5_i16 = (int32_T)c5_ndx.vector.data[c5_i14];
    if ((c5_i16 < 1) || (c5_i16 > 19200)) {
      emlrtDynamicBoundsCheckR2012b(c5_i16, 1, 19200, &c5_nf_emlrtBCI, &c5_st);
    }

    c5_h_x.vector.data[c5_i14].im = c5_b_varargin_2[c5_i16 - 1].im;
  }

  c5_array_real_T_Destructor(chartInstance, &c5_ndx);
  c5_b_st.site = &c5_ik_emlrtRSI;
  c5_nx = c5_h_x.size[0];
  c5_b_dv[0] = (real_T)c5_h_x.size[0];
  c5_array_real_T_SetSize(chartInstance, &c5_b_st, c5_r_estimated,
    &c5_gf_emlrtRTEI, (int32_T)c5_b_dv[0]);
  c5_c_st.site = &c5_jk_emlrtRSI;
  c5_f_b = c5_nx;
  c5_g_b = c5_f_b;
  if (c5_g_b < 1) {
    c5_overflow = false;
  } else {
    c5_overflow = (c5_g_b > 2147483646);
  }

  if (c5_overflow) {
    c5_d_st.site = &c5_v_emlrtRSI;
    c5_check_forloop_overflow_error(chartInstance, &c5_d_st);
  }

  for (c5_g_k = 0; c5_g_k < c5_nx; c5_g_k++) {
    c5_h_k = c5_g_k;
    c5_i_x = c5_h_x.vector.data[c5_h_k];
    c5_x_y = c5_i_x.im;
    c5_j_x = c5_i_x.re;
    c5_y_y = muDoubleScalarAtan2(c5_x_y, c5_j_x);
    c5_r_estimated->vector.data[c5_h_k] = c5_y_y;
  }

  c5_array_creal_T_Destructor(chartInstance, &c5_h_x);
  c5_tmp_size[0] = 1;
  c5_tmp_size[1] = 2;
  c5_g_loop_ub = 1;
  for (c5_i17 = 0; c5_i17 <= c5_g_loop_ub; c5_i17++) {
    c5_tmp_data[c5_i17] = c5_varargin_3_data[c5_i17];
  }

  c5_st.site = &c5_wj_emlrtRSI;
  c5_b_log(chartInstance, &c5_st, c5_tmp_data, c5_tmp_size);
  for (c5_i18 = 0; c5_i18 < 2; c5_i18++) {
    c5_lnR_data[c5_i18] = c5_tmp_data[c5_i18];
  }

  c5_h_loop_ub = c5_r_estimated->size[0] - 1;
  for (c5_i19 = 0; c5_i19 <= c5_h_loop_ub; c5_i19++) {
    c5_r_estimated->vector.data[c5_i19] = (c5_r_estimated->vector.data[c5_i19] +
      3.1415926535897931) / 6.2831853071795862;
  }

  c5_h_b = c5_lnR_data[1] - c5_lnR_data[0];
  c5_i_loop_ub = c5_r_estimated->size[0] - 1;
  for (c5_i20 = 0; c5_i20 <= c5_i_loop_ub; c5_i20++) {
    c5_r_estimated->vector.data[c5_i20] *= c5_h_b;
  }

  c5_st.site = &c5_xj_emlrtRSI;
  c5_lnR = c5_lnR_data[0];
  c5_j_loop_ub = c5_r_estimated->size[0] - 1;
  for (c5_i21 = 0; c5_i21 <= c5_j_loop_ub; c5_i21++) {
    c5_r_estimated->vector.data[c5_i21] += c5_lnR;
  }

  c5_b_st.site = &c5_gf_emlrtRSI;
  c5_b_nx = c5_r_estimated->size[0];
  c5_c_st.site = &c5_ff_emlrtRSI;
  c5_i_b = c5_b_nx;
  c5_j_b = c5_i_b;
  if (c5_j_b < 1) {
    c5_b_overflow = false;
  } else {
    c5_b_overflow = (c5_j_b > 2147483646);
  }

  if (c5_b_overflow) {
    c5_d_st.site = &c5_v_emlrtRSI;
    c5_check_forloop_overflow_error(chartInstance, &c5_d_st);
  }

  for (c5_i_k = 0; c5_i_k < c5_b_nx; c5_i_k++) {
    c5_j_k = c5_i_k;
    c5_k_x = c5_r_estimated->vector.data[c5_j_k];
    c5_l_x = c5_k_x;
    c5_l_x = muDoubleScalarExp(c5_l_x);
    c5_r_estimated->vector.data[c5_j_k] = c5_l_x;
  }
}

static boolean_T c5_b_all(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, c5_coder_array_boolean_T *c5_b_x)
{
  static char_T c5_b_cv[51] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'a', 'l', 'l', '_', 'o', 'r', '_',
    'a', 'n', 'y', '_', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c', 'o',
    'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  emlrtStack c5_b_st;
  emlrtStack c5_c_st;
  emlrtStack c5_st;
  const mxArray *c5_b_y = NULL;
  const mxArray *c5_c_y = NULL;
  real_T c5_c_a;
  real_T c5_vlen;
  int32_T c5_b_b;
  int32_T c5_c;
  int32_T c5_c_b;
  int32_T c5_d_a;
  int32_T c5_d_b;
  int32_T c5_e_a;
  int32_T c5_i2;
  int32_T c5_ix;
  int32_T c5_vspread;
  boolean_T c5_b;
  boolean_T c5_exitg1;
  boolean_T c5_overflow;
  boolean_T c5_y;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_c_st.prev = &c5_b_st;
  c5_c_st.tls = c5_b_st.tls;
  c5_st.site = &c5_gk_emlrtRSI;
  if ((c5_b_x->size[0] == 1) || ((real_T)c5_b_x->size[0] != 1.0)) {
    c5_b = true;
  } else {
    c5_b = false;
  }

  if (!c5_b) {
    c5_b_y = NULL;
    sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1, 51),
                  false);
    c5_c_y = NULL;
    sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1, 51),
                  false);
    sf_mex_call(&c5_st, &c5_jb_emlrtMCI, "error", 0U, 2U, 14, c5_b_y, 14,
                sf_mex_call(&c5_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c5_st, NULL, "message", 1U, 1U, 14, c5_c_y)));
  }

  c5_y = true;
  c5_vlen = (real_T)c5_b_x->size[0];
  c5_c_a = c5_vlen;
  c5_c = (int32_T)c5_c_a;
  c5_d_a = c5_c - 1;
  c5_vspread = c5_d_a;
  c5_b_b = c5_vspread;
  c5_i2 = c5_b_b;
  c5_e_a = c5_i2 + 1;
  c5_i2 = c5_e_a;
  c5_b_st.site = &c5_hk_emlrtRSI;
  c5_c_b = c5_i2;
  c5_d_b = c5_c_b;
  if (c5_d_b < 1) {
    c5_overflow = false;
  } else {
    c5_overflow = (c5_d_b > 2147483646);
  }

  if (c5_overflow) {
    c5_c_st.site = &c5_v_emlrtRSI;
    c5_check_forloop_overflow_error(chartInstance, &c5_c_st);
  }

  c5_ix = 0;
  c5_exitg1 = false;
  while ((!c5_exitg1) && (c5_ix + 1 <= c5_i2)) {
    if (!c5_b_x->vector.data[c5_ix]) {
      c5_y = false;
      c5_exitg1 = true;
    } else {
      c5_ix++;
    }
  }

  return c5_y;
}

static real_T c5_emlrt_marshallIn(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c5_a__output_of_feval_, const char_T
  *c5_identifier)
{
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y;
  c5_thisId.fIdentifier = (const char_T *)c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_y = c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_a__output_of_feval_),
    &c5_thisId);
  sf_mex_destroy(&c5_a__output_of_feval_);
  return c5_y;
}

static real_T c5_b_emlrt_marshallIn(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c5_e_u, const emlrtMsgIdentifier *c5_parentId)
{
  real_T c5_d;
  real_T c5_y;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_e_u), &c5_d, 1, 0, 0U, 0, 0U, 0);
  c5_y = c5_d;
  sf_mex_destroy(&c5_e_u);
  return c5_y;
}

const mxArray *sf_c5_flightControlSystem_get_eml_resolved_functions_info(void)
{
  const mxArray *c5_nameCaptureInfo = NULL;
  c5_nameCaptureInfo = NULL;
  sf_mex_assign(&c5_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1, 0U, 2, 0, 1), false);
  return c5_nameCaptureInfo;
}

static void c5_slStringInitializeDynamicBuffers
  (SFc5_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c5_chart_data_browse_helper(SFc5_flightControlSystemInstanceStruct
  *chartInstance, int32_T c5_ssIdNumber, const mxArray **c5_mxData, uint8_T
  *c5_isValueTooBig)
{
  real_T c5_d;
  *c5_mxData = NULL;
  *c5_mxData = NULL;
  *c5_isValueTooBig = 0U;
  switch (c5_ssIdNumber) {
   case 4U:
    *c5_isValueTooBig = 1U;
    break;

   case 8U:
    c5_d = *chartInstance->c5_number;
    sf_mex_assign(c5_mxData, sf_mex_create("mxData", &c5_d, 0, 0U, 0, 0U, 0),
                  false);
    break;
  }
}

static const mxArray *c5_feval(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, const mxArray *c5_input0, const
  mxArray *c5_input1)
{
  const mxArray *c5_m = NULL;
  (void)chartInstance;
  c5_m = NULL;
  sf_mex_assign(&c5_m, sf_mex_call(c5_sp, NULL, "feval", 1U, 2U, 14, sf_mex_dup
    (c5_input0), 14, sf_mex_dup(c5_input1)), false);
  sf_mex_destroy(&c5_input0);
  sf_mex_destroy(&c5_input1);
  return c5_m;
}

static void c5_b_feval(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, const mxArray *c5_input0, const mxArray *c5_input1)
{
  (void)chartInstance;
  sf_mex_call(c5_sp, NULL, "feval", 0U, 2U, 14, sf_mex_dup(c5_input0), 14,
              sf_mex_dup(c5_input1));
  sf_mex_destroy(&c5_input0);
  sf_mex_destroy(&c5_input1);
}

static const mxArray *c5_sprintf(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, const mxArray *c5_input0)
{
  const mxArray *c5_m = NULL;
  (void)chartInstance;
  c5_m = NULL;
  sf_mex_assign(&c5_m, sf_mex_call(c5_sp, NULL, "sprintf", 1U, 1U, 14,
    sf_mex_dup(c5_input0)), false);
  sf_mex_destroy(&c5_input0);
  return c5_m;
}

static const mxArray *c5_c_feval(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, const mxArray *c5_input0, const
  mxArray *c5_input1, const mxArray *c5_input2, const mxArray *c5_input3, const
  mxArray *c5_input4, const mxArray *c5_input5, const mxArray *c5_input6, const
  mxArray *c5_input7)
{
  const mxArray *c5_m = NULL;
  (void)chartInstance;
  c5_m = NULL;
  sf_mex_assign(&c5_m, sf_mex_call(c5_sp, NULL, "feval", 1U, 8U, 14, sf_mex_dup
    (c5_input0), 14, sf_mex_dup(c5_input1), 14, sf_mex_dup(c5_input2), 14,
    sf_mex_dup(c5_input3), 14, sf_mex_dup(c5_input4), 14, sf_mex_dup(c5_input5),
    14, sf_mex_dup(c5_input6), 14, sf_mex_dup(c5_input7)), false);
  sf_mex_destroy(&c5_input0);
  sf_mex_destroy(&c5_input1);
  sf_mex_destroy(&c5_input2);
  sf_mex_destroy(&c5_input3);
  sf_mex_destroy(&c5_input4);
  sf_mex_destroy(&c5_input5);
  sf_mex_destroy(&c5_input6);
  sf_mex_destroy(&c5_input7);
  return c5_m;
}

static void c5_d_feval(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, const mxArray *c5_input0, const mxArray *c5_input1)
{
  (void)chartInstance;
  sf_mex_call(c5_sp, NULL, "feval", 0U, 2U, 14, sf_mex_dup(c5_input0), 14,
              sf_mex_dup(c5_input1));
  sf_mex_destroy(&c5_input0);
  sf_mex_destroy(&c5_input1);
}

static const mxArray *c5_e_feval(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, const mxArray *c5_input0, const
  mxArray *c5_input1, const mxArray *c5_input2)
{
  const mxArray *c5_m = NULL;
  (void)chartInstance;
  c5_m = NULL;
  sf_mex_assign(&c5_m, sf_mex_call(c5_sp, NULL, "feval", 1U, 3U, 14, sf_mex_dup
    (c5_input0), 14, sf_mex_dup(c5_input1), 14, sf_mex_dup(c5_input2)), false);
  sf_mex_destroy(&c5_input0);
  sf_mex_destroy(&c5_input1);
  sf_mex_destroy(&c5_input2);
  return c5_m;
}

static void c5_b_parseInputs(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, real_T c5_varargin_2_data[], real_T
  c5_radiusRange_data[], int32_T c5_radiusRange_size[2])
{
  static char_T c5_b_cv[30] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'c', 'h', 'a',
    'c', 'c', 'u', 'm', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'I', 'n',
    't', 'e', 'g', 'e', 'r' };

  static char_T c5_b_cv1[29] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'c', 'h',
    'a', 'c', 'c', 'u', 'm', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'N',
    'o', 'n', 'N', 'a', 'N' };

  static char_T c5_b_cv2[29] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'c', 'h',
    'a', 'c', 'c', 'u', 'm', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'F',
    'i', 'n', 'i', 't', 'e' };

  emlrtStack c5_b_st;
  emlrtStack c5_st;
  const mxArray *c5_b_y = NULL;
  const mxArray *c5_c_y = NULL;
  const mxArray *c5_d_y = NULL;
  const mxArray *c5_e_y = NULL;
  const mxArray *c5_f_y = NULL;
  const mxArray *c5_g_y = NULL;
  const mxArray *c5_h_y = NULL;
  const mxArray *c5_i_y = NULL;
  const mxArray *c5_j_y = NULL;
  const mxArray *c5_k_y = NULL;
  const mxArray *c5_y = NULL;
  real_T c5_b_k;
  real_T c5_b_x;
  real_T c5_c_x;
  real_T c5_d_k;
  real_T c5_d_x;
  real_T c5_e_x;
  real_T c5_f_x;
  int32_T c5_c_k;
  int32_T c5_i;
  int32_T c5_k;
  int32_T c5_loop_ub;
  boolean_T c5_b;
  boolean_T c5_b1;
  boolean_T c5_b2;
  boolean_T c5_b3;
  boolean_T c5_b4;
  boolean_T c5_b5;
  boolean_T c5_b_b;
  boolean_T c5_b_p;
  boolean_T c5_c_b;
  boolean_T c5_c_p;
  boolean_T c5_d_b;
  boolean_T c5_e_b;
  boolean_T c5_exitg1;
  boolean_T c5_p;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_st.site = &c5_le_emlrtRSI;
  c5_b_st.site = &c5_ad_emlrtRSI;
  if (c5_all(chartInstance, c5_varargin_2_data)) {
    c5_b = true;
  } else {
    c5_b = false;
  }

  if (!c5_b) {
    c5_y = NULL;
    sf_mex_assign(&c5_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1, 30),
                  false);
    c5_b_y = NULL;
    sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_cv6, 10, 0U, 1, 0U, 2, 1, 47),
                  false);
    c5_c_y = NULL;
    sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_cv4, 10, 0U, 1, 0U, 2, 1, 29),
                  false);
    sf_mex_call(&c5_b_st, &c5_k_emlrtMCI, "error", 0U, 2U, 14, c5_y, 14,
                sf_mex_call(&c5_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c5_b_st, NULL, "message", 1U, 2U, 14, c5_b_y, 14, c5_c_y)));
  }

  c5_b_st.site = &c5_ad_emlrtRSI;
  c5_p = true;
  c5_k = 0;
  c5_exitg1 = false;
  while ((!c5_exitg1) && (c5_k < 2)) {
    c5_b_k = (real_T)c5_k + 1.0;
    c5_b_x = c5_varargin_2_data[(int32_T)c5_b_k - 1];
    c5_c_x = c5_b_x;
    c5_b_b = muDoubleScalarIsNaN(c5_c_x);
    c5_b_p = !c5_b_b;
    if (c5_b_p) {
      c5_k++;
    } else {
      c5_p = false;
      c5_exitg1 = true;
    }
  }

  if (c5_p) {
    c5_b1 = true;
  } else {
    c5_b1 = false;
  }

  if (!c5_b1) {
    c5_d_y = NULL;
    sf_mex_assign(&c5_d_y, sf_mex_create("y", c5_b_cv1, 10, 0U, 1, 0U, 2, 1, 29),
                  false);
    c5_e_y = NULL;
    sf_mex_assign(&c5_e_y, sf_mex_create("y", c5_cv5, 10, 0U, 1, 0U, 2, 1, 46),
                  false);
    c5_f_y = NULL;
    sf_mex_assign(&c5_f_y, sf_mex_create("y", c5_cv4, 10, 0U, 1, 0U, 2, 1, 29),
                  false);
    sf_mex_call(&c5_b_st, &c5_l_emlrtMCI, "error", 0U, 2U, 14, c5_d_y, 14,
                sf_mex_call(&c5_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c5_b_st, NULL, "message", 1U, 2U, 14, c5_e_y, 14, c5_f_y)));
  }

  c5_b_st.site = &c5_ad_emlrtRSI;
  c5_b_st.site = &c5_ad_emlrtRSI;
  c5_c_p = true;
  c5_c_k = 0;
  c5_exitg1 = false;
  while ((!c5_exitg1) && (c5_c_k < 2)) {
    c5_d_k = (real_T)c5_c_k + 1.0;
    c5_d_x = c5_varargin_2_data[(int32_T)c5_d_k - 1];
    c5_e_x = c5_d_x;
    c5_c_b = muDoubleScalarIsInf(c5_e_x);
    c5_b3 = !c5_c_b;
    c5_f_x = c5_d_x;
    c5_d_b = muDoubleScalarIsNaN(c5_f_x);
    c5_b5 = !c5_d_b;
    c5_e_b = (c5_b3 && c5_b5);
    if (c5_e_b) {
      c5_c_k++;
    } else {
      c5_c_p = false;
      c5_exitg1 = true;
    }
  }

  if (c5_c_p) {
    c5_b2 = true;
  } else {
    c5_b2 = false;
  }

  if (!c5_b2) {
    c5_g_y = NULL;
    sf_mex_assign(&c5_g_y, sf_mex_create("y", c5_b_cv2, 10, 0U, 1, 0U, 2, 1, 29),
                  false);
    c5_h_y = NULL;
    sf_mex_assign(&c5_h_y, sf_mex_create("y", c5_cv2, 10, 0U, 1, 0U, 2, 1, 46),
                  false);
    c5_i_y = NULL;
    sf_mex_assign(&c5_i_y, sf_mex_create("y", c5_cv4, 10, 0U, 1, 0U, 2, 1, 29),
                  false);
    sf_mex_call(&c5_b_st, &c5_g_emlrtMCI, "error", 0U, 2U, 14, c5_g_y, 14,
                sf_mex_call(&c5_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c5_b_st, NULL, "message", 1U, 2U, 14, c5_h_y, 14, c5_i_y)));
  }

  if (c5_varargin_2_data[0] > c5_varargin_2_data[1]) {
    c5_b4 = true;
  } else {
    c5_b4 = false;
  }

  if (c5_b4) {
    c5_j_y = NULL;
    sf_mex_assign(&c5_j_y, sf_mex_create("y", c5_cv10, 10, 0U, 1, 0U, 2, 1, 39),
                  false);
    c5_k_y = NULL;
    sf_mex_assign(&c5_k_y, sf_mex_create("y", c5_cv10, 10, 0U, 1, 0U, 2, 1, 39),
                  false);
    sf_mex_call(c5_sp, &c5_n_emlrtMCI, "error", 0U, 2U, 14, c5_j_y, 14,
                sf_mex_call(c5_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c5_sp, NULL, "message", 1U, 1U, 14, c5_k_y)));
  }

  if (c5_varargin_2_data[0] == c5_varargin_2_data[1]) {
    c5_radiusRange_size[0] = 1;
    c5_radiusRange_size[1] = 1;
    c5_radiusRange_data[0] = c5_varargin_2_data[0];
  } else {
    c5_radiusRange_size[0] = 1;
    c5_radiusRange_size[1] = 2;
    c5_loop_ub = 1;
    for (c5_i = 0; c5_i <= c5_loop_ub; c5_i++) {
      c5_radiusRange_data[c5_i] = c5_varargin_2_data[c5_i];
    }
  }
}

static void c5_b_log(SFc5_flightControlSystemInstanceStruct *chartInstance,
                     const emlrtStack *c5_sp, real_T c5_x_data[], int32_T
                     c5_x_size[2])
{
  static char_T c5_b_cv[3] = { 'l', 'o', 'g' };

  emlrtStack c5_b_st;
  emlrtStack c5_c_st;
  emlrtStack c5_st;
  const mxArray *c5_b_y = NULL;
  const mxArray *c5_c_y = NULL;
  const mxArray *c5_y = NULL;
  real_T c5_b_x_data[81];
  real_T c5_b_k;
  real_T c5_b_x;
  real_T c5_c_x;
  real_T c5_d;
  int32_T c5_b_x_size[2];
  int32_T c5_b;
  int32_T c5_b_b;
  int32_T c5_c_k;
  int32_T c5_d_k;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i2;
  int32_T c5_k;
  int32_T c5_loop_ub;
  int32_T c5_nx;
  boolean_T c5_b_p;
  boolean_T c5_overflow;
  boolean_T c5_p;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_c_st.prev = &c5_b_st;
  c5_c_st.tls = c5_b_st.tls;
  c5_b_x_size[1] = c5_x_size[1];
  c5_loop_ub = c5_x_size[1] - 1;
  for (c5_i = 0; c5_i <= c5_loop_ub; c5_i++) {
    c5_b_x_data[c5_i] = c5_x_data[c5_i];
  }

  c5_p = false;
  c5_d = (real_T)c5_b_x_size[1];
  c5_i1 = (int32_T)c5_d - 1;
  for (c5_k = 0; c5_k <= c5_i1; c5_k++) {
    c5_b_k = (real_T)c5_k + 1.0;
    if (c5_p || (c5_b_x_data[(int32_T)c5_b_k - 1] < 0.0)) {
      c5_b_p = true;
    } else {
      c5_b_p = false;
    }

    c5_p = c5_b_p;
  }

  if (c5_p) {
    c5_y = NULL;
    sf_mex_assign(&c5_y, sf_mex_create("y", c5_cv1, 10, 0U, 1, 0U, 2, 1, 30),
                  false);
    c5_b_y = NULL;
    sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_cv1, 10, 0U, 1, 0U, 2, 1, 30),
                  false);
    c5_c_y = NULL;
    sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1, 3),
                  false);
    sf_mex_call(c5_sp, &c5_r_emlrtMCI, "error", 0U, 2U, 14, c5_y, 14,
                sf_mex_call(c5_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c5_sp, NULL, "message", 1U, 2U, 14, c5_b_y, 14, c5_c_y)));
  }

  c5_st.site = &c5_ef_emlrtRSI;
  c5_nx = c5_x_size[1];
  c5_b_st.site = &c5_ff_emlrtRSI;
  c5_b = c5_nx;
  c5_b_b = c5_b;
  if (c5_b_b < 1) {
    c5_overflow = false;
  } else {
    c5_overflow = (c5_b_b > 2147483646);
  }

  if (c5_overflow) {
    c5_c_st.site = &c5_v_emlrtRSI;
    c5_check_forloop_overflow_error(chartInstance, &c5_c_st);
  }

  c5_i2 = (uint8_T)c5_nx - 1;
  for (c5_c_k = 0; c5_c_k <= c5_i2; c5_c_k++) {
    c5_d_k = c5_c_k;
    c5_b_x = c5_x_data[c5_d_k];
    c5_c_x = c5_b_x;
    c5_c_x = muDoubleScalarLog(c5_c_x);
    c5_x_data[c5_d_k] = c5_c_x;
  }
}

static void c5_b_exp(SFc5_flightControlSystemInstanceStruct *chartInstance,
                     const emlrtStack *c5_sp, creal_T c5_x_data[], int32_T
                     c5_x_size[2])
{
  emlrtStack c5_b_st;
  emlrtStack c5_c_st;
  emlrtStack c5_st;
  creal_T c5_b_x;
  real_T c5_c_x;
  real_T c5_d;
  real_T c5_d1;
  real_T c5_d2;
  real_T c5_d3;
  real_T c5_d4;
  real_T c5_d_x;
  real_T c5_r;
  int32_T c5_b;
  int32_T c5_b_b;
  int32_T c5_b_k;
  int32_T c5_i;
  int32_T c5_k;
  int32_T c5_nx;
  boolean_T c5_c_b;
  boolean_T c5_d_b;
  boolean_T c5_guard1;
  boolean_T c5_overflow;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_st.site = &c5_gf_emlrtRSI;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_c_st.prev = &c5_b_st;
  c5_c_st.tls = c5_b_st.tls;
  c5_nx = c5_x_size[1];
  c5_b_st.site = &c5_ff_emlrtRSI;
  c5_b = c5_nx;
  c5_b_b = c5_b;
  if (c5_b_b < 1) {
    c5_overflow = false;
  } else {
    c5_overflow = (c5_b_b > 2147483646);
  }

  if (c5_overflow) {
    c5_c_st.site = &c5_v_emlrtRSI;
    c5_check_forloop_overflow_error(chartInstance, &c5_c_st);
  }

  c5_i = (uint8_T)c5_nx - 1;
  for (c5_k = 0; c5_k <= c5_i; c5_k++) {
    c5_b_k = c5_k;
    c5_b_x = c5_x_data[c5_b_k];
    if (c5_b_x.re == 0.0) {
      c5_d = c5_b_x.im;
      c5_d2 = c5_b_x.im;
      c5_b_x.re = muDoubleScalarCos(c5_d);
      c5_b_x.im = muDoubleScalarSin(c5_d2);
    } else if (c5_b_x.im == 0.0) {
      c5_d1 = c5_b_x.re;
      c5_b_x.re = muDoubleScalarExp(c5_d1);
      c5_b_x.im = 0.0;
    } else {
      c5_c_x = c5_b_x.im;
      c5_c_b = muDoubleScalarIsInf(c5_c_x);
      c5_guard1 = false;
      if (c5_c_b) {
        c5_d_x = c5_b_x.re;
        c5_d_b = muDoubleScalarIsInf(c5_d_x);
        if (c5_d_b && (c5_b_x.re < 0.0)) {
          c5_b_x = c5_dc;
        } else {
          c5_guard1 = true;
        }
      } else {
        c5_guard1 = true;
      }

      if (c5_guard1) {
        c5_r = muDoubleScalarExp(c5_b_x.re / 2.0);
        c5_d3 = c5_b_x.im;
        c5_d4 = c5_b_x.im;
        c5_b_x.re = c5_r * (c5_r * muDoubleScalarCos(c5_d3));
        c5_b_x.im = c5_r * (c5_r * muDoubleScalarSin(c5_d4));
      }
    }

    c5_x_data[c5_b_k] = c5_b_x;
  }
}

static void c5_b_ComputeWeightedCentroid(SFc5_flightControlSystemInstanceStruct *
  chartInstance, const emlrtStack *c5_sp, real_T c5_I[19200],
  c5_coder_array_s_R6Og1x0kmqQXSF9Pw *c5_stats, c5_sHtk0WM4OMtyqkehwQYcq2
  *c5_statsAlreadyComputed)
{
  c5_cell_wrap_51 c5_reshapes[2];
  c5_coder_array_int32_T c5_idx;
  c5_coder_array_int32_T c5_varargout_4;
  c5_coder_array_int32_T c5_vk;
  c5_coder_array_real_T c5_Intensity;
  c5_coder_array_real_T c5_j;
  c5_coder_array_real_T c5_r;
  c5_coder_array_real_T c5_r1;
  c5_coder_array_real_T_2D c5_result;
  emlrtStack c5_b_st;
  emlrtStack c5_c_st;
  emlrtStack c5_d_st;
  emlrtStack c5_st;
  const mxArray *c5_b_y = NULL;
  const mxArray *c5_c_y = NULL;
  const mxArray *c5_d_y = NULL;
  const mxArray *c5_y = NULL;
  real_T c5_wc[2];
  real_T c5_M;
  real_T c5_b_k;
  real_T c5_b_n;
  real_T c5_c_idx;
  real_T c5_d;
  real_T c5_d1;
  real_T c5_d2;
  real_T c5_d3;
  real_T c5_d_k;
  real_T c5_f_k;
  real_T c5_sumIntensity;
  int32_T c5_sizes[2];
  int32_T c5_ab_loop_ub;
  int32_T c5_b_idx;
  int32_T c5_b_loop_ub;
  int32_T c5_b_result;
  int32_T c5_bb_loop_ub;
  int32_T c5_c_k;
  int32_T c5_c_loop_ub;
  int32_T c5_c_n;
  int32_T c5_cb_loop_ub;
  int32_T c5_d_loop_ub;
  int32_T c5_db_loop_ub;
  int32_T c5_e_k;
  int32_T c5_e_loop_ub;
  int32_T c5_eb_loop_ub;
  int32_T c5_expected;
  int32_T c5_f_loop_ub;
  int32_T c5_fb_loop_ub;
  int32_T c5_g_loop_ub;
  int32_T c5_gb_loop_ub;
  int32_T c5_h_loop_ub;
  int32_T c5_hb_loop_ub;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i10;
  int32_T c5_i100;
  int32_T c5_i101;
  int32_T c5_i102;
  int32_T c5_i103;
  int32_T c5_i104;
  int32_T c5_i105;
  int32_T c5_i106;
  int32_T c5_i107;
  int32_T c5_i108;
  int32_T c5_i109;
  int32_T c5_i11;
  int32_T c5_i110;
  int32_T c5_i111;
  int32_T c5_i112;
  int32_T c5_i113;
  int32_T c5_i114;
  int32_T c5_i115;
  int32_T c5_i116;
  int32_T c5_i117;
  int32_T c5_i118;
  int32_T c5_i119;
  int32_T c5_i12;
  int32_T c5_i120;
  int32_T c5_i121;
  int32_T c5_i122;
  int32_T c5_i123;
  int32_T c5_i124;
  int32_T c5_i125;
  int32_T c5_i126;
  int32_T c5_i127;
  int32_T c5_i128;
  int32_T c5_i13;
  int32_T c5_i14;
  int32_T c5_i15;
  int32_T c5_i16;
  int32_T c5_i17;
  int32_T c5_i18;
  int32_T c5_i19;
  int32_T c5_i2;
  int32_T c5_i20;
  int32_T c5_i21;
  int32_T c5_i22;
  int32_T c5_i23;
  int32_T c5_i24;
  int32_T c5_i25;
  int32_T c5_i26;
  int32_T c5_i27;
  int32_T c5_i28;
  int32_T c5_i29;
  int32_T c5_i3;
  int32_T c5_i30;
  int32_T c5_i31;
  int32_T c5_i32;
  int32_T c5_i33;
  int32_T c5_i34;
  int32_T c5_i35;
  int32_T c5_i36;
  int32_T c5_i37;
  int32_T c5_i38;
  int32_T c5_i39;
  int32_T c5_i4;
  int32_T c5_i40;
  int32_T c5_i41;
  int32_T c5_i42;
  int32_T c5_i43;
  int32_T c5_i44;
  int32_T c5_i45;
  int32_T c5_i46;
  int32_T c5_i47;
  int32_T c5_i48;
  int32_T c5_i49;
  int32_T c5_i5;
  int32_T c5_i50;
  int32_T c5_i51;
  int32_T c5_i52;
  int32_T c5_i53;
  int32_T c5_i54;
  int32_T c5_i55;
  int32_T c5_i56;
  int32_T c5_i57;
  int32_T c5_i58;
  int32_T c5_i59;
  int32_T c5_i6;
  int32_T c5_i60;
  int32_T c5_i61;
  int32_T c5_i62;
  int32_T c5_i63;
  int32_T c5_i64;
  int32_T c5_i65;
  int32_T c5_i66;
  int32_T c5_i67;
  int32_T c5_i68;
  int32_T c5_i69;
  int32_T c5_i7;
  int32_T c5_i70;
  int32_T c5_i71;
  int32_T c5_i72;
  int32_T c5_i73;
  int32_T c5_i74;
  int32_T c5_i75;
  int32_T c5_i76;
  int32_T c5_i77;
  int32_T c5_i78;
  int32_T c5_i79;
  int32_T c5_i8;
  int32_T c5_i80;
  int32_T c5_i81;
  int32_T c5_i82;
  int32_T c5_i83;
  int32_T c5_i84;
  int32_T c5_i85;
  int32_T c5_i86;
  int32_T c5_i87;
  int32_T c5_i88;
  int32_T c5_i89;
  int32_T c5_i9;
  int32_T c5_i90;
  int32_T c5_i91;
  int32_T c5_i92;
  int32_T c5_i93;
  int32_T c5_i94;
  int32_T c5_i95;
  int32_T c5_i96;
  int32_T c5_i97;
  int32_T c5_i98;
  int32_T c5_i99;
  int32_T c5_i_loop_ub;
  int32_T c5_ib_loop_ub;
  int32_T c5_j_loop_ub;
  int32_T c5_k;
  int32_T c5_k_loop_ub;
  int32_T c5_l_loop_ub;
  int32_T c5_loop_ub;
  int32_T c5_m_loop_ub;
  int32_T c5_n;
  int32_T c5_n_loop_ub;
  int32_T c5_o_loop_ub;
  int32_T c5_p_loop_ub;
  int32_T c5_q_loop_ub;
  int32_T c5_r_loop_ub;
  int32_T c5_s_loop_ub;
  int32_T c5_t_loop_ub;
  int32_T c5_u_loop_ub;
  int32_T c5_v_loop_ub;
  int32_T c5_w_loop_ub;
  int32_T c5_x_loop_ub;
  int32_T c5_y_loop_ub;
  boolean_T c5_b;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_c_st.prev = &c5_b_st;
  c5_c_st.tls = c5_b_st.tls;
  c5_d_st.prev = &c5_c_st;
  c5_d_st.tls = c5_c_st.tls;
  c5_statsAlreadyComputed->WeightedCentroid = true;
  c5_st.site = &c5_ei_emlrtRSI;
  c5_statsAlreadyComputed->PixelList = true;
  c5_d = (real_T)c5_stats->size[0];
  c5_i = (int32_T)c5_d - 1;
  c5_array_real_T_Constructor(chartInstance, &c5_Intensity);
  c5_array_real_T_Constructor(chartInstance, &c5_j);
  c5_array_real_T_Constructor(chartInstance, &c5_r);
  c5_array_int32_T_Constructor(chartInstance, &c5_varargout_4);
  c5_array_real_T_2D_Constructor(chartInstance, &c5_result);
  c5_array_cell_wrap_51_2s_Construct(chartInstance, c5_reshapes);
  c5_array_int32_T_Constructor(chartInstance, &c5_idx);
  c5_array_int32_T_Constructor(chartInstance, &c5_vk);
  for (c5_k = 0; c5_k <= c5_i; c5_k++) {
    c5_b_k = (real_T)c5_k + 1.0;
    c5_i1 = c5_stats->size[0];
    c5_i2 = (int32_T)c5_b_k;
    if ((c5_i2 < 1) || (c5_i2 > c5_i1)) {
      emlrtDynamicBoundsCheckR2012b(c5_i2, 1, c5_i1, &c5_ag_emlrtBCI, &c5_st);
    }

    c5_array_real_T_SetSize(chartInstance, &c5_st, &c5_r, &c5_mf_emlrtRTEI,
      c5_stats->vector.data[c5_i2 - 1].PixelIdxList.size[0]);
    c5_i4 = c5_stats->size[0];
    c5_i5 = (int32_T)c5_b_k;
    if ((c5_i5 < 1) || (c5_i5 > c5_i4)) {
      emlrtDynamicBoundsCheckR2012b(c5_i5, 1, c5_i4, &c5_ag_emlrtBCI, &c5_st);
    }

    c5_loop_ub = c5_stats->vector.data[c5_i5 - 1].PixelIdxList.size[0] - 1;
    for (c5_i8 = 0; c5_i8 <= c5_loop_ub; c5_i8++) {
      c5_i11 = c5_stats->size[0];
      c5_i14 = (int32_T)c5_b_k;
      if ((c5_i14 < 1) || (c5_i14 > c5_i11)) {
        emlrtDynamicBoundsCheckR2012b(c5_i14, 1, c5_i11, &c5_ag_emlrtBCI, &c5_st);
      }

      c5_r.vector.data[c5_i8] = c5_stats->vector.data[c5_i14 - 1].
        PixelIdxList.vector.data[c5_i8];
    }

    if (c5_r.size[0] != 0) {
      c5_b_st.site = &c5_gi_emlrtRSI;
      c5_i16 = c5_stats->size[0];
      c5_i17 = (int32_T)c5_b_k;
      if ((c5_i17 < 1) || (c5_i17 > c5_i16)) {
        emlrtDynamicBoundsCheckR2012b(c5_i17, 1, c5_i16, &c5_cg_emlrtBCI,
          &c5_b_st);
      }

      c5_array_real_T_SetSize(chartInstance, &c5_b_st, &c5_Intensity,
        &c5_of_emlrtRTEI, c5_stats->vector.data[c5_i17 - 1].PixelIdxList.size[0]);
      c5_i24 = c5_stats->size[0];
      c5_i28 = (int32_T)c5_b_k;
      if ((c5_i28 < 1) || (c5_i28 > c5_i24)) {
        emlrtDynamicBoundsCheckR2012b(c5_i28, 1, c5_i24, &c5_cg_emlrtBCI,
          &c5_b_st);
      }

      c5_c_loop_ub = c5_stats->vector.data[c5_i28 - 1].PixelIdxList.size[0] - 1;
      for (c5_i34 = 0; c5_i34 <= c5_c_loop_ub; c5_i34++) {
        c5_i37 = c5_stats->size[0];
        c5_i40 = (int32_T)c5_b_k;
        if ((c5_i40 < 1) || (c5_i40 > c5_i37)) {
          emlrtDynamicBoundsCheckR2012b(c5_i40, 1, c5_i37, &c5_cg_emlrtBCI,
            &c5_b_st);
        }

        c5_Intensity.vector.data[c5_i34] = c5_stats->vector.data[c5_i40 - 1].
          PixelIdxList.vector.data[c5_i34];
      }

      c5_c_st.site = &c5_hi_emlrtRSI;
      c5_array_int32_T_SetSize(chartInstance, &c5_c_st, &c5_idx,
        &c5_pf_emlrtRTEI, c5_Intensity.size[0]);
      c5_e_loop_ub = c5_Intensity.size[0] - 1;
      for (c5_i44 = 0; c5_i44 <= c5_e_loop_ub; c5_i44++) {
        c5_idx.vector.data[c5_i44] = (int32_T)c5_Intensity.vector.data[c5_i44];
      }

      c5_f_loop_ub = c5_idx.size[0] - 1;
      for (c5_i50 = 0; c5_i50 <= c5_f_loop_ub; c5_i50++) {
        c5_idx.vector.data[c5_i50]--;
      }

      c5_array_int32_T_SetSize(chartInstance, &c5_c_st, &c5_vk, &c5_qf_emlrtRTEI,
        c5_idx.size[0]);
      c5_g_loop_ub = c5_idx.size[0] - 1;
      for (c5_i52 = 0; c5_i52 <= c5_g_loop_ub; c5_i52++) {
        c5_vk.vector.data[c5_i52] = c5_div_nzp_s32(chartInstance,
          c5_idx.vector.data[c5_i52], 120, 0, 0U, 0, 0);
      }

      c5_array_int32_T_SetSize(chartInstance, &c5_c_st, &c5_varargout_4,
        &c5_rf_emlrtRTEI, c5_vk.size[0]);
      c5_i_loop_ub = c5_vk.size[0] - 1;
      for (c5_i61 = 0; c5_i61 <= c5_i_loop_ub; c5_i61++) {
        c5_varargout_4.vector.data[c5_i61] = c5_vk.vector.data[c5_i61] + 1;
      }

      c5_k_loop_ub = c5_vk.size[0] - 1;
      for (c5_i65 = 0; c5_i65 <= c5_k_loop_ub; c5_i65++) {
        c5_vk.vector.data[c5_i65] *= 120;
      }

      c5_m_loop_ub = c5_idx.size[0] - 1;
      for (c5_i68 = 0; c5_i68 <= c5_m_loop_ub; c5_i68++) {
        c5_idx.vector.data[c5_i68] -= c5_vk.vector.data[c5_i68];
      }

      c5_o_loop_ub = c5_idx.size[0] - 1;
      for (c5_i71 = 0; c5_i71 <= c5_o_loop_ub; c5_i71++) {
        c5_idx.vector.data[c5_i71]++;
      }

      c5_array_real_T_SetSize(chartInstance, &c5_b_st, &c5_Intensity,
        &c5_sf_emlrtRTEI, c5_idx.size[0]);
      c5_q_loop_ub = c5_idx.size[0] - 1;
      for (c5_i76 = 0; c5_i76 <= c5_q_loop_ub; c5_i76++) {
        c5_Intensity.vector.data[c5_i76] = (real_T)c5_idx.vector.data[c5_i76];
      }

      c5_array_real_T_SetSize(chartInstance, &c5_b_st, &c5_j, &c5_sf_emlrtRTEI,
        c5_varargout_4.size[0]);
      c5_t_loop_ub = c5_varargout_4.size[0] - 1;
      for (c5_i79 = 0; c5_i79 <= c5_t_loop_ub; c5_i79++) {
        c5_j.vector.data[c5_i79] = (real_T)c5_varargout_4.vector.data[c5_i79];
      }

      c5_b_st.site = &c5_fi_emlrtRSI;
      c5_c_st.site = &c5_ii_emlrtRSI;
      c5_b_result = c5_j.size[0];
      c5_sizes[0] = c5_b_result;
      c5_d_st.site = &c5_ji_emlrtRSI;
      c5_expected = c5_sizes[0];
      if (c5_j.size[0] == c5_expected) {
        c5_b = true;
      } else {
        c5_b = false;
      }

      if (!c5_b) {
        c5_y = NULL;
        sf_mex_assign(&c5_y, sf_mex_create("y", c5_cv, 10, 0U, 1, 0U, 2, 1, 39),
                      false);
        c5_b_y = NULL;
        sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_cv, 10, 0U, 1, 0U, 2, 1, 39),
                      false);
        sf_mex_call(&c5_d_st, &c5_ab_emlrtMCI, "error", 0U, 2U, 14, c5_y, 14,
                    sf_mex_call(&c5_d_st, NULL, "getString", 1U, 1U, 14,
          sf_mex_call(&c5_d_st, NULL, "message", 1U, 1U, 14, c5_b_y)));
      }

      if (c5_Intensity.size[0] == c5_expected) {
        c5_b = true;
      } else {
        c5_b = false;
      }

      if (!c5_b) {
        c5_c_y = NULL;
        sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_cv, 10, 0U, 1, 0U, 2, 1, 39),
                      false);
        c5_d_y = NULL;
        sf_mex_assign(&c5_d_y, sf_mex_create("y", c5_cv, 10, 0U, 1, 0U, 2, 1, 39),
                      false);
        sf_mex_call(&c5_d_st, &c5_ab_emlrtMCI, "error", 0U, 2U, 14, c5_c_y, 14,
                    sf_mex_call(&c5_d_st, NULL, "getString", 1U, 1U, 14,
          sf_mex_call(&c5_d_st, NULL, "message", 1U, 1U, 14, c5_d_y)));
      }

      c5_array_real_T_SetSize(chartInstance, &c5_c_st, &c5_reshapes[0].f1,
        &c5_tf_emlrtRTEI, c5_j.size[0]);
      c5_bb_loop_ub = c5_j.size[0] - 1;
      for (c5_i93 = 0; c5_i93 <= c5_bb_loop_ub; c5_i93++) {
        c5_reshapes[0].f1.vector.data[c5_i93] = c5_j.vector.data[c5_i93];
      }

      c5_array_real_T_SetSize(chartInstance, &c5_c_st, &c5_reshapes[1].f1,
        &c5_tf_emlrtRTEI, c5_Intensity.size[0]);
      c5_cb_loop_ub = c5_Intensity.size[0] - 1;
      for (c5_i95 = 0; c5_i95 <= c5_cb_loop_ub; c5_i95++) {
        c5_reshapes[1].f1.vector.data[c5_i95] = c5_Intensity.vector.data[c5_i95];
      }

      c5_array_real_T_SetSize(chartInstance, &c5_c_st, &c5_Intensity,
        &c5_d_emlrtRTEI, c5_reshapes[0].f1.size[0]);
      c5_eb_loop_ub = c5_reshapes[0].f1.size[0] - 1;
      for (c5_i100 = 0; c5_i100 <= c5_eb_loop_ub; c5_i100++) {
        c5_Intensity.vector.data[c5_i100] = c5_reshapes[0]
          .f1.vector.data[c5_i100];
      }

      c5_array_real_T_SetSize(chartInstance, &c5_c_st, &c5_j, &c5_d_emlrtRTEI,
        c5_reshapes[1].f1.size[0]);
      c5_fb_loop_ub = c5_reshapes[1].f1.size[0] - 1;
      for (c5_i102 = 0; c5_i102 <= c5_fb_loop_ub; c5_i102++) {
        c5_j.vector.data[c5_i102] = c5_reshapes[1].f1.vector.data[c5_i102];
      }

      c5_array_real_T_2D_SetSize(chartInstance, &c5_c_st, &c5_result,
        &c5_uf_emlrtRTEI, c5_Intensity.size[0], 2);
      c5_gb_loop_ub = c5_Intensity.size[0] - 1;
      for (c5_i105 = 0; c5_i105 <= c5_gb_loop_ub; c5_i105++) {
        c5_result.vector.data[c5_i105] = c5_Intensity.vector.data[c5_i105];
      }

      c5_hb_loop_ub = c5_j.size[0] - 1;
      for (c5_i108 = 0; c5_i108 <= c5_hb_loop_ub; c5_i108++) {
        c5_result.vector.data[c5_i108 + c5_result.size[0]] =
          c5_j.vector.data[c5_i108];
      }

      c5_i110 = c5_result.size[0] << 1;
      c5_i111 = c5_stats->size[0];
      c5_i112 = (int32_T)c5_b_k;
      if ((c5_i112 < 1) || (c5_i112 > c5_i111)) {
        emlrtDynamicBoundsCheckR2012b(c5_i112, 1, c5_i111, &c5_tf_emlrtBCI,
          &c5_st);
      }

      c5_i115 = c5_i112 - 1;
      c5_array_real_T_2D_SetSize(chartInstance, &c5_st, &c5_stats->
        vector.data[c5_i115].PixelList, &c5_vf_emlrtRTEI, c5_result.size[0],
        c5_stats->vector.data[c5_i115].PixelList.size[1]);
      c5_i117 = c5_stats->size[0];
      c5_i119 = (int32_T)c5_b_k;
      if ((c5_i119 < 1) || (c5_i119 > c5_i117)) {
        emlrtDynamicBoundsCheckR2012b(c5_i119, 1, c5_i117, &c5_tf_emlrtBCI,
          &c5_st);
      }

      c5_i120 = c5_i119 - 1;
      c5_array_real_T_2D_SetSize(chartInstance, &c5_st, &c5_stats->
        vector.data[c5_i120].PixelList, &c5_vf_emlrtRTEI, c5_stats->
        vector.data[c5_i120].PixelList.size[0], 2);
      c5_i121 = c5_stats->size[0];
      c5_i122 = (int32_T)c5_b_k;
      if ((c5_i122 < 1) || (c5_i122 > c5_i121)) {
        emlrtDynamicBoundsCheckR2012b(c5_i122, 1, c5_i121, &c5_tf_emlrtBCI,
          &c5_st);
      }

      c5_i123 = c5_stats->size[0];
      c5_i124 = (int32_T)c5_b_k;
      if ((c5_i124 < 1) || (c5_i124 > c5_i123)) {
        emlrtDynamicBoundsCheckR2012b(c5_i124, 1, c5_i123, &c5_tf_emlrtBCI,
          &c5_st);
      }

      c5_i125 = c5_i110;
      c5_ib_loop_ub = c5_i125 - 1;
      for (c5_i126 = 0; c5_i126 <= c5_ib_loop_ub; c5_i126++) {
        c5_i127 = c5_stats->size[0];
        c5_i128 = (int32_T)c5_b_k;
        if ((c5_i128 < 1) || (c5_i128 > c5_i127)) {
          emlrtDynamicBoundsCheckR2012b(c5_i128, 1, c5_i127, &c5_hg_emlrtBCI,
            &c5_st);
        }

        c5_stats->vector.data[c5_i128 - 1].PixelList.vector.data[c5_i126] =
          c5_result.vector.data[c5_i126];
      }
    } else {
      c5_i13 = c5_stats->size[0];
      c5_i15 = (int32_T)c5_b_k;
      if ((c5_i15 < 1) || (c5_i15 > c5_i13)) {
        emlrtDynamicBoundsCheckR2012b(c5_i15, 1, c5_i13, &c5_rf_emlrtBCI, &c5_st);
      }

      c5_i21 = c5_i15 - 1;
      c5_array_real_T_2D_SetSize(chartInstance, &c5_st, &c5_stats->
        vector.data[c5_i21].PixelList, &c5_nf_emlrtRTEI, 0,
        c5_stats->vector.data[c5_i21].PixelList.size[1]);
      c5_i23 = c5_stats->size[0];
      c5_i27 = (int32_T)c5_b_k;
      if ((c5_i27 < 1) || (c5_i27 > c5_i23)) {
        emlrtDynamicBoundsCheckR2012b(c5_i27, 1, c5_i23, &c5_rf_emlrtBCI, &c5_st);
      }

      c5_i32 = c5_i27 - 1;
      c5_array_real_T_2D_SetSize(chartInstance, &c5_st, &c5_stats->
        vector.data[c5_i32].PixelList, &c5_nf_emlrtRTEI, c5_stats->
        vector.data[c5_i32].PixelList.size[0], 2);
      c5_i35 = c5_stats->size[0];
      c5_i36 = (int32_T)c5_b_k;
      if ((c5_i36 < 1) || (c5_i36 > c5_i35)) {
        emlrtDynamicBoundsCheckR2012b(c5_i36, 1, c5_i35, &c5_rf_emlrtBCI, &c5_st);
      }

      c5_i43 = c5_stats->size[0];
      c5_i46 = (int32_T)c5_b_k;
      if ((c5_i46 < 1) || (c5_i46 > c5_i43)) {
        emlrtDynamicBoundsCheckR2012b(c5_i46, 1, c5_i43, &c5_rf_emlrtBCI, &c5_st);
      }
    }
  }

  c5_array_cell_wrap_51_2s_Destructo(chartInstance, c5_reshapes);
  c5_st.site = &c5_di_emlrtRSI;
  c5_statsAlreadyComputed->PixelValues = true;
  c5_d1 = (real_T)c5_stats->size[0];
  c5_i3 = (int32_T)c5_d1 - 1;
  for (c5_c_k = 0; c5_c_k <= c5_i3; c5_c_k++) {
    c5_d_k = (real_T)c5_c_k + 1.0;
    c5_i6 = c5_stats->size[0];
    c5_i7 = (int32_T)c5_d_k;
    if ((c5_i7 < 1) || (c5_i7 > c5_i6)) {
      emlrtDynamicBoundsCheckR2012b(c5_i7, 1, c5_i6, &c5_bg_emlrtBCI, &c5_st);
    }

    c5_array_real_T_SetSize(chartInstance, &c5_st, &c5_r, &c5_wf_emlrtRTEI,
      c5_stats->vector.data[c5_i7 - 1].PixelIdxList.size[0]);
    c5_i10 = c5_stats->size[0];
    c5_i12 = (int32_T)c5_d_k;
    if ((c5_i12 < 1) || (c5_i12 > c5_i10)) {
      emlrtDynamicBoundsCheckR2012b(c5_i12, 1, c5_i10, &c5_bg_emlrtBCI, &c5_st);
    }

    c5_b_loop_ub = c5_stats->vector.data[c5_i12 - 1].PixelIdxList.size[0] - 1;
    for (c5_i20 = 0; c5_i20 <= c5_b_loop_ub; c5_i20++) {
      c5_i22 = c5_stats->size[0];
      c5_i26 = (int32_T)c5_d_k;
      if ((c5_i26 < 1) || (c5_i26 > c5_i22)) {
        emlrtDynamicBoundsCheckR2012b(c5_i26, 1, c5_i22, &c5_bg_emlrtBCI, &c5_st);
      }

      c5_r.vector.data[c5_i20] = c5_stats->vector.data[c5_i26 - 1].
        PixelIdxList.vector.data[c5_i20];
    }

    c5_wc[0] = (real_T)c5_r.size[0];
    c5_i25 = c5_stats->size[0];
    c5_i29 = (int32_T)c5_d_k;
    if ((c5_i29 < 1) || (c5_i29 > c5_i25)) {
      emlrtDynamicBoundsCheckR2012b(c5_i29, 1, c5_i25, &c5_qf_emlrtBCI, &c5_st);
    }

    c5_i33 = c5_i29;
    c5_array_real_T_SetSize(chartInstance, &c5_st, &c5_stats->vector.data[c5_i33
      - 1].PixelValues, &c5_xf_emlrtRTEI, (int32_T)c5_wc[0]);
    c5_b_st.site = &c5_ki_emlrtRSI;
    c5_i39 = c5_stats->size[0];
    c5_i41 = (int32_T)c5_d_k;
    if ((c5_i41 < 1) || (c5_i41 > c5_i39)) {
      emlrtDynamicBoundsCheckR2012b(c5_i41, 1, c5_i39, &c5_fg_emlrtBCI, &c5_b_st);
    }

    c5_array_real_T_SetSize(chartInstance, &c5_b_st, &c5_Intensity,
      &c5_yf_emlrtRTEI, c5_stats->vector.data[c5_i41 - 1].PixelIdxList.size[0]);
    c5_i49 = c5_stats->size[0];
    c5_i51 = (int32_T)c5_d_k;
    if ((c5_i51 < 1) || (c5_i51 > c5_i49)) {
      emlrtDynamicBoundsCheckR2012b(c5_i51, 1, c5_i49, &c5_fg_emlrtBCI, &c5_b_st);
    }

    c5_h_loop_ub = c5_stats->vector.data[c5_i51 - 1].PixelIdxList.size[0] - 1;
    for (c5_i54 = 0; c5_i54 <= c5_h_loop_ub; c5_i54++) {
      c5_i58 = c5_stats->size[0];
      c5_i60 = (int32_T)c5_d_k;
      if ((c5_i60 < 1) || (c5_i60 > c5_i58)) {
        emlrtDynamicBoundsCheckR2012b(c5_i60, 1, c5_i58, &c5_fg_emlrtBCI,
          &c5_b_st);
      }

      c5_Intensity.vector.data[c5_i54] = c5_stats->vector.data[c5_i60 - 1].
        PixelIdxList.vector.data[c5_i54];
    }

    c5_c_st.site = &c5_hi_emlrtRSI;
    c5_array_int32_T_SetSize(chartInstance, &c5_c_st, &c5_idx, &c5_pf_emlrtRTEI,
      c5_Intensity.size[0]);
    c5_j_loop_ub = c5_Intensity.size[0] - 1;
    for (c5_i63 = 0; c5_i63 <= c5_j_loop_ub; c5_i63++) {
      c5_idx.vector.data[c5_i63] = (int32_T)c5_Intensity.vector.data[c5_i63];
    }

    c5_l_loop_ub = c5_idx.size[0] - 1;
    for (c5_i66 = 0; c5_i66 <= c5_l_loop_ub; c5_i66++) {
      c5_idx.vector.data[c5_i66]--;
    }

    c5_array_int32_T_SetSize(chartInstance, &c5_c_st, &c5_vk, &c5_qf_emlrtRTEI,
      c5_idx.size[0]);
    c5_n_loop_ub = c5_idx.size[0] - 1;
    for (c5_i70 = 0; c5_i70 <= c5_n_loop_ub; c5_i70++) {
      c5_vk.vector.data[c5_i70] = c5_div_nzp_s32(chartInstance,
        c5_idx.vector.data[c5_i70], 120, 0, 0U, 0, 0);
    }

    c5_array_int32_T_SetSize(chartInstance, &c5_c_st, &c5_varargout_4,
      &c5_rf_emlrtRTEI, c5_vk.size[0]);
    c5_p_loop_ub = c5_vk.size[0] - 1;
    for (c5_i75 = 0; c5_i75 <= c5_p_loop_ub; c5_i75++) {
      c5_varargout_4.vector.data[c5_i75] = c5_vk.vector.data[c5_i75] + 1;
    }

    c5_s_loop_ub = c5_vk.size[0] - 1;
    for (c5_i78 = 0; c5_i78 <= c5_s_loop_ub; c5_i78++) {
      c5_vk.vector.data[c5_i78] *= 120;
    }

    c5_u_loop_ub = c5_idx.size[0] - 1;
    for (c5_i82 = 0; c5_i82 <= c5_u_loop_ub; c5_i82++) {
      c5_idx.vector.data[c5_i82] -= c5_vk.vector.data[c5_i82];
    }

    c5_w_loop_ub = c5_idx.size[0] - 1;
    for (c5_i84 = 0; c5_i84 <= c5_w_loop_ub; c5_i84++) {
      c5_idx.vector.data[c5_i84]++;
    }

    c5_array_real_T_SetSize(chartInstance, &c5_b_st, &c5_j, &c5_sf_emlrtRTEI,
      c5_idx.size[0]);
    c5_x_loop_ub = c5_idx.size[0] - 1;
    for (c5_i87 = 0; c5_i87 <= c5_x_loop_ub; c5_i87++) {
      c5_j.vector.data[c5_i87] = (real_T)c5_idx.vector.data[c5_i87];
    }

    c5_array_real_T_SetSize(chartInstance, &c5_b_st, &c5_Intensity,
      &c5_sf_emlrtRTEI, c5_varargout_4.size[0]);
    c5_y_loop_ub = c5_varargout_4.size[0] - 1;
    for (c5_i88 = 0; c5_i88 <= c5_y_loop_ub; c5_i88++) {
      c5_Intensity.vector.data[c5_i88] = (real_T)
        c5_varargout_4.vector.data[c5_i88];
    }

    c5_i90 = c5_stats->size[0];
    c5_i91 = (int32_T)c5_d_k;
    if ((c5_i91 < 1) || (c5_i91 > c5_i90)) {
      emlrtDynamicBoundsCheckR2012b(c5_i91, 1, c5_i90, &c5_gg_emlrtBCI, &c5_st);
    }

    c5_array_real_T_SetSize(chartInstance, &c5_st, &c5_r, &c5_ag_emlrtRTEI,
      c5_stats->vector.data[c5_i91 - 1].PixelValues.size[0]);
    c5_i92 = c5_stats->size[0];
    c5_i94 = (int32_T)c5_d_k;
    if ((c5_i94 < 1) || (c5_i94 > c5_i92)) {
      emlrtDynamicBoundsCheckR2012b(c5_i94, 1, c5_i92, &c5_gg_emlrtBCI, &c5_st);
    }

    c5_db_loop_ub = c5_stats->vector.data[c5_i94 - 1].PixelValues.size[0] - 1;
    for (c5_i96 = 0; c5_i96 <= c5_db_loop_ub; c5_i96++) {
      c5_i97 = c5_stats->size[0];
      c5_i99 = (int32_T)c5_d_k;
      if ((c5_i99 < 1) || (c5_i99 > c5_i97)) {
        emlrtDynamicBoundsCheckR2012b(c5_i99, 1, c5_i97, &c5_gg_emlrtBCI, &c5_st);
      }

      c5_r.vector.data[c5_i96] = c5_stats->vector.data[c5_i99 - 1].
        PixelValues.vector.data[c5_i96];
    }

    c5_d3 = (real_T)c5_r.size[0];
    c5_i98 = (int32_T)c5_d3 - 1;
    for (c5_b_idx = 0; c5_b_idx <= c5_i98; c5_b_idx++) {
      c5_c_idx = (real_T)c5_b_idx + 1.0;
      c5_i101 = c5_stats->size[0];
      c5_i103 = (int32_T)c5_d_k;
      if ((c5_i103 < 1) || (c5_i103 > c5_i101)) {
        emlrtDynamicBoundsCheckR2012b(c5_i103, 1, c5_i101, &c5_pf_emlrtBCI,
          &c5_st);
      }

      c5_i104 = c5_i103 - 1;
      c5_i106 = c5_j.size[0];
      c5_i107 = (int32_T)c5_c_idx;
      if ((c5_i107 < 1) || (c5_i107 > c5_i106)) {
        emlrtDynamicBoundsCheckR2012b(c5_i107, 1, c5_i106, &c5_wf_emlrtBCI,
          &c5_st);
      }

      c5_i109 = (int32_T)c5_j.vector.data[c5_i107 - 1];
      if ((c5_i109 < 1) || (c5_i109 > 120)) {
        emlrtDynamicBoundsCheckR2012b(c5_i109, 1, 120, &c5_vf_emlrtBCI, &c5_st);
      }

      c5_i113 = c5_Intensity.size[0];
      c5_i114 = (int32_T)c5_c_idx;
      if ((c5_i114 < 1) || (c5_i114 > c5_i113)) {
        emlrtDynamicBoundsCheckR2012b(c5_i114, 1, c5_i113, &c5_xf_emlrtBCI,
          &c5_st);
      }

      c5_i116 = c5_stats->vector.data[c5_i104].PixelValues.size[0];
      c5_i118 = (int32_T)c5_c_idx;
      if ((c5_i118 < 1) || (c5_i118 > c5_i116)) {
        emlrtDynamicBoundsCheckR2012b(c5_i118, 1, c5_i116, &c5_yf_emlrtBCI,
          &c5_st);
      }

      c5_stats->vector.data[c5_i104].PixelValues.vector.data[c5_i118 - 1] =
        c5_I[(c5_i109 + 120 * ((int32_T)c5_Intensity.vector.data[c5_i114 - 1] -
               1)) - 1];
    }
  }

  c5_array_int32_T_Destructor(chartInstance, &c5_vk);
  c5_array_int32_T_Destructor(chartInstance, &c5_idx);
  c5_array_int32_T_Destructor(chartInstance, &c5_varargout_4);
  c5_array_real_T_Destructor(chartInstance, &c5_j);
  c5_d2 = (real_T)c5_stats->size[0];
  c5_i9 = (int32_T)c5_d2 - 1;
  c5_array_real_T_Constructor(chartInstance, &c5_r1);
  for (c5_e_k = 0; c5_e_k <= c5_i9; c5_e_k++) {
    c5_f_k = (real_T)c5_e_k + 1.0;
    c5_i18 = c5_stats->size[0];
    c5_i19 = (int32_T)c5_f_k;
    if ((c5_i19 < 1) || (c5_i19 > c5_i18)) {
      emlrtDynamicBoundsCheckR2012b(c5_i19, 1, c5_i18, &c5_dg_emlrtBCI,
        (emlrtConstCTX)c5_sp);
    }

    c5_st.site = &c5_dl_emlrtRSI;
    c5_array_real_T_SetSize(chartInstance, &c5_st, &c5_Intensity,
      &c5_bg_emlrtRTEI, c5_stats->vector.data[c5_i19 - 1].PixelValues.size[0]);
    c5_i30 = c5_stats->size[0];
    c5_i31 = (int32_T)c5_f_k;
    if ((c5_i31 < 1) || (c5_i31 > c5_i30)) {
      emlrtDynamicBoundsCheckR2012b(c5_i31, 1, c5_i30, &c5_dg_emlrtBCI,
        (emlrtConstCTX)c5_sp);
    }

    c5_d_loop_ub = c5_stats->vector.data[c5_i31 - 1].PixelValues.size[0] - 1;
    for (c5_i38 = 0; c5_i38 <= c5_d_loop_ub; c5_i38++) {
      c5_i42 = c5_stats->size[0];
      c5_i45 = (int32_T)c5_f_k;
      if ((c5_i45 < 1) || (c5_i45 > c5_i42)) {
        emlrtDynamicBoundsCheckR2012b(c5_i45, 1, c5_i42, &c5_eg_emlrtBCI,
          (emlrtConstCTX)c5_sp);
      }

      c5_Intensity.vector.data[c5_i38] = c5_stats->vector.data[c5_i45 - 1].
        PixelValues.vector.data[c5_i38];
    }

    c5_st.site = &c5_ci_emlrtRSI;
    c5_sumIntensity = c5_sum(chartInstance, &c5_st, &c5_Intensity);
    c5_i47 = c5_stats->size[0];
    c5_i48 = (int32_T)c5_f_k;
    if ((c5_i48 < 1) || (c5_i48 > c5_i47)) {
      emlrtDynamicBoundsCheckR2012b(c5_i48, 1, c5_i47, &c5_of_emlrtBCI,
        (emlrtConstCTX)c5_sp);
    }

    for (c5_n = 0; c5_n < 2; c5_n++) {
      c5_b_n = (real_T)c5_n + 1.0;
      c5_i55 = c5_stats->size[0];
      c5_i57 = (int32_T)c5_f_k;
      if ((c5_i57 < 1) || (c5_i57 > c5_i55)) {
        emlrtDynamicBoundsCheckR2012b(c5_i57, 1, c5_i55, &c5_sf_emlrtBCI,
          (emlrtConstCTX)c5_sp);
      }

      c5_i62 = c5_i57 - 1;
      c5_i64 = c5_stats->vector.data[c5_i62].PixelList.size[0];
      c5_st.site = &c5_bi_emlrtRSI;
      c5_array_real_T_2D_SetSize(chartInstance, &c5_st, &c5_result,
        &c5_cg_emlrtRTEI, c5_i64, 2);
      c5_i67 = c5_stats->size[0];
      c5_i69 = (int32_T)c5_f_k;
      if ((c5_i69 < 1) || (c5_i69 > c5_i67)) {
        emlrtDynamicBoundsCheckR2012b(c5_i69, 1, c5_i67, &c5_sf_emlrtBCI,
          (emlrtConstCTX)c5_sp);
      }

      c5_i72 = c5_i69 - 1;
      c5_i73 = c5_stats->size[0];
      c5_i74 = (int32_T)c5_f_k;
      if ((c5_i74 < 1) || (c5_i74 > c5_i73)) {
        emlrtDynamicBoundsCheckR2012b(c5_i74, 1, c5_i73, &c5_sf_emlrtBCI,
          (emlrtConstCTX)c5_sp);
      }

      c5_r_loop_ub = (c5_stats->vector.data[c5_i72].PixelList.size[0] << 1) - 1;
      for (c5_i77 = 0; c5_i77 <= c5_r_loop_ub; c5_i77++) {
        c5_i80 = c5_stats->size[0];
        c5_i81 = (int32_T)c5_f_k;
        if ((c5_i81 < 1) || (c5_i81 > c5_i80)) {
          emlrtDynamicBoundsCheckR2012b(c5_i81, 1, c5_i80, &c5_sf_emlrtBCI,
            (emlrtConstCTX)c5_sp);
        }

        c5_result.vector.data[c5_i77] = c5_stats->vector.data[c5_i81 - 1].
          PixelList.vector.data[c5_i77];
      }

      c5_c_n = (int32_T)c5_b_n - 1;
      c5_st.site = &c5_bi_emlrtRSI;
      c5_array_real_T_SetSize(chartInstance, &c5_st, &c5_r, &c5_cg_emlrtRTEI,
        c5_result.size[0]);
      c5_v_loop_ub = c5_result.size[0] - 1;
      for (c5_i83 = 0; c5_i83 <= c5_v_loop_ub; c5_i83++) {
        c5_r.vector.data[c5_i83] = c5_result.vector.data[c5_i83 +
          c5_result.size[0] * c5_c_n];
      }

      c5_i85 = c5_r.size[0];
      c5_i86 = c5_Intensity.size[0];
      if ((c5_i85 != c5_i86) && ((c5_i85 != 1) && (c5_i86 != 1))) {
        emlrtDimSizeImpxCheckR2021b(c5_i85, c5_i86, &c5_c_emlrtECI,
          (emlrtConstCTX)c5_sp);
      }

      if (c5_r.size[0] == c5_Intensity.size[0]) {
        c5_st.site = &c5_bi_emlrtRSI;
        c5_array_real_T_SetSize(chartInstance, &c5_st, &c5_r1, &c5_cg_emlrtRTEI,
          c5_r.size[0]);
        c5_ab_loop_ub = c5_r.size[0] - 1;
        for (c5_i89 = 0; c5_i89 <= c5_ab_loop_ub; c5_i89++) {
          c5_r1.vector.data[c5_i89] = c5_r.vector.data[c5_i89] *
            c5_Intensity.vector.data[c5_i89];
        }

        c5_st.site = &c5_bi_emlrtRSI;
        c5_M = c5_sum(chartInstance, &c5_st, &c5_r1);
      } else {
        c5_st.site = &c5_bi_emlrtRSI;
        c5_M = c5_binary_expand_op_1(chartInstance, &c5_st, c5_bi_emlrtRSI,
          &c5_r, &c5_Intensity);
      }

      c5_wc[(int32_T)c5_b_n - 1] = c5_M / c5_sumIntensity;
    }

    for (c5_i53 = 0; c5_i53 < 2; c5_i53++) {
      c5_i56 = c5_stats->size[0];
      c5_i59 = (int32_T)c5_f_k;
      if ((c5_i59 < 1) || (c5_i59 > c5_i56)) {
        emlrtDynamicBoundsCheckR2012b(c5_i59, 1, c5_i56, &c5_uf_emlrtBCI,
          (emlrtConstCTX)c5_sp);
      }

      c5_stats->vector.data[c5_i59 - 1].WeightedCentroid[c5_i53] = c5_wc[c5_i53];
    }
  }

  c5_array_real_T_Destructor(chartInstance, &c5_r1);
  c5_array_real_T_2D_Destructor(chartInstance, &c5_result);
  c5_array_real_T_Destructor(chartInstance, &c5_r);
  c5_array_real_T_Destructor(chartInstance, &c5_Intensity);
}

static void c5_b_sort(SFc5_flightControlSystemInstanceStruct *chartInstance,
                      const emlrtStack *c5_sp, c5_coder_array_real_T_2D *c5_b_x,
                      c5_coder_array_int32_T_2D *c5_idx)
{
  c5_coder_array_int32_T c5_iwork;
  c5_coder_array_real_T c5_xwork;
  emlrtStack c5_b_st;
  emlrtStack c5_c_st;
  emlrtStack c5_d_st;
  emlrtStack c5_e_st;
  emlrtStack c5_st;
  real_T c5_x4[4];
  real_T c5_b_dv[2];
  real_T c5_c_x;
  int32_T c5_idx4[4];
  int32_T c5_perm[4];
  int32_T c5_b_b;
  int32_T c5_b_i1;
  int32_T c5_b_i2;
  int32_T c5_b_i3;
  int32_T c5_b_i4;
  int32_T c5_b_k;
  int32_T c5_b_loop_ub;
  int32_T c5_b_n;
  int32_T c5_b_nNaNs;
  int32_T c5_b_nNonNaN;
  int32_T c5_c_b;
  int32_T c5_c_k;
  int32_T c5_c_n;
  int32_T c5_d_k;
  int32_T c5_e_b;
  int32_T c5_e_k;
  int32_T c5_f_b;
  int32_T c5_f_k;
  int32_T c5_g_b;
  int32_T c5_g_k;
  int32_T c5_h_b;
  int32_T c5_h_k;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i2;
  int32_T c5_i3;
  int32_T c5_i4;
  int32_T c5_i5;
  int32_T c5_i6;
  int32_T c5_i_b;
  int32_T c5_i_k;
  int32_T c5_ib;
  int32_T c5_itmp;
  int32_T c5_j_b;
  int32_T c5_k;
  int32_T c5_k_b;
  int32_T c5_l_b;
  int32_T c5_loop_ub;
  int32_T c5_m;
  int32_T c5_m_b;
  int32_T c5_n;
  int32_T c5_nBlocks;
  int32_T c5_nLastBlock;
  int32_T c5_nNaNs;
  int32_T c5_nNonNaN;
  int32_T c5_n_b;
  int32_T c5_o_b;
  int32_T c5_p_b;
  int32_T c5_preSortLevel;
  int32_T c5_quartetOffset;
  int32_T c5_tailOffset;
  int32_T c5_wOffset;
  boolean_T c5_b;
  boolean_T c5_b_overflow;
  boolean_T c5_c_overflow;
  boolean_T c5_d_b;
  boolean_T c5_d_overflow;
  boolean_T c5_e_overflow;
  boolean_T c5_f_overflow;
  boolean_T c5_overflow;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_st.site = &c5_ri_emlrtRSI;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_c_st.prev = &c5_b_st;
  c5_c_st.tls = c5_b_st.tls;
  c5_d_st.prev = &c5_c_st;
  c5_d_st.tls = c5_c_st.tls;
  c5_e_st.prev = &c5_d_st;
  c5_e_st.tls = c5_d_st.tls;
  for (c5_i = 0; c5_i < 2; c5_i++) {
    c5_b_dv[c5_i] = (real_T)c5_b_x->size[c5_i];
  }

  c5_array_int32_T_2D_SetSize(chartInstance, &c5_st, c5_idx, &c5_dg_emlrtRTEI,
    (int32_T)c5_b_dv[0], 1);
  c5_loop_ub = (int32_T)c5_b_dv[0] - 1;
  for (c5_i1 = 0; c5_i1 <= c5_loop_ub; c5_i1++) {
    c5_idx->vector.data[c5_i1] = 0;
  }

  c5_b = (c5_b_x->size[0] == 0);
  if (!c5_b) {
    c5_b_st.site = &c5_si_emlrtRSI;
    c5_array_int32_T_Constructor(chartInstance, &c5_iwork);
    c5_array_real_T_Constructor(chartInstance, &c5_xwork);
    for (c5_k = 0; c5_k < 1; c5_k++) {
      c5_b_st.site = &c5_ti_emlrtRSI;
      c5_n = c5_b_x->size[0];
      c5_array_int32_T_SetSize(chartInstance, &c5_b_st, &c5_iwork,
        &c5_eg_emlrtRTEI, c5_idx->size[0]);
      c5_b_loop_ub = c5_idx->size[0] - 1;
      for (c5_i2 = 0; c5_i2 <= c5_b_loop_ub; c5_i2++) {
        c5_iwork.vector.data[c5_i2] = 0;
      }

      c5_b_dv[0] = (real_T)c5_b_x->size[0];
      c5_array_real_T_SetSize(chartInstance, &c5_b_st, &c5_xwork,
        &c5_fg_emlrtRTEI, (int32_T)c5_b_dv[0]);
      c5_c_st.site = &c5_ui_emlrtRSI;
      c5_b_n = c5_b_x->size[0];
      for (c5_i3 = 0; c5_i3 < 4; c5_i3++) {
        c5_x4[c5_i3] = 0.0;
      }

      for (c5_i4 = 0; c5_i4 < 4; c5_i4++) {
        c5_idx4[c5_i4] = 0;
      }

      c5_nNaNs = 0;
      c5_ib = 0;
      c5_d_st.site = &c5_bj_emlrtRSI;
      c5_b_b = c5_b_n;
      c5_c_b = c5_b_b;
      if (c5_c_b < 1) {
        c5_overflow = false;
      } else {
        c5_overflow = (c5_c_b > 2147483646);
      }

      if (c5_overflow) {
        c5_e_st.site = &c5_v_emlrtRSI;
        c5_check_forloop_overflow_error(chartInstance, &c5_e_st);
      }

      for (c5_b_k = 0; c5_b_k < c5_b_n; c5_b_k++) {
        c5_c_k = c5_b_k;
        c5_c_x = c5_b_x->vector.data[c5_c_k];
        c5_d_b = muDoubleScalarIsNaN(c5_c_x);
        if (c5_d_b) {
          c5_idx->vector.data[(c5_b_n - c5_nNaNs) - 1] = c5_c_k + 1;
          c5_xwork.vector.data[(c5_b_n - c5_nNaNs) - 1] = c5_b_x->
            vector.data[c5_c_k];
          c5_nNaNs++;
        } else {
          c5_ib++;
          c5_idx4[c5_ib - 1] = c5_c_k + 1;
          c5_x4[c5_ib - 1] = c5_b_x->vector.data[c5_c_k];
          if (c5_ib == 4) {
            c5_quartetOffset = c5_c_k - c5_nNaNs;
            if (c5_x4[0] >= c5_x4[1]) {
              c5_b_i1 = 1;
              c5_b_i2 = 2;
            } else {
              c5_b_i1 = 2;
              c5_b_i2 = 1;
            }

            if (c5_x4[2] >= c5_x4[3]) {
              c5_b_i3 = 3;
              c5_b_i4 = 4;
            } else {
              c5_b_i3 = 4;
              c5_b_i4 = 3;
            }

            if (c5_x4[c5_b_i1 - 1] >= c5_x4[c5_b_i3 - 1]) {
              if (c5_x4[c5_b_i2 - 1] >= c5_x4[c5_b_i3 - 1]) {
                c5_perm[0] = c5_b_i1;
                c5_perm[1] = c5_b_i2;
                c5_perm[2] = c5_b_i3;
                c5_perm[3] = c5_b_i4;
              } else if (c5_x4[c5_b_i2 - 1] >= c5_x4[c5_b_i4 - 1]) {
                c5_perm[0] = c5_b_i1;
                c5_perm[1] = c5_b_i3;
                c5_perm[2] = c5_b_i2;
                c5_perm[3] = c5_b_i4;
              } else {
                c5_perm[0] = c5_b_i1;
                c5_perm[1] = c5_b_i3;
                c5_perm[2] = c5_b_i4;
                c5_perm[3] = c5_b_i2;
              }
            } else if (c5_x4[c5_b_i1 - 1] >= c5_x4[c5_b_i4 - 1]) {
              if (c5_x4[c5_b_i2 - 1] >= c5_x4[c5_b_i4 - 1]) {
                c5_perm[0] = c5_b_i3;
                c5_perm[1] = c5_b_i1;
                c5_perm[2] = c5_b_i2;
                c5_perm[3] = c5_b_i4;
              } else {
                c5_perm[0] = c5_b_i3;
                c5_perm[1] = c5_b_i1;
                c5_perm[2] = c5_b_i4;
                c5_perm[3] = c5_b_i2;
              }
            } else {
              c5_perm[0] = c5_b_i3;
              c5_perm[1] = c5_b_i4;
              c5_perm[2] = c5_b_i1;
              c5_perm[3] = c5_b_i2;
            }

            c5_idx->vector.data[c5_quartetOffset - 3] = c5_idx4[c5_perm[0] - 1];
            c5_idx->vector.data[c5_quartetOffset - 2] = c5_idx4[c5_perm[1] - 1];
            c5_idx->vector.data[c5_quartetOffset - 1] = c5_idx4[c5_perm[2] - 1];
            c5_idx->vector.data[c5_quartetOffset] = c5_idx4[c5_perm[3] - 1];
            c5_b_x->vector.data[c5_quartetOffset - 3] = c5_x4[c5_perm[0] - 1];
            c5_b_x->vector.data[c5_quartetOffset - 2] = c5_x4[c5_perm[1] - 1];
            c5_b_x->vector.data[c5_quartetOffset - 1] = c5_x4[c5_perm[2] - 1];
            c5_b_x->vector.data[c5_quartetOffset] = c5_x4[c5_perm[3] - 1];
            c5_ib = 0;
          }
        }
      }

      c5_wOffset = (c5_b_n - c5_nNaNs) - 1;
      if (c5_ib > 0) {
        c5_c_n = c5_ib;
        for (c5_i5 = 0; c5_i5 < 4; c5_i5++) {
          c5_perm[c5_i5] = 0;
        }

        if (c5_c_n == 1) {
          c5_perm[0] = 1;
        } else if (c5_c_n == 2) {
          if (c5_x4[0] >= c5_x4[1]) {
            c5_perm[0] = 1;
            c5_perm[1] = 2;
          } else {
            c5_perm[0] = 2;
            c5_perm[1] = 1;
          }
        } else if (c5_x4[0] >= c5_x4[1]) {
          if (c5_x4[1] >= c5_x4[2]) {
            c5_perm[0] = 1;
            c5_perm[1] = 2;
            c5_perm[2] = 3;
          } else if (c5_x4[0] >= c5_x4[2]) {
            c5_perm[0] = 1;
            c5_perm[1] = 3;
            c5_perm[2] = 2;
          } else {
            c5_perm[0] = 3;
            c5_perm[1] = 1;
            c5_perm[2] = 2;
          }
        } else if (c5_x4[0] >= c5_x4[2]) {
          c5_perm[0] = 2;
          c5_perm[1] = 1;
          c5_perm[2] = 3;
        } else if (c5_x4[1] >= c5_x4[2]) {
          c5_perm[0] = 2;
          c5_perm[1] = 3;
          c5_perm[2] = 1;
        } else {
          c5_perm[0] = 3;
          c5_perm[1] = 2;
          c5_perm[2] = 1;
        }

        c5_d_st.site = &c5_cj_emlrtRSI;
        c5_g_b = c5_ib;
        c5_h_b = c5_g_b;
        if (c5_h_b < 1) {
          c5_c_overflow = false;
        } else {
          c5_c_overflow = (c5_h_b > 2147483646);
        }

        if (c5_c_overflow) {
          c5_e_st.site = &c5_v_emlrtRSI;
          c5_check_forloop_overflow_error(chartInstance, &c5_e_st);
        }

        c5_i6 = (uint8_T)c5_ib - 1;
        for (c5_e_k = 0; c5_e_k <= c5_i6; c5_e_k++) {
          c5_c_k = c5_e_k;
          c5_idx->vector.data[((c5_wOffset - c5_ib) + c5_c_k) + 1] =
            c5_idx4[c5_perm[c5_c_k] - 1];
          c5_b_x->vector.data[((c5_wOffset - c5_ib) + c5_c_k) + 1] =
            c5_x4[c5_perm[c5_c_k] - 1];
        }
      }

      c5_m = c5_nNaNs >> 1;
      c5_d_st.site = &c5_dj_emlrtRSI;
      c5_e_b = c5_m;
      c5_f_b = c5_e_b;
      if (c5_f_b < 1) {
        c5_b_overflow = false;
      } else {
        c5_b_overflow = (c5_f_b > 2147483646);
      }

      if (c5_b_overflow) {
        c5_e_st.site = &c5_v_emlrtRSI;
        c5_check_forloop_overflow_error(chartInstance, &c5_e_st);
      }

      for (c5_d_k = 0; c5_d_k < c5_m; c5_d_k++) {
        c5_c_k = c5_d_k + 1;
        c5_itmp = c5_idx->vector.data[c5_wOffset + c5_c_k];
        c5_idx->vector.data[c5_wOffset + c5_c_k] = c5_idx->vector.data[c5_b_n -
          c5_c_k];
        c5_idx->vector.data[c5_b_n - c5_c_k] = c5_itmp;
        c5_b_x->vector.data[c5_wOffset + c5_c_k] = c5_xwork.vector.data[c5_b_n -
          c5_c_k];
        c5_b_x->vector.data[c5_b_n - c5_c_k] = c5_xwork.vector.data[c5_wOffset +
          c5_c_k];
      }

      if ((c5_nNaNs & 1) != 0) {
        c5_b_x->vector.data[(c5_wOffset + c5_m) + 1] = c5_xwork.vector.data
          [(c5_wOffset + c5_m) + 1];
      }

      c5_nNonNaN = c5_n - c5_nNaNs;
      c5_preSortLevel = 2;
      if (c5_nNonNaN > 1) {
        if (c5_n >= 256) {
          c5_nBlocks = c5_nNonNaN >> 8;
          if (c5_nBlocks > 0) {
            c5_c_st.site = &c5_vi_emlrtRSI;
            c5_i_b = c5_nBlocks;
            c5_j_b = c5_i_b;
            if (c5_j_b < 1) {
              c5_d_overflow = false;
            } else {
              c5_d_overflow = (c5_j_b > 2147483646);
            }

            if (c5_d_overflow) {
              c5_d_st.site = &c5_v_emlrtRSI;
              c5_check_forloop_overflow_error(chartInstance, &c5_d_st);
            }

            for (c5_m_b = 0; c5_m_b < c5_nBlocks; c5_m_b++) {
              c5_n_b = c5_m_b;
              c5_c_st.site = &c5_wi_emlrtRSI;
              c5_b_merge_pow2_block(chartInstance, &c5_c_st, c5_idx, c5_b_x,
                                    c5_n_b << 8);
            }

            c5_tailOffset = c5_nBlocks << 8;
            c5_nLastBlock = c5_nNonNaN - c5_tailOffset;
            if (c5_nLastBlock > 0) {
              c5_c_st.site = &c5_xi_emlrtRSI;
              c5_b_merge_block(chartInstance, &c5_c_st, c5_idx, c5_b_x,
                               c5_tailOffset, c5_nLastBlock, 2, &c5_iwork,
                               &c5_xwork);
            }

            c5_preSortLevel = 8;
          }
        }

        c5_c_st.site = &c5_yi_emlrtRSI;
        c5_b_merge_block(chartInstance, &c5_c_st, c5_idx, c5_b_x, 0, c5_nNonNaN,
                         c5_preSortLevel, &c5_iwork, &c5_xwork);
      }

      if ((c5_nNaNs > 0) && (c5_nNonNaN > 0)) {
        c5_c_st.site = &c5_aj_emlrtRSI;
        c5_b_nNonNaN = c5_nNonNaN - 1;
        c5_b_nNaNs = c5_nNaNs - 1;
        c5_d_st.site = &c5_nj_emlrtRSI;
        c5_k_b = c5_b_nNaNs + 1;
        c5_l_b = c5_k_b;
        if (c5_l_b < 1) {
          c5_e_overflow = false;
        } else {
          c5_e_overflow = (c5_l_b > 2147483646);
        }

        if (c5_e_overflow) {
          c5_e_st.site = &c5_v_emlrtRSI;
          c5_check_forloop_overflow_error(chartInstance, &c5_e_st);
        }

        for (c5_f_k = 0; c5_f_k <= c5_b_nNaNs; c5_f_k++) {
          c5_h_k = c5_f_k;
          c5_xwork.vector.data[c5_h_k] = c5_b_x->vector.data[(c5_b_nNonNaN +
            c5_h_k) + 1];
          c5_iwork.vector.data[c5_h_k] = c5_idx->vector.data[(c5_b_nNonNaN +
            c5_h_k) + 1];
        }

        for (c5_g_k = c5_b_nNonNaN + 1; c5_g_k >= 1; c5_g_k--) {
          c5_b_x->vector.data[c5_b_nNaNs + c5_g_k] = c5_b_x->vector.data[c5_g_k
            - 1];
          c5_idx->vector.data[c5_b_nNaNs + c5_g_k] = c5_idx->vector.data[c5_g_k
            - 1];
        }

        c5_d_st.site = &c5_oj_emlrtRSI;
        c5_o_b = c5_b_nNaNs + 1;
        c5_p_b = c5_o_b;
        if (c5_p_b < 1) {
          c5_f_overflow = false;
        } else {
          c5_f_overflow = (c5_p_b > 2147483646);
        }

        if (c5_f_overflow) {
          c5_e_st.site = &c5_v_emlrtRSI;
          c5_check_forloop_overflow_error(chartInstance, &c5_e_st);
        }

        for (c5_i_k = 0; c5_i_k <= c5_b_nNaNs; c5_i_k++) {
          c5_h_k = c5_i_k;
          c5_b_x->vector.data[c5_h_k] = c5_xwork.vector.data[c5_h_k];
          c5_idx->vector.data[c5_h_k] = c5_iwork.vector.data[c5_h_k];
        }
      }
    }

    c5_array_real_T_Destructor(chartInstance, &c5_xwork);
    c5_array_int32_T_Destructor(chartInstance, &c5_iwork);
  }
}

static void c5_b_merge_pow2_block(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_int32_T_2D *c5_idx,
  c5_coder_array_real_T_2D *c5_b_x, int32_T c5_offset)
{
  emlrtStack c5_b_st;
  emlrtStack c5_st;
  real_T c5_xwork[256];
  int32_T c5_iwork[256];
  int32_T c5_b;
  int32_T c5_bLen;
  int32_T c5_bLen2;
  int32_T c5_b_b;
  int32_T c5_b_j;
  int32_T c5_b_k;
  int32_T c5_blockOffset;
  int32_T c5_c_a;
  int32_T c5_c_b;
  int32_T c5_c_j;
  int32_T c5_d_a;
  int32_T c5_d_b;
  int32_T c5_e_b;
  int32_T c5_exitg1;
  int32_T c5_f_b;
  int32_T c5_g_b;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_iout;
  int32_T c5_j;
  int32_T c5_k;
  int32_T c5_nPairs;
  int32_T c5_offset1;
  int32_T c5_p;
  int32_T c5_q;
  boolean_T c5_b_overflow;
  boolean_T c5_c_overflow;
  boolean_T c5_overflow;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  for (c5_b = 0; c5_b < 6; c5_b++) {
    c5_bLen = 1 << (c5_b + 2);
    c5_bLen2 = c5_bLen << 1;
    c5_nPairs = 256 >> (c5_b + 3);
    c5_st.site = &c5_ej_emlrtRSI;
    c5_b_b = c5_nPairs;
    c5_c_b = c5_b_b;
    if (c5_c_b < 1) {
      c5_overflow = false;
    } else {
      c5_overflow = (c5_c_b > 2147483646);
    }

    if (c5_overflow) {
      c5_b_st.site = &c5_v_emlrtRSI;
      c5_check_forloop_overflow_error(chartInstance, &c5_b_st);
    }

    c5_i = (uint8_T)c5_nPairs - 1;
    for (c5_k = 0; c5_k <= c5_i; c5_k++) {
      c5_b_k = c5_k;
      c5_blockOffset = (c5_offset + c5_b_k * c5_bLen2) - 1;
      c5_st.site = &c5_fj_emlrtRSI;
      c5_d_b = c5_bLen2;
      c5_e_b = c5_d_b;
      if (c5_e_b < 1) {
        c5_b_overflow = false;
      } else {
        c5_b_overflow = (c5_e_b > 2147483646);
      }

      if (c5_b_overflow) {
        c5_b_st.site = &c5_v_emlrtRSI;
        c5_check_forloop_overflow_error(chartInstance, &c5_b_st);
      }

      c5_i1 = (uint16_T)c5_bLen2 - 1;
      for (c5_j = 0; c5_j <= c5_i1; c5_j++) {
        c5_b_j = c5_j;
        c5_iwork[c5_b_j] = c5_idx->vector.data[(c5_blockOffset + c5_b_j) + 1];
        c5_xwork[c5_b_j] = c5_b_x->vector.data[(c5_blockOffset + c5_b_j) + 1];
      }

      c5_p = 0;
      c5_q = c5_bLen;
      c5_iout = c5_blockOffset;
      do {
        c5_exitg1 = 0;
        c5_iout++;
        if (c5_xwork[c5_p] >= c5_xwork[c5_q]) {
          c5_idx->vector.data[c5_iout] = c5_iwork[c5_p];
          c5_b_x->vector.data[c5_iout] = c5_xwork[c5_p];
          if (c5_p + 1 < c5_bLen) {
            c5_p++;
          } else {
            c5_exitg1 = 1;
          }
        } else {
          c5_idx->vector.data[c5_iout] = c5_iwork[c5_q];
          c5_b_x->vector.data[c5_iout] = c5_xwork[c5_q];
          if (c5_q + 1 < c5_bLen2) {
            c5_q++;
          } else {
            c5_offset1 = c5_iout - c5_p;
            c5_st.site = &c5_gj_emlrtRSI;
            c5_c_a = c5_p + 1;
            c5_f_b = c5_bLen;
            c5_d_a = c5_c_a;
            c5_g_b = c5_f_b;
            if (c5_d_a > c5_g_b) {
              c5_c_overflow = false;
            } else {
              c5_c_overflow = (c5_g_b > 2147483646);
            }

            if (c5_c_overflow) {
              c5_b_st.site = &c5_v_emlrtRSI;
              c5_check_forloop_overflow_error(chartInstance, &c5_b_st);
            }

            for (c5_c_j = c5_p + 1; c5_c_j <= c5_bLen; c5_c_j++) {
              c5_idx->vector.data[c5_offset1 + c5_c_j] = c5_iwork[c5_c_j - 1];
              c5_b_x->vector.data[c5_offset1 + c5_c_j] = c5_xwork[c5_c_j - 1];
            }

            c5_exitg1 = 1;
          }
        }
      } while (c5_exitg1 == 0);
    }
  }
}

static void c5_b_merge_block(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_int32_T_2D *c5_idx,
  c5_coder_array_real_T_2D *c5_b_x, int32_T c5_offset, int32_T c5_n, int32_T
  c5_preSortLevel, c5_coder_array_int32_T *c5_iwork, c5_coder_array_real_T
  *c5_xwork)
{
  emlrtStack c5_b_st;
  emlrtStack c5_st;
  int32_T c5_b;
  int32_T c5_bLen;
  int32_T c5_bLen2;
  int32_T c5_b_b;
  int32_T c5_b_k;
  int32_T c5_k;
  int32_T c5_nBlocks;
  int32_T c5_nPairs;
  int32_T c5_nTail;
  int32_T c5_tailOffset;
  boolean_T c5_overflow;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_nBlocks = c5_n >> c5_preSortLevel;
  c5_bLen = 1 << c5_preSortLevel;
  while (c5_nBlocks > 1) {
    if ((c5_nBlocks & 1) != 0) {
      c5_nBlocks--;
      c5_tailOffset = c5_bLen * c5_nBlocks;
      c5_nTail = c5_n - c5_tailOffset;
      if (c5_nTail > c5_bLen) {
        c5_st.site = &c5_hj_emlrtRSI;
        c5_b_merge(chartInstance, &c5_st, c5_idx, c5_b_x, c5_offset +
                   c5_tailOffset, c5_bLen, c5_nTail - c5_bLen, c5_iwork,
                   c5_xwork);
      }
    }

    c5_bLen2 = c5_bLen << 1;
    c5_nPairs = c5_nBlocks >> 1;
    c5_st.site = &c5_ij_emlrtRSI;
    c5_b = c5_nPairs;
    c5_b_b = c5_b;
    if (c5_b_b < 1) {
      c5_overflow = false;
    } else {
      c5_overflow = (c5_b_b > 2147483646);
    }

    if (c5_overflow) {
      c5_b_st.site = &c5_v_emlrtRSI;
      c5_check_forloop_overflow_error(chartInstance, &c5_b_st);
    }

    for (c5_k = 0; c5_k < c5_nPairs; c5_k++) {
      c5_b_k = c5_k;
      c5_st.site = &c5_jj_emlrtRSI;
      c5_b_merge(chartInstance, &c5_st, c5_idx, c5_b_x, c5_offset + c5_b_k *
                 c5_bLen2, c5_bLen, c5_bLen, c5_iwork, c5_xwork);
    }

    c5_bLen = c5_bLen2;
    c5_nBlocks = c5_nPairs;
  }

  if (c5_n > c5_bLen) {
    c5_st.site = &c5_kj_emlrtRSI;
    c5_b_merge(chartInstance, &c5_st, c5_idx, c5_b_x, c5_offset, c5_bLen, c5_n -
               c5_bLen, c5_iwork, c5_xwork);
  }
}

static void c5_b_merge(SFc5_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c5_sp, c5_coder_array_int32_T_2D *c5_idx,
  c5_coder_array_real_T_2D *c5_b_x, int32_T c5_offset, int32_T c5_np, int32_T
  c5_nq, c5_coder_array_int32_T *c5_iwork, c5_coder_array_real_T *c5_xwork)
{
  emlrtStack c5_b_st;
  emlrtStack c5_st;
  int32_T c5_b;
  int32_T c5_b_b;
  int32_T c5_b_j;
  int32_T c5_c_a;
  int32_T c5_c_b;
  int32_T c5_c_j;
  int32_T c5_d_a;
  int32_T c5_d_b;
  int32_T c5_exitg1;
  int32_T c5_iout;
  int32_T c5_j;
  int32_T c5_n;
  int32_T c5_offset1;
  int32_T c5_p;
  int32_T c5_q;
  int32_T c5_qend;
  boolean_T c5_b_overflow;
  boolean_T c5_overflow;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  if (c5_nq != 0) {
    c5_n = c5_np + c5_nq;
    c5_st.site = &c5_mj_emlrtRSI;
    c5_b = c5_n;
    c5_b_b = c5_b;
    if (c5_b_b < 1) {
      c5_overflow = false;
    } else {
      c5_overflow = (c5_b_b > 2147483646);
    }

    if (c5_overflow) {
      c5_b_st.site = &c5_v_emlrtRSI;
      c5_check_forloop_overflow_error(chartInstance, &c5_b_st);
    }

    for (c5_j = 0; c5_j < c5_n; c5_j++) {
      c5_b_j = c5_j;
      c5_iwork->vector.data[c5_b_j] = c5_idx->vector.data[c5_offset + c5_b_j];
      c5_xwork->vector.data[c5_b_j] = c5_b_x->vector.data[c5_offset + c5_b_j];
    }

    c5_p = 0;
    c5_q = c5_np;
    c5_qend = c5_np + c5_nq;
    c5_iout = c5_offset - 1;
    do {
      c5_exitg1 = 0;
      c5_iout++;
      if (c5_xwork->vector.data[c5_p] >= c5_xwork->vector.data[c5_q]) {
        c5_idx->vector.data[c5_iout] = c5_iwork->vector.data[c5_p];
        c5_b_x->vector.data[c5_iout] = c5_xwork->vector.data[c5_p];
        if (c5_p + 1 < c5_np) {
          c5_p++;
        } else {
          c5_exitg1 = 1;
        }
      } else {
        c5_idx->vector.data[c5_iout] = c5_iwork->vector.data[c5_q];
        c5_b_x->vector.data[c5_iout] = c5_xwork->vector.data[c5_q];
        if (c5_q + 1 < c5_qend) {
          c5_q++;
        } else {
          c5_offset1 = c5_iout - c5_p;
          c5_st.site = &c5_lj_emlrtRSI;
          c5_c_a = c5_p + 1;
          c5_c_b = c5_np;
          c5_d_a = c5_c_a;
          c5_d_b = c5_c_b;
          if (c5_d_a > c5_d_b) {
            c5_b_overflow = false;
          } else {
            c5_b_overflow = (c5_d_b > 2147483646);
          }

          if (c5_b_overflow) {
            c5_b_st.site = &c5_v_emlrtRSI;
            c5_check_forloop_overflow_error(chartInstance, &c5_b_st);
          }

          for (c5_c_j = c5_p + 1; c5_c_j <= c5_np; c5_c_j++) {
            c5_idx->vector.data[c5_offset1 + c5_c_j] = c5_iwork->
              vector.data[c5_c_j - 1];
            c5_b_x->vector.data[c5_offset1 + c5_c_j] = c5_xwork->
              vector.data[c5_c_j - 1];
          }

          c5_exitg1 = 1;
        }
      }
    } while (c5_exitg1 == 0);
  }
}

static void c5_binary_expand_op(SFc5_flightControlSystemInstanceStruct
  *chartInstance, creal_T c5_in1_data[], int32_T c5_in1_size[2], real_T
  c5_in2_data[], int32_T c5_in2_size[2])
{
  creal_T c5_b_in1_data[81];
  real_T c5_ai;
  real_T c5_ar;
  real_T c5_b_s;
  real_T c5_bi;
  real_T c5_bim;
  real_T c5_br;
  real_T c5_brm;
  real_T c5_d;
  real_T c5_ni;
  real_T c5_nr;
  real_T c5_sgnbi;
  real_T c5_sgnbr;
  int32_T c5_b_in1_size[2];
  int32_T c5_aux_0_1;
  int32_T c5_aux_1_1;
  int32_T c5_b_loop_ub;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i2;
  int32_T c5_loop_ub;
  int32_T c5_stride_0_1;
  int32_T c5_stride_1_1;
  (void)chartInstance;
  if (c5_in2_size[1] == 1) {
    c5_b_in1_size[1] = c5_in1_size[1];
  } else {
    c5_b_in1_size[1] = c5_in2_size[1];
  }

  c5_stride_0_1 = (c5_in1_size[1] != 1);
  c5_stride_1_1 = (c5_in2_size[1] != 1);
  c5_aux_0_1 = 0;
  c5_aux_1_1 = 0;
  if (c5_in2_size[1] == 1) {
    c5_i = c5_in1_size[1];
  } else {
    c5_i = c5_in2_size[1];
  }

  c5_loop_ub = c5_i - 1;
  for (c5_i1 = 0; c5_i1 <= c5_loop_ub; c5_i1++) {
    c5_ar = c5_in1_data[c5_aux_0_1].re;
    c5_ai = c5_in1_data[c5_aux_0_1].im;
    c5_br = c5_in2_data[c5_aux_1_1];
    c5_bi = 0.0;
    if (c5_bi == 0.0) {
      if (c5_ai == 0.0) {
        c5_b_in1_data[c5_i1].re = c5_ar / c5_br;
        c5_b_in1_data[c5_i1].im = 0.0;
      } else if (c5_ar == 0.0) {
        c5_b_in1_data[c5_i1].re = 0.0;
        c5_b_in1_data[c5_i1].im = c5_ai / c5_br;
      } else {
        c5_b_in1_data[c5_i1].re = c5_ar / c5_br;
        c5_b_in1_data[c5_i1].im = c5_ai / c5_br;
      }
    } else if (c5_br == 0.0) {
      if (c5_ar == 0.0) {
        c5_b_in1_data[c5_i1].re = c5_ai / c5_bi;
        c5_b_in1_data[c5_i1].im = 0.0;
      } else if (c5_ai == 0.0) {
        c5_b_in1_data[c5_i1].re = 0.0;
        c5_b_in1_data[c5_i1].im = -(c5_ar / c5_bi);
      } else {
        c5_b_in1_data[c5_i1].re = c5_ai / c5_bi;
        c5_b_in1_data[c5_i1].im = -(c5_ar / c5_bi);
      }
    } else {
      c5_brm = muDoubleScalarAbs(c5_br);
      c5_bim = muDoubleScalarAbs(c5_bi);
      if (c5_brm > c5_bim) {
        c5_b_s = c5_bi / c5_br;
        c5_d = c5_br + c5_b_s * c5_bi;
        c5_nr = c5_ar + c5_b_s * c5_ai;
        c5_ni = c5_ai - c5_b_s * c5_ar;
        c5_b_in1_data[c5_i1].re = c5_nr / c5_d;
        c5_b_in1_data[c5_i1].im = c5_ni / c5_d;
      } else if (c5_bim == c5_brm) {
        if (c5_br > 0.0) {
          c5_sgnbr = 0.5;
        } else {
          c5_sgnbr = -0.5;
        }

        if (c5_bi > 0.0) {
          c5_sgnbi = 0.5;
        } else {
          c5_sgnbi = -0.5;
        }

        c5_nr = c5_ar * c5_sgnbr + c5_ai * c5_sgnbi;
        c5_ni = c5_ai * c5_sgnbr - c5_ar * c5_sgnbi;
        c5_b_in1_data[c5_i1].re = c5_nr / c5_brm;
        c5_b_in1_data[c5_i1].im = c5_ni / c5_brm;
      } else {
        c5_b_s = c5_br / c5_bi;
        c5_d = c5_bi + c5_b_s * c5_br;
        c5_nr = c5_b_s * c5_ar + c5_ai;
        c5_ni = c5_b_s * c5_ai - c5_ar;
        c5_b_in1_data[c5_i1].re = c5_nr / c5_d;
        c5_b_in1_data[c5_i1].im = c5_ni / c5_d;
      }
    }

    c5_aux_1_1 += c5_stride_1_1;
    c5_aux_0_1 += c5_stride_0_1;
  }

  c5_in1_size[0] = 1;
  c5_in1_size[1] = c5_b_in1_size[1];
  c5_b_loop_ub = c5_b_in1_size[1] - 1;
  for (c5_i2 = 0; c5_i2 <= c5_b_loop_ub; c5_i2++) {
    c5_in1_data[c5_i2] = c5_b_in1_data[c5_i2];
  }
}

static real_T c5_binary_expand_op_1(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, emlrtRSInfo c5_in1,
  c5_coder_array_real_T *c5_in2, c5_coder_array_real_T *c5_in3)
{
  c5_coder_array_real_T c5_b_in2;
  emlrtStack c5_st;
  real_T c5_out1;
  int32_T c5_aux_0_0;
  int32_T c5_aux_1_0;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i2;
  int32_T c5_loop_ub;
  int32_T c5_stride_0_0;
  int32_T c5_stride_1_0;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_array_real_T_Constructor(chartInstance, &c5_b_in2);
  c5_st.site = &c5_bi_emlrtRSI;
  if (c5_in3->size[0] == 1) {
    c5_i = c5_in2->size[0];
  } else {
    c5_i = c5_in3->size[0];
  }

  c5_array_real_T_SetSize(chartInstance, &c5_st, &c5_b_in2, &c5_cg_emlrtRTEI,
    c5_i);
  c5_stride_0_0 = (c5_in2->size[0] != 1);
  c5_stride_1_0 = (c5_in3->size[0] != 1);
  c5_aux_0_0 = 0;
  c5_aux_1_0 = 0;
  if (c5_in3->size[0] == 1) {
    c5_i1 = c5_in2->size[0];
  } else {
    c5_i1 = c5_in3->size[0];
  }

  c5_loop_ub = c5_i1 - 1;
  for (c5_i2 = 0; c5_i2 <= c5_loop_ub; c5_i2++) {
    c5_b_in2.vector.data[c5_i2] = c5_in2->vector.data[c5_aux_0_0] *
      c5_in3->vector.data[c5_aux_1_0];
    c5_aux_1_0 += c5_stride_1_0;
    c5_aux_0_0 += c5_stride_0_0;
  }

  c5_st.site = &c5_in1;
  c5_out1 = c5_sum(chartInstance, &c5_st, &c5_b_in2);
  c5_array_real_T_Destructor(chartInstance, &c5_b_in2);
  return c5_out1;
}

static void c5_array_real_T_2D_SetSize(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_real_T_2D
  *c5_coderArray, const emlrtRTEInfo *c5_srcLocation, int32_T c5_size0, int32_T
  c5_size1)
{
  real_T *c5_newData;
  int32_T c5_newCapacity;
  int32_T c5_newNumel;
  (void)chartInstance;
  c5_coderArray->size[0] = c5_size0;
  c5_coderArray->size[1] = c5_size1;
  c5_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)(int32_T)
    emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)c5_coderArray->size[0],
                       c5_srcLocation, (void *)c5_sp), (size_t)(uint32_T)
    c5_coderArray->size[1], c5_srcLocation, (void *)c5_sp);
  if (c5_newNumel > c5_coderArray->vector.allocated) {
    c5_newCapacity = c5_coderArray->vector.allocated;
    if (c5_newCapacity < 16) {
      c5_newCapacity = 16;
    }

    while (c5_newCapacity < c5_newNumel) {
      if (c5_newCapacity > 1073741823) {
        c5_newCapacity = MAX_int32_T;
      } else {
        c5_newCapacity <<= 1;
      }
    }

    c5_newData = (real_T *)emlrtMallocMex(sizeof(real_T) * (uint32_T)
      c5_newCapacity);
    if ((void *)c5_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c5_srcLocation, (void *)c5_sp);
    }

    if ((void *)c5_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c5_srcLocation, (void *)c5_sp);
    }

    if (c5_coderArray->vector.data != NULL) {
      memcpy(c5_newData, c5_coderArray->vector.data, sizeof(real_T) * (uint32_T)
             c5_coderArray->vector.numel);
      if (c5_coderArray->vector.owner) {
        emlrtFreeMex(c5_coderArray->vector.data);
      }
    }

    c5_coderArray->vector.data = c5_newData;
    c5_coderArray->vector.allocated = c5_newCapacity;
    c5_coderArray->vector.owner = true;
  }

  c5_coderArray->vector.numel = c5_newNumel;
}

static void c5_array_creal_T_SetSize(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_creal_T *c5_coderArray,
  const emlrtRTEInfo *c5_srcLocation, int32_T c5_size0)
{
  creal_T *c5_newData;
  int32_T c5_newCapacity;
  int32_T c5_newNumel;
  (void)chartInstance;
  c5_coderArray->size[0] = c5_size0;
  c5_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)
    c5_coderArray->size[0], c5_srcLocation, (void *)c5_sp);
  if (c5_newNumel > c5_coderArray->vector.allocated) {
    c5_newCapacity = c5_coderArray->vector.allocated;
    if (c5_newCapacity < 16) {
      c5_newCapacity = 16;
    }

    while (c5_newCapacity < c5_newNumel) {
      if (c5_newCapacity > 1073741823) {
        c5_newCapacity = MAX_int32_T;
      } else {
        c5_newCapacity <<= 1;
      }
    }

    c5_newData = (creal_T *)emlrtMallocMex(sizeof(creal_T) * (uint32_T)
      c5_newCapacity);
    if ((void *)c5_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c5_srcLocation, (void *)c5_sp);
    }

    if ((void *)c5_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c5_srcLocation, (void *)c5_sp);
    }

    if (c5_coderArray->vector.data != NULL) {
      memcpy(c5_newData, c5_coderArray->vector.data, sizeof(creal_T) * (uint32_T)
             c5_coderArray->vector.numel);
      if (c5_coderArray->vector.owner) {
        emlrtFreeMex(c5_coderArray->vector.data);
      }
    }

    c5_coderArray->vector.data = c5_newData;
    c5_coderArray->vector.allocated = c5_newCapacity;
    c5_coderArray->vector.owner = true;
  }

  c5_coderArray->vector.numel = c5_newNumel;
}

static void c5_array_boolean_T_2D_SetSize(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_boolean_T_2D
  *c5_coderArray, const emlrtRTEInfo *c5_srcLocation, int32_T c5_size0, int32_T
  c5_size1)
{
  int32_T c5_newCapacity;
  int32_T c5_newNumel;
  boolean_T *c5_newData;
  (void)chartInstance;
  c5_coderArray->size[0] = c5_size0;
  c5_coderArray->size[1] = c5_size1;
  c5_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)(int32_T)
    emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)c5_coderArray->size[0],
                       c5_srcLocation, (void *)c5_sp), (size_t)(uint32_T)
    c5_coderArray->size[1], c5_srcLocation, (void *)c5_sp);
  if (c5_newNumel > c5_coderArray->vector.allocated) {
    c5_newCapacity = c5_coderArray->vector.allocated;
    if (c5_newCapacity < 16) {
      c5_newCapacity = 16;
    }

    while (c5_newCapacity < c5_newNumel) {
      if (c5_newCapacity > 1073741823) {
        c5_newCapacity = MAX_int32_T;
      } else {
        c5_newCapacity <<= 1;
      }
    }

    c5_newData = (boolean_T *)emlrtMallocMex(sizeof(boolean_T) * (uint32_T)
      c5_newCapacity);
    if ((void *)c5_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c5_srcLocation, (void *)c5_sp);
    }

    if ((void *)c5_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c5_srcLocation, (void *)c5_sp);
    }

    if (c5_coderArray->vector.data != NULL) {
      memcpy(c5_newData, c5_coderArray->vector.data, sizeof(boolean_T)
             * (uint32_T)c5_coderArray->vector.numel);
      if (c5_coderArray->vector.owner) {
        emlrtFreeMex(c5_coderArray->vector.data);
      }
    }

    c5_coderArray->vector.data = c5_newData;
    c5_coderArray->vector.allocated = c5_newCapacity;
    c5_coderArray->vector.owner = true;
  }

  c5_coderArray->vector.numel = c5_newNumel;
}

static void c5_array_int32_T_SetSize(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_int32_T *c5_coderArray,
  const emlrtRTEInfo *c5_srcLocation, int32_T c5_size0)
{
  int32_T c5_newCapacity;
  int32_T c5_newNumel;
  int32_T *c5_newData;
  (void)chartInstance;
  c5_coderArray->size[0] = c5_size0;
  c5_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)
    c5_coderArray->size[0], c5_srcLocation, (void *)c5_sp);
  if (c5_newNumel > c5_coderArray->vector.allocated) {
    c5_newCapacity = c5_coderArray->vector.allocated;
    if (c5_newCapacity < 16) {
      c5_newCapacity = 16;
    }

    while (c5_newCapacity < c5_newNumel) {
      if (c5_newCapacity > 1073741823) {
        c5_newCapacity = MAX_int32_T;
      } else {
        c5_newCapacity <<= 1;
      }
    }

    c5_newData = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
      c5_newCapacity);
    if ((void *)c5_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c5_srcLocation, (void *)c5_sp);
    }

    if ((void *)c5_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c5_srcLocation, (void *)c5_sp);
    }

    if (c5_coderArray->vector.data != NULL) {
      memcpy(c5_newData, c5_coderArray->vector.data, sizeof(int32_T) * (uint32_T)
             c5_coderArray->vector.numel);
      if (c5_coderArray->vector.owner) {
        emlrtFreeMex(c5_coderArray->vector.data);
      }
    }

    c5_coderArray->vector.data = c5_newData;
    c5_coderArray->vector.allocated = c5_newCapacity;
    c5_coderArray->vector.owner = true;
  }

  c5_coderArray->vector.numel = c5_newNumel;
}

static void c5_array_real_T_SetSize(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_real_T *c5_coderArray,
  const emlrtRTEInfo *c5_srcLocation, int32_T c5_size0)
{
  real_T *c5_newData;
  int32_T c5_newCapacity;
  int32_T c5_newNumel;
  (void)chartInstance;
  c5_coderArray->size[0] = c5_size0;
  c5_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)
    c5_coderArray->size[0], c5_srcLocation, (void *)c5_sp);
  if (c5_newNumel > c5_coderArray->vector.allocated) {
    c5_newCapacity = c5_coderArray->vector.allocated;
    if (c5_newCapacity < 16) {
      c5_newCapacity = 16;
    }

    while (c5_newCapacity < c5_newNumel) {
      if (c5_newCapacity > 1073741823) {
        c5_newCapacity = MAX_int32_T;
      } else {
        c5_newCapacity <<= 1;
      }
    }

    c5_newData = (real_T *)emlrtMallocMex(sizeof(real_T) * (uint32_T)
      c5_newCapacity);
    if ((void *)c5_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c5_srcLocation, (void *)c5_sp);
    }

    if ((void *)c5_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c5_srcLocation, (void *)c5_sp);
    }

    if (c5_coderArray->vector.data != NULL) {
      memcpy(c5_newData, c5_coderArray->vector.data, sizeof(real_T) * (uint32_T)
             c5_coderArray->vector.numel);
      if (c5_coderArray->vector.owner) {
        emlrtFreeMex(c5_coderArray->vector.data);
      }
    }

    c5_coderArray->vector.data = c5_newData;
    c5_coderArray->vector.allocated = c5_newCapacity;
    c5_coderArray->vector.owner = true;
  }

  c5_coderArray->vector.numel = c5_newNumel;
}

static void c5_array_real32_T_2D_SetSize(SFc5_flightControlSystemInstanceStruct *
  chartInstance, const emlrtStack *c5_sp, c5_coder_array_real32_T_2D
  *c5_coderArray, const emlrtRTEInfo *c5_srcLocation, int32_T c5_size0, int32_T
  c5_size1)
{
  int32_T c5_newCapacity;
  int32_T c5_newNumel;
  real32_T *c5_newData;
  (void)chartInstance;
  c5_coderArray->size[0] = c5_size0;
  c5_coderArray->size[1] = c5_size1;
  c5_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)(int32_T)
    emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)c5_coderArray->size[0],
                       c5_srcLocation, (void *)c5_sp), (size_t)(uint32_T)
    c5_coderArray->size[1], c5_srcLocation, (void *)c5_sp);
  if (c5_newNumel > c5_coderArray->vector.allocated) {
    c5_newCapacity = c5_coderArray->vector.allocated;
    if (c5_newCapacity < 16) {
      c5_newCapacity = 16;
    }

    while (c5_newCapacity < c5_newNumel) {
      if (c5_newCapacity > 1073741823) {
        c5_newCapacity = MAX_int32_T;
      } else {
        c5_newCapacity <<= 1;
      }
    }

    c5_newData = (real32_T *)emlrtMallocMex(sizeof(real32_T) * (uint32_T)
      c5_newCapacity);
    if ((void *)c5_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c5_srcLocation, (void *)c5_sp);
    }

    if ((void *)c5_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c5_srcLocation, (void *)c5_sp);
    }

    if (c5_coderArray->vector.data != NULL) {
      memcpy(c5_newData, c5_coderArray->vector.data, sizeof(real32_T)
             * (uint32_T)c5_coderArray->vector.numel);
      if (c5_coderArray->vector.owner) {
        emlrtFreeMex(c5_coderArray->vector.data);
      }
    }

    c5_coderArray->vector.data = c5_newData;
    c5_coderArray->vector.allocated = c5_newCapacity;
    c5_coderArray->vector.owner = true;
  }

  c5_coderArray->vector.numel = c5_newNumel;
}

static void c5_array_creal_T_2D_SetSize(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_creal_T_2D
  *c5_coderArray, const emlrtRTEInfo *c5_srcLocation, int32_T c5_size0, int32_T
  c5_size1)
{
  creal_T *c5_newData;
  int32_T c5_newCapacity;
  int32_T c5_newNumel;
  (void)chartInstance;
  c5_coderArray->size[0] = c5_size0;
  c5_coderArray->size[1] = c5_size1;
  c5_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)(int32_T)
    emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)c5_coderArray->size[0],
                       c5_srcLocation, (void *)c5_sp), (size_t)(uint32_T)
    c5_coderArray->size[1], c5_srcLocation, (void *)c5_sp);
  if (c5_newNumel > c5_coderArray->vector.allocated) {
    c5_newCapacity = c5_coderArray->vector.allocated;
    if (c5_newCapacity < 16) {
      c5_newCapacity = 16;
    }

    while (c5_newCapacity < c5_newNumel) {
      if (c5_newCapacity > 1073741823) {
        c5_newCapacity = MAX_int32_T;
      } else {
        c5_newCapacity <<= 1;
      }
    }

    c5_newData = (creal_T *)emlrtMallocMex(sizeof(creal_T) * (uint32_T)
      c5_newCapacity);
    if ((void *)c5_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c5_srcLocation, (void *)c5_sp);
    }

    if ((void *)c5_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c5_srcLocation, (void *)c5_sp);
    }

    if (c5_coderArray->vector.data != NULL) {
      memcpy(c5_newData, c5_coderArray->vector.data, sizeof(creal_T) * (uint32_T)
             c5_coderArray->vector.numel);
      if (c5_coderArray->vector.owner) {
        emlrtFreeMex(c5_coderArray->vector.data);
      }
    }

    c5_coderArray->vector.data = c5_newData;
    c5_coderArray->vector.allocated = c5_newCapacity;
    c5_coderArray->vector.owner = true;
  }

  c5_coderArray->vector.numel = c5_newNumel;
}

static void c5_array_boolean_T_SetSize(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_boolean_T
  *c5_coderArray, const emlrtRTEInfo *c5_srcLocation, int32_T c5_size0)
{
  int32_T c5_newCapacity;
  int32_T c5_newNumel;
  boolean_T *c5_newData;
  (void)chartInstance;
  c5_coderArray->size[0] = c5_size0;
  c5_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)
    c5_coderArray->size[0], c5_srcLocation, (void *)c5_sp);
  if (c5_newNumel > c5_coderArray->vector.allocated) {
    c5_newCapacity = c5_coderArray->vector.allocated;
    if (c5_newCapacity < 16) {
      c5_newCapacity = 16;
    }

    while (c5_newCapacity < c5_newNumel) {
      if (c5_newCapacity > 1073741823) {
        c5_newCapacity = MAX_int32_T;
      } else {
        c5_newCapacity <<= 1;
      }
    }

    c5_newData = (boolean_T *)emlrtMallocMex(sizeof(boolean_T) * (uint32_T)
      c5_newCapacity);
    if ((void *)c5_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c5_srcLocation, (void *)c5_sp);
    }

    if ((void *)c5_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c5_srcLocation, (void *)c5_sp);
    }

    if (c5_coderArray->vector.data != NULL) {
      memcpy(c5_newData, c5_coderArray->vector.data, sizeof(boolean_T)
             * (uint32_T)c5_coderArray->vector.numel);
      if (c5_coderArray->vector.owner) {
        emlrtFreeMex(c5_coderArray->vector.data);
      }
    }

    c5_coderArray->vector.data = c5_newData;
    c5_coderArray->vector.allocated = c5_newCapacity;
    c5_coderArray->vector.owner = true;
  }

  c5_coderArray->vector.numel = c5_newNumel;
}

static void c5_array_sOA5t73y81YtFHGIDxk0fKF_S
  (SFc5_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c5_sp, c5_coder_array_sOA5t73y81YtFHGIDxk *c5_coderArray, const emlrtRTEInfo
   *c5_srcLocation, int32_T c5_size0)
{
  c5_sOA5t73y81YtFHGIDxk0fKF *c5_newData;
  int32_T c5_newCapacity;
  int32_T c5_newNumel;
  (void)chartInstance;
  c5_coderArray->size[0] = c5_size0;
  c5_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)
    c5_coderArray->size[0], c5_srcLocation, (void *)c5_sp);
  if (c5_newNumel > c5_coderArray->vector.allocated) {
    c5_newCapacity = c5_coderArray->vector.allocated;
    if (c5_newCapacity < 16) {
      c5_newCapacity = 16;
    }

    while (c5_newCapacity < c5_newNumel) {
      if (c5_newCapacity > 1073741823) {
        c5_newCapacity = MAX_int32_T;
      } else {
        c5_newCapacity <<= 1;
      }
    }

    c5_newData = (c5_sOA5t73y81YtFHGIDxk0fKF *)emlrtMallocMex(sizeof
      (c5_sOA5t73y81YtFHGIDxk0fKF) * (uint32_T)c5_newCapacity);
    if ((void *)c5_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c5_srcLocation, (void *)c5_sp);
    }

    if ((void *)c5_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c5_srcLocation, (void *)c5_sp);
    }

    if (c5_coderArray->vector.data != NULL) {
      memcpy(c5_newData, c5_coderArray->vector.data, sizeof
             (c5_sOA5t73y81YtFHGIDxk0fKF) * (uint32_T)
             c5_coderArray->vector.numel);
      if (c5_coderArray->vector.owner) {
        emlrtFreeMex(c5_coderArray->vector.data);
      }
    }

    c5_coderArray->vector.data = c5_newData;
    c5_coderArray->vector.allocated = c5_newCapacity;
    c5_coderArray->vector.owner = true;
  }

  c5_coderArray->vector.numel = c5_newNumel;
}

static void c5_array_s_R6Og1x0kmqQXSF9Pwa49FD_
  (SFc5_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c5_sp, c5_coder_array_s_R6Og1x0kmqQXSF9Pw *c5_coderArray, const emlrtRTEInfo
   *c5_srcLocation, int32_T c5_size0)
{
  c5_s_R6Og1x0kmqQXSF9Pwa49FD *c5_newData;
  int32_T c5_b_i;
  int32_T c5_i;
  int32_T c5_newCapacity;
  int32_T c5_newNumel;
  c5_coderArray->size[0] = c5_size0;
  c5_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)
    c5_coderArray->size[0], c5_srcLocation, (void *)c5_sp);
  if (c5_newNumel < c5_coderArray->vector.numel) {
    for (c5_i = c5_newNumel; c5_i < c5_coderArray->vector.numel; c5_i++) {
      c5_b_array_s_R6Og1x0kmqQXSF9Pwa49FD_(chartInstance,
        &c5_coderArray->vector.data[c5_i]);
    }
  }

  if (c5_newNumel > c5_coderArray->vector.allocated) {
    c5_newCapacity = c5_coderArray->vector.allocated;
    if (c5_newCapacity < 16) {
      c5_newCapacity = 16;
    }

    while (c5_newCapacity < c5_newNumel) {
      if (c5_newCapacity > 1073741823) {
        c5_newCapacity = MAX_int32_T;
      } else {
        c5_newCapacity <<= 1;
      }
    }

    c5_newData = (c5_s_R6Og1x0kmqQXSF9Pwa49FD *)emlrtMallocMex(sizeof
      (c5_s_R6Og1x0kmqQXSF9Pwa49FD) * (uint32_T)c5_newCapacity);
    if ((void *)c5_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c5_srcLocation, (void *)c5_sp);
    }

    if ((void *)c5_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c5_srcLocation, (void *)c5_sp);
    }

    if (c5_coderArray->vector.data != NULL) {
      memcpy(c5_newData, c5_coderArray->vector.data, sizeof
             (c5_s_R6Og1x0kmqQXSF9Pwa49FD) * (uint32_T)
             c5_coderArray->vector.numel);
      if (c5_coderArray->vector.owner) {
        emlrtFreeMex(c5_coderArray->vector.data);
      }
    }

    c5_coderArray->vector.data = c5_newData;
    c5_coderArray->vector.allocated = c5_newCapacity;
    c5_coderArray->vector.owner = true;
  }

  for (c5_b_i = c5_coderArray->vector.numel; c5_b_i < c5_newNumel; c5_b_i++) {
    c5_c_array_s_R6Og1x0kmqQXSF9Pwa49FD_(chartInstance,
      &c5_coderArray->vector.data[c5_b_i]);
  }

  c5_coderArray->vector.numel = c5_newNumel;
}

static void c5_array_real_T_Destructor(SFc5_flightControlSystemInstanceStruct
  *chartInstance, c5_coder_array_real_T *c5_coderArray)
{
  (void)chartInstance;
  if (c5_coderArray->vector.owner && (c5_coderArray->vector.data != (real_T *)
       NULL)) {
    emlrtFreeMex(c5_coderArray->vector.data);
  }
}

static void c5_b_array_s_R6Og1x0kmqQXSF9Pwa49FD_
  (SFc5_flightControlSystemInstanceStruct *chartInstance,
   c5_s_R6Og1x0kmqQXSF9Pwa49FD *c5_pStruct)
{
  c5_array_real_T_Destructor(chartInstance, &c5_pStruct->PixelIdxList);
  c5_array_real_T_2D_Destructor(chartInstance, &c5_pStruct->PixelList);
  c5_array_real_T_Destructor(chartInstance, &c5_pStruct->PixelValues);
}

static void c5_array_real_T_2D_Destructor(SFc5_flightControlSystemInstanceStruct
  *chartInstance, c5_coder_array_real_T_2D *c5_coderArray)
{
  (void)chartInstance;
  if (c5_coderArray->vector.owner && (c5_coderArray->vector.data != (real_T *)
       NULL)) {
    emlrtFreeMex(c5_coderArray->vector.data);
  }
}

static void c5_c_array_s_R6Og1x0kmqQXSF9Pwa49FD_
  (SFc5_flightControlSystemInstanceStruct *chartInstance,
   c5_s_R6Og1x0kmqQXSF9Pwa49FD *c5_pStruct)
{
  c5_array_boolean_T_0x0_Constructor(chartInstance, &c5_pStruct->Image);
  c5_array_boolean_T_0x0_Constructor(chartInstance, &c5_pStruct->FilledImage);
  c5_array_real_T_Constructor(chartInstance, &c5_pStruct->PixelIdxList);
  c5_array_real_T_2D_Constructor(chartInstance, &c5_pStruct->PixelList);
  c5_array_real_T_Constructor(chartInstance, &c5_pStruct->PixelValues);
  c5_array_real_T_1x0_Constructor(chartInstance, &c5_pStruct->SubarrayIdx);
}

static void c5_array_boolean_T_0x0_Constructor
  (SFc5_flightControlSystemInstanceStruct *chartInstance,
   c5_coder_array_boolean_T_0x0 *c5_pArray)
{
  (void)chartInstance;
  c5_pArray->size[0] = 0;
  c5_pArray->size[1] = 0;
}

static void c5_array_real_T_Constructor(SFc5_flightControlSystemInstanceStruct
  *chartInstance, c5_coder_array_real_T *c5_coderArray)
{
  (void)chartInstance;
  c5_coderArray->vector.data = (real_T *)NULL;
  c5_coderArray->vector.numel = 0;
  c5_coderArray->vector.allocated = 0;
  c5_coderArray->vector.owner = true;
  c5_coderArray->size[0] = 0;
}

static void c5_array_real_T_2D_Constructor
  (SFc5_flightControlSystemInstanceStruct *chartInstance,
   c5_coder_array_real_T_2D *c5_coderArray)
{
  (void)chartInstance;
  c5_coderArray->vector.data = (real_T *)NULL;
  c5_coderArray->vector.numel = 0;
  c5_coderArray->vector.allocated = 0;
  c5_coderArray->vector.owner = true;
  c5_coderArray->size[0] = 0;
  c5_coderArray->size[1] = 0;
}

static void c5_array_real_T_1x0_Constructor
  (SFc5_flightControlSystemInstanceStruct *chartInstance,
   c5_coder_array_real_T_1x0 *c5_pArray)
{
  (void)chartInstance;
  c5_pArray->size[0] = 0;
  c5_pArray->size[1] = 0;
}

static void c5_array_cell_wrap_51_2D_SetSize
  (SFc5_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c5_sp, c5_coder_array_cell_wrap_51_2D *c5_coderArray, const emlrtRTEInfo
   *c5_srcLocation, int32_T c5_size0, int32_T c5_size1)
{
  c5_cell_wrap_51 *c5_newData;
  int32_T c5_b_i;
  int32_T c5_i;
  int32_T c5_newCapacity;
  int32_T c5_newNumel;
  c5_coderArray->size[0] = c5_size0;
  c5_coderArray->size[1] = c5_size1;
  c5_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)(int32_T)
    emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)c5_coderArray->size[0],
                       c5_srcLocation, (void *)c5_sp), (size_t)(uint32_T)
    c5_coderArray->size[1], c5_srcLocation, (void *)c5_sp);
  if (c5_newNumel < c5_coderArray->vector.numel) {
    for (c5_i = c5_newNumel; c5_i < c5_coderArray->vector.numel; c5_i++) {
      c5_array_cell_wrap_51_Destructor(chartInstance,
        &c5_coderArray->vector.data[c5_i]);
    }
  }

  if (c5_newNumel > c5_coderArray->vector.allocated) {
    c5_newCapacity = c5_coderArray->vector.allocated;
    if (c5_newCapacity < 16) {
      c5_newCapacity = 16;
    }

    while (c5_newCapacity < c5_newNumel) {
      if (c5_newCapacity > 1073741823) {
        c5_newCapacity = MAX_int32_T;
      } else {
        c5_newCapacity <<= 1;
      }
    }

    c5_newData = (c5_cell_wrap_51 *)emlrtMallocMex(sizeof(c5_cell_wrap_51) *
      (uint32_T)c5_newCapacity);
    if ((void *)c5_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c5_srcLocation, (void *)c5_sp);
    }

    if ((void *)c5_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c5_srcLocation, (void *)c5_sp);
    }

    if (c5_coderArray->vector.data != NULL) {
      memcpy(c5_newData, c5_coderArray->vector.data, sizeof(c5_cell_wrap_51) *
             (uint32_T)c5_coderArray->vector.numel);
      if (c5_coderArray->vector.owner) {
        emlrtFreeMex(c5_coderArray->vector.data);
      }
    }

    c5_coderArray->vector.data = c5_newData;
    c5_coderArray->vector.allocated = c5_newCapacity;
    c5_coderArray->vector.owner = true;
  }

  for (c5_b_i = c5_coderArray->vector.numel; c5_b_i < c5_newNumel; c5_b_i++) {
    c5_array_cell_wrap_51_Constructor(chartInstance, &c5_coderArray->
      vector.data[c5_b_i]);
  }

  c5_coderArray->vector.numel = c5_newNumel;
}

static void c5_array_cell_wrap_51_Destructor
  (SFc5_flightControlSystemInstanceStruct *chartInstance, c5_cell_wrap_51
   *c5_pStruct)
{
  c5_array_real_T_Destructor(chartInstance, &c5_pStruct->f1);
}

static void c5_array_cell_wrap_51_Constructor
  (SFc5_flightControlSystemInstanceStruct *chartInstance, c5_cell_wrap_51
   *c5_pStruct)
{
  c5_array_real_T_Constructor(chartInstance, &c5_pStruct->f1);
}

static void c5_array_int32_T_2D_SetSize(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_int32_T_2D
  *c5_coderArray, const emlrtRTEInfo *c5_srcLocation, int32_T c5_size0, int32_T
  c5_size1)
{
  int32_T c5_newCapacity;
  int32_T c5_newNumel;
  int32_T *c5_newData;
  (void)chartInstance;
  c5_coderArray->size[0] = c5_size0;
  c5_coderArray->size[1] = c5_size1;
  c5_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)(int32_T)
    emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)c5_coderArray->size[0],
                       c5_srcLocation, (void *)c5_sp), (size_t)(uint32_T)
    c5_coderArray->size[1], c5_srcLocation, (void *)c5_sp);
  if (c5_newNumel > c5_coderArray->vector.allocated) {
    c5_newCapacity = c5_coderArray->vector.allocated;
    if (c5_newCapacity < 16) {
      c5_newCapacity = 16;
    }

    while (c5_newCapacity < c5_newNumel) {
      if (c5_newCapacity > 1073741823) {
        c5_newCapacity = MAX_int32_T;
      } else {
        c5_newCapacity <<= 1;
      }
    }

    c5_newData = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
      c5_newCapacity);
    if ((void *)c5_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c5_srcLocation, (void *)c5_sp);
    }

    if ((void *)c5_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c5_srcLocation, (void *)c5_sp);
    }

    if (c5_coderArray->vector.data != NULL) {
      memcpy(c5_newData, c5_coderArray->vector.data, sizeof(int32_T) * (uint32_T)
             c5_coderArray->vector.numel);
      if (c5_coderArray->vector.owner) {
        emlrtFreeMex(c5_coderArray->vector.data);
      }
    }

    c5_coderArray->vector.data = c5_newData;
    c5_coderArray->vector.allocated = c5_newCapacity;
    c5_coderArray->vector.owner = true;
  }

  c5_coderArray->vector.numel = c5_newNumel;
}

static void c5_array_cell_wrap_60_2s_Construct
  (SFc5_flightControlSystemInstanceStruct *chartInstance, c5_cell_wrap_60
   c5_pMatrix[2])
{
  int32_T c5_i;
  for (c5_i = 0; c5_i < 2; c5_i++) {
    c5_array_cell_wrap_60_Constructor(chartInstance, &c5_pMatrix[c5_i]);
  }
}

static void c5_array_cell_wrap_60_Constructor
  (SFc5_flightControlSystemInstanceStruct *chartInstance, c5_cell_wrap_60
   *c5_pStruct)
{
  c5_array_real_T_2D_Constructor(chartInstance, &c5_pStruct->f1);
}

static void c5_array_cell_wrap_60_2s_Destructo
  (SFc5_flightControlSystemInstanceStruct *chartInstance, c5_cell_wrap_60
   c5_pMatrix[2])
{
  int32_T c5_i;
  for (c5_i = 0; c5_i < 2; c5_i++) {
    c5_array_cell_wrap_60_Destructor(chartInstance, &c5_pMatrix[c5_i]);
  }
}

static void c5_array_cell_wrap_60_Destructor
  (SFc5_flightControlSystemInstanceStruct *chartInstance, c5_cell_wrap_60
   *c5_pStruct)
{
  c5_array_real_T_2D_Destructor(chartInstance, &c5_pStruct->f1);
}

static void c5_array_boolean_T_2D_Constructor
  (SFc5_flightControlSystemInstanceStruct *chartInstance,
   c5_coder_array_boolean_T_2D *c5_coderArray)
{
  (void)chartInstance;
  c5_coderArray->vector.data = (boolean_T *)NULL;
  c5_coderArray->vector.numel = 0;
  c5_coderArray->vector.allocated = 0;
  c5_coderArray->vector.owner = true;
  c5_coderArray->size[0] = 0;
  c5_coderArray->size[1] = 0;
}

static void c5_array_int32_T_Constructor(SFc5_flightControlSystemInstanceStruct *
  chartInstance, c5_coder_array_int32_T *c5_coderArray)
{
  (void)chartInstance;
  c5_coderArray->vector.data = (int32_T *)NULL;
  c5_coderArray->vector.numel = 0;
  c5_coderArray->vector.allocated = 0;
  c5_coderArray->vector.owner = true;
  c5_coderArray->size[0] = 0;
}

static void c5_array_creal_T_Constructor(SFc5_flightControlSystemInstanceStruct *
  chartInstance, c5_coder_array_creal_T *c5_coderArray)
{
  (void)chartInstance;
  c5_coderArray->vector.data = (creal_T *)NULL;
  c5_coderArray->vector.numel = 0;
  c5_coderArray->vector.allocated = 0;
  c5_coderArray->vector.owner = true;
  c5_coderArray->size[0] = 0;
}

static void c5_array_boolean_T_2D_Destructor
  (SFc5_flightControlSystemInstanceStruct *chartInstance,
   c5_coder_array_boolean_T_2D *c5_coderArray)
{
  (void)chartInstance;
  if (c5_coderArray->vector.owner && (c5_coderArray->vector.data != (boolean_T *)
       NULL)) {
    emlrtFreeMex(c5_coderArray->vector.data);
  }
}

static void c5_array_int32_T_Destructor(SFc5_flightControlSystemInstanceStruct
  *chartInstance, c5_coder_array_int32_T *c5_coderArray)
{
  (void)chartInstance;
  if (c5_coderArray->vector.owner && (c5_coderArray->vector.data != (int32_T *)
       NULL)) {
    emlrtFreeMex(c5_coderArray->vector.data);
  }
}

static void c5_array_creal_T_Destructor(SFc5_flightControlSystemInstanceStruct
  *chartInstance, c5_coder_array_creal_T *c5_coderArray)
{
  (void)chartInstance;
  if (c5_coderArray->vector.owner && (c5_coderArray->vector.data != (creal_T *)
       NULL)) {
    emlrtFreeMex(c5_coderArray->vector.data);
  }
}

static void c5_array_real32_T_2D_Constructor
  (SFc5_flightControlSystemInstanceStruct *chartInstance,
   c5_coder_array_real32_T_2D *c5_coderArray)
{
  (void)chartInstance;
  c5_coderArray->vector.data = (real32_T *)NULL;
  c5_coderArray->vector.numel = 0;
  c5_coderArray->vector.allocated = 0;
  c5_coderArray->vector.owner = true;
  c5_coderArray->size[0] = 0;
  c5_coderArray->size[1] = 0;
}

static void c5_array_creal_T_2D_Constructor
  (SFc5_flightControlSystemInstanceStruct *chartInstance,
   c5_coder_array_creal_T_2D *c5_coderArray)
{
  (void)chartInstance;
  c5_coderArray->vector.data = (creal_T *)NULL;
  c5_coderArray->vector.numel = 0;
  c5_coderArray->vector.allocated = 0;
  c5_coderArray->vector.owner = true;
  c5_coderArray->size[0] = 0;
  c5_coderArray->size[1] = 0;
}

static void c5_array_real32_T_2D_Destructor
  (SFc5_flightControlSystemInstanceStruct *chartInstance,
   c5_coder_array_real32_T_2D *c5_coderArray)
{
  (void)chartInstance;
  if (c5_coderArray->vector.owner && (c5_coderArray->vector.data != (real32_T *)
       NULL)) {
    emlrtFreeMex(c5_coderArray->vector.data);
  }
}

static void c5_array_creal_T_2D_Destructor
  (SFc5_flightControlSystemInstanceStruct *chartInstance,
   c5_coder_array_creal_T_2D *c5_coderArray)
{
  (void)chartInstance;
  if (c5_coderArray->vector.owner && (c5_coderArray->vector.data != (creal_T *)
       NULL)) {
    emlrtFreeMex(c5_coderArray->vector.data);
  }
}

static void c5_array_sOA5t73y81YtFHGIDxk0fKF_C
  (SFc5_flightControlSystemInstanceStruct *chartInstance,
   c5_coder_array_sOA5t73y81YtFHGIDxk *c5_coderArray)
{
  (void)chartInstance;
  c5_coderArray->vector.data = (c5_sOA5t73y81YtFHGIDxk0fKF *)NULL;
  c5_coderArray->vector.numel = 0;
  c5_coderArray->vector.allocated = 0;
  c5_coderArray->vector.owner = true;
  c5_coderArray->size[0] = 0;
}

static void c5_array_int32_T_2D_Constructor
  (SFc5_flightControlSystemInstanceStruct *chartInstance,
   c5_coder_array_int32_T_2D *c5_coderArray)
{
  (void)chartInstance;
  c5_coderArray->vector.data = (int32_T *)NULL;
  c5_coderArray->vector.numel = 0;
  c5_coderArray->vector.allocated = 0;
  c5_coderArray->vector.owner = true;
  c5_coderArray->size[0] = 0;
  c5_coderArray->size[1] = 0;
}

static void c5_array_sOA5t73y81YtFHGIDxk0fKF_D
  (SFc5_flightControlSystemInstanceStruct *chartInstance,
   c5_coder_array_sOA5t73y81YtFHGIDxk *c5_coderArray)
{
  (void)chartInstance;
  if (c5_coderArray->vector.owner && (c5_coderArray->vector.data !=
       (c5_sOA5t73y81YtFHGIDxk0fKF *)NULL)) {
    emlrtFreeMex(c5_coderArray->vector.data);
  }
}

static void c5_array_int32_T_2D_Destructor
  (SFc5_flightControlSystemInstanceStruct *chartInstance,
   c5_coder_array_int32_T_2D *c5_coderArray)
{
  (void)chartInstance;
  if (c5_coderArray->vector.owner && (c5_coderArray->vector.data != (int32_T *)
       NULL)) {
    emlrtFreeMex(c5_coderArray->vector.data);
  }
}

static void c5_d_array_s_R6Og1x0kmqQXSF9Pwa49FD_
  (SFc5_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c5_sp, c5_s_R6Og1x0kmqQXSF9Pwa49FD *c5_dst, const
   c5_s_R6Og1x0kmqQXSF9Pwa49FD *c5_src, const emlrtRTEInfo *c5_srcLocation)
{
  c5_dst->Area = c5_src->Area;
  c5_array_real_T_1x2s_Copy(chartInstance, c5_dst->Centroid, c5_src->Centroid);
  c5_array_real_T_1x4s_Copy(chartInstance, c5_dst->BoundingBox,
    c5_src->BoundingBox);
  c5_dst->MajorAxisLength = c5_src->MajorAxisLength;
  c5_dst->MinorAxisLength = c5_src->MinorAxisLength;
  c5_dst->Eccentricity = c5_src->Eccentricity;
  c5_dst->Orientation = c5_src->Orientation;
  c5_array_boolean_T_0x0_Copy(chartInstance, c5_sp, &c5_dst->Image,
    &c5_src->Image, c5_srcLocation);
  c5_array_boolean_T_0x0_Copy(chartInstance, c5_sp, &c5_dst->FilledImage,
    &c5_src->FilledImage, c5_srcLocation);
  c5_dst->FilledArea = c5_src->FilledArea;
  c5_dst->EulerNumber = c5_src->EulerNumber;
  c5_array_real_T_8x2s_Copy(chartInstance, c5_dst->Extrema, c5_src->Extrema);
  c5_dst->EquivDiameter = c5_src->EquivDiameter;
  c5_dst->Extent = c5_src->Extent;
  c5_array_real_T_Copy(chartInstance, c5_sp, &c5_dst->PixelIdxList,
                       &c5_src->PixelIdxList, c5_srcLocation);
  c5_array_real_T_2D_Copy(chartInstance, c5_sp, &c5_dst->PixelList,
    &c5_src->PixelList, c5_srcLocation);
  c5_dst->Perimeter = c5_src->Perimeter;
  c5_dst->Circularity = c5_src->Circularity;
  c5_array_real_T_Copy(chartInstance, c5_sp, &c5_dst->PixelValues,
                       &c5_src->PixelValues, c5_srcLocation);
  c5_array_real_T_1x2s_Copy(chartInstance, c5_dst->WeightedCentroid,
    c5_src->WeightedCentroid);
  c5_dst->MeanIntensity = c5_src->MeanIntensity;
  c5_dst->MinIntensity = c5_src->MinIntensity;
  c5_dst->MaxIntensity = c5_src->MaxIntensity;
  c5_array_real_T_1x0_Copy(chartInstance, c5_sp, &c5_dst->SubarrayIdx,
    &c5_src->SubarrayIdx, c5_srcLocation);
  c5_array_real_T_1x2s_Copy(chartInstance, c5_dst->SubarrayIdxLengths,
    c5_src->SubarrayIdxLengths);
}

static void c5_array_real_T_1x2s_Copy(SFc5_flightControlSystemInstanceStruct
  *chartInstance, real_T c5_dst[2], const real_T c5_src[2])
{
  int32_T c5_i;
  (void)chartInstance;
  for (c5_i = 0; c5_i < 2; c5_i++) {
    c5_dst[c5_i] = c5_src[c5_i];
  }
}

static void c5_array_real_T_1x4s_Copy(SFc5_flightControlSystemInstanceStruct
  *chartInstance, real_T c5_dst[4], const real_T c5_src[4])
{
  int32_T c5_i;
  (void)chartInstance;
  for (c5_i = 0; c5_i < 4; c5_i++) {
    c5_dst[c5_i] = c5_src[c5_i];
  }
}

static void c5_array_boolean_T_0x0_Copy(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_boolean_T_0x0 *c5_dst,
  const c5_coder_array_boolean_T_0x0 *c5_src, const emlrtRTEInfo *c5_srcLocation)
{
  c5_array_boolean_T_0x0_SetSize(chartInstance, c5_sp, c5_dst->size,
    c5_srcLocation, c5_src->size[0], c5_src->size[1]);
  emlrtSizeMulR2012b((size_t)(uint32_T)(int32_T)emlrtSizeMulR2012b((size_t)1U,
    (size_t)(uint32_T)c5_src->size[0], c5_srcLocation, (void *)c5_sp), (size_t)
                     (uint32_T)c5_src->size[1], c5_srcLocation, (void *)c5_sp);
}

static void c5_array_boolean_T_0x0_SetSize
  (SFc5_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c5_sp, int32_T c5_size[2], const emlrtRTEInfo *c5_srcLocation, int32_T
   c5_size0, int32_T c5_size1)
{
  (void)chartInstance;
  emlrtSizeMulR2012b((size_t)(uint32_T)(int32_T)emlrtSizeMulR2012b((size_t)1U,
    (size_t)(uint32_T)c5_size[0], c5_srcLocation, (void *)c5_sp), (size_t)
                     (uint32_T)c5_size[1], c5_srcLocation, (void *)c5_sp);
  c5_size[0] = c5_size0;
  c5_size[1] = c5_size1;
  emlrtSizeMulR2012b((size_t)(uint32_T)(int32_T)emlrtSizeMulR2012b((size_t)1U,
    (size_t)(uint32_T)c5_size[0], c5_srcLocation, (void *)c5_sp), (size_t)
                     (uint32_T)c5_size[1], c5_srcLocation, (void *)c5_sp);
}

static void c5_array_real_T_8x2s_Copy(SFc5_flightControlSystemInstanceStruct
  *chartInstance, real_T c5_dst[16], const real_T c5_src[16])
{
  int32_T c5_i;
  (void)chartInstance;
  for (c5_i = 0; c5_i < 16; c5_i++) {
    c5_dst[c5_i] = c5_src[c5_i];
  }
}

static void c5_array_real_T_Copy(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_real_T *c5_dst, const
  c5_coder_array_real_T *c5_src, const emlrtRTEInfo *c5_srcLocation)
{
  int32_T c5_i;
  c5_array_real_T_SetSize(chartInstance, c5_sp, c5_dst, c5_srcLocation,
    c5_src->size[0]);
  for (c5_i = 0; c5_i < c5_src->vector.numel; c5_i++) {
    c5_dst->vector.data[c5_i] = c5_src->vector.data[c5_i];
  }
}

static void c5_array_real_T_2D_Copy(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_real_T_2D *c5_dst,
  const c5_coder_array_real_T_2D *c5_src, const emlrtRTEInfo *c5_srcLocation)
{
  int32_T c5_i;
  c5_array_real_T_2D_SetSize(chartInstance, c5_sp, c5_dst, c5_srcLocation,
    c5_src->size[0], c5_src->size[1]);
  for (c5_i = 0; c5_i < c5_src->vector.numel; c5_i++) {
    c5_dst->vector.data[c5_i] = c5_src->vector.data[c5_i];
  }
}

static void c5_array_real_T_1x0_Copy(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_real_T_1x0 *c5_dst,
  const c5_coder_array_real_T_1x0 *c5_src, const emlrtRTEInfo *c5_srcLocation)
{
  c5_array_real_T_1x0_SetSize(chartInstance, c5_sp, c5_dst->size, c5_srcLocation,
    c5_src->size[0], c5_src->size[1]);
  emlrtSizeMulR2012b((size_t)(uint32_T)(int32_T)emlrtSizeMulR2012b((size_t)1U,
    (size_t)(uint32_T)c5_src->size[0], c5_srcLocation, (void *)c5_sp), (size_t)
                     (uint32_T)c5_src->size[1], c5_srcLocation, (void *)c5_sp);
}

static void c5_array_real_T_1x0_SetSize(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, int32_T c5_size[2], const
  emlrtRTEInfo *c5_srcLocation, int32_T c5_size0, int32_T c5_size1)
{
  (void)chartInstance;
  emlrtSizeMulR2012b((size_t)(uint32_T)(int32_T)emlrtSizeMulR2012b((size_t)1U,
    (size_t)(uint32_T)c5_size[0], c5_srcLocation, (void *)c5_sp), (size_t)
                     (uint32_T)c5_size[1], c5_srcLocation, (void *)c5_sp);
  c5_size[0] = c5_size0;
  c5_size[1] = c5_size1;
  emlrtSizeMulR2012b((size_t)(uint32_T)(int32_T)emlrtSizeMulR2012b((size_t)1U,
    (size_t)(uint32_T)c5_size[0], c5_srcLocation, (void *)c5_sp), (size_t)
                     (uint32_T)c5_size[1], c5_srcLocation, (void *)c5_sp);
}

static void c5_array_s_jsRMsmv0Wf6iHXg8PgCG1G_
  (SFc5_flightControlSystemInstanceStruct *chartInstance,
   c5_s_jsRMsmv0Wf6iHXg8PgCG1G *c5_pStruct)
{
  c5_array_real_T_Constructor(chartInstance, &c5_pStruct->RegionIndices);
  c5_array_int32_T_Constructor(chartInstance, &c5_pStruct->RegionLengths);
  c5_array_cell_wrap_51_2D_Construct(chartInstance, &c5_pStruct->PixelIdxList);
}

static void c5_array_cell_wrap_51_2D_Construct
  (SFc5_flightControlSystemInstanceStruct *chartInstance,
   c5_coder_array_cell_wrap_51_2D *c5_coderArray)
{
  (void)chartInstance;
  c5_coderArray->vector.data = (c5_cell_wrap_51 *)NULL;
  c5_coderArray->vector.numel = 0;
  c5_coderArray->vector.allocated = 0;
  c5_coderArray->vector.owner = true;
  c5_coderArray->size[0] = 0;
  c5_coderArray->size[1] = 0;
}

static void c5_e_array_s_R6Og1x0kmqQXSF9Pwa49FD_
  (SFc5_flightControlSystemInstanceStruct *chartInstance,
   c5_coder_array_s_R6Og1x0kmqQXSF9Pw *c5_coderArray)
{
  (void)chartInstance;
  c5_coderArray->vector.data = (c5_s_R6Og1x0kmqQXSF9Pwa49FD *)NULL;
  c5_coderArray->vector.numel = 0;
  c5_coderArray->vector.allocated = 0;
  c5_coderArray->vector.owner = true;
  c5_coderArray->size[0] = 0;
}

static void c5_array_boolean_T_Constructor
  (SFc5_flightControlSystemInstanceStruct *chartInstance,
   c5_coder_array_boolean_T *c5_coderArray)
{
  (void)chartInstance;
  c5_coderArray->vector.data = (boolean_T *)NULL;
  c5_coderArray->vector.numel = 0;
  c5_coderArray->vector.allocated = 0;
  c5_coderArray->vector.owner = true;
  c5_coderArray->size[0] = 0;
}

static void c5_b_array_s_jsRMsmv0Wf6iHXg8PgCG1G_
  (SFc5_flightControlSystemInstanceStruct *chartInstance,
   c5_s_jsRMsmv0Wf6iHXg8PgCG1G *c5_pStruct)
{
  c5_array_real_T_Destructor(chartInstance, &c5_pStruct->RegionIndices);
  c5_array_int32_T_Destructor(chartInstance, &c5_pStruct->RegionLengths);
  c5_array_cell_wrap_51_2D_Destructo(chartInstance, &c5_pStruct->PixelIdxList);
}

static void c5_array_cell_wrap_51_2D_Destructo
  (SFc5_flightControlSystemInstanceStruct *chartInstance,
   c5_coder_array_cell_wrap_51_2D *c5_coderArray)
{
  int32_T c5_i;
  if (c5_coderArray->vector.owner && (c5_coderArray->vector.data !=
       (c5_cell_wrap_51 *)NULL)) {
    for (c5_i = 0; c5_i < c5_coderArray->vector.numel; c5_i++) {
      c5_array_cell_wrap_51_Destructor(chartInstance,
        &c5_coderArray->vector.data[c5_i]);
    }

    emlrtFreeMex(c5_coderArray->vector.data);
  }
}

static void c5_f_array_s_R6Og1x0kmqQXSF9Pwa49FD_
  (SFc5_flightControlSystemInstanceStruct *chartInstance,
   c5_coder_array_s_R6Og1x0kmqQXSF9Pw *c5_coderArray)
{
  int32_T c5_i;
  if (c5_coderArray->vector.owner && (c5_coderArray->vector.data !=
       (c5_s_R6Og1x0kmqQXSF9Pwa49FD *)NULL)) {
    for (c5_i = 0; c5_i < c5_coderArray->vector.numel; c5_i++) {
      c5_b_array_s_R6Og1x0kmqQXSF9Pwa49FD_(chartInstance,
        &c5_coderArray->vector.data[c5_i]);
    }

    emlrtFreeMex(c5_coderArray->vector.data);
  }
}

static void c5_array_boolean_T_Destructor(SFc5_flightControlSystemInstanceStruct
  *chartInstance, c5_coder_array_boolean_T *c5_coderArray)
{
  (void)chartInstance;
  if (c5_coderArray->vector.owner && (c5_coderArray->vector.data != (boolean_T *)
       NULL)) {
    emlrtFreeMex(c5_coderArray->vector.data);
  }
}

static void c5_array_cell_wrap_51_Copy(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_cell_wrap_51 *c5_dst, const
  c5_cell_wrap_51 *c5_src, const emlrtRTEInfo *c5_srcLocation)
{
  c5_array_real_T_Copy(chartInstance, c5_sp, &c5_dst->f1, &c5_src->f1,
                       c5_srcLocation);
}

static void c5_array_cell_wrap_51_1s_Construct
  (SFc5_flightControlSystemInstanceStruct *chartInstance, c5_cell_wrap_51
   c5_pMatrix[1])
{
  int32_T c5_i;
  for (c5_i = 0; c5_i < 1; c5_i++) {
    c5_array_cell_wrap_51_Constructor(chartInstance, &c5_pMatrix[c5_i]);
  }
}

static void c5_array_cell_wrap_51_1s_Destructo
  (SFc5_flightControlSystemInstanceStruct *chartInstance, c5_cell_wrap_51
   c5_pMatrix[1])
{
  int32_T c5_i;
  for (c5_i = 0; c5_i < 1; c5_i++) {
    c5_array_cell_wrap_51_Destructor(chartInstance, &c5_pMatrix[c5_i]);
  }
}

static void c5_array_cell_wrap_51_2s_Construct
  (SFc5_flightControlSystemInstanceStruct *chartInstance, c5_cell_wrap_51
   c5_pMatrix[2])
{
  int32_T c5_i;
  for (c5_i = 0; c5_i < 2; c5_i++) {
    c5_array_cell_wrap_51_Constructor(chartInstance, &c5_pMatrix[c5_i]);
  }
}

static void c5_array_cell_wrap_51_2s_Destructo
  (SFc5_flightControlSystemInstanceStruct *chartInstance, c5_cell_wrap_51
   c5_pMatrix[2])
{
  int32_T c5_i;
  for (c5_i = 0; c5_i < 2; c5_i++) {
    c5_array_cell_wrap_51_Destructor(chartInstance, &c5_pMatrix[c5_i]);
  }
}

static int32_T c5_div_nzp_s32(SFc5_flightControlSystemInstanceStruct
  *chartInstance, int32_T c5_numerator, int32_T c5_denominator, int32_T
  c5_EMLOvCount_src_loc, uint32_T c5_ssid_src_loc, int32_T c5_offset_src_loc,
  int32_T c5_length_src_loc)
{
  int32_T c5_quotient;
  uint32_T c5_absDenominator;
  uint32_T c5_absNumerator;
  uint32_T c5_tempAbsQuotient;
  boolean_T c5_quotientNeedsNegation;
  (void)chartInstance;
  (void)c5_EMLOvCount_src_loc;
  (void)c5_ssid_src_loc;
  (void)c5_offset_src_loc;
  (void)c5_length_src_loc;
  if (c5_numerator < 0) {
    c5_absNumerator = ~(uint32_T)c5_numerator + 1U;
  } else {
    c5_absNumerator = (uint32_T)c5_numerator;
  }

  if (c5_denominator < 0) {
    c5_absDenominator = ~(uint32_T)c5_denominator + 1U;
  } else {
    c5_absDenominator = (uint32_T)c5_denominator;
  }

  c5_quotientNeedsNegation = ((c5_numerator < 0) != (c5_denominator < 0));
  c5_tempAbsQuotient = c5_absNumerator / c5_absDenominator;
  if (c5_quotientNeedsNegation) {
    c5_quotient = -(int32_T)c5_tempAbsQuotient;
  } else {
    c5_quotient = (int32_T)c5_tempAbsQuotient;
  }

  return c5_quotient;
}

static void init_dsm_address_info(SFc5_flightControlSystemInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc5_flightControlSystemInstanceStruct
  *chartInstance)
{
  chartInstance->c5_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c5_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c5_d_u = (real_T (*)[19200])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c5_number = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c5_flightControlSystem_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1910383744U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1284012669U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(880096718U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3434751941U);
}

mxArray *sf_c5_flightControlSystem_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,10);
  mxSetCell(mxcell3p, 0, mxCreateString("coder.internal.lapack.LAPACKApi"));
  mxSetCell(mxcell3p, 1, mxCreateString("coder.internal.blas.BLASApi"));
  mxSetCell(mxcell3p, 2, mxCreateString(
             "images.internal.coder.buildable.IppfilterBuildable"));
  mxSetCell(mxcell3p, 3, mxCreateString(
             "images.internal.coder.buildable.ImfilterBuildable"));
  mxSetCell(mxcell3p, 4, mxCreateString(
             "images.internal.coder.buildable.Grayto8Buildable"));
  mxSetCell(mxcell3p, 5, mxCreateString(
             "images.internal.coder.buildable.GetnumcoresBuildable"));
  mxSetCell(mxcell3p, 6, mxCreateString(
             "images.internal.coder.buildable.CannyThresholdingTbbBuildable"));
  mxSetCell(mxcell3p, 7, mxCreateString(
             "images.internal.coder.buildable.IppreconstructBuildable"));
  mxSetCell(mxcell3p, 8, mxCreateString(
             "images.internal.coder.buildable.Ordfilt2Buildable"));
  mxSetCell(mxcell3p, 9, mxCreateString(
             "images.internal.coder.buildable.ImregionalmaxBuildable"));
  return(mxcell3p);
}

mxArray *sf_c5_flightControlSystem_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("late");
  mxArray *fallbackReason = mxCreateString("ir_function_calls");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("ippfilter_real64");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c5_flightControlSystem_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c5_flightControlSystem(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiBWYGRgYAPSHEDMxAABrFA+IxKGiLPAxRWAuKSyIBUkXlyU7JkCpPMSc8H8xNI"
    "Kz7y0fLD5FgwI89kImM8JFYeAD/aU6VdwQNfPgkU/G5J+ASg/rzQ3KbUIEj4gAAC6Iw7q"
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c5_flightControlSystem_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "sRSTv7I7nuXYRGJECdPE9SH";
}

static void sf_opaque_initialize_c5_flightControlSystem(void *chartInstanceVar)
{
  initialize_params_c5_flightControlSystem
    ((SFc5_flightControlSystemInstanceStruct*) chartInstanceVar);
  initialize_c5_flightControlSystem((SFc5_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c5_flightControlSystem(void *chartInstanceVar)
{
  enable_c5_flightControlSystem((SFc5_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c5_flightControlSystem(void *chartInstanceVar)
{
  disable_c5_flightControlSystem((SFc5_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c5_flightControlSystem(void *chartInstanceVar)
{
  sf_gateway_c5_flightControlSystem((SFc5_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c5_flightControlSystem(SimStruct*
  S)
{
  return get_sim_state_c5_flightControlSystem
    ((SFc5_flightControlSystemInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c5_flightControlSystem(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c5_flightControlSystem((SFc5_flightControlSystemInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_cleanup_runtime_resources_c5_flightControlSystem(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc5_flightControlSystemInstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_flightControlSystem_optimization_info();
    }

    mdl_cleanup_runtime_resources_c5_flightControlSystem
      ((SFc5_flightControlSystemInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c5_flightControlSystem(void *chartInstanceVar)
{
  mdl_start_c5_flightControlSystem((SFc5_flightControlSystemInstanceStruct*)
    chartInstanceVar);
  if (chartInstanceVar) {
    sf_reset_warnings_ChartRunTimeInfo(((SFc5_flightControlSystemInstanceStruct*)
      chartInstanceVar)->S);
  }
}

static void sf_opaque_mdl_terminate_c5_flightControlSystem(void
  *chartInstanceVar)
{
  mdl_terminate_c5_flightControlSystem((SFc5_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_flightControlSystem(SimStruct *S)
{
  mdlProcessParamsCommon(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c5_flightControlSystem
      ((SFc5_flightControlSystemInstanceStruct*)sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c5_flightControlSystem_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [20] = {
    "eNrdWE1vG0UYHkfBoqhE4UI5VGpu7QVRWlWlEoKm9rp1lRAr65TCBY13X3tHmZ3ZzocdI/Un8A+",
    "49V/0xJEjR34GR7jxznrtmI1JdtZSE1hpvZ5dP/O+88zzfqxJo7tP8NjC8+UNQpp4fR/PDTI73i",
    "vGjaVzdn+TfFmMex8QEiVUma4YSuJ/RDKGEYjQDofsxBMrbNqjiqa6hl1BUzgELbk1TAo/55kYg",
    "gIR4QSZVMbLrmap5Uwcd6yInGX9bcKiJEyk5fETnJDGB4JP/81uZk0PLbaZgsh0AGKTKGlHSYfT",
    "0fksKDNpJRAda5t6c6XBhDZzS9X7lhuWcQhOIOoKbSiyoC9Yb2iogZY58VYI0+EcLdOMMyqqc51",
    "QHUKG6jBwlMX4eWANslfRLtobMEGNVIzyIOUtp/CK2B5HP/dR1tybZ5OaNgzsaMTEyLGrbAoC14",
    "86qcDVsCXHoOgIDoRnDLrVBSf5Bi90WT0Gu06WtWLQprNd0bWwud1gjAzpmnY7kWhRzrUfti+zP",
    "RgDz+23qaE1sDP7HmCtWdyXL6hyUeAZSVawVxYKbEuKmFXf4XEJlSfcbzB5VoCz1EkKYqR54fpi",
    "oos0abWRaQvDqL23V9HeWWxXGFBDGkHl3Kco04AO57rytBszTQfcoZElk6+y8gwgakOJHlrRnkh",
    "1jBz7JtlTrlwk+KEhHkEbDOQJI0B1v6DcVvQ51ZjhnDyONGYsP7uIdfFTCxzRKIHY1RPGYR+0m0",
    "BXzs9YR3ZxtWNmpm3QkWJZ1UiyGmIsJI6l/jSDI3Es5ER0lEzDoiM4R1cAmDWoElgWnmBZUtMOO",
    "l/NawWv+k5ZddqzlBpOB04bT0FgZXFrdZWQRhhVgcDWDR1aBxuyH7G0C820wXZqGuQxEOf96CcN",
    "v370o2J8fxFLXd1XuFMUy7DATml3kDd70Gcp5DdCij3FbFgczu5dcmr32sb5djfwW6MmjqyJe7a",
    "E21zBz8dLuO1iHD34YcjZKHFJ2CjJwynynp7143oFvlf5X8aRM7hTnufXO0v4xgq7ZOm6zv48Xs",
    "J9WLKzWcI1C84++/kX+/r5HX17++1Pb7Z+/Wsd+7956nmrGN+c92eLCjY+k+Sr6OFGSQ9urA/D/",
    "vhh96GwL787fPo8aMW94FH4LJ9vx9Pf+f0dPA0muDxfqqgbF+9abkzt7B3Azf/Fkr/NC+a/tqQn",
    "Qv74ej38zuMyfhVfzRJfzVn/NgD1T/1e9XxxWfnpMv2skr8a7xhH3jFu3fX55uX/+u/vnpMPSOn",
    "321d4HeVr3fp81db1O/GrR7eK8VeLd+dWwni8onsvHmODPVz19H+i7z89+Zv3C4Hjr/jz7/v7u4",
    "LyKbbrs9eh4nZPuf+dFo8UUL36negy6hBZ0f+tqvfXS/HtxhMmYjnRn35+78G9dera32t/AdY=",
    ""
  };

  static char newstr [1425] = "";
  newstr[0] = '\0';
  for (i = 0; i < 20; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c5_flightControlSystem(SimStruct *S)
{
  const char* newstr = sf_c5_flightControlSystem_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(1975557167U));
  ssSetChecksum1(S,(1932020349U));
  ssSetChecksum2(S,(2377781287U));
  ssSetChecksum3(S,(4190637731U));
}

static void mdlRTW_c5_flightControlSystem(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c5_flightControlSystem(SimStruct *S)
{
  SFc5_flightControlSystemInstanceStruct *chartInstance;
  chartInstance = (SFc5_flightControlSystemInstanceStruct *)utMalloc(sizeof
    (SFc5_flightControlSystemInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc5_flightControlSystemInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c5_flightControlSystem;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c5_flightControlSystem;
  chartInstance->chartInfo.mdlStart = sf_opaque_mdl_start_c5_flightControlSystem;
  chartInstance->chartInfo.mdlTerminate =
    sf_opaque_mdl_terminate_c5_flightControlSystem;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c5_flightControlSystem;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c5_flightControlSystem;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c5_flightControlSystem;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c5_flightControlSystem;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c5_flightControlSystem;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c5_flightControlSystem;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c5_flightControlSystem;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c5_flightControlSystem;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartEventFcn = NULL;
  chartInstance->S = S;
  chartInstance->chartInfo.dispatchToExportedFcn = NULL;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  mdl_setup_runtime_resources_c5_flightControlSystem(chartInstance);
}

void c5_flightControlSystem_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c5_flightControlSystem(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_flightControlSystem(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_flightControlSystem(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_flightControlSystem_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
