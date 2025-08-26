// Reverse a string using stack
// No constraints on length.. size is extended if capacity is reached

# include <iostream>
# include <string>
# include <climits>
using namespace std;

class Stack {
    char *data;
    int capacity;
    int nextIndex;

    public:

    Stack() {
        data = new char[4];
        capacity = 4;
        nextIndex = 0;
    }

    bool isEmpty() {
        if(nextIndex == 0) return true;
        else return false;
        // return nextIndex == 0;
    }


    // If capacity is reached, a new array (with twice size )is formed dynamically,contents of previous array are copied into the new array, and data pointer is made to point to the new array
    void push(char c) {
        if (nextIndex == capacity) {
            char *newdata = new char[2*capacity];
            for (int i=0; i<nextIndex; i++) {
                newdata[i] = data[i];
            }
            capacity = 2*capacity;
            delete [] data;             // Deallocating the previous array
            data = newdata;
        }
        data[nextIndex] = c;
        nextIndex++;
    }

    char pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return CHAR_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }


    void reverse(string str) {
        for (int i = 0 ; i <str.length() ; i++) {
            push(str[i]);
        }
        while (nextIndex>0) {
            cout << pop();
        }       
    }
};



int main() 
{
    Stack s;
    string str;
    cout << "Enter string : ";
    cin >> str;
    s.reverse(str);
    cout << endl;
}
