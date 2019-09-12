#ifndef _SANGUNITY_LOADER_HELPER_HPP
#define _SANGUNITY_LOADER_HELPER_HPP

#include <boost/property_tree/ptree.hpp>

namespace sangunity {
    template<typename T>
    T parse_to(const boost::property_tree::ptree& element) {
        auto it = element.begin();
        auto x = it->second.get_value<double>();
        ++it;
        auto y = it->second.get_value<double>();
        ++it;
        auto z = it->second.get_value<double>();
        return T{x, y, z};
    }
}

#endif