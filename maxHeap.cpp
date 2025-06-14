#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
private:
    vector<int> heap = {0};  // index 0 is a dummy to make the heap 1-indexed

    int parent(int i)     { return i / 2; }
    int leftChild(int i)  { return 2 * i; }
    int rightChild(int i) { return 2 * i + 1; }

    void heapifyUp(int i) {
        while (i > 1 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }
    
    // MAX-HEAPIFY — O(log n)
    void heapifyDown(int i) {
        int largest = i;
        int l = leftChild(i);
        int r = rightChild(i);
        int size = heap.size() - 1; // because index 0 is ignored

        if (l <= size && heap[l] > heap[largest])
            largest = l;
        if (r <= size && heap[r] > heap[largest])
            largest = r;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }
    //mohem awy- O(n)
    void buildMaxHeap(vector<int> arr) {
        heap = {0}; // reset
        for (int val : arr) 
            heap.push_back(val);
        int size = heap.size() - 1;
    
        for (int i = size / 2; i >= 1; i--) {
            heapifyDown(i);
        }
    }

public:
    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    int getMax() { //o(1)
        if (heap.size() <= 1) {
            cout << "Heap is empty!\n";
            return -1;
        }
        return heap[1];
    }
    //HEAP-EXTRACT-MAX — O(log n) 
    void extractMax() {
        if (heap.size() <= 1) return;
    
        heap[1] = heap.back();
        heap.pop_back();
    
        heapifyDown(1);
    }
       
    //HEAP-INCREASE-KEY — O(log n)
    void increaseKey(int i, int new_val) {
        if (new_val < heap[i]) return; // ignoring invalid increase
    
        heap[i] = new_val;
        heapifyUp(i);
    }
    

    void removeMax() {
        if (heap.size() <= 1) {
            cout << "Heap is empty!\n";
            return;
        }

        heap[1] = heap.back();
        heap.pop_back();
        heapifyDown(1);
    }

    void printHeap() {
        cout << "Heap elements: ";
        for (int i = 1; i < heap.size(); ++i)
            cout << heap[i] << " ";
        cout << endl;
    }

    bool isEmpty() {
        return heap.size() <= 1;
    }

    vector<int> heapSort() { //O(n log n)
        vector<int> sorted;
        // Work on a copy to preserve original heap
        vector<int> temp = heap;

        for (int i = 0; i < size; i++) {
            sorted.push_back(getMax()); // extract max
            removeMax();
        }

        // Restore the original heap
        heap = temp;

        reverse(sorted.begin(), sorted.end()); // ascending order
        return sorted;
    }
};
int main() {    
    MaxHeap pq;

    pq.insert(10);
    pq.insert(30);
    pq.insert(20);
    pq.insert(5);
    pq.insert(40);

    pq.printHeap();               // Should show the largest at the top

    cout << "Max: " << pq.getMax() << endl;

    pq.removeMax();
    pq.printHeap();               // New max should appear
     // 🔽 Perform heap sort
     vector<int> sorted = pq.heapSort();
     cout << "Sorted array (heap sort): ";
     for (int val : sorted)
         cout << val << " ";
     cout << endl;

    return 0;
}
