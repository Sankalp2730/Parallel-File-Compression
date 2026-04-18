#include "compressor.h"
#include <omp.h>
#include <vector>

std::vector<std::vector<char>> rle_compress_parallel(
    const std::vector<std::vector<char>>& blocks)
{
    std::vector<std::vector<char>> compressed_blocks(blocks.size());

    #pragma omp parallel for
    for (int i = 0; i < static_cast<int>(blocks.size()); ++i)
    {
        compressed_blocks[i] = rle_compress(blocks[i]);
    }

    return compressed_blocks;
}
