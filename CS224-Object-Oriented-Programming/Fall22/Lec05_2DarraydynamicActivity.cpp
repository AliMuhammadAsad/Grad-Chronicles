#include <iostream>
using namespace std;
int** create2Darray(int row , int col);
void populate2Darray(int** arr , int r , int c);
void print2Darray(int** a , int rr , int cc);
void releaseMemory(int** w);

int main()
{
    //2D array - Dynamic memory allocation
    //=====================================

    // p is a pointer of 2D array - dimensions 4X5
    int** p = create2Darray(4 , 5);
    populate2Darray(p , 4 , 5 ); // it will populate the 2Darray with random integers
    print2Darray(p,  4, 5); //outputs the 2Darray to screen
    releaseMemory(p); //releasing the memory created dynamically
   
    system("pause");

}

int** create2Darray(int row,int col){
    int** arr = new int*[row];
    for(int i = 0; i < col; i++)
        *(arr + i) = new int[col];
    return arr;
}

void populate2Darray(int** arr,int r,int c){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            *(*(arr + i) + j) = rand(); 
            // cin >> *(*(arr + i) + j);
        }
    }
}

void print2Darray(int** a,int rr,int cc){
    for(int i = 0; i < rr; i++){
        for(int j = 0; j < cc; j++){
            cout << *(*(a + i) + j) << ' ';
        }
        cout << endl; //changes the row
    }
}

void releaseMemory(int** w){ /*For some reason, its giving me wrong number of rows so I am having trouble in generalising
                               unless the rows are already given and passed as paramter in this function. */

    // int rows = sizeof(w) / sizeof(*(w + 0));
    // for(int i = 0; i < rows; i++){
    //     delete[] *(w + i); *(w + i) = NULL;
    // }
    // delete[] w; w = NULL;
    // cout << rows;

    for(int i = 0; i < 4 ; i++){
        delete[] *(w + i); *(w + i) = NULL;
    }
    delete[] w; w = NULL;
}