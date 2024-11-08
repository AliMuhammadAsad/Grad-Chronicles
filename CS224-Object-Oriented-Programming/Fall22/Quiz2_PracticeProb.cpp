//Sorting a list of strings using pointers
/* You have to define the following functions:
1. main function: in this function you will first take n as user input then create an array of size n which can store strings. 
Then take n strings from user and put them into the array of strings. Then pass this array of strings to the sort function. Finally print the strings.
2. sort function: this function take an array of strings and size n as parameters. loop throgh the array and sort all the strings. */

#include<iostream>
#include<cstring>


using namespace std;
/// define sort() function here

void sort(char **arr, int size){
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - 1 - i; j++){
            int res = strcmp(*(arr + j), *(arr + j + 1));
            if(res > 0){
                char *temp = *(arr + j + 1); *(arr + j + 1) = *(arr + j); *(arr + j) = temp;
            }
        }
    }
    
}


int main() 
{
    // write your main() code here
    int n; cin >> n; cin.ignore();
    char** arr = new char*[n];
    for(int i = 0; i < n; i++){
        *(arr + i) = new char[1000];
        cin.get(*(arr + i), 10000); cin.ignore();
    }
    
    sort(arr, n);
    
    for(int i = 0; i < n; i++){
        cout << *(arr + i) << endl;
    }
    
    return 0;
}
