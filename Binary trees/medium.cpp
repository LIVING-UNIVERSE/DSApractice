//104. Maximum Depth of Binary Tree
Solved
Easy
Topics
Companies
LinkedIn
Amazon
Spotify
Google
Microsoft
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 3
Example 2:

Input: root = [1,null,2]
Output: 2
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-100 <= Node.val <= 100

// solution
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    public:
        int maxDepth(TreeNode* root) {
            if(root==NULL) return 0;
            return 1+max(maxDepth(root->left),maxDepth(root->right));
        }
    };




//110. Balanced Binary Tree
Solved
Easy
Topics
Companies
Amazon
Spotify
Facebook
Google
Adobe
Given a binary tree, determine if it is height-balanced.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: true
Example 2:


Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
Example 3:

Input: root = []
Output: true
 

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-104 <= Node.val <= 104



// solution
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:

    int height(TreeNode* root){
        if(root==NULL) return 0;
        int l=height(root->left);
        int r=height(root->right);
        if(l==-1 || r==-1 || abs(l-r)>1) return -1;
        return 1+max(l,r);
    }
public:

    bool isBalanced(TreeNode* root) {
        int val=height(root);
        return (val==-1)?false:true;
    }
};




//543. Diameter of Binary Tree
Solved
Easy
Topics
Companies
Facebook
Amazon
Bloomberg
Google
Microsoft
Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

 

Example 1:


Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
Example 2:

Input: root = [1,2]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-100 <= Node.val <= 100



// solution
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:
    // if I use pass by value a copy of 'ans' will be created thus i have to use pass by refrence to update the value of 'ans';
         int f(TreeNode* root,int &ans){
            if(root==NULL) return 0;
            int lh= f(root->left,ans);
            int rh=f(root->right,ans);
            ans=max(ans,lh+rh);
            return max(lh,rh)+1;
         }
    public:
        int diameterOfBinaryTree(TreeNode* root) {
            int ans=0;
            f(root,ans);
            return ans;
        }
};



//124. Binary Tree Maximum Path Sum
Solved
Hard
Topics
Companies
DoorDash
Amazon
Facebook
Microsoft
Google
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.

 

Example 1:


Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.
Example 2:


Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
 

Constraints:

The number of nodes in the tree is in the range [1, 3 * 104].
-1000 <= Node.val <= 1000



// optimal solution
// the idea is to calculate the maximum path sum for each node and update the value of 'ans' if the sum is greater than 'ans'
// t: O(n) s: O(h) where h is the height of the tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:
        int f(TreeNode* root,int & ans){
            if(!root) return 0;
            int l= f(root->left,ans);
            int r=f(root->right,ans);
            int sum=root->val;
            if(l>=0) sum+=l;
            if(r>=0) sum+=r;
            ans=max(ans,sum);
            return max(root->val,root->val+max(l,r));
        }
    public:
        int maxPathSum(TreeNode* root) {
            int ans=-1e8;
            f(root,ans);
            return ans;
        }
};




//100. Same Tree
Solved
Easy
Topics
Companies
LinkedIn
Amazon
Google
Apple
Facebook
Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

 

Example 1:


Input: p = [1,2,3], q = [1,2,3]
Output: true
Example 2:


Input: p = [1,2], q = [1,null,2]
Output: false
Example 3:


Input: p = [1,2,1], q = [1,1,2]
Output: false
 

Constraints:

The number of nodes in both trees is in the range [0, 100].
-104 <= Node.val <= 104


// brute force solution
// t:O(n) s:O(2n)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:
        void preorder(TreeNode* root,vector<int> &arr){
            if(root==NULL){
                arr.push_back(-1e8) ; return ;
            }
            arr.push_back(root->val);
            preorder(root->left,arr);
            preorder(root->right,arr);
        }
    public:
        bool isSameTree(TreeNode* p, TreeNode* q) {
            vector<int> pa,qa;
            preorder(p,pa);
            preorder(q,qa);
            return (pa==qa);
        }
};



// optimal solution
// t:O(n) s:O(h)  <- recursion call stack
class Solution {
    public:
        bool isSameTree(TreeNode* p, TreeNode* q) {
            if(p==NULL || q==NULL){
                return (p==NULL && q==NULL);
            }
            if(p->val!=q->val) return false;
            if( isSameTree(p->left,q->left)==false) return false;
            if( isSameTree(p->right,q->right)==false) return  false;
            return true;
        }
};   


// better way of writing the above code
class Solution {
    public:
        bool isSameTree(TreeNode* p, TreeNode* q) {
            if(p==NULL || q==NULL) return (p==NULL && q==NULL);
            return (p->val==q->val && isSameTree(p->left,q->left) && isSameTree(p->right,q->right));
        }
};


