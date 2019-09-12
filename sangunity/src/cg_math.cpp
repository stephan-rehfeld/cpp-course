#include "cg_math.hpp"

sangunity::point_3d::point_3d(double x, double y, double z) :
    sangunity::linear_algebra::vec<3, double>{ x, y, z} {
}

sangunity::direction_3d::direction_3d(double x, double y, double z) :
    sangunity::linear_algebra::vec<3, double>{ x, y, z} {   
}

std::ostream & sangunity::operator<< (std::ostream &out, const sangunity::direction_3d& d)
{
    out << "direction_3d[x=" << d.x() << ", y=" << d.y() << ", z=" << d.z() << "]";
    return out;
}

std::ostream & sangunity::operator<< (std::ostream &out, const sangunity::point_3d& p)
{
    out << "point_3d[x=" << p.x() << ", y=" << p.y() << ", z=" << p.z() << "]";
    return out;
}
