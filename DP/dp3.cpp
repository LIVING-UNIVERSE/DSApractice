//1143. Longest Common Subsequence
Solved
Medium
Topics
Companies
Hint
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
 

Constraints:

1 <= text1.length, text2.length <= 1000
text1 and text2 consist of only lowercase English characters.




// top down approach
class Solution {
private:
    int f(int ind1,int ind2,string t1,string t2,vector<vector<int>> &dp){
        if(ind1==0 || ind2==0) return 0;
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        if(t1[ind1-1]==t2[ind2-1]) return 1+f(ind1-1,ind2-1,t1,t2,dp);
        return max(f(ind1-1,ind2,t1,t2,dp),f(ind1,ind2-1,t1,t2,dp));
    }
public:
    int longestCommonSubsequence(string t1, string t2) {
        int n1=t1.size(),n2=t2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        return f(n1,n2,t1,t2,dp);
        
    }
};


// bottoms up solution
class Solution {
public:
    int longestCommonSubsequence(string t1, string t2) {
        int n1=t1.size(),n2=t2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        for(int i=1; i<=n1; i++){
            for(int j=1; j<=n2; j++){
                if(t1[i-1]==t2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n1][n2];
        
    }
};


// bottoms up approach(space optimized)
class Solution {
public:
    int longestCommonSubsequence(string t1, string t2) {
        int n1=t1.size(),n2=t2.size();
        vector<int> prev(n2+1,0);
        for(int i=1; i<=n1; i++){
            vector<int> curr(n2+1,0);
            for(int j=1; j<=n2; j++){
                if(t1[i-1]==t2[j-1]) curr[j]=1+prev[j-1];
                else{
                    curr[j]=max(prev[j],curr[j-1]);
                }
            }
            prev=curr;
        }
        return prev[n2];
        
    }
};