//3. Longest Substring Without Repeating Characters
Solved
Medium
Topics
Companies
Hint
Amazon
Microsoft
Facebook
Bloomberg
Apple
Given a string s, find the length of the longest substring without duplicate characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.


// brute force O(n^2)
class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int n=s.size();
            if(n==0) return 0;
            if(n==1) return 1;
            int res=0;
            for(int i=0; i<n; i++){
                vector<int> hash(256,-1);
                int length=0;
                for(int j=i;j<n;j++){
                    int val=s[j];
                    if(hash[val]==-1){
                        length++;
                        hash[val]=j;
                    }
                    else{
                        res=max(res,length);
                        break;
                    }
                }
                res=max(res,length);
            }
            return res;
        }
};


// optimal solution O(n)
// use constant space of 256 instead of a map
class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int n=s.size();
            if(n==0) return 0;
            unordered_map<char,int> m;
            int res=0,start=0,length=1;
            m[s[0]]=0;
            for(int i=1; i<n; i++){
                if(m.find(s[i])==m.end()){
                    length++;
                    m[s[i]]=i;
                }
                else{
                    if(m[s[i]]>=start){
                        res=max(res,length);
                        int ind=m[s[i]];
                        length=i-ind-1;
                        start=ind+1;
                    }
                    length++;
                    m[s[i]]=i;
                }
            }
            res=max(res,length);
            return res;
        }
};




//1004. Max Consecutive Ones III
Solved
1656
Medium
Topics
Companies
Hint
Facebook
Microsoft
Google
Amazon
ByteDance
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

 

Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
Example 2:

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.
0 <= k <= nums.length


// brute force O(n^2)
class solution{
    public:
        int longestOnes(vector<int>& arr, int k) {
            int n=arr.size();
            int res=0;
            for(int i=0; i<n; i++){
                int count=0;
                for(int j=i;j<n;j++){
                    if(arr[j]==0) count++;
                    if(count>k){
                        break;
                    }
                }
                res=max(res,j-i+1);
            }
            return res;
        }
};


// better solution O(n)+O(n)==O(2n)
//                  ^    ^
//                  |    |
//           (for left) (for right)
class Solution {
    public:
        int longestOnes(vector<int>& arr, int k) {
            int n=arr.size();
            int l=0,r=0,length=0,maxLength=0,count=0;
            while(r<n){
                if(arr[r]==0) count++;
                if(count<=k){
                    length=r-l+1;
                    maxLength=max(length,maxLength);
                }
                else{
                    while(arr[l]==1){
                        l++;
                    }
                    l++;count--;
                }
                r++;
            }
            return maxLength;
        }
};




// opitmal solution O(n)
// use sliding window
class Solution {
    public:
        int longestOnes(vector<int>& arr, int k) {
            int n=arr.size();
            int l=0,r=0,length=0,maxLength=0,count=0;
            while(r<n){
                if(arr[r]==0) count++;
                if(count<=k){
                    length=r-l+1;
                    maxLength=max(length,maxLength);
                }
                else{
                   if(arr[l]==0) count--;
                   l++;
                }
                r++;
            }
            return maxLength;
        }
};