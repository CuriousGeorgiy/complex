#include "complex/Complex.hpp"

#include "doctest/doctest.h"

#include "flt/Comparison.hpp"

#include <cmath>
#include <numbers>

TEST_SUITE_BEGIN("complex");

TEST_CASE("construction") {
    SUBCASE("from another complex") {
        Complex x{Complex{1, 1}};
        REQUIRE(almost_equal(x.re_, 1));
        REQUIRE(almost_equal(x.im_, 1));
    }

    SUBCASE("from real and imaginary part") {
        Complex x{1, 1};
        REQUIRE(almost_equal(x.re_, 1));
        REQUIRE(almost_equal(x.im_, 1));
    }

    SUBCASE("from real") {
        Complex x{1};
        REQUIRE(almost_equal(x.re_, 1));
        REQUIRE(almost_equal(x.im_, 0));
    }
}

TEST_CASE("assignment") {
    SUBCASE("from another complex") {
        Complex x{0, 0};
        x = {1, 1};
        REQUIRE(almost_equal(x.re_, 1));
        REQUIRE(almost_equal(x.im_, 1));
    }

    SUBCASE("from another real") {
        Complex x{0, 0};
        x = 1;
        REQUIRE(almost_equal(x.re_, 1));
        REQUIRE(almost_equal(x.im_, 0));
    }
}

TEST_CASE("compound") {
    SUBCASE("complex += complex") {
        Complex x{0, 0};
        x += {1, 1};
        REQUIRE(almost_equal(x.re_, 1));
        REQUIRE(almost_equal(x.im_, 1));
    }

    SUBCASE("complex += real") {
        Complex x{0, 0};
        x += 1;
        REQUIRE(almost_equal(x.re_, 1));
        REQUIRE(almost_equal(x.im_, 0));
    }

    SUBCASE("complex -= complex") {
        Complex x{0, 0};
        x -= {1, 1};
        REQUIRE(almost_equal(x.re_, -1));
        REQUIRE(almost_equal(x.im_, -1));
    }

    SUBCASE("complex -= real") {
        Complex x{0, 0};
        x -= 1;
        REQUIRE(almost_equal(x.re_, -1));
        REQUIRE(almost_equal(x.im_, 0));
    }

    SUBCASE("complex *= complex") {
        Complex x{1, 2};
        x *= {3, 4};
        REQUIRE(almost_equal(x.re_, -5));
        REQUIRE(almost_equal(x.im_, 10));
    }

    SUBCASE("complex *= real") {
        Complex x{1, 2};
        x *= 3;
        REQUIRE(almost_equal(x.re_, 3));
        REQUIRE(almost_equal(x.im_, 6));
    }

    SUBCASE("complex /= complex") {
        Complex x{1, 2};
        x /= {3, 4};
        REQUIRE(almost_equal(x.re_, 11.f / 25));
        REQUIRE(almost_equal(x.im_, 2.f / 25));
    }

    SUBCASE("complex /= real") {
        Complex x{1, 2};
        x /= 3;
        REQUIRE(almost_equal(x.re_, 1.f / 3));
        REQUIRE(almost_equal(x.im_, 2.f / 3));
    }
}

TEST_CASE("unary") {
    SUBCASE("+") {
        Complex z{1, 2};
        z = +z;
        REQUIRE(almost_equal(z.re_, 1));
        REQUIRE(almost_equal(z.im_, 2));
    }

    SUBCASE("-") {
        Complex z{1, 2};
        z = -z;
        REQUIRE(almost_equal(z.re_, -1));
        REQUIRE(almost_equal(z.im_, -2));
    }
}

