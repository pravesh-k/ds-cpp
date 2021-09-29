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
void swap(Node** head_ref, int x, int y){

    if(x == y)
        return;

    Node* prevX = NULL, *currX = *head_ref;

    while(currX && currX->data != x){
        prevX = currX;
        currX = currX->next;
    }

    Node* prevY = NULL, *currY = *head_ref;

    while(currY && currY->data != y){
        prevY = currY;
        currY = currY->next;
    }

    if(currX == NULL && currY == NULL)
        return;
    

    if(prevX != NULL)
        prevX->next = currY;
    else
        *head_ref = currY;

    if(prevY != NULL)
        prevY->next = currX;
    else
        *head_ref = currX;

    Node* temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;
       
}

int main(){
    Node* head = NULL;
    for(int i = 1; i <= 10; i++)
        push(&head, (i*i+24/i-4*i));

    printList(head);
    swap(&head, 22, 21);
    printList(head);

}