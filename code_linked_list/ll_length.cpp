// A C++ program to find the length of LL using different methods

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

void push(Node** head_ref, int new_data){

    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
    return;
}

// Function (Iterative) to find the length of LL
int findLength(Node* head){
    int count = 0;
    while(head != NULL){
        count++;
        head = head->next;
    }
    return count;
}

// Function (Recursive) to find the length of LL
int findLengthRecur(Node* head){
    if(head == NULL)
        return 0;
    
    else
        return 1 + findLength(head->next);
}

int main(){

    Node* head = NULL;
    for(int i = 0; i < 14; i++)
        push(&head, 10*i);

    cout<<findLength(head)<<"\n";
    cout<<findLengthRecur(head);
}