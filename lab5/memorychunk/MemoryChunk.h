//
// Created by rencpawe on 28.03.17.
//

#ifndef JIMP_EXERCISES_MEMORYCHUNK_H
#define JIMP_EXERCISES_MEMORYCHUNK_H


#include <cstdint>
#include <algorithm>

namespace memorychunk
{
    class MemoryChunk {
    public:
//        MemoryChunk(size_t sz);
        MemoryChunk(const size_t &sz);

        MemoryChunk(const MemoryChunk &sz);
        MemoryChunk(MemoryChunk &&sz);
        MemoryChunk &operator=(const MemoryChunk &sz);
        MemoryChunk &operator=(MemoryChunk &&sz);

        int8_t *MemoryAt(size_t offset) const;
        size_t ChunkSize() const;
        ~MemoryChunk();
    private:
        size_t size;
        int8_t* ptr;
    };
}



#endif //JIMP_EXERCISES_MEMORYCHUNK_H
