#include <iostream>

// The header limits provides several functions to analze the range limit of fundamental
// types. We use is here to determine lowest, minimum, and maximum values.
#include <limits>

// A function template that prints the type name of T, the size of T in byte, and the
// lowest, minimum, and maximum value. Note that unlike in Java, the types are not erased,
// but the template is instantiated for every passed type. Hence, print_type_information<bool>()
// and print_type_information<char>() are two disting functions.
template<typename T>
void print_type_information() {
    std::cout << typeid(T).name() << "\t| "
              << sizeof(T) << "\t| "
              << std::numeric_limits<T>::min() << "\t| "
              << std::numeric_limits<T>::max() << "\t| "
              << std::numeric_limits<T>::lowest() << std::endl;
}

int main() {
    std::cout << "Name" << "\t| "
              << "Size" << "\t| "
              << "Min" << "\t| "
              << "Max" << "\t| "
              << "Lowest" << std::endl;
    
    print_type_information<bool>();
    print_type_information<char>();
    print_type_information<char16_t>();
    print_type_information<char32_t>();
    print_type_information<wchar_t>();
    print_type_information<signed char>();
    print_type_information<short int>();
    print_type_information<int>();
    print_type_information<long int>();
    print_type_information<long long int>();
    print_type_information<unsigned char>();
    print_type_information<unsigned short int>();
    print_type_information<unsigned int>();
    print_type_information<unsigned long int>();
    print_type_information<unsigned long long int>();
    print_type_information<float>();
    print_type_information<double>();
    print_type_information<long double>();
}
