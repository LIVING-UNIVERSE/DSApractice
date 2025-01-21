//Matrix Chain Multiplication
Difficulty: HardAccuracy: 49.64%Submissions: 135K+Points: 8
Given an array arr[] which represents dimensions of sequence of matrices where the ith matrix has the dimensions (arr[i-1] x arr[i]) for i>=1., find the most efficient way to multiply these matrices together. The efficient way is the one that involves the least number of multiplications.

Examples:

Input: arr[] = [2, 1, 3, 4]
Output: 20
Explanation: There are 3 matrices of dimensions 2 × 1, 1 × 3, and 3 × 4, Let the input 3 matrices be M1, M2, and M3. There are two ways to multiply: ((M1 x M2) x M3) and (M1 x (M2 x M3)), note that the result of (M1 x M2) is a 2 x 3 matrix and result of (M2 x M3) is a 1 x 4 matrix. 
((M1 x M2) x M3)  requires (2 x 1 x 3)  + (0) +  (2 x 3 x 4) = 30 
(M1 x (M2 x M3))  requires (0)  + (1 x 3 x 4) +  (2 x 1 x 4) = 20. 
The minimum of these two is 20.
Input: arr[] = [1, 2, 3, 4, 3]
Output: 30
Explanation: There are 4 matrices of dimensions 1 × 2, 2 × 3, 3 × 4, 4 × 3. Let the input 4 matrices be M1, M2, M3 and M4. The minimum number of multiplications are obtained by ((M1 x M2) x M3) x M4). The minimum number is (1 x 2 x 3) + (1 x 3 x 4) + (1 x 4 x 3) = 30.
Input: arr[] = [3, 4]
Output: 0
Explanation: As there is only one matrix so, there is no cost of multiplication.
Constraints: 
2 ≤ arr.size() ≤ 100
1 ≤ arr[i] ≤ 500



// top down approach
class Solution {
  private:
    int f(int ind1,int ind2,vector<int> &arr,vector<vector<int>> &dp){
        if(ind1==ind2) return 0;
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        int res=1e8;
        for(int k=ind1; k<ind2;k++){
            int count= arr[ind1-1]*arr[k]*arr[ind2] + f(ind1,k,arr,dp)+f(k+1,ind2,arr,dp);
            res=min(res,count);
        }
        return dp[ind1][ind2]= res;
    }
  public:
    int matrixMultiplication(vector<int> &arr) {
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return f(1,n-1,arr,dp);
    }
};


// bottoms up approach
class Solution {
  public:
    int matrixMultiplication(vector<int> &arr) {
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=n-1; i>=1; i--){
            for(int j=i+1; j<n; j++){
                dp[i][j]=1e8;
                for(int k=i; k<j; k++){
                    int count= arr[i-1]*arr[k]*arr[j] + dp[i][k]+dp[k+1][j];
                    dp[i][j]=min(dp[i][j],count);
                }
            }
        }
        return dp[1][n-1];
    }
};
