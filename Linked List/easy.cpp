//Array to Linked List
Difficulty: EasyAccuracy: 66.76%Submissions: 82K+Points: 2Average Time: 10m
Given an array of integer arr. Your task is to construct the linked list from arr & return the head of the linked list.

Examples:

Input: arr = [1, 2, 3, 4, 5]
Output: LinkedList: 1->2->3->4->5
Explanation: Linked list for the given array will be

Input: arr = [2, 4, 6, 7, 5, 1, 0]
Output: LinkedList: 2->4->6->7->5->1->0
Explanation: Linked list for the given array will be

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 <= arr.size() <= 106
1 <= arr[i] <= 106


// solution
/*class Node {
public:
    int data;
    Node* next;

    // Default constructor
    Node()
    {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};*/

class Solution {
    public:
      Node* constructLL(vector<int>& arr) {
          int n=arr.size();
          Node* head =new Node(arr[0]);
          Node* prev=head;
          for(int i=1; i<n; i++){
              Node *curr= new Node(arr[i]);
              prev->next=curr;
              prev=curr;
          }
          return head;
      }
  };




//Linked List Insertion At End
Difficulty: BasicAccuracy: 43.96%Submissions: 327K+Points: 1Average Time: 20m
Given the head of a Singly Linked List and a value x, insert that value x at the end of the LinkedList and return the modified Linked List.

Examples :

Input: LinkedList: 1->2->3->4->5 , x = 6
Output: 1->2->3->4->5->6
Explanation: 

We can see that 6 is inserted at the end of the linkedlist.
Input: LinkedList: 5->4 , x = 1
Output: 5->4->1
Explanation: 

We can see that 1 is inserted at the end of the linkedlist.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
0 <= number of nodes <= 105
1 <= node->data , x <= 103


// solution
/*Structure of the linked list node is as
struct Node {
  int data;
  struct Node * next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

class Solution {
    public:
      Node *insertAtEnd(Node *head, int x) {
          Node *temp= new Node(x);
          if(head == NULL) return temp;
          Node* curr=head;
          while(curr->next!=NULL){
              curr=curr->next;
          }
          curr->next=temp;
          return head;
      }
  };





//237. Delete Node in a Linked List
Solved
Medium
Topics
Companies
Microsoft
Amazon
There is a singly-linked list head and we want to delete a node node in it.

You are given the node to be deleted node. You will not be given access to the first node of head.

All the values of the linked list are unique, and it is guaranteed that the given node node is not the last node in the linked list.

Delete the given node. Note that by deleting the node, we do not mean removing it from memory. We mean:

The value of the given node should not exist in the linked list.
The number of nodes in the linked list should decrease by one.
All the values before node should be in the same order.
All the values after node should be in the same order.
Custom testing:

For the input, you should provide the entire linked list head and the node to be given node. node should not be the last node of the list and should be an actual node in the list.
We will build the linked list and pass the node to your function.
The output will be the entire list after calling your function.
 

Example 1:


Input: head = [4,5,1,9], node = 5
Output: [4,1,9]
Explanation: You are given the second node with value 5, the linked list should become 4 -> 1 -> 9 after calling your function.
Example 2:


Input: head = [4,5,1,9], node = 1
Output: [4,5,9]
Explanation: You are given the third node with value 1, the linked list should become 4 -> 5 -> 9 after calling your function.
 

Constraints:

The number of the nodes in the given list is in the range [2, 1000].
-1000 <= Node.val <= 1000
The value of each node in the list is unique.
The node to be deleted is in the list and is not a tail node.


// solution
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    public:
        void deleteNode(ListNode* node) {
            node->val=node->next->val;
            node->next=node->next->next;
        }
    };







//Search in Linked List
Difficulty: EasyAccuracy: 65.4%Submissions: 92K+Points: 2Average Time: 10m
Given a linked list of n nodes and a key, the task is to check if the key is present in the linked list or not.

Example:

Input: n = 4, key = 3
1->2->3->4
Output: true
Explanation: 3 is present in Linked List, so the function returns true.
Constraint:
1 <= n <= 105
1 <= key <= 105

// solution
/* Link list node */
/*
struct Node
{
    int data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
}; */

class Solution {
    public:
      // Function to count nodes of a linked list.
      bool searchKey(int n, Node* head, int key) {
          Node * curr=head;
          while(n--){
              if(curr->data==key) return true;
              curr=curr->next;
          }
          return false;
      }
};
  



//Introduction to Doubly Linked List
Difficulty: EasyAccuracy: 76.51%Submissions: 57K+Points: 2Average Time: 15m
Geek is learning data structures and is familiar with linked lists, but he's curious about how to access the previous element in a linked list in the same way that we access the next element. His teacher explains doubly linked lists to him.

Given an integer array arr of size n. Construct the doubly linked list from arr and return the head of it.

Example 1:

Input:
n = 5
arr = [1,2,3,4,5]
Output:
1 2 3 4 5
Explanation: Linked list for the given array will be 1<->2<->3<->4<->5.
Example 2:

