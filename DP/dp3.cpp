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




//Longest Common Substring
Difficulty: MediumAccuracy: 42.69%Submissions: 260K+Points: 4
You are given two strings s1 and s2. Your task is to find the length of the longest common substring among the given strings.

Examples:

Input: s1 = "ABCDGH", s2 = "ACDGHR"
Output: 4
Explanation: The longest common substring is "CDGH" with a length of 4.
Input: s1 = "abc", s2 = "acb"
Output: 1
Explanation: The longest common substrings are "a", "b", "c" all having length 1.
Input: s1 = "YZ", s2 = "yz"
Output: 0
Constraints:
1 <= s1.size(), s2.size() <= 103
Both strings may contain upper and lower case alphabets.




// tabular solution
(some problems are can only be efficiently solved by tabular method. Here if s1[ind1]==s2[ind2] we add 1 to previous call and 
if they dont match just put zero and not always dp[n-1][m-1] will give you answer; just like here we had to take maximum of 
all elements in the table)

class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        int n1=s1.size(),n2=s2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        int res=0;
        for(int i=1;i<=n1; i++){
            for(int j=1; j<=n2;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                    res=max(res,dp[i][j]);
                }
            }
        }
        return res;
    }
};





//516. Longest Palindromic Subsequence
Solved
Medium
Topics
Companies
Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
Example 2:

Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
 

Constraints:

1 <= s.length <= 1000
s consists only of lowercase English letters.



//method-1
(using brain -> using lcs(longest common subsequence) on the same string and its reversed string.)
// bottoms up approach
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        string t=s;
        reverse(t.begin(),t.end());
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
    }
};


// bottoms up(space optimized)
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        string t=s;
        reverse(t.begin(),t.end());
        vector<int> prev(n+1,0),curr(n+1,0);
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(s[i-1]==t[j-1]){
                    curr[j]=1+prev[j-1];
                }
                else{
                    curr[j]=max(prev[j],curr[j-1]);
                }
            }
            prev=curr;
        }
        return prev[n];
    }
};



// method -2

// bottoms up approach
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0; i<n; i++){
            dp[i][i]=1;
        }
        for(int i=n-1; i>=0; i--){
            for(int j=i+1;j<n; j++){
                if(s[i]==s[j]) dp[i][j]=2+dp[i+1][j-1];
                else{
                    dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];
    }
};

// bottoms up (space optimized)
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        // vector<vector<int>> dp(n,vector<int>(n,0));
        vector<int> prev(n,0);
        prev[0]=1;
        for(int i=n-1; i>=0; i--){
            vector<int> curr(n,0);
            curr[i]=1;
            for(int j=i+1;j<n; j++){
                if(s[i]==s[j]) curr[j]=2+prev[j-1];
                else{
                    curr[j]=max(prev[j],curr[j-1]);
                }
            }
            prev=curr;
        }
        return prev[n-1];
    }
};





//1312. Minimum Insertion Steps to Make a String Palindrome
Solved
1787
Hard
Topics
Companies
Hint
Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.

 

Example 1:

Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we do not need any insertions.
Example 2:

Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".
Example 3:

Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".
 

Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.



NOTE-> MOST OF THE DP ON STRING QUESTIONS CAN BE SOLVED BY USING LCS(LONGEST COMMON SUBSEQUENCE) .
// bottoms up approach
    class Solution {
public:
    int minInsertions(string s) {
        string t=s;
        reverse(t.begin(),t.end());
        int n=s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=1; i<=n; i++){
            for(int j=1;j<=n; j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return n-dp[n][n];
    }
};



// bottoms up approach(space optimized);
class Solution {
public:
    int minInsertions(string s) {
        string t=s;
        reverse(t.begin(),t.end());
        int n=s.size();
        // vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        vector<int> prev(n+1,0),curr(n+1,0);
        for(int i=1; i<=n; i++){
            for(int j=1;j<=n; j++){
                if(s[i-1]==t[j-1]){
                    curr[j]=1+prev[j-1];
                }
                else{
                    curr[j]=max(prev[j],curr[j-1]);
                }
            }
            prev=curr;
        }
        return n-prev[n];
    }
};




//583. Delete Operation for Two Strings
Solved
Medium
Topics
Companies
Amazon
Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

In one step, you can delete exactly one character in either string.

 

Example 1:

Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
Example 2:

Input: word1 = "leetcode", word2 = "etco"
Output: 4
 

Constraints:

1 <= word1.length, word2.length <= 500
word1 and word2 consist of only lowercase English letters.


// solution
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1=word1.size(),n2=word2.size();
        // vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        vector<int> prev(n2+1,0),curr(n2+1,0);
        for(int i=1; i<=n1; i++){
            for(int j=1;j<=n2; j++){
                if(word1[i-1]==word2[j-1]){
                    curr[j]=1+prev[j-1];
                }
                else{
                    curr[j]=max(prev[j],curr[j-1]);
                }
            }
            prev=curr;
        }
        return n1+n2-2*prev[n2];
    }
};