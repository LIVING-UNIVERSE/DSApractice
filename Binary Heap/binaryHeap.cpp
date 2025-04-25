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


//Nearly sorted
Difficulty: MediumAccuracy: 75.25%Submissions: 70K+Points: 4Average Time: 30m
Given an array arr[], where each element is at most k away from its target position, you need to sort the array optimally.
Note: You need to change the given array arr[] in place.

Examples:

Input: arr[] = [6, 5, 3, 2, 8, 10, 9], k = 3
Output: [2, 3, 5, 6, 8, 9, 10]
Explanation: The sorted array will be 2 3 5 6 8 9 10
Input: arr[]= [1, 4, 5, 2, 3, 6, 7, 8, 9, 10], k = 2
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
Explanation: The sorted array will be 1 2 3 4 5 6 7 8 9 10
Dont use the inbuilt sort() function for this question.

Constraints:
1 ≤ arr.size() ≤ 106
0 ≤ k < arr.size()
1 ≤ arri ≤ 106



// brute force
// t:O(n^2logn) sp:O(1)

class Solution {
    public:
      void nearlySorted(vector<int>& arr, int k) {
          int n=arr.size();
          int low=0,high=k;
          while(high<n){
              sort(arr.begin()+low,arr.begin()+high+1);
              low++;high++;
          }
      }
};

// optimal solution

class Solution {
    public:
      void nearlySorted(vector<int>& arr, int k) {
          int n=arr.size();
          priority_queue<int,vector<int>,greater<int>> pq;
          int i,ind=0;
          for(i=0;i<=k;i++){
              pq.push(arr[i]);
          }
          while(i<n){
              arr[ind]=pq.top();
              pq.pop();
              pq.push(arr[i]);
              i++;ind++;
          }
          while(ind<n){
              arr[ind]=pq.top();
              pq.pop();
              ind++;
          }
      }
};



//23. Merge k Sorted Lists
Solved
Hard
Topics
Companies
Facebook
Amazon
Microsoft
Apple
Google
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
 

Constraints:

k == lists.length
0 <= k <= 104
0 <= lists[i].length <= 500
-104 <= lists[i][j] <= 104
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 104.


// brute force
// t:O(n*k) sp:O(1)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    ListNode* f(ListNode* head1, ListNode* head2){
        ListNode* curr1=head1;
        ListNode* curr2=head2;
        ListNode* temp= new ListNode(-1);
        ListNode* dummy=temp;
        while(curr1 && curr2){
            if(curr1->val<curr2->val){
                dummy->next=curr1;
                curr1=curr1->next;
            }
            else{
                dummy->next=curr2;
                curr2=curr2->next;
            }
            dummy=dummy->next;
        }
        while(curr1){
            dummy->next=curr1;
            curr1=curr1->next;
            dummy=dummy->next;
        }
        while(curr2){
            dummy->next=curr2;
            curr2=curr2->next;
            dummy=dummy->next;
        }
        return temp->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& arr) {
        int n=arr.size();
        ListNode* node= new ListNode(-1e8);
        for(int i=0;i<n;i++){
            if(arr[i]){
                node= f(node,arr[i]);
            }
        }
        return node->next;
    }
};


// better solution
// t:O(nlogn) sp:O(n)
class Solution {
    public:
        ListNode* mergeKLists(vector<ListNode*>& arr) {
            int n=arr.size();
            vector<int> v;
            for(int i=0;i<n;i++){
                ListNode* curr= arr[i];
                while(curr){
                    v.push_back(curr->val);
                    curr=curr->next;
                }
            }
            sort(v.begin(),v.end());
            ListNode* temp=  new ListNode(-1);
            ListNode* curr=temp;
            for(int i=0;i<v.size();i++){
                ListNode* node= new ListNode(v[i]);
                curr->next=node;
                curr=curr->next;
            }
            return temp->next;
        }
};


// optimal solution
// t:O(nlogk) sp:O(k)
class Solution {
    public:
        ListNode* mergeKLists(vector<ListNode*>& arr) {
            int n=arr.size();
            priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;
            for(int i=0;i<n;i++){
                if(arr[i]){
                    pq.push({arr[i]->val,arr[i]});
                }
            }
            ListNode* dummy = new ListNode(-1);
            ListNode* temp = dummy;
            while(!pq.empty()){
                auto [val,node] = pq.top();
                pq.pop();
                temp->next=node;
                temp=temp->next;
                if(node->next){
                    pq.push({node->next->val,node->next});
                }
            }
            return dummy->next;
        }
};




//Replace elements by its rank in the array
Difficulty: MediumAccuracy: 49.96%Submissions: 38K+Points: 4Average Time: 30m
Given an array arr of N integers, the task is to replace each element of the array by its rank in the array. The rank of an element is defined as the distance between the element with the first element of the array when the array is arranged in ascending order. If two or more are same in the array then their rank is also the same as the rank of the first occurrence of the element. 

