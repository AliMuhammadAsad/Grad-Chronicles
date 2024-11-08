#include<iostream>
using namespace std;
// Topics Covered:
// Arrays, local variables, and functions, passing array to a function
// printing array address
// Memory organisation of an array


//local variables are much like they were in python, local variable is kept to the scope of the function etc, while global is not

int find_holes(int x){ //returns the number of holes in the given integer, like 1 has no hole, 4 has 1 hole in between, 8 has 2 holes in it etc.
    int nHoles = 0; int r = 0;
    while(x > 0){
        r = x % 10;
        if (r == 4 || r == 6 || r == 9 || r == 0) nHoles += 1;
        else if (r == 8) nHoles += 2;
        x /= 10;
    }
    return nHoles;
}

void holes_in_array(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout << find_holes(arr[i]) << endl;
    }
}

int main(){
    //1, 2, 3, 5, 7 -> 0 Holes
    //4, 6, 9, 0 -> 1 Hole
    //8 -> 2 holes
    int num[5] = {24, 757, 76778, 789797, 353599};
    holes_in_array(num, 5);
    cout << "Array size is: " << sizeof(num) / 4 << endl;

    system("pause");
}