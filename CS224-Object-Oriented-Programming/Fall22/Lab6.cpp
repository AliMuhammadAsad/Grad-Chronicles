/* Complex Calculator. Uses a class called Complex to initialize, and perform operations on Complex Numbers */

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
            if(imag < 0)
                cout << real << imag << "i" << endl;
            else
                cout << real << "+" << imag << "i" << endl; 
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

//------------------------------------------------------------------------------------------------------------------------------------

/* Time 24 Hours - uses a class Time24 that has attributes hours, minutes, seconds, pm/am and adjusts the time accordingly. Also adds two times. */

#include<iostream>

using namespace std;

class Time24{
    private:
        int hours, minutes, seconds; char period;
        void adjust(){
            int m_over = 0, h_over = 0;
            while(seconds >= 60){
                seconds = seconds - 60; m_over++;
            }
            minutes = minutes + m_over;
            while(minutes >= 60){
                minutes = minutes - 60; h_over++;
            }
            hours = hours + h_over;
            while(hours >= 24){
                hours = hours - 24;
            }
        }
    public:
        Time24(int h, int m, int s){
            hours = h; minutes = m; seconds = s;
            adjust();
        }
        Time24(int h, int m, int s, char p){
            hours = h; minutes = m; seconds = s; period = p;
            if(p == 'p')
                hours = hours + 12;
            adjust();
        }
        void add(Time24 t){
            hours = hours + t.hours; minutes = minutes + t.minutes; seconds = seconds + t.seconds;
            adjust();
        }
        
        const void show(){
            if(hours < 10)
                cout << "0" << hours << ":";
            else if (hours >= 10)
                cout << hours << ":";
            if(minutes < 10)
                cout << "0" << minutes << ":";
            else if(minutes >= 10)
                cout << minutes << ":";
            if(seconds < 10)
                cout << "0" << seconds << endl;
            else if(seconds >= 10)
                cout << seconds << endl;
        }
};

int main(){
    int hours1, minutes1, seconds1;
    cin>>hours1>>minutes1>>seconds1;
    Time24 t1(hours1, minutes1, seconds1);


    int hours2, minutes2, seconds2;
    char period;
    cin>>hours2>>minutes2>>seconds2>>period;
    Time24 t2 = {hours2, minutes2, seconds2, period};

    cout<<"t1: "; t1.show();
    cout<<"t2: "; t2.show();

    t1.add(t2);// result of addition is stored in t1
    cout<<"t1+t2: "; t1.show();
}

//------------------------------------------------------------------------------------------------------------------------------------

/* TollBooth - class TollBooth that keeps track of cars that have passed and toll collected from those cars. Includes paying and no paying cars
               but displays only total cars and total toll collected. */

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
    public:
        int totalcars, totalmoney;
    TollBooth(){
        totalcars = 0; totalmoney = 0;
    }    
    
    void payingcar(){
        totalcars++; totalmoney = totalmoney + 50;
    }
    
    void nopaycar(){
        totalcars++; totalmoney = totalmoney + 0;
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
        if(car == 'p')
            habibtoll.payingcar();
        else
            habibtoll.nopaycar();
        cin >> car;
    }
    habibtoll.display();
    
    return 0;
}

//------------------------------------------------------------------------------------------------------------------------------------

/* Students Database - class Student that contains information about students such as ID, first name, last name and exam score.
                       Function MinStudent takes an array of Type Students and returns the students with least marks.
                       Function MaxStudent takes an array of Type Students and returns the students with most marks.
                       Input taken, first line contains n number of students. Then first line contains Id, followed by first name, last name and then exam score in
                       seperate lines uptill n number of data for each student has been collected.
                       The Student Objects are saved in a dynamic array of type Students. class Student also has a method to show a student object's information. */

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

//1. Define the Student class here
class Student{
    // private:
    public: 
        long int std_id; float std_e_score;
        char std_f_name[100], std_l_name[100];
    // public:
        Student(){} //Default initialisation
        void show(){ //Method Show().
            cout << std_id << endl;
            cout << std_f_name << endl;
            cout << std_l_name << endl;
            cout << std_e_score << endl;
        }
};

//2. Define the MinMax function here
Student* MinStudent(Student* std, int n){
    float low = 101; int index = 0;
    for(int i = 0; i < n; i++){
        if(std[i].std_e_score < low){
            low = std[i].std_e_score; index = i;
        }
    }
    return std + index;
}

Student* Maxstudent(Student* std, int n){
    float high = 0; int index = 0;
    for(int i = 0; i < n; i++){
        if(std[i].std_e_score > high){
            high = std[i].std_e_score; index = i;
        }
    }
    return std + index; 
}

//3. Do the necessary steps in the main function
int main() {
    //1. create Student array of size n dynamically
    int n; cin >> n;
    Student* std_arr = new Student[n];
    //2. Read the Student information into the Student array
    long int id; char f_name[100], l_name[100]; float marks;
    for(int i = 0; i < n; i++){
        cin >> std_arr[i].std_id; cin.ignore(); //student id
        cin.getline(std_arr[i].std_f_name, 100); //first name
        cin.getline(std_arr[i].std_l_name, 100); //last name
        cin >> std_arr[i].std_e_score; cin.ignore(); //marks
    }
    
    //3. Pass the student array to the MinStudent function and store returned value in pointer of type Student
    Student* min_cry_cry_like_me_rn = MinStudent(std_arr, n);
    
    //4. Pass the student array to the MaxStudent function and store returned value in pointer of type Student
    Student* max_cry_cry_like_me_rn = Maxstudent(std_arr, n);

    cout<<"Student with Minimum score:"<<endl;
    //5. Call Student's show() function to print the student information of the object returned by MinStudent function.
    min_cry_cry_like_me_rn->show(); cout << endl;
    
    cout<<"Student with Maximum score:"<<endl;
    //6. Call Student's show() function to print the student information of the object returned by MaxStudent function.
    max_cry_cry_like_me_rn->show();
    
    //7. Delete the array
    delete [] std_arr;
    
    return 0;
}