Example 1:

Input:
N = 6
arr = [20, 15, 26, 2, 98, 6]
Output:
4, 3, 5, 1, 6, 2
Explanation:
After sorting, array becomes {2,6,15,20,26,98}
Rank(2) = 1 (at index 0) 
Rank(6) = 2 (at index 1) 
Rank(15) = 3 (at index 2) 
Rank(20) = 4 (at index 3) and so on..
Example 2:

Input:
N = 4
arr = [2, 2, 1, 6]
Output:
2, 2, 1, 3
Explanation:
After sorting, array becomes {1, 2, 2, 6}
Rank(1) = 1 (at index 0) 
Rank(2) = 2 (at index 1) 
Rank(2) = 2 (at index 2) 
Rank(6) = 3 (at index 3)
Rank(6) = 3 because rank after 2 is 3 as rank 
of same element remains same and for next element 
increases by 1.
Your Task:
Complete the function int replaceWithRank(), which takes integer N  and an array of N integers as input and returns the list in which element at each position of original array is replaced by the rank of that element.

Expected Time Complexity: O(N * logN)
Expected Auxiliary Space: O(N)


Constraints:

1 <= N <= 105
1 <= arr[i] <= 109

// solution
// t:O(nlogn)+O(n) sp:O(n)
class Solution{
    public:
    
        vector<int> replaceWithRank(vector<int> &arr, int n){
            priority_queue<pair<int,int> ,vector<pair<int,int>>, greater<pair<int,int>>> pq;
            for(int i=0;i<n;i++){
                pq.push({arr[i],i});
            }
            int rank=0,prev=INT_MIN;
            while(!pq.empty()){
                int ele=pq.top().first;
                int ind=pq.top().second;
                pq.pop();
                if(ele!=prev){
                    prev=ele;rank++;
                }
                arr[ind]=rank;
            }
            return arr;
        }
    
};




//621. Task Scheduler
Solved
Medium
Topics
Companies
Hint
You are given an array of CPU tasks, each labeled with a letter from A to Z, and a number n. Each CPU interval can be idle or allow the completion of one task. Tasks can be completed in any order, but there's a constraint: there has to be a gap of at least n intervals between two tasks with the same label.

Return the minimum number of CPU intervals required to complete all tasks.

 

Example 1:

Input: tasks = ["A","A","A","B","B","B"], n = 2

Output: 8

Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.

After completing task A, you must wait two intervals before doing A again. The same applies to task B. In the 3rd interval, neither A nor B can be done, so you idle. By the 4th interval, you can do A again as 2 intervals have passed.

Example 2:

Input: tasks = ["A","C","A","B","D","B"], n = 1

Output: 6

Explanation: A possible sequence is: A -> B -> C -> D -> A -> B.

With a cooling interval of 1, you can repeat a task after just one other task.

Example 3:

Input: tasks = ["A","A","A", "B","B","B"], n = 3

Output: 10

Explanation: A possible sequence is: A -> B -> idle -> idle -> A -> B -> idle -> idle -> A -> B.

There are only two types of tasks, A and B, which need to be separated by 3 intervals. This leads to idling twice between repetitions of these tasks.

 

Constraints:

1 <= tasks.length <= 104
tasks[i] is an uppercase English letter.
0 <= n <= 100

// solution1 using heap(priority_queue)
// t:O(n) sp:O(1) preffered solution of my version
class Solution {
    public:
        int leastInterval(vector<char>& arr, int k) {
            int n=arr.size();
            vector<int> v(26,0);
            for(int i=0;i<n;i++){
                v[arr[i]-'A']++;
            }
            priority_queue<int> pq;
            for(int i=0;i<26;i++){
                if(v[i]>0){
                    pq.push(v[i]);
                }
            }
            int res=0;
            while(!pq.empty()){
                vector<int> temp;
                for(int i=0;i<=k;i++){
                    if(!pq.empty()){
                        int freq=pq.top();
                        pq.pop();
                        temp.push_back(freq-1);
                    }
                }
                for(int i=0;i<temp.size();i++){
                    if(temp[i]>0){
                        pq.push(temp[i]);
                    }
                }
                res+=(pq.empty())?temp.size():k+1;
            }
            return res;
        }
};

