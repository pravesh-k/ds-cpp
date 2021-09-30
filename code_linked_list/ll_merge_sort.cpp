// A C++ program to merge sort a LL.

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

// function to merge two sorted LL's into one sorted LL
Node* merge_sorted_lists_recur(Node* a, Node* b){
    if(a == NULL)
        return b;
    else if(b == NULL)
            return a;
    
    Node* result = NULL;

    if(a->data <= b->data){
        result = a;
        result->next = merge_sorted_lists_recur(a->next, b);
    }
    else{
        result = b;
        result->next = merge_sorted_lists_recur(a, b->next);
    }

    return result;

}

// Functioon to split LL into two halves (Front half and Back half)
void frontBackSplit(Node* source, Node** front_half_ref, Node** back_half_left){

    Node* slow = source, *fast = source->next;
    
    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }

    *front_half_ref = source;
    *back_half_left = slow->next;
    slow->next = NULL;

}

// Function to mergeSort
void mergeSort_LL(Node** head_ref){
    
    if(*head_ref == NULL || (*head_ref)->next == NULL)
        return;

    Node *a, *b;

    frontBackSplit((*head_ref), &a, &b);
    mergeSort_LL(&a);
    mergeSort_LL(&b);
    *head_ref = merge_sorted_lists_recur(a, b);

}

int main(){
    
    Node* head = NULL;
    for(int i = 1; i <= 8; i++)
        push(&head, (i*i*i-6*i*i+7*i+10));
    
    printList(head);
    mergeSort_LL(&head);
    printList(head);

}