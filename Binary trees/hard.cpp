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




//662. Maximum Width of Binary Tree
Solved
Medium
Topics
Companies
Amazon
Google
Microsoft
Facebook
Bloomberg
Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer.

 

Example 1:


Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).
Example 2:


Input: root = [1,3,2,5,null,null,9,6,null,7]
Output: 7
Explanation: The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7).
Example 3:


Input: root = [1,3,2,5]
Output: 2
Explanation: The maximum width exists in the second level with length 2 (3,2).
 

Constraints:

The number of nodes in the tree is in the range [1, 3000].
-100 <= Node.val <= 100


// brute force
// t:O(n) sp:O(n)
class Solution {
    public:
        int widthOfBinaryTree(TreeNode* root) {
            if(root==NULL) return 0;
            queue<pair<TreeNode*,long long>> q;
            q.push({root,0LL});
            long long ans=0;
            while(!q.empty()){
                int size=q.size();
                long long sm=q.front().second;
                long long lg=q.back().second;
                ans=max(ans,lg-sm+1);
                for(int i=0;i<size;i++){
                    auto [temp,ind]= q.front();
                    q.pop();
                    if(temp->left) q.push({temp->left,2*ind+1-sm});
                    if(temp->right) q.push({temp->right,2*ind+2-sm});
                }
            }
            return (int)ans;
        }
};


// optimal solution
// t:O(n) sp:O(n)
class Solution {
    public:
        int widthOfBinaryTree(TreeNode* root) {
            if(root==NULL) return 0;
            queue<pair<TreeNode*,long long>> q;
            q.push({root,0LL});
            long long ans=0;
            while(!q.empty()){
                int size=q.size();
                long long sm=q.front().second;
                long long lg=q.back().second;
                ans=max(ans,lg-sm+1);
                for(int i=0;i<size;i++){
                    auto [temp,ind]= q.front();
                    ind=ind-sm;
                    q.pop();
                    if(temp->left) q.push({temp->left,2*ind+1});
                    if(temp->right) q.push({temp->right,2*ind+2});
                }
            }
            return (int)ans;
        }
};
    




//863. All Nodes Distance K in Binary Tree
Solved
Medium
Topics
Companies
Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.

 

Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
Example 2:

Input: root = [1], target = 1, k = 3
Output: []
 

Constraints:

The number of nodes in the tree is in the range [1, 500].
0 <= Node.val <= 500
All the values Node.val are unique.
target is the value of one of the nodes in the tree.
0 <= k <= 1000



// optimal solution
// t:O(n) sp:O(n)
class Solution {
    private:
        void f(TreeNode* root,map<TreeNode*,TreeNode*> &m){
            queue<TreeNode*> q;
            m[root]=NULL;
            q.push(root);
            while(!q.empty()){
                auto temp= q.front();
                q.pop();
                if(temp->left){
                    m[temp->left]=temp;
                    q.push(temp->left);
                }
                if(temp->right){
                    m[temp->right]=temp;
                    q.push(temp->right);
                }
            }
        }
    public:
        vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
            vector<int> ans;
            if(!root || !target) return ans;
            map<TreeNode*,TreeNode*> m;
            f(root,m);
            unordered_set<TreeNode*> s;
            queue<pair<TreeNode*,int>> q;
            q.push({target,0});
            s.insert(target);
            while(!q.empty()){
                auto [temp,count]=q.front();
                q.pop();
                if(count==k){
                    ans.push_back(temp->val);
                    continue;
                }
                if(temp->left && s.find(temp->left)==s.end()){
                    q.push({temp->left,count+1});
                    s.insert(temp->left);
                }
                if(temp->right && s.find(temp->right)==s.end()){
                    q.push({temp->right,count+1});
                    s.insert(temp->right);
                }
                auto parent= m[temp];
                if(parent && s.find(parent)==s.end()){
                    q.push({parent,count+1});
                    s.insert(parent);
                }
            }
            return ans;
        }
};




//Burning Tree
Difficulty: HardAccuracy: 53.53%Submissions: 105K+Points: 8
Given a binary tree and a node data called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.
Note: The tree contains unique values.

Examples : 

Input: root[] = [1,2,3,4,5,N,6,N,N,7,8,N,9,N,N,N,N,N,10],  target = 8
  
