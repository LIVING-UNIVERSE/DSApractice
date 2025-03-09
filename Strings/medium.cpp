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