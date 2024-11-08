#include<iostream>
using namespace std;

//----------------------------------------------------------------------------------------//

//Q1 - Body Temperature - Fahrenheit to Celsius and difference from normal temp
int main(){
    float F, C, above;
    cin >> F; C = (F - 32) / 1.8; above = C - 37;
    cout << F << " F is " << above << " C above normal body temperature.";
}

//----------------------------------------------------------------------------------------//

//Q2 - Hurricane Harvey - mph to kmh 
int main(){
    float mph, kmh; 
    cin >> mph; kmh = mph * 1.6;
    cout << mph << " mi/h are equivalent to " << kmh << " km/h.";
    //Testing
    //Another line added
}

//----------------------------------------------------------------------------------------//

//Q3 - Trip to Bahamas - Celsius to Fahrenheit

int main() {
    float C, F;
    cin >> C; F = (1.8 * C) + 32;
    cout << C << " C are equivalent to " << F << " F.";
}

//----------------------------------------------------------------------------------------//

//Q4 - Data type sizes - size of each data type

int main()
{
    cout << "The size of char is: " << sizeof(char) << " bytes" << endl;
    cout << "The size of int is: " << sizeof(int) << " bytes" << endl;
    cout << "The size of float is: " << sizeof(float) << " bytes" << endl;
    cout << "The size of double is: " << sizeof(double) << " bytes" << endl;
    cout << "The size of long is: " << sizeof(long) << " bytes" << endl;
    cout << "The size of short is: " << sizeof(short) << " bytes" << endl;
    cout << "The size of bool is: " << sizeof(bool) << " bytes" << endl;
    return 0;
}

//----------------------------------------------------------------------------------------//

//Q5 - Swap two numbers

int main()
{
    int value1, value2, swapper;
    cin>>value1;
    cin>>value2;
    swapper = value1; value1 = value2; value2 = swapper;
    // Write logic to swap value1 and value2
    
    cout<<value1<<" "<<value2;
}

//----------------------------------------------------------------------------------------//

//Q6 - Count Currency - Takes amount and diff notes with which it can be represented

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int amount, f5000, th1000, f500, h100, f50, t20, t10, f5, t2, o1;
    cin >> amount;
    
    f5000 = amount / 5000; amount = amount - (5000 * f5000);
    th1000 = amount / 1000; amount = amount - (1000 * th1000);
    f500 = amount / 500; amount = amount - (500 * f500);
    h100 = amount / 100; amount = amount - (100 * h100);
    f50 = amount / 50; amount = amount - (50 * f50);
    t20 = amount / 20; amount = amount - (20 * t20);
    t10 = amount / 10; amount = amount - (10 * t10);
    f5 = amount / 5; amount = amount - (5 * f5);
    t2 = amount / 2; amount = amount - (2 * t2);
    o1 = amount;
    
    cout << "Total number of notes:" << endl;
    cout << "5000 : " << f5000 << endl;
    cout << "1000 : " << th1000 << endl;
    cout << "500 : " << f500 << endl;
    cout << "100 : " << h100 << endl;
    cout << "50 : " << f50 << endl;
    cout << "20 : " << t20 << endl;
    cout << "10 : " << t10 << endl;
    cout << "5 : " << f5 << endl;
    cout << "2 : " << t2 << endl;
    cout << "1 : " << o1 << endl;  
    return 0; 
}

//----------------------------------------------------------------------------------------//

//Q7 - How tall are you - converts meters to fts and inches
// 1 inch = 2.54 cm and 1 ft = 12 inches

int main(){
    float meters, cm; int inch, ft;
    cin >> meters;
    cm = meters * 100; ft = (cm / 2.54) / 12; inch = (cm / 2.54) - (ft * 12);
    cout << meters << " m is approximately equivalent to " << ft << " ft and " << inch << " inches!";
}

//----------------------------------------------------------------------------------------//

//Q8 - Case converter - takes small character as input, converts it to capital 
//built in functions not allowed - use ASCII codes

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char small;
    cin >> small;
    cout << char(int(small) - 32);
    
    return 0;
}

//----------------------------------------------------------------------------------------//

//Q9 - Quotient Remainder - takes dividend and divisor as input, prints its quotient and remainder

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int dividend, divisor, quotient, remainder;
    cin >> dividend >> divisor;
    quotient = dividend / divisor; remainder = dividend - (quotient * divisor);
    cout << quotient << " " << remainder;
    return 0;
}