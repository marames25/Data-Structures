#include <iostream>
using namespace std;

class CircularQueue {
private:
    static const int SIZE = 5;
    int queue[SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        if (front == -1 && rear == -1) { // lw el queue fadya
            return true;
        } else {
            return false;
        }
    }

    bool isFull() {
        // lw el front fel awel w el rear fel akher OR el front b3d el rear b 1 (circularly)
        if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) {
            return true;
        } else {
            return false;
        }
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "queue is full" << endl;
        } else {
            if (isEmpty()) {
                front = rear = 0; // awl element yd5ol
                queue[rear] = val;
            } else if (rear == SIZE - 1) { // lw el rear wsl lel akher
                rear = 0;
                queue[rear] = val;
            } else {
                queue[++rear] = val;
            }
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "queue is empty" << endl;
        } else {
            if (front == rear) { // m3nah en da akher element mwgood fel queue
                front = rear = -1;
            } else if (front == SIZE - 1) { // el front f akher el queue
                front = 0;
            } else {
                front++;
            }
        }
    }

    int peek() {
        if (isEmpty()) {
            cout << "queue is empty" << endl;
            return -1;
        } else {
            return queue[front];
        }
    }
    
    void display(){
        if(isEmpty()){
            cout<<"nothing to show"<<endl;
        }else{
            if(front<=rear){
                for (int i = front; i <= rear; i++) {
                    cout << queue[i] << " ";
                }
                cout << endl;
            }else{
                // print from front to end of array
                for (int i = front; i < SIZE; i++)
                {
                    cout << queue[i] << " ";
                }       
                // print from start of array to rear
                for (int i = 0; i <= rear; i++) {
                    cout << queue[i] << " ";
                }
                
            }
            cout << endl;
        }
    }
    void clear() {
        front = -1;
        rear = -1;
    }
    
};
int main() {
    CircularQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50); // Should say full after this

    q.display();

    q.dequeue();
    q.dequeue();

    q.display();

    q.enqueue(60);
    q.enqueue(70); // Should wrap around

    q.display();

    cout << "Peek: " << q.peek() << endl;

    return 0;
}
