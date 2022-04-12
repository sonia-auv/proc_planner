//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: LMFsolve.h
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 12-Apr-2022 11:44:16
//

#ifndef LMFSOLVE_H
#define LMFSOLVE_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace coder {
class anonymous_function;

}

// Function Declarations
namespace coder {
namespace matlabshared {
namespace tracking {
namespace internal {
namespace scenario {
void LMFsolve(const anonymous_function *FUN, ::coder::array<double, 1U> &x);

void fletcher(double S, double Snew, const ::coder::array<double, 1U> &dx,
              const ::coder::array<double, 1U> &v,
              const ::coder::array<double, 2U> &Jtri, double *lambda,
              double *lambdac);

void mulJt(const ::coder::array<double, 2U> &Jtri,
           const ::coder::array<double, 1U> &x, ::coder::array<double, 1U> &y);

void solveDampenedHessian(const ::coder::array<double, 2U> &Jtri, double lambda,
                          const ::coder::array<double, 1U> &v,
                          ::coder::array<double, 1U> &dx);

} // namespace scenario
} // namespace internal
} // namespace tracking
} // namespace matlabshared
} // namespace coder
void j_binary_expand_op(coder::array<bool, 1U> &in1,
                        const coder::array<double, 1U> &in2, const int in3[2]);

#endif
//
// File trailer for LMFsolve.h
//
// [EOF]
//
