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




// Implement Lower Bound
Easy
40/40
Average time to solve is 20m
Contributed by
347 upvotes
Problem statement
You are given an array 'arr' sorted in non-decreasing order and a number 'x'. You must return the index of the lower bound of 'x'.



Note:
1. For a sorted array 'arr', 'lower_bound' of a number 'x' is defined as the smallest index 'idx' such that the value 'arr[idx]' is not less than 'x'.If all numbers are smaller than 'x', then 'n' should be the 'lower_bound' of 'x', where 'n' is the size of array.

2. Try to do this in O(log(n)).


Example:
Input: ‘arr’ = [1, 2, 2, 3] and 'x' = 0

Output: 0

Explanation: Index '0' is the smallest index such that 'arr[0]' is not less than 'x'.


Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= ‘n’ <= 10^5
0 <= ‘arr[i]’ <= 10^5
1 <= ‘x’ <= 10^5
Sample Input 1:
6
1 2 2 3 3 5
0


Sample Output 1:
0


Explanation Of Sample Input 1 :
Index '0' is the smallest index such that 'arr[0]' is not less than 'x'.


Sample Input 2:
6
1 2 2 3 3 5
2


Sample Output 2:
1


Sample Input 3:
6
1 2 2 3 3 5
7


Sample Output 3:
6



// solution
int lowerBound(vector<int> arr, int n, int x) {
	int low=0,high=n-1;
	while(low<=high){
		int mid=(low+high)/2;
		if(arr[mid]>=x){
			high=mid-1;
		}
		else{
			low=mid+1;
		}
	}
	return low;
}





//Implement Upper Bound
Difficulty: EasyAccuracy: 58.45%Submissions: 2K+Points: 2
Given a sorted array arr[] and a number target, the task is to find the upper bound of the target in this given array.

The upper bound of a number is defined as the smallest index in the sorted array where the element is greater than the given number.

Note: If all the elements in the given array are smaller than or equal to the target, the upper bound will be the length of the array.

Examples :

Input:  arr[] = [2, 3, 7, 10, 11, 11, 25], target = 9
Output: 3
Explanation: 3 is the smallest index in arr[], at which element (arr[3] = 10) is larger than 9.
Input: arr[] = [2, 3, 7, 10, 11, 11, 25], target = 11
Output: 6
Explanation: 6 is the smallest index in arr[], at which element (arr[6] = 25) is larger than 11.
Input: arr[] = [2, 3, 7, 10, 11, 11, 25], target = 100
Output: 7
Explanation: As no element in arr[] is greater than 100, return the length of array.
Constraints:
1 ≤ arr.size() ≤ 106
1 ≤ arr[i] ≤ 106
1 ≤ target ≤ 106



// solution
class Solution {
    public:
      int upperBound(vector<int>& arr, int target) {
          int n=arr.size();
          int low=0,high=n-1;
          while(low<=high){
              int mid=(low+high)/2;
              if(arr[mid]>target){
                  high=mid-1;
              }
              else{
                  low=mid+1;
              }
          }
          return low;
      }
  };