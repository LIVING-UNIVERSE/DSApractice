//451. Sort Characters By Frequency
Solved
Medium
Topics
Companies
Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.

 

Example 1:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
 

Constraints:

1 <= s.length <= 5 * 105
s consists of uppercase and lowercase English letters and digits.

// brute force
// t:O(nlogn) sp:O(n)
class Solution {
    private:
        static bool cmp(pair<char,int> a,pair<char,int> b){
            return a.second>b.second;
        }
    public:
        string frequencySort(string s) {
            unordered_map<char,int> m;
            string res="";
            for(int i=0; i<s.size(); i++){
                m[s[i]]++;
            }
            vector<pair<char,int>> v;
            for(auto it=m.begin();it!=m.end();it++){
                v.push_back({it->first,it->second});
            }
            sort(v.begin(),v.end(),cmp);
            for(int i=0; i<v.size(); i++){
                while(v[i].second--){
                    res+=v[i].first;
                }
            }
            return res;
        }
};



// optimal solution
// t:O(n) sp:O(n)
class Solution {
    private:
        static bool cmp(pair<char,int> a,pair<char,int> b){
            return a.second>b.second;
        }
    public:
        string frequencySort(string s) {
            string res="";
            vector<pair<char,int>> v(256);
            for(int i=0; i<256; i++){
                char c=i;
                v[i]={c,0};
            }
            for(int i=0; i<s.size(); i++){
                int val=s[i];
                v[val].second++;
            }
            sort(v.begin(),v.end(),cmp);
            for(int i=0; i<256; i++){
                while(v[i].second--){
                    res+=v[i].first;
                }
            }
            return res;
        }
};



//1614. Maximum Nesting Depth of the Parentheses
Solved
1323
Easy
Topics
Companies
Hint
Bloomberg
Facebook
Given a valid parentheses string s, return the nesting depth of s. The nesting depth is the maximum number of nested parentheses.

 

Example 1:

Input: s = "(1+(2*3)+((8)/4))+1"

Output: 3

Explanation:

Digit 8 is inside of 3 nested parentheses in the string.

Example 2:

Input: s = "(1)+((2))+(((3)))"

Output: 3

Explanation:

Digit 3 is inside of 3 nested parentheses in the string.

Example 3:

Input: s = "()(())((()()))"

Output: 3

 

Constraints:

1 <= s.length <= 100
s consists of digits 0-9 and characters '+', '-', '*', '/', '(', and ')'.
It is guaranteed that parentheses expression s is a VPS.


// brute force
// t:O(n) sp:O(n)
class Solution {
    public:
        int maxDepth(string s) {
            stack<char> st;
            int res=0;
            for(int i=0;i<s.size();i++){
                if(s[i]=='('){
                    st.push('(');
                    int size=st.size();
                    res=max(res,size);
                }
                else if(s[i]==')' && !st.empty()){
                    st.pop();
                }
            }
            return res;
        }
};


// optimal solution
// t:O(n) sp:O(1)
class Solution {
    public:
        int maxDepth(string s) {
            int depth=0;
            int res=0;
            for(int i=0;i<s.size();i++){
                if(s[i]=='('){
                    depth++;
                    res=max(res,depth);
                }
                else if(s[i]==')'){
                    depth--;
                }
            }
            return res;
        }
};



//13. Roman to Integer
Solved
Easy
Topics
Companies
Hint
Amazon
Adobe
Apple
Google
Bloomberg
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.

 

Example 1:

Input: s = "III"
Output: 3
Explanation: III = 3.
Example 2:

Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
Example 3:

Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 

Constraints:

1 <= s.length <= 15
s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
It is guaranteed that s is a valid roman numeral in the range [1, 3999].


// solution
class Solution {
    private:
        int f(char c){
            if(c=='I') return 1;
            if(c=='V') return 5;
            if(c=='X') return 10;
            if(c=='L') return 50;
            if(c=='C') return 100;
            else if(c=='D') return 500;
            return 1000;
        }
    public:
        int romanToInt(string s) {
            int x=0,y=0;
            int val=0;
            for(int i=s.size()-1; i>=0;i--){
                int x=f(s[i]);
                if(x>=y){
                    val+=x;
                }
                else{
                    val-=x;
                }
                y=x;
            }
            return val;
        }
};



//205. Isomorphic Strings
Solved
Easy
Topics
Companies
Amazon
LinkedIn
Google
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 

Example 1:

Input: s = "egg", t = "add"

Output: true

Explanation:

The strings s and t can be made identical by:

Mapping 'e' to 'a'.
Mapping 'g' to 'd'.
Example 2:

Input: s = "foo", t = "bar"

Output: false

