NOTE: inorder traversal of a BST is always sorted.
//700. Search in a Binary Search Tree
Solved
1303
Easy
Topics
Companies
Amazon
You are given the root of a binary search tree (BST) and an integer val.

Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.

 

Example 1:


Input: root = [4,2,7,1,3], val = 2
Output: [2,1,3]
Example 2:


Input: root = [4,2,7,1,3], val = 5
Output: []
 

Constraints:

The number of nodes in the tree is in the range [1, 5000].
1 <= Node.val <= 107
root is a binary search tree.
1 <= val <= 107


// optimal solution
// t:O(h) sp:O(1)
class Solution {
    public:
        TreeNode* searchBST(TreeNode* root, int val) {
            while(root!=NULL && root->val!=val){
                root=(root->val>val)?root->left:root->right;
            }
            return root;
        }
};


class Solution {
    public:
        TreeNode* searchBST(TreeNode* root, int val) {
            if(root==NULL) return NULL;
            if(root->val==val) return root;
            TreeNode* left= searchBST(root->left,val);
            TreeNode* right=searchBST(root->right,val);
            if(left) return left;
            if(right) return right;
            return NULL;
        }
};



//Ceil in BST
Difficulty: MediumAccuracy: 62.73%Submissions: 133K+Points: 4Average Time: 30m
Given a BST and a number X, find Ceil of X.
Note: Ceil(X) is a number that is either equal to X or is immediately greater than X.

If Ceil could not be found, return -1.

Example 1:

Input: root = [5, 1, 7, N, 2, N, N, N, 3], X = 3
      5
    /   \
   1     7
    \
     2 
      \
       3
Output: 3
Explanation: We find 3 in BST, so ceil of 3 is 3.
Example 2:

Input: root = [10, 5, 11, 4, 7, N, N, N, N, N, 8], X = 6
     10
    /  \
   5    11
  / \ 
 4   7
      \
       8
Output: 7
Explanation: We find 7 in BST, so ceil of 6 is 7.
Your task:
You dont need to read input or print anything. Just complete the function findCeil() to implement ceil in BST which returns the ceil of X in the given BST.

Constraints:
1 <= Number of nodes <= 105
1 <= Value of nodes<= 105


// optimal solution
int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
    Node* curr=root;
    int ans=-1;
    while(curr){
        if(curr->data>input){
            ans=curr->data;
            curr=curr->left;
        }
        else if(curr->data==input){
            ans=curr->data;
            break;
        }
        else{
            curr=curr->right;
        }
    }
    return ans;
}


//Floor in BST
Difficulty: MediumAccuracy: 51.06%Submissions: 101K+Points: 4Average Time: 20m
You are given a BST(Binary Search Tree) with n number of nodes and value x. your task is to find the greatest value node of the BST which is smaller than or equal to x.
Note: when x is smaller than the smallest node of BST then returns -1.

Examples:

Input:
n = 7               2
                     \
                      81
                    /     \
                 42       87
                   \       \
                    66      90
                   /
                 45
x = 87
Output: 87
Explanation: 87 is present in tree so floor will be 87.
Input:
n = 4                     6
                           \
                            8
                          /   \
                        7       9
x = 11
Output: 9
Input:
n = 4                     6
                           \
                            8
                          /   \
                        7       9
x = 5
Output: -1
Constraint:
1 <= Noda data <= 109
1 <= n <= 105


// optimal solution
// t:O(logn) sp:O(1)
class Solution{

    public:
        int floor(Node* root, int x) {
            int res=-1;
            Node* curr=root;
            while(curr){
                if(curr->data==x){
                    res=curr->data;
                    break;
                }
                else if(curr->data>x){
                    curr=curr->left;
                }
                else{
                    res=curr->data;
                    curr=curr->right;
                }
            }
            return res;
        }
};



//701. Insert into a Binary Search Tree
Solved
1342
Medium
Topics
Companies
LinkedIn
Amazon
Goldman Sachs
You are given the root node of a binary search tree (BST) and a value to insert into the tree. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.

 

Example 1:


Input: root = [4,2,7,1,3], val = 5
Output: [4,2,7,1,3,5]
Explanation: Another accepted tree is:

Example 2:

Input: root = [40,20,60,10,30,50,70], val = 25
Output: [40,20,60,10,30,50,70,null,null,25]
Example 3:

Input: root = [4,2,7,1,3,null,null,null,null,null,null], val = 5
Output: [4,2,7,1,3,5]
 

Constraints:

The number of nodes in the tree will be in the range [0, 104].
-108 <= Node.val <= 108
All the values Node.val are unique.
-108 <= val <= 108
Its guaranteed that val does not exist in the original BST.



// optimal  solution
// t:O(h) sp:O(1)
class Solution {
    public:
        TreeNode* insertIntoBST(TreeNode* root, int val) {
            TreeNode* temp= new TreeNode(val);
            if(!root){
                return temp;
            }
            TreeNode* prev=NULL;
            TreeNode* curr=root;
            while(curr){
                prev=curr;
                if(curr->val>val) curr=curr->left;
                else{
                    curr=curr->right;
                }
            }
            if(prev->val>val) prev->left=temp;
            else{
                prev->right=temp;
            }
            return root;
        }
};



//450. Delete Node in a BST
Solved
Medium
Topics
Companies
Amazon
Microsoft
Oracle
Google
LinkedIn
Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
 

Example 1:


Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
Please notice that another valid answer is [5,2,6,null,4,null,7] and its also accepted.

Example 2:

Input: root = [5,3,6,2,4,null,7], key = 0
Output: [5,3,6,2,4,null,7]
Explanation: The tree does not contain a node with value = 0.
Example 3:

