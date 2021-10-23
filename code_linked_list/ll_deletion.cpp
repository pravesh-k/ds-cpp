// A C++ program to delete a node in a LL

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

void printList(Node* n){

    while(n != NULL){
        cout<<n->data<<" ";
        n = n->next;
    }
    cout<<"\n";

}

// Function to delete a node when prev_node is provided
void deleteNode(Node** head_ref, int data){

    Node* temp = *head_ref;     // variables to store the current node and 
    Node* prev = NULL;          // the node previous to the current node

    if(temp == NULL)
        return;

    while(temp != NULL){
        if(temp->data == data){
            if(temp == *head_ref)
                *head_ref = temp->next;
            else
                prev->next = temp->next;

            delete temp;
            return;
        }
        else{

            prev = temp;
            temp = temp->next;
        }
    }
    return;
    
}

// Function to delete a node using recursion when prev_node is provided
void deleteNodeRecur(Node** head_ref, int data){

    Node* temp = *head_ref;
    
    if(temp == NULL)
        return;
        
    if(temp->data == data){

        *head_ref = temp->next;

        delete temp;
        return;
    }
    deleteNodeRecur(&temp->next, data);
}

// Function to delete a node at a given position
void deleteNodePos(Node** head_ref, int pos){

    Node* temp = *head_ref;
    Node* prev = NULL;

    if(temp == NULL)
        return;

    if(pos == 1){

        *head_ref = temp->next;
        delete temp;
        return;
    }

    while(pos != 1){
        
        prev = temp;
        temp = temp->next;    
        pos--;
        if(temp == NULL){
            cout<<"Pos Error\n";
            return;
        }
    }
    prev->next = temp->next;
    delete temp;
    return;

}

// Function to add node at beginning of LL
void push(Node** head_ref, int new_data){

    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
    return;

}

int main(){

    Node* head = NULL;
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    push(&head, 40);
    // printList(head);
    // deleteNode(&head, 30);
    printList(head);
    // deleteNodeRecur(&head, 20);
    deleteNodePos(&head, 5);
    printList(head);
}