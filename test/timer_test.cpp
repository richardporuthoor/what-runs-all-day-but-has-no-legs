#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>
#include "mock_time.hpp"

using Catch::Approx;

TEST_CASE("Timer elapsed using mock time") {
    MockTime m;
    Timer t(&m);

    m.set(0);
    t.start();

    m.set(CLOCKS_PER_SEC * 5);
    t.stop();

    REQUIRE(t.elapsed() == Approx(5.0));
}

TEST_CASE("Timer add using mock time") {
    MockTime m1, m2;
    Timer t1(&m1), t2(&m2);

    m1.set(0);
    t1.start();
    m1.set(CLOCKS_PER_SEC * 10);
    t1.stop();

    m2.set(0);
    t2.start();
    m2.set(CLOCKS_PER_SEC * 7);
    t2.stop();

    Timer sum = t1.add(t2);

    REQUIRE(sum.elapsed() == Approx(17.0));
}

TEST_CASE("Timer subtract using mock time") {
    MockTime m1, m2;
    Timer t1(&m1), t2(&m2);

    m1.set(0);
    t1.start();
    m1.set(CLOCKS_PER_SEC * 12);
    t1.stop();

    m2.set(0);
    t2.start();
    m2.set(CLOCKS_PER_SEC * 5);
    t2.stop();

    Timer diff = t1.subtract(t2);

    REQUIRE(diff.elapsed() == Approx(7.0));
}