Output: 7
Explanation: If leaf with the value 8 is set on fire. 
After 1 sec: 5 catches fire.
After 2 sec: 2, 7 catches fire.
After 3 sec: 4, 1 catches fire.
After 4 sec: 3 catches fire.
After 5 sec: 6 catches fire.
After 6 sec: 9 catches fire.
After 7 sec: 10 catches fire.
It takes 7s to burn the complete tree.
Input: root[] = [1, 2, 3, 4, 5, N, 7, 8, N, 10], target = 10

Output: 5
Explanation: If leaf with the value 10 is set on fire. 
- After 1 sec: Node 5 catches fire.
- After 2 sec: Node 2 catches fire.
- After 3 sec: Nodes 1 and 4 catches fire.
- After 4 sec: Node 3 and 8 catches fire.
- After 5 sec: Node 7 catches fire.
It takes 5s to burn the complete tree.
Constraints:
1 ≤ number of nodes ≤ 105
1 ≤ node->data ≤ 105



// optimal solution
class Solution {
    private:
      void f(Node* root, unordered_map<Node*,Node*> &m){
          queue<Node*> q;
          m[root]=NULL;
          q.push(root);
          while(!q.empty()){
              Node* temp=q.front();
              q.pop();
              if(temp->left){
                  m[temp->left]=temp;
                  q.push(temp->left);
              }
              if(temp->right){
                  m[temp->right]=temp;
                  q.push(temp->right);
              }
          }
      }
      Node* find(Node* root,int target){
          queue<Node*> q;
          q.push(root);
          while(!q.empty()){
              auto temp=q.front();
              q.pop();
              if(temp->data==target) return temp;
              if(temp->left) q.push(temp->left);
              if(temp->right) q.push(temp->right);
          }
          return NULL;
      }
    public:
      int minTime(Node* root, int target) {
          int res=0;
          if(!root) return res;
          unordered_set<Node*> s;
          unordered_map<Node*,Node*> m;
          f(root,m);
          queue<pair<Node*,int>> q;
          Node* tag=find(root,target);
          s.insert(tag);
          q.push({tag,0});
          while(!q.empty()){
              Node* temp=q.front().first;
              int count=q.front().second;
              q.pop();
              res=max(res,count);
              if(temp->left && s.find(temp->left)==s.end()){
                  q.push({temp->left,count+1});
                  s.insert(temp->left);
              }
              if(temp->right && s.find(temp->right)==s.end()){
                  q.push({temp->right,count+1});
                  s.insert(temp->right);
              }
              Node* parent= m[temp];
              if(parent && s.find(parent)==s.end()){
                  q.push({parent,count+1});
                  s.insert(parent);
              }
          }
          return res;
      }
};




//222. Count Complete Tree Nodes
Solved
Easy
Topics
Companies
Google
Amazon
tiktok
Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.

 

Example 1:


Input: root = [1,2,3,4,5,6]
Output: 6
Example 2:

Input: root = []
Output: 0
Example 3:

Input: root = [1]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [0, 5 * 104].
0 <= Node.val <= 5 * 104
The tree is guaranteed to be complete.


// brute force
// t:O(n) sp:O(h)
class Solution {
    public:
        int countNodes(TreeNode* root) {
            if(root==NULL) return 0;
            return countNodes(root->left)+countNodes(root->right)+1;
        }
};


// better solution
// t:O(logn*logn) sp:O(h)
class Solution {
    private:
        int height(TreeNode* root){
            int h=0;
            while(root){
                h++;
                root=root->left;
            }
            return h;
        }
    public:
        int countNodes(TreeNode* root) {
            if(root==NULL) return 0;
            int lh=height(root->left);
            int rh=height(root->right);
            if(lh==rh) return (1<<lh)+countNodes(root->right);
            return (1<<rh)+countNodes(root->left);
        }
};


// optimal solution
// t:O(logn) sp:O(h)
class Solution {
    private:
        int lheight(TreeNode* root){
            int count=0;
            while(root){
                count++;
                root=root->left;
            }
            return count;
        }
        int rheight(TreeNode* root){
            int count=0;
            while(root){
                count++;
                root=root->right;
            }
            return count;
        }
    public:
        int countNodes(TreeNode* root) {
            int lh=lheight(root);
            int rh=rheight(root);
            if(lh==rh) return (1<<lh)-1;
            return 1+countNodes(root->left)+countNodes(root->right);
        }
    };