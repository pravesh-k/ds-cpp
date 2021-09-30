// A C++ program to add two numbers represented by linked list

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

void printList(Node* head){

    if(head == NULL){
        cout<<"\n";
        return;
    }
    
    cout<<head->data<<"  ";
    return printList(head->next);
}

void push(Node** head_ref, int new_data){
    
    Node* temp = new Node();
    temp->data = new_data;
    temp->next = *head_ref;
    *head_ref = temp;
}

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

// Function to add two numbers represented by LL
Node* addTwoNum(Node* a, Node* b){

    Node* res = NULL;
    int carry = 0, sum;

    while(a != NULL || b != NULL){
        
        sum = carry + (a ? a->data:0) + (b ? b->data:0);
        carry = (sum >= 10) ? 1 : 0;
        sum = sum % 10;
        
        append(&res, sum);

        if(a)
            a = a->next;
        if(b)
            b = b->next;
    }
    
    if (carry > 0){
        append(&res, carry);
    }
 
    return res;
}

int main(){
    
    Node* a = NULL, *b = NULL, *res = NULL;

    for(int i = 1; i <= 4; i++){
        push(&a, 2*i);
    }
    for(int i = 4; i >= 1; i--){
        push(&b, (i+5));
    }

    printList(a);
    printList(b);

    res = addTwoNum(a, b);
    printList(res);
}