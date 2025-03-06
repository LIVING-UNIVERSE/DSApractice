//Longest Substring with K Uniques
Difficulty: MediumAccuracy: 34.65%Submissions: 179K+Points: 4
Given a string s, you need to print the size of the longest possible substring with exactly k unique characters. If no possible substring exists, print -1.

Examples:

Input: s = "aabacbebebe", k = 3
Output: 7
Explanation: "cbebebe" is the longest substring with 3 distinct characters.
Input: s = "aaaa", k = 2
Output: -1
Explanation: There's no substring with 2 distinct characters.
Input: s = "aabaaab", k = 2
Output: 7
Explanation: "aabaaab" is the longest substring with 2 distinct characters.
Constraints:
1 ≤ s.size() ≤ 105
1 ≤ k ≤ 26
All characters are lowercase letters


// brute force
// t:O(n^2) sp:O(1)
class Solution {
    public:
      int longestKSubstr(string &s, int k) {
          int n=s.size();
          int res=0;
          for(int i=0; i<n; i++){
              unordered_map<char,int> m;
              int count=0;
              for(int j=i;j<n;j++){
                  if(m.find(s[j])==m.end() && m.size()==k){
                      break;
                  }
                  m[s[j]]++;count++;
              }
              if(i==0 && m.size()<k) return -1;
              res=max(res,count);
          }
          return res;
      }
};



// better solultion 
// t:O(n)+O(n) sp:O(1)

// User function template for C++

class Solution {
    public:
      int longestKSubstr(string &s, int k) {
          int n=s.size();
          int l=0,r=0,maxLength=-1,length;
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
              if(m.size()==k){
                  length=r-l+1;
                  maxLength=max(maxLength,length);
              }
              r++;
          }
          return maxLength;
      }
};


// optimal solution
// t:O(n) sp:O(1)
class Solution {
    public:
      int longestKSubstr(string &s, int k) {
          int n=s.size();
          int l=0,r=0,maxLength=-1,length;
          unordered_map<char,int> m;
          while(r<n){
              m[s[r]]++;
              if(m.size()>k){
                  m[s[l]]--;
                  if(m[s[l]]==0){
                      m.erase(s[l]);
                  }
                  l++;
              }
              if(m.size()==k){
                  length=r-l+1;
                  maxLength=max(length,maxLength);
              }
              r++;
          }
          return maxLength;
      }
  };




//992. Subarrays with K Different Integers
Solved
2210
Hard
Topics
Companies
Hint
Given an integer array nums and an integer k, return the number of good subarrays of nums.

A good array is an array where the number of different integers in that array is exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
Example 2:

Input: nums = [1,2,1,3,4], k = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
 

Constraints:

1 <= nums.length <= 2 * 104
1 <= nums[i], k <= nums.length



// optimal solution
// t:O(n) sp:O(1)
class Solution {
    private:
        int f(vector<int> &arr, int k){
            int n=arr.size();
            if(k<=0) return 0;
            int l=0,r=0,res=0;
            unordered_map<int,int> m;
            while(r<n){
                m[arr[r]]++;
                while(m.size()>k){
                    m[arr[l]]--;
                    if(m[arr[l]]==0){
                        m.erase(arr[l]);
                    }
                    l++;
                }
                res+=r-l+1;
                r++;
            }
            return res;
        }
    public:
        int subarraysWithKDistinct(vector<int>& arr, int k) {
            return f(arr,k)-f(arr,k-1);
        }
};