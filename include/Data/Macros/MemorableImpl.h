#pragma once
#include "Memorable.h"

namespace Cg
{
  namespace Memorable
  {
    template<typename Primitive>
    bool put(std::istream* stream, Primitive& whereTo)
    {
      return stream->read(reinterpret_cast<char*>(&whereTo), sizeof(Primitive)).good();
    }

    template<typename Primitive>
    bool put(std::istream* stream, size_t count, Primitive* whereTo)
    {
      return stream->read(reinterpret_cast<char*>(whereTo), sizeof(Primitive) * count).good();
    }

    template<typename Primitive>
    std::ostream* put(std::ostream* stream, Primitive* whereFrom)
    {
      return &stream->write(reinterpret_cast<Literal>(whereFrom), sizeof(Primitive));
    }

    template<typename Primitive>
    std::ostream* put(std::ostream* stream, size_t count, Primitive* whereFrom)
    {
      return &stream->write(reinterpret_cast<Literal>(whereFrom), sizeof(Primitive) * count);
    }

    template<typename T, bool F>
    PacketWrapper<T, F>::PacketWrapper(T* data)
    {
      package = data;
    }
    template<typename T, bool F>
    bool PacketWrapper<T, F>::get(std::istream* stream)
    {
      return Memorable::get<T, F>(stream, *package);
    }
    template<typename T, bool F>
    std::ostream* PacketWrapper<T, F>::out(std::ostream* stream) const
    {
      return Memorable::out<T, F>(stream, package);
    }
    template<typename T, bool F>
    size_t PacketWrapper<T, F>::getStorageRequirement() const
    {
      return Memorable::getStorageRequirement<T, F>(*package);
    }
    template<typename T, bool F>
    static std::ostream& operator<<(std::ostream& stream, const PacketWrapper<T, F>& packet)
    {
      packet.out(&stream);
      return stream;
    }
    template<typename T, bool F>
    std::istream& operator>>(std::istream& stream, PacketWrapper<T, F>& packet)
    {
      packet.get(&stream);
      return stream;
    }

    template<typename T, bool F>
    T* PacketWrapperFactory<T, F>::produce(PacketWrapper<T, F>*& newPacket) const
    {
      T* newData = new T();
      newPacket = new PacketWrapper<T, F>(newData);
      return newData;
    }

    template<typename T, bool F>
    void* PacketWrapperFactory<T, F>::produce(Packet*& newPacket) const
    {
      return (void*)produce((PacketWrapper<T, F>*&)(newPacket));
    }
  }
}