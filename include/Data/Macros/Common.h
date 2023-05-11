#pragma once
#ifndef CONG_COMMON_H
#define CONG_COMMON_H

#define FORCE_INLINE __forceinline //TODO: Make top level

#define NULL 0
#define HIGH_NULL ~0
#define SHIGH_NULL -1

namespace Cg
{
  // Common primitive types
  typedef unsigned char Byte;
  typedef unsigned short UShort;
  typedef unsigned int UInt;

  // C-style strings
  typedef const char* CString;
  typedef const char* CStringC; // Constant c-style string
  typedef const char* Literal; // Hard read only
}

#endif