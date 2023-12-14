#include<iostream>
using namespace std;
//Topics covered: Arrays, and printing array address

int main(){
    //Array declaration: datatype ArrayName = values;
    //M1
    int arr1[5] = {10, 20, 30, 40, 50};
    //M2
    int arr2[5] = {}; arr2[0] = 1; arr2[1] = 2; arr2[2] = 3; arr2[3] = 4; arr2[4] = 5; 
    //M3
    int arr3[5];
    for(int i = 0; i < 5; i++){
        arr3[i] = i * 5;
    }

    int size;
    cout << "enter the size of the array:";
    cin >> size;
    int numbers[size];
    for(int i = 0; i < size; i++){
        cout << "Enter value in array at index " << i << ": ";
        cin >> numbers[i];
    }

    cout << "Array Address is: " << arr1 << endl; //Notice that this doesn't output the elements of the array as happened in python, instead by this we get the array address, where the array is stored in memory.

    for(int i = 0; i < size; i++){
        cout << "Element: " << numbers[i] << " at index " << i << " with address " << (numbers+i) << endl;
        /*Notice the address of the elements in the array
        The first element is the base address of the array, and then each successive element is at an increment of 4 (4 bytes) as an int was of 4 bytes.
        */
    }

    system("pause");
}  