//Row with max 1s
Difficulty: MediumAccuracy: 33.09%Submissions: 337K+Points: 4
You are given a 2D binary array arr[][] consisting of only 1s and 0s. Each row of the array is sorted in non-decreasing order. Your task is to find and return the index of the first row that contains the maximum number of 1s. If no such row exists, return -1.

Note:

The array follows 0-based indexing.
The number of rows and columns in the array are denoted by n and m respectively.
Examples:

Input: arr[][] = [[0,1,1,1], [0,0,1,1], [1,1,1,1], [0,0,0,0]]
Output: 2
Explanation: Row 2 contains the most number of 1s (4 1s). Hence, the output is 2.
Input: arr[][] = [[0,0], [1,1]]
Output: 1
Explanation: Row 1 contains the most number of 1s (2 1s). Hence, the output is 1.
Input: arr[][] = [[0,0], [0,0]]
Output: -1
Explanation: No row contains any 1s, so the output is -1.
Constraints:
1 ≤ arr.size(), arr[i].size() ≤ 103
0 ≤ arr[i][j] ≤ 1 


// brute force O(m*n)
class Solution {
    public:
      int rowWithMax1s(vector<vector<int>> &arr) {
          // brute force
          int ind=-1,maxCount=0;
          int n=arr.size(),m=arr[0].size();
          for(int i=0;i<n; i++){
              int count=0;
              for(int j=0;j<m;j++){
                  if(arr[i][j]) count++;
              }
              if(count>maxCount){
                  maxCount=count;
                  ind=i;
              }
          }
          return ind;
      }
};


// optimal solution O(n*log(m))
class Solution {
    public:
      int rowWithMax1s(vector<vector<int>> &arr) {
          // better O(n*log(m))
          int ind=-1,maxCount=0;
          int n=arr.size(),m=arr[0].size();
          for(int i=0;i<n; i++){
              int low=0,high=m-1;
              while(low<=high){
                  int mid=(low+high)/2;
                  if(arr[i][mid]){
                      high=mid-1;
                  }
                  else{
                      low=mid+1;
                  }
              }
              if(m-low>maxCount){
                  maxCount=m-low;
                  ind=i;
              }
          }
          return ind;
      }
};



//74. Search a 2D Matrix
Solved
Medium
Topics
Companies
Facebook
Amazon
Microsoft
Bloomberg
Apple
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

 

Example 1:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
Example 2:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104


// brute force O(m*n)
class Solution {
    public:
      bool searchMatrix(vector<vector<int>> &matrix, int target) {
          // brute force
          int n=matrix.size(),m=matrix[0].size();
          for(int i=0;i<n; i++){
              for(int j=0;j<m;j++){
                  if(matrix[i][j]==target) return true;
              }
          }
          return false;
      }
};


// better solution t:o(n)+O(log(m))
class Solution {
    public:
      bool searchMatrix(vector<vector<int>> &matrix, int target) {
          // better O(n)+O(log(m))
          int n=matrix.size(),m=matrix[0].size();
          int row=-1;
          for(int i=0;i<n; i++){
              if(matrix[i][0]<=target && matrix[i][m-1]>=target){
                  row=i;
                  break;
              }
          }
          if(row==-1) return false;
          int low=0,high=m-1;
          while(low<=high){
              int mid=(low+high)/2;
              if(matrix[row][mid]==target) return true;
              else if(matrix[row][mid]<target) low=mid+1;
              else high=mid-1;
          }
          return false;
      }
};


// optimal solution O(log(m*n))
class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& arr, int target) {
            int n=arr.size(),m=arr[0].size();
            int low=0,high=n*m-1;
            while(low<=high){
                int mid=low+(high-low)/2;
                int div=mid/m,rem=mid%m;
                if(arr[div][rem]==target){
                    return true;
                }
                else if(arr[div][rem]<target){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
            return false;
        }
};




//240. Search a 2D Matrix II
Solved
Medium
Topics
Companies
Amazon
Microsoft
Bloomberg
Apple
Facebook
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
 

Example 1:


Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
Output: true
Example 2:


Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
Output: false
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= n, m <= 300
-109 <= matrix[i][j] <= 109
All the integers in each row are sorted in ascending order.
All the integers in each column are sorted in ascending order.
-109 <= target <= 109


// brute force t:O(m*n)
class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& arr, int target) {
            for(int i=0; i<arr.size(); i++){
                for(int j=0;j<arr[0].size();j++){
                    if(arr[i][j]==target) return true;
                }
            }
            return false;
        }
};


// better solution t:O(n*log(m))
class Solution {
    private:
        bool f(vector<int> &arr,int target){
            int n=arr.size();
            int low=0,high=n-1;
            while(low<=high){
                int mid=(low+high)>>1;
                if(arr[mid]==target) return true;
                else if(arr[mid]>target){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            return false;
        }
    public:
        bool searchMatrix(vector<vector<int>>& arr, int target) {
            int n=arr.size(),m=arr[0].size();
            for(int i=0; i<n; i++){
                if(f(arr[i],target)) return true;
            }
            return false;
        }
};



// optimal solution t:O(n+m)
class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& arr, int target) {
            int n=arr.size(),m=arr[0].size();
            int i=0,j=m-1;
            while(i<n && j>=0){
                if(arr[i][j]==target) return true;
                else if(arr[i][j]>target){
                    j--;
                }
                else{
                    i++;
                }
            }
            return false;
        }
};