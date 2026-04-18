#ifndef TIMER_H
#define TIMER_H

#include <chrono>

class Timer
{
public:
    void start();
    double stop(); // returns time in milliseconds

private:
    std::chrono::high_resolution_clock::time_point begin;
};

#endif
