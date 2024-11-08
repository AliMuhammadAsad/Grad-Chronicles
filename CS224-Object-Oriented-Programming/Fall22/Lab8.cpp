//Q1 Complex Calculator using operator overloading
#include<iostream>

using namespace std;

class Complex{
    private:
        double real, imag;
    public:
        Complex(){
            real = 0; imag = 0;
        }    
        
        Complex(double a, double b){
            real = a; imag = b;
        }
        
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
            if(num.imag > 0) out << num.real << "+" << num.imag << "i";
            else out << num.real << num.imag << "i";
            return out;
        }
};


int main(){
   Complex c1, c2;
    
    cin>>c1; //extraction operator is overloaded
    cin>>c2;

    double d1;
    cin>>d1;
    
    Complex result;
    //showing the numbers:
    cout<<"c1: "<< c1 <<endl; // insertion operator is overloaded
    cout<<"c2: "<< c2 <<endl; 
    cout<<"d1: "<< d1 <<endl;

    // Check the opertions where both operands are complex
    result = c1 + c2; 
    cout<<"c1+c2: "<<result<<endl;
    
    
    result = c1 - c2; 
    cout<<"c1-c2: "<< result <<endl;
    
    result = c1 * c2; 
    cout<<"c1*c2: "<< result <<endl;
    
    // Check the opertions where one operator is complex, other is double

    result = c1 + d1; 
    cout<<"c1+d1: "<< result <<endl;
    
    
    result = c1 - d1; 
    cout<<"c1-d1: "<< result <<endl;
    
    result = c1 * d1; 
    cout<<"c1*d1: "<< result <<endl;
}

//-------------------------------------------------------------------------------------------------------------------------------------

//Q2 Area Calculator using operator overloading

#include<iostream>

using namespace std;

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

//-----------------------------------------------------------------------------------------------------------------------------------
//DataRate Class
#include<iostream>
#include<cmath>
using namespace std;

class DataRate{
    public:
    unsigned int rate; string type = "bit/s";
    DataRate(){rate = 0;}
    DataRate(unsigned int x){rate = x;}
    DataRate(unsigned int x, unsigned int exp){rate = x * pow(10, exp);}
    DataRate(unsigned int x, string unit){
        if(unit == "bps" || unit == "bit/s" || unit == "b/s") rate = x;
        else if(unit == "kbps" || unit == "kbit/s" || unit == "kb/s") rate = x * 1000;
        else if(unit == "Mbps" || unit == "Mbit/s" || unit == "Mb/s") rate = x * 1000000;
        else if(unit == "Gbps" || unit == "Gbit/s" || unit == "Gb/s") rate = x * 1000000000;
    }
    void show(){
        cout << rate << " " << type << endl;
    }
};



int main(){
    unsigned int val, mult;
    string multiple;

    // DataRate sets zero in default constructor
    DataRate d1;

    cin>>val;
    // Rate is initilized to integer value supplied as bps
    DataRate d2(val);

    cin>>val>>mult;
    // Rate is initialized as val*10^mult bps
    DataRate d3(val, mult);


    cin>>val>>multiple;
    // Rate is initialized as the val*multiple, where multiple could be bps, kbps, Mbps, Gbps... 
    DataRate d4(val, multiple);

    // all of the datarates are shown here.
    d1.show();
    d2.show();
    d3.show();
    d4.show();

    return 0;
}
