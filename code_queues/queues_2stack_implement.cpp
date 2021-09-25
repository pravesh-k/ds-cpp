// A C++ program to implement a queue using 2 stacks

#include<bits/stdc++.h>
using namespace std;

class Queue1{ // implementation by making enQueue operation costly

    public:
    stack<int> s1, s2;

    void enQueue(int x){
    
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }

    void deQueue(){
    
        if(s1.empty()){
            cout<<"Underflow"<<endl;
            return;
        }
        else
            s1.pop();
    }

    void printQueue(){
        stack<int> s = s1;
        while(!s.empty()){
            cout<<s.top()<<"  ";
            s.pop();
        }
        cout<<endl;
    }

};

class Queue2{ // implementation by making deQueue operation costly

    public:
    stack<int> s1, s2;

    void enQueue(int x){
    
        s1.push(x);
    }

    void deQueue(){

        if(s1.empty() && s2.empty()){
            cout<<"Underflow"<<endl;
            return;
        }
        else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            s2.pop();
        }
    }

    void printQueue(){
        stack<int> s = s2;
        while(!s.empty()){
            cout<<s.top()<<"  ";
            s.pop();
        }
        cout<<endl;
    }

};

int main(){

    Queue2 q;

    q.enQueue(5);
    q.enQueue(10);
    q.enQueue(15);
    q.enQueue(25);
    q.enQueue(55);
    q.deQueue();
    q.deQueue();
    q.printQueue();
}
