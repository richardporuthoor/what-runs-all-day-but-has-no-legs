#pragma once
#include "timer.hpp"

class MockTime : public TimeSource {
public:
    long value = 0;

    long now() const override {
        return value;
    }

    void set(long v) {
        value = v;
    }
};