TEST_CASE("binary") {
    SUBCASE("complex + complex") {
        Complex x{1, 2};
        Complex y{3, 4};
        Complex z{0, 0};
        z = x + y;
        REQUIRE(almost_equal(z.re_, 4));
        REQUIRE(almost_equal(z.im_, 6));
    }

    SUBCASE("complex + real") {
        Complex x{1, 2};
        Complex y{0, 0};
        y = x + 5;
        REQUIRE(almost_equal(y.re_, 6));
        REQUIRE(almost_equal(y.im_, 2));
    }

    SUBCASE("real + complex") {
        Complex x{1, 2};
        Complex y{0, 0};
        y = 5 + x;
        REQUIRE(almost_equal(y.re_, 6));
        REQUIRE(almost_equal(y.im_, 2));
    }

    SUBCASE("complex - complex") {
        Complex x{1, 2};
        Complex y{3, 4};
        Complex z{0, 0};
        z = x - y;
        REQUIRE(almost_equal(z.re_, -2));
        REQUIRE(almost_equal(z.im_, -2));
    }

    SUBCASE("complex - real") {
        Complex x{1, 2};
        Complex y{0, 0};
        y = x - 5;
        REQUIRE(almost_equal(y.re_, -4));
        REQUIRE(almost_equal(y.im_, 2));
    }

    SUBCASE("real - complex") {
        Complex x{1, 2};
        Complex y{0, 0};
        y = 5 - x;
        REQUIRE(almost_equal(y.re_, 4));
        REQUIRE(almost_equal(y.im_, -2));
    }

    SUBCASE("complex * complex") {
        Complex x{1, 2};
        Complex y{3, 4};
        Complex z{0, 0};
        z = x * y;
        REQUIRE(almost_equal(z.re_, -5));
        REQUIRE(almost_equal(z.im_, 10));
    }

    SUBCASE("complex * real") {
        Complex x{1, 2};
        Complex y{0, 0};
        y = x * 3;
        REQUIRE(almost_equal(y.re_, 3));
        REQUIRE(almost_equal(y.im_, 6));
    }

    SUBCASE("complex * real") {
        Complex x{1, 2};
        Complex y{0, 0};
        y = 3 * x;
        REQUIRE(almost_equal(y.re_, 3));
        REQUIRE(almost_equal(y.im_, 6));
    }

    SUBCASE("complex / complex") {
        Complex x{1, 2};
        Complex y{3, 4};
        Complex z{0, 0};
        z = x / y;
        REQUIRE(almost_equal(z.re_, 11.f / 25));
        REQUIRE(almost_equal(z.im_, 2.f / 25));
    }

    SUBCASE("complex / real") {
        Complex x{1, 2};
        Complex y{0, 0};
        y = x / 3;
        REQUIRE(almost_equal(y.re_, 1.f / 3));
        REQUIRE(almost_equal(y.im_, 2.f / 3));
    }

    SUBCASE("real / complex") {
        Complex x{1, 2};
        Complex y{0, 0};
        y = 3 / x;
        REQUIRE(almost_equal(y.re_, 3.f / 5));
        REQUIRE(almost_equal(y.im_, -6.f / 5));
    }

    SUBCASE("complex == complex") {
        Complex x{1, 2};
        Complex y{1, 2};
        REQUIRE(x == y);
    }

    SUBCASE("complex == real") {
        Complex x{1, 0};
        REQUIRE(x == 1);
    }

    SUBCASE("real == complex") {
        Complex x{1, 0};
        REQUIRE(1 == x);
    }

    SUBCASE("complex != complex") {
        Complex x{1, 2};
        Complex y{3, 4};
        REQUIRE(x != y);
    }

    SUBCASE("complex != real") {
        Complex x{1, 0};
        REQUIRE(x != 2);
        x = {1, 2};
        REQUIRE(x != 1);
    }

    SUBCASE("real != complex") {
        Complex x{1, 0};
        REQUIRE(2 != x);
        x = {1, 2};
        REQUIRE(1 != x);
    }
}

TEST_CASE("abs") {
    Complex x{1, 2};
    REQUIRE(almost_equal(x.abs(), sqrt(5)));
}

TEST_CASE("phase") {
    Complex x{1, 2};
    REQUIRE(almost_equal(x.phase(), atan2(2, 1)));
}

TEST_CASE("norm") {
    Complex x{1, 2};
    REQUIRE(almost_equal(x.norm(), 5));
}

TEST_CASE("conj") {
    Complex x{1, 2};
    Complex y{1, -2};
    REQUIRE(x.conj() == y);
}

TEST_CASE("polar") {
    Complex x{2 * sin(std::numbers::pi_v<float> / 3),
              2 * cos(std::numbers::pi_v<float> / 3)};
    REQUIRE(polar(2, std::numbers::pi_v<float> / 3) == x);
}

TEST_SUITE_END;