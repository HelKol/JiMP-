//
// Created by rencpawe on 28.03.17.
//

#include "MemoryChunk.h"

namespace memorychunk{
    MemoryChunk::MemoryChunk(const size_t &sz) {
        size= sz;
        ptr= new int8_t[size];
    }
    MemoryChunk::MemoryChunk(const MemoryChunk &sz) {

    }

    MemoryChunk::MemoryChunk(MemoryChunk &&sz) : ptr{nullptr}, size{sz.size}{
        std::swap(ptr, sz.ptr);
    }

    MemoryChunk &MemoryChunk::operator=(const MemoryChunk &sz) {

    }

    MemoryChunk &MemoryChunk::operator=(MemoryChunk &&sz) {

    }

    int8_t *MemoryChunk::MemoryAt(size_t offset) const {
        return ptr+offset;
    }

    size_t MemoryChunk::ChunkSize() const {
        return size;
    }

    MemoryChunk::~MemoryChunk() {
        delete [] ptr;
    }
}