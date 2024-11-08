/* Q1 - Truck Polymorphism :In this question you have to define two classes:
1. Vehicle class have attributes regNo (string type), and no. of wheel(int type). 
It has a 2 arguments constructor to initialize the attributes and a function to print the values.

2. Truck class, which is child to Vehicle. It adds maxWeight attribute (int type). 
It has a 3 arguments constructor to initialize the attributes. 
The constructor delegates to Vehicle's constructor to initialize registration number and no. of wheels. 
Truck class also have a show function to print the attributes, where it calls the Vehicle's class show function to print the reg number and no. of wheels. 

main function is already provided, where you can see polymorphism is exhibited, hence you need to create the show function as virtual function.
Input:
3
XY231 4 4000
MN892 6 80000
HT432 8 500

Output:
This is a Truck, Max Weight: 4000 Reg. No.:XY231, No. of wheels: 4
This is a Truck, Max Weight: 80000 Reg. No.:MN892, No. of wheels: 6
This is a Truck, Max Weight: 500 Reg. No.:HT432, No. of wheels: 8
*/
#include<iostream>
#include<cstring>
using namespace std;

class Vehicle{
    protected:
    string regNo; int wheel_nums;
    public:
    Vehicle(string reg_num, int wheels){
        regNo = reg_num; wheel_nums = wheels;
    }
    virtual void show() = 0;
};

class Truck : public Vehicle{
    private:
    int maxWeight;
    public:
    Truck(string reg_num, int wheels, int weight) : Vehicle(reg_num, wheels){
        maxWeight = weight;
    }
    void show(){
        cout << "This is a Truck, Max Weight: " << maxWeight << " Reg. No.:" << regNo << ", No. of wheels: " << wheel_nums << endl;
    }
};

int main(){
    int n, weight, wheels;
    string reg;
    Vehicle *ptr;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>reg>>wheels>>weight;
        ptr = new Truck(reg, wheels, weight);
        //notic the following call is polymorphic, hence show function must be virtual in Vehicle class.
        ptr->show(); 
        delete ptr;
    }    
}

/* -------------------------------------------------------------------------------------------------------------------------
Q2 Animals Updated: We will implement a hierarchy of Animals who each have a name and a distinctive sound.
Write a class Animal that stores a name and a sound, each of type std::string, and the value of each passed through the constructor. 
Derive the classes, Cat, Cow, Dog, Duck, Horse, and Pig from Animal. Each of these has a  default sound as follows.
Cat	Meow
Cow	Moo
Dog	Woof
Duck	Quack
Horse	Neigh
Pig	Oink

If no sound is passed through the constructor, then the default sound is stored. 
Each animal also performs a sound producing action, e.g. bark for dog.
The default actions are as follows.
Cat	purr
Cow	moo
Dog	bark
Duck	quack
Horse	nicker
Pig	snort

Add a method make_sound() to the Animal class that outputs the name and sound for an animal, 
e.g. for a dog named "Spot" with the default sound, the output would be
Spot barks: Woof!

You will take as input the number of animals in the barn and then inputs the type and name of each animal - cat, cow, dog, duck, horse, or pig. 
Once all animals have been input, the program calls animal's make_sound() function.
Notice in outputting the sounds of the animals how the same code leads to different behavior. This is referred to as polymorphism.
Hint: You will need a dynamic array in which each element is of type Animal*.
*/

