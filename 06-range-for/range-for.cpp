#include "range-for.hpp"

area_iterator area_2d::begin() {
    return area_iterator(*this, point_2d{0, 0});
}

area_iterator area_2d::end() {
    return area_iterator(*this, point_2d{0, height});
}

area_iterator::area_iterator(const area_2d& area, point_2d start) : area{area}, current_point{start} {

}

area_iterator& area_iterator::operator++()
{
    if(this->current_point.x == this->area.width-1) { 
        this->current_point.x = 0;
        if( this->current_point.y < this->area.height) {
            this->current_point.y += 1;
        }
    } else {
        this->current_point.x += 1;
    }
    return *this;
}

area_iterator area_iterator::operator++(int)
{
    area_iterator tmp(*this); 
    this->operator++(); 
    return tmp;
}

point_2d area_iterator::operator*() const {
    return this->current_point;
}
