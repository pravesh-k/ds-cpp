// A C++ program to implement queues

#include<bits/stdc++.h>
using namespace std;

#define MAX 1000

class Queue{
    int front, rear;

    public:
    int arr[MAX];
    Queue(){
        front = -1;
        rear = -1;
    }
    
    // Function to check if queue is full (overflow)
    bool isFull(){
        if(front == 0 && rear == MAX -1)
            return true;
        else
            return false;
    }

    // Function to check if queue is empty (underflow)
    bool isEmpty(){
        if(front == -1)
            return true;
        else
            return false;
    }

    // Function to enqueue, insert data at rear
    void enqueue(int x){
        if(isFull()){
            cout<<"Overflow"<<endl;
            return;
        }
        else{
            if(front == -1)
                front = 0;
            arr[++rear] = x;
        }
    }

    // Function to dequeue, pop data from front
    int dequeue(){
        if(isEmpty()){
            cout<<"Underflow"<<endl;
            return (-1);
        }
        else{
            int x = arr[front];
            if(front >= rear)
                front = rear = -1;
            else
                front++;        
            return x;
        }
    }

    // Function to return the value at the front
    int peekFront(){
        if(!isEmpty())
            return arr[front];
        else
            return (-1);
    }

    // Function to print the Queue
    void printQueue(){
        for(int i = front; i <= rear; i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
};

int main(){

    Queue q;

    q.enqueue(5);
    q.enqueue(8);
    q.enqueue(2);
    q.enqueue(10);
    q.enqueue(15);

    q.printQueue();

    q.dequeue();
    q.dequeue();

    q.printQueue();

    cout<<q.peekFront()<<endl;

    return 0;
}