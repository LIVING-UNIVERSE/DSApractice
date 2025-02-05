118. Pascals Triangle
Solved
Easy
Topics
Companies
Amazon
Apple
Microsoft
Goldman Sachs
Snapchat
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


 

Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Example 2:

Input: numRows = 1
Output: [[1]]
 

Constraints:

1 <= numRows <= 30


// optimal solution
class Solution {
private:
    vector<int> f(int ind){
        int r=ind-1,res=1;
        vector<int> v;
        v.push_back(1);
        for(int i=1; i<ind; i++){
            res*=(r-i+1);
            res=res/i;
            v.push_back(res);
        }
        return v;
    }
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> res;
        for(int i=1; i<=n; i++){
            res.push_back(f(i));
        }
        return res;
    }
};