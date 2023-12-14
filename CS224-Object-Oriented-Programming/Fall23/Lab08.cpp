#include<bits/stdc++.h>
using namespace std;

// -------------------------------------------------------------------------------- //
/*  Q1) Publishing Company
Imagine a publishing company that markets both books and audio cassette versions of its works.
Create a class Publication that stores the title (a string) and price (type float) of a publication.
From this class derive two classes:
1. book, which adds a page_count(int)
2. tape, which adds a playing_time(float)
Each of these classes should have a function getdata() to get the data from the input stream and putdata() function displays its data to output stream */

class Publication{
    private:
        string title; float price;
    
    public:
        void getdata(){ getline(cin, title); cin >> price; }
        void putdata(){
            cout << "Publication title: " << title << endl;
            cout << "Publication price: " << price << endl;
        }
};

class book: public Publication{
    private:
        int page_count;
    public:
        void getdata(){ Publication::getdata(); cin >> page_count; }
        void putdata(){
            Publication::putdata();
            cout << "Book page count: " << page_count << endl;
        }
};

class tape: public Publication{
    private:
        float playing_time;
    public:
        void getdata(){ Publication::getdata(); cin >> playing_time; }
        void putdata(){
            Publication::putdata();
            cout << "Tape's playing time: " << playing_time << endl;
        }
};

int main()
{
    book b;
    tape t;
    b.getdata();
    cin.ignore();
    t.getdata();
    b.putdata();
    t.putdata();
}

// -------------------------------------------------------------------------------- //
/* Q2) Payment Class
Define a class named Payment that contains: 1)a private member variable of type double that stores the amount of the payment and appropriate accessor and mutator methods.
2) a method named paymentDetails() that outputs an English sentence that describes the amount of the payment.
 
Cash Payment Class
Define a class named CashPayment that is derived from Payment.
This class should redefine the paymentDetails() method to indicate that the payment is in cash. Include appropriate constructor(s).
 
Credit Card Payment Class
Define a class named CreditCardPayment that is derived from Payment.
This class should contain member variables for the name on the card, expiration date, and credit card number. Include appropriate constructor(s).
Redefine the paymentDetails() method to include all credit card information in the printout.*/

class Payment{
    private:
        double amount;
    public:
        void setamount(double pay){ amount = pay; }
        double getamount(){ return amount; }
        void paymentDetails(){ cout << amount << endl; } 
};

class CashPayment: public Payment{
    public:
    CashPayment(double cash){
        Payment::setamount(cash);
    }
    void paymentDetails(){ cout << "Amount of cash payment: $" << Payment::getamount() << endl; }
};

class CreditCardPayment: public Payment{
    private:
        string name, exp_date, credit_card_no;
    public:
        CreditCardPayment(double am, string naam, string exp, string cc_no){
            Payment::setamount(am); name = naam; exp_date = exp; credit_card_no = cc_no;
        }
        void paymentDetails(){
            cout << "Amount of credit card payment: $" << Payment::getamount() << endl;
            cout << "Name on the credit card: " << name << endl;
            cout << "Expiration date: " << exp_date << endl;
            cout << "Credit card number: " << credit_card_no << endl;
        }
};
