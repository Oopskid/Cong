#pragma once
#include <cstdint>

namespace Cg
{
  // Base class denoting a generator which is expected to produce sequential numbers one after another
  class ChainGenerator
  {
    public:
    virtual uint64_t next() = 0; // Proceed to the next element
    virtual uint64_t getResult() = 0; // Return the current element (which is typically cached)
    // Returns [0, 1]
    inline float getFloat() { return float(getResult()) / float(UINT64_MAX); }
    // Returns [-1, 1]
    inline float getNormalisedFloat() { return 2.f * getFloat() - 1.f; } 
  };

}