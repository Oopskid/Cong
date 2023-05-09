#pragma once
#ifndef CONG_BITS_H
#define CONG_BITS_H
#include "Common.h"

// Inline defs
#define BITS_ALL ~0

// Inline bit operations
FORCE_INLINE static constexpr size_t BIT(const size_t index) { return size_t(0x01) << index; }

#endif