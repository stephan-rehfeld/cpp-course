#ifndef _SANGUNITY_CAMERA_LOADER_HPP
#define _SANGUNITY_CAMERA_LOADER_HPP

#include "camera.hpp"
#include "loader_helper.hpp"
#include <string>

namespace sangunity {
    camera load_camera(const std::string filename);
}

#endif