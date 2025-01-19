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



// NOTE-> important for LIS.
// so there are three methods to solve LIS(longest increasing subsequence) problem ->
// (1).  using simple recursion and memoization for memoization you have to index shifiting which is done by making the whole logic as it is 
//      but in dp array you have to insert (ind + amount by which index is shifted); 
//      just changes in dp array
//      t: O(n*n);
//      s: O(n*n) + O(n)
//            ^      ^
//   for dp array  recursion call stack   

class Solution {
  private:
    int f(int ind,int prev_ind,vector<int> &arr,vector<vector<int>> &dp){
        if(ind==arr.size()) return 0;
        if(dp[ind][prev_ind+1]!=-1) return dp[ind][prev_ind+1];
        int notTaken=f(ind+1,prev_ind,arr,dp);
        int taken=0;
        if(prev_ind==-1 || arr[ind]>arr[prev_ind]){
            taken=1+f(ind+1,ind,arr,dp);
        }
        return dp[ind][prev_ind+1]=max(taken,notTaken);
    }
  public:
    // Function to find length of longest increasing subsequence.
    int lis(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return f(0,-1,arr,dp);
    }
};


// (2.) using tabular form and space optimization
//    t:O(n*n)
//    s:O(n*n)

class Solution {
  public:
    // Function to find length of longest increasing subsequence.
    int lis(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=n-1; i>=0; i--){
            for(int j=n-1;j>=-1; j--){
                int notTaken=dp[i+1][j+1];
                int taken=0;
                if(j==-1 || arr[i]>arr[j]){
                    taken=1+dp[i+1][i+1];
                }
                dp[i][j+1]=max(taken,notTaken);
            }
        }
        return dp[0][0];
    }
};


//     t:O(n*n)
//     s:O(n)
class Solution {
  public:
    // Function to find length of longest increasing subsequence.
    int lis(vector<int>& arr) {
        int n=arr.size();
        // vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        vector<int> prev(n+1,0),curr(n+1,0);
        for(int i=n-1; i>=0; i--){
            for(int j=n-1;j>=-1; j--){
                int notTaken=prev[j+1];
                int taken=0;
                if(j==-1 || arr[i]>arr[j]){
                    taken=1+prev[i+1];
                }
                curr[j+1]=max(taken,notTaken);
            }
            prev=curr;
        }
        return prev[0];
    }
};



