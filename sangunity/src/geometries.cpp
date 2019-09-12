#include "geometries.hpp"
#include <optional>

#include <iostream>
#include <cmath>

std::optional<sangunity::hit> sangunity::intersect(plane p, ray r) {
    if(are_orthogonal(p.normal, r.direction)) return std::nullopt;
    double t = dot(p.anchor - r.origin, p.normal) / dot(r.direction, p.normal);
    if( t > 0.0) return hit{t, p.normal};
    else return std::nullopt;
}

std::optional<sangunity::hit> sangunity::intersect(sphere s, ray r) {
    auto a = dot(r.direction, r.direction);
    auto b = dot(r.direction, 2.0 * (r.origin - s.center));
    auto c = dot(r.origin - s.center, r.origin - s.center) - pow(s.radius, 2.0);

    auto d = pow(b, 2.0) - 4 * a * c;
    if(d<0.0) return std::nullopt;

    auto t1 = (-b + sqrt(d)) / (2*a);
    auto t2 = (-b - sqrt(d)) / (2*a);

    if( t2 > 0.0 ) return hit{t2, normalized( point_on_ray(r, t2) - s.center) };
    else if( t1 > 0.0) return hit{t1, normalized( point_on_ray(r, t1) - s.center) };
    return std::nullopt;
}