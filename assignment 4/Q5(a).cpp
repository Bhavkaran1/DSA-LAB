#include <iostream>
using namespace std;

#define SIZE 10

class Queue {
    int arr[SIZE];
    int front, rear;
public:
    Queue() { front = -1; rear = -1; }

    void enqueue(int val) {
        if (rear == SIZE - 1)
            return;
        if (front == -1)
            front = 0;
        arr[++rear] = val;
    }

    int dequeue() {
        if (front == -1 || front > rear)
            return -1;
        int val = arr[front++];
        return val;
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }
};

class Stack {
    Queue q1, q2;

public:
    void push(int x) {
        q2.enqueue(x);
        while (!q1.isEmpty())
            q2.enqueue(q1.dequeue());
        // swap queues
        Queue temp = q1;
        q1 = q2;
        q2 = temp;
    }

    void pop() {
        if (q1.isEmpty())
            cout << "Stack empty!\n";
        else
            cout << q1.dequeue() << " popped.\n";
    }

    void display() {
        cout << "Top element is at front of q1.\n";
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.pop();
    s.push(40);
    s.pop();
    return 0;
}
