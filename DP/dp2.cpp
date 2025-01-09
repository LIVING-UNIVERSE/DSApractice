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




//322. Coin Change
Solved
Medium
Topics
Companies
Amazon
Microsoft
Google
Mathworks
Bloomberg
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0
 

Constraints:

1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104



// top down approach
class Solution {
private:
    int f(int ind, int amt, vector<int> &arr,vector<vector<int>> &dp){
        if(amt==0) return 0;
        if(ind ==0){
            if(amt%arr[0]==0) return amt/arr[0];
            return 1e8;
        }
        if(dp[ind][amt]!=-1) return dp[ind][amt];
        int nt=f(ind-1,amt,arr,dp);
        int t=1e8;
        if(amt>=arr[ind]){
            t=1+f(ind,amt-arr[ind],arr,dp);
        }
        return dp[ind][amt]=min(t,nt);
    }
public:
    int coinChange(vector<int>& arr, int amt) {
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(amt+1,-1));
        int ans=f(n-1,amt,arr,dp);
        return (ans==1e8)?-1:ans;
    }
};



// bottoms up aproach
class Solution {
public:
    int coinChange(vector<int>& arr, int amt) {
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(amt+1,1e8));
        for(int i=0; i<n; i++){
            dp[i][0]=0;
        }
        for(int i=1; i<=amt; i++){
            if(i%arr[0]==0) dp[0][i]=i/arr[0];
        }
        for(int i=1; i<n ; i++){
            for(int a=1; a<=amt; a++){
                int nt=dp[i-1][a];
                int t=1e8;
                if(a>=arr[i]){
                    t=1+dp[i][a-arr[i]];
                }
                dp[i][a]=min(t,nt);
            }
        }
        int ans=dp[n-1][amt];
        return (ans==1e8)?-1:ans;
    }
};




// bottoms up(space optimization)
class Solution {
public:
    int coinChange(vector<int>& arr, int amt) {
        int n=arr.size();
        vector<int> prev(amt+1,1e8);
        prev[0]=0;
        for(int i=1; i<=amt; i++){
            if(i%arr[0]==0) prev[i]=i/arr[0];
        }
        for(int i=1; i<n ; i++){
            vector<int> curr(amt+1,1e8);
            curr[0]=0;
            for(int a=1; a<=amt; a++){
                int nt=prev[a];
                int t=1e8;
                if(a>=arr[i]){
                    t=1+curr[a-arr[i]];
                }
                curr[a]=min(t,nt);
            }
            prev=curr;
        }
        int ans=prev[amt];
        return (ans==1e8)?-1:ans;
    }
};





//Perfect Sum Problem
Difficulty: MediumAccuracy: 20.58%Submissions: 450K+Points: 4
Given an array arr of non-negative integers and an integer target, the task is to count all subsets of the array whose sum is equal to the given target.

Examples:

Input: arr[] = [5, 2, 3, 10, 6, 8], target = 10
Output: 3
Explanation: The subsets {5, 2, 3}, {2, 8}, and {10} sum up to the target 10.
Input: arr[] = [2, 5, 1, 4, 3], target = 10
Output: 3
Explanation: The subsets {2, 1, 4, 3}, {5, 1, 4}, and {2, 5, 3} sum up to the target 10.
Input: arr[] = [5, 7, 8], target = 3
Output: 0
Explanation: There are no subsets of the array that sum up to the target 3.
Input: arr[] = [35, 2, 8, 22], target = 0
Output: 1
Explanation: The empty subset is the only subset with a sum of 0.
Constraints:
1 ≤ arr.size() ≤ 103
0 ≤ arr[i] ≤ 103
0 ≤ target ≤ 103


// top down approach
class Solution {
  private:
    int f(int ind, int target, vector<int> &arr,vector<vector<int>> &dp){
        if(ind==0){
            if(target==0 && arr[0]==0) return 2;
            if(target==0) return 1;
            if(arr[0]==target) return 1;
            return 0;
        }
        int nt=f(ind-1,target,arr,dp);
        int t=0;
        if(target>=arr[ind]){
            t=f(ind-1,target-arr[ind],arr,dp);
        }
        return dp[ind][target]=t+nt;
    }
  public:
    int perfectSum(vector<int>& arr, int target) {
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return f(n-1,target,arr,dp);
    }
};



// bottoms up approach
class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(target+1,0));
        if(arr[0]<=target){
            dp[0][arr[0]]=1;
        }
        if(arr[0]==0){
            dp[0][0]=2;
        }
        else{
            dp[0][0]=1;
        }
        for(int i=1; i<n; i++){
            for(int t=0; t<=target; t++){
                int notTaken=dp[i-1][t];
                int taken=0;
                if(t>=arr[i]){
                    taken=dp[i-1][t-arr[i]];
                }
                dp[i][t]=notTaken+taken;
            }
        }
        return dp[n-1][target];
    }
};


