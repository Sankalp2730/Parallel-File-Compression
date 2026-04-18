#include "timer.h"

void Timer::start()
{
    begin = std::chrono::high_resolution_clock::now();
}

double Timer::stop()
{
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - begin;
    return elapsed.count();
}
