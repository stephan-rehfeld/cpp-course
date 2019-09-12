#ifndef _SANGUNITY_CG_CONCEPTS_HPP
#define _SANGUNITY_CG_CONCEPTS_HPP

#include <optional>
#include "ray.hpp"
#include "hit.hpp"

namespace sangunity {

    template<typename T>
    concept Intersectable = requires( T a, sangunity::ray ray ) {
            { intersect(a, ray) } -> std::optional<hit>;
    };

}

#endif