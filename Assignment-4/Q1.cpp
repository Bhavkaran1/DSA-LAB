#include <iostream>
using namespace std;

#define SIZE 5

class Queue {
    int arr[SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int value) {
        if (rear == SIZE - 1) {
            cout << "Queue is full!\n";
        } else {
            if (front == -1)
                front = 0;
            rear++;
            arr[rear] = value;
            cout << value << " added to queue\n";
        }
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty!\n";
        } else {
            cout << arr[front] << " removed from queue\n";
            front++;
        }
    }

    void peek() {
        if (front == -1 || front > rear)
            cout << "Queue is empty!\n";
        else
            cout << "Front element is: " << arr[front] << endl;
    }

    void display() {
        if (front == -1 || front > rear)
            cout << "Queue is empty!\n";
        else {
            cout << "Queue elements: ";
            for (int i = front; i <= rear; i++)
                cout << arr[i] << " ";
            cout << endl;
        }
    }
};

int main() {
    Queue q;
    int ch, val;

    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            q.enqueue(val);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.peek();
            break;
        case 4:
            q.display();
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }

    } while (ch != 5);

    return 0;
}
