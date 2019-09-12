#include "range-for.hpp"
#include <iostream>

int main() {
    area_2d area{10, 30};
    for(auto point : area) {
        std::cout << "point[x=" << point.x << " ,y=" << point.y << "]" << std::endl;
    }
    return EXIT_SUCCESS;
}