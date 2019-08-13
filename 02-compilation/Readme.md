# Compilation example

This small example shows the  difference between C++ and Java in compilation
of projects with multiple files. Both projects have two files, one that contains
the main function/method and the other one contains a function called foo() which
simply prints a the string "Hello World from foo()" to the console.

## Java

To compile the java example, it is enough to pass Main.java to the compiler. The
compiler resolves the dependencies and compile the file Foo.java automatically.
As byte code is not executable directly, the java application is required to start
the JVM.

    javac Main.java
    java Main

## C++

### gcc

To make the process of compilation and linking more clear, here are the commands
seperatley.

    g++ -c foo.cpp
    g++ -c main.cpp
    g++ main.o foo.o -o main
    ./main

Note that the first two commands compile the files foo.cpp and main.cpp but not link
the binaries. As result, the files foo.o and main.o are generated, which contain the
object code. The last command links object files and generated the executable.

Shorthand is

    g++ main.cpp foo.cpp -o main
    ,/main

### clang

To make the process of compilation and linking more clear, here are the commands
seperatley.

    clang++ -c foo.cpp
    clang++ -c main.cpp
    clang++ main.o foo.o -o main
    ./main

Note that the first two commands compile the files foo.cpp and main.cpp but not link
the binaries. As result, the files foo.o and main.o are generated, which contain the
object code. The last command links object files and generated the executable.

Shorthand is

    clang++ main.cpp foo.cpp -o main
    ./main
