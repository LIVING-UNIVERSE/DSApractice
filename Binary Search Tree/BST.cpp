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



//98. Validate Binary Search Tree
Solved
Medium
Topics
Companies
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:


Input: root = [2,1,3]
Output: true
Example 2:


Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-231 <= Node.val <= 231 - 1


// optimal solution
// t:O(n) sp:O(h)
class Solution {
    private:
        bool f(TreeNode* root ,long mini,long maxi){
            if(root==NULL) return true;
            if(root->val<=mini || root->val>=maxi) return false;
            bool left=f(root->left,mini,root->val);
            bool right=f(root->right,root->val,maxi);
            return (left && right);
        }
    public:
        bool isValidBST(TreeNode* root) {
            return f(root,LONG_MIN,LONG_MAX);
        }
};

// 2nd approach
// t:O(n) sp:O(h)
class Solution {
    private:
        pair<bool,pair<int,int>> f(TreeNode* root){
            int lmax=root->val,lmin=root->val;
            int rmax=root->val,rmin=root->val;
            if(root->left){
                auto p=f(root->left);
                bool left=p.first;
                lmin=p.second.first;
                lmax=p.second.second;
                if(!left || lmax>=root->val) return {false,{lmin,rmax}};
            }
            if(root->right){
                auto p=f(root->right);
                bool right=p.first;
                rmin=p.second.first;
                rmax=p.second.second;
                if(!right || rmin<=root->val) return {false,{lmin,rmax}};
            }
            return {true,{lmin,rmax}};
        }
    public:
        bool isValidBST(TreeNode* root) {
            return f(root).first;
        }
};



//1008. Construct Binary Search Tree from Preorder Traversal
Solved
1563
Medium
Topics
Companies
Amazon
Microsoft
Facebook
Bloomberg
Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.

It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.

A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.

A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.

 

Example 1:


Input: preorder = [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]
Example 2:

Input: preorder = [1,3]
Output: [1,null,3]
 

Constraints:

1 <= preorder.length <= 100
1 <= preorder[i] <= 1000
All the values of preorder are unique.



// brute force
// t:O(nlogn) sp:O(n)
class Solution {
    private:
        TreeNode* f(int is,int ie,int ps,int pe,vector<int> &in,vector<int> &pre,unordered_map<int,int> &m){
            if(is>ie || ps>pe) return NULL;
            TreeNode* root= new TreeNode(pre[ps]);
            int ind= m[root->val]-is;
            TreeNode* left= f(is,is+ind-1,ps+1,ps+ind,in,pre,m);
            TreeNode* right= f(is+ind+1,ie,ps+ind+1,pe,in,pre,m);
            root->left=left;
            root->right=right;
            return root;
        }
    public:
        TreeNode* bstFromPreorder(vector<int>& pre) {
            vector<int> in=pre;
            sort(in.begin(),in.end());
            unordered_map<int,int> m;
            for(int i=0;i<in.size();i++){
                m[in[i]]=i;
            }
            return f(0,in.size()-1,0,pre.size()-1,in,pre,m);
        }
};



// optimal solution
// t:O(n) sp:O(h)
class Solution {
    private:
        TreeNode* f(int &ind, int ub,vector<int> &arr){
            if(ind>=arr.size() || arr[ind]>ub) return NULL;
            TreeNode* root= new TreeNode(arr[ind]);
            ind++;
            root->left= f(ind,root->val,arr);
            root->right=f(ind,ub,arr);
            return root;
        }
    public:
        TreeNode* bstFromPreorder(vector<int>& preorder) {
            int ind=0;
            return f(ind,INT_MAX,preorder);
        }
};




//Predecessor and Successor
Difficulty: MediumAccuracy: 47.36%Submissions: 133K+Points: 4
You are given root node of the BST and an integer key. You need to find the in-order successor and predecessor of the given key. If either predecessor or successor is not found, then set it to NULL.

Note:- In an inorder traversal the number just smaller than the target is the predecessor and the number just greater than the target is the successor. 

