#include<bits/stdc++.h>
using namespace std;

// -------------------------------------------------------------------------------- //
// Q1) Time 24 hours:
// Write a function validatedTime that takes in hours, minutes, seconds. The function has multiple definitions:

void validatedTime(){
    cout << "00:00:00" << endl;
}

void validatedTime(int hours){
    if(hours >= 24){
        hours = hours % 24;
    }
    if(hours < 10) cout << "0" << hours << ":00:00" << endl;
    else cout << hours << ":00:00" << endl;
}

void validatedTime(int hours, int minutes){
    if(minutes >= 60){
        hours += (minutes / 60); minutes = minutes % 60;
    }
    
    if(hours >= 24){
        hours = hours % 24;
    }
    
    if(hours < 10) cout << "0" << hours;
    else cout << hours;
    
    if(minutes < 10) cout << ":0" << minutes;
    else cout << ":" << minutes;
    cout << ":00" << endl;
}

void validatedTime(int hours, int minutes, int seconds){
    if(seconds >= 60){
        minutes += (seconds / 60); seconds = seconds % 60;
    }
    
    if(minutes >= 60){
        hours += (minutes / 60); minutes = minutes % 60;
    }
    
    if(hours >= 24){
        hours = hours % 24;
    }
    
    if(hours < 10) cout << "0" << hours;
    else cout << hours;
    
    if(minutes < 10) cout << ":0" << minutes;
    else cout << ":" << minutes;
    
    if(seconds < 10) cout << ":0" << seconds;
    else cout << ":" << seconds;
}
int main(){
    int hours, minutes, seconds;
    cin>>hours>>minutes>>seconds;
    validatedTime();
    validatedTime(hours);
    validatedTime(hours, minutes);
    validatedTime(hours, minutes, seconds);
}

// -------------------------------------------------------------------------------- //
// Q2) Complex Calculator - Overloaded
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
    if(*(c + 1) < 0) cout << *(c + 0) << *(c + 1) << "i" << endl;    
    else cout << *(c + 0) << "+" << *(c + 1) << "i" << endl;
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

// -------------------------------------------------------------------------------- //
// Q3) Holes in a number/Alphabet - Overloading + Recursion
int holes = 0;
int rem = 0;

int countHoles(int num){
    if(num > 0){
        rem = num % 10;
        if(rem == 8) holes += 2;
        else if(rem == 0 || rem == 4 || rem == 6 || rem == 9) holes++;
        return countHoles(num / 10);
    }
    return holes;
}

int string_length(char line[]){
    int len = 0;
    while(line[len] != '\0') len++;
    return len;
}

int i = 0;
int countHoles(char* word){
    int len = string_length(word);
    if(i < len){
        if(*(word + i) == 'A' || *(word + i) == 'D' || *(word + i) == 'O' || *(word + i) == 'P' || *(word + i) == 'Q' || *(word + i) == 'R') holes++;
        else if(*(word + i) == 'B') holes += 2;
        else if((*word + i) == '\n'){holes = holes; i = 0;}
        // cout << "i: " << i << "\tholes: " << holes << "\tChar: " << *(word + i) << endl;  
        i++;
        return countHoles(word);
    }
    i = 0;
    return holes;
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
            nHoles=countHoles(carr);
        }
    }
    
    cout << nHoles <<" holes";
    return 0;
}

// -------------------------------------------------------------------------------- //
// Q4) Call Me
// Write a function callMe(), (notice it has no arguments), displays a message that this function has been called for a number of times. So basically keeping track of number of function calls.
// Do this in 2 ways: M1) Using a global variable. M2) Using a local static variable.
// Comment on whichever method is more appropriate.

// Method 1: Global Variable
// int count = 0;
// void callMe(){
//     count++; cout << "I have been called " << count << " times" << endl;
// }

// int main(){
//     for(int i = 0; i < 10; i++) callMe();
//     return 0;
// }

// Method 2: Local Static Variable
void callMe(){
    static int count = 0;
    count++; cout << "I have been called " << count << " times" << endl;
}

int main(){
    for(int i = 0; i < 10; i++) callMe();
    return 0;
}

// Using a local static variable is obviously more appropriate since the variable keeps count encapsulated within the function. We don't need to define the variable outside the function and it can't be called outside either as its not being used directly, rather, just for function counts. In addition, it makes the program more simple reducing the need for unnecessary global variables.