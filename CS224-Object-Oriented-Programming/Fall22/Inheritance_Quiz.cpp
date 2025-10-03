/* This program contains the following classes:

**Handle** - has two attributes: size (of type int) and num_handles (of type int). 
It has the following functions: 
Getters
set_values that sets the two attributes of the class

**Crockery** - has three attributes: material (of type string), microwaveable (of type bool) and size (of type int), 
with the following functions: 
A pure virtual function called SolidsLiquids that returns a char. {'S' if the type of crockery is Plate, and 'L' if the type of crockery is Kettle}
A virtual function called set_plate that takes five arguments: string shape, bool printed, string material, bool microwaveable, int size; returns nothing
A virtual function called set_kettle that takes six arguments: int lid_size, int handle_size, int num_handle, string material, bool microwaveable, int size; returns
nothing
A virtual function called display that takes no arguments and returns nothing. It should print the attributes of Crockery class with the appropriate labels
as explained in the Sample Output
set_values that takes three arguments to set the attributes of this class

**Plate** - derived from Crockery with two attributes of its own: shape (string) and printed (bool), 
with the following functions: 
set_plate function as defined in the Crockery class. It should first call the set_values function of the parent class with the respective arguments, 
and then sets its own attributes
display function that calls the parent class display function, and prints the attributes of itself with appropriate labels as explained in the Sample Output

**Kettle** - derived from Crockery with two additional attributes: lid_size (of type int) and kettle_handle (of type Handle),
with the following functions:
set_kettle function as defined in the Crockery class. It should first call the set_values function of the parent class with the respective arguments, 
and then sets its own attributes
display function that calls the parent class display function, and prints the attributes of itself with appropriate labels as explained in the Sample Output

Write a driver program that prompts the user to enter a character ('p' or 'P' for Plate, and 'k' or 'K' for Kettle), and based on the input the
program should dynamically allocate Crockery to either Plate or Kettle. Then based on user's input, it should set the values of the respective attributes
and display them, as specified in Sample Ouput. The main function should call the SolidsLiquids function and based on the returned value it should print the last
line of the output. 
Constraints: 0 is false, and 1 is true 

Input Format For Custom Testing: 
The first line contains a character to choose either Plate or Kettle
The following lines will contain the input to the respective attributes of the class chosen

Sample Case 0:
Sample Input For Custom Testing
p
Plastic
0
3
Round
1

Sample Output
Made of: Plastic
Not microwaveable
Size is: 3 inches
Shape: Round
Plate has a design printed on it
Used to hold solid items!

Explanation: 
Prints the information about Plate as the chosen character is 'p'

Sample Case 1:
Sample Input For Custom Testing
k
Ceramic
1
5
1
2
1

Sample Output:
Made of: Ceramic
Microwaveable
Size is: 5 inches
Lid size: 1 inches
Handle size: 2 inches
Number of handles: 1
Used to hold liquids!
Explanation

Prints the information about Plate as the chosen character is 'k' */

#include <iostream>
#include <cstring>

using namespace std;


class Handle{
    protected:
    int size, num_handles;
    public:
    void getdata(){
        cout << "Handle size: " << size << " inches" << endl;
        cout << "Number of handles: " << num_handles << endl;
    }
    
    void set_values(int s, int no_handles){
        size = s; num_handles = no_handles;
    }    
};

class Crockery{
    protected:
    string material; bool microwaveable; int size;
    public:
    virtual char SolidsLiquids() = 0;
    virtual void set_plate(string shapee, bool print, string mat, bool microwave, int s){}
    virtual void set_kettle(int size_lid, int size_handle, int n_handle, string mat, bool microwave, int s){}
    void display(){
        cout << "Made of: " << material << endl;
        if(microwaveable == true) cout << "Microwaveable" << endl;
        else cout << "Not microwaveable" << endl;
        cout << "Size is: " << size << " inches" << endl;
    }
    void set_values(string mat, bool microwave, int s){
        material = mat; microwaveable = microwave; size = s;
    }
};

class Plate : public Crockery {
    protected:
    string shape; bool printed;
    public:
    void set_plate(string shapee, bool print, string mat, bool microwave, int s){
        Crockery::set_values(mat, microwave, s);
        shape = shapee; printed = print;
    }
    
    void display(){
        Crockery::display();
        cout << "Shape: " << shape << endl;
        if(printed == true) cout << "Plate has a design printed on it" << endl;
        else cout << "Plate does not have a design printed on it" << endl;
    }
    char SolidsLiquids(){
        return 'S';
    }
};

class Kettle : public Crockery{
    protected:
    int lid_size; Handle kettle_handle;
    public:
    void set_kettle(int size_lid, int size_handle, int n_handle, string mat, bool microwave, int s){
        Crockery::set_values(mat, microwave, s);
        lid_size = size_lid; kettle_handle.set_values(size_handle, n_handle);
    }
    void display(){
        Crockery::display();
        cout << "Lid size: " << lid_size << " inches" << endl;
        kettle_handle.getdata();
    }
    char SolidsLiquids(){
        return 'L';
    }
};


int main(){
    char prompt;
    cin >> prompt;
    string mat; bool microwave; int s; 
    if(prompt == 'p' || prompt == 'P'){
        Crockery* plate = new Plate();
        string shapee; bool print;
        cin >> mat >> microwave >> s >> shapee >> print; 
        plate->set_plate(shapee, print, mat, microwave, s);
        plate->display();
        if(plate->SolidsLiquids() == 'S') cout << "Used to hold solid items!\n";
    }
    else if (prompt == 'k' || prompt == 'K'){
        Crockery* kettle = new Kettle();
        int size_lid, size_handle, n_handle;
        cin >> mat >> microwave >> s >> size_lid >> size_handle >> n_handle;
        kettle->set_kettle(size_lid, size_handle, n_handle, mat, microwave, s);
        kettle->display();
        if(kettle->SolidsLiquids() == 'L') cout << "Used to hold liquids!\n";
    }   
    return 0;
}
