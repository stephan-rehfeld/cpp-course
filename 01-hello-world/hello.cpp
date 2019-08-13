// This is a C++ source file. The source files typically contain the definitions
// of functions, members functions, and more executable code.

// Header files contain declarations of other compilation units or libraries.
// They are required to use these functions in this source code.
#include <iostream> // Declares functions for input and output.

// Main function is called when executable is started.
int main()
{
    // std::cout is an ostream (outputstream) that is used to write to standard out.
    // Is has an overloaded operator << that means to put the string into the
    // output stream.
    // std::endl means new line and flushes the stream to the output.
    std::cout << "Hello World" << std::endl;

    // This means that the application returns without errors. Can be evalulated
    // i. e. by calling scripts/batch files.
    return EXIT_SUCCESS;
}
