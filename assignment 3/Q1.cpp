// Implementing stacks using arrays


# include <iostream>
# include <climits>     // INT_MIN is in this library
using namespace std;

class StackUsingArray {

    int *data;
    int nextIndex;       // nextIndex...Points to the index after the top index
    int capacity;


    public :

    // Stack Constructor
    StackUsingArray(int size) {
        data = new int[size];
        nextIndex = 0;
        capacity = size;
    }

    ~StackUsingArray() {delete [] data;}    // Deallocating array's memory


    bool isEmpty() {
        if(nextIndex == 0) return true;
        else return false;
        // return nextIndex == 0;
    }

    bool isFull() {
        if (nextIndex==capacity) return true;
        else return false;
    }

    void push(int element) {
        if (nextIndex == capacity) {
            cout << "Stack is full" << endl;
            return;
        }
        data[nextIndex] = element;
        nextIndex ++;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }


    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return INT_MIN;
        }
        return data[nextIndex-1];
    }


    int size() {
        return nextIndex;
    }


    void display() {            // From top
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        
        for (int i = nextIndex-1; i>=0; i--) {
            cout << data[i] << " ";
        }
        cout << endl;

        // Using peek()
        // int temp = nextIndex;
        // while (nextIndex>0) {
        //     cout << peek() << " ";
        //     nextIndex--;
        // }
        // nextIndex = temp;

        // To print bottom element first 
        for (int i = 0 ; i<nextIndex ; i++) {
            cout << data[i] << " ";
        }

    }
};



int main() 
{   
    int stack_size;
    cout << "Enter maximum size of stack : " ;
    cin >> stack_size;
    StackUsingArray s(stack_size);
    int choice;
    //(i) push(), (ii) pop(), (iii) isEmpty(), (iv) isFull(), (v) display(), and (vi) peek().
    

    
    do {
        cout << "\n 1. push() \n 2. pop \n 3. isEmpty() \n 4. isFull() \n 5. display() \n 6. peek() " << endl;
        cout << "Enter choice : ";
        cin >> choice;
        

        switch(choice) {

        case 0 : 
            cout << "Terminating Program " << endl;
            break;
            
        case 1 : 
            int data;
            cout <<"Enter data to push : ";
            cin >> data;
            s.push(data);
            break;

        case 2 :
            cout << s.pop() << endl;
            break;

        case 3 :
            int empty;
            empty = s.isEmpty();
            empty == 0? cout << "Not empty": cout << "Empty";
            cout << endl;
            break;

        case 4 :
            int full;
            full = s.isFull();
            full == 0? cout << "Not Full": cout << "Full";
            break;

        case 5 : 
            s.display();
            break;

        case 6:
            cout << s.peek() << endl;
            break;

        default : cout << "Invalid Choice " << endl;
    }
    } while (choice != 0);

    return 0;
}
