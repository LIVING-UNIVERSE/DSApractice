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



