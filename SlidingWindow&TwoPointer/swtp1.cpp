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




//424. Longest Repeating Character Replacement
Solved
Medium
Topics
Companies
Google
Amazon
Uber
Adobe
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

 

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.
 

Constraints:

1 <= s.length <= 105
s consists of only uppercase English letters.
0 <= k <= s.length



// brute force 
// t:O(n^2) sp:O(1)
class Solution {
    public:
        int characterReplacement(string s, int k) {
            int n=s.size();
            if(n==1) return 1;
            int maxLength=0;
            for(int i=0; i<n; i++){
                int length=0;
                for(int j=i;j<n;j++){
                    int count=0;
                    int maxCount=0;
                    for(int l=i;l<=j;l++){
                        if(s[l]!=s[j]){
                            count++;
                        }
                        maxCount=max(maxCount,count);
                    }
                    if(maxCount<=k){
                        length=j-i+1;
                        maxLength=max(maxLength,length);
                    }
                }
            }
            return maxLength;
        }
};


// better solution
// t:(O(n)+O(n))*26 sp:O(1)
class Solution {
    public:
        int characterReplacement(string s, int k) {
            int n=s.size();
            int l=0,r=0,maxLength=0,maxFreq=0;
            vector<int> hash(26,0);
            while(r<n){
                hash[s[r]-'A']++;
                if(hash[s[r]-'A']>maxFreq){
                    maxFreq=hash[s[r]-'A'];
                }
                int reqOp=r-l+1-maxFreq;
                while(reqOp>k){
                    hash[s[l]-'A']--;
                    l++;
                    maxFreq=*max_element(hash.begin(),hash.end());
                    reqOp=r-l+1-maxFreq;
                }
                maxLength=max(r-l+1,maxLength);
                r++;
            }
            return maxLength;
        }
};


// better solution
// t:O(n)+O(n) sp:O(1)
class Solution {
    public:
        int characterReplacement(string s, int k) {
            int n=s.size();
            int l=0,r=0,maxLength=0,maxFreq=0;
            vector<int> hash(26,0);
            while(r<n){
                hash[s[r]-'A']++;
                if(hash[s[r]-'A']>maxFreq){
                    maxFreq=hash[s[r]-'A'];
                }
                int reqOp=r-l+1-maxFreq;
                while(reqOp>k){
                    hash[s[l]-'A']--;
                    l++;
                    reqOp=r-l+1-maxFreq;
                }
                maxLength=max(r-l+1,maxLength);
                r++;
            }
            return maxLength;
        }
};



// optimal solution
// t:O(n) sp:O(1)
class Solution {
    public:
        int characterReplacement(string s, int k) {
            int n=s.size();
            int l=0,r=0,maxLength=0,maxFreq=0;
            vector<int> hash(26,0);
            while(r<n){
                hash[s[r]-'A']++;
                if(hash[s[r]-'A']>maxFreq){
                    maxFreq=hash[s[r]-'A'];
                }
                int reqOp=r-l+1-maxFreq;
                if(reqOp>k){
                    hash[s[l]-'A']--;
                    l++;
                    reqOp=r-l+1-maxFreq;
                }
                maxLength=max(r-l+1,maxLength);
                r++;
            }
            return maxLength;
        }
};




//930. Binary Subarrays With Sum
Solved
1592
Medium
Topics
Companies
Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.

 

Example 1:

Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
Example 2:

Input: nums = [0,0,0,0,0], goal = 0
Output: 15
 

Constraints:

1 <= nums.length <= 3 * 104
nums[i] is either 0 or 1.
0 <= goal <= nums.length


// brute force
// t:O(n^2) sp:O(1)
class Solution {
    public:
        int numSubarraysWithSum(vector<int>& arr, int goal) {
            int n=arr.size();
            int res=0;
            for(int i=0; i<n; i++){
                int count=0,sum=0;
                for(int j=i;j<n;j++){
                    sum+=arr[j];
                    if(sum==goal) count++;
                }
                res+=count;
            }
            return res;
        }
};

// better solution
// t:O(n)+O(n) sp:O(n)
class Solution {
    public:
        int numSubarraysWithSum(vector<int>& arr, int goal) {
            int n=arr.size();
            int sum=0,count=0;
            unordered_map<int,int> m;
            for(int i=0; i<n; i++){
                sum+=arr[i];
                if(sum==goal){
                    count++;
                }
                if(m.find(sum-goal)!=m.end()){
                    count+=m[sum-goal];
                }
                m[sum]++;
            }
            return count;
        }
};

