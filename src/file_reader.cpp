#include "file_reader.h"
#include <fstream>
#include <iostream>

std::vector<char> read_file(const std::string& filename)
{
    std::ifstream file(filename, std::ios::binary);

    if (!file)
    {
        std::cerr << "Error: Cannot open file " << filename << std::endl;
        return {};
    }

    file.seekg(0, std::ios::end);
    std::size_t size = file.tellg();
    file.seekg(0, std::ios::beg);

    std::vector<char> buffer(size);
    file.read(buffer.data(), size);

    return buffer;
}
