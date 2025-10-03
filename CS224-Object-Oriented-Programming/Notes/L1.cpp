#include<iostream>
#include<string> //includes string 
using namespace std;

int main(){
    //Variables and Data types - have to declare the data type for each variable before
    //data type : int , float , double , char , void ,bool,string
    //operators are much same as in python, +, -, *, /, ++, --, ==, %, <, <=, >, >=, !=, &&, ||. Hence not diving into these seperately
    int a = 5; int b = 2; 
    float f = 3.2; double d = 100000; 
    char c = 'a';
    string s = "Bleh bleh bleh";
    bool boo = true;
    bool boo1; boo1 = false;

    cout << a << "\n"<< b << "\n" << f << "\n" << d << "\n" << c << "\n" << s << "\n" << boo << "\n" << boo1 << endl; // I've used << to seperate the variables etc. The 'endl' automatically enters a new line once the cout statement ends.

    /* Size of data types:
    bool: Typically 1 byte.
    char: Typically 1 byte.
    short: Typically 2 bytes.
    int: Typically 4 bytes.
    long: Typically 4 bytes (although it can be larger, such as 8 bytes on some platforms).
    float: Typically 4 bytes.
    double: Typically 8 bytes.
    The size of each type can be found by using the "sizeof" operator. For eg, "sizeof(int)"
    */
    //Also a lab question
    cout << "The size of char is: " << sizeof(char) << " bytes" << endl;
    cout << "The size of bool is: " << sizeof(bool) << " bytes" << endl;
    cout << "The size of int is: " << sizeof(int) << " bytes" << endl;
    cout << "The size of float is: " << sizeof(float) << " bytes" << endl;
    cout << "The size of double is: " << sizeof(double) << " bytes" << endl;
    cout << "The size of long is: " << sizeof(long) << " bytes" << endl;
    cout << "The size of short is: " << sizeof(short) << " bytes" << endl;


    // Taking inputs from the user
    /* For outputs, we used "cout << ;". For inputs, we use "cin >> ;". [c input]. Notice the difference in the >> operator which inserts the input from the user into the input stream. */
    int num;
    cout << "Please enter a number, (should be a number or else): "; //notice i didn't use 'endl' here so that input is taken in the same line in the terminal
    cin >> num;
    cout << "Your number is " << num << endl; 

    system("pause"); // The system pause pauses the system until a key is pressed and then exits the program.
}