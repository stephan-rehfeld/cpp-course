// Header files usually contain an include guard, so that declarations are not
// repeated, event when header file is included several times.
#ifndef _FOO_H
#define _FOO_H

// Function foo is declared here with its signature. It only declared that this
// function exists, but it does not define the function. This is done in the cpp
// file.
void foo();

// End of include guard.
#endif
