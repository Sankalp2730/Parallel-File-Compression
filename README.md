Parallel File Compression Using OpenMP

Project Overview

This project implements a parallel file compression system using shared-memory parallelism on a multi-core CPU.
The primary goal is to reduce compression time by dividing the input file into independent blocks and compressing them concurrently using OpenMP, while preserving lossless compression.

The project demonstrates the performance difference between serial and parallel compression, and evaluates scalability with varying numbers of threads.

Key Features

Lossless file compression

Block-based parallelism

Serial vs Parallel performance comparison

Shared-memory parallelism using OpenMP

Executed on local multi-core system

Designed for experimental evaluation and research publication

Technology Stack

Programming Language: C++

Parallel Library: OpenMP

Compiler: GCC (MinGW-w64)

IDE: Visual Studio Code

Operating System: Windows

Parallel File Compression/
│
├── src/                # Source (.cpp) files
├── include/            # Header (.h) files
├── input_files/        # Test input files
├── output_files/       # (Optional) compressed outputs
├── experiments/        # Raw experiment results
├── results/            # Graphs and tables
├── docs/               # Reference documents
├── paper/              # Research paper drafts
├── build/              # Compiled executables
└── README.txt


Compression Method

Compression Type: Lossless

Algorithm Used: Run-Length Encoding (RLE)

Parallel Strategy: Block-level parallelism

Block Strategy

Input file is divided into fixed-size blocks (64 KB)

Each block is compressed independently

Blocks are processed in parallel using OpenMP threads

Compressed blocks are merged in original order

g++ -std=c++17 -fopenmp src/main.cpp src/file_reader.cpp src/block_splitter.cpp src/compressor_serial.cpp src/compressor_parallel.cpp src/timer.cpp -Iinclude -o build/compressor.exe


fsutil file createnew input_files\small.txt 102400
fsutil file createnew input_files\medium.txt 5242880
fsutil file createnew input_files\large.txt 20971520

#To run the code#
build\compressor.exe input_files\small.txt
build\compressor.exe input_files\medium.txt
build\compressor.exe input_files\large.txt


Output Details

For each run, the program displays:

Input file size

Compressed file size

Compression ratio

Serial execution time

Parallel execution time (2, 4, 8 threads)

Speedup values

Performance Evaluation Metrics

Compression Time

Compression Ratio

Speedup

Speedup = Serial Time / Parallel Time


Experimental Observations

Small files show lower speedup due to parallel overhead

Medium and large files demonstrate significant performance improvement

Speedup increases with thread count until saturation

Results validate the effectiveness of block-based shared-memory parallelism

Base Research Inspiration

This project is inspired by a parallel compression approach discussed in academic literature, adapted from a cloud-based model to a local shared-memory OpenMP implementation.

Conclusion

The project successfully demonstrates how parallel processing can significantly improve file compression performance on multi-core systems.
The implementation is modular, extensible, and suitable for academic evaluation, viva presentations, and research publication.
