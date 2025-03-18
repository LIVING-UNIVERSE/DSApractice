//144. Binary Tree Preorder Traversal
Solved
Easy
Topics
Companies
Adobe
Google
Given the root of a binary tree, return the preorder traversal of its nodes values.

 

Example 1:

Input: root = [1,null,2,3]

Output: [1,2,3]

Explanation:



Example 2:

Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]

Output: [1,2,4,5,6,7,3,8,9]

Explanation:



Example 3:

Input: root = []

Output: []

Example 4:

Input: root = [1]

Output: [1]

 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
 

Follow up: Recursive solution is trivial, could you do it iteratively?


// recursive solution
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
    void f(TreeNode* root,vector<int> &arr){
        if(root==NULL) return;
        arr.push_back(root->val);
        f(root->left,arr);
        f(root->right,arr);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> arr;
        f(root,arr);
        return arr;
    }
};
// iterative solution
// using stack
class Solution {
    public:
        vector<int> preorderTraversal(TreeNode* root) {
            if(root==NULL) return {};
            vector<int> ans;
            stack<TreeNode*> st;
            st.push(root);
            while(!st.empty()){
                TreeNode* temp= st.top();
                st.pop();
                ans.push_back(temp->val);
                if(temp->right) st.push(temp->right);
                if(temp->left) st.push(temp->left);
            }
            return ans;
        }
};



// 94. Binary Tree Inorder Traversal
Solved
Easy
Topics
Companies
Microsoft
Amazon
Apple
Adobe
Given the root of a binary tree, return the inorder traversal of its nodes values.

 

Example 1:

Input: root = [1,null,2,3]

Output: [1,3,2]

Explanation:



Example 2:

Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]

Output: [4,2,6,5,7,1,3,9,8]

Explanation:



Example 3:

Input: root = []

Output: []

Example 4:

Input: root = [1]

Output: [1]

 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
 

Follow up: Recursive solution is trivial, could you do it iteratively?



// solution
class Solution {
    private:
        void f(TreeNode* root,vector<int> &arr){
            if(root==NULL)return ;
            f(root->left,arr);
            arr.push_back(root->val);
            f(root->right,arr);
        }
    public:
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int> arr;
            f(root,arr);
            return arr;
        }
    };




// 145. Binary Tree Postorder Traversal
Easy
Topics
Companies
Facebook
TuSimple
Given the root of a binary tree, return the postorder traversal of its nodes values.

 

Example 1:

Input: root = [1,null,2,3]

Output: [3,2,1]

Explanation:



Example 2:

Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]

Output: [4,6,7,5,2,9,8,3,1]

Explanation:



Example 3:

Input: root = []

Output: []

Example 4:

Input: root = [1]

Output: [1]

 

Constraints:

The number of the nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
 

Follow up: Recursive solution is trivial, could you do it iteratively?

// solution
class Solution {
    private:
        void f(TreeNode* root,vector<int> &arr){
            if(root==NULL)return ;
            f(root->left,arr);
            f(root->right,arr);
            arr.push_back(root->val);
        }
    public:
        vector<int> postorderTraversal(TreeNode* root) {
            vector<int> arr;
            f(root,arr);
            return arr;
        }
};


//102. Binary Tree Level Order Traversal
Solved
Medium
Topics
Companies
Hint
LinkedIn
Amazon
Microsoft
Facebook
Bloomberg
Given the root of a binary tree, return the level order traversal of its nodes values. (i.e., from left to right, level by level).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000



// solution
// note: use q.size() to calculate how many times the inner loop will continue
class Solution {
    public:
        vector<vector<int>> levelOrder(TreeNode* root) {
            if(root==NULL) return {};
            vector<vector<int>> ans;
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty()){
                int size=q.size();
                vector<int> v;
                while(size--){
                    TreeNode* temp=q.front();
                    q.pop();
                    v.push_back(temp->val);
                    if(temp->left) q.push(temp->left);
                    if(temp->right) q.push(temp->right);
                }
                ans.push_back(v);
            }
            return ans;
        }
    };