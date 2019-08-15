#include <iostream>

constexpr int foo();

int x; // x is zero initalized
static const int c {foo()}; // c is const initalized (depending on C++ version if happens before or instead static)
int a[10]; // Elements of array in non-local scope is zero initalized.

int main() {
    std::cout << "Value of x is " << x << std::endl;

    // y is NOT initalized, value is indeterminate!
    // Play around with optimatzation parameter (e.g. -O3) to may see differences.
    int y; 

    // It initalized by value 23.
    int z {23};

    std::cout << "Value of y is " << y << std::endl;
    std::cout << "Value of z is " << z << std::endl;

    for(size_t i = 0; i < 10; ++i ) {
        std::cout << "a[" << i << "] = " << a[i] << std::endl;
    }

    // Array is initialized, but elements are not.
    // Array contains indeterminate values.
    int b[10];
    for(size_t i = 0; i < 10; ++i ) {
        std::cout << "b[" << i << "] = " << b[i] << std::endl;
    }

    // Values initalized, all elements are initialzed to zero.
    int c[10] {};
    for(size_t i = 0; i < 10; ++i ) {
        std::cout << "c[" << i << "] = " << c[i] << std::endl;
    }

    return EXIT_SUCCESS;
}

constexpr int foo() {
    return 42;
}
