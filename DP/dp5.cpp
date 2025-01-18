//Longest Increasing Subsequence
Difficulty: MediumAccuracy: 32.8%Submissions: 320K+Points: 4
Given an array arr[] of integers, the task is to find the length of the Longest Strictly Increasing Subsequence (LIS).

A subsequence is strictly increasing if each element in the subsequence is strictly less than the next element.

Examples:

Input: arr[] = [5, 8, 3, 7, 9, 1]
Output: 3
Explanation: The longest strictly increasing subsequence could be [5, 7, 9], which has a length of 3.
Input: arr[] = [0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15]
Output: 6
Explanation: One of the possible longest strictly increasing subsequences is [0, 2, 6, 9, 13, 15], which has a length of 6.
Input: arr[] = [3, 10, 2, 1, 20]
Output: 3
Explanation: The longest strictly increasing subsequence could be [3, 10, 20], which has a length of 3.
Constraints:
1 ≤ arr.size() ≤ 10^3
0 ≤ arr[i] ≤ 10^6


// top down approach
class Solution {
  private:
    int f(int ind,int prev_ind,vector<int> &arr,vector<vector<int>> &dp){
        if(ind==arr.size()) return 0;
        if(dp[ind][prev_ind]!=-1) return dp[ind][prev_ind];
        int notTaken= f(ind+1,prev_ind,arr,dp);
        int taken=0;
        if(prev_ind==0||arr[ind]>arr[prev_ind-1]){
            taken =1+f(ind+1,ind+1,arr,dp);
        }
        return dp[ind][prev_ind]= max(taken,notTaken);
    }
  public:
    // Function to find length of longest increasing subsequence.
    int lis(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return f(0,0,arr,dp);
    }
};




// bottoms up approach
class Solution {

  public:
    // Function to find length of longest increasing subsequence.
    int lis(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=n-1; i>=0; i--){
            for(int j=0;j<n; j++){
                int notTaken=dp[i+1][j];
                int taken=0;
                if(j==0 || arr[i]>arr[j-1]){
                    taken=1+dp[i+1][i+1];
                }
                dp[i][j]=max(taken,notTaken);
            }
        }
        return dp[0][0];
    }
};


// bottoms up approach(space optimized)


class Solution {

  public:
    // Function to find length of longest increasing subsequence.
    int lis(vector<int>& arr) {
        int n=arr.size();
        vector<int> prev(n+1,0),curr(n+1,0);
        for(int i=n-1; i>=0; i--){
            for(int j=0;j<n; j++){
                int notTaken=prev[j];
                int taken=0;
                if(j==0 || arr[i]>arr[j-1]){
                    taken=1+prev[i+1];
                }
                curr[j]=max(taken,notTaken);
            }
            prev=curr;
        }
        return prev[0];
    }
};



//300. Longest Increasing Subsequence
Solved
Medium
Topics
Companies
Given an integer array nums, return the length of the longest strictly increasing 
subsequence
.

 

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1
 

Constraints:

1 <= nums.length <= 2500
-104 <= nums[i] <= 104



// this is  O(nlogn) solution if asked specifically then give this approach 
class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        // this is a O(nlogn) solution 
        int n=arr.size();
        vector<int> v;
        v.push_back(arr[0]);
        for(int i=1; i<n ; i++){
            if(arr[i]>v[v.size()-1]){
                v.push_back(arr[i]);
            }
            else{
                int ind=lower_bound(v.begin(),v.end(),arr[i])-v.begin();
                v[ind]=arr[i];
            }
        }
        return v.size();
    }
};