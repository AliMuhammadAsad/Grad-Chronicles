#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data; Node* next;
    
    Node(){ data = 0; next = NULL;}
    Node(int val){ data = val; next = NULL; }
};

class Queue{
    public:
    Node* front; Node* rear;
    
    Queue(){ front = NULL; rear = NULL; }
    
    void Enqueue(int val){
        Node* nodeptr = new Node;
        nodeptr->data = val; nodeptr->next = NULL;
        if(front == NULL) front = rear = nodeptr;
        else{
            Node* temp = front;
            while(temp->next != NULL) temp = temp->next;
            temp->next = nodeptr;
        }
    }

    void Dequeue(){
        Node* temp = front;
        if(front == NULL) ;
        else{
            front = front->next;
            delete temp;
        }
    }

    void print_queue(){
        Node* temp = front;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// ---------------------------------------------------------------------------------- //
// Using getters and setters

class Node{
    private:
    int data; Node* next;
    
    public:
    Node(){ data = 0; next = NULL;}
    Node(int val){ data = val; next = NULL; }

    void setData(int val){ data = val; }
    int getData(){ return data; }
    void setPtr(Node* ptr){ next = ptr; }
    Node* getPtr(){ return next; }
};

class Queue{
    public:
    Node* front; Node* rear;
    
    Queue(){ front = NULL; rear = NULL; }
    
    void Enqueue(int val){
        Node* nodeptr = new Node;
        nodeptr->setData(val); nodeptr->setPtr(NULL);
        if(front == NULL) front = rear = nodeptr;
        else{
            Node* temp = front;
            while(temp->getPtr() != NULL) temp = temp->getPtr();
            temp->setPtr(nodeptr);
        }
    }

    void Dequeue(){
        Node* temp = front;
        if(front == NULL) ;
        else{
            front = front->getPtr();
            delete temp;
        }
    }

    void print_queue(){
        Node* temp = front;
        while(temp != NULL){
            cout << temp->getData() << " ";
            temp = temp->getPtr();
        }
        cout << endl;
    }
};

int main(){
    Queue q;
    q.Enqueue(1); q.Enqueue(2); q.Enqueue(3); q.Enqueue(4); q.Enqueue(5);
    q.print_queue();
    q.Dequeue(); q.Dequeue();
    q.print_queue();
    return 0;
}