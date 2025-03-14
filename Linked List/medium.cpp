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




//2095. Delete the Middle Node of a Linked List
Solved
1324
Medium
Topics
Companies
Hint
You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.

The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.

For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.
 

Example 1:


Input: head = [1,3,4,7,1,2,6]
Output: [1,3,4,1,2,6]
Explanation:
The above figure represents the given linked list. The indices of the nodes are written below.
Since n = 7, node 3 with value 7 is the middle node, which is marked in red.
We return the new list after removing this node. 
Example 2:


Input: head = [1,2,3,4]
Output: [1,2,4]
Explanation:
The above figure represents the given linked list.
For n = 4, node 2 with value 3 is the middle node, which is marked in red.
Example 3:


Input: head = [2,1]
Output: [2]
Explanation:
The above figure represents the given linked list.
For n = 2, node 1 with value 1 is the middle node, which is marked in red.
Node 0 with value 2 is the only node remaining after removing node 1.
 

Constraints:

The number of nodes in the list is in the range [1, 105].
1 <= Node.val <= 105



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
        ListNode* deleteMiddle(ListNode* head) {
            if(head==NULL|| head->next==NULL) return NULL;
            ListNode* slow=head;
            ListNode* fast=head;
            ListNode* prev=NULL;
            while(fast!=NULL && fast->next!=NULL){
                prev=slow;
                slow=slow->next;
                fast=fast->next->next;
            }
            ListNode* temp=slow->next;
            prev->next=temp;
            delete(slow);
            return head;
        }
};




//234. Palindrome Linked List
Solved
Easy
Topics
Companies
Facebook
Amazon
Microsoft
Apple
Bloomberg
Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
 

Follow up: Could you do it in O(n) time and O(1) space?


// brute force
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
        bool isPalindrome(ListNode* head) {
            vector<int> v;
            ListNode* curr=head;
            while(curr!=NULL){
                v.push_back(curr->val);
                curr=curr->next;
            }
            vector<int> temp=v;
            reverse(temp.begin(),temp.end());
            return temp==v;
        }
};


// optimal solution
// t:O(n) s:O(1)
class Solution {
    private:
        ListNode* reverse(ListNode* head){
            ListNode* curr=head;
            ListNode* prev=NULL;
            while(curr!=NULL){
                ListNode* temp=curr->next;
                curr->next=prev;
                prev=curr;
                curr=temp;
            }
            return prev;
        }
    public:
        bool isPalindrome(ListNode* head){
            ListNode* curr=head;
            ListNode* slow=head;
            ListNode* fast=head;
            while(fast!=NULL && fast->next!=NULL){
                slow=slow->next;
                fast=fast->next->next;
            }
            ListNode* nHead= reverse(slow);
            ListNode* temp=nHead;
            while(temp!=NULL){
                if(temp->val!=curr->val)  return false;
                temp=temp->next;
                curr=curr->next;
            }
            reverse(nHead);
            return true;
        }
};




//148. Sort List
Solved
Medium
Topics
Companies
Facebook
Microsoft
Amazon
ByteDance
Apple
Given the head of a linked list, return the list after sorting it in ascending order.

 

Example 1:


Input: head = [4,2,1,3]
Output: [1,2,3,4]
Example 2:


Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is in the range [0, 5 * 104].
-105 <= Node.val <= 105
 

Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?



// brute force
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
    ListNode* sortList(ListNode* head) {
        vector<int> arr;
        ListNode* curr=head;
        while(curr!=NULL){
            arr.push_back(curr->val);
            curr=curr->next;
        }
        sort(arr.begin(),arr.end());
        curr=head;
        for(int i=0; i<arr.size();i++){
            curr->val=arr[i];
            curr=curr->next;
        }
        return head;
    }
};



// optimal solution
// t:O(nlogn) s:O(1)
class Solution {
    private:
        ListNode* findMid(ListNode* head){
            ListNode* slow=head;
            ListNode* fast=head;
            ListNode* prev=NULL;
            while(fast!=NULL && fast->next!=NULL){
                prev=slow;
                slow=slow->next;
                fast=fast->next->next;
            }
            prev->next=NULL;
            return slow;
        }
        ListNode* merge(ListNode* head,ListNode* mid){
            ListNode* prev= new ListNode(0);
            ListNode* curr=prev;
            while(head!=NULL && mid!=NULL){
                if(head->val<mid->val){
                    curr->next=head;
                    curr=curr->next;
                    head=head->next;
                }
                else{
                    curr->next=mid;
                    curr=curr->next;
                    mid=mid->next;
                }
            }
            if(head==NULL){
                curr->next=mid;
            }
            else{
                curr->next=head;
            }
            ListNode* temp=prev->next;
            delete(prev);
            return temp;
        }
        ListNode* mergeSort(ListNode* head){
            if(head==NULL || head->next==NULL) return head;
            ListNode* mid=findMid(head);
            ListNode* temp1=mergeSort(head);
            ListNode* temp2=mergeSort(mid);
            return merge(temp1,temp2);
        }    
    public:
        ListNode* sortList(ListNode* head) {
            if(head==NULL|| head->next==NULL) return head;
            return mergeSort(head);
        }
 };




