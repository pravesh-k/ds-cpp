// A C++ program to insert a mew node at (1) Beginning (2) After a node (3) End
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

    Node* h;
    h = last->next;
    do{
        cout<<h->data<<"  ";
        h = h->next;
    }
    while(h != last->next);
    cout<<"\n";
}

int main(){
    
    Node* last = NULL;
    
    // append(&head,77);

    addToEmpty(&last, 54);
    addBegin(&last, 67);
    addBegin(&last, 15);

    addAfter(&last, 54, 37);  
    addAfter(&last, 15, 88);

    addEnd(&last,8);

    addEnd(&last, 11);

    printList(last);
    
    return 0;
}