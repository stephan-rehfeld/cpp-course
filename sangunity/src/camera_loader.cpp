#include "camera_loader.hpp"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include "loader_helper.hpp"

sangunity::camera sangunity::load_camera(const std::string filename) {
    boost::property_tree::ptree camera_json;
    boost::property_tree::read_json(filename, camera_json);
    auto position{ parse_to<point_3d>(camera_json.get_child("position"))};
    auto direction{ parse_to<direction_3d>(camera_json.get_child("direction"))};
    auto up_vector{ parse_to<direction_3d>(camera_json.get_child("up_vector"))};
    auto field_of_view_degree = units::degree<double>(camera_json.get<double>("field_of_view"));
    auto field_of_view = units::angle_cast<units::radians>(field_of_view_degree);
    return camera{ position, direction, up_vector, field_of_view};
    
}