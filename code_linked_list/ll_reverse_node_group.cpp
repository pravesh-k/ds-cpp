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

// Function to reverse a Linked List in groups of given size
Node* reverseGroup(Node* head, int k){

    // base case
    if (!head)
        return NULL;
    Node* current = head;
    Node* next = NULL;
    Node* prev = NULL;
    int count = 0;
 
    /*reverse first k nodes of the linked list */
    while (current != NULL && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
 
    if (next != NULL)
        head->next = reverseGroup(next, k);
 
    /* prev is new head of the input list */
    return prev;
}

int main(){
    
    Node* head = NULL, *result  = NULL;
    for(int i = 10; i >= 1; i--)
        push(&head, (10*i));
    
    printList(head);
    result = reverseGroup(head, 3);
    printList(result);

}