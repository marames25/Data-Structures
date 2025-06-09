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
    Node* head;
    Node* tail;
    int size;
public:

    linkedList(){
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    
    void pushBack(int element){

        Node *newnode = new Node;
        newnode->next = nullptr;
        newnode->data = element;
        if(size == 0){
            head = tail = newnode;
        }else{
            tail->next = newnode;
            tail = newnode;
        }
        size++;
    }

    void pushFront(int element){
        Node *newnode = new Node;
        newnode->data =  element;
        newnode->next = head;
        head = newnode;
        if(size == 0){
            tail = head ;
        }
        size ++;
    }

    void popFront(){
        if (size == 0) return;
        else if(size ==1 ){
            delete head;
            head = nullptr;
            tail = head;
        }else{
            Node *tmp = head;
            head = head->next;
            delete tmp;
        }
        size--;
    }

    void popBack(){
        if (size == 0) return;
        else if(size ==1 ){
            delete head;
            head = nullptr;
            tail = head;
        }
        else{
            Node *tmp = head;
            while (tmp->next!=tail)
            {
                tmp = tmp->next;
            }
            delete tail;
            tail = tmp;  
        }
        size--;
    }

    void display(){
        if(size){
            Node *tmp = head;
            while (tmp!=nullptr)
            {
                cout<<tmp->data<<" ";
                tmp =  tmp->next;
            }
            cout<<endl;
            
        }
    }

    int at(int index){
        if(index>=0 && index <size){
            Node *tmp = head;

            for (int  i = 0; i < index; i++)
            {
                tmp = tmp->next;
            }
            return tmp->data;
            
        }
        return -1;
    }

    bool isEmpty(){
        return !size;
    } 
    
    int max(){
        if(!isEmpty()){
            Node *tmp = head;
            int maxVal = head->data;
            while (tmp != nullptr)
            {
                if(tmp->data > maxVal){
                    maxVal = tmp->data;
                }
                tmp = tmp->next;
            }
            return maxVal;
        }
        return -1;
    }

    int min(){
        if (!isEmpty()){
            Node *tmp = head;
            int minVal = head->data;
            while (tmp!=nullptr)
            {
                if(tmp->data <minVal){
                    minVal = tmp->data;
                }
                tmp = tmp->next;
        
            }
            return minVal;  
        }
        return -1;
    }

    int Size(){
        return size;
    }

    int findAtIndex(int element){

        Node *tmp = head;
        int index =0;
        while (tmp!=nullptr)
        {
            if (tmp->data == element) return index;
            tmp = tmp->next;
            index ++;
        }            
        return -1;
    }

    void pushSorted(int element){  
        Node *newnode = new Node;
        newnode->data = element;
        newnode->next = nullptr;

        if(!head || element <head->data){
            newnode->next = head;
            head = newnode;
            if(size == 0) tail = newnode;
            size++;
            return;
        }
        Node *tmp = head ;
        while (tmp->next && tmp->next->data < element)
        {
            tmp =  tmp->next;
        }
        newnode->next = tmp->next;
        tmp->next = newnode;
        if(newnode->next == nullptr){
            tail = newnode;
        }
        size++;
    }

    void insert(int index, int element){
        Node *newnode = new Node;
        newnode->data = element;
        newnode->next = nullptr;
        
        if (isEmpty()){
            head = tail = nullptr;
        }
        else if(index == size-1){
            pushBack(element);
        }
        else if(index == 0){
            pushFront(element);
        }
        else{
            Node *current = head;
            Node *prev = head;
            int count = 0;
            while (current!=nullptr)
            {
                if(index == count){
                    newnode->next = current;
                    prev->next= newnode;
                    size++;
                }
                count++;
                prev =  current;
                current=current->next;
            }
            


        }
    }

    bool isSorted(){
        if (size == 0 || size == 1) return true;
        Node *tmp = head;
        
        while (tmp->next!=nullptr){ 
            if (tmp->data > tmp->next->data)
            {
                return false;
            }
            tmp = tmp->next;
        }
        return true;
            
        
    }

    void Delete(int index){
        if(index ==0){
            popFront();
        }
        else if(index == size -1){
            popBack();
        }
        else if (index>0 && index <size){
            Node *current = head;
            Node *prev = head;
            for (int i = 0; i < index; i++)
            {
                prev = current;
                current =  current->next;
            }
            prev->next = current->next;
            delete current;
            size--;
            


        }
    }
    
    bool isLooping(){
        Node *fast = head;
        Node *slow = head;
        while (fast!=nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) return true;
        }
        return false; 
        
    }
    
    void add(linkedList &other){
        if(other.size !=0){
            if(size == 0){
                head = other.head;
                tail = other.tail;
            }
            else{
                tail->next = other.head;
                tail = other.tail;
            }
        }
    }

    void reverse(){
        Node *prev = nullptr;
        Node *curr = head;
        Node *nxt =  curr->next;
        while(curr !=nullptr){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr =nxt;
        }
        head = prev;
    }

    ~linkedList(){
        Node *tmp = head;
        while(head != nullptr){
            tmp = head;
            head= head->next;
            delete tmp;
        }
    }
    
};



int main(){
    linkedList l ;
    l.pushFront(20);
    l.pushFront(10);
    l.pushBack(30);
    l.display();
    l.reverse();
    l.display();


}