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
// 1-- Create a class Node, which has one variable for storing data and a pointer which points to the next node
class Node{
    public:
    int data; Node* next;
    Node(){
        data = 0; next = NULL;
    }
    Node(int x){
        data = x; next = NULL;
    }
};

// 2 -- Create a class Queue ; which has two public pointers for front and rear nodes
//     and it also has two public functions void Enqueue(int x) and int Dequeue()
//      also add a function print_queue() which prints all the elements in the queue

class Queue{
    private:
    Node* front; Node* rear;
    public:
    
    Queue(){
        front = NULL; rear = NULL;
    }
    
    void Enqueue(int elem){
        Node* nodepointer = new Node;
        
        nodepointer -> data = elem; nodepointer -> next = NULL;
        if(front == NULL){
            front = rear = nodepointer;
        }
        else{
            Node* temp = front;
            while(temp -> next != NULL){
                temp = temp -> next;
            }
            temp -> next = nodepointer;
        }
    }
    
    void Dequeue(){
        Node* temp = front;
        if(temp == NULL){
            ;
        }
        else{
        front = front -> next;
        delete temp;
        }
    }
    
    void print_queue(){
        Node* temp = front;
        while(temp != NULL){
            cout << temp -> data << " ";
            temp = temp -> next;
        }
        cout << endl;
    }
};




int main() {
    
    Queue* queue = new Queue; // 
    
    int n,value; // n is the number of values to be enqueued 
    
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> value; // reading the value
        queue->Enqueue(value);
    }
    
    queue->print_queue(); // prints the queue after enqueuing the data
    
    cin >> n;
    for(int i=0;i<n;i++)
    {
        queue->Dequeue();
    }
    
    queue->print_queue(); // prints the queue after enqueuing the data
    
    return 0;
}


//--------------------------------------------------------------------------------------------------------------------------------
#include<iostream>

using namespace std;
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
        if(hours >= 24){
            hours = hours % 24;
        }
    }
    public:
    Time(){
        hours = 0; minutes = 0; seconds = 0;
    }
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
