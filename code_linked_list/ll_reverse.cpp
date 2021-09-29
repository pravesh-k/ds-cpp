// A C++ program to swap nodes in a LL

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

void printList(Node* n){
    while(n != NULL){
        cout<<n->data<<"  ";
        n = n->next;
    }
    cout<<"\n";
}

// Function to add node at beginning of LL
void push(Node** head_ref, int new_data){

    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
    return;

}

// Function to swap two nodes of LL
void reverse(Node** head_ref){
    
    Node *prev = NULL, *curr = *head_ref, *temp = NULL;
    
    while(curr != NULL){
        
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    
    *head_ref = prev;

}

int main(){
    Node* head = NULL;
    for(int i = 1; i <= 10; i++)
        push(&head, (i*i+24/i-4*i));

    printList(head);
    reverse(&head);
    printList(head);

}