//Sort a linked list of 0s, 1s and 2s
Difficulty: MediumAccuracy: 60.75%Submissions: 230K+Points: 4Average Time: 30m
Given a linked list where nodes can contain values 0s, 1s, and 2s only. The task is to segregate 0s, 1s, and 2s linked list such that all zeros segregate to the head side, 2s at the end of the linked list, and 1s in the middle of 0s and 2s.

Examples:

Input: LinkedList: 1->2->2->1->2->0->2->2
Output: 0->1->1->2->2->2->2->2
Explanation: All the 0s are segregated to the left end of the linked list, 2s to the right end of the list, and 1s in between.
 
Input: LinkedList: 2->2->0->1
Output: 0->1->2->2
Explanation: After arranging all the 0s,1s and 2s in the given format, the output will be 0 1 2 2.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(n).

Constraints:
1 <= no. of nodes <= 106
0 <= node->data <= 2



// brute force
// t:O(n) s:O(n)
/*

  Node is defined as
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
      // Function to sort a linked list of 0s, 1s and 2s.
      Node* segregate(Node* head) {
          int zCount=0;
          int oCount=0;
          int tCount=0;
          Node* curr=head;
          while(curr!=NULL){
              if(curr->data==0) zCount++;
              else if(curr->data ==1) oCount++;
              else{
                  tCount++;
              }
              curr=curr->next;
          }
          curr=head;
          while(curr!=NULL){
              if(zCount){
                  curr->data=0;zCount--;
              }
              else if(oCount){
                  curr->data=1;oCount--;
              }
              else{
                  curr->data=2;
              }
              curr=curr->next;
          }
          return head;
      }
  };

  

// optimal solution
// t:O(n) s:O(1)
class Solution {
    public:
      // Function to sort a linked list of 0s, 1s and 2s.
      Node* segregate(Node* head) {
          if(head==NULL || head->next==NULL) return head;
          Node* zero= new Node(-1);
          Node* one =new Node(-1);
          Node* two= new Node(-1);
          Node* z=zero;
          Node* o=one;
          Node* t=two;
          Node* curr=head;
          while(curr!=NULL){
              Node* temp=curr->next;
              if(curr->data==0){
                  z->next=curr;
                  z=z->next;
              }
              else if(curr->data==1){
                  o->next=curr;
                  o=o->next;
              }
              else{
                  t->next=curr;
                  t=t->next;
              }
              curr->next=NULL;
              curr=temp;
          }
          if(one->next!=NULL){
              z->next=one->next;
              if(two->next!=NULL){
                  o->next=two->next;
              }
          }
          else if(two->next!=NULL){
              z->next=two->next;
          }
          Node* nHead=zero->next;
          delete(zero);
          delete(one);
          delete(two);
          return nHead;
      }
};




//160. Intersection of Two Linked Lists
Solved
Easy
Topics
Companies
Microsoft
Amazon
LinkedIn
Facebook
Adobe
Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

For example, the following two linked lists begin to intersect at node c1:


The test cases are generated such that there are no cycles anywhere in the entire linked structure.

Note that the linked lists must retain their original structure after the function returns.

Custom Judge:

The inputs to the judge are given as follows (your program is not given these inputs):

intersectVal - The value of the node where the intersection occurs. This is 0 if there is no intersected node.
listA - The first linked list.
listB - The second linked list.
skipA - The number of nodes to skip ahead in listA (starting from the head) to get to the intersected node.
skipB - The number of nodes to skip ahead in listB (starting from the head) to get to the intersected node.
The judge will then create the linked structure based on these inputs and pass the two heads, headA and headB to your program. If you correctly return the intersected node, then your solution will be accepted.

 

Example 1:


Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Intersected at '8'
Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.
- Note that the intersected node's value is not 1 because the nodes with value 1 in A and B (2nd node in A and 3rd node in B) are different node references. In other words, they point to two different locations in memory, while the nodes with value 8 in A and B (3rd node in A and 4th node in B) point to the same location in memory.
Example 2:


Input: intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
Output: Intersected at '2'
Explanation: The intersected node's value is 2 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [1,9,1,2,4]. From the head of B, it reads as [3,2,4]. There are 3 nodes before the intersected node in A; There are 1 node before the intersected node in B.
Example 3:


Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
Output: No intersection
Explanation: From the head of A, it reads as [2,6,4]. From the head of B, it reads as [1,5]. Since the two lists do not intersect, intersectVal must be 0, while skipA and skipB can be arbitrary values.
Explanation: The two lists do not intersect, so return null.
 

Constraints:

The number of nodes of listA is in the m.
The number of nodes of listB is in the n.
1 <= m, n <= 3 * 104
1 <= Node.val <= 105
0 <= skipA <= m
0 <= skipB <= n
intersectVal is 0 if listA and listB do not intersect.
intersectVal == listA[skipA] == listB[skipB] if listA and listB intersect.
 

Follow up: Could you write a solution that runs in O(m + n) time and use only O(1) memory?


// brute force
// t:O(n+m) s:O(n+m)
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
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            unordered_set<ListNode*> s;
            ListNode* curr=headA;
            while(curr!=NULL){
                s.insert(curr);
                curr=curr->next;
            }
            curr=headB;
            while(curr!=NULL){
                if(s.find(curr)!=s.end()) return curr;
                curr=curr->next;
            }
            return NULL;
        }
};


// better 1
// t:O(n+2m) s:O(1)
class Solution {
    public:
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            ListNode* end=headA;
            while(end->next!=NULL){
                end=end->next;
            }
            end->next=headA;
            ListNode* slow=headB;
            ListNode* fast=headB;
            while(fast!=NULL && fast->next!=NULL){
                slow=slow->next;
                fast=fast->next->next;
                if(slow==fast){
                    break;
                }
            }
            if(fast==NULL || fast->next==NULL){
                end->next=NULL;
                return NULL;
            }
            ListNode* curr=headB;
            while(curr!=slow){
                curr=curr->next;
                slow=slow->next;
            }
            end->next=NULL;
            return slow;
        }
};



// better solution 2
// t:O(n+2m) s:O(1)
class Solution {
    private:
        int count(ListNode* head){
            int count=0;
            while(head!=NULL){
                count++;
                head=head->next;
            }
            return count;
        }
    public:
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            int lenA=count(headA),lenB=count(headB);
            if(lenB>lenA) return getIntersectionNode(headB,headA);
            while(lenA>lenB){
                headA=headA->next;
                lenA--;
            }
            while(headA!=NULL){
                if(headA==headB) return headA;
                headA=headA->next;
                headB=headB->next;
            }
            return NULL;
        }
};



// better solution
// t:O(n+m) s:O(1)
class Solution {
    public:
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            ListNode* currA=headA;
            ListNode* currB=headB;
            while(currA!=currB){
                if(currA->next==NULL && currB->next==NULL) return NULL;
                currA=(currA->next==NULL)?headB:currA->next;
                currB=(currB->next==NULL)?headA:currB->next;
            }
            return currA;
        }
};




//Add 1 to a Linked List Number
Difficulty: MediumAccuracy: 31.91%Submissions: 299K+Points: 4Average Time: 20m
You are given a linked list where each element in the list is a node and have an integer data. You need to add 1 to the number formed by concatinating all the list node numbers together and return the head of the modified linked list. 

Note: The head represents the first element of the given array.

Examples :

Input: LinkedList: 4->5->6
Output: 457

Explanation: 4->5->6 represents 456 and when 1 is added it becomes 457. 
Input: LinkedList: 1->2->3
Output: 124
 
Explanation:  1->2->3 represents 123 and when 1 is added it becomes 124. 
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= len(list) <= 105
0 <= list[i] <= 9



// brute force
// t:O(3n) s:O(1)

// User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
    private:
      Node* reverse(Node* head){
          Node* prev=NULL;
          Node* curr=head;
          while(curr!=NULL){
              Node* temp=curr->next;
              curr->next=prev;
              prev=curr;
              curr=temp;
          }
          return prev;
      }
    public:
      Node* addOne(Node* head) {
          bool carry=true;
          Node* nHead=reverse(head);
          Node* curr=nHead;
          Node* prev=NULL;
          while(curr!=NULL){
              prev=curr;
              if(carry){
                  if(curr->data+1>=10){
                      curr->data=0;
                  }
                  else{
                      curr->data=curr->data+1;
                      carry=false;
                  }
              }
              curr=curr->next;
          }
          if(carry){
              Node* msb= new Node(1);
              prev->next=msb;
              prev=prev->next;
          }
          return reverse(nHead);
      }
};


// optimal solution
// t:O(n) s:O(1)
// using backtracking
class Solution {
    private:
      int f(Node* head){
          if(head==NULL) return 1;
          int carry=f(head->next);
          if(head->data+carry>=10){
              head->data=0;return 1;
          }
          head->data=head->data+carry;
          return 0;
      }
    public:
      Node* addOne(Node* head) {
          int carry=f(head);
          if(carry){
              Node* nHead= new Node(1);
              nHead->next=head;
              return nHead;
          }
          return head;
      }
};




// 2. Add Two Numbers
Solved
Medium
Topics
Companies
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.



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
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* curr1=l1;
            ListNode* curr2=l2;
            ListNode* newHead= new ListNode(-1);
            ListNode* temp=newHead;
            int carry=0;
            while(curr1!=NULL || curr2!=NULL){
                int sum=carry;
                if(curr1){
                    sum+=curr1->val;
                    curr1=curr1->next;
                }
                if(curr2){
                    sum+=curr2->val;
                    curr2=curr2->next;
                }
                ListNode* create= new ListNode(sum%10);
                carry=sum/10;
                temp->next=create;
                temp=temp->next;
            }
            if(carry){
                ListNode* one = new ListNode(1);
                temp->next=one;
            }
            return newHead->next;
        }
};



//Merge two sorted linked lists
Difficulty: MediumAccuracy: 62.91%Submissions: 183K+Points: 4Average Time: 30m
Given the head of two sorted linked lists consisting of nodes respectively. The task is to merge both lists and return the head of the sorted merged list.

Examples:

Input: head1 = 5 -> 10 -> 15 -> 40, head2 = 2 -> 3 -> 20
Output: 2 -> 3 -> 5 -> 10 -> 15 -> 20 -> 40
Explanation:

Input: head1 = 1 -> 1, head2 = 2 -> 4
Output: 1 -> 1 -> 2 -> 4
Explanation:

Constraints:
1 <= no. of nodes<= 103
0 <= node->data <= 105


// solution
/* Link list Node
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
      Node* sortedMerge(Node* head1, Node* head2) {
          Node* dummy= new Node(-1);
          Node* temp=dummy;
          Node* curr1= head1;
          Node* curr2= head2;
          while(curr1!=NULL && curr2!=NULL){
              if(curr1->data < curr2->data){
                  temp->next=curr1;
                  curr1=curr1->next;
              }
              else{
                  temp->next=curr2;
                  curr2=curr2->next;
              }
              temp=temp->next;
          }
          temp->next=(curr1)?curr1:curr2;
          return dummy->next;
      }
};


//Find pairs with given sum in doubly linked list
Difficulty: EasyAccuracy: 66.01%Submissions: 74K+Points: 2Average Time: 10m
Given a sorted doubly linked list of positive distinct elements, the task is to find pairs in a doubly-linked list whose sum is equal to given value target.

 

Example 1:

Input:  
1 <-> 2 <-> 4 <-> 5 <-> 6 <-> 8 <-> 9
target = 7
Output: (1, 6), (2,5)
Explanation: We can see that there are two pairs 
(1, 6) and (2,5) with sum 7.
 

Example 2:

Input: 
1 <-> 5 <-> 6
target = 6
Output: (1,5)
Explanation: We can see that there is one pairs  (1, 5) with sum 6.

 

Your Task:
You dont need to read input or print anything. Your task is to complete the function findPairsWithGivenSum() which takes head node of the doubly linked list and an integer target as input parameter and returns an array of pairs. If there is no such pair return empty array.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
Constraints:
1 <= N <= 105
1 <= target <= 105


// brute force
// t:O(n) s:O(n)

//User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target){
        vector<pair<int,int>> v;
        unordered_set<int> s;
        Node* curr= head;
        while(curr!=NULL){
            if(s.find(target-curr->data)!=s.end()){
                v.push_back({target-curr->data,curr->data});
            }
            s.insert(curr->data);
            curr=curr->next;
        }
        reverse(v.begin(),v.end());
        return v;
    }
};



// optimal solution
class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target){
        if(head==NULL|| head->next==NULL) return {};
        Node* tail=head;
        while(tail->next!=NULL){
            tail=tail->next;
        }
        Node* curr=head;
        vector<pair<int,int>> v;
        while(curr!=tail && curr->prev!=tail){
            if(curr->data+tail->data==target){
                v.push_back({curr->data,tail->data});
                curr=curr->next;
                tail=tail->prev;
            }
            else if(curr->data+tail->data>target){
                tail=tail->prev;
            }
            else{
                curr=curr->next;
            }
        }
        return v;
    }
};