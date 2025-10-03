#include<iostream>
#include<cstring>
#include<string>
using namespace std;

template <typename D>
class MyQueue{
    public :
    int size , front, rear;
    D *arr;
    MyStack(int s){
        size = s;
        front =-1;
        arr = new D[size];
        for (int i =0 ; i < size ; i++)
            cin >> arr[i];
    }
    void show(){
        for (int i =0 ; i < size ; i++)
            cout <<  arr[i] << " ";
        cout << endl;
    }
   // Implement Enqueue function.
   void enqueue(D x){
    if (rear == size-1){ 
        cout << "Could not queue element as max size of queue has been reached\n"; 
    }
    else{
        if (front == -1) front = 0;
        rear++;
        arr[rear] = x;
    }
   }
   // Implement Dequeue function.
   void dequeue(){
    if (front == rear){
        front = rear = -1;
    }
    else front++;
   }
   // Implement front function.
   D front(){
    return arr[front];
   }
   // Implement is_empty function.
   bool is_empty(){
    if (front == -1 && rear == -1){
        return true;
    }
    else return false;
   }

};
int main()
{
    
    MyStack<int> st(3);
    st.enqueue(234);
    st.enqueue(454);
    st.enqueue(765);

    MyStack<char> stChar(4);
    stChar.enqueue('A');
    stChar.enqueue('%');
    stChar.enqueue('&');
    stChar.enqueue('W');
    MyStack<string> stString(2);
    stString.enqueue('Today is');
    stString.enqueue('Friday');

    st.show(); // output : 234 454 75
    stChar.show(); // output : A % & W
    stString.show(); // output : Today is Friday


    st.dequeue();
    st.show(); //output : 454 75

    stChar.dequeue();
    stChar.dequeue();
    stChar.show(); //output : & W

    stString.dequeue();
    stString.dequeue();
    stString.show(); // output : Queue is empty



system("pause");
}