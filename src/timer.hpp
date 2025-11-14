#pragma once

#include <ctime>

class TimeSource {
public:
    virtual long now() const = 0;
    virtual ~TimeSource() = default;
};

class CppTimeSource : public TimeSource {
public:
    long now() const override {
        return std::clock();
    }
};

class Timer {
private:
    long start_clock = 0;
    long stop_clock = 0;
    bool running = false;
    TimeSource* time;

public:
    Timer(TimeSource* t = nullptr);

    void start();
    void stop();
    double elapsed() const;

    void pretty_print() const;
    void set_elapsed_seconds(long seconds);
    Timer add(const Timer& other) const;
    Timer subtract(const Timer& other) const;
};