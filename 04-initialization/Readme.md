# Initalization example

This example demonstrates the differences in intalization of local and global variables. Not all possible
type of initializations and not all possible orders are illustrated.

## Compile and run

### gcc

At first compiliation, just use the default optimization level. Observe the values of not initialized variables, such as y and b.

    g++ initalization.cpp -o typinitalizationes
    ./initalization

Now compile the example again, this time highest optimization turned on. Compare the results with compilation
with default optimization and results of other compilers and on other platforms.

    g++ -O3 initalization.cpp -o typinitalizationes
    ./initalization

### clang


At first compiliation, just use the default optimization level. Observe the values of not initialized variables, such as y and b.

    clang++ initalization.cpp -o initalization
    ./initalization

Now compile the example again, this time highest optimization turned on. Compare the results with compilation
with default optimization and results of other compilers and on other platforms.

    clang++ -O3 initalization.cpp -o initalization
    ./initalization
