#include <iostream>
using namespace std;

#define SIZE 10

class Queue {
    int arr[SIZE];
    int front, rear;
public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int val) {
        if (rear == SIZE - 1)
            cout << "Queue full!\n";
        else {
            if (front == -1)
                front = 0;
            arr[++rear] = val;
        }
    }

    int dequeue() {
        if (front == -1 || front > rear)
            return -1;
        else
            return arr[front++];
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    int size() {
        if (front == -1) return 0;
        return (rear - front + 1);
    }

    void display() {
        if (isEmpty())
            cout << "Queue empty!\n";
        else {
            for (int i = front; i <= rear; i++)
                cout << arr[i] << " ";
            cout << endl;
        }
    }

    void interleave() {
        int n = size();
        int half = n / 2;
        int firstHalf[SIZE];

        // store first half
        for (int i = 0; i < half; i++)
            firstHalf[i] = dequeue();

        // interleave
        for (int i = 0; i < half; i++) {
            enqueue(firstHalf[i]);
            enqueue(arr[front + i]);
        }
    }
};

int main() {
    Queue q;
    int n, val;
    cout << "Enter even number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        q.enqueue(val);
    }

    cout << "Original queue: ";
    q.display();

    q.interleave();

    cout << "Interleaved queue: ";
    q.display();

    return 0;
}
