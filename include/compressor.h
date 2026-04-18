#ifndef COMPRESSOR_H
#define COMPRESSOR_H

#include <vector>

std::vector<char> rle_compress(const std::vector<char>& data);
std::vector<std::vector<char>> rle_compress_parallel(
    const std::vector<std::vector<char>>& blocks);


#endif