// bottoms up approach(space optimized)
class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        int n=arr.size();
        // vector<vector<int>> dp(n,vector<int>(target+1,0));
        vector<int> prev(target+1,0);
        if(arr[0]<=target){
            prev[arr[0]]=1;
        }
        if(arr[0]==0){
            prev[0]=2;
        }
        else{
            prev[0]=1;
        }
        for(int i=1; i<n; i++){
            vector<int> curr(target+1,0);
            for(int t=0; t<=target; t++){
                int notTaken=prev[t];
                int taken=0;
                if(t>=arr[i]){
                    taken=prev[t-arr[i]];
                }
                curr[t]=notTaken+taken;
            }
            prev=curr;
        }
        return prev[target];
    }
};



//Partitions with Given Difference
Difficulty: MediumAccuracy: 36.76%Submissions: 156K+Points: 4
Given an array arr[], partition it into two subsets(possibly empty) such that each element must belong to only one subset. Let the sum of the elements of these two subsets be sum1 and sum2. Given a difference d, count the number of partitions in which sum1 is greater than or equal to sum2 and the difference between sum1 and sum2 is equal to d. 

Examples :

Input: arr[] =  [5, 2, 6, 4], d = 3
Output: 1
Explanation: There is only one possible partition of this array. Partition : {6, 4}, {5, 2}. The subset difference between subset sum is: (6 + 4) - (5 + 2) = 3.
Input: arr[] = [1, 1, 1, 1], d = 0 
Output: 6 
Explanation: We can choose two 1's from indices {0,1}, {0,2}, {0,3}, {1,2}, {1,3}, {2,3} and put them in sum1 and remaning two 1's in sum2.
Thus there are total 6 ways for partition the array arr. 
Input: arr[] = [1, 2, 1, 0, 1, 3, 3], d = 11
Output: 2
Constraint:
1 <= arr.size() <= 50
0 <= d  <= 50
0 <= arr[i] <= 6



//top down approach
class Solution {
  private:
    int f(int ind,int target, vector<int> &arr,vector<vector<int>> &dp){
        if(ind==0){
            if(target==0 && arr[0]==0) return 2;
            if(target==0) return 1;
            if(target==arr[0]) return 1;
            return 0;
        }
        if(dp[ind][target]!=-1) return dp[ind][target];
        int notTaken = f(ind-1,target,arr,dp);
        int taken=0;
        if(target>=arr[ind]){
            taken=f(ind-1,target-arr[ind],arr,dp);
        }
        return dp[ind][target]=taken+notTaken;
    }
  public:
    int countPartitions(vector<int>& arr, int d) {
        // s1-s2=d  ;(s2=t-s1)
        // s1-t+s1=d
        // 2s1=t+d  =>   s1=(t+d)/2
        // => target=(t+d)/2
        int n=arr.size();
        int sum=0;
        for(int i=0; i<n; i++){
            sum+=arr[i];
        }
        if((sum+d)%2!=0) return 0;
        int target=(sum+d)/2;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return f(n-1,target,arr,dp);
    }
};



// bottoms up approach
class Solution {

  public:
    int countPartitions(vector<int>& arr, int d) {
        // s1-s2=d  ;(s2=t-s1)
        // s1-t+s1=d
        // 2s1=t+d  =>   s1=(t+d)/2
        // => target=(t+d)/2
        int n=arr.size();
        int sum=0;
        for(int i=0; i<n; i++){
            sum+=arr[i];
        }
        if((sum+d)%2!=0) return 0;
        int target=(sum+d)/2;
        vector<vector<int>> dp(n,vector<int>(target+1,0));
        if(arr[0]<=target){
            dp[0][arr[0]]=1;
        }
        if(arr[0]==0){
            dp[0][0]=2;
        }
        else{
            dp[0][0]=1;
        }
        for(int i=1; i<n; i++){
            for(int t=0; t<=target; t++){
                int notTaken=dp[i-1][t];
                int taken=0;
                if(t>=arr[i]){
                    taken=dp[i-1][t-arr[i]];
                }
                dp[i][t]=notTaken+taken;
            }
        }
        return dp[n-1][target];
    }
};


// bottoms up approach(space optimized)
class Solution {

