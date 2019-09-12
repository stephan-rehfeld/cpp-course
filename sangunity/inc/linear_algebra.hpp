#ifndef _SANGUNITY_LINEAR_ALGEBRA_HPP
#define _SANGUNITY_LINEAR_ALGEBRA_HPP

#include <array>

namespace sangunity::linear_algebra {

    template<std::size_t ROWS, std::size_t COLUMNS, typename T>
    class mat {
    public:
        template<typename ... ARGS>
        mat( ARGS&& ... element ) : elements{element...} {
            static_assert(sizeof...(ARGS) == ROWS*COLUMNS, "Invalid number of constructor arguments.");
        }

/*
        std::span<T, COLUMNS>&  operator[](std::size_t row) {

        }

        const std::spand<T, COLUMNS>& operator[](std::size_t row) const {

        }
*/
        T& operator()(std::size_t row, std::size_t column) {
            return this->elements[row*COLUMNS + column];
        }

        const T& operator()(std::size_t row, std::size_t column) const {
            return this->elements[row*COLUMNS + column];
        }
    private:
        std::array<T, ROWS*COLUMNS> elements;
    };


    template<unsigned int ROWS, typename T> 
    class vec: private mat<ROWS, 1, T> {
    public:
        template<typename ... ARGS>
        vec( ARGS&& ... element ) : mat<ROWS, 1, T>{element...} {
        }

        T& operator()(std::size_t column) {
            return mat<ROWS, 1, T>::operator()(0, column);
        }

        const T& operator()(std::size_t column) const {
            return mat<ROWS, 1, T>::operator()(0, column);
        }
    };

}

#endif
