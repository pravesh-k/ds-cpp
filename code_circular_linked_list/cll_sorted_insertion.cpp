// A C++ program to perform a sorted insert in CLL
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

// (3)To insert a node at the end of a LL
void addEnd(Node** last, int new_data){

    if(*last == NULL){
        addToEmpty(last, new_data);
        return;
    }
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*last)->next;
    (*last)->next = new_node;
    *last = new_node;

}

// (4)To insert a node in between a CLL
void addAfter(Node** last, int key_pos, int new_data){ // insert a new node (with data as new_data) after the 
                                                       // node in CLL which has data equal to key_pos

    if(*last == NULL)
        return;

    Node* new_node = new Node();
    new_node->data = new_data;
    
    Node* temp = (*last)->next;

    while(temp != *last){
        if(temp->data == key_pos)
            break;
        temp = temp->next;
    }

    if(temp == *last){
        addEnd(last, new_data);
    }
    else{
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

void printList(Node* last){
    if(last != NULL){
        Node* h;
        h = last->next;
        do{
            cout<<h->data<<"  ";
            h = h->next;
        }
        while(h != last->next);
        cout<<"\n";
    }
    else
        return;
}

// Function to perform sorted Insertion in a CLL
void sortedInsertion(Node** last, int new_data){

    if(*last == NULL){
        addToEmpty(last, new_data);
        return;
    }

    if(new_data >= (*last)->data){
        addEnd(last, new_data);
        return;
    }

    Node* temp = (*last)->next;
    
    if(temp->data >= new_data){
        addBegin(last, new_data);
        return;
    }
    
    while(temp != *last){

        if((temp->data < new_data) && (new_data < temp->next->data))
            addAfter(last, temp->data, new_data);
        else
            temp = temp->next;        
    }
}

int main(){
    
    Node* last = NULL;
    
    addToEmpty(&last, 54);
    addBegin(&last, 45);
    addBegin(&last, 31);
    addBegin(&last, 24);
    addBegin(&last, 17);
    printList(last);

    sortedInsertion(&last, 21);
    printList(last);
    
    return 0;
}