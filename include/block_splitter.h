#ifndef BLOCK_SPLITTER_H
#define BLOCK_SPLITTER_H

#include <vector>
#include <cstddef>

std::vector<std::vector<char>> split_into_blocks(
    const std::vector<char>& data,
    std::size_t block_size
);

#endif
