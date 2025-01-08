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






//416. Partition Equal Subset Sum
Attempted
Medium
Topics
Companies
Facebook
Microsoft
Amazon
Apple
Google
Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100



// top down approach
class Solution {
private:
    bool f(int ind,int target, vector<vector<int>> &dp, vector<int> &arr){
        if(target==0) return true;
        if(ind==0) return (arr[0]==target);
        if(dp[ind][target]!=-1) return dp[ind][target];
        bool notTaken = f(ind-1,target,dp,arr);
        bool taken = false;
        if(target>arr[ind]){
            taken =f(ind-1,target-arr[ind],dp,arr);
        }
        return dp[ind][target]=taken || notTaken;
    }
public:
    bool canPartition(vector<int>& arr) {
        int n=arr.size();
        int sum=0;
        for(int x:arr){
            sum+=x;
        }
        if(sum%2!=0) return false;
        int target=sum/2;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return f(n-1,target,dp,arr);
    }
};



// bottoms up approach
class Solution {
public:
    bool canPartition(vector<int>& arr) {
        int n=arr.size();
        int sum=0;
        for(int x:arr){
            sum+=x;
        }
        if(sum%2!=0) return false;
        int target=sum/2;
        vector<vector<bool>> dp(n,vector<bool>(target+1,false));
        for(int i=0; i<n; i++){
            dp[i][0]=true;
        }
        if(arr[0]<=target){
            dp[0][arr[0]]=true;
        }
        for(int i=1; i<n; i++){
            for(int j=1; j<=target; j++){
                bool notTaken= dp[i-1][j];
                bool taken=false;
                if(j>=arr[i]){
                    taken=dp[i-1][j-arr[i]];
                }
                dp[i][j]=taken||notTaken;
            }
        }
        return dp[n-1][target];
    }
};


// bottoms up approach(space optimized)
class Solution {
public:
    bool canPartition(vector<int>& arr) {
        int n=arr.size();
        int sum=0;
        for(int x:arr){
            sum+=x;
        }
        if(sum%2!=0) return false;
        int target=sum/2;
        vector<bool> prev(target+1,false);
        prev[0]=true;
        if(target>=arr[0]){
            prev[arr[0]]=true;
        }
        for(int i=1; i<n; i++){
            vector<bool> curr(target+1,false);
            curr[0]=true;
            for(int j=1; j<=target; j++){
                bool notTaken= prev[j];
                bool taken=false;
                if(j>=arr[i]){
                    taken=prev[j-arr[i]];
                }
                curr[j]=taken||notTaken;
            }
            prev=curr;
        }
        return prev[target];
    }
};




//213. House Robber II
Solved
Medium
Topics
Companies
Hint
Google
Amazon
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
Example 2:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 3:

Input: nums = [1,2,3]
Output: 3
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 1000




// solution
class Solution {
private:
    int f(int ind ,vector<int> &arr){
        int prev2=0;
        int prev=arr[0];
        for(int i=1; i<arr.size(); i++){
            int taken =arr[i];
            if(i>1){
                taken+=prev2;
            }
            int notTaken=prev;
            int curr=max(taken,notTaken);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
public:
    int rob(vector<int>& arr) {
        int n=arr.size();
        if(n==1) return arr[0];
        if(n==2) return max(arr[0],arr[1]);
        vector<int> t1,t2;
        for(int i=0; i<n; i++){
            if(i!=0) t2.push_back(arr[i]);
            if(i!=n-1) t1.push_back(arr[i]);
        }
        return max(f(n-2,t1),f(n-2,t2));
    }
};