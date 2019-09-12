#ifndef _SANGUNITY_CAMERA_HPP
#define _SANGUNITY_CAMERA_HPP

#include "cg_math.hpp"
#include "units.hpp"
#include "ray.hpp"
#include "cg_math.hpp"

namespace sangunity {
    struct camera final {
        point_3d position;
        direction_3d gaze_direction;
        direction_3d up_vector;
        units::radians<double> field_of_view;
    };

    ray ray_for(camera camera, area_2d<int> image_size, point_2d<int> pixel);
}

#endif