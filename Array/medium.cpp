1. Two Sum
Solved
Easy
Topics
Companies
Hint
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
 

Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?

// brute force
class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        vector<int> v;
        int n=arr.size();
        for(int i=0 ; i<n-1; i++){
            for(int j=i+1;j<n; j++){
                if(arr[i]+arr[j]==target){
                    v.push_back(i);
                    v.push_back(j);
                }
            }
        }
        return v;
    }
};


//optimal solution  
class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        vector<int> v;
        unordered_map<int,int> m;
        int n=arr.size();
        for(int i=0 ; i<n; i++){
            int f=target-arr[i];
            if(m.find(f)!=m.end()){
                v.push_back(m[f]);
                v.push_back(i);
            }
            m[arr[i]]=i;
        }
        return v;
    }
};



//75. Sort Colors
Solved
Medium
Topics
Companies
Hint
Microsoft
Amazon
VMware
Adobe
Salesforce
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library sort function.

 

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
 

Constraints:

n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.
 

Follow up: Could you come up with a one-pass algorithm using only constant extra space?


// brute force
class Solution {
public:
    void sortColors(vector<int>& arr) {
        int n=arr.size();
        int prev=0,next=n-1;
        for(int i=0; i<n; i++){
            if(arr[i]==0){
                swap(arr[i],arr[prev]);
                prev++;
            }
        }
        for(int i=n-1; i>=0;i--){
            if(arr[i]==2){
                swap(arr[i],arr[next]);
                next--;
            }
        }
    }
};


//optimal solution
class Solution {
public:
    void sortColors(vector<int>& arr) {
        int n=arr.size();
        int low=0,mid=0,high=n-1;
        while(mid<=high){
            if(arr[mid]==0){
                swap(arr[mid],arr[low]);
                low++;mid++;
            }
            else if(arr[mid]==1){
                mid++;
            }
            else{
                swap(arr[mid],arr[high]);
                high--;
            }
        }
    }
};




//169. Majority Element
Solved
Easy
Topics
Companies
Amazon
Microsoft
Adobe
Apple
Google
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 

Constraints:

n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109
 

Follow-up: Could you solve the problem in linear time and in O(1) space?


// time:O(nlogn) and space:O(n) solution
class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int> m;
        for(int i=0; i<n; i++){
            m[arr[i]]++;
        }
        int res;
        for(auto it=m.begin(); it!=m.end(); it++){
            if(it->second > n/2) res=it->first;
        }
        return res;
    }
};


// time:O(nlogn) and space:O(1) better solution
class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int ans=arr[0],len=1;
        for(int i=1; i<n; i++){
            if(arr[i]!=ans){
                ans=arr[i];len=1;
            }
            else{
                len++;
                if(len> n/2) break;
            }
        }
        return ans;
    }
};


// optimal solution(moore's voting algorithm)
class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int n=arr.size();
        int res=arr[0],len=1;
        for(int i=1; i<n; i++){
            if(arr[i]==res){
                len++;
            }
            else if(len==0){
                res=arr[i];
            }
            else{
                len--;
            }
        }
        int count=0;
        for(int i=0; i<n; i++){
            if(arr[i]==res) count++;
        }
        if(count> n/2) return res;
        return -1;
    }
};




//53. Maximum Subarray
Attempted
Medium
Topics
Companies
LinkedIn
Amazon
Apple
Microsoft
Adobe
Given an integer array nums, find the 
subarray
 with the largest sum, and return its sum.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
 

Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.


// brute force
class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int n=arr.size();
        int res=INT_MIN;
        for(int i=0; i<n ;i++){
            int sum=0;
            for(int j=i; j<n; j++){
                sum+=arr[j];
                res=max(res,sum);
            }
        }
        return res;
    }
};


// optimal solution(Kadane's algorithm)
class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int n=arr.size();
        int res=INT_MIN;
        for(int i=0; i<n ;i++){
            int sum=0;
            for(int j=i; j<n; j++){
                sum+=arr[j];
                res=max(res,sum);
            }
        }
        return res;
    }
};


