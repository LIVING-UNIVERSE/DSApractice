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



//Print all LCS sequences
Difficulty: HardAccuracy: 30.64%Submissions: 46K+Points: 8
You are given two strings s and t. Now your task is to print all longest common sub-sequences in lexicographical order.

Note -  A Sub-sequence is derived from another string by deleting some or none of the elements without changing the order of the remaining elements.

Example 1:

Input: s = abaaa, t = baabaca
Output: aaaa abaa baaa
Explanation - Length of lcs is 4, in lexicographical order they are aaaa, abaa, baaa

Example 2:

Input: s = aaa, t = a
Output: a
Your Task:
You do not need to read or print anything. Your task is to complete the function all_longest_common_subsequences() which takes strings s and t as first and second parameters respectively and returns a list of strings which contains all possible longest common subsequences in lexicographical order.
 

Expected Time Complexity: O(n3)
Expected Space Complexity: O(k * n) where k is a constant less than n.
 

Constraints:
1 ≤ Length of both strings ≤ 50


// top down approach
class Solution {
  private:
    static bool my_compare(string a, string b) {
        // If one string is a prefix of the other, longer string comes first
        if (a.compare(0, b.size(), b) == 0 || b.compare(0, a.size(), a) == 0)
            return a.size() > b.size();
        else
            return a < b; // Otherwise, lexicographical order
    }

    vector<string> f(int ind1, int ind2, string s, string t, vector<vector<vector<string>>> &dp) {
        if (ind1 < 0 || ind2 < 0) {
            vector<string> temp = {""};
            return temp;
        }
        if (!dp[ind1][ind2].empty()) // Check if already computed
            return dp[ind1][ind2];

        if (s[ind1] == t[ind2]) {
            vector<string> temp = f(ind1 - 1, ind2 - 1, s, t, dp);
            for (int i = 0; i < temp.size(); i++) {
                temp[i] += s[ind1];
            }
            return dp[ind1][ind2] = temp;
        } else {
            vector<string> temp1 = f(ind1 - 1, ind2, s, t, dp);
            vector<string> temp2 = f(ind1, ind2 - 1, s, t, dp);

            int count = 0;
            unordered_set<string> us;

            for (int i = 0; i < temp1.size(); i++) {
                if (temp1[i].size() > count) {
                    count = temp1[i].size();
                }
                us.insert(temp1[i]);
            }
            for (int i = 0; i < temp2.size(); i++) {
                if (temp2[i].size() > count) {
                    count = temp2[i].size();
                }
                us.insert(temp2[i]);
            }

            vector<string> v;
            for (auto i = us.begin(); i != us.end(); i++) {
                if (i->size() == count) {
                    v.push_back(*i);
                }
            }
            return dp[ind1][ind2] = v;
        }
    }

  public:
    vector<string> all_longest_common_subsequences(string s, string t) {
        int n1 = s.size(), n2 = t.size();
        vector<vector<vector<string>>> dp(n1, vector<vector<string>>(n2, vector<string>()));
        vector<string> v = f(n1 - 1, n2 - 1, s, t, dp);
        sort(v.begin(), v.end(), my_compare);
        return v;
    }
};



