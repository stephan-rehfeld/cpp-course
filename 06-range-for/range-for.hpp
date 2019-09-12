#ifndef _RANGE_FOR_HPP
#define _RANGE_FOR_HPP

struct point_2d final {
    int x;
    int y;

    inline bool operator==(point_2d rhs) const {
        return this->x == rhs.x && this->y == rhs.y;
    }
};

class area_iterator;

struct area_2d final {
    int width;
    int height;

    area_iterator begin();

    area_iterator end();
};

class area_iterator final {
    private:
    const area_2d& area;
    point_2d current_point;

    public:
    area_iterator(const area_2d& area, point_2d start);

    inline bool operator==(const area_iterator& rhs) const {
        return this->current_point == rhs.current_point;   
    }

    inline bool operator!=(const area_iterator& rhs) const {
        return !(*this == rhs);
    }

    area_iterator& operator++();

    area_iterator operator++(int);

    point_2d operator*() const;
};

#endif