// optimal solution 1
// t:O(n) sp:O(1)
class Solution {
    public:
        int numSubarraysWithSum(vector<int>& arr, int goal) {
            int n=arr.size();
            int l=0,r=0,sum=0,count=0,res=0;
            while(r<n){
                sum+=arr[r];
                while(l<r && (arr[l]==0 || sum>goal)){
                    if(arr[l]==0){
                        count++;
                    }
                    else{
                        count=0;
                        sum-=arr[l];
                    }
                    l++;
                }
                if(sum==goal){
                    res+=1+count;
                }
                r++;
            }
            return res;
        }
};


// optimal solution 2
class Solution {
    private:
        int f(vector<int> &arr,int goal){
            int n=arr.size();
            if(goal<0) return 0;
            int l=0,r=0,sum=0,res=0;
            while(r<n){
                sum+=arr[r];
                while(sum>goal){
                    sum-=arr[l];l++;
                }
                res+=r-l+1;
                r++;
            }
            return res;
        }
    public:
        int numSubarraysWithSum(vector<int>& arr, int goal) {
            return f(arr,goal)-f(arr,goal-1);
        }
};



//1248. Count Number of Nice Subarrays
Solved
1624
Medium
Topics
Companies
Hint
Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.

 

Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
Example 2:

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There are no odd numbers in the array.
Example 3:

Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16
 

Constraints:

1 <= nums.length <= 50000
1 <= nums[i] <= 10^5
1 <= k <= nums.length


// brute force
// t:O(n^2) sp:O(1)
class Solution {
    public:
        int numberOfSubarrays(vector<int>& arr, int k) {
            int n=arr.size();
            int res=0;
            for(int i=0; i<n; i++){
                int count=0;
                for(int j=i;j<n;j++){
                    if(arr[j]%2!=0){
                        count++;
                    }
                    if(count==k){
                        res++;
                    }
                }
            }
            return res;
        }
};


// optimal solution 1
// t:O(n) sp:O(1)
class Solution {
    public:
        int numberOfSubarrays(vector<int>& arr, int k) {
            int n=arr.size();
            int l=0,r=0,count=0,res=0,evenCount=0;
            while(r<n){
                if(arr[r]%2!=0){
                    count++;
                }
                while(l<r &&(arr[l]%2==0 || count>k)){
                    if(arr[l]%2==0){
                        evenCount++;
                    }
                    else{
                        count--;evenCount=0;
                    }
                    l++;
                }
                if(count==k){
                    res+=1+evenCount;
                }
                r++;
            }
            return res;
        }
};



// optimal solution 2
// t:O(n) sp:O(1)
class Solution {
    private:
        int f(vector<int> &arr, int k){
            int n=arr.size(); 
            int l=0,r=0,count=0,res=0;
            while(r<n){
                if(arr[r]%2!=0){
                    count++;
                }
                while(count>k){
                    if(arr[l]%2!=0){
                        count--;
                    }
                    l++;
                }
                res+=r-l+1;
                r++;
            }
            return res;
        }
    public:
        int numberOfSubarrays(vector<int>& arr, int k) {
            return f(arr,k)-f(arr,k-1);
        }
};





//1358. Number of Substrings Containing All Three Characters
Solved
1646
Medium
Topics
Companies
Hint
Microsoft
Adobe
DE Shaw
Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.

 

Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
Example 2:

Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
Example 3:

Input: s = "abc"
Output: 1
 

Constraints:

3 <= s.length <= 5 x 10^4
s only consists of a, b or c characters.



// brute force
// t:O(n^2) sp:O(1)
class Solution {
    public:
        int numberOfSubstrings(string s) {
            int n=s.size();
            int res=0;
            for(int i=0; i<n; i++){
                for(int j=i+2;j<n;j++){
                    unordered_map<char,int> m;
                    for(int k=i;k<=j;k++){
                        m[s[k]]++;
                    }
                    if(m.find('a')!=m.end() && m.find('b')!=m.end() && m.find('c')!=m.end()){
                        res++;
                    }
                }
            }
        }
};


// Optimal solution
// t:O(n) sp:O(1)
class Solution {
    public:
        int numberOfSubstrings(string s) {
            int n=s.size();
            int l=0,r=0,res=0;
            vector<int> hash(3,-1);
            while(r<n){
                hash[s[r]-'a']=r;
                if(hash[0]!=-1 && hash[1]!=-1 && hash[2]!=-1){
                    res+=*min_element(hash.begin(),hash.end())+1;
                }
                r++;
            }
            return res;
        }
};