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
