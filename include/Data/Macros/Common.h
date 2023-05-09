#pragma once
#ifndef CONG_COMMON_H
#define CONG_COMMON_H

#define FORCE_INLINE __forceinline //TODO: Make top level

#define NULL 0
#define HIGH_NULL ~0
#define SHIGH_NULL -1

namespace Cg
{
  // Common types
  typedef unsigned char Byte;
  typedef unsigned short UShort;
  typedef unsigned int UInt;
}

#endif