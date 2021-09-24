// A C++ program to check the parenthesis balance in an expression

// #include "stack_implement.cpp"
#include<bits/stdc++.h>
using namespace std;

bool paranthesisBalance(string str){

    stack<char> s; // using the inbuilt stack DS

    //traverse the expressiom
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '(' || str[i] == '{' || str[i] == '['){
            s.push(str[i]);
            // cout<<s.top()<<"\n";
            continue;
        }
        // if till now none of the brackets are opening then 
        // stack will be empty and that means either expression 
        // has empty string or has only closing brackets which makes it obvious that expression is unbalanced
        if(s.empty()) 
            return false;

        if((str[i] == ')' && s.top() == '(') || (str[i] == '}' && s.top() == '{') || (str[i] == ']' && s.top() == '[')){
            // cout<<s.top()<<"\n";
            s.pop();
        }
        else
            break;
    }
    return s.empty();

}

int main(){

    string str = "{([])}";
    if(paranthesisBalance(str) == true)
        cout<<"Balanced\n";
    else
        cout<<"Unbalanced\n";

    return 0;
}