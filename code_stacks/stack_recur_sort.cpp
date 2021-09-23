// A C++ program to sort a stack using recursion only

#include<bits/stdc++.h>
using namespace std;

void sortedInsert(stack<int> &s, int x){
    
    if(s.empty() || (x > s.top())){
        s.push(x);
        return;
    }
    else{
        int y = s.top(); s.pop();
        sortedInsert(s, x);
        s.push(y);
    }
}
void recur_sort(stack<int> &s){

    if(s.empty()){
        return;
    }
    else{
        int x = s.top(); s.pop(); 
        recur_sort(s); // This operation stores all the elements in funtion call stack
        sortedInsert(s, x);
    }
}

void printStack(stack<int> stack)
{
    while (!stack.empty())
    {
        cout << stack.top() <<endl;
        stack.pop();
    }
    cout << endl;
}

int main(){

    stack<int> s;
    s.push(7);
    s.push(2);
    s.push(5);
    s.push(11);
    s.push(9);

    printStack(s);
    recur_sort(s);
    printStack(s);
}