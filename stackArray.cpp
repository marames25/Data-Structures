#include <bits/stdc++.h>
using namespace std;
#define size 20

int myStack[size] ,top = -1;

void push (int val){
    if (top == size -1){
        cout<<"stack overflow"<<endl;
    }else{
        myStack[++top] = val;
    }

}
int pop(){
    if ( top == -1){
        cout<<"Nothing to delete"<<endl;
        return -1;
    }else{
        return myStack[top--];
    }

}
int peek(){
    if ( top == -1){
        cout<<"Nothing to show"<<endl;
        return -1;
    }else{
        return myStack[top];
    }
}
void print(){
    if(top==-1){
        cout<<"Stack is empty"<<endl;
    }else{
        for(int i = top;i>=0;i--){
            cout<< myStack[i]<< " ";
        }
    }
    cout<<endl;
}
int main(){
    push(10);
    push(20);
    push(30);
    cout << "Top element: " << peek() << endl;
    print(); 
    cout << "Popped: " << pop() << endl;
    cout << "Popped: " << pop() << endl;
    cout << "Popped: " << pop() << endl;
    print();
    cout << "Popped: " << pop() << endl; // This will trigger underflow message

    return 0;

}