  public:
    int countPartitions(vector<int>& arr, int d) {
        // s1-s2=d  ;(s2=t-s1)
        // s1-t+s1=d
        // 2s1=t+d  =>   s1=(t+d)/2
        // => target=(t+d)/2
        int n=arr.size();
        int sum=0;
        for(int i=0; i<n; i++){
            sum+=arr[i];
        }
        if((sum+d)%2!=0) return 0;
        int target=(sum+d)/2;
        vector<vector<int>> dp(n,vector<int>(target+1,0));
        if(arr[0]<=target){
            dp[0][arr[0]]=1;
        }
        if(arr[0]==0){
            dp[0][0]=2;
        }
        else{
            dp[0][0]=1;
        }
        for(int i=1; i<n; i++){
            for(int t=0; t<=target; t++){
                int notTaken=dp[i-1][t];
                int taken=0;
                if(t>=arr[i]){
                    taken=dp[i-1][t-arr[i]];
                }
                dp[i][t]=notTaken+taken;
            }
        }
        return dp[n-1][target];
    }
};




//494. Target Sum
Solved
Medium
Topics
Companies
Facebook
Amazon
Google
Adobe
Bloomberg
You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

 

Example 1:

Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
Example 2:

Input: nums = [1], target = 1
Output: 1
 

Constraints:

1 <= nums.length <= 20
0 <= nums[i] <= 1000
0 <= sum(nums[i]) <= 1000
-1000 <= target <= 1000




//(same as partition with given difference but here targets can be -ve so take absolute of target)
class Solution {
public:
    int findTargetSumWays(vector<int>& arr, int d) {
        int n=arr.size();
        int sum=0;
        for(int i=0; i<n; i++){
            sum+=arr[i];
        }
        d=abs(d);
        if((sum+d)%2!=0) return 0;
        int target=(sum+d)/2;
        // vector<vector<int>> dp(n,vector<int>(target+1,0));
        vector<int> prev(target+1,0);
        if(arr[0]<=target){
            prev[arr[0]]=1;
        }
        if(arr[0]==0){
            prev[0]=2;
        }
        else{
            prev[0]=1;
        }
        for(int i=1; i<n; i++){
            vector<int> curr(target+1,0);
            for(int t=0; t<=target; t++){
                int notTaken=prev[t];
                int taken=0;
                if(t>=arr[i]){
                    taken=prev[t-arr[i]];
                }
                curr[t]=notTaken+taken;
            }
            prev=curr;
        }
        return prev[target];
    }
};



//518. Coin Change II
Attempted
Medium
Topics
Companies
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.

 

Example 1:

Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
Example 3:

Input: amount = 10, coins = [10]
Output: 1
 

Constraints:

1 <= coins.length <= 300
1 <= coins[i] <= 5000
All the values of coins are unique.
0 <= amount <= 5000

// top down approach
class Solution {
private:
    int f(int ind, int target, vector<int> &arr,vector<vector<int>> &dp){
        if(target==0) return 1;
        if(ind==0){
            if(target%arr[0]==0) return 1;
            return 0;
        }
        int notTaken=f(ind-1,target,arr,dp);
        int taken=0;
        if(target>=arr[ind]){
            taken=f(ind,target-arr[ind],arr,dp);
        }
        return notTaken+taken;
    }
public:
    int change(int target, vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return f(n-1,target,arr,dp);
    }
};


// bottoms up approach
class Solution {
public:
    int change(int target, vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(target+1,0));
        for(int i=0; i<n; i++){
            dp[i][0]=1;
        }
        for(int i=1; i<=target; i++){
            if(i%arr[0]==0) {
                dp[0][i]=1;
            }
        }
        for(int i=1; i<n; i++){
            for(int j=1; j<=target;j++){
                long notTaken=dp[i-1][j];
                long taken=0;
                if(j>=arr[i]){
                    taken=dp[i][j-arr[i]];
                }
                dp[i][j]= int(notTaken+taken);
            }
        }
        return dp[n-1][target];
    }
};



// bottoms up approach(space optimization)
class Solution {
public:
    int change(int target, vector<int>& arr) {
        int n=arr.size();
        vector<int> prev(target+1,0);
        prev[0]=0;
        for(int i=1; i<=target; i++){
            if(i%arr[0]==0) {
                prev[i]=1;
            }
        }
        for(int i=1; i<n; i++){
            vector<int> curr(target+1,0);
            curr[0]=1;
            for(int j=1; j<=target;j++){
                long notTaken=prev[j];
                long taken=0;
                if(j>=arr[i]){
                    taken=prev[j-arr[i]];
                }
                curr[j]= int(notTaken+taken);
            }
            prev=curr;
        }
        return prev[target];
    }
};