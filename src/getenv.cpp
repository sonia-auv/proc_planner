//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// getenv.cpp
//
// Code generation for function 'getenv'
//

// Include files
#include "getenv.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cstddef>
#include <stdlib.h>
#include <string.h>

// Function Definitions
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

// End of code generation (getenv.cpp)
