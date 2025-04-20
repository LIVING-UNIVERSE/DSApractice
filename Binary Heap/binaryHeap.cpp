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



//215. Kth Largest Element in an Array
Solved
Medium
Topics
Companies
Facebook
Amazon
LinkedIn
Microsoft
Google
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
 

Constraints:

1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104


// brute force
// t:O(logn) sp:O(1)
class Solution {
    public:
        int findKthLargest(vector<int>& arr, int k) {
            // brute force
            int n=arr.size();
            sort(arr.begin(),arr.end());
            return arr[n-k];
        }
};



// solution using heap
// t:O(nlogn) sp:O(n)
class Solution {
    public:
        int findKthLargest(vector<int>& arr, int k) {
            int n=arr.size();
            priority_queue<int,vector<int>> q;
            for(int i=0;i<n;i++){
                q.push(arr[i]);
            }
            int count=1;
            while(count<k){
                q.pop();count++;
            }
            return q.top();
        }
};



// better solution
// t:O(nlogk) sp:O(k)
class Solution {
    public:
        int findKthLargest(vector<int>& arr, int k) {
            // better solution
            // t:O(nlogk) sp:O(k)
            int n=arr.size();
            priority_queue<int,vector<int>,greater<int>> pq;
            for(int i=0;i<k;i++){
                pq.push(arr[i]);
            }
            for(int i=k;i<n;i++){
                if(arr[i]>pq.top()){
                    pq.pop();
                    pq.push(arr[i]);
                }
            }
            return pq.top();
        }
};



// optimal solution
class Solution {
    private:
        int f(vector<int> &arr, int low,int high){
            int n=arr.size();
            int pivot=high;
            int i=low,j=high-1;
            while(i<=j){
                while(i<=high-1 && arr[i]<arr[pivot]){
                    i++;
                }
                while(j>=low && arr[j]>arr[pivot]){
                    j--;
                }
                if(i<=j){
                    swap(arr[i],arr[j]);i++;j--;
                }
            }
            swap(arr[i],arr[pivot]);
            return i;
        }
    public:
        int findKthLargest(vector<int>& arr, int k) {
            int n=arr.size();
            int low=0,high=n-1;
            int pivot;
            while(true){
                pivot=f(arr,low,high);
                if(pivot==n-k) return arr[pivot];
                else if(pivot>n-k){
                    high=pivot-1;
                }
                else{
                    low=pivot+1;
                }
            }
            return -1;
        }
};



//Kth Smallest
Difficulty: MediumAccuracy: 35.17%Submissions: 685K+Points: 4Average Time: 25m
Given an array arr[] and an integer k where k is smaller than the size of the array, your task is to find the kth smallest element in the given array.

Follow up: Dont solve it using the inbuilt sort function.

Examples :

Input: arr[] = [7, 10, 4, 3, 20, 15], k = 3
Output: 7
Explanation: 3rd smallest element in the given array is 7.
Input: arr[] = [2, 3, 1, 20, 15], k = 4 
Output: 15
Explanation: 4th smallest element in the given array is 15.
Constraints:
1 <= arr.size <= 106
1<= arr[i] <= 106
1 <= k <= n


// better solution
class Solution {
    public:
      // arr : given array
      // k : find kth smallest element and return using this function
      int kthSmallest(vector<int> &arr, int k) {
          // code here
          int n=arr.size();
          priority_queue<int,vector<int>> pq;
          for(int i=0;i<k;i++){
              pq.push(arr[i]);
          }
          for(int i=k;i<n;i++){
              if(pq.top()>arr[i]){
                  pq.pop();
                  pq.push(arr[i]);
              }
          }
          return pq.top();
      }
};


// optimal solution

// User function template for C++

class Solution {
    private:
      int f(vector<int> &arr, int low,int high){
          int n=arr.size();
          int pivot=high;
          int i=low,j=high-1;
          while(i<=j){
              while(i<=high-1 && arr[i]<arr[pivot]){
                  i++;
              }
              while(j>=low && arr[j]>arr[pivot]){
                  j--;
              }
              if(i<=j){
                  swap(arr[i],arr[j]);i++;j--;
              }
          }
          swap(arr[i],arr[pivot]);
          return i;
      }
    public:
      // arr : given array
      // k : find kth smallest element and return using this function
      int kthSmallest(vector<int> &arr, int k) {
          // code here
          int n=arr.size();
          int low=0,high=n-1;
          int pivot;
          while(true){
              pivot=f(arr,low,high);
              if(pivot==k-1) return arr[pivot];
              else if(pivot>k-1){
                  high=pivot-1;
              }
              else{
                  low=pivot+1;
              }
          }
          return -1;
      }
};