#include<bits/stdc++.h>
using namespace std;

// -------------------------------------------------------------------------------- //
// Q1) Identify Character - C++
// Given a character input, identify if the character is a lower case, upper case, digit or a special character.

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    char c; cin >> c; int v = int(c);
    if(v >= 48 && v <= 57) cout << c << " is a digit" << endl;
    else if(v >= 65 && v <= 90) cout << c << " is an upper case letter" << endl;
    else if(v >= 97 && v <= 122) cout << c << " is a lower case letter" << endl;
    else cout << c << " is a special character" << endl;
    return 0;
}

// -------------------------------------------------------------------------------- //
// Q2) 12-Hour to 24-Hour Clock - C++
// Write a program that takes two integer inputs:
// 1) time in hours between 1 to 12 
// 2) whether it is am(1) or pm(2)
// Convert it into 24hour format and print on the screen

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int time_in_hours, dn; cin >> time_in_hours >> dn;
    cout << (dn == 1 ? time_in_hours : time_in_hours + 12) << endl;
    return 0;
}

// -------------------------------------------------------------------------------- //
// Q3) Number Checker - C++
// Take input and print true if satisfies the following conditions:
// 1) is divisible by 2 and 3, 2) is not divisible by 5, 3) is either 36 or less, or greater than 200, 4) value of the least significant digit is greater than the second least significant digit

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n; cin >> n;
    if((n % 2 == 0 && n % 3 == 0) && (n % 5 != 0) && (n <= 36 || n > 200) && (n % 10 > (n / 10) % 10)) cout << "True" << endl;
    else cout << "False" << endl;
    return 0;
}

// -------------------------------------------------------------------------------- //
// Q4) Estate Agency
// You get an input of plot size, output total cost by adding commission and tax

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int size; double ap; cin >> size;
    switch(size){
        case 120: ap = 1000000; cout << fixed << setprecision(0) << (ap * 1.015) + (ap * 0.02) << endl; break;
        case 150: ap = 1500000; cout << fixed << setprecision(0) << (ap * 1.015) + (ap * 0.018) << endl; break;
        case 200: ap = 3000000; cout << fixed << setprecision(0) << (ap * 1.015) + (ap * 0.015) << endl; break;
        case 500: ap = 8000000; cout << fixed << setprecision(0) << (ap * 1.015) + (ap * 0.01) << endl; break;
        default: cout << "Your desired plot size is not in this scheme" << endl; break;
    }   
    return 0;
}

// --------------------------------------------------------------------------------- //
// Q5) Date Compare : Takes two dates, prints the greater one

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int d1, d2, m1, m2, y1, y2; cin >> d1 >> m1 >> y1 >> d2 >> m2 >> y2;
    if(y1 > y2) cout << d1 << " " << m1 << " " << y1 << endl;
    else if(y2 > y1) cout << d2 << " " << m2 << " " << y2 << endl;
    else{
        if(m1 > m2) cout << d1 << " " << m1 << " " << y1 << endl;
        else if(m2 > m1) cout << d2 << " " << m2 << " " << y2 << endl;
        else{
            if(d1 > d2) cout << d1 << " " << m1 << " " << y1 << endl;
            else if(d2 > d1) cout << d2 << " " << m2 << " " << y2 << endl;
            else cout << "The given dates are same." << endl;
        } 
    }
    return 0;
}

// --------------------------------------------------------------------------------- //
// Q6) Countup - C++
// program that takes two ints a and b, and counts up from the smaller to larger number inclusive (make a separate function)
void countup(int a, int b){
    int s = min(a, b); int l = max(a, b);
    for(int i = s; i < l; i++){
        cout << i << ", ";
    }
    cout << l << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int a, b; cin >> a >> b;
    countup(a, b);
    return 0;
}

// --------------------------------------------------------------------------------- //
// Q7) Magic Number
// Given an array of positive integers, a magic number has frequency in an array equal to its value. Return the largest magic number

// 1) Using vectors:
int findMaxMagicNumber(int arr[], int size){
    vector<int> freq(size + 1, 0);
    for(int i = 0; i < size; i++){
        freq[arr[i]]++;
    }
    int magnum = -1;
    for(int i = 1; i <= size; i++){
        int f = freq[i];
        if(i == f && f > magnum) magnum = f;
    }
    return magnum;
}

// 2) Using arrays
int findMaxMagicNumber(int arr[], int size){
    int* freq = new int[size + 1];
    for(int i = 0; i < size; i++) freq[i] = 0;
    
    for(int i = 0; i < size; i++) freq[arr[i]]++;
    
    int magnum = -1;
    
    for(int i = 1; i <= size; i++){
        if(i == freq[i] && i > magnum) magnum = i;  
    }
    
    return magnum;
}