Examples :

Input: root[] = [8, 1, 9, N, 4, N, 10, 3, N, N, N]
      8
    /   \
   1     9
   \      \
    4      10
   /
  3
key = 8
Output: 4 9
Explanation: In the given BST the inorder predecessor of 8 is 4 and inorder successor of 8 is 9.
Input: root[] = [10, 2, 11, 1, 5, N, N, N, N, 3, 6, N, 4, N, N]
      10
    /   \
   2     11
  / \
 1   5
    / \
   3   6
    \
     4
key = 11
Output: 10 -1
Explanation: In given BST, the inorder predecessor of 11 is 10 whereas it does not have any inorder successor.
Input: root[] = [2, 1, 3]
      2
    /   \
   1     3
key = 3
Output: 2 -1
Constraints: 
1 <= Number of nodes <= 105
1 <= key <= 106


// brute force
// t:O(n) sp:O(n)
class Solution{
    private:
        void f(Node* root,vector<Node*> &v){
            if(root==NULL) return ;
            f(root->left,v);
            v.push_back(root);
            f(root->right,v);
        }
    public:
        void findPreSuc(Node* root, Node*& pre, Node*& suc, int key){
            vector<Node*> v;
            f(root,v);
            int n=v.size();
            for(int i=0;i<n;i++){
                if(v[i]->key<key){
                    pre=v[i];
                }
                if(v[i]->key>key){
                    suc=v[i];
                    break;
                }
            }
        }
};



// optimal solution
// O(logn) sp:O(1)
class Solution{
    private:
        Node* findPre(Node*root,int key){
            Node* curr=root;
            Node* res=NULL;
            while(curr){
                if(curr->key<key){
                    res=curr;
                    curr=curr->right;
                }
                else{
                    curr=curr->left;
                }
            }
            return res;
        }
        Node* findSuc(Node* root,int key){
            Node* curr=root;
            Node* res=NULL;
            while(curr){
                if(curr->key>key){
                    res=curr;
                    curr=curr->left;
                }
                else{
                    curr=curr->right;
                }
            }
            return res;
        }
    public:
        void findPreSuc(Node* root, Node*& pre, Node*& suc, int key){
            pre=findPre(root,key);
            suc=findSuc(root,key);
        }
};



//173. Binary Search Tree Iterator
Solved
Medium
Topics
Companies
Facebook
Microsoft
Amazon
Bloomberg
Salesforce
Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):

BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as part of the constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.
boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
int next() Moves the pointer to the right, then returns the number at the pointer.
Notice that by initializing the pointer to a non-existent smallest number, the first call to next() will return the smallest element in the BST.

You may assume that next() calls will always be valid. That is, there will be at least a next number in the in-order traversal when next() is called.

 

Example 1:


