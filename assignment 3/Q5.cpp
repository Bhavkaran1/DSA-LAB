// Q5. Write a program for the evaluation of a Postfix expression.

#include <iostream>
#include <stack>
using namespace std;

// evaluate postfix expression (digits only)
int evalPostfix(string post) {
    stack<int> st;
    for(char c: post){
        // if operand → push
        if(c>='0'&&c<='9') st.push(c-'0');
        // if operator → pop two values and apply
        else {
            int b=st.top(); st.pop();
            int a=st.top(); st.pop();
            if(c=='+') st.push(a+b);
            else if(c=='-') st.push(a-b);
            else if(c=='*') st.push(a*b);
            else if(c=='/') st.push(a/b);
        }
    }
    return st.top(); // final result
}

int main(){
    string post;
    cout<<"Enter postfix: ";
    cin>>post;
    cout<<"Result: "<<evalPostfix(post);
}
