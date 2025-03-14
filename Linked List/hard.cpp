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