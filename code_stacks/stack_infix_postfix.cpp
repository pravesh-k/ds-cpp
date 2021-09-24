// A C++ program to convert an infix into postfix expression

#include<bits/stdc++.h>
using namespace std;

// Fucntion to return the precedence of the operator
int operatorPrecedence(char op){

    if(op == '+' || op == '-')
        return 1;
    if(op == '/' || op == '*')
        return 2;
    if(op == '^')
        return 3;
    else
        return 0;
}

// Fucntion to return the postfix expression after conversion from infix
string infixToPostfix(string exp){

    stack<char> st;
    string res = "";
    for(int i = 0; i < exp.length(); i++){

        char ch = exp[i];
        
        // if ch is alphanumeric, add to postfix result expression
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
            res += ch;
        else            
            if(ch == '(' || ch == '{' || ch == '[') // if any opening parenthesis push to operator stack
                st.push(ch);
            else
                if(ch == ')' || ch == '}' || ch == ']'){ // if any closing parenthesis, pop until matching opening parenthesis is detected
                    if(ch == ')')
                        while(st.top() != '('){
                            res += st.top();
                            st.pop();
                        }
                    if(ch == '}')
                        while(st.top() != '{'){
                            res += st.top();
                            st.pop();
                        }
                    if(ch == ']')
                        while(st.top() != '['){
                            res += st.top();
                            st.pop();
                        }
                    st.pop(); // pop out the opening parenthesis from the stack
                }
                else
                    if(ch == '-' || ch == '+' || ch == '*' || ch == '/' || ch == '^'){ // if ch is any of the operator
                        if(st.empty()) // if stack is empty, no need to check for precedence and push ch at the top
                            st.push(ch);
                        else
                            if(operatorPrecedence(ch) > operatorPrecedence(st.top())) // if prcedence of ch is higher than operator
                                st.push(ch);                                          //  at the stack, push ch into stack top
                            else{
                                while(!st.empty() && operatorPrecedence(ch) <= operatorPrecedence(st.top())){ // if ch is of lower precedence
                                    res += st.top();                                                          // start popping out operators
                                    st.pop();                                                                 // from the stack top until an
                                }                                                                             // operator of low precedence is detected
                                st.push(ch); // after all high precedence operator are popped out
                            }                // push the current ch operator at the stack top
                    }
    }
    while(!st.empty()){ // if any operators are left in the stack, then pop and append all elements to the result postfix exp
        res += st.top();
        st.pop();
    }

    return res;
}

int main(){

    string inf_exp = "a+b*{(c^d-e)^(f+g*h)}-i";
    cout<<inf_exp<<"\n"<<endl;
    cout<<infixToPostfix(inf_exp)<<endl;

    return 0;
}