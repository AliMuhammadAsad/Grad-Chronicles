/*Q1 - Hotel Rooms:
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

#include<iostream>
#include<vectors>
#include<cstring>
using namespace std;

class HotelRoom{
    public:
    int bathroom_num, bedroom_num;
    HotelRoom(){
        bathroom_num = 0; bedroom_num = 0;
    }
    HotelRoom(int bathrooms, int bedrooms){
        bathroom_num = bathrooms; bedroom_num = bedrooms;
    }
    virtual int get_price(){
        int price = 100*bathroom_num + 50*bedroom_num;
        return price;
    }
};

class Apartment : public HotelRoom{
    public:
    Apartment(int bathrooms, int bedrooms) : HotelRoom(bathrooms, bedrooms) {};
    int get_price(){
        int price = HotelRoom::get_price() + 100;
        return price;
    }
};

int main(){
    int n; cin >> n;
    vector<HotelRoom*> Room;
    for(int i = 0; i < n; i++){
        string type; int bedrooms; int bathrooms;
        cin >> type >> bedrooms >> bathrooms;
        if(type == "standard") Room.push_back(new HotelRoom(bathrooms, bedrooms));
        else if (type == "apartment") Room.push_back(new Apartment(bathrooms, bedrooms));
    }
    int total_price = 0;
    for(int i = 0; i < n; i++){
        total_price += Room[i]->get_price();
    }
    cout << total_price;
}


/* -------------------------------------------------------------------------------------------------------------------------------------------------------------
Q2 Create three classes Person, Professor and Student. 
The class Person should have data members name and age.
The classes Professor and Student should inherit from the class Person.

The class Professor should have two integer members: publications and cur_id. There will be two member functions: getdata and putdata. 
The function getdata should get the input from the user: the name, age and publications of the professor. 
The function putdata should print the name, age, publications and the cur_id of the professor.

The class Student should have two data members: marks, which is an array of size 6  and cur_id. 
It has two member functions: getdata and putdata. 
The function getdata should get the input from the user: the name, age, and the marks of the student in 6 subjects. 
The function putdata should print the name, age, sum of the marks and the cur_id of the student.

For each object being created of the Professor or the Student class, sequential id's should be assigned to them starting from 1.
Solve this problem using virtual functions, constructors and static variables. You can create more data members if you want.
Write a main() using the guidline given in the comments.
Sample Input:
4
1
Walter 56 99
2
Jesse 18 50 48 97 76 34 98
2
Pinkman 22 10 12 0 18 45 50
1
White 58 87
Explanation of Input Formate:
The first line of input contains the number of objects that are being created. 
If the first line of input for each object is 1, it means that the object being created is of the Professor class, you will have to input the name, 
age and publications of the professor.

If the first line of input for each object is 2, it means that the object is of the Student class, you will have to input the name, age and the marks of the student in  subjects.
Sample Output:
Walter 56 99 1
Jesse 18 403 1
Pinkman 22 135 2
White 58 87 2
Output Formate Explanation:
There are two types of output depending on the object.
If the object is of type Professor, print the space separated name, age, publications and id on a new line.
*/

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

class Person{
    public:
    string name; int age;
    virtual void getdata(){
        cin >> name >> age;
    }
    virtual void putdata(){
        cout << name << " " << age;
    }
};

class Professor : public Person{
    public:
    int publications, cur_id; static int p_id;
    Professor(){
        cur_id += p_id++;
    }
    void getdata(){
        Person::getdata(); cin >> publications;
    }
    void putdata(){
        Person::putdata(); cout << " " << publications << " " << cur_id << endl;
    }
};

int Professor::p_id = 1;

class Student : public Person{
    public:
    int marks[6], cur_id; static int s_id;
    Student(){
        cur_id += s_id++;
    }
    public:
    void getdata(){
        Person::getdata();
        for(int i = 0; i < 6; i++) cin >> marks[i];
    } 
    void putdata(){
        Person::putdata();
        int total_marks = 0;
        for(int i = 0; i < 6; i++) total_marks += marks[i];
        cout << " " << total_marks << " " << cur_id << endl;
    }
};

int Student::s_id = 1;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, check; cin >> n;
    Person* people[n];
    for(int i = 0; i < n; i++){
        cin >> check;
        if(check == 1) people[i] = new Professor; 
        else people[i] = new Student;
        people[i]->getdata();
    }
    for(int i = 0; i < n; i++){
        people[i]->putdata();
    }
    return 0;
}
