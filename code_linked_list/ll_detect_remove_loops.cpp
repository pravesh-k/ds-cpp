// A C++ program to detect and remove loops in a linked list

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

/* // Function to remove if loop detected
void removeLoop(Node* loop_node, Node* head){

    Node* ptr1 = loop_node, *ptr2 = loop_node;
    int k = 1;

    while(ptr1->next != ptr2){ //counting the number of nodes in the loop
        k++;
        ptr1 = ptr1->next;
    }

    ptr1 = head;
    ptr2 = head;

    for(int i = 0; i < k; i++)
        ptr2 = ptr2->next;
    
    while(ptr1 != ptr2){ //finding the head of the exact node where loop is formed
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    while(ptr2->next != ptr1) // finding the prev node of head node of the loop
        ptr2 = ptr2->next;

    ptr2->next = NULL; //breaking the link between head and prev node of the loop

}

// Function to detect loop
bool detectAndRemoveLoop(Node* head){

    Node* slow_p = head, *fast_p = head;
    while(slow_p && fast_p && fast_p->next){
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;

        if(slow_p == fast_p){
            removeLoop(slow_p, head); //calling removeLoop function once confirmed if there exists a loop
            return true;
        }        
    }
    
    return false;
}
 */
// Another simple and optimized function (without counting 
// the number of nodes in a loop) to detect and remove the loop 

void detectAndRemoveLoopOptimized(Node* head){
    
    if(head == NULL || head->next == NULL) //check if 0 or 1 node present in LL. Can't have a loop.
        return;

    Node* slow = head, *fast = head;
    while(slow && fast && fast->next){ //find the node inside the loop where slow and fast meet
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            break;
    }

    if(slow == fast){

        slow = head; //setting slow at head. will move towards head node of loop from head of LL.
                     //Meanwhile fast is at a node inside the loop.
                     //mathematically fast and slow now are at equal distances from the head node of loop

        if(slow == fast){ //if head of LL is head node of the loop, find the prev node of the head node in the loop
            while(fast->next != slow)
                fast = fast->next;
        }
        else
            while(fast->next != slow->next){ //if head of LL is not the head node of loop, 
                                             //find the prev node of head node in the loop
                slow = slow->next;
                fast = fast->next;
            }
    }
    fast->next = NULL; //breaking link between prev and head node of the loop.
}

int main(){
    
    Node* head = NULL;
    for(int i = 5; i >= 1; i--)
        push(&head, (10*i));
    
    printList(head);
    head->next->next->next->next->next = head->next;
    // printList(head);
    // bool res = detectAndRemoveLoop(head);
    detectAndRemoveLoopOptimized(head);
    printList(head);

}