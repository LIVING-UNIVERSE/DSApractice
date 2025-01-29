//1752. Check if Array Is Sorted and Rotated
Attempted
Easy
Topics
Companies
Hint
Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

There may be duplicates in the original array.

Note: An array A rotated by x positions results in an array B of the same length such that A[i] == B[(i+x) % A.length], where % is the modulo operation.

 

Example 1:

Input: nums = [3,4,5,1,2]
Output: true
Explanation: [1,2,3,4,5] is the original sorted array.
You can rotate the array by x = 3 positions to begin on the the element of value 3: [3,4,5,1,2].
Example 2:

Input: nums = [2,1,3,4]
Output: false
Explanation: There is no sorted array once rotated that can make nums.
Example 3:

Input: nums = [1,2,3]
Output: true
Explanation: [1,2,3] is the original sorted array.
You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.
 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100


// optimize solution
class Solution {
public:
    bool check(vector<int>& arr) {
       int n=arr.size();
       int count=0;
       for(int i=1; i<=n; i++){
            if(arr[(i-1)%n]>arr[i%n]) count++;
       }
       return (count<=1);
    }
};




//26. Remove Duplicates from Sorted Array
Solved
Easy
Topics
Companies
Hint
Facebook
Amazon
Adobe
Microsoft
LinkedIn
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
Return k.
Custom Judge:

The judge will test your solution with the following code:

int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
If all assertions pass, then your solution will be accepted.

 

Example 1:

Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
Example 2:

Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
 

Constraints:

1 <= nums.length <= 3 * 104
-100 <= nums[i] <= 100
nums is sorted in non-decreasing order.


// better solution
class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int n=arr.size();
        int lu=0,count=1;
        for(int i=1; i<n; i++){
            if(arr[i]!=arr[lu]){
                swap(arr[lu+1],arr[i]);
                lu++;
                count++;
            }
        }
        return count;
    }
};



//189. Rotate Array
Solved
Medium
Topics
Companies
Hint
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

 

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
 

Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
0 <= k <= 105
 

Follow up:

Try to come up with as many solutions as you can. There are at least three different ways to solve this problem.
Could you do it in-place with O(1) extra space?


//optimal solution
class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        int n=arr.size();
        k=k%n;
        reverse(arr.begin(),arr.begin()+n-k);
        reverse(arr.begin()+n-k,arr.end());
        reverse(arr.begin(),arr.end());
    }
};




//283. Move Zeroes
Solved
Easy
Topics
Companies
Hint
Facebook
Microsoft
Apple
Amazon
Yandex
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
 

Constraints:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
 

Follow up: Could you minimize the total number of operations done?


// brute force
class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        // brute force solution
        int n=arr.size();
        vector<int> temp;
        for(int i=0; i<n; i++){
            if(arr[i]!=0) temp.push_back(arr[i]);
        }
        for(int i=0; i<n; i++){
            if(i<temp.size()) arr[i]=temp[i];
            else{
                arr[i]=0;
            }
        }
    }
};


// optimal solution
class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int n=arr.size();
        int ind=0;
        for(int i=0; i<n; i++){
            if(arr[i]!=0){
                swap(arr[i],arr[ind]);
                ind++;
            }
        }
    }
};