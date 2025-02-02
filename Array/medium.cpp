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