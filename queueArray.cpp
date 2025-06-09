#include <iostream>
using namespace std;

class Queue {
private:
    static const int SIZE = 5;
    int queue[SIZE];
    int front, rear; // rear da el current element

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int val) {
        if (rear == SIZE - 1) {
            cout << "Queue is full" << endl;
            return;
        }
        if (front == -1) {
            front = 0;
        }
        queue[++rear] = val;
    }

    void dequeue() {
        if (front == -1 && rear == -1 || front > rear) {
            cout << "Queue is empty" << endl;
            return;
        }
        front++;
    }

    int peek() {
        if (front == -1  && rear == -1 || front > rear) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return queue[front];
    }

    void display() {
        if (front == -1 && rear == -1 || front > rear) {
            cout << "Queue is empty" << endl;
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
    void clear() {
        front = -1;
        rear = -1;
    }
    
};
int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();  // Output: 10 20 30

    cout << "Peek: " << q.peek() << endl;  // Output: 10

    q.dequeue();
    q.display();  // Output: 20 30

    return 0;
}
