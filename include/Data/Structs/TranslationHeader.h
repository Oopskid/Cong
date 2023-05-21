#pragma once
#include "Data/Macros/Common.h"

namespace Cg
{
  namespace Memorable
  {
    // For managing I/O across device and contexts
    struct TranslationHeader
    {
      public:
      size_t wordsize; // Integer size
      size_t charsize; // String character size
    };
  }
}