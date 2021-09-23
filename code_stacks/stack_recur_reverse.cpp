// A C++ program to reverse a stack using recursion

#include<bits/stdc++.h>
using namespace std;

// function to insert the call stack values to the bottom of the stack
void insertAtBottom(stack<int> &s, int x){
    
    if(s.empty()){
        s.push(x);
        return;
    }
    else{
        int y = s.top(); s.pop();
        insertAtBottom(s, x);
        s.push(y);
    }
}

// function to reverse the stack
void recur_reverse(stack<int> &s){

    if(s.empty()){
        return;
    }
    
    else{
        int x = s.top(); s.pop();
        recur_reverse(s);
        insertAtBottom(s, x);
    }
}

// Function to print the stack
stack<int> printStack(stack<int> s){

    if(s.empty()){
        cout<<endl;
        return s;
    }
    
    else{
        cout<<s.top()<<endl;
        s.pop();
        return printStack(s);
    }
}

int main(){

    stack<int> s, r;
    s.push(2);
    s.push(4);
    s.push(6);
    s.push(8);
    s.push(10);

    printStack(s);
    recur_reverse(s);
    printStack(s);
    
    return 0;
}