Input
["BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
[[[7, 3, 15, null, null, 9, 20]], [], [], [], [], [], [], [], [], []]
Output
[null, 3, 7, true, 9, true, 15, true, 20, false]

Explanation
BSTIterator bSTIterator = new BSTIterator([7, 3, 15, null, null, 9, 20]);
bSTIterator.next();    // return 3
bSTIterator.next();    // return 7
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 9
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 15
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 20
bSTIterator.hasNext(); // return False
 

Constraints:

The number of nodes in the tree is in the range [1, 105].
0 <= Node.val <= 106
At most 105 calls will be made to hasNext, and next.
 

Follow up:

Could you implement next() and hasNext() to run in average O(1) time and use O(h) memory, where h is the height of the tree?


// brute force
// t:O(1) sp:O(n)
// we are travelling to n nodes and if we use 10 next() callls then time complexity for per call is O(1).
class BSTIterator {
    private:
        void f(TreeNode* root,vector<int> &arr){
            if(root==NULL) return ;
            f(root->left,arr);
            arr.push_back(root->val);
            f(root->right,arr);
        }
    public:
        vector<int> v;
        int it=0;
        BSTIterator(TreeNode* root) {
            f(root,v);
        }
        
        int next() {
            return v[it++];
        }
        
        bool hasNext() {
            return (it<v.size());
        }
};



// optimal solution
// t:O(1) sp:O(h)
class BSTIterator {
    private:
        void f(TreeNode* root){
            while(root){
                st.push(root);
                root=root->left;
            }
        }
    public:
        stack<TreeNode*> st;
        BSTIterator(TreeNode* root) {
            f(root);
        }
        
        int next() {
            TreeNode* temp=st.top();
            st.pop();
            if(temp->right){
                f(temp->right);
            }
            return temp->val;
        }
        
        bool hasNext() {
            return (!st.empty());
        }
};




//653. Two Sum IV - Input is a BST
Solved
Easy
Topics
Companies
Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.

 

Example 1:


Input: root = [5,3,6,2,4,null,7], k = 9
Output: true
Example 2:


Input: root = [5,3,6,2,4,null,7], k = 28
Output: false
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-104 <= Node.val <= 104
root is guaranteed to be a valid binary search tree.
-105 <= k <= 105



// brute force
//t :O(n) sp:O(n)
class Solution {
    private:
        void f(TreeNode* root,vector<int> &v){
            if(root==NULL) return ;
            f(root->left,v);
            v.push_back(root->val);
            f(root->right,v);
        }
    public:
        bool findTarget(TreeNode* root, int k) {
            vector<int> v;
            f(root,v);
            int n=v.size();
            int l=0,r=n-1;
            while(l<r){
                if(v[l]+v[r]==k) return true;
                else if(v[l]+v[r]<k) l++;
                else{
                    r--;
                }
            }
            return false;           
        }
};
    

// optimal solution
// t:O(n) sp:O(2*log(n))
class Solution {
    private:
        void pref(){
            TreeNode* temp=pre.top();
            pre.pop();
            if(temp->right){
                TreeNode* curr=temp->right;
                while(curr){
                    pre.push(curr);
                    curr=curr->left;
                }
            }
        }
        void postf(){
            TreeNode* temp=post.top();
            post.pop();
            if(temp->left){
                TreeNode* curr=temp->left;
                while(curr){
                    post.push(curr);
                    curr=curr->right;
                }
            }
        }
    public:
        stack <TreeNode*> pre;
        stack <TreeNode*> post;
        bool findTarget(TreeNode* root, int k) {
            TreeNode* curr=root;
            while(curr){
                pre.push(curr);
                curr=curr->left;
            }
            curr=root;
            while(curr){
                post.push(curr);
                curr=curr->right;
            }
            while(!pre.empty() && !post.empty()){
                TreeNode* preNode= pre.top();
                TreeNode* postNode=post.top();
                if(preNode->val+postNode->val>k){
                    postf();
                }
                else if(preNode->val+postNode->val==k && preNode==postNode){
                    postf();
                    pref();
                }
                else if(preNode->val+postNode->val==k && preNode!=postNode){
                    return true;
                }
                else{
                    pref();
                }
            }
            return false;
        }
};



//Largest BST
Difficulty: MediumAccuracy: 29.73%Submissions: 167K+Points: 4Average Time: 40m
Youre given a binary tree. Your task is to find the size of the largest subtree within this binary tree that also satisfies the properties of a Binary Search Tree (BST). The size of a subtree is defined as the number of nodes it contains.

Note: A subtree of the binary tree is considered a BST if for every node in that subtree, the left child is less than the node, and the right child is greater than the node, without any duplicate values in the subtree.

Examples :

Input: root = [5, 2, 4, 1, 3]
Root-to-leaf-path-sum-equal-to-a-given-number-copy
Output: 3
Explanation:The following sub-tree is a BST of size 3
Balance-a-Binary-Search-Tree-3-copy
Input: root = [6, 7, 3, N, 2, 2, 4]

Output: 3
Explanation: The following sub-tree is a BST of size 3:

Constraints:
1 ≤ number of nodes ≤ 105
1 ≤ node->data ≤ 105



// brute force solution
// t:O(n*n)  sp:O(n)
class Solution{
    private:
        int size(Node* root){
            if(root==NULL) return 0;
            return size(root->left)+size(root->right)+1;
        }
        bool isBST(Node* root, int lb,int ub){
            if(root==nullptr) return true;
            bool left=isBST(root->left,lb,root->data);
            bool right=isBST(root->right,root->data,ub);
            if(left==false || right==false) return false;
            if(root->data<=lb || root->data>=ub) return false;
            return true;
        }
        void f(Node* root){
            if(root==NULL) return ;
            f(root->left);
            if(isBST(root,INT_MIN,INT_MAX)) res=max(res,size(root));
            f(root->right);
        }
    public:
        int res=0;
        int largestBst(Node *root){
            f(root);
            return res;
        }
};



// optimal solution
// t:O(n) sp:O(h)
class Solution{
    private:
        int res=0;
        vector<int> f(Node* root){
            if(root->left==NULL && root->right==NULL){
                res=max(res,1);
                return {root->data,root->data,1};
            }
            int lmin=root->data,lmax=root->data,lsize=0;
            int rmin=root->data,rmax=root->data,rsize=0;
            if(root->left){
                vector<int> vleft=f(root->left);
                lmin=vleft[0];lmax=vleft[1];lsize=vleft[2];
            }
            if(root->right){
                vector<int> vright=f(root->right);
                rmin=vright[0];rmax=vright[1];rsize=vright[2];
            }
            if(rsize==-1|| lsize==-1) return {INT_MIN,INT_MAX,-1};
            if(rsize!=-1 && lsize!=-1){
                if(root->left && root->data<=lmax) return {INT_MIN,INT_MAX,-1};
                if(root->right && root->data>=rmin) return {INT_MIN,INT_MAX,-1};
            }
            res=max(res,lsize+rsize+1);
            return {lmin,rmax,lsize+rsize+1};
        }   
    public:
        int largestBst(Node *root){
            f(root);
            return res;
        }
};




//99. Recover Binary Search Tree
Solved
Medium
Topics
Companies
You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

 

Example 1:


Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]
Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.
Example 2:


