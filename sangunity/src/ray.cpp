#include "ray.hpp"

sangunity::point_3d sangunity::point_on_ray(ray r, double t ) {
    return r.origin + t * r.direction;
}

std::ostream & sangunity::operator<< (std::ostream &out, const sangunity::ray& r)
{
    out << "ray[origin=" << r.origin << ", direction=" << r.direction << "]";
    return out;
}       
