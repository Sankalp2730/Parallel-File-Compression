#include <iostream>
#include <omp.h>

#include "file_reader.h"
#include "block_splitter.h"
#include "compressor.h"
#include "timer.h"

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cout << "Usage: compressor <input_file>\n";
        return 1;
    }

    std::string input_file = argv[1];

    auto data = read_file(input_file);
    if (data.empty())
    {
        std::cout << "Error: Input file is empty or cannot be read.\n";
        return 1;
    }

    const std::size_t BLOCK_SIZE = 64 * 1024;
    auto blocks = split_into_blocks(data, BLOCK_SIZE);

    Timer timer;

    /* ---------- SERIAL COMPRESSION ---------- */
    timer.start();
    std::vector<char> serial_output;
    for (const auto& block : blocks)
    {
        auto c = rle_compress(block);
        serial_output.insert(serial_output.end(), c.begin(), c.end());
    }
    double serial_time = timer.stop();

    /* ---------- PARALLEL COMPRESSION ---------- */
    int thread_counts[] = {2, 4, 8};

    std::cout << "\nInput file size: " << data.size() << " bytes\n";
    std::cout << "Compressed size: " << serial_output.size() << " bytes\n";
    std::cout << "Compression ratio: "
              << (double)serial_output.size() / data.size()
              << "\n\n";

    std::cout << "Serial time (ms): " << serial_time << "\n";

    for (int t : thread_counts)
    {
        omp_set_num_threads(t);

        timer.start();
        rle_compress_parallel(blocks);
        double parallel_time = timer.stop();

        double speedup = serial_time / parallel_time;

        std::cout << "Threads: " << t
                  << " | Parallel time (ms): " << parallel_time
                  << " | Speedup: " << speedup << "\n";
    }

    return 0;
}
