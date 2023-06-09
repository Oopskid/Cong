#pragma once
#include "BlockChain.h"

#ifndef TEA_AVALANCHE
  #define TEA_AVALANCHE 32 // Number of permutations required for the 'avalanche effect' when seeding a TEA sequence
#endif
#ifndef TEA_STIR
  #define TEA_STIR 6 // Number of permutations required for the next statistically random TEA value 
#endif

namespace Cg
{
  class TEAGenerator : public ChainGenerator
  {
    public:
    TEAGenerator(uint32_t magic = 0x9e3779b9);
    void seed(uint32_t keyValue[4]);
    void associate(uint32_t xV, uint32_t yV);
    uint64_t next() final;
    uint64_t getResult() final;

    protected:
    void stir(); // A single round of TEA
    inline uint32_t& x() { return values[0]; }
    inline uint32_t& y() { return values[1]; }

    private:
    // Used between rounds
    const uint32_t delta; // Magic number
    uint32_t sum; // Rolling value

    // Inputs/outputs
    uint32_t values[2]; // Values at play in the generator
    uint32_t key[4]; // 128 bit key
  };
}