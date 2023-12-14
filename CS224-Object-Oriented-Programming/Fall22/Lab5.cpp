//Q1 Complex Number Calculator using overloaded functions

#include<iostream>
using namespace std;

double *add(double *c1, double *c2){
    double *c3 = new double[2];
    *(c3 + 0) = *(c1 + 0) + *(c2 + 0);
    *(c3 + 1) = *(c1 + 1) + *(c2 + 1);
    return c3;
}

double *add(double *c1, double c2){
    double *c3 = new double[2];
    *(c3 + 0) = *(c1 + 0) + c2;
    *(c3 + 1) = *(c1 + 1);
    return c3;
}


double *subtract(double *c1, double *c2){
    double *c3 = new double[2];
    *(c3 + 0) = *(c1 + 0) - *(c2 + 0);
    *(c3 + 1) = *(c1 + 1) - *(c2 + 1);
    return c3;
}

double *subtract(double *c1, double c2){
    double *c3 = new double[2];
    *(c3 + 0) = *(c1 + 0) - c2;
    *(c3 + 1) = *(c1 + 1);
    return c3;
}



double *multiply(double *c1, double *c2){
    double *c3 = new double[2];
    *(c3 + 0) = (*(c1 + 0) * *(c2 + 0)) - (*(c1 + 1) * *(c2 + 1));
    *(c3 + 1) = (*(c1 + 0) * *(c2 + 1)) + (*(c1 + 1) * *(c2 + 0));
    return c3;
}

double *multiply(double *c1, double c2){
    double *c3 = new double[2];
    *(c3 + 0) = *(c1 + 0) * c2;
    *(c3 + 1) = *(c1 + 1) * c2;
    return c3;
}

void show(double *c){
    if(*(c + 1) < 0){
        cout << *(c + 0) << *(c + 1) << "i" << endl;    
    }
    else{
        cout << *(c + 0) << "+" << *(c + 1) << "i" << endl;
    }
    
}


int main()
{
    // there are two elements in this array the first one represents the real part and second one represents imagenary part
    double * c1 = new double[2]; 
    double * c2 = new double[2];
    
    cin>>c1[0]>>c1[1];
    cin>>c2[0]>>c2[1];

    double d1;
    cin>>d1;

    cout<<"c1+c2: "; show(add(c1,c2));
    cout<<"c1-c2: "; show(subtract(c1,c2));
    cout<<"c1*c2: "; show(multiply(c1,c2));

    
    cout<<"c1+d1: "; show(add(c1,d1));
    cout<<"c1-d1: "; show(subtract(c1,d1));
    cout<<"c1*d1: "; show(multiply(c1,d1));
}

//-----------------------------------------------------------------------------------------------//

//Q2 Remove Duplicates in same array without using another temporary array

#include<iostream>

using namespace std;
// create the RemoveDuplicates function here

int RemoveDuplicates(int *arr, int size){
    int i = 0; int j = 1;
    while(j < size){
        if(*(arr + i) == *(arr + j))
            j++;
        else{
            *(arr + i + 1) = *(arr + j); i++;
        }
    }
    return i+1;
}
// Do Not Make Changes in Main


int main() {
    
    int size;
    cin >> size;
    int* arr = new int[size];
    
    for(int i=0; i<size; i++)
    {
        cin>> *(arr+i) ;
    }
    
    int k = RemoveDuplicates(arr, size);
    
    for(int i=0; i < k; i++)
    {
        cout << arr[i] << " " ;
    }
    
    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------------------------//
//Q3 - Count holes in a number/word - function overloading and recursion.

#include<iostream>
#include<string>
#include<cstring>

using namespace std;

// write your code here
int num_holes = 0; int rem = 0;

int countHoles(int num){
    if(num > 0){
        rem = num % 10;
        if(rem == 0 || rem == 4 || rem == 6 || rem == 9)
            num_holes = num_holes + 1;
        else if(rem == 8)
            num_holes = num_holes + 2;
        else 
            num_holes = num_holes;
        return countHoles(num/10);
    }
    return num_holes;
}

int string_length(char line[]){
    int count = 0;
    while(line[count] != '\0')
        count++;
    return count;
}

int iter = 0;
int countHoles(char* word){
    int length = string_length(word);
    if(iter < length){
        if( *(word + iter) == 'A' || *(word + iter) == 'D' || *(word + iter) == 'O' || *(word + iter) == 'P' || *(word + iter) == 'Q' || *(word + iter) == 'R')
            num_holes++;
        else if( *(word + iter) == 'B')
            num_holes = num_holes + 2;
        else
            num_holes = num_holes;
        iter++;
        return countHoles(word);
    }
    iter = 0;
    return num_holes;  
}


// Please do not change the main()
int main() 
{
    string input;

    int nHoles=0;
    
    while(getline(cin,input))
    {
        if(isdigit(input[0]))
        {
            nHoles=countHoles(stoi(input));
        }
        else
        {
            char * carr = new char[input.length()];
            carr = strcpy(carr, input.c_str());
            nHoles =countHoles(carr);
        }
    }
    
    cout << nHoles <<" holes";
    return 0;
}
