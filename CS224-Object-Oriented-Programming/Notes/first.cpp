#include<iostream>      // The #include<> is used to include header files which provide additional functionality to the code. In this case, the "iostream" header file contains necessary input/output operations for the C++ allowing us to take inputs - cin -  and outputs - cout -. [iostream - input output stream]
using namespace std;    // this line tells the compiler to use the 'std' namespace. 'std' contains many standard c++ functions, classes and objects. By using this line, we can avoid the usage of "std::" everytime we use those, making the code more precise  

int main(){ // This line declares the "int main(){}" function. the 'main' function is the entry point of the program, starting the execution of the program. In C++, we also have to declare the type of each function, method, variable etc, hence the 'int' before main declares it as a function that returns an 'int' value. A function declared with 'void' wouldn't return anything, a function of type 'bool' would return a bool - truth/false - value.

    cout << "Hello world"; // cout is the standard output stream -> c output, and it is used for displaying output to the console. Here, we are using cout to print the string "Hello world" to the console. The << operator is used for insertion, and it inserts the string into the cout stream.

    // Without the use of namespace std, the cout would look like: std::cout << "Hello World";

    return 0; // Used to exit the function much as in python, the return type should match the function type. In case of a void function, we don't return anything.
}

/*
Since C++ is a compiled language, we must fisrt compile it. 
To compile, open the terminal and type: "g++ filename.cpp". For eg, for this file, "g++ first.cpp"
This compiles the program, and in case of a successful compilation, an "a.exe" file will be generated that can be executed.
To run the exe file, type in the terminal: "a.exe". If this doesn't work, ".\a.exe" should compile
Whenever changes are made to the code, the code will have to be saved and recompiled and then executed for the changes to take effect
*/

