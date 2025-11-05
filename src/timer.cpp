#include <ctime>

#include "timer.hpp"

void Timer::start() {
   start_clock = std::clock();
   running = true;
}

void Timer::stop() {
   if (!running)
   {
      return;
   }
   stop_clock = std::clock();
   running = false;
}

double Timer::elapsed() const {
   if (start_clock == 0 && stop_clock == 00 && !running) {
      return 0.0;
   }
   long total_time = running ? std::clock() : stop_clock;
   return static_cast<double>(total_time - start_clock) / CLOCKS_PER_SEC;
}

   