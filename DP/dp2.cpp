//Subset Sum Problem
Difficulty: MediumAccuracy: 32.0%Submissions: 295K+Points: 4
Given an array of positive integers, arr[] and a value, target, determine if there is a subset of the given set with sum equal to given target. 

Examples:

Input: arr[] = [3, 34, 4, 12, 5, 2], target = 9
Output: true 
Explanation: Here there exists a subset with target sum = 9, 4+3+2 = 9.
Input: arr[] = [3, 34, 4, 12, 5, 2], target = 30
Output: false
Explanation: There is no subset with target sum 30.
Input: arr[] = [1, 2, 3], sum = 6
Output: true
Explanation: The entire array can be taken as a subset, giving 1 + 2 + 3 = 6.
Constraints:
1 <= arr.size() <= 200
1<= arr[i] <= 200
1<= sum <= 4*104


// top down approach
class Solution {
  private:
    bool f(int ind,int target, vector<int> &arr,vector<vector<int>> &dp){
        if(target==0) return true;
        if(ind==0) return (arr[ind]==target);
        if(dp[ind][target]!=-1) return dp[ind][target];
        bool notTaken=f(ind-1,target,arr,dp);
        bool taken=false;
        if(target>=arr[ind]){
            taken = f(ind-1,target-arr[ind],arr,dp);
        }
        return dp[ind][target]=(notTaken || taken);
    }
  public:
    bool isSubsetSum(vector<int>& arr, int target) {
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return f(n-1,target,arr,dp);
    }
};

//bottoms up approach

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int target) {
        int n=arr.size();
        vector<vector<bool>> dp(n,vector<bool>(target+1,false));
        for(int i=0; i<n; i++){
            dp[i][0]=true;
        }
        dp[0][arr[0]]=true;
        for(int i=1; i<n ; i++){
            for(int j=1;j<=target;j++){
                bool notTaken=dp[i-1][j];
                bool taken=false;
                if(j>=arr[i]){
                    taken=dp[i-1][j-arr[i]];
                }
                dp[i][j]=notTaken|| taken;
            }
        }
        return dp[n-1][target];
    }
};

// bottoms up approach(space optimized)
class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int target) {
        int n=arr.size();
        // vector<vector<bool>> dp(n,vector<bool>(target+1,false));
        vector<bool> prev(target+1,false);
        // for(int i=0; i<n; i++){
        //     dp[i][0]=true;
        // }
        prev[0]=true;
        prev[arr[0]]=true;
        for(int i=1; i<n ; i++){
            vector<bool> curr(target+1,false);
            curr[0]=true;
            for(int j=1;j<=target;j++){
                bool notTaken=prev[j];
                bool taken=false;
                if(j>=arr[i]){
                    taken=prev[j-arr[i]];
                }
                curr[j]=notTaken|| taken;
            }
            prev=curr;
        }
        return prev[target];
    }
};
