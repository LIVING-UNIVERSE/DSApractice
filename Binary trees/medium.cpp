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