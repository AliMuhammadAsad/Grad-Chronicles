#include<bits/stdc++.h>
using namespace std;
// -------------------------------------------------------------------------------- //
// Q1 TollBooth
// Model a TollBooth, using class TollBooth, public attributes total cars, and total money.
// Constructor initializes to 0, payingcar function incremenets cars by 1, money by 50, nopaycar incremenets cars by 1, money by 0.
// Display function displays total cars and total money.
class TollBooth{
    public:
        int totalcars, totalmoney;
        
    TollBooth(){
        totalcars = 0; totalmoney = 0;
    }
    
    void payingCar(){
        totalcars++; totalmoney+=50;
    }
    
    void nopayCar(){
        totalcars++; totalmoney+=0;
    }
    
    void display(){
        cout << "Total cars passed: " << totalcars << endl;
        cout << "Total toll collected: Rs. " << totalmoney << endl;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    TollBooth habibtoll;
    char car; cin >> car;
    while(car != 'q'){
        if(car == 'p') habibtoll.payingCar();
        else habibtoll.nopayCar();
        cin >> car;
    }
    habibtoll.display();
    return 0;
} 


// -------------------------------------------------------------------------------- //
// Q2) Stack Class using array
// Implement Stack ADT by creating a class that provides an interface for the following basic operations. Class should not be initializes without specifying the size of the stack.
// Code must take care of memory leaks and release memory resources.
class Stack{
    private:
        int* arr; int size, head;
    public:
        Stack(int s){
            size = s; arr = new int[size]; head = -1;
        }

        void push(int val){
            head++; arr[head] = val;
        }

        int pop(){
            int temp = arr[head]; head--;
            return temp; 
        }

        int top(){
            if(head == -1) return -1;
            else return arr[head];
        }

        bool isempty(){
            if(head == -1) return true;
            else return false;
        }

        ~Stack(){delete[] arr;}
};

int main()
{
    Stack stack1(10);
    
    cout << "Stack1 top is: " << stack1.top() <<endl;
    
    if (stack1.isempty())
    {
        cout << "Stack1 is empty" <<endl;
    }
    else
    {
        cout << "Stack1 is not empty" <<endl;
    }
    
    int nums;
    cin >> nums;
    
    for (int i = 0; i < nums; i++)
    {
        int a;
        cin>>a;
        stack1.push(a);
        cout<<"Pushed "<<a<<" to the Stack1.."<<endl;
    }
    
    cout << "Stack1 top is: " << stack1.top() <<endl;
    
    for (int i = 0; i < nums/2; i++)
    {
        cout << stack1.pop() << " popped from the Stack1."<<endl;
    }
    
    cout << "Stack1 top is: " << stack1.top() << endl;
    
    if (stack1.isempty())
    {
        cout << "Stack1 is empty" <<endl;
    }
    else
    {
        cout << "Stack1 is not empty" <<endl;
    }
    
    for (int i = 0; i < nums/2; i++)
    {
        cout << stack1.pop() << " popped from the Stack1."<<endl;
    }
    
    cout << "Stack1 top is: " << stack1.top() <<endl;
    
    if (stack1.isempty())
    {
        cout << "Stack1 is empty" <<endl;
    }
    else
    {
        cout << "Stack1 is not empty" <<endl;
    }
}


// -------------------------------------------------------------------------------- //
// Q3) Complex Calculator
// Define a class Complex that has two private attributes real, imag both of type double. 
// A default constructor that initializes the attributes with zero, and an overloaded constructor that initializes the attributes with supplied values.
// class also have methods to add, subtract, and multiply complex numbers. 
// Since complex numbers can be added/multiplied/subtracted with a real number as well, so the add, subtract and multiply functions should be overloaded: one where operand is Complex numbers, other where operand is real.
//  The class also have method show, that display the complex number is usual way i.e. x+yi
class Complex{
    private:
        double real, imag;
    public:
        Complex(){ real = 0; imag = 0; }    
        
        Complex(double a, double b){ real = a; imag = b; }
        
        Complex add(Complex num){
            Complex res;
            res.real = real + num.real;
            res.imag = imag + num.imag;
            return res;
        }
        
        Complex add(double num){
            Complex res;
            res.real = real + num; res.imag = imag;
            return res;
        }
        
