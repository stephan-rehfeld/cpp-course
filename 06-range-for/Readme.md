# Range for example

This example shows a small implementation of a struct that is usable in a range-for loop. The struct
area_2d represents a discrete are with width and height. Used in a range-for loop, every point is provided
through a point_2d.

## Compile and run

### gcc

    g++ main.cpp range-for.cpp -o range-for
    ./range-for

### clang

    clang++ main.cpp range-for.cpp -o range-for
    ./range-for
