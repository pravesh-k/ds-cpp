// A C++ program to implement a priority queue DS using heap

#include<bits/stdc++.h>
using namespace std;

void printQueue(priority_queue<int> q){
    while(!q.empty()){
        cout<<q.top()<<"  ";
        q.pop();
    }
    cout<<endl;
}

int main(){

    priority_queue<int> q; // using inbuilt class priority_queue for max heap pritority queue

    // priority_queue<int, vector<int>, greater<int>> q // using this syntax for min heap priority queue

    q.push(5);
    q.push(12);
    q.push(1);
    q.push(3);
    printQueue(q);

    return 0;
}