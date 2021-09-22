// A C++ program to reverse string using stack.

#include "stack_implement.cpp" // importing module to use class Stack and the functions associated with it
#include<bits/stdc++.h>
using namespace std;

string reverse(string str){

    Stack s;
    
    for(int i = 0; i < str.length(); i++)
        s.push(str[i]);
    
    for(int i = 0; i < str.length(); i++)
        str[i] = s.pop();

    return str;
}

int main(){

    string str = "Hello World";
    cout<<str<<"\n";
    str = reverse(str);
    cout<<str<<"\n";

    return 0;
}