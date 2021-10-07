#include<bits/stdc++.h>
using namespace std;

class Node{ // blueprint of each node of the tree

    public:
    int data;
    Node *left, *right;
    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

// // Different Depth First Traversal ways for traversing through the tree

// Function for InOrder Traversal through the tree
void inOrder(Node *root){

    if(root == NULL)
        return;

    inOrder(root->left);
    cout<<root->data<<"  ";
    inOrder(root->right);
}

// Function for PreOrder Traversal through the tree
void preOrder(Node *root){

    if(root == NULL)
        return;

    cout<<root->data<<"  ";
    preOrder(root->left);
    preOrder(root->right);
}

// Function for PostOrder Traversal through the tree
void postOrder(Node *root){

    if(root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<"  ";
}

// // Breadth first traversal for traversing through the tree

int height(Node *root); // Function to find the height of the tree

void printCurrentLevel(Node *root, int level); // Function to print all the nodes in a level

// Function for levelOrder Traversal through the tree
void levelOrder(Node *root){

    int h = height(root);
    for(int i = 1; i <= h; i++){
        printCurrentLevel(root, i);
    }
}

void printCurrentLevel(Node *root, int level){

    if(root == NULL)
        return;
    if(level == 1)
        cout<<root->data<<"  ";
    else{
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

int height(Node* node){
    
    if (node == NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);
 
        /* use the larger one */
        if (lheight > rheight)
        {
            return (lheight + 1);
        }
        else {
          return (rheight + 1);
        }
    }
}

// Level Order Traversal Ends Here

// ===========================================================================================================
// // Diameter of a binary tree
/* Definition: The diameter of a tree (sometimes called the width) is the number of nodes on the longest 
   path between two end nodes.

   Logically: The diameter of a tree T is the largest of the following quantities:
    -the diameter of T’s left subtree.
    -the diameter of T’s right subtree.
    -the longest path between leaves that goes through the root of T (this can be computed 
     from the heights of the subtrees of T (Actually it is the sum of heights of left & right subtrees + 1 ))
   */
// ===========================================================================================================
// Function to find the diameter of a binary tree

int max(int a, int b) {return (a>b)?a:b;} // function to return max out of two numbers(int)

int diameter(Node *root){
    
    if(root == NULL)
        return 0;
    
    int lh = height(root->left); // height of left subtree
    int rh = height(root->right); //height of right subtree

    int ldiameter = diameter(root->left);
    int rdiameter = diameter(root->right);

    return max(lh+rh+1, max(ldiameter, rdiameter));
}

// // In-Order traversal can also be done without recursion ( by using stacks)
// Function for non-recursive inOrder traversal
void inOrderNonRecur(Node *root){

    stack<Node *> s;
    Node *curr = root;

    while(curr != NULL || !s.empty()){
        
        while(curr != NULL){
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top();
        s.pop();
        cout<<curr->data<<"  ";

        curr = curr->right;
    }
}

// Driver/main Function
int main(){

    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout<<"In-Order"<<endl;
    inOrder(root);
    cout<<"\nPre-Order"<<endl;
    preOrder(root);
    cout<<"\nPost-Order"<<endl;
    postOrder(root);
    cout<<"\nLevel-Order"<<endl;
    levelOrder(root);
    cout<<"\nDiameter of the Tree"<<endl;
    cout<<diameter(root)<<endl;
    cout<<"Non Recursive In-Order"<<endl;
    inOrderNonRecur(root);
    return 0;
}