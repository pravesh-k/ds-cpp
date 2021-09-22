// A C++ program to find the next greater element for each element in an array

#include<bits/stdc++.h>
using namespace std;

void printNGE(int arr[], int n){

    stack<int> s;
    s.push(arr[0]);
    
    for(int i = 0; i < n; i++){
        if(s.empty()){
            s.push(arr[i]);
            continue;
        }
        while(!s.empty() && s.top() < arr[i]){
            cout<<s.top()<<" -> "<<arr[i]<<endl;
            s.pop();
        }
        s.push(arr[i]);
    }
    while(!s.empty()){
        cout<<s.top()<<" -> "<<-1<<endl;
        s.pop();
    }
}

int main(){

    int arr[] = {13, 5, 9, 2, 3, 15, 19, 7};
    printNGE(arr, sizeof(arr)/sizeof(arr[0]));
}