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



//56. Merge Intervals
Solved
Medium
Topics
Companies
Facebook
Amazon
Google
Bloomberg
Salesforce
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 

Constraints:

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104



// optimal solution
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        int begin=arr[0][0],end=arr[0][1];
        for(int i=1; i<n; i++){
            if(arr[i][0]>end){
                vector<int> temp;
                temp.push_back(begin);
                temp.push_back(end);
                ans.push_back(temp);
                begin=arr[i][0];
                end=arr[i][1];
            }
            else{
                end=max(end,arr[i][1]);
            }
        }
        vector<int> temp;
        temp.push_back(begin);
        temp.push_back(end);
        ans.push_back(temp);
        return ans;
    }
};

// further optimal solution
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            if(ans.empty() || (arr[i][0]>ans.back()[1])){
                ans.push_back({arr[i][0],arr[i][1]});
            }
            else{
                ans.back()[1]=max(ans.back()[1],arr[i][1]);
            }
        }
        return ans;
    }
};