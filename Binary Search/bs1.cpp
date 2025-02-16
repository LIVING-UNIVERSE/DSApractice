//704. Binary Search
Solved
1695
Easy
Topics
Companies
Amazon
Apple
Google
Microsoft
Bloomberg
Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
Example 2:

Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
 

Constraints:

1 <= nums.length <= 104
-104 < nums[i], target < 104
All the integers in nums are unique.
nums is sorted in ascending order.


// iterative solution
class Solution {
    public:
        // iterative approach
        int search(vector<int>& arr, int target) {
            int low=0,high=arr.size()-1;
            while(low<=high){
                int mid=(low+high)/2;
                if(arr[mid]==target) return mid;
                else if(arr[mid]>target){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            return -1;
        }
    };


// recursive solution
class Solution {
    private:
        int f(int h,int l,int x,vector<int> &arr){
            if(l>h) return -1;
            int mid=(l+h)/2;
            if(arr[mid]==x) return mid;
            if(arr[mid]>x) return f(mid-1,l,x,arr);
            return f(h,mid+1,x,arr);
        }
    public:
        //recursive approach
        int search(vector<int>& arr, int target) {
            return f(arr.size()-1,0,target,arr);
        }
    };