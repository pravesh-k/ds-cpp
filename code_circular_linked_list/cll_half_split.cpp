// A C++ program to split a CLL in two halves, creating two CLL's.
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

// (1)To insert a new node when list is empty
void addToEmpty(Node** last, int new_data){

    if(*last != NULL)
        return;

    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = new_node;
    *last = new_node;

}

// (2)To insert a new node at the beginning of the CLL
void addBegin(Node** last, int new_data){

    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*last)->next;
    (*last)->next = new_node;

}

void printList(Node* last){

    if(last == NULL)
        return;

    Node* h;
    h = last->next;
    do{
        cout<<h->data<<"  ";
        h = h->next;
    }
    while(h != last->next);
    cout<<"\n";
}

// Function to split CLL in two halves
void splitList(Node* last, Node** l1, Node** l2){

    if(last == NULL || last->next == last) // if there is no or one node present in the list
        return;                            // list with one element can't split

    Node* slow = last->next;
    Node* fast = last->next;

    while(fast->next != last->next && fast->next->next != last->next){
        fast = fast->next->next;
        slow = slow->next;
    }

    if(fast->next->next == last->next)
        fast = fast->next;
    
    fast = fast->next;

    // cout<<last->next->data<<"\n"<<slow->data<<"\n"<<fast->data<<"\n";

    *l1 = slow;
    *l2 = last;
    (*l2)->next = slow->next;
    slow->next = fast;
    
}

int main(){
    
    Node* last = NULL, *l1 = NULL, *l2 = NULL;
    
    addToEmpty(&last, 54);
    addBegin(&last, 67);
    // addBegin(&last, 15);
    // addBegin(&last, 20);
    // addBegin(&last, 100);
    // addBegin(&last, 2);
    // addBegin(&last, 33);
    // addBegin(&last, 11);

    printList(last);
    splitList(last, &l1, &l2);
    printList(l1);
    printList(l2);
    return 0;
}