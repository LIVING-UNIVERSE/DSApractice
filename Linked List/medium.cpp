//876. Middle of the Linked List
Solved
Easy
Topics
Companies
Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.
Example 2:


Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
 

Constraints:

The number of nodes in the list is in the range [1, 100].
1 <= Node.val <= 100



// solution
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
    public:
        ListNode* middleNode(ListNode* head) {
            ListNode* slow=head;
            ListNode* fast=head;
            while(fast!=NULL && fast->next!=NULL){
                slow=slow->next;
                fast=fast->next->next;
            }
            return slow;
        }
};





//206. Reverse Linked List
Solved
Easy
Topics
Companies
Amazon
Microsoft
Apple
Bloomberg
Facebook
Given the head of a singly linked list, reverse the list, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
Example 2:


Input: head = [1,2]
Output: [2,1]
Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000
 

Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?



// iterative solution
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
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return NULL;
        ListNode *prev=head;
        ListNode* curr=head->next;
        head->next=NULL;
        while(curr!=NULL){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
};




class Solution {
    private:
        ListNode* f(ListNode* node,ListNode* prev){
            if(node==NULL) return prev;
            ListNode* temp=node->next;
            node->next=prev;
            return f(temp,node);
        }
    public:
        ListNode* reverseList(ListNode* head) {
            return f(head,NULL);
        }
};





//141. Linked List Cycle
Solved
Easy
Topics
Companies
Amazon
Spotify
Microsoft
Oracle
Visa
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tails next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

 

Example 1:


Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
Example 2:


Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.
Example 3:


Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.
 

Constraints:

The number of the nodes in the list is in the range [0, 104].
-105 <= Node.val <= 105
pos is -1 or a valid index in the linked-list.
 

Follow up: Can you solve it using O(1) (i.e. constant) memory?



// brute force
// t:O(n) s:O(n)
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
        bool hasCycle(ListNode *head) {
            unordered_set<ListNode*> s;
            while(head!=NULL){
                if(s.find(head)!=s.end()) return true;
                s.insert(head);
                head=head->next;
            }
            return false;
        }
};



// optimal solution
// t:O(n) s:O(1)
class Solution {
    public:
        bool hasCycle(ListNode *head) {
            ListNode* slow=head;
            ListNode* fast=head;
            while(fast!=NULL && fast->next!=NULL){
                slow=slow->next;
                fast=fast->next->next;
                if(slow==fast) return true;
            }
            return false;
        }
};





//142. Linked List Cycle II
Solved
Medium
Topics
Companies
Amazon
Microsoft
Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tails next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.

 

Example 1:


Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
Example 2:


Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.
Example 3:


Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.
 

Constraints:

The number of the nodes in the list is in the range [0, 104].
-105 <= Node.val <= 105
pos is -1 or a valid index in the linked-list.
 

Follow up: Can you solve it using O(1) (i.e. constant) memory?



// brute force
// t:O(n) s:O(n)
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
        ListNode *detectCycle(ListNode *head) {
            unordered_set<ListNode*> s;
            while(head!=NULL){
                if(s.find(head)!=s.end()) return head;
                s.insert(head);
                head=head->next;
            }
            return NULL;
        }
};

// optimal solution
// t:O(n) s:O(1)
class Solution {
    public:
        ListNode *detectCycle(ListNode *head) {
            ListNode* slow=head;
            ListNode* fast=head;
            while(fast!=NULL && fast->next!=NULL){
                slow=slow->next;
                fast=fast->next->next;
                if(fast==slow) break;
            }
            if(fast==NULL || fast->next == NULL) return NULL;
            ListNode* curr= head;
            while(curr!=slow){
                curr=curr->next;
                slow=slow->next;
            }
            return curr;
        }
};




//Find length of Loop
Difficulty: EasyAccuracy: 44.26%Submissions: 237K+Points: 2Average Time: 30m
Given the head of a linked list, determine whether the list contains a loop. If a loop is present, return the number of nodes in the loop, otherwise return 0.



Note: 'c' is the position of the node which is the next pointer of the last node of the linkedlist. If c is 0, then there is no loop.

Examples:

Input: LinkedList: 25->14->19->33->10->21->39->90->58->45, c = 4
Output: 7
Explanation: The loop is from 33 to 45. So length of loop is 33->10->21->39-> 90->58->45 = 7. 
The number 33 is connected to the last node of the linkedlist to form the loop because according to the input the 4th node from the beginning(1 based indexing) 
will be connected to the last node for the loop.
 
Input: LinkedList: 5->4, c = 0
Output: 0
Explanation: There is no loop.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= no. of nodes <= 106
0 <= node.data <=106
0 <= c<= n-1


// solution
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
    public:
      // Function to find the length of a loop in the linked list.
      int countNodesinLoop(Node *head) {
          int count=0;
          unordered_map<Node*,int> m;
          while(head!=NULL){
              if(m.find(head)!=m.end()) return count-m[head];
              m[head]=count;count++;
              head=head->next;
          }
          return 0;
      }
  };


// optimal solution
class Solution {
    public:
      // Function to find the length of a loop in the linked list.
      int countNodesinLoop(Node *head) {
          Node* slow=head;
          Node* fast=head;
          while(fast!=NULL && fast->next!=NULL){
              slow=slow->next;
              fast=fast->next->next;
              if(slow==fast) break;
          }
          if(fast==NULL || fast->next==NULL) return 0;
          int count=1;
          slow=slow->next;
          while(slow!=fast){
              slow=slow->next;
              count++;
          }
          return count;
      }
};



//19. Remove Nth Node From End of List
Solved
Medium
Topics
Companies
Hint
Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
 

Follow up: Could you do this in one pass?


// solution
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
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast=head;
        for(int i=0; i<n-1; i++){
            fast=fast->next;
        }
        ListNode* slow=head;
        ListNode* prev=NULL;
        while(fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next;
        }
        ListNode*temp=slow->next;
        if(prev!=NULL){
            prev->next=temp;
        }
        else{
            return temp;
        }
        delete(slow);
        return head;
    }
};





//328. Odd Even Linked List
Solved
Medium
Topics
Companies
Facebook
Amazon
Adobe
eBay
tiktok
Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]
Example 2:


Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]
 

Constraints:

The number of nodes in the linked list is in the range [0, 104].
-106 <= Node.val <= 106




// solution
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
    public:
        ListNode* oddEvenList(ListNode* head) {
            if(head==NULL) return NULL;
            if(head->next==NULL || head->next->next==NULL) return head;
            ListNode*even=head->next;
            ListNode* low=head;
            ListNode* high=head->next;
            while(high!=NULL && high->next!=NULL){
                low->next=high->next;
                low=low->next;
                high->next=low->next;
                high=high->next;
            }
            low->next=even;
            return head;
        }
};