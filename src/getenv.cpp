//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: getenv.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 09-Jul-2022 18:30:27
//

// Include Files
#include "getenv.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cstddef>
#include <stdlib.h>
#include <string.h>

// Function Definitions
//
// Arguments    : ::coder::array<char, 2U> &value
// Return Type  : void
//
namespace coder {
void b_getenv(::coder::array<char, 2U> &value)
{
  char *rawValue;
  rawValue = getenv("AUV");
  if (rawValue == NULL) {
    value.set_size(1, 0);
  } else {
    size_t length;
    length = strlen(rawValue);
    value.set_size(1, (int)length);
    memcpy((void *)&value[0], (void *)rawValue,
           (size_t)(int)length * sizeof(char));
  }
}

} // namespace coder

//
// File trailer for getenv.cpp
//
// [EOF]
//
