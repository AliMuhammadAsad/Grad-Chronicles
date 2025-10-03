#include<iostream>
using namespace std;
//Topics: - passing name of array means passing address of an array
// - pointers (our all time favorite xD)
// - dynamic memory allocation

void increase_marks(int arr[], int len){
    for(int i = 0; i < len; i++){
        arr[i] += arr[i] * 0.1; //suppose we have an array which has some marks, thus increasing each mark by 10%
    }
    // len += 4;
    cout << "len = " << len << endl;
}

int main(){
    //Arrays:
    // =============================================
    // pass by address and pass by value

    // cout << "====================================ARRAYS====================================" << endl;
    // int size; cout << "Enter size of array: "; cin >> size;
    // int numbers[size];
    // for(int i = 0; i < size; i++){
    //     cout << "Enter marks: "; cin >> numbers[i];
    // }

    // increase_marks(numbers, size); //calling function
    
    // for(int i = 0; i < size; i++){
    //     cout << "Updated Marks: " << numbers[i] << " at array index " << i << " at memory address " << &numbers[i] << endl; 
    //     //(numbers+i) == &numbers[i] (both can be used to access address)
    // }
    // cout << "Size = " << size << endl;
    
    //Pointers
    // a pointer is a variable that stores address of a memory location.
    //declaration: datatype* name = address of variable.
    cout << "====================================POINTERS====================================" << endl;
    int token; cout << "Enter token number: "; cin >> token;
    int* p  = &token; //since token was an int, the pointer is of int type 
    cout << "Token: " << token << " also token " << *p << endl;
    cout <<  "Token address: " << p << " also address " << &token << endl;
    cout << "(notice how they the same)" << endl;

    //Dynamic Memory allocation
    double* dp = new double; //uses the new operator to dynamically allocate a double. Finds a memory location to store one value of type double.
    int *ip = new int; //find a memory location to store one int value.

    if(dp == NULL || ip == NULL) cout << "Out of space\n";
    else{
        cout << "Enter value for double: "; cin >> *dp;
        cout << "Enter value for integer: "; cin >> *ip;
    }

    cout << *dp << " " << *ip << endl;
    cout << dp << " " << ip << endl;
    cout << sizeof(*dp) << " " << sizeof(*ip) << endl;

    //Difference between array pointers and pointers
    int num[5] = {23, 44, 33, 55, 77};
    int *arrptr = num; //array pointer pointing to array
    for(int i = 0; i < 5; i++){ //array elements using array pointer
        cout << "Element: " << i << " at array index " << *(arrptr + i) << endl;
    }

    int x = 90;
    int *po = &x; //po pointing to x
    cout << "Value of x through pointer: " << *po << endl;
    int y = 16;
    po = &y; //now po is pointing tp y
    cout << "Value of pointer is now " << *po << endl;
    *po = 30; cout << "Pointer is now " << *po << endl; 

    // num = &y; //we cannot change address of array pointer.
    cout << *arrptr << endl; //points to base address of array - first element

    *arrptr = &y; //this is allowed

    system("pause");
}