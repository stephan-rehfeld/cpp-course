#ifndef _SANGUNITY_RAY_HPP
#define _SANGUNITY_RAY_HPP

#include "cg_math.hpp"
#include <iostream>

namespace sangunity {

    struct ray final {
        point_3d origin;
        direction_3d direction;
    };

    point_3d point_on_ray(ray r, double t);

    std::ostream & operator << (std::ostream &out, const ray& r);
}

#endif