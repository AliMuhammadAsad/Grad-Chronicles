#include<bits/stdc++.h>
using namespace std;

// -------------------------------------------------------------------------------- //
// Q1) Numbers (abstract class)
// Define a class Interface whos only role is to provide a common interface for the derived classes. It should provide the functions: display(), increment(). 
// Define your abstract class such that NumInterface n1; produces an error

class NumInterface {
    public:
        virtual void display() = 0;
        virtual void increment() = 0;
};

int main(){
    NumInterface n1; //uncommented, this should return an error that cannot declare a variable of abstract type. 
    cout << "Hello World!" << endl;
    return 0;
}

// -------------------------------------------------------------------------------- //
/* Q2) Numbers (abstract class)
From the base class derived in Q1, derive two classes:
1. NumWhole: // store values of whole numbers, 
 -NumWhole(val), getval(), setVal(), display(), increment(), operator+ -> add two whole numbers using the '+' operator

2. NumComplex: // store values of signed complex numbers 
 - NumComplex(real,imag), getReal(), getImag(), setReal(), setImag(), display(), increment(), operator+ -> add two complex numbers using the '+' operator 
*/

class NumInterface {
    public:
        virtual void display() const = 0;
        virtual void increment() = 0;
};

class NumWhole : public NumInterface{
    private:
        int val;
    public:
        NumWhole(){}
        NumWhole(int value){val = value;}
        int getVal() const {return val;}
        void setVal(int value){val = value;}
        void display() const {cout << val;}
        void increment(){val++;}
        NumWhole operator+(const NumWhole n) const {
            NumWhole res; res.val = val + n.val;
            return res;
        }
};

class NumComplex: public NumInterface{
    private:
        int real, imag;
    public:
        NumComplex(){}
        NumComplex(int r, int i){real = r; imag = i;}
        int getReal() const {return real;}
        int getImag() const {return imag;}
        void setReal(int r){real = r;}
        void setImag(int i){imag = i;}
        void display() const {
            cout << "(" << real;
            imag >= 0 ? cout << "+" : cout << "-";
            imag >= 0 ? cout << imag: cout << -imag;
            cout << "i" << ")";
        }
        void increment(){real++; imag++;}
        NumComplex operator+(const NumComplex &n){
            NumComplex res;
            res.real = real + n.real; res.imag = imag + n.imag;
            return res;
        }
};

int main(){
    NumWhole n1(33u), n2(44u);
    n1.display(); cout<<","; n2.display(); cout<<endl; //33,44 followed by newline

    // displaying const numbers
    NumWhole const n3(55u), n4(66u);
    n3.display(); cout<<","; n4.display(); cout<<endl; //55,66 followed by newline

    NumWhole n5 = n3 + n4;
    n5.increment(); n5.display(); cout<<endl;   //should display 122, followed by a newline

    NumComplex c1(2,0), c2(4,-5);
    c1.display(); c2.display(); cout<<endl; //(2+0i)(4-5i) followed by newline

    NumComplex const c3(2,0), c4(4,-5);
    c3.display(); c4.display(); cout<<endl; //(2+0i)(4-5i) followed by newline

    NumComplex c5 = c3 + c4;
    c5.increment(); c5.display(); cout<<endl; //(y-4i) followed by newline

    NumInterface const * p[10] = {&n1, &n2, &n3, &n4, &n5, &c1, &c2, &c3, &c4, &c5};

    // below display: 33,44,55,66,122,(2+0i),(4-5i),(2+0i),(4-5i),(7-4i),
    for(int i=0; i<10; i++){
        p[i]->display();
        cout<<",";
    }
    cout<<endl;
    return 0;
}


// -------------------------------------------------------------------------------- //
/*Q3 - Hotel Rooms:
In a Hotel there are two types of rooms Simple Hotel room and Apartment room. Apartment are expensive as compared to Simple rooms. 
Define a class HotelRoom which has two int members for storing the number of bathrooms and bedrooms. 
Define a constructor which initializes these members. 
Also define a function named get_price , which calculates the prices using this formuls: 50 * (# of bedrooms) + 100 * (# of bathrooms) 

Define another class called Apartment which inherits from HotelRoom. Define a relevant constructor for it. 
This class also has a get_price function which calculate the price using the above formula plus 100. 

Write a main() which takes int n as input and creates a vector of type HotelRoom* of size n. Then takes n lines of input. 
Each line contains the type of room, number of bed rooms and number of bathrooms. 
You have to create an object based on the type of room and add it into the array. 
After taking the input, loop through all the rooms and calculate the total price(profit) of all the rooms and print it. */

class HotelRoom{
    public:
    int bathroom_num, bedroom_num;
    HotelRoom(){bathroom_num = 0; bedroom_num = 0;}
    HotelRoom(int bathrooms, int bedrooms){bathroom_num = bathrooms; bedroom_num = bedrooms;}
    virtual int get_price(){
        return 100*bathroom_num + 50*bedroom_num;
    }
};

class Apartment : public HotelRoom{
    public:
    Apartment(int bathrooms, int bedrooms) : HotelRoom(bathrooms, bedrooms) {};
    int get_price(){
        return HotelRoom::get_price() + 100;
    }
};

int main(){
    int n; cin >> n; 
    string type; int bedrooms; int bathrooms;
    vector<HotelRoom*> Room;
    for(int i = 0; i < n; i++){
        cin >> type >> bedrooms >> bathrooms;
        if(type == "standard") Room.push_back(new HotelRoom(bathrooms, bedrooms));
        else if (type == "apartment") Room.push_back(new Apartment(bathrooms, bedrooms));
    }
    int total_price = 0;
    for(int i = 0; i < n; i++) total_price += Room[i]->get_price();
    cout << total_price;
}