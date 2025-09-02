// Q4. Write a program to convert an Infix expression into a Postfix expression.

#include <iostream>
#include <stack>
using namespace std;

// function to define operator precedence
int prec(char op) {
    if (op=='+'||op=='-') return 1;
    if (op=='*'||op=='/') return 2;
    return 0;
}

// convert infix expression to postfix
string infixToPostfix(string infix) {
    stack<char> st;
    string post="";
    for(char c: infix){
        // if operand → add to result
        if((c>='0'&&c<='9')||(c>='A'&&c<='Z')||(c>='a'&&c<='z'))
            post+=c;
        // if opening bracket → push
        else if(c=='(') st.push(c);
        // if closing bracket → pop until '('
        else if(c==')'){
            while(!st.empty()&&st.top()!='('){ post+=st.top(); st.pop();}
            st.pop(); // remove '('
        }
        // if operator → pop higher/equal precedence ops
        else {
            while(!st.empty()&&prec(st.top())>=prec(c)){ post+=st.top(); st.pop();}
            st.push(c);
        }
    }
    // pop all remaining operators
    while(!st.empty()){ post+=st.top(); st.pop();}
    return post;
}

int main(){
    string infix;
    cout<<"Enter infix: ";
    cin>>infix;
    cout<<"Postfix: "<<infixToPostfix(infix);
}
