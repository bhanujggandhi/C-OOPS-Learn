#include <bits/stdc++.h>

using namespace std;

/*
Explanation: The reason for compiler error is simple, the name of printf() is changed by the C++ compiler and it doesn’t find the definition of the function with a new name.

Solution: Extern “C” in C++

When some code is put in the extern “C” block, the C++ compiler ensures that the function names are un-mangled – that the compiler emits a binary file with their names unchanged, as a C compiler would do.
If we change the above program to the following, the program works fine and prints “GeeksforGeeks” on the console(as shown below).
*/

// extern "C" {
// int printf(const char* format, ...);
// }

// int main() {

//     printf("hello");
//     return 0;
// }

int printf(char *format, ...);

int main() {
    printf("Hello, world!");
    return 0;
}