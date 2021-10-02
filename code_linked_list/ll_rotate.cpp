// A C++ program to rotate a linked list in anti-clockwise direction by given number of nodes

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

void printList(Node* head){
    while(head != NULL){
        cout<<head->data<<"  ";
        head = head->next;
    }
    cout<<"\n";
}

void push(Node** head_ref, int new_data){
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to rotate
void rotate(Node** head_ref, int k){

    if(*head_ref == NULL || (*head_ref)->next == NULL || k == 0)
        return;

    Node* temp = *head_ref;

    while(k-- != 1)
        temp = temp->next;
    
    Node* new_head = temp;
    
    while(new_head->next != NULL)
        new_head = new_head->next;

    new_head->next = *head_ref;
    *head_ref = temp->next;
    temp->next = NULL;
}

int main(){
    
    Node* head = NULL;
    for(int i = 10; i >= 1; i--)
        push(&head, (10*i));
    
    printList(head);
    rotate(&head, 7);
    printList(head);

}