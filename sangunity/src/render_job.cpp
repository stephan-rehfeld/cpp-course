#include "render_job.hpp"
#include <vector>
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <iostream>

std::optional<sangunity::render_job> sangunity::parse_render_job(int argc, char *argv[]) {
    std::vector<std::string> arguments;
    for(size_t i = 0; i < argc; ++i) arguments.push_back(argv[i]);

    std::optional<std::string> scene_filename;
    std::optional<std::string> camera_filename;
    std::optional<area_2d<int>> image_size;
    std::optional<std::string> out_filename;

    if(auto it = std::find(arguments.begin(), arguments.end(), "--scene"); it != arguments.end()) {
        ++it;
        if(it != arguments.end()) {
            scene_filename = *it;
        } else {
            std::cerr << "scene filename is missing" << std::endl;
            return std::nullopt;
        }
    } else {
        std::cerr << "--scene is missing" << std::endl;
        return std::nullopt;
    }

    if(auto it = std::find(arguments.begin(), arguments.end(), "--camera"); it != arguments.end()) {
        ++it;
        if(it != arguments.end()) {
            camera_filename = *it;
        } else {
            std::cerr << "camera filename is missing" << std::endl;
            return std::nullopt;
        }
    } else {
        std::cerr << "--camera is missing" << std::endl;
        return std::nullopt;
    }

    if(auto it = std::find(arguments.begin(), arguments.end(), "--size"); it != arguments.end()) {
        ++it;
        if(it != arguments.end()) {
            auto size_string = *it;
            std::vector<std::string> result; 
            boost::split(result, size_string, boost::is_any_of(","));
            if(result.size() != 2) {
                std::cerr << "-failed to parse image size" << std::endl;
                return std::nullopt;
            }
            auto width = std::stoi(result[0]);
            auto height = std::stoi(result[1]);
            image_size = area_2d<int>{width, height};
        } else {
            std::cerr << "image size is missing" << std::endl;
            return std::nullopt;
        }
    } else {
        std::cerr << "--size is missing" << std::endl;
        return std::nullopt;
    }

    if(auto it = std::find(arguments.begin(), arguments.end(), "--out"); it != arguments.end()) {
        ++it;
        if(it != arguments.end()) {
            out_filename = *it;
        } else {
            std::cerr << "out filename is missing" << std::endl;
            return std::nullopt;
        }
    } else {
        std::cerr << "--out is missing" << std::endl;
        return std::nullopt;
    }

    return render_job{*scene_filename, *camera_filename, *image_size, *out_filename};
}