Input:
n = 1
arr = [1]
Output:
1
Explanation: Linked list for the given array will be 1.
Constraints:
1 <= n <= 105
1 <= arr[i] <= 100

Your Task:
You dont need to read input or print anything. Your task is to complete the function constructDLL() which takes arr[] as input parameters and returns the head of the Linked List.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)


// solution
// User function Template for C++

/*
class Node{
public:
    Node* prev;
    int data;
    Node* next;

    Node()
    {
        prev = NULL;
        data = 0;
        next = NULL;
    }

    Node(int value)
    {
        prev = NULL;
        data = value;
        next = NULL;
    }
};*/

class Solution {
    public:
      Node* constructDLL(vector<int>& arr) {
          Node* head = new Node(arr[0]);
          Node* temp=head;
          for(int i=1; i<arr.size(); i++){
              Node* node = new Node(arr[i]);
              temp->next=node;
              node->prev=temp;
              temp=node;
          }
          return head;
      }
};






//Doubly linked list Insertion at given position
Difficulty: BasicAccuracy: 47.13%Submissions: 150K+Points: 1Average Time: 20m
Given a doubly-linked list, a position p, and an integer x. The task is to add a new node with value x at the position just after pth node in the doubly linked list and return the head of the updated list.

Examples:

Input: LinkedList: 2<->4<->5, p = 2, x = 6 
Output: 2<->4<->5<->6
Explanation: p = 2, and x = 6. So, 6 is inserted after p, i.e, at position 2 (0-based indexing).
Input: LinkedList: 1<->2<->3<->4, p = 0, x = 44
Output: 1<->44<->2<->3<->4
Explanation: p = 0, and x = 44 . So, 44 is inserted after p, i.e, at position 0 (0-based indexing).
Constraints:
0 <= p < size of doubly linked list <= 106
1 <= x <= 106


// solution
/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

// Function to insert a new node at given position in doubly linked list.
class Solution {
    public:
      // Function to insert a new node at given position in doubly linked list.
      Node *addNode(Node *head, int pos, int data) {
          Node* temp= new Node(data);
          if(head == NULL) return temp;
          Node* curr=head;
          for(int i=0; i<pos; i++){
              curr=curr->next;
          }
          if(curr->next!=NULL){
              Node* temp1=curr->next;
              temp->next=temp1;
              temp1->prev=temp;
          }
          curr->next=temp;
          temp->prev=curr;
          return head;
      }
};




//Delete in a Doubly Linked List
Difficulty: EasyAccuracy: 42.98%Submissions: 184K+Points: 2Average Time: 40m
Given a Doubly Linked list and a position. The task is to delete a node from a given position (position starts from 1) in a doubly linked list and return the head of the doubly Linked list.

Examples:

Input: LinkedList = 1 <--> 3 <--> 4, x = 3
Output: 1 <--> 3
Explanation: After deleting the node at position 3 (position starts from 1),the linked list will be now as 1 <--> 3.
 
Input: LinkedList = 1 <--> 5 <--> 2 <--> 9, x = 1
Output: 5 <--> 2 <--> 9
Explanation:

Constraints:
2 <= size of the linked list <= 106
1 <= x <= size of the linked list 
1 <= node->data <= 104

// solution
/* Structure of Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

class Solution {
    public:
      // Function to delete a node at given position.
      Node* deleteNode(Node* head, int x) {
          if(x==1){
              Node* temp=head->next;
              temp->prev=NULL;
              return temp;
          }
          Node* curr=head;
          while(x>1){
              curr=curr->next;
              x--;
          }
          Node* pre=curr->prev;
          Node* post=curr->next;
          pre->next=post;
          if(post){
              post->prev=pre;
          }
          delete(curr);
          return head;
      }
};



//Reverse a Doubly Linked List
Difficulty: EasyAccuracy: 70.38%Submissions: 170K+Points: 2Average Time: 15m
Given a doubly linked list. Your task is to reverse the doubly linked list and return its head.

Examples:

Input: LinkedList: 3 <-> 4 <-> 5
Output: 5 <-> 4 <-> 3

Input: LinkedList: 75 <-> 122 <-> 59 <-> 196
Output: 196 <-> 59 <-> 122 <-> 75

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(1).

Constraints:
1 <= number of nodes <= 106
0 <= node->data <= 104



// solution
/*
class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/
class Solution {
    public:
      // Function to reverse a doubly linked list
      DLLNode* reverseDLL(DLLNode* head) {
         DLLNode* pre=NULL;
         DLLNode* post=NULL;
         DLLNode* curr=head;
         DLLNode* prev=NULL;
         while(curr!=NULL){
             prev=curr;
             pre=(curr->prev)?curr->prev:NULL;
             post=(curr->next)?curr->next:NULL;
             curr->prev=post;
             curr->next=pre;
             curr=curr->prev;
         }
         return prev;
      }
  };