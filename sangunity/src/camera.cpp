#include "camera.hpp"

sangunity::ray sangunity::ray_for(camera camera, area_2d<int> image_size, point_2d<int> pixel) {
    auto w = -sangunity::normalized(camera.gaze_direction);
    auto u = sangunity::cross(camera.up_vector, w);
    auto v = sangunity::cross(w, u);

    auto width = (double)image_size.width;
    auto height = (double)image_size.height;
    auto x = (double)pixel.x;
    auto y = (double)pixel.y;

    auto a = -w *  ((image_size.height / 2.0) / tan(static_cast<double>(camera.field_of_view)));
    auto b = (x - (width-1.0)/2.0 ) * u;
    auto c = (y - (height-1.0)/2.0) * v;
    auto direction =  sangunity::normalized(a + b + c);

    return ray{camera.position, direction};
}