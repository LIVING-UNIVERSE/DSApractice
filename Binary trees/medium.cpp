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





//103. Binary Tree Zigzag Level Order Traversal
Solved
Medium
Topics
Companies
Amazon
Facebook
Microsoft
Bloomberg
Google
Given the root of a binary tree, return the zigzag level order traversal of its nodes values. (i.e., from left to right, then right to left for the next level and alternate between).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100



// optimal solution
// t:O(n) s:O(n)
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        bool flag=true;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int> v(size);
            for(int i=0;i<size;i++){
                TreeNode* temp=q.front();
                q.pop();
                int ind=(flag)?i:size-i-1;
                v[ind]=temp->val;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            ans.push_back(v);
            flag=(!flag);
        }
        return ans;
    }
};




//Tree Boundary Traversal
Difficulty: MediumAccuracy: 23.33%Submissions: 447K+Points: 4Average Time: 35m
Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

Left Boundary: This includes all the nodes on the path from the root to the leftmost leaf node. You must prefer the left child over the right child when traversing. Do not include leaf nodes in this section.

Leaf Nodes: All leaf nodes, in left-to-right order, that are not part of the left or right boundary.

Reverse Right Boundary: This includes all the nodes on the path from the rightmost leaf node to the root, traversed in reverse order. You must prefer the right child over the left child when traversing. Do not include the root in this section if it was already included in the left boundary.

Note: If the root doesnt have a left subtree or right subtree, then the root itself is the left or right boundary. 

Examples:

Input: root[] = [1, 2, 3, 4, 5, 6, 7, N, N, 8, 9, N, N, N, N]
Output: [1, 2, 4, 8, 9, 6, 7, 3]
Explanation:

Input: root[] = [1, 2, N, 4, 9, 6, 5, N, 3, N, N, N, N 7, 8]
Output: [1, 2, 4, 6, 5, 7, 8]
Explanation:

As the root doesnt have a right subtree, the right boundary is not included in the traversal.
Input: root[] = [1, N, 2, N, 3, N, 4, N, N] 
    1
     \
      2
       \
        3
         \
          4

Output: [1, 4, 3, 2]
Explanation:
Left boundary: [1] (as there is no left subtree)
Leaf nodes: [4]
Right boundary: [3, 2] (in reverse order)
Final traversal: [1, 4, 3, 2]
Constraints:
1 ≤ number of nodes ≤ 105
1 ≤ node->data ≤ 105



// solution
/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
    private:
      void f(Node* root,vector<int> &v){
          if(root->left==NULL && root->right==NULL) return ;
          if(root->right){
              f(root->right,v);
          }
          else{
              f(root->left,v);
          }
          v.push_back(root->data);
      }
      void preorder(Node* root,vector<int> &v){
          if(root->left==NULL && root->right==NULL){
              v.push_back(root->data);
              return ;
          }
          if(root->left) preorder(root->left,v);
          if(root->right) preorder(root->right,v);
      }
    public:
      vector<int> boundaryTraversal(Node *root) {
          vector<int> v;
          if(!root) return v;
          Node* curr=root;
          v.push_back(curr->data);
          if(curr->left){
              curr=curr->left;
              while(curr->left!=NULL || curr->right!=NULL){
                  v.push_back(curr->data);
                  if(curr->left){
                      curr=curr->left;
                  }
                  else{
                      curr=curr->right;
                  }
              }
          }
          if(root->left) preorder(root->left,v);
          if(root->right) preorder(root->right,v);
          if(root->right){
              f(root->right,v);
          }
          return v;
      }
  };





//987. Vertical Order Traversal of a Binary Tree
Solved
Hard
Topics
Companies
Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

Return the vertical order traversal of the binary tree.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Explanation:
Column -1: Only node 9 is in this column.
Column 0: Nodes 3 and 15 are in this column in that order from top to bottom.
Column 1: Only node 20 is in this column.
Column 2: Only node 7 is in this column.
Example 2:


