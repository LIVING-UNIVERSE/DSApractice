//Root to Leaf Paths
Difficulty: MediumAccuracy: 43.65%Submissions: 134K+Points: 4Average Time: 30m
Given a Binary Tree, you need to find all the possible paths from the root node to all the leaf nodes of the binary tree.

Note: The paths should be returned such that paths from the left subtree of any node are listed first, followed by paths from the right subtree.

Examples:

Input: root[] = [1, 2, 3, 4, 5]
ex-3
Output: [[1, 2, 4], [1, 2, 5], [1, 3]] 
Explanation: All possible paths: 1->2->4, 1->2->5 and 1->3
Input: root[] = [1, 2, 3]
       1
    /     \
   2       3
Output: [[1, 2], [1, 3]] 
Explanation: All possible paths: 1->2 and 1->3
Input: root[] = [10, 20, 30, 40, 60]
         10
       /    \
      20    30
     /  \
    40   60
Output: [[10, 20, 40], [10, 20, 60], [10, 30]]
Explanation: All possible paths: 10->20 ->40, 10->20->60 and 10->30
Constraints:
1<=number of nodes<=104
1<=node->data<=104



// optimal solution
// t:O(n) sp:O(h)
/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
    private:
      void f(Node* root,vector<int> &v,vector<vector<int>> &ans){
          if(root->left==NULL && root->right==NULL){
              v.push_back(root->data);
              ans.push_back(v);
              v.pop_back();
              return ;
          }
          v.push_back(root->data);
          if(root->left) f(root->left,v,ans);
          if(root->right) f(root->right,v,ans);
          v.pop_back();
      }
    public:
      vector<vector<int>> Paths(Node* root) {
          vector<vector<int>> ans;
          if(!root) return ans;
          vector<int> v;
          f(root,v,ans);
          return ans;
      }
  };
  




// 236. Lowest Common Ancestor of a Binary Tree
Solved
Medium
Topics
Companies
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

 

Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
Example 2:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
Example 3:

Input: root = [1,2], p = 1, q = 2
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [2, 105].
-109 <= Node.val <= 109
All Node.val are unique.
p != q
p and q will exist in the tree.



// brute force
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    private:
        bool f(TreeNode* root,TreeNode* target,vector<TreeNode*> & v){
            if(!root) return false;
            if(root==target){
                v.push_back(root);return true;
            }
            bool l=f(root->left,target,v);
            bool r=f(root->right,target,v);
            if(l||r){
                v.push_back(root);return true;
            }
            return false;
        }
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            vector<TreeNode*> vp;
            vector<TreeNode*> vq;
            f(root,p,vp);
            f(root,q,vq);
            int i=vp.size()-1,j=vq.size()-1;
            TreeNode* temp=NULL;
            while(i>=0 && j>=0){
                if(vp[i]==vq[j]){
                    temp=vp[i];i--;j--;
                }
                else{
                    break;
                }
            }
            return temp;
        }
};



// optimal solution
class Solution {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
           if(root==p || root==q || root==NULL) return root;
           TreeNode* l=lowestCommonAncestor(root->left,p,q);
           TreeNode* r=lowestCommonAncestor(root->right,p,q);
           if(l && r) return root;
           if(l) return l;
           if(r) return r;
           return NULL;
        }
};



//Children Sum in a Binary Tree
Difficulty: MediumAccuracy: 51.58%Submissions: 188K+Points: 4Average Time: 20m
Given a binary tree having n nodes. Check whether all of its nodes have a value equal to the sum of their child nodes. Return 1 if all the nodes in the tree satisfy the given properties, else it returns 0. For every node, the data value must be equal to the sum of the data values in the left and right children. Consider the data value 0 for a NULL child. Also, leaves are considered to follow the property.

Examples:

Input:
Binary tree
       35
      /  \
     20   15
    / \   / \
   15  5 10  5

Output: 1
Explanation: 
Here, every node is sum of its left and right child.
Input:
Binary tree
       1
     /   \
    4     3
   /  
  5    
Output: 0
Explanation: 
Here, 1 is the root node and 4, 3 are its child nodes. 4 + 3 = 7 which is not equal to the value of root node. Hence, this tree does not satisfy the given condition.
Input:
Binary tree
       10
      /  \
     4    6
    / \  / \
   1   3 2  4

Output: 1
Explanation: 
Here, every node is a sum of its left and right child.
Constraints:
1 <= number of nodes <= 105
0 <= node->data <= 105



// optimal solution
// t:O(n) sp:O(h)
class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root){
        if(root==NULL) return 1;
        if(root->left==NULL && root->right==NULL) return 1;
        int l=isSumProperty(root->left);
        int r=isSumProperty(root->right);
        if(l==0 || r==0) return 0;
        int lval=(root->left)?root->left->data:0;
        int rval=(root->right)?root->right->data:0;
        return (lval+rval==root->data);
    }
};



// if we have to make a binary tree to follow child sum property and we can only increse node value then
// optimal solution
class Solution {
    public:
        void f(Node* root) {
            if (root == NULL) return;
            if (root->left == NULL && root->right == NULL) return;
    
            int lval = (root->left) ? root->left->data : 0;
            int rval = (root->right) ? root->right->data : 0;
    
            if (lval + rval < root->data) {
                if (root->left) root->left->data = root->data;
                if (root->right) root->right->data = root->data;
            }
    
            f(root->left);
            f(root->right);
    
            // Ensure parent node holds the sum of its children
            int sum = 0;
            if (root->left) sum += root->left->data;
            if (root->right) sum += root->right->data;
            root->data = sum;
        }
    };
    