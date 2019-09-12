#include "units.hpp"

std::string const sangunity::units::radians_unit::symbol {"rad"};

std::string const sangunity::units::degree_unit::symbol {"°"};

template<>
sangunity::units::degree<double> sangunity::units::angle_cast(sangunity::units::radians<double> r) { 
    return degree<double>{r.v * 180.0 /3.1415};
}

template<>
sangunity::units::radians<double> sangunity::units::angle_cast(sangunity::units::degree<double> d) {
    return radians<double>{d.v * 3.1415 / 180.0};
}