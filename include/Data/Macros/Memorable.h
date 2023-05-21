#pragma once

#ifndef CONG_MEMORABLE_H
#define CONG_MEMORABLE_H

#include "Common.h"
#include <iostream>

namespace Cg
{
  // Representing the need to I/O classes and structs
  namespace Memorable
  {
    // Static unspecialised inline I/O functions
    template<typename T, bool formatted = false> // TODO: how to get formatted distinction with type deduction
    bool get(std::istream* stream, T&) { return false; }
    template<typename T, bool formatted = false>
    std::ostream* out(std::ostream* stream, T*) { return nullptr; }
    template<typename T, bool formatted = false>
    size_t getStorageRequirement(T&) { return HIGH_NULL; }

    // I/O fixed raw primitive (dangerous)
    template<typename Primitive> bool put(std::istream* stream, Primitive& whereTo);
    template<typename Primitive> bool put(std::istream* stream, size_t count, Primitive* whereTo);
    template<typename Primitive> std::ostream* put(std::ostream* stream, Primitive* whereFrom);
    template<typename Primitive> std::ostream* put(std::ostream* stream, size_t count, Primitive* whereFrom);

    // Standard memorable I/O (raw data)
    #define DeclareRawGenericMemorable(T) template<> bool get<T, false>(std::istream* stream, T& x) { return put(stream, x); }\
                                          template<> std::ostream* out<T, false>(std::ostream* stream, T* x) { return put(stream, x); }\
                                          template<> size_t getStorageRequirement<T, false>(T&) { return sizeof(T); }
    // Defines friend memorable I/O for a class/struct (raw data)
    #define ExportRawClassMemorable(T) friend bool Cg::Memorable::get<T, false>(std::istream* stream, T& x);\
                                       friend std::ostream* Cg::Memorable::out<T, false>(std::ostream* stream, T* x);\
                                       friend size_t Cg::Memorable::getStorageRequirement<T, false>(T& x);
    // Defines friend memorable I/O for a class/struct (formatted)
    #define ExportFormattedClassMemorable(T) friend bool Cg::Memorable::get<T, true>(std::istream* stream, T& x);\
                                             friend std::ostream* Cg::Memorable::out<T, true>(std::ostream* stream, T* x);\
                                             friend size_t Cg::Memorable::getStorageRequirement<T, true>(T& x);
    // All together now
    #define ExportAllClassMemorable(T) ExportRawClassMemorable(T) ExportFormattedClassMemorable(T)

    // Dynamic wrapper for arbitrary management
    class Packet
    {
      public:
      virtual bool get(std::istream* stream) = 0;
      virtual std::ostream* out(std::ostream* stream) const = 0;
      virtual size_t getStorageRequirement() const = 0;
    };

    template<typename T, bool formatted = false> class PacketWrapper : Packet
    {
      public:
      PacketWrapper(T* data);

      virtual bool get(std::istream* stream) override;
      virtual std::ostream* out(std::ostream* stream) const override;
      virtual size_t getStorageRequirement() const override;

      private:
      T* package;
    };

    template<typename T> class FormattedPacketWrapper : public PacketWrapper<T, true> {
      public:
      FormattedPacketWrapper(T* data) : PacketWrapper(data) {  }
    };
  }
}

#endif