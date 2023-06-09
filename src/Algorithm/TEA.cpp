#include "pch.h"
#include "Algorithm/TEA.h"

namespace Cg
{
  TEAGenerator::TEAGenerator(uint32_t magic) : delta(magic), sum(0), values{0}, key{0} { }
  
  void TEAGenerator::seed(uint32_t keyValue[4])
  {
    key[0] = keyValue[0]; key[1] = keyValue[1];
    key[2] = keyValue[2]; key[3] = keyValue[3];
    sum = 0;
    associate(x(), y());
  }

  void TEAGenerator::associate(uint32_t xV, uint32_t yV)
  {
    x() = xV;
    y() = yV;

    // Cause the avalanche effect to dissociate from the starting values
    for (size_t i = 0; i < TEA_AVALANCHE; ++i) { stir(); }
  }

  uint64_t TEAGenerator::next()
  {
    // Run a sufficient number of rounds to get another number
    for (size_t i = 0; i < TEA_STIR; ++i)
    {
      stir();
    }
    return getResult();
  }

  uint64_t TEAGenerator::getResult()
  {
    return *reinterpret_cast<uint64_t*>(values);
  }

  void TEAGenerator::stir()
  {
    sum += delta;
    x() += ((y() << 4) + key[0]) ^ (y() + sum) ^ ((y() >> 5) + key[1]);
    y() += ((x() << 4) + key[2]) ^ (x() + sum) ^ ((x() >> 5) + key[3]);
  }
}