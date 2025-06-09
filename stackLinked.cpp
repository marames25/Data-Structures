#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class linkedList {
private:
    Node* top;
    Node* tail;
    int size;

public:
    linkedList() {
        top = nullptr;
        tail = nullptr;
        size = 0;
    }

    int Size() {
        return size;
    }
    bool isEmpty() {
        return top == nullptr;
    }

    void push(int element) {
        Node* newnode = new Node;
        newnode->data = element;
        newnode->next = top;
        top = newnode;
        if (size == 0) {
            tail = top;
        }
        size++;
    }

    int pop() {
        if (size == 0) {
            cout << "Stack underflow" << endl;
            return -1;
        } else if (size == 1) {
            int val = top->data;
            delete top;
            top = nullptr;
            tail = nullptr;
            size--;
            return val;
        } else {
            Node* tmp = top;
            top = top->next;
            int val = tmp->data;
            delete tmp;
            size--;
            return val;
        }
    }

    int peek() {
        if (size == 0) {
            cout << "Stack underflow" << endl;
            return -1;
        } else {
            return top->data;
        } 
    }

    void display() {
        if (size == 0) {
            cout << "Stack is empty" << endl;
            return;
        }

        Node* tmp = top;
        while (tmp != nullptr) {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }

    ~linkedList() {
        Node* tmp;
        while (top != nullptr) {
            tmp = top;
            top = top->next;
            delete tmp;
        }
    }
};
int main() {
    linkedList l;
    l.push(20);
    l.push(10);
    l.push(30);

    l.display();      // Output: 30 10 20
    cout<<l.pop()<<endl;
    l.display();      

  
}
