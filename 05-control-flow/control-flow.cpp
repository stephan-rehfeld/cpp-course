#include <iostream>
#include <vector>
#include <string>

int constexpr foo() {
    return 5;
}

void if_examples() {
    if( auto i = foo(); i < 5) {
        std::cout << "i was smaller than 5" << std::endl;
    }
}

void switch_examples() {
    switch( auto i = foo(); i) {
        case 1: 
            std::cout << "i was 1" << std::endl;
            break;

        case 2: 
            std::cout << "i was 2" << std::endl;
            break; 

        default:
            std::cout << "i neither 1 nor 2" << std::endl;
            break; 

    }
}

void for_examples() {
    int a[] {4, 8, 15, 16, 23, 42};
    for( size_t i = 0; i < sizeof(a) / sizeof(int); ++i ) { // Use this sizeof(a) / sizeof(int) with care
        std::cout << "a[" << i << "] = " << a[i] << std::endl;
    }

    std::vector<int> b {4, 8, 15, 16, 23, 42};
    for( std::vector<int>::size_type i = 0; i < b.size(); ++i ) {
        std::cout << "b[" << i << "] = " << b[i] << std::endl;
    }
}

void range_for_examples() {
    std::vector<std::string> sentence{ "The", "cake", "is", "a", "lie"};
    
    for( auto s : sentence ) {
        std::cout << s << std::endl;
    }

    // Values are copied, hence modification has not effect.
    for( auto s : sentence ) {
        s += "!"; // Has no effect on the values in sentence.
    }

    // As you see, no changes
    for( auto s : sentence ) {
        std::cout << s << std::endl;
    }

    // Using references
    for( auto&& s : sentence ) {
        s += "!"; // Now we work on references, and values in sentence are changed
    }

    // Values are changed
    for( auto s : sentence ) {
        std::cout << s << std::endl;
    }

    // Use const reference in case you don't want to copy and want to prevent modification
    for( const auto& s : sentence ) {
        //s += "!"; // Line does not compile, because we have a const reference
        std::cout << s << std::endl;
    }

    // or

    // We now have a const reference to sentence;
    const auto& const_sentence = sentence;

    for( auto&& s : const_sentence ) {
        //s += "!"; // Now auto&& is deduced to const std::string& !
        std::cout << s << std::endl;
    }
}

int main() {
    if_examples();
    switch_examples();
    for_examples();
    range_for_examples();
}