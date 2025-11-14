#include <ctime>
#include <iostream>
#include "timer.hpp"

Timer::Timer(TimeSource* t) {
    if (t == nullptr) t = new CppTimeSource();
    time = t;
}

void Timer::start() {
    start_clock = time->now();
    running = true;
}

void Timer::stop() {
    if (!running) return;
    stop_clock = time->now();
    running = false;
}

double Timer::elapsed() const {
    if (start_clock == 0 && stop_clock == 0 && !running) {
        return 0.0;
    }
    long total_time = running ? time->now() : stop_clock;
    return static_cast<double>(total_time - start_clock) / CLOCKS_PER_SEC;
}

void Timer::pretty_print() const {
    long total = static_cast<long>(elapsed());

    if (total == 0) {
        std::cout << "No time has passed.\n";
        return;
    }

    long hours = total / 3600;
    long minutes = (total % 3600) / 60;
    long seconds = total % 60;

    if (hours == 0 && minutes == 0 && seconds == 1) {
        std::cout << "1 second has passed.\n";
        return;
    }
    if (hours == 0 && minutes == 0) {
        std::cout << seconds << " seconds have passed.\n";
        return;
    }
    if (hours == 0 && minutes == 1 && seconds == 0) {
        std::cout << "1 minute has passed.\n";
        return;
    }
    if (hours == 0 && minutes > 0 && seconds == 0) {
        std::cout << minutes << " minutes have passed.\n";
        return;
    }
    if (hours == 0 && minutes > 0) {
        std::cout << minutes << " minutes and " << seconds << " seconds have passed.\n";
        return;
    }
    if (hours == 1 && minutes == 0 && seconds == 0) {
        std::cout << "1 hour has passed.\n";
        return;
    }

    std::cout << hours << " hours, " << minutes << " minutes, and " << seconds << " seconds have passed.\n";
}

void Timer::set_elapsed_seconds(long seconds) {
    start_clock = 0;
    stop_clock = seconds * CLOCKS_PER_SEC;
    running = false;
}

Timer Timer::add(const Timer& other) const {
    Timer result;
    long s = static_cast<long>(elapsed() + other.elapsed());
    result.set_elapsed_seconds(s);
    return result;
}

Timer Timer::subtract(const Timer& other) const {
    Timer result;
    long s = static_cast<long>(elapsed() - other.elapsed());
    if (s < 0) s = 0;
    result.set_elapsed_seconds(s);
    return result;
}