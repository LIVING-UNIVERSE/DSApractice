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




//1547. Minimum Cost to Cut a Stick
Solved
Hard
Topics
Companies
Hint
Given a wooden stick of length n units. The stick is labelled from 0 to n. For example, a stick of length 6 is labelled as follows:


Given an integer array cuts where cuts[i] denotes a position you should perform a cut at.

You should perform the cuts in order, you can change the order of the cuts as you wish.

The cost of one cut is the length of the stick to be cut, the total cost is the sum of costs of all cuts. When you cut a stick, it will be split into two smaller sticks (i.e. the sum of their lengths is the length of the stick before the cut). Please refer to the first example for a better explanation.

Return the minimum total cost of the cuts.

 

Example 1:


Input: n = 7, cuts = [1,3,4,5]
Output: 16
Explanation: Using cuts order = [1, 3, 4, 5] as in the input leads to the following scenario:

The first cut is done to a rod of length 7 so the cost is 7. The second cut is done to a rod of length 6 (i.e. the second part of the first cut), the third is done to a rod of length 4 and the last cut is to a rod of length 3. The total cost is 7 + 6 + 4 + 3 = 20.
Rearranging the cuts to be [3, 5, 1, 4] for example will lead to a scenario with total cost = 16 (as shown in the example photo 7 + 4 + 3 + 2 = 16).
Example 2:

Input: n = 9, cuts = [5,6,1,4,2]
Output: 22
Explanation: If you try the given cuts ordering the cost will be 25.
There are much ordering with total cost <= 25, for example, the order [4, 6, 5, 2, 1] has total cost = 22 which is the minimum possible.
 

Constraints:

2 <= n <= 106
1 <= cuts.length <= min(n - 1, 100)
1 <= cuts[i] <= n - 1
All the integers in cuts array are distinct.


// top down approach
class Solution {
private:
     int f(int i,int j,vector<int> &arr,vector<vector<int>>& dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int res=1e8;
        for(int k=i; k<=j;k++){
            int count= arr[j+1]-arr[i-1] + f(i,k-1,arr,dp)+f(k+1,j,arr,dp);
            res=min(res,count);
        }
        return dp[i][j]= res;
     }
public:
    int minCost(int n, vector<int>& arr) {
        sort(arr.begin(),arr.end());
        arr.push_back(n);
        arr.insert(arr.begin(),0);
        vector<vector<int>> dp(arr.size()+1,vector<int>(arr.size()+1,0));
        for(int i=arr.size()-2; i>=1; i--){
            for(int j=i;j<=arr.size()-2; j++){
                int res=1e8;
                for(int k=i; k<=j;k++){
                    int count= arr[j+1]-arr[i-1] +dp[i][k-1]+dp[k+1][j];
                    res=min(res,count);
                }
                dp[i][j]=res;
            }
        }
        return dp[1][arr.size()-2];
    }
};

// bottoms up approach
class Solution {
public:
    int minCost(int n, vector<int>& arr) {
        arr.push_back(n);
        arr.push_back(0);
        sort(arr.begin(),arr.end());
        vector<vector<int>> dp(arr.size()+1,vector<int>(arr.size()+1,0));
        for(int i=arr.size()-2; i>=1; i--){
            for(int j=i;j<=arr.size()-2; j++){
                int res=1e8;
                for(int k=i; k<=j;k++){
                    int count= arr[j+1]-arr[i-1] +dp[i][k-1]+dp[k+1][j];
                    res=min(res,count);
                }
                dp[i][j]=res;
            }
        }
        return dp[1][arr.size()-2];
    }
};
