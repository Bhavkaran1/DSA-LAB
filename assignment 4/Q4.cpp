#include <iostream>
using namespace std;

#define SIZE 100

class Queue {
    char arr[SIZE];
    int front, rear;
public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(char c) {
        if (rear == SIZE - 1)
            return;
        if (front == -1)
            front = 0;
        arr[++rear] = c;
    }

    void dequeue() {
        if (front == -1)
            return;
        front++;
        if (front > rear)
            front = rear = -1;
    }

    char frontElement() {
        return arr[front];
    }

    bool isEmpty() {
        return (front == -1);
    }
};

int main() {
    char s[SIZE];
    cout << "Enter string: ";
    cin >> s;

    Queue q;
    int freq[26] = {0};

    for (int i = 0; s[i] != '\0'; i++) {
        char ch = s[i];
        q.enqueue(ch);
        freq[ch - 'a']++;

        while (!q.isEmpty() && freq[q.frontElement() - 'a'] > 1)
            q.dequeue();

        if (q.isEmpty())
            cout << -1 << " ";
        else
            cout << q.frontElement() << " ";
    }

    return 0;
}
