#pragma once
#ifndef CONG_BITS_H
#define CONG_BITS_H
#include "Common.h"

// Inline defs
#define BITS_ALL ~0

// Inline bit operations
FORCE_INLINE static constexpr size_t BIT(const size_t index) { return (size_t)0x01 << index; }
FORCE_INLINE static constexpr size_t MASK(const size_t bits) { return ~((size_t)BITS_ALL << bits); }
template<typename IntTy> IntTy SET(IntTy value, IntTy mask) { return value | mask; }
template<typename IntTy> IntTy CLEAR(IntTy value, IntTy mask) { return value & ~mask; }
template<typename IntTy> bool SATISFIES(IntTy value, IntTy mask) { return (value & mask) == mask; }

#endif