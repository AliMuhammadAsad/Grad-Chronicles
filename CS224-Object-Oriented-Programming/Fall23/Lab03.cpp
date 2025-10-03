#include<bits/stdc++.h>
using namespace std;

// -------------------------------------------------------------------------------- //
// Q1) Sorting an Array of Strings using pointers;
// Sort an array of strings using pointers.
// You have to define the following functions:
// main: takes n as user input, creates an array of size n which can store strings, pass the array to a sort function, finally print the strings.
// sort: takes an array of strings and size n as parameters, loops through the array and sort all the strings
void swap(string* a, string* b){
    string temp = *a; *a = *b; *b = temp;
}

void sorter(string arr[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                swap(&arr[j], &arr[j + 1]); 
            }
        }
    }
}


int main() {
    // write your main() code here
    int n; cin >> n; cin.ignore();
    string* arr = new string[n];
    for(int i = 0; i < n; i++){
        getline(cin, arr[i]);
    }
    sorter(arr, n);
    for(int i = 0; i < n; i++){
        cout << arr[i] << endl;
    }
    delete[] arr;
    return 0;
}

// -------------------------------------------------------------------------------- //
// Q2) Swapping Values: write a function that takes pointers to two integers and swaps the values of the integers

void swap(int* a, int* b){
    int temp = *a; *a = *b; *b = temp;
}

int main() {
    int a, b;
    cin >> a >> b;
    swap(&a, &b);
    cout << a << ' ' << b;    
    return 0;
}

// -------------------------------------------------------------------------------- //
// Q3) Points on a line?
// Given an array of points in a two dimensional space, find out if all the points lie on a line
// both arr1 = [(0, 1), (1, 2), (3, 4), (3.5, 4.5)] and arr2 = [(-6, -1), (-5, -2), (-4, -3), (-2, -5), (-1, -6)]
// Constraints: Assume that points are already sorted by increasing order of their x coordinate.
// Hint: This has something to do with the first derivative or the difference between consecutive points of arr1 or arr2

struct Point{
    float x; float y;
};

/*
 * Complete the 'isLine' function below. 
 * The function receives arrayOfPoints and returns True if all points in arrayOfPoints lie within in a line
 */

bool isLine(vector<Point> arrayOfPoints) {
// use arrayOfPoints[i].x to access x coordinate of ith point
// use arrayOfPoints[i].y to access y coordinate of ith point 
    int length = arrayOfPoints.size(); // length is the total number of points inside arrayOfPoints
    if(length < 2) return true;
    
    double slope = (arrayOfPoints[1].y - arrayOfPoints[0].y) / (arrayOfPoints[1].x - arrayOfPoints[0].x);
    for(int i = 2; i < length; i++){
        double curr = (arrayOfPoints[i].y - arrayOfPoints[i - 1].y) / (arrayOfPoints[i].x - arrayOfPoints[i - 1].x);
        if(curr != slope) return false;
    }
    return true;
}