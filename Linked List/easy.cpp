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