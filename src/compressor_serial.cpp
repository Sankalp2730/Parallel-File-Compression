#include "compressor.h"

std::vector<char> rle_compress(const std::vector<char>& data)
{
    std::vector<char> compressed;

    if (data.empty())
        return compressed;

    char current = data[0];
    int count = 1;

    for (std::size_t i = 1; i < data.size(); ++i)
    {
        if (data[i] == current && count < 255)
        {
            count++;
        }
        else
        {
            compressed.push_back(current);
            compressed.push_back(static_cast<char>(count));

            current = data[i];
            count = 1;
        }
    }

    // push last run
    compressed.push_back(current);
    compressed.push_back(static_cast<char>(count));

    return compressed;
}
