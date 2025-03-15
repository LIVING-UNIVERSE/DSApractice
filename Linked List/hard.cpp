//25. Reverse Nodes in k-Group
Solved
Hard
Topics
Companies
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the lists nodes, only nodes themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
Example 2:


Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
 

Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 5000
0 <= Node.val <= 1000
 

Follow-up: Can you solve the problem in O(1) extra memory space?


// solution
// t:O(n) s:O(1)
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
        int len(ListNode* head){
            int count=0;
            while(head!=NULL){
                count++;head=head->next;
            }
            return count;
        }
        void reverse(ListNode* head,ListNode* tail){
            ListNode* curr=head;
            ListNode* prev=NULL;
            while(curr!=tail){
                ListNode* temp=curr->next;
                curr->next=prev;
                prev=curr;
                curr=temp;
            }
            curr->next=prev;
        }
    public:
        ListNode* reverseKGroup(ListNode* head, int k) {
            ListNode* dummy = new ListNode(-1);
            ListNode* temp=dummy;
            int length = len(head);
            ListNode* curr=head;
            while(length>=k){
                ListNode* begin=curr;
                int val=k-1;
                while(val--){
                    curr=curr->next;
                }
                ListNode* end=curr;
                curr=curr->next;
                reverse(begin,end);
                temp->next=end;
                temp=begin;
                length-=k;
            }
            temp->next=curr;
            return dummy->next;
        }
};



//61. Rotate List
Solved
Medium
Topics
Companies
Microsoft
Bloomberg
Given the head of a linked list, rotate the list to the right by k places.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:


Input: head = [0,1,2], k = 4
Output: [2,0,1]
 

Constraints:

The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109


// solution
// t:O(n) s:O(1)
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
        int len(ListNode* head){
            int count=0;
            while(head!=NULL){
                count++;head=head->next;
            }
            return count;
        }
    public:
        ListNode* rotateRight(ListNode* head, int k) {
            if(head==NULL) return NULL;
            int length=len(head);
            k=k%length;
            if(k==0) return head;
            ListNode* curr= head;
            int val=length-k-1;
            while(val--){
                curr=curr->next;
            }
            ListNode* newHead=curr->next;
            curr->next=NULL;
            curr=newHead;
            while(curr->next!=NULL){
                curr=curr->next;
            }
            curr->next=head;
            return newHead;
        }
};




//Flattening a Linked List
Difficulty: MediumAccuracy: 51.53%Submissions: 178K+Points: 4Average Time: 40m
Given a linked list containing n head nodes where every node in the linked list contains two pointers:
(i) next points to the next node in the list.
(ii) bottom pointer to a sub-linked list where the current node is the head.
Each of the sub-linked lists nodes and the head nodes are sorted in ascending order based on their data.
Your task is to flatten the linked list such that all the nodes appear in a single level while maintaining the sorted order.

Note:
1. ↓ represents the bottom pointer and -> represents the next pointer.
2. The flattened list will be printed using the bottom pointer instead of the next pointer.

Examples:

Input:

Output: 5-> 7-> 8-> 10 -> 19-> 20-> 22-> 28-> 30-> 35-> 40-> 45-> 50.
Explanation: 
Bottom pointer of 5 is pointing to 7.
Bottom pointer of 7 is pointing to 8.
Bottom pointer of 8 is pointing to 10 and so on.
Input:
 
Output: 5-> 7-> 8-> 10-> 19-> 22-> 28-> 30-> 50
Explanation:
Bottom pointer of 5 is pointing to 7.
Bottom pointer of 7 is pointing to 8.
Bottom pointer of 8 is pointing to 10 and so on.
Constraints:
0 <= n <= 100
1 <= number of nodes in sub-linked list(mi) <= 50
1 <= node->data <= 104


// brute force
// t:O(n^2) s:O(n)
/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
    public:
      // Function which returns the  root of the flattened linked list.
      Node *flatten(Node *root) {
          priority_queue<int,vector<int>,greater<int>> pq;
          Node* curr= root;
          while(curr!=NULL){
              Node* temp=curr;
              while(temp!=NULL){
                  pq.push(temp->data);
                  temp=temp->bottom;
              }
              curr=curr->next;
          }
          Node* dummy= new Node(-1);
          Node* temp= dummy;
          while(!pq.empty()){
              Node* create= new Node(pq.top());
              temp->bottom=create;
              temp=temp->bottom;
              pq.pop();
          }
          return dummy->bottom;
      }
  };



// optimal  solution
class Solution{
    private:
      Node* merge(Node* headA,Node* headB){
          Node* curr1=headA;
          Node* curr2=headB;
          Node* dummy= new Node(-1);
          Node* dum= dummy;
          while(curr1!=NULL && curr2!=NULL){
              if(curr1->data<curr2->data){
                  dum->bottom=curr1;
                  curr1=curr1->bottom;
              }
              else{
                  dum->bottom=curr2;
                  curr2=curr2->bottom;
              }
              dum=dum->bottom;
          }
          dum->bottom=(curr1)?curr1:curr2;
          Node* newHead= dummy->bottom;
          delete(dummy);
          return newHead;
      }
    public:
      // Function which returns the  root of the flattened linked list.
      Node *flatten(Node *head) {
          Node* curr=head;
          while(curr->next){
              Node* post=curr->next->next;
              curr=merge(curr,curr->next);
              curr->next=post;
          }
          return curr;
      }
};
  