// A C++ program to insert a mew node at (1) Beginning (2) After a node (3) End
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

// (1)To insert a new node at the beginning of the LL
void push(Node** head_ref, int new_data){

    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;

}

// (2)To insert a node after a given prev_node in a LL
void insertAfter(Node* prev_node, int new_data){

    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;

}

// (3)To insert a node at the end of a LL
void append(Node** head_ref, int new_data){

    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = NULL;

    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }

    Node* temp = *head_ref;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = new_node;
    return;
}

void printList(Node* n){

    while(n != NULL){
        cout<<n->data<<" ";
        n = n->next;
    }
    cout<<"\n";
}

int main(){
    
    Node* head = NULL;
    
    // append(&head,77);

    push(&head, 54);
    push(&head, 67);
    push(&head, 15);

    // insertAfter(head, 37);  
    // insertAfter(head->next->next, 45);

    // append(&head,8);

    // push(&head, 11);

    printList(head);
    
    return 0;
}