Explanation:

The strings s and t can not be made identical as 'o' needs to be mapped to both 'a' and 'r'.

Example 3:

Input: s = "paper", t = "title"

Output: true

 

Constraints:

1 <= s.length <= 5 * 104
t.length == s.length
s and t consist of any valid ascii character.


// solution
class Solution {
    public:
        bool isIsomorphic(string s, string t) {
            unordered_map<char,char> m1;
            unordered_map<char,char> m2;
            for(int i=0;i<s.size();i++){
                if(m1.find(s[i])!=m2.end() && m1[s[i]]!=t[i]) return false;
                if(m2.find(t[i])!=m2.end() && m2[t[i]]!=s[i]) return false;
                m1[s[i]]=t[i];m2[t[i]]=s[i];
            }
            return true;
        }
};


//8. String to Integer (atoi)
Solved
Medium
Topics
Companies
Facebook
Microsoft
Amazon
Google
Bloomberg
Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

The algorithm for myAtoi(string s) is as follows:

Whitespace: Ignore any leading whitespace (" ").
Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.
Return the integer as the final result.

 

Example 1:

Input: s = "42"

Output: 42

Explanation:

The underlined characters are what is read in and the caret is the current reader position.
Step 1: "42" (no characters read because there is no leading whitespace)
         ^
Step 2: "42" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "42" ("42" is read in)
           ^
Example 2:

Input: s = " -042"

Output: -42

Explanation:

Step 1: "   -042" (leading whitespace is read and ignored)
            ^
Step 2: "   -042" ('-' is read, so the result should be negative)
             ^
Step 3: "   -042" ("042" is read in, leading zeros ignored in the result)
               ^
Example 3:

Input: s = "1337c0d3"

Output: 1337

Explanation:

Step 1: "1337c0d3" (no characters read because there is no leading whitespace)
         ^
Step 2: "1337c0d3" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "1337c0d3" ("1337" is read in; reading stops because the next character is a non-digit)
             ^
Example 4:

Input: s = "0-1"

Output: 0

Explanation:

Step 1: "0-1" (no characters read because there is no leading whitespace)
         ^
Step 2: "0-1" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "0-1" ("0" is read in; reading stops because the next character is a non-digit)
          ^
Example 5:

Input: s = "words and 987"

Output: 0

Explanation:

Reading stops at the first non-digit character 'w'.

 

Constraints:

0 <= s.length <= 200
s consists of English letters (lower-case and upper-case), digits (0-9), ' ', '+', '-', and '.'.


// optimal solution
// t:O(n) sp:O(1)
class Solution {
    public:
        int myAtoi(string s) {
            int i=0,sign=1;
            int n=s.size();
            long long val=0;
            while(i<n && s[i]==' '){
                i++;
            }
            if(i<n &&(s[i]=='-' || s[i]=='+')){
                sign=(s[i]=='-')?-1:1;i++;
            }
            while(i<n && s[i]=='0'){
                i++;
            }
            while(i<n && isdigit(s[i])){
                val=val*10LL + (long long)(s[i]-'0');
                if(val>INT_MAX){
                    return (sign==1)?INT_MAX:INT_MIN;
                }
                i++;
            }
            return sign*val;
        }
};



//Substrings with K Distinct
Difficulty: MediumAccuracy: 20.46%Submissions: 146K+Points: 4Average Time: 20m
Given a string s of lowercase alphabets, count all possible substrings (not necessarily distinct) that have exactly k distinct characters. 

Examples :

Input: s = "aba", k = 2
Output: 3
Explanation: The substrings are: "ab", "ba" and "aba".
Input: s = "abaaca", k = 1
Output: 7
Explanation: The substrings are: "a", "b", "a", "aa", "a", "c", "a".
Input: s = "cdad", k = 4
Output: 0
Constraints:
1 ≤ s.size() ≤ 106
1 ≤ k ≤ 26


// optimal solution
// t:O(n)+O(n) sp:O(1)
// always remember that the number of substrings of a string of length n is n*(n+1)/2
// always remember for calculating number of substrings with given condition always use f(k)-f(k-1) algorithm ; always works
class Solution {
    private:
      int f(string &s,int k){
          int l=0,r=0,count=0;
          int n=s.size();
          unordered_map<char,int> m;
          while(r<n){
              m[s[r]]++;
              while(m.size()>k){
                  m[s[l]]--;
                  if(m[s[l]]==0){
                      m.erase(s[l]);
                  }
                  l++;
              }
              count+=(r-l+1);
              r++;
          }
          return count;
      }
    public:
      int countSubstr(string& s, int k) {
          return f(s,k)-f(s,k-1);
      }
};