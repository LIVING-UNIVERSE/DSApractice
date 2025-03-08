//1021. Remove Outermost Parentheses
Solved
1311
Easy
Topics
Companies
Hint
Microsoft
A valid parentheses string is either empty "", "(" + A + ")", or A + B, where A and B are valid parentheses strings, and + represents string concatenation.

For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.
A valid parentheses string s is primitive if it is nonempty, and there does not exist a way to split it into s = A + B, with A and B nonempty valid parentheses strings.

Given a valid parentheses string s, consider its primitive decomposition: s = P1 + P2 + ... + Pk, where Pi are primitive valid parentheses strings.

Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.

 

Example 1:

Input: s = "(()())(())"
Output: "()()()"
Explanation: 
The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
After removing outer parentheses of each part, this is "()()" + "()" = "()()()".
Example 2:

Input: s = "(()())(())(()(()))"
Output: "()()()()(())"
Explanation: 
The input string is "(()())(())(()(()))", with primitive decomposition "(()())" + "(())" + "(()(()))".
After removing outer parentheses of each part, this is "()()" + "()" + "()(())" = "()()()()(())".
Example 3:

Input: s = "()()"
Output: ""
Explanation: 
The input string is "()()", with primitive decomposition "()" + "()".
After removing outer parentheses of each part, this is "" + "" = "".
 

Constraints:

1 <= s.length <= 105
s[i] is either '(' or ')'.
s is a valid parentheses string.



// solution
class Solution {
    public:
        string removeOuterParentheses(string s) {
            int n=s.size(),count=0;
            string res="",temp="";
            for(int i=0; i<n; i++){
                if(s[i]=='('){
                    count++;
                    if(count>1) temp+=s[i];
                }
                if(s[i]==')'){
                    count--;
                    if(count>0) temp+=s[i];
                }
                if(count==0){
                    res+=temp;temp="";
                }
            }
            return res;
        }
};



//151. Reverse Words in a String
Solved
Medium
Topics
Companies
Microsoft
Apple
LinkedIn
Amazon
Google
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

 

Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Constraints:

1 <= s.length <= 104
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.
 

Follow-up: If the string data type is mutable in your language, can you solve it in-place with O(1) extra space?


// brute force
// t:O(n) sp:O(n)
class Solution {
    public:
        string reverseWords(string s) {
            int n=s.size();
            vector<string> v;
            string temp="";
            for(int i=0; i<n; i++){
                if(s[i]==' '){
                    v.push_back(temp);
                    temp="";
                }
                else{
                    temp+=s[i];
                }
            }
            v.push_back(temp);
            reverse(v.begin(),v.end());
            temp="";
            for(auto x: v){
                if(x!=""){
                    temp+=x;temp+=" ";
                }
            }
            temp.erase(temp.end()-1);
            return temp;
        }
};


// optimal solution (in place)
// t:O(n) sp:O(1)
class Solution {
    public:
        string reverseWords(string s) {
            int n=s.size();
            reverse(s.begin(),s.end());
            int l=0,r=0,i=0;
            for(int i=0; i<n;i++){
                while(i<n && s[i]!=' '){
                    s[r]=s[i];r++;i++;
                }
                if(l<r){
                    reverse(s.begin()+l,s.begin()+r);
                    s[r]=' ';
                    r++;l=r;
                }
            }
            return s.substr(0,r-1);
        }
};