Input: root = [1,2,3,4,5,6,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation:
Column -2: Only node 4 is in this column.
Column -1: Only node 2 is in this column.
Column 0: Nodes 1, 5, and 6 are in this column.
          1 is at the top, so it comes first.
          5 and 6 are at the same position (2, 0), so we order them by their value, 5 before 6.
Column 1: Only node 3 is in this column.
Column 2: Only node 7 is in this column.
Example 3:


Input: root = [1,2,3,4,6,5,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation:
This case is the exact same as example 2, but with nodes 5 and 6 swapped.
Note that the solution remains the same since 5 and 6 are in the same location and should be ordered by their values.
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
0 <= Node.val <= 1000



// optimal solution
// time complexity for code below is O(nlogn) and space complexity is O(n)
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
        vector<vector<int>> verticalTraversal(TreeNode* root) {
            vector<vector<int>> ans;
            queue<pair<TreeNode*,pair<int,int>>> q;
            map<int,map<int,multiset<int>>> m;
            q.push({root,{0,0}});
            while(!q.empty()){
                auto p=q.front();
                q.pop();
                TreeNode* temp=p.first;
                int col=p.second.first;
                int row=p.second.second;
                m[col][row].insert(temp->val);
                if(temp->left) q.push({temp->left,{col-1,row+1}});
                if(temp->right) q.push({temp->right,{col+1,row+1}});
            }
            int val=-1;
            for(auto it=m.begin();it!=m.end();it++){
                vector<int> v;
                for(auto t=it->second.begin();t!=it->second.end();t++){
                    for(auto x: t->second){
                        v.push_back(x);
                    }
                }
                ans.push_back(v);
            }
            return ans;
        }
};



//Top View of Binary Tree
Difficulty: MediumAccuracy: 38.43%Submissions: 367K+Points: 4Average Time: 45m
You are given a binary tree, and your task is to return its top view. The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.

Note: 

Return the nodes from the leftmost node to the rightmost node.
If two nodes are at the same position (horizontal distance) and are outside the shadow of the tree, consider the leftmost node only. 
Examples:

Input: root[] = [1, 2, 3] 
 
Output: [2, 1, 3]
Input: root[] = [10, 20, 30, 40, 60, 90, 100]
 
Output: [40, 20, 10, 30, 100]
Explaination: The root 10 is visible.
On the left, 40 is the leftmost node and visible, followed by 20.
On the right, 30 and 100 are visible. Thus, the top view is 40 20 10 30 100.
Input: root[] = [1, 2, 3, N, 4, N, N, N, 5, N, 6]
       1
     /   \
    2     3
     \   
      4
       \
        5
         \
          6
Output: [2, 1, 3, 6]
Explaination: Node 1 is the root and visible.
Node 2 is the left child and visible from the left side.
Node 3 is the right child and visible from the right side.
Nodes 4, 5, and 6 are vertically aligned, but only the lowest node 6 is visible from the top view. Thus, the top view is 2 1 3 6.
Constraints:
1 ≤ number of nodes ≤ 105
1 ≤ node->data ≤ 105


// optimal solution
// t:O(nlogn) sp:O(n)+O(n)
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
    public:
      // Function to return a list of nodes visible from the top view
      // from left to right in Binary Tree.
      vector<int> topView(Node *root) {
          vector<int> ans;
          if(!root) return ans;
          map<int,int> m;
          queue<pair<int,Node*>> q;
          q.push({0,root});
          while(!q.empty()){
              auto p=q.front();
              q.pop();
              int col=p.first;
              Node* temp= p.second;
              if(m.find(col)==m.end()){
                  m[col]=temp->data;
              }
              if(temp->left) q.push({col-1,temp->left});
              if(temp->right) q.push({col+1,temp->right});
          }
          for(auto it=m.begin();it!=m.end();it++){
              ans.push_back(it->second);
          }
          return ans;
      }
};




//Bottom View of Binary Tree
Difficulty: MediumAccuracy: 54.18%Submissions: 293K+Points: 4Average Time: 45m
Given a binary tree, return an array where elements represent the bottom view of the binary tree from left to right.

Note: If there are multiple bottom-most nodes for a horizontal distance from the root, then the latter one in the level traversal is considered. For example, in the below diagram, 3 and 4 are both the bottommost nodes at a horizontal distance of 0, here 4 will be considered.

                      20
                    /    \
                  8       22
                /   \     /   \
              5      3 4     25
                     /    \      
                 10       14

For the above tree, the output should be 5 10 4 14 25.

Examples :

Input:
       1
     /   \
    3     2
Output: 3 1 2
Explanation: First case represents a tree with 3 nodes and 2 edges where root is 1, left child of 1 is 3 and right child of 1 is 2.

Thus bottom view of the binary tree will be 3 1 2.
Input:
         10
       /    \
      20    30
     /  \
    40   60
Output: 40 20 60 30
Input:
        1
       /   
      2
Output: 2 1
Constraints:
1 <= number of nodes <= 105
1 <= node->data <= 105


// optimal solution
// t:O(nlogn) sp:O(n)+O(n)
class Solution {
    public:
      vector <int> bottomView(Node *root) {
          vector<int> ans;
          map<int,int> m;
          queue<pair<int,Node*>> q;
          q.push({0,root});
          while(!q.empty()){
              auto p=q.front();
              q.pop();
              int col=p.first;
              Node* temp=p.second;
              m[col]=temp->data;
              if(temp->left) q.push({col-1,temp->left});
              if(temp->right) q.push({col+1,temp->right});
          }
          for(auto it=m.begin();it!=m.end();it++){
              ans.push_back(it->second);
          }
          return ans;
      }
  };




//199. Binary Tree Right Side View
Solved
Medium
Topics
Companies
Facebook
Amazon
Bloomberg
Qualtrics
Oracle
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 

Example 1:

Input: root = [1,2,3,null,5,null,4]

Output: [1,3,4]

Explanation:



Example 2:

Input: root = [1,2,3,4,null,null,null,5]

Output: [1,3,4,5]

Explanation:



Example 3:

Input: root = [1,null,3]

Output: [1,3]

Example 4:

Input: root = []

Output: []

 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100


// optimal solution
// t:O(n) sp:O(height)
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            while(size--){
                TreeNode* temp= q.front();
                q.pop();
                if(size==0) ans.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        return ans;
    }
};




//101. Symmetric Tree
Solved
Easy
Topics
Companies
Facebook
Amazon
LinkedIn
Google
Microsoft
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 

Example 1:


Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:


Input: root = [1,2,2,null,3,null,3]
Output: false
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100
 

Follow up: Could you solve it both recursively and iteratively?


// optimal solution
// t:O(n) sp:O(h)
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
        bool f(TreeNode* l,TreeNode* r){
            if(l==NULL || r==NULL){
                return (l==NULL && r==NULL);
            }
            return ((l->val==r->val)&&((f(l->right,r->left))&&(f(l->left,r->right))));
        }
    public:
        bool isSymmetric(TreeNode* root) {
            return f(root->left,root->right);
        }
};