#include "Timer.h"

#include <iostream>

Timer::Timer() {
    m_StartTimepoint = std::chrono::high_resolution_clock::now();
}

Timer::~Timer() {
    Stop();
}

void Timer::Stop() const {
    const auto endTimepoint = std::chrono::high_resolution_clock::now();

    const auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimepoint).time_since_epoch().count();
    const auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();

    const auto duration = end - start;
    const double ms = static_cast<double>(duration) * 0.001;

    std::cout << " " << duration << "us (" << ms << "ms) ";
}
