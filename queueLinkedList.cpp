#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* next; 
};

class linkedList
{
private:
    Node* front;
    Node* rear;
    int size;
public:

    linkedList(){
        front = nullptr;
        rear = nullptr; // hykhle el add o(1) f kda ahsan f msh htraverse asln
        size = 0;
    }

    bool isEmpty(){
        return !size;
    } 
    
    void enqueue(int element){

        Node *newnode = new Node;
        newnode->next = nullptr;
        newnode->data = element;
        if(size == 0){
            front = rear = newnode;
        }else{
            rear->next = newnode;
            rear = newnode;
        }
        size++;
    }


    void dequeue(){
        if (size == 0) return;
        else if(size ==1 ){
            delete front;
            front = nullptr;
            rear = front;
        }else{
            Node *tmp = front;
            front = front->next;
            delete tmp;
        }
        size--;
    }

    int peek() {
        if (size == 0) {
            cout << "queue is empty" << endl;
            return -1;
        } else {
            return front->data;
        } 
    }

    
    void display(){
        if(size){
            Node *tmp = front;
            while (tmp!=nullptr)
            {
                cout<<tmp->data<<" ";
                tmp =  tmp->next;
            }
            cout<<endl;
            
        }
    }
    
    void clear() {
        Node* tmp;
        while (front != nullptr) {
            tmp = front;
            front = front->next;
            delete tmp;
        }
        rear = nullptr;
        size = 0;
    }

    
    ~linkedList(){
        Node *tmp = front;
        while(front != nullptr){
            tmp = front;
            front= front->next;
            delete tmp;
        }
    }
    
};



int main(){

    linkedList q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();  // Output: 10 20 30
    cout<<"peek:"<<q.peek()<<endl;
    q.dequeue();
    q.display();  // Output: 20 30

    return 0;





}