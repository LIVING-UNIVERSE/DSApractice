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



//1423. Maximum Points You Can Obtain from Cards
Solved
1574
Medium
Topics
Companies
Hint
Google
Amazon
Adobe
There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

 

Example 1:

Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.
Example 2:

Input: cardPoints = [2,2,2], k = 2
Output: 4
Explanation: Regardless of which two cards you take, your score will always be 4.
Example 3:

Input: cardPoints = [9,7,7,9,7,7,9], k = 7
Output: 55
Explanation: You have to take all the cards. Your score is the sum of points of all cards.
 

Constraints:

1 <= cardPoints.length <= 105
1 <= cardPoints[i] <= 104
1 <= k <= cardPoints.length


// otpimal solution O(k)
class Solution {
    public:
        int maxScore(vector<int>& arr, int k) {
            int  n=arr.size();
            int sum=0;
            int l=n-k,r=n-1;
            for(int i=l; i<=r;i++){
                sum+=arr[i];
            }
            int res=sum;
            while(k--){
                sum-=arr[l];
                l=(l+1)%n;r=(r+1)%n;
                sum+=arr[r];
                res=max(res,sum);
            }
            return res;
        }
};



//Find length of the longest subarray containing atmost two distinct integers
Difficulty: MediumAccuracy: 47.98%Submissions: 95K+Points: 4Average Time: 30m
Given an array arr[] containing positive elements, the task is to find the length of the longest subarray of an input array containing at most two distinct integers.

Examples:

Input: arr[]= [2, 1, 2]
Output: 3
Explanation: The entire array [2, 1, 2] contains at most two distinct integers (2 and 1). Hence, the length of the longest subarray is 3.
Input: arr[] = [3, 1, 2, 2, 2, 2]
Output: 5
Explanation: The longest subarray containing at most two distinct integers is [1, 2, 2, 2, 2], which has a length of 5. The subarray starts at the second element 1 and ends at the last element. It contains at most two distinct integers (1 and 2).
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] <=105


// brute force
// t:O(n^2) sp:O(1)
class Solution {
    public:
      int totalElements(vector<int> &arr) {
          int n=arr.size();
          if(n==1) return 1;
          int maxLength=0;
          for(int i=0; i<n; i++){
              unordered_map<int,int> m;
              int length=0;
              for(int j=i;j<n;j++){
                  if(m.find(arr[j])==m.end() && m.size()==2){
                      break;
                  }
                  m[arr[j]]++;
                  length++;
              }
              maxLength=max(length,maxLength);
          }
          return maxLength;
      }
};


// better solution 
// t:O(n)+O(n) sp:O(1)
class Solution {
    public:
      int totalElements(vector<int> &arr) {
          int n=arr.size();
          if(n==1) return 1;
          int maxLength=0;
          for(int i=0; i<n; i++){
              unordered_map<int,int> m;
              int length=0;
              for(int j=i;j<n;j++){
                  if(m.find(arr[j])==m.end() && m.size()==2){
                      break;
                  }
                  m[arr[j]]++;
                  length++;
              }
              maxLength=max(length,maxLength);
          }
          return maxLength;
      }
};



// optimal solution
// t:O(n) sp:O(1)
class Solution {
    public:
      int totalElements(vector<int> &arr) {
          int n=arr.size();
          if(n==1) return 1;
          int l=0,r=0,length=0,maxLength=0;
          unordered_map<int,int> m;
          while(r<n){
              m[arr[r]]++;
              if(m.size()>=3){
                  m[arr[l]]--;
                  if(m[arr[l]]==0){
                      m.erase(arr[l]);
                  }
                  l++;
              }
              length=r-l+1;
              maxLength=max(length,maxLength);
              r++;
          }
          return maxLength;
      }
  };