#ifndef _SANGUNITY_UNITS_HPP
#define _SANGUNITY_UNITS_HPP

#include <string>
#include <ratio>
#include "cg_math.hpp"

namespace sangunity::units {

    enum class unit_type {
        angle
    };

    struct radians_unit {
        static const std::string symbol;
        static constexpr unit_type type {unit_type::angle};
    };

    struct degree_unit {
        static const std::string symbol;
        static constexpr unit_type type {unit_type::angle};
    };

    template<typename T>
    concept Ratio = requires {
        {T::num} -> intmax_t;
        {T::den} -> intmax_t
    };

    template<typename T>
    concept Unit = requires {
        {T::symbol} -> std::string;
        {T::type} -> unit_type;
    };

    template<typename T, Ratio R, Unit U>
    class prefixed_typed_value {
    protected:
        prefixed_typed_value(T value) : v{value} {

        }

    protected:
        T v;
    };

    template<typename T>
    struct radians : public prefixed_typed_value<T, std::ratio<1, 1>, radians_unit> {
    public:
        explicit radians(T value) : prefixed_typed_value<T, std::ratio<1, 1>, radians_unit>{value} {

        }

        explicit operator T() const { 
            return this->v;
        }

        template<template<typename> typename O, typename X> requires std::is_same<T, X>::value
        friend O<X> angle_cast(radians<X> r);
    };

    template<typename T>
    struct degree : public prefixed_typed_value<T, std::ratio<1, 1>, degree_unit> {
    public:
        explicit degree(T value) : prefixed_typed_value<T, std::ratio<1, 1>, degree_unit>{value} {

        }

        explicit operator T() const { 
            return this->v;
        }

        template<template<typename> typename O, typename X> requires std::is_same<T, X>::value
        friend O<X> angle_cast(degree<X> d);
    };

    template<template<typename> typename O, typename X>
    O<X> angle_cast(radians<X> r);

    template<template<typename> typename O, typename X>
    O<X> angle_cast(degree<X> d);
}

#endif