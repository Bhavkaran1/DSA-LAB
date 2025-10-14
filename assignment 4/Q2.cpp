#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue {
    int arr[SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int value) {
        if ((front == 0 && rear == SIZE - 1) || (rear + 1 == front)) {
            cout << "Queue is full!\n";
        } else {
            if (front == -1)
                front = 0;
            rear = (rear + 1) % SIZE;
            arr[rear] = value;
            cout << value << " added to circular queue\n";
        }
    }

    void dequeue() {
        if (front == -1) {
            cout << "Queue is empty!\n";
        } else {
            cout << arr[front] << " removed from queue\n";
            if (front == rear)
                front = rear = -1;
            else
                front = (front + 1) % SIZE;
        }
    }

    void peek() {
        if (front == -1)
            cout << "Queue is empty!\n";
        else
            cout << "Front element: " << arr[front] << endl;
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty!\n";
        } else {
            cout << "Queue elements: ";
            int i = front;
            while (true) {
                cout << arr[i] << " ";
                if (i == rear)
                    break;
                i = (i + 1) % SIZE;
            }
            cout << endl;
        }
    }
};

int main() {
    CircularQueue cq;
    int ch, val;

    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            cq.enqueue(val);
            break;
        case 2:
            cq.dequeue();
            break;
        case 3:
            cq.peek();
            break;
        case 4:
            cq.display();
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
