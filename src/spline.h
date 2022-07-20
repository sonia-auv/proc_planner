//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// spline.h
//
// Code generation for function 'spline'
//

#ifndef SPLINE_H
#define SPLINE_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
void spline(const ::coder::array<double, 1U> &x,
            const ::coder::array<double, 2U> &y,
            ::coder::array<double, 2U> &output_breaks,
            ::coder::array<double, 2U> &output_coefs);

}

#endif
// End of code generation (spline.h)
