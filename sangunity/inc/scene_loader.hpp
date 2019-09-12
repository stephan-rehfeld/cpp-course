#ifndef _SANGUNITY_SCENE_LOADER_HPP
#define _SANGUNITY_SCENE_LOADER_HPP

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <string>

#include "cg_concepts.hpp"
#include "scene.hpp"
#include "loader_helper.hpp"

namespace sangunity {
    template<Intersectable... T>
    scene<T...> load_scene(const std::string& filename) {
        scene<T...> scene{};

        boost::property_tree::ptree scene_json;
        boost::property_tree::read_json(filename, scene_json);

        for( auto& geometry_json : scene_json.get_child("geometries")) {
            auto geometry_type = geometry_json.second.get<std::string>("type");
            if( "plane" == geometry_type ) {
                auto anchor{ parse_to<point_3d>(geometry_json.second.get_child("anchor"))};
                auto normal{ parse_to<direction_3d>(geometry_json.second.get_child("normal"))};
                scene.add_intersectable(plane{anchor, normal});
            } else if( "sphere" == geometry_type) {
                auto center{ parse_to<point_3d>(geometry_json.second.get_child("center"))};
                auto radius = geometry_json.second.get_child("radius").get_value<double>();
                scene.add_intersectable(sphere{center, radius});
            }
        }
        return scene;
    }
}

#endif