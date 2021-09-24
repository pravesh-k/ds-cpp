// A C++ program to implement two stacks in one array.

#include<bits/stdc++.h>
using namespace std;

#define MAX 10

class TwoStacks {
	int top1, top2;

    public:
    int arr[MAX];

    TwoStacks() // constructor
    {
        top1 = -1;
        top2 = MAX;
    }
    void push1(int x);
    void push2(int x);
    int pop1();
    int pop2();
};
	// Method to push an element x to stack1
void TwoStacks::push1(int x){
    // There is at least one empty space for new element
    if (top1 < top2 - 1) {
        arr[++top1] = x;
    }
    else {
        cout << "Stack Overflow";
        exit(1);
    }
}

	// Method to push an element x to stack2
void TwoStacks::push2(int x)
{
    // There is at least one empty
    // space for new element
    if (top1 < top2 - 1) {
        top2--;
        arr[top2] = x;
    }
    else {
        cout << "Stack Overflow";
        exit(1);
    }
}

// Method to pop an element from first stack
int TwoStacks::pop1()
{
    if (top1 >= 0) {
        int x = arr[top1];
        top1--;
        return x;
    }
    else {
        cout << "Stack UnderFlow";
        exit(1);
    }
}

// Method to pop an element from second stack
int TwoStacks::pop2()
{
    if (top2 < MAX) {
        int x = arr[top2];
        top2++;
        return x;
    }
    else {
        cout << "Stack UnderFlow";
        exit(1);
    }
}

/* Driver program to test twStacks class */
int main()
{
	TwoStacks ts;
	ts.push1(5);
	ts.push1(10);
    ts.push1(23);
	ts.push2(7);
    // ts.pop1();
	ts.push2(40);
	// ts.pop2();
    ts.push2(45);

    
    for(int i = 0; i < MAX; i++)
        cout<<ts.arr[i]<<"  ";
	
    return 0;
}
