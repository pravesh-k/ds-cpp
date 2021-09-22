// A Module/C++ program to implement stack DS in arrays and perform
//  different operations such as push, pop, peek, etc

#include<bits/stdc++.h>
using namespace std;

#define MAX 1000

class Stack{
    int top;

    public:
    char a[MAX];

    Stack(){
        top = -1;
    }
    void push(int x);
    char pop();
    char peek();
    bool isEmpty();
};

void Stack::push(int x){

    if(top >= (MAX-1)){
        cout<<"Stack Overflow\n";
        return;
    }

    else{
        a[++top] = x;
        // cout<<"pushed "<<x<<"\n";
        return;
    }
}

char Stack::pop(){
    
    if(top<0){
        cout<<"Stack Underflow\n";
        return 0;
    }
    else{
        int x = a[top--];
        return x;
    }
}

char Stack::peek(){

    if(top<0){
        cout<<"Stack Underflow\n";
        return 0;
    }
    else{
        int x = a[top];
        return x;
    }
}

bool Stack::isEmpty(){

    return top<0;
}

void printStack(Stack s){
    
    cout<<"Stack elements are:\n";
    while(!s.isEmpty()){
        cout<<s.pop()<<"  ";
    }
    cout<<"\n";
}

/* int main(){  //commenting out to remove conflicts in other cpp 
                //programs where this code is used as module to call methods

    Stack s;
    s.push("a");
    s.push("f");
    s.push("d");
    printStack(s);
    cout<<s.pop()<<" popped from stack\n";
    printStack(s);

    return 0;
} */