//Binary Heap Operations
Difficulty: MediumAccuracy: 22.3%Submissions: 105K+Points: 4Average Time: 15m
A binary heap is a Binary Tree with the following properties:
1) Its a complete tree (All levels are completely filled except possibly the last level and the last level has all keys as left as possible). This property of Binary Heap makes them suitable to be stored in an array.

2) A Binary Heap is either Min Heap or Max Heap. In a Min Binary Heap, the key at the root must be minimum among all keys present in Binary Heap. The same property must be recursively true for all nodes in Binary Tree. Max Binary Heap is similar to MinHeap.

You are given an empty Binary Min Heap and some queries and your task is to implement the three methods insertKey,  deleteKey,  and extractMin on the Binary Min Heap and call them as per the query given below:
1) 1  x  (a query of this type means to insert an element in the min-heap with value x )
2) 2  x  (a query of this type means to remove an element at position x from the min-heap)
3) 3  (a query like this removes the min element from the min-heap and prints it ).

Examples :

Input: 
Q = 7
Queries:
insertKey(4)
insertKey(2)
extractMin()
insertKey(6)
deleteKey(0)
extractMin()
extractMin()
Output: [2, 6, -1]
Explanation: In the first test case for
query 
insertKey(4) the heap will have  {4}  
insertKey(2) the heap will be {2 4}
extractMin() removes min element from 
             heap ie 2 and prints it
             now heap is {4} 
insertKey(6) inserts 6 to heap now heap
             is {4 6}
deleteKey(0) delete element at position 0
             of the heap,now heap is {6}
extractMin() remove min element from heap
             ie 6 and prints it  now the
             heap is empty
extractMin() since the heap is empty thus
             no min element exist so -1
             is printed.
Input:
Q = 5
Queries:
insertKey(8)
insertKey(9)
deleteKey(1)
extractMin()
extractMin()
Output: [8, -1]
Constraints:
1 <= Q <= 104
1 <= x <= 104


// solution
/*The structure of the class is
struct MinHeap
{
    int *harr;
    int capacity, heap_size;
    MinHeap(int cap) {heap_size = 0; capacity = cap; harr = new int[cap];}
    int extractMin();
    void deleteKey(int i);
    void insertKey(int k);
    int parent(int i);
    int left(int i);
    int right(int i);
};*/



//Function to extract minimum value in heap and then to store 
//next minimum value at first index.
int MinHeap::extractMin() {
    if(heap_size==0) return -1;
    if(heap_size==1){
        heap_size--;return harr[heap_size];
    }
    swap(harr[0],harr[heap_size-1]);
    heap_size--;
    MinHeapify(0);
    return harr[heap_size];
}

//Function to delete a key at ith index.
void MinHeap::deleteKey(int i){
    decreaseKey(i,INT_MIN);
    extractMin();
}

//Function to insert a value in Heap.
void MinHeap::insertKey(int k) {
    heap_size++;
    harr[heap_size-1]=k;
    for(int i=heap_size-1;i!=0 && harr[parent(i)]>harr[i];){
        swap(harr[parent(i)],harr[i]);
        i=parent(i);
    }
}

//Function to change value at ith index and store that value at first index.
void MinHeap::decreaseKey(int i, int new_val) {
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i]) {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

/* You may call below MinHeapify function in
   above codes. Please do not delete this code
   if you are not writing your own MinHeapify */
void MinHeap::MinHeapify(int i) 
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i]) smallest = l;
    if (r < heap_size && harr[r] < harr[smallest]) smallest = r;
    if (smallest != i) {
        swap(harr[i], harr[smallest]);
        MinHeapify(smallest);
    }
}



//Heap Sort
Difficulty: MediumAccuracy: 53.06%Submissions: 122K+Points: 4Average Time: 20m
Given an array arr[]. The task is to sort the array elements by Heap Sort.

Examples:

Input: arr[] = [4, 1, 3, 9, 7]
Output: [1, 3, 4, 7, 9]
Explanation: After sorting elements using heap sort, elements will be in order as 1, 3, 4, 7, 9.
Input: arr[] = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
Explanation: After sorting elements using heap sort, elements will be in order as 1, 2, 3, 4, 5, 6, 7, 8, 9, 10.
Input: arr[] = [2, 1, 5]
Output: [1, 2, 5]
Explanation: After sorting elements using heap sort, elements will be in order as 1, 2, 5.
Constraints:
1 ≤ arr.size() ≤ 106
1 ≤ arr[i] ≤ 106



// solution
// The functions should be written in a way that array become sorted
// in increasing order when heapSort() is called.

class Solution {
    private:
      void buildHeap(vector<int> &arr,int size){
          for(int i=(size-2)/2; i>=0;i--){
              maxHeapify(i,size,arr);
          }
      }
      void maxHeapify(int i,int size,vector<int> &arr){
          int left=2*i+1,right=2*i+2;
          int largest=i;
          if(left<size && arr[left]>arr[largest]){
              largest=left;
          }
          if(right<size && arr[right]>arr[largest]){
              largest=right;
          }
          if(largest!=i){
              swap(arr[largest],arr[i]);
              maxHeapify(largest,size,arr);
          }
      }
    public:
      // Function to sort an array using Heap Sort.
      void heapSort(vector<int>& arr) {
          int n=arr.size();
          buildHeap(arr,n);
          for(int i=n-1;i>=1;i--){
              swap(arr[0],arr[i]);
              maxHeapify(0,i,arr);
          }
      }
  };