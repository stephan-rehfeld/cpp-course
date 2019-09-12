#include "geometries.hpp"
#include "scene_loader.hpp"
#include "camera_loader.hpp"
#include "cg_math.hpp"
#include "render_job.hpp"

#include <iostream>
#include <boost/gil.hpp>
#include <boost/gil/extension/io/jpeg.hpp>

namespace {
    void print_usage() {
        std::cout << "Usage: render --scene <scene.json>" << std::endl;
        std::cout << "              --camera <camera.json>" << std::endl;
        std::cout << "              --size <width,height.json>" << std::endl;
        std::cout << "              --out <image.jpg>" << std::endl;
    }
}

int main (int argc, char *argv[]) {
    if(auto render_job = sangunity::parse_render_job(argc, argv); render_job.has_value()) {
        auto scene = sangunity::load_scene<sangunity::plane, sangunity::sphere>(render_job->scene_filename);
        auto camera = sangunity::load_camera(render_job->camera_filename);
    
        std::cout << "Start rendering..." << std::endl;
        int hits = 0;

        boost::gil::gray8_image_t image{ render_job->image_size.width, render_job->image_size.height };
        auto view{boost::gil::view(image)};
        auto rotated_view = boost::gil::rotated180_view(view);
        for( auto pixel : render_job->image_size) {
        
            auto ray = sangunity::ray_for(camera, render_job->image_size, pixel);
            auto hit = scene.intersect(ray);
        
            if(hit.has_value()) {
                ++hits;
                auto brightness{ std::min(std::abs(sangunity::dot(ray.direction, hit->normal)), 1.0)};
                auto brightness_uint8_t = (u_int8_t)(brightness * 255.0);
                rotated_view(pixel.x, pixel.y) = brightness_uint8_t;
            }
        }

        std::cout << "FINISHED rendering. " << hits << std::endl;

        boost::gil::write_view( "out.jpg", view, boost::gil::image_write_info< boost::gil::jpeg_tag >( 95 ));
    } else {
        ::print_usage();
    }
} 

