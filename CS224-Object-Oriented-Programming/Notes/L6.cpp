#include<iostream>
#include<cstring>
using namespace std;

int length(char n[]){ //A simple alg that returns the lenght of a character array. The '\0' denotes the end of the character array
    int i = 0; 
    while(n[i] != '\0') i++;
    return i;
}

void mystrcpy(char dest[], char source[]){ //function to make a copy of char array
    int i = 0;
    while(source[i] != '\0') i++;

    for(int x = 0; x < i; x++){
        dest[x] = source[x];
    }
    dest[i] = '\0';
}

int main(){
    cout << "===================================Char Arrays=====================================" << endl;
    //char arrays
    // char fname[100] = {'A', 'L', 'I', '\0'};
    // char lname[100];
    // cin >> fname >> lname;

    // char feedback[100];
    // cin.get(feedback, 10, '@'); //newline is the default seperator here for chars
    // // cin.ignore();
    // cin.getline(feedback, 20, '%'); //newline is the default seperator here chars
    // // cin.ignore(); //the cin.ignore() is used to discard any remaining newline characters or other unwanted characters in the input
    // //when cin.get or cin.getline is used, it leaves the newline characters in the input buffer, hence cin.ignore()
    // //feedback is the array, the numbers represent number of characters that will be read, the delimeter is optional and is a stopping sign. the delimeter is not needed and cin.get(array, number) and cin.getline(array, number) still works
    // //cin.get and cin.getline are input functions used to read character sequences and store them in character arrrays
    // //cin.get: - reads a single character from the input stream, including whitespace characters (spaces, tabs, etc.), and stores it in a character variable or an array element
    // //cin.getline: - reads a line of text from the input until a newline character ('\n') is encountered or until the specified number of characters are read, and stores it in a character array
    // //     - It discards the newline character from the input stream and replaces it with the null character ('\0') to terminate the string
    // cout << "Your feedback: " << feedback << endl;
    // for(int i = 0; i < 5; i++){
    //     cout << feedback[i] << endl;
    // }
    // // cout << fname << lname;

    char fname[100], lname[100];
    int age; float height;
    cout << "Enter first name: "; cin.get(fname, 100); cin.ignore(); //reads input till 99 charcters are read or newline encountered
    cout << "Enter last name: "; cin.get(lname, 100); cin.ignore();
    
    cout << fname << " " << "length of fname: " << strlen(fname) << endl;
    cout << lname << " " << "lenght of lname: " << length(lname) << endl;

    mystrcpy(lname, fname); //copies fname into lname
    cout << fname << " " << "length of fname: " << strlen(fname) << endl;
    cout << lname << " " << "lenght of lname: " << length(lname) << endl;

    system("pause");
}
