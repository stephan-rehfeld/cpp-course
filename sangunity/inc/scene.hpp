#ifndef _SANGUNITY_SCENE_HPP
#define _SANGUNITY_SCENE_HPP

#include "cg_concepts.hpp"
#include "hit.hpp"
#include <vector>
#include <tuple>
#include <type_traits>
#include <utility>
#include <optional>

namespace sangunity {

    template<std::size_t C, Intersectable I>
    constexpr std::size_t _index_of_type() {
        return -1;
    }

    template<std::size_t C, Intersectable I, Intersectable T, Intersectable... Ts>
    constexpr std::size_t _index_of_type() {
        if( std::is_same<typename std::remove_reference<I>::type, T>::value) {
            return C;
        }
        return _index_of_type<C+1, I, Ts...>();
    }

    template<Intersectable I, Intersectable... T>
    constexpr std::size_t index_of_type() {
        return _index_of_type<0, I, T...>();
    }

    template<Intersectable... T>
    class scene final {
    private:
        std::tuple<std::vector<T>...> intersectables;

        template<std::size_t C>
        void intersect(ray r, std::optional<hit>& hit_result ) {
            for( const auto& intersectable : std::get<C>(this->intersectables)) {
                std::optional<hit> new_hit {sangunity::intersect(intersectable, r)};
                if(new_hit.has_value() && (!hit_result.has_value() || new_hit->t < hit_result->t))
                    hit_result = new_hit;
            }
            if constexpr ( C+1 < std::tuple_size<typename std::tuple<std::vector<T>...>>::value)
                intersect<C+1>(r, hit_result);
        }

    public:
        template<Intersectable I>
        void add_intersectable(I&& i)
        {
            static_assert((std::is_same<T, typename std::remove_reference<I>::type>::value || ...), "Passed type I was not in list T of this scene.");
            
            constexpr std::size_t index = index_of_type<I, T...>();
            std::get<index>(this->intersectables).push_back(std::forward<I>(i));
        }

        std::optional<hit> intersect(ray r) {
            std::optional<hit> hit_result{std::nullopt};
            this->intersect<0>(r, hit_result);
            return hit_result;
        }
    };
}

#endif