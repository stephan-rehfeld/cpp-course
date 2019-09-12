#ifndef _SANGUNITY_RENDER_JOB_HPP
#define _SANGUNITY_RENDER_JOB_HPP

#include <string>
#include <optional>
#include "cg_math.hpp"

namespace sangunity {
    struct render_job final {
        std::string scene_filename;
        std::string camera_filename;
        area_2d<int> image_size;
        std::string out_filename;
    };

    std::optional<render_job> parse_render_job(int argc, char *argv[]);
}

#endif