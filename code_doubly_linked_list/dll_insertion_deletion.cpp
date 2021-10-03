// A C++ program to implement Doubly Linked Lists (DLL) and 
// perform insertion at (1) beginning, (2) end and (3) in between of the DLL
// and also perform delete operation

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int new_data){ // A parameterized constructor for Node class
        data = new_data;
        prev = NULL;
        next = NULL;
    }
};

// Function to print the node data of the DLL
void printList(Node* list){

    if(list == NULL)
        return;
    
    while(list != NULL){
        cout<<list->data<<"  ";
        list = list->next;
    }
    cout<<"\n";
}

// Function to insert a node at the beginning/front of the DLL
void insertFront(Node** head_ref, int new_data){

    Node* new_node = new Node(new_data);

    if(*head_ref != NULL){
        new_node->next = *head_ref;
        (*head_ref)->prev = new_node;
    }
    *head_ref = new_node;
}

// Function to insert a node at the end/last of the DLL
void insertEnd(Node** head_ref, int new_data){

    Node* new_node = new Node(new_data);

    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }
    Node* temp = *head_ref;

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
    
}

// Function to insert a node after a given node in a DLL
void insertAfter(Node* prev_node, int new_data){

    Node* new_node = new Node(new_data);

    if(prev_node == NULL){
        cout<<"prev_node shouldn't be NULL";
        return;
    }
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    new_node->prev = prev_node;

    if(new_node->next != NULL)
        new_node->next->prev = new_node;

}

// Function to insert a node before a given node in a DLL
void insertBefore(Node** head_ref, Node* curr_node, int new_data){

    Node* new_node = new Node(new_data);

    if(curr_node == NULL){
        cout<<"curr_node shouldn't be NULL";
        return;
    }
    new_node->prev = curr_node->prev;
    curr_node->prev = new_node;
    new_node->next = curr_node;    

    if(new_node->prev != NULL)
        new_node->prev->next = new_node;
    else
        (*head_ref) = new_node;
}

// Function to delete a node from a DLL, given the pointer to the node to be deleted
void deleteNode(Node** head_ref, Node* del){

    if(*head_ref == NULL || del == NULL)
        return;
    
    if(del == *head_ref)
        *head_ref = del->next;

    if(del->next != NULL)
        del->next->prev = del->prev;
    
    if(del->prev != NULL)
        del->prev->next = del->next;
    
    delete(del);
    return;
}

int main(){
    
    Node* head = NULL;

    insertFront(&head, 2);
    insertEnd(&head, 4);
    insertAfter(head->next, 8);
    insertBefore(&head, head->next, 10);
    insertBefore(&head, head->next->next, 18);
    printList(head);
    deleteNode(&head, head->next->next->next->next);
    printList(head);
    return 0;
}