        Complex subtract(Complex num){
            Complex res;
            res.real = real - num.real;
            res.imag = imag - num.imag;
            return res;
        }
        
        Complex subtract(double num){
            Complex res;
            res.real = real - num; res.imag = imag;
            return res;
        }
        
        Complex multiply(Complex num){
            Complex res;
            res.real = (real * num.real) - (imag * num.imag);
            res.imag = (real * num.imag) + (imag * num.real);
            return res;
        }
        
        Complex multiply(double num){
            Complex res;
            res.real = real * num;
            res.imag = imag * num;
            return res;
        }
        
        void show(){
            if(imag < 0) cout << real << imag << "i" << endl;
            else cout << real << "+" << imag << "i" << endl; 
        }
};

int main(){
    double real, imag;
    cin>>real>>imag;
    Complex c1 = {real, imag};

    cin>>real>>imag;
    Complex c2 = {real, imag};

    double d1;
    cin>>d1;
    
    Complex result;
    //showing the numbers:
    cout<<"c1: "; c1.show();
    cout<<"c2: "; c2.show();
    cout<<"d1: "<<d1<<endl;

    // Check the opertions where both operands are complex
    result = c1.add(c2); 
    cout<<"c1+c2: "; result.show();
    
    
    result = c1.subtract(c2); 
    cout<<"c1-c2: "; result.show();
    
    result = c1.multiply(c2); 
    cout<<"c1*c2: "; result.show();
    
    // Check the opertions where one operator is complex, other is double

    result = c1.add(d1); 
    cout<<"c1+d1: "; result.show();
    
    
    result = c1.subtract(d1); 
    cout<<"c1-d1: "; result.show();
    
    result = c1.multiply(d1); 
    cout<<"c1*d1: "; result.show();
}

// -------------------------------------------------------------------------------- //
// Q4) Time12 Hours
// Create a class Time12 that has the private member attributes hours, minutes, seconds, period, and separator.
// Time12() initializes: hours = 12, minutes = 0, seconds = 0, period = 'A', separator = ':'.
// Time12(int h) initializes: hours = h, minutes = 0, seconds = 0, period = 'A', separator = ':'.
// Time12(int h, int m) initializes: hours = h, minutes = m, seconds = 0, period = 'A', separator = ':'.
// Time12(int h, int m, int s) initializes: hours = h, minutes = m, seconds = s, period = 'A', separator = ':'.
// Time12(int h, int m, int s, char p) initializes: hours = h, minutes = m, seconds = s, period = p, separator = ':'.
// Time12(int h, int m, int s, char p, char sep) initializes: hours = h, minutes = m, seconds = s, period = p, separator = sep.
// show() displays the time in 12 hour format, e.g. 10:30:45AM
// You are not allowed to use getter/setter functions for private attributes.
// All values are going to be valid, that is, there is going to be no overflow to be checked. 
class Time12{
    private:
        int hours, minutes, seconds; char period, separator;
    public:
    
    Time12(){
        hours = 12; minutes = 0; seconds = 0; period = 'A'; separator = ':';    
    } 
    Time12(int h){
        hours = h; minutes = 0; seconds = 0; period = 'A'; separator = ':'; 
    }
    Time12(int h, int m){
        hours = h; minutes = m; seconds = 0; period = 'A'; separator = ':';
    }
    Time12(int h, int m, int s){
        hours = h; minutes = m; seconds = s; period = 'A'; separator = ':';
    }
    Time12(int h, int m, int s, char p){
        hours = h; minutes = m; seconds = s; period = p; separator = ':'; 
    }
    Time12(int h, int m, int s, char p, char sep){
        hours = h; minutes = m; seconds = s; period = p; separator = sep; 
    }
    
    void show(){
        cout << hours << separator;
        if(minutes < 10) cout << "0" << minutes << separator;
        else cout << minutes << separator;
        if(seconds < 10) cout << "0" << seconds;
        else  cout << seconds;
        cout << period << "M" << endl;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    Time12 t1(12); t1.show();
    Time12 t2(7); t2.show();
    Time12 t3(10, 34); t3.show();
    Time12 t4(12, 2, 10); t4.show();
    Time12 t5(10, 30); t5.show();
    Time12 t6(10, 10, 10, 'P', '-'); t6.show();
    return 0;
}