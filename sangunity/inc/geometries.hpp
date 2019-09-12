#ifndef _SANGUNITY_GEOMETRIES_HPP
#define _SANGUNITY_GEOMETRIES_HPP

#include "cg_math.hpp"
#include "ray.hpp"
#include "hit.hpp"
#include <optional>

namespace sangunity {

    struct plane final {
        point_3d anchor;
        direction_3d normal;
    };
    std::optional<hit> intersect(plane p, ray r);
    
    struct sphere final {
        point_3d center;
        double radius;
    };
    std::optional<hit> intersect(sphere s, ray r);
}

#endif
