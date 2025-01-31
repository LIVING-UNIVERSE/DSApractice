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