// my code
class Solution {
    public:
        int leastInterval(vector<char>& arr, int k) {
            int n=arr.size();
            vector<int> v(26,0);
            for(int i=0;i<n;i++){
                v[arr[i]-'A']++;
            }
            priority_queue<pair<int,int>,vector<pair<int,int>>> pq;
            for(int i=0;i<26;i++){
                if(v[i]>0){
                    pq.push({v[i],i});
                    v[i]=0;
                }
            }
            for(int i=0;i<26;i++){
                v[i]=0;
            }
            int idle_count=0;
            while(!pq.empty()){
                int count=k+1;
                while(count>0 && !pq.empty()){
                    auto [freq,ind] = pq.top();
                    pq.pop();
                    v[ind]=freq-1;
                    count--;
                }
                int sum=accumulate(v.begin(),v.end(),0);
                if(sum){
                    while(count>0){
                        idle_count++;
                        count--;
                    }
                    for(int i=0;i<26;i++){
                        if(v[i]>0){
                            pq.push({v[i],i});
                            v[i]=0;
                        }
                    }
                }
            }
            return n+idle_count;
        }
};



// optimal solution
// t:O(n) sp:O(1)
class Solution {
    public:
        int leastInterval(vector<char>& arr, int n) {
            int size= arr.size();
            vector<int> freq(26,0);
            for(int i=0;i<size;i++){
                freq[arr[i]-'A']++;
            }
            sort(freq.begin(),freq.end());
            int maxFreq= freq[25]-1;
            int idle_slots= n*maxFreq;
            for(int i=24;i>=0;i--){
                idle_slots-=min(maxFreq,freq[i]);
            }
            return (idle_slots>0)? size+idle_slots: size;
        }
};



//846. Hand of Straights
Solved
1565
Medium
Topics
Companies
Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.

Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.

 

Example 1:

Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
Output: true
Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]
Example 2:

Input: hand = [1,2,3,4,5], groupSize = 4
Output: false
Explanation: Alice's hand can not be rearranged into groups of 4.

 

Constraints:

1 <= hand.length <= 104
0 <= hand[i] <= 109
1 <= groupSize <= hand.length


// solution
// t:O(n) sp:O(n)
class Solution {
    public:
        bool isNStraightHand(vector<int>& arr, int k) {
            int n=arr.size();
            map<int,int> m;
            for(int i=0;i<n;i++){
                m[arr[i]]++;
            }
            while(!m.empty()){
                if(m.size()<k) return false;
                auto it=m.begin();
                int prev=it->first;
                it++;
                for(int i=1;i<k;i++){
                    if(it->first!=prev+1) return false;
                    prev=it->first;
                    it++;
                }
                it=m.begin();
                for(int i=0;i<k;i++){
                    it->second--;
                    if(it->second==0){
                        m.erase(it);
                    }
                    it++;
                }
            }
            return true;
        }
};



//Minimum Cost of ropes
Difficulty: EasyAccuracy: 42.73%Submissions: 237K+Points: 2
Given an array, arr[] of rope lengths, connect all ropes into a single rope with the minimum total cost. The cost to connect two ropes is the sum of their lengths. 

Examples:

Input: arr[] = [4, 3, 2, 6]
Output: 29
Explanation: We can connect the ropes in following ways.
1) First connect ropes of lengths 2 and 3. Which makes the array [4, 5, 6]. Cost of this operation 2 + 3 = 5. 
2) Now connect ropes of lengths 4 and 5. Which makes the array [9, 6]. Cost of this operation 4 + 5 = 9.
3) Finally connect the two ropes and all ropes have connected. Cost of this operation 9 + 6 =15. Total cost is 5 + 9 + 15 = 29. This is the optimized cost for connecting ropes. 
Other ways of connecting ropes would always have same or more cost. For example, if we connect 4 and 6 first (we get three rope of 3, 2 and 10), then connect 10 and 3 (we get two rope of 13 and 2). Finally we connect 13 and 2. Total cost in this way is 10 + 13 + 15 = 38.
Input: arr[] = [4, 2, 7, 6, 9]
Output: 62 
Explanation: First, connect ropes 4 and 2, which makes the array [6, 7, 6, 9]. Cost of this operation 4 + 2 = 6. 
Next, add ropes 6 and 6, which results in [12, 7, 9]. Cost of this operation 6 + 6 = 12.
Then, add 7 and 9, which makes the array [12,16]. Cost of this operation 7 + 9 = 16. And
finally, add these two which gives [28]. Hence, the total cost is 6 + 12 + 16 + 28 = 62.
Input: arr[] = [10]
Output: 0
Explanation: Since there is only one rope, no connections are needed, so the cost is 0.
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 104


// solution
// t:O(n) sp:O(n)
class Solution {
    public:
      int minCost(vector<int>& arr) {
          int cost=0;
          int n=arr.size();
          priority_queue<int,vector<int>,greater<int>> pq(arr.begin(),arr.end());
          while(pq.size()>1){
              int len=pq.top();
              pq.pop();
              len+=pq.top();
              pq.pop();
              cost+=len;
              if(pq.empty()) return cost;
              pq.push(len);
          }
          return cost;
      }
  };