Input: root = [3,1,4,null,null,2]
Output: [2,1,4,null,null,3]
Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.
 

Constraints:

The number of nodes in the tree is in the range [2, 1000].
-231 <= Node.val <= 231 - 1
 

Follow up: A solution using O(n) space is pretty straight-forward. Could you devise a constant O(1) space solution?



// brute force
// t:O(n) sp:O(n)
class Solution{
    private:
        void f(TreeNode* root,vector<TreeNode*> &v){
            if(root==NULL) return;
            f(root->left,v);
            v.push_back(root);
            f(root->right,v);
        }
    public:
        void recoverTree(TreeNode* root) {
            vector<TreeNode*> v;
            f(root,v);
            TreeNode* first=NULL;
            TreeNode* second=NULL;
            TreeNode* temp=NULL;
            for(int i=1;i<v.size();i++){
                if(v[i]->val<v[i-1]->val){
                    if(first==NULL){
                        first=v[i-1];
                        temp=v[i];
                    }
                    else{
                        second=v[i];
                    }
                }
            }
            if(second==NULL) swap(first->val,temp->val);
            else{
                swap(first->val,second->val);
            }
        }
};



// optimal solution
// t:O(n) sp:O(1)
class Solution {
    private:
        void f(TreeNode* root){
            if(root==NULL) return;
            f(root->left);
            if(prev && root->val<prev->val){
                if(first==NULL){
                    first=prev;
                    temp=root;
                }
                else{
                    second=root;
                }
            }
            prev=root;
            f(root->right);
        }
    public:
        TreeNode* prev=NULL;
        TreeNode* first=NULL;
        TreeNode* second=NULL;
        TreeNode* temp=NULL;
        void recoverTree(TreeNode* root) {
            f(root);
            if(!second) swap(first->val,temp->val);
            else{
                swap(first->val,second->val);
            }
        }
};