Input: root = [], key = 0
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-105 <= Node.val <= 105
Each node has a unique value.
root is a valid binary search tree.
-105 <= key <= 105
 

Follow up: Could you solve it with time complexity O(height of tree)?



// optimal solution
// t:O(h) sp:O(1)
class Solution {
    private:
        TreeNode* f(TreeNode* root){
            if(!root->left) return root->right;
            else if(!root->right) return root->left;
            TreeNode* right=root->right;
            TreeNode* temp=root->left;
            while(temp->right){
                temp=temp->right;
            }
            temp->right=right;
            return root->left;
        }
    public:
        TreeNode* deleteNode(TreeNode* root, int key) {
            if(root==NULL) return NULL;
            TreeNode* curr=root;
            while(curr){
                if(curr->val==key) break;
                else if(curr->val>key) curr=curr->left;
                else{
                    curr=curr->right;
                }
            }
            if(!curr) return root;
            if(curr==root) return f(root);
            curr=root;
            while(curr){
                if(curr->val>key){
                    if(curr->left && curr->left->val==key) curr->left=f(curr->left);
                    else{
                        curr=curr->left;
                    }
                }
                else{
                    if(curr->right && curr->right->val==key) curr->right=f(curr->right);
                    else{
                        curr=curr->right;
                    }
                }
            }
            return root;
        }
};


// optimal solution
// this is the standard solution
// t:O(h) sp:O(h)
class Solution {
    public:
        TreeNode* deleteNode(TreeNode* root, int key) {
            if(root==NULL) return NULL;
            if(root->val>key){
                root->left=deleteNode(root->left,key);
            }
            else if(root->val<key){
                root->right=deleteNode(root->right,key);
            }
            else{
                if(root->left==NULL && root->right==NULL) return NULL;
                if(!root->left) return root->right;
                if(!root->right) return root->left;
                TreeNode* temp= root->left;
                TreeNode* right=root->right;
                while(temp->right){
                    temp=temp->right;
                }
                temp->right=right;
                return root->left;
            }
            return root;
        }
    };



//230. Kth Smallest Element in a BST
Solved
Medium
Topics
Companies
Hint
Uber
Amazon
Facebook
Microsoft
LinkedIn
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

Example 1:
Input: root = [3,1,4,null,2], k = 1
Output: 1
Example 2:
Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3
Constraints:
The number of nodes in the tree is n.
1 <= k <= n <= 104
0 <= Node.val <= 104
Follow up: If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest frequently, how would you optimize?


// solution
//t:O(n) sp:O(n)
class Solution {
    private:
        TreeNode* f(TreeNode* root,int &count,int k){
            if(!root) return NULL;
            TreeNode* left = f(root->left,count,k);
            count++;
            if(count==k) return root;
            TreeNode* right=f(root->right,count,k);
            if(left || right){
                return (left)?left:right;
            }
            return NULL;
        }
    public:
        int kthSmallest(TreeNode* root, int k) {
            if(!root) return -1;
            int count=0;
            TreeNode* ans=f(root,count,k);
            return (ans)?ans->val:-1;
        }
};


// optimal solution using morris traversal
class Solution {
    public:
        int kthSmallest(TreeNode* root, int k) {
            TreeNode* curr = root;
            int count = 0;
            
            while (curr) {
                if (!curr->left) {
                    count++;
                    if (count == k) return curr->val;
                    curr = curr->right;
                } else {
                    TreeNode* temp = curr->left;
                    while (temp->right && temp->right != curr) {
                        temp = temp->right;
                    }
                    if (!temp->right) {
                        temp->right = curr;
                        curr = curr->left;
                    } else {
                        temp->right = NULL;
                        count++;
                        if (count == k) return curr->val;
                        curr = curr->right;
                    }
                }
            }
            return -1; // If k is out of range
        }
};




//235. Lowest Common Ancestor of a Binary Search Tree
Solved
Medium
Topics
Companies
LinkedIn
Facebook
Amazon
Apple
Google
Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

 

Example 1:


Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.
Example 2:


Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
Example 3:

Input: root = [2,1], p = 2, q = 1
Output: 2
 

Constraints:

The number of nodes in the tree is in the range [2, 105].
-109 <= Node.val <= 109
All Node.val are unique.
p != q
p and q will exist in the BST.



// brute force
// t:O(n) sp:O(h)
class Solution {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            if(root==NULL) return NULL;
            if(root->val==p->val || root->val==q->val) return root;
            TreeNode* left=lowestCommonAncestor(root->left,p,q);
            TreeNode* right=lowestCommonAncestor(root->right,p,q);
            if(right && left) return root;
            if(right || left){
                return (left)?left:right;
            }
            return NULL;
        }
};


// optimal solution
// t:O(h) sp:O(1)
class Solution {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            if(root==NULL) return NULL;
            if(root->val>p->val && root->val>q->val){
                return lowestCommonAncestor(root->left,p,q);
            }
            else if(root->val<p->val && root->val<q->val){
                return lowestCommonAncestor(root->right,p,q);
            }
            return root;
        }
};

// or
class Solution {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            if(p->val>q->val) return  lowestCommonAncestor(root,q,p);
            TreeNode* curr=root;
            while(curr){
                if(curr->val==p->val || curr->val==q->val) return curr;
                if(p->val<curr->val && q->val > curr->val) return curr;
                else if(p->val<curr->val || q->val<curr->val){
                    curr=curr->left;
                }
                else{
                    curr=curr->right;
                }
            }
            return NULL;
        }
};