#pragma once

#include <ctime>

class Timer {
private:
    long start_clock = 0;
    long stop_clock = 0;
    bool running = false;
public:
    void start();
    void stop();
    double elapsed() const;
};
