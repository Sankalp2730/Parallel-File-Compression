#include "block_splitter.h"

std::vector<std::vector<char>> split_into_blocks(
    const std::vector<char>& data,
    std::size_t block_size)
{
    std::vector<std::vector<char>> blocks;

    std::size_t total_size = data.size();
    std::size_t offset = 0;

    while (offset < total_size)
    {
        std::size_t current_block_size =
            std::min(block_size, total_size - offset);

        blocks.emplace_back(
            data.begin() + offset,
            data.begin() + offset + current_block_size
        );

        offset += current_block_size;
    }

    return blocks;
}
