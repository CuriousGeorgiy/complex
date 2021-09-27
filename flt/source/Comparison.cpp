#include "flt/Comparison.hpp"

#include <cmath>
#include <limits>

bool almost_equal(float x, float y) {
    return fabs(x - y) <=
           std::numeric_limits<float>::epsilon() * fabs(x + y) ||
           fabs(x - y) < std::numeric_limits<float>::min();
}