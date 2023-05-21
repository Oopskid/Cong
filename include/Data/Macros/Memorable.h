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