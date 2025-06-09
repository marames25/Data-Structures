#include <bits/stdc++.h>
using namespace std;

class list
{
private:
    int* arr;
    int size;
    int length;
public:
    list (int sz){
        size =sz;
        arr = new int[size];
        length = 0;
    }

    bool isEmpty(){
        return(!length);
    }

    bool isFull(){
        return length == size;
    }

    int listSize(){
        return size;
    }

    int listLength(){
        return length;
    }

    void print(){
        if (length != 0){
            for (int i = 0; i < length; i++){
            cout<< arr[i]<<" ";
            }
        cout<<endl;
        return;
        }
        cout<<"EMPTY"<<endl;
    }

    bool isItemEqual (int index, int element){
        if(index >=0 && index <= length && lenght != 0){
            return arr[index]== element;
        }
        return false;
    }

    void insertAt(int index, int element){
        if(index >=0 && index <= length && index <length){
            for (int i = length ; i>index ;i--){
                arr[i] = arr[i-1];
            }
            arr[index] = element;
            lenght++;
        }
    }

    void insertEnd(int element){
        if (index +1 <= size ){
            arr[length] = element;
            length++;
        }
    }

    void removeAt(int index){
        if(index >=0 && index < length){
            for(int i = index;i<lenght;i++){
                arr[i] =  arr[i+1];
            }
            length--;
        }
    }

    void replaceAt(int index,int element){
        if(index >=0 && index < length){
            arr[index] = element;
        }

    }

    void clear(){
        int lenght = 0;
    }

    bool search(int element){
        for(int i = 0 ;i<length;i++ ){
            if(arr[i]==element) return true;
        }
        return false;
    }

    int searchIndex(int element){
        for(int i = 0 ;i<length;i++ ){
            if(arr[i]==element) return i;
        }
        return -1;
    }

    void remove (int element){
        int inedx = searchIndex(element);
        removeAt(index);
    }
    
    ~list(){
        delete []arr;
    }

};
int main(){

}