//  (3). You can also do this in O(nlogn) time using binary search on dp
//    t:O(n*log(n))
//    s:O(n);
class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n=arr.size();
        vector<int> v;
        v.push_back(arr[0]);
        for(int i=1; i<n ;i++){
            if(arr[i]>v[v.end()-1-v.begin()]){
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



//     (4). This tabular method has no intuitive logic you have to learn/cram it ; this is specifically used for printing the
//         exact LIS for a given array
//         t:O(n*n)
//         s:O(n)

class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n=arr.size();
        vector<int> dp(n,1);
        int res=1;
        for(int i=1; i<n; i++){
            for(int j=i-1; j>=0; j--){
                if(arr[j]<arr[i]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            res=max(res,dp[i]);
        }
        return res;
    }
};





//Print Longest Increasing Subsequence
Difficulty: MediumAccuracy: 51.81%Submissions: 28K+Points: 4
Given an integer n and an array of integers arr, return the Longest Increasing Subsequence which is Index-wise lexicographically smallest.
Note - A subsequence S1 is Index-wise lexicographically smaller than a subsequence S2 if in the first position where S1 and S2 differ, subsequence S1 has an element that appears earlier in the array  arr than the corresponding element in S2.
LIS  of a given sequence is defined as that longest possible subsequence all of whose elements are in increasing order. For example, the length of LIS for {10, 22, 9, 33, 21, 50, 41, 60, 80} is 6 and the LIS is {10, 22, 33, 50, 60, 80}. 

Example 1:

Input:
n = 16
arr = [0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15]
Output:
0 4 6 9 13 15 
Explanation:
longest Increasing subsequence is 0 4 6 9 13 15  and the length of the longest increasing subsequence is 6.
Example 2:

Input:
n = 1
arr = [1]
Output:
1
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function longestIncreasingSubsequence() which takes integer n and array arr and returns the longest increasing subsequence.

// Expected Time Complexity: O(n2)
// Expected Space Complexity: O(n)

// Constraint:
// 1 <= n < = 103
// 0 <= arr[i] <= 109



// using the same t:O(n*n) tabular approach stated above
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        if(n==1) return {1};
        vector<int> dp(n,1);
        vector<int> temp(n,0);
        int res=0,ind;
        for(int i=1; i<n; i++){
            temp[i]=i;
            for(int j=i-1; j>=0;j--){
                if(arr[j]<arr[i] && dp[j]+1>=dp[i]){
                    temp[i]=j;
                    dp[i]=dp[j]+1;
                }
            }
            if(dp[i]>res){
                res=dp[i];
                ind=i;
            }
        }
        vector<int> ans;
        while(res>0){
            ans.push_back(arr[ind]);
            ind =temp[ind];
            res--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};




//368. Largest Divisible Subset
Solved
Medium
Topics
Companies
Google
Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.
Example 2:

Input: nums = [1,2,4,8]
Output: [1,2,4,8]
 

Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 2 * 109
All the integers in nums are unique.



// since we have tor return an array we have to use the tabular approach of LIS
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n=arr.size();
        if(n==1) return arr;
        sort(arr.begin(),arr.end());
        vector<int> dp(n,1);
        vector<int> temp(n);
        int res=0,ind=-1;
        for(int i=1; i<n; i++){
            for(int j=0; j<i;j++){
                if(arr[i]%arr[j]==0 && dp[j]+1>=dp[i]){
                    temp[i]=j;
                    dp[i]=dp[j]+1;
                }
            }
            if(dp[i]>res){
                res=dp[i];
                ind=i;
            }
        }
        vector<int> ans;
        while(res>0){
            ans.push_back(arr[ind]);
            ind=temp[ind];
            res--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};




//1048. Longest String Chain
Solved
1599
Medium
Topics
Companies
Hint
You are given an array of words where each word consists of lowercase English letters.

wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

Return the length of the longest possible word chain with words chosen from the given list of words.

 

Example 1:

Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
Example 2:

Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
Output: 5
Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].
Example 3:

Input: words = ["abcd","dbqca"]
Output: 1
Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.
 

Constraints:

1 <= words.length <= 1000
1 <= words[i].length <= 16
words[i] only consists of lowercase English letters.


// solution
class Solution {
private:
    static bool comparator(string a, string b){
        return a.size()<b.size();
    }
public:
    int longestStrChain(vector<string>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end(),comparator);
        vector<int> dp(n,1);
        int res=1;
        for(int i=1; i<n; i++){
            for(int j=0;j<i;j++){
                if(arr[j].size()==arr[i].size()-1 && dp[j]+1>=dp[i]){
                    int count=0,a=0,b=0;
                    while(a<arr[i].size() && b<arr[j].size()){
                        if(arr[i][a]!=arr[j][b]){
                            a++;count++;
                        }
                        else{
                            a++;b++;
                        }
                    }
                    if(count<=1){
                        dp[i]=dp[j]+1;
                    }
                }
            }
            res=max(res,dp[i]);
        }
        return res;
    }
};



//Longest Bitonic subsequence
Difficulty: MediumAccuracy: 47.34%Submissions: 103K+Points: 4
Given an array of positive integers. Find the maximum length of Bitonic subsequence. 
A subsequence of array is called Bitonic if it is first strictly increasing, then strictly decreasing. Return the maximum length of bitonic subsequence.
 
Note : A strictly increasing or a strictly decreasing sequence should not be considered as a bitonic sequence

Examples :

Input: n = 5, nums[] = [1, 2, 5, 3, 2]
Output: 5
Explanation: The sequence {1, 2, 5} is increasing and the sequence {3, 2} is decreasing so merging both we will get length 5.
Input: n = 8, nums[] = [1, 11, 2, 10, 4, 5, 2, 1]
Output: 6
Explanation: The bitonic sequence {1, 2, 10, 4, 2, 1} has length 6.
Input: n = 5, nums[] = [10, 20, 30]
Output: 0
Explanation: The decreasing or increasing part cannot be empty
Input: n = 3, nums[] = [10, 10, 10]
Output: 0
Explanation: The subsequences must be strictly increasing or decreasing
Constraints:
1 ≤ length of array ≤ 103
1 ≤ arr[i] ≤ 104



// solution
class Solution {
  private:
    vector<int> f(vector<int> &arr){
        int n=arr.size();
        vector<int> dp(n,1);
        for(int i=1; i<n; i++){
            for(int j=0;j<i; j++){
                if(arr[j]<arr[i]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        return dp;
    }
  public:
    int LongestBitonicSequence(int n, vector<int> &arr) {
        vector<int> dpi =f(arr);
        vector<int> v=arr;
        reverse(v.begin(),v.end());
        vector<int> dpd =f(v);
        reverse(dpd.begin(),dpd.end());
        int res=0;
        for(int i=0; i<n ;i++){
            if(dpi[i]>1 && dpd[i]>1){
                res=max(res,dpi[i]+dpd[i]-1);
            }
        }
        return res;
    }
};