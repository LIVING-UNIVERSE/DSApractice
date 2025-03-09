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