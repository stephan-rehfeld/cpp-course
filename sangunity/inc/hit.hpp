#ifndef _SANGUNITY_HIT_HPP
#define _SANGUNITY_HIT_HPP

#include "cg_math.hpp"

namespace sangunity {
    struct hit final {
        double t;
        direction_3d normal;
    };
}

#endif