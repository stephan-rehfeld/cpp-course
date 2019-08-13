// Including the foo.h header, so that declarations are already known here.
#include "foo.h"

// Including iostream, because we want to use std::cout here.
#include <iostream>

// Definition of void foo().
void foo() 
{
    std::cout << "Hello World from foo()" << std::endl;
}