// kadane's second approach
class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int n=arr.size();
        int res=-1e8;
        int maxEnding=-1e8;
        for(int i=0; i<n ;i++){
            maxEnding=max(arr[i],maxEnding+arr[i]);
            res=max(res,maxEnding);
        }
        return res;
    }
};



// divide and conquer approach
class Solution {
    // divide and conquer approach (O(n*logn))
    int f(int l,int r,vector<int> &arr){
        if(l==r) return arr[l];
        int p= l+(r-l)/2;
        int lss=f(l,p,arr);
        int rss=f(p+1,r,arr);
        int css;
        int sum=0,left=INT_MIN;
        for(int i=p;i>=l;i--){
            sum+=arr[i];
            left=max(left,sum);
        }
        sum=0;
        int right=INT_MIN;
        for(int i=p+1; i<=r; i++){
            sum+=arr[i];
            right=max(right,sum);
        }
        css=left+right;
        return max(css,max(rss,lss));
    }
public:
    int maxSubArray(vector<int>& arr) {
        int n=arr.size();
        return f(0,n-1,arr);
    }
};



//Array Leaders
Difficulty: EasyAccuracy: 29.94%Submissions: 810K+Points: 2
You are given an array arr of positive integers. Your task is to find all the leaders in the array. An element is considered a leader if it is greater than or equal to all elements to its right. The rightmost element is always a leader.

Examples:

Input: arr = [16, 17, 4, 3, 5, 2]
Output: [17, 5, 2]
Explanation: Note that there is nothing greater on the right side of 17, 5 and, 2.
Input: arr = [10, 4, 2, 4, 1]
Output: [10, 4, 4, 1]
Explanation: Note that both of the 4s are in output, as to be a leader an equal element is also allowed on the right. side
Input: arr = [5, 10, 20, 40]
Output: [40]
Explanation: When an array is sorted in increasing order, only the rightmost element is leader.
Input: arr = [30, 10, 10, 5]
Output: [30, 10, 10, 5]
Explanation: When an array is sorted in non-increasing order, all elements are leaders.
Constraints:
1 <= arr.size() <= 106
0 <= arr[i] <= 106



//optimal solution  
class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        int n=arr.size();
        vector<int> v;
        v.push_back(arr[n-1]);
        int prev=arr[n-1];
        for(int i=n-2; i>=0; i--){
            if(arr[i]>=prev){
                v.push_back(arr[i]);
                prev=arr[i];
            }
        }
        reverse(v.begin(),v.end());
        return v;
    }
};



//48. Rotate Image
Solved
Medium
Topics
Companies
Cisco
Facebook
Microsoft
Amazon
Apple
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
Example 2:


Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
 

Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 20
-1000 <= matrix[i][j] <= 1000


// optimal solution
class Solution {
public:
    void rotate(vector<vector<int>>& arr) {
        int n=arr.size();
        for(int i=0; i<n; i++){
            for(int j=i;j<n; j++){
                swap(arr[i][j],arr[j][i]);
            }
        }
        for(int i=0; i<n; i++){
            reverse(arr[i].begin(),arr[i].end());
        }
    }
};



//2149. Rearrange Array Elements by Sign
Solved
1236
Medium
Topics
Companies
Hint
Amazon
You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.

You should return the array of nums such that the the array follows the given conditions:

Every consecutive pair of integers have opposite signs.
For all integers with the same sign, the order in which they were present in nums is preserved.
The rearranged array begins with a positive integer.
Return the modified array after rearranging the elements to satisfy the aforementioned conditions.

 

Example 1:

Input: nums = [3,1,-2,-5,2,-4]
Output: [3,-2,1,-5,2,-4]
Explanation:
The positive integers in nums are [3,1,2]. The negative integers are [-2,-5,-4].
The only possible way to rearrange them such that they satisfy all conditions is [3,-2,1,-5,2,-4].
Other ways such as [1,-2,2,-5,3,-4], [3,1,2,-2,-5,-4], [-2,3,-5,1,-4,2] are incorrect because they do not satisfy one or more conditions.  
Example 2:

Input: nums = [-1,1]
Output: [1,-1]
Explanation:
1 is the only positive integer and -1 the only negative integer in nums.
So nums is rearranged to [1,-1].
 

Constraints:

2 <= nums.length <= 2 * 105
nums.length is even
1 <= |nums[i]| <= 105
nums consists of equal number of positive and negative integers.
 

It is not required to do the modifications in-place.



// brute force
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& arr) {
        int n=arr.size();
        vector<int> pos,neg;
        for(int i=0; i<n ;i++){
            if(arr[i]>0){
                pos.push_back(arr[i]);
            }
            else{
                neg.push_back(arr[i]);
            }
        }
        for(int i=0; i<n/2; i++){
            arr[i*2]=pos[i];
            arr[i*2+1]=neg[i];
        }
        return arr;
    }
};


// optimal solution
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& arr) {
        int n=arr.size();
        vector<int> v(n);
        int pos=0,neg=1;
        for(int i=0; i<n; i++){
            if(arr[i]<0){
                v[neg]=arr[i];neg+=2;
            }
            else{
                v[pos]=arr[i];pos+=2;
            }
        }
        return v;
    }
};



//31. Next Permutation
Solved
Medium
Topics
Companies
A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]
Example 2:

Input: nums = [3,2,1]
Output: [1,2,3]
Example 3:

Input: nums = [1,1,5]
Output: [1,5,1]
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 100

// brute force
//(1) genearate all permutations using recursion
//(2) sort all permutations
//(3) find the next permutation
// just tell the interviewer he don't ask you to code this because its code is time comsuming

// optimal solution
// using stl
class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        next_permutation(arr.begin(),arr.end());
    }
};


// optimal solution
class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int n=arr.size();
        int lind=n-1;
        for(int i=n-2; i>=0; i--){
            if(arr[i]<arr[lind]){
                for(int j=n-1; j>=0;j--){
                    if(arr[j]>arr[i]){
                        swap(arr[i],arr[j]);
                        break;
                    }
                }
                reverse(arr.begin()+i+1,arr.end());
                break;
            }
            else{
                lind=i;
            }
        }
        if(lind==0){
            reverse(arr.begin(),arr.end());
        }
    }
};




560. Subarray Sum Equals K
Solved
Medium
Topics
Companies
Hint
Facebook
Amazon
Google
Microsoft
Oracle
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
 

Constraints:

1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107


// brute force
class Solution {
public:
    int subarraySum(vector<int>& arr, int target) {
        int n=arr.size();
        int count=0;
        for(int i=0; i<n; i++){
            int sum=0;
            for(int j=i; j<n; j++){
                sum+=arr[j];
                if(sum==target) count++;
            }
        }
        return count;
    }
};



// optimal solution
class Solution {
public:
    int subarraySum(vector<int>& arr, int target) {
        int n=arr.size();
        unordered_map<int,int> m;
        m[0]++;
        int sum=0,count=0;
        for(int i=0; i<n; i++){
            sum+=arr[i];
            if(m.find(sum-target)!=m.end()){
                count+=m[sum-target];
            }
            m[sum]++;
        }
        return count;
    }
};




//128. Longest Consecutive Sequence
Solved
Medium
Topics
Companies
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109


// brute force O(nlogn)
class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        int n=arr.size();
        if(n<=1) return n;
        sort(arr.begin(),arr.end());
        int len=1,res=0;
        for(int i=1; i<n; i++){
            if(arr[i]==(arr[i-1]+1)){
                len++;
            }
            else if(arr[i]==arr[i-1]){
                continue;
            }
            else{
                res=max(res,len);
                len=1;
            }
        }
        res=max(res,len);
        return res;
    }
};


// optimal approach t:O(3n)  s:O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        int n=arr.size();
        unordered_set<int> s(arr.begin(),arr.end());
        int res=0;
        for(auto x: s){
            if(s.find(x-1)==s.end()){
                int len=1,ele=x+1;
                while(s.find(ele)!=s.end()){
                    len++;ele++;
                }
                res=max(res,len);
            }
        }
        return res;
    }
};