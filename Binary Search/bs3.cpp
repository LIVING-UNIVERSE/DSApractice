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
