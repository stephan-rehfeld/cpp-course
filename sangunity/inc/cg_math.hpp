#ifndef _SANGUNITY_CG_MATH_HPP
#define _SANGUNITY_CG_MATH_HPP

#include "linear_algebra.hpp"
#include <cmath>
#include <iostream>

namespace sangunity {

    class direction_3d : private sangunity::linear_algebra::vec<3, double> {
    public:
        inline double& x() {
            return sangunity::linear_algebra::vec<3, double>::operator()(0);
        };
        const double& x() const {
            return sangunity::linear_algebra::vec<3, double>::operator()(0);
        };
        double& y() {
            return sangunity::linear_algebra::vec<3, double>::operator()(1);
        };
        const double& y() const {
            return sangunity::linear_algebra::vec<3, double>::operator()(1);
        };
        double& z() {
            return sangunity::linear_algebra::vec<3, double>::operator()(2);
        };
        const double& z() const {
            return sangunity::linear_algebra::vec<3, double>::operator()(2);
        };

        direction_3d& operator+=(direction_3d v) {
            this->x() += v.x();
            this->y() += v.y();
            this->z() += v.y();
            return *this;
        }

        direction_3d& operator/=(double v) {
            this->x() /= v;
            this->y() /= v;
            this->z() /= v;
            return *this;
        }

        direction_3d& operator*=(double v) {
            this->x() *= v;
            this->y() *= v;
            this->z() *= v;
            return *this;
        }

        direction_3d(double x, double y, double z);

        inline direction_3d operator-() const {
            return direction_3d{-x(), -y(), -z()};
        }
    };

    class point_3d : private sangunity::linear_algebra::vec<3, double> {
    public:
        inline double& x() {
            return sangunity::linear_algebra::vec<3, double>::operator()(0);
        };
        const double& x() const {
            return sangunity::linear_algebra::vec<3, double>::operator()(0);
        };
        double& y() {
            return sangunity::linear_algebra::vec<3, double>::operator()(1);
        };
        const double& y() const {
            return sangunity::linear_algebra::vec<3, double>::operator()(1);
        };
        double& z() {
            return sangunity::linear_algebra::vec<3, double>::operator()(2);
        };
        const double& z() const {
            return sangunity::linear_algebra::vec<3, double>::operator()(2);
        };

        point_3d(double x, double y, double z);

        point_3d& operator+=(const direction_3d& v) {
            this->x() += v.x();
            this->y() += v.y();
            this->z() += v.z();
            return *this;
        }
    };

    std::ostream & operator << (std::ostream &out, const direction_3d& d);

    std::ostream & operator << (std::ostream &out, const point_3d& p);

    inline point_3d operator+(point_3d lhs, const direction_3d& rhs)
    {
        lhs += rhs;
        return lhs;
    }

    inline direction_3d operator+(direction_3d lhs, const direction_3d& rhs)
    {
        lhs += rhs;
        return lhs;
    }

    inline direction_3d operator-(point_3d lhs, const point_3d& rhs)
    {
        direction_3d result{lhs.x() - rhs.x(), lhs.y() - rhs.y(), lhs.z() - rhs.z()};
        return result;
    }

    inline direction_3d operator*(double lhs, direction_3d rhs)
    {
        rhs *= lhs;
        return rhs;
    }

    inline direction_3d operator*(direction_3d lhs, double rhs)
    {
        lhs *= rhs;
        return lhs;
    }

    inline double dot(direction_3d a, direction_3d b) {
        return a.x() * b.x() + a.y() * b.y() + a.z() * b.z();
    }

    inline bool are_orthogonal(direction_3d a, direction_3d b) {
        return dot(a, b) == 0.0;
    }

    inline double magnitude(direction_3d v) {
        return sqrt( pow(v.x(), 2.0) + pow(v.y(), 2.0) + pow(v.z(), 2.0));
    }

    inline direction_3d normalized(direction_3d v) {
        return v /= magnitude(v);
    }

    inline direction_3d cross(direction_3d a, direction_3d b) {
        return direction_3d{a.y() * b.z() - a.z() * b.y(),
                            a.z() * b.x() - a.x() * b.z(),
                            a.x() * b.y() - a.y() - b.x()};
    }

    template<typename T>
    struct point_2d final {
        T x;
        T y;

        inline bool operator==(point_2d rhs) const {
            return this->x == rhs.x && this->y == rhs.y;
        }
    };

    template<typename T>
    struct area_2d final {
        T width;
        T height;

        class area_iterator final {
        private:
            const area_2d& area;
            point_2d<T> current_point;

        public:
            area_iterator(const area_2d& area, point_2d<T> start) : area{area}, current_point{start} {

            }

            inline bool operator==(const area_iterator& rhs) const {
                return this->current_point == rhs.current_point;
            }

            inline bool operator!=(const area_iterator& rhs) const {
                return !(*this == rhs);
            }

            area_iterator& operator++()
            {
                if(this->current_point.x == this->area.width-1) {
                    this->current_point.x = 0;
                    if( this->current_point.y < this->area.height) {
                        this->current_point.y += 1;
                    }
                }
                else {
                    this->current_point.x += 1;
                }
                return *this;
            }

            area_iterator operator++(int)
            {
                area_iterator tmp(*this); 
                this->operator++(); 
                return tmp;
            }

            point_2d<T> operator*() const {
                return this->current_point;
            }
        };

        area_iterator begin() {
            return area_iterator(*this, point_2d<T>{0, 0});
        }

        area_iterator end() {
            return area_iterator(*this, point_2d<T>{0, height});
        }
    };
}

#endif
