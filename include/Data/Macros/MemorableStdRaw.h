#pragma once

#ifndef CONG_MEMORABLESTD_H
#define CONG_MEMORABLESTD_H

#include "MemorableImpl.h"

#include <string>

namespace Cg
{
  namespace Memorable
  {
    DeclareRawGenericMemorable(uint32_t)
    DeclareRawGenericMemorable(bool)
    DeclareRawGenericMemorable(char)
    DeclareRawGenericMemorable(Cg::Byte)
    
    template<> bool get<std::string, false>(std::istream* stream, std::string& x) 
    {
      uint32_t expectedSize;
      bool good = get(stream, expectedSize);
      x.reserve(expectedSize);
      return good && put(stream, expectedSize, const_cast<char*>(x.data()));
    }
    template<> std::ostream* out<std::string, false>(std::ostream* stream, std::string* x) 
    {
      uint32_t stringSize = x->size();
      out(stream, &stringSize);
      put(stream, stringSize, x->data());
      return stream;
    }

    template<> size_t getStorageRequirement<std::string, false>(std::string& x)
    { 
      return sizeof(uint32_t) + x.size();
    }

  }
}

#endif