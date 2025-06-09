#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class BST {
private:
    struct Node {
        int data;
        Node* left;
        Node* right;

        Node(int val) {
            data = val;
            left = right = nullptr;
        }
    };

    Node* root = nullptr;
     //-------- Recursive Method ----------
    void addHelper(Node* tmp, int val) {
        if (val <= tmp->data) {
            if (tmp->left == nullptr) {
                tmp->left = new Node(val);
            } else {
                addHelper(tmp->left, val);  
            }
        } else {
            if (tmp->right == nullptr) {
                tmp->right = new Node(val);
            } else {
                addHelper(tmp->right, val);
            }
        }
    }

public:
    // ----------- Iterative Insert Method -------------
    void add(int val) {  
        Node* newNode = new Node(val);

        if (root == nullptr) {
            root = newNode;
            return;
        }

        Node* tmp = root;
        Node* prev = nullptr;

        while (tmp != nullptr) {
            prev = tmp;
            if (val <= tmp->data)
                tmp = tmp->left;
            else
                tmp = tmp->right;
        }

        if (val <= prev->data)
            prev->left = newNode;
        else
            prev->right = newNode;
    }
    //--recursive
    void addrecursive(int val) {
        if (root == nullptr) {
            root = new Node(val);
        } else {
            addHelper(root, val);
        }
    }
    //---min, max
    int getMax(){
        Node* tmp = root;
        while (tmp->right !=nullptr)
        {
            tmp = tmp->right;
        }
        return tmp->data;
        
    }
    int getMin(){
        Node* tmp = root;
        while (tmp->left !=nullptr)
        {
            tmp = tmp->left;
        }
        return tmp->data;
        
    }
};

int main() {
    BST tree;
    tree.add(10);
    tree.add(5);
    tree.add(15);
    tree.add(3);
    tree.add(7);
    tree.addrecursive(15);
    cout<<"Max: "<<tree.getMax()<<endl;
    cout<<"Min: "<<tree.getMin()<<endl;
    return 0;
}
