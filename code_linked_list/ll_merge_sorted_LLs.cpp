// A C++ program to merge two sorted LL's into one single sorted LL

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
Node* merge_sorted_lists(Node* a, Node* b){

    if(a == NULL){
        return b;
        }
    else if(b == NULL){
            return a;
        }

    Node* mergehead = NULL;

    if(a->data <= b->data){
        cout<<"a first\n";
        mergehead = a;
        a = a->next;
    }
    else{
        cout<<"b first\n";
        mergehead = b;
        b = b->next;
    }

    Node* mergetail = mergehead;
        
    while(a != NULL && b!=NULL){
        
        if(a->data <= b->data){
            cout<<"here here\n";
            mergetail->next = a;
            mergetail = mergetail->next;
            a = a->next;
            cout<<a<<"\n";
        }
        else{
            cout<<"now here\n";
            mergetail->next = b;
            mergetail = mergetail->next;
            b = b->next;
            cout<<b<<"\n";
        }
        
        
    }
    if(a != NULL)
        mergetail->next = a;
    else if(b != NULL)
            mergetail->next = b;
    
    return mergehead;
}

// Function (Recursive) to merge two sorted LL's a create a single sorted merged LL.
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

int main(){
    
    Node* head1 = NULL, *head2 = NULL, *result = NULL;
    for(int i = 5; i >= 2; i--){
        push(&head1, (3+i*i/2));
        push(&head2, (5+i*i*i/5));
    }
    printList(head1);
    printList(head2);
    result = merge_sorted_lists_recur(head1, head2);
    printList(result);

}