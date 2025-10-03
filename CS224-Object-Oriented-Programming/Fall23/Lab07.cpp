#include<bits/stdc++.h>
using namespace std;

// -------------------------------------------------------------------------------- //
// Q1 Area Calculator using Operator Overloading
// Class Area that has two variables (length and width), of type "Distance" (a struct), to model area of rectangle. 
// Initialize a variable of type Area to specific dimensions (taken as input). Overload the double operator so that Area object can be converted to double value, returning area in square feet.

struct Distance{
    double feet, inches;
};

// Write the Area class here, and overload the double operator in it.
class Area{
    private:
        Distance l, w; //l refers to lenght, w refers to width
    public:
    Area(Distance length, Distance width){
        l = length; w = width;
    }
    operator double(){
    double l1, w1, area;
    l1 = l.feet + (l.inches / 12);
    w1 = w.feet + (w.inches / 12);
    area = l1 * w1;
    return area;
    }
};
int main(){
    double ft1, ft2, in1, in2;
    cin>>ft1>>in1>>ft2>>in2;
    Area area1 = {{ft1, in1}, {ft2,in2}};
    
    double decimalArea = area1; // overload the double operator to convert area object into decimal value.
    cout<<"Area is: "<< decimalArea <<"sq feet"<<endl;

}

// -------------------------------------------------------------------------------- //
// Q2 Time using operator overloading
// Create a class Time that has separate int members data for hours, minues and seconds.
// One constructor initializes it to 0, and one initializes it to passed values.
// another member "show" displays time in 23:59:59 format.
// overloaded operator + that adds the time and returns a time object.

class Time{
    private:
    int hours, minutes, seconds;
    void adjust(){
        int m_over = 0; int h_over = 0;
        if(seconds >= 60){
            m_over = seconds / 60;
            seconds = seconds % 60;
            minutes = minutes + m_over;
        }
        if(minutes >= 60){
            h_over = minutes / 60; minutes = minutes % 60; hours = hours + h_over;
        }
        if(hours >= 24) hours = hours % 24;
    }
    public:
    Time(){hours = 0; minutes = 0; seconds = 0;}
    Time(int h, int m, int s){
        hours = h; minutes = m; seconds = s;
        adjust();
    }
    Time operator + (Time time){
        Time result;
        result.hours = hours + time.hours; 
        result.minutes = minutes + time.minutes; 
        result.seconds = seconds + time.seconds;
        result.adjust();
        return result;
    }
    
    void show(){
        // adjust();
        if(hours < 10) cout << "0" << hours << ":";
        else if (hours >= 10) cout << hours << ":";
        if(minutes < 10) cout << "0" << minutes << ":";
        else if(minutes >= 10) cout << minutes << ":";
        if(seconds < 10) cout << "0" << seconds << endl;
        else if(seconds >= 10) cout << seconds << endl;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int hh, mm, ss;
    cin>>hh>>mm>>ss;
    Time t1(hh, mm, ss); //t1(hh, mm, ss)
    cin>>hh>>mm>>ss;
    Time t2(hh, mm, ss);
    Time t3;
    t3=t1+t2; //adding two times should produce a valid time, overflowed hours/minutes/seconds should be adjusted.
    // e.g. adding 18:10:20 with 10:20:30 results in 4:30:50
    
    t1.show();
    t2.show();
    t3.show();
    return 0;
}


// -------------------------------------------------------------------------------- //
// Q3 Complex Calculator using operator overloading

class Complex{
    private:
        double real, imag;
    public:
        Complex(){real = 0; imag = 0;}
        Complex(double a, double b){real = a; imag = b;}

        Complex operator +(Complex num){
            Complex res;
            res.real = real + num.real;
            res.imag = imag + num.imag;
            return res;
        }
        
        Complex operator +(double num){
            Complex res;
            res.real = real + num; res.imag = imag;
            return res;
        }
        
        Complex operator -(Complex num){
            Complex res;
            res.real = real - num.real;
            res.imag = imag - num.imag;
            return res;
        }
        
        Complex operator -(double num){
            Complex res;
            res.real = real - num; res.imag = imag;
            return res;
        }
        
        Complex operator *(Complex num){
            Complex res;
            res.real = (real * num.real) - (imag * num.imag);
            res.imag = (real * num.imag) + (imag * num.real);
            return res;
        }
        
        Complex operator *(double num){
            Complex res;
            res.real = real * num;
            res.imag = imag * num;
            return res;
        }

        friend istream& operator >>(istream& inp, Complex& num){
            inp >> num.real >> num.imag;
            return inp;
        }
        
        friend ostream& operator <<(ostream& out, Complex& num){
            if(num.imag > 0) out << num.real << " + " << num.imag << "i" << endl;
            else{
                num.imag = num.imag * -1;
                out << num.real << " - " << num.imag << "i" << endl;
            }
            return out;
        }
};

int main(int argc, char** argv){
    Complex c1; 
    Complex c2;

    cin >> c1; cin >> c2;
    Complex c3(c2 - c1);
    cout << c3;
    c3 = c1 * c2;
    cout << c3;
    return 0;
}