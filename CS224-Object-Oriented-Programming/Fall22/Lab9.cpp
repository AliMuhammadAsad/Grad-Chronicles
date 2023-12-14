/*Q1 Publication Company - Imagine a Publication Company that markets both books and audio cassette versions of its works.
Create a class Publication that stores title(string) and price(float). Derive two classes book and tape. Book adds a page_count(int) and tape adds a playing time (float)
Each of these three classes should have a function getdata() to get data from the input stream, and putdata() to display the data to the output stream.*/  
#include <iostream>
#include<cstring>
using namespace std;

class Publication{
    private:
    string title; float price;
    public:
    void getdata(){
        getline(cin, title); cin >> price; 
    }
    void putdata(){
        cout << "Publication title: " << title << endl;
        cout << "Publication price: " << price << endl;
    }
};

class book : public Publication {
    private:
    int page_count;
		public:
    void getdata(){
        Publication::getdata(); cin >> page_count;
    }
    void putdata(){
        Publication::putdata();
        cout << "Book page count: " << page_count << endl;
    }
};

class tape : public Publication {
    private:
    float playing_time;
		public:
    void getdata(){
        Publication::getdata(); cin >> playing_time;
    }
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

/* Input:
Harry Potter and the Philosopher's Stone
5000
400
Guardians of the Galaxy
500
60

Output:
Publication title: Harry Potter and the Philosopher's Stone
Publication price: 5000
Book page count: 400
Publication title: Guardians of the Galaxy
Publication price: 500
Tape's playing time: 60

-----------------------------------------------------------------------------------------------------------------------------------------

Q2 - Payment Class
Define a class named Payment that contains: 1)a member variable of type double that stores the amount of the payment and appropriate accessor and mutator methods.
2) a method named paymentDetails() that outputs an English sentence that describes the amount of the payment.
 
Cash Payment Class
Define a class named CashPayment that is derived from Payment.
This class should redefine the paymentDetails() method to indicate that the payment is in cash. Include appropriate constructor(s).
 
Credit Card Payment Class
Define a class named CreditCardPayment that is derived from Payment.
This class should contain member variables for the name on the card, expiration date, and credit card number. Include appropriate constructor(s).
Redefine the paymentDetails() method to include all credit card information in the printout. */
#include <iostream>
#include <cstring>
using namespace std;

class Payment{
    private:
    double amount;
    public:
    void setamount(double pay){
        amount = pay;        
    }
    double getamount(){
        return amount;
    }
    void paymentDetails(){
        cout << amount << endl;
    }
};

class CashPayment : public Payment{
    public:
    CashPayment(double am){
        Payment::setamount(am); 
    }
    void paymentDetails(){
        cout << "Amount of cash payment: $" << Payment::getamount() << endl;
    }
};

class CreditCardPayment : public Payment{
    public:
    string name, exp_date, credit_card_no;
    CreditCardPayment(double am, string naam, string expiration, string card_number){
        Payment::setamount(am); name = naam; exp_date = expiration; credit_card_no = card_number;
    }
    void paymentDetails(){
        cout << "Amount of credit card payment: $" << Payment::getamount() << endl;
        cout << "Name on the credit card: " << name << endl;
        cout << "Expiration date: " << exp_date << endl;
        cout << "Credit card number: " << credit_card_no << endl;
    }
};

int main()
{
	CashPayment cp1(75.25);
	CashPayment cp2(36.95);
	CreditCardPayment ccp1(95.15, "Smith", "12/21/2009", "321654987");
	CreditCardPayment ccp2(45.75, "James", "10/30/2008", "963852741");

	cout << "Details of Cash #1..." << endl;
	cp1.paymentDetails();
	
	cout << "\nDetails of Cash #2..." << endl;
	cp2.paymentDetails();
	
	cout << "\nDetails of Credit Card #1..." << endl;
	ccp1.paymentDetails();
	
	cout << "\nDetails of Credit Card #2..." << endl;
	ccp2.paymentDetails();
		
	return 0;
}

/*Output:
Details of Cash #1...
Amount of cash payment: $75.25
Details of Cash #2...
Amount of cash payment: $36.95
Details of Credit Card #1...
Amount of credit card payment: $95.15
Name on the credit card: Smith
Expiration date: 12/21/2009
Credit card number: 321654987
Details of Credit Card #2...
Amount of credit card payment: $45.75
Name on the credit card: James
Expiration date: 10/30/2008
Credit card number: 963852741
Expected Output

Download
Details of Cash #1...
Amount of cash payment: $75.25
Details of Cash #2...
Amount of cash payment: $36.95
Details of Credit Card #1...
Amount of credit card payment: $95.15
Name on the credit card: Smith
Expiration date: 12/21/2009
Credit card number: 321654987
Details of Credit Card #2...
Amount of credit card payment: $45.75
Name on the credit card: James
Expiration date: 10/30/2008
Credit card number: 963852741 

--------------------------------------------------------------------------------------------------------------------------------

Q3 - Lyari TollBooth
TollBooth: 

Imagine a tollbooth at a bridge. Cars passing by the booth are expected to pay a 50 Rupees toll. Mostly they do, but sometimes a car goes by without paying. The tollbooth keeps track of the number of cars that have gone by, and of the total amount of money collected. 
This class is already modell. The two data items are a type unsigned int to hold the total number of cars, and to hold the total amount of money collected. A constructor initializes both of these to 0. A member function called payingCar() increments the car total and adds 50 to the cash total. Another function, called nopayCar(),increments the car total but adds nothing to the cash total.

LyariTollBooth:
At Lyari TollBooth, many cars go without paying the toll. So, management decided to impose Rs. 500 fine to such cars, and keep track of the fine as well. You already have implemented TollBooth class, and it all works well, and you don't want to change this class. Rather, you'll be implementing a new class LyariTollBooth that adds functionality to the fine, while it uses the functionality already developed in TollBooth class.
Finally, a member function called display() displays the two totals. Make appropriate member functions const. */

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class TollBooth{
    private:
    unsigned int totalcars, totalmoney;
    public:
    TollBooth(){
        totalcars = totalmoney = 0;
    }
    void payingCar(){
        totalcars++; totalmoney = totalmoney + 50;
    }
    void nopayCar(){
        totalcars++; totalmoney = totalmoney + 0;
    }
    void display(){
        cout << "Total cars passed: " << totalcars << endl;
        cout << "Total toll collected: Rs. " << totalmoney << endl;
    }
};

class LyariTollBooth : public TollBooth{
    private:
    unsigned int fine;
    public:
    LyariTollBooth(){
        fine = 0;
    }
    void addfine(){
        fine+= 500;
    }
    void display(){
        TollBooth::display();
        cout << "Total fine collected: Rs. " << fine << endl;
    }
};


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    LyariTollBooth Habib_ka_Toll;
    char car; cin >> car;
    while(car != 'q'){
        if(car == 'p'){
            Habib_ka_Toll.payingCar();
        }
        else if(car == 'n'){
            Habib_ka_Toll.nopayCar(); Habib_ka_Toll.addfine();
        }
        cin >> car;
    }
    Habib_ka_Toll.display();
    return 0;
}
