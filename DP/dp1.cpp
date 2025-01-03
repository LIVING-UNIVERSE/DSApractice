fibonacci with recursion

// #include<bits/stdc++.h>
#include<iostream>
#include<unordered_set>
#include<unordered_map>
using namespace std; 

int f(int n ){
    if(n<=1) return n;
    return f(n-1)+f(n-2);
}

int main(){
    int n=5;
    cout<<f(n);
    return 0;
}

// with memoization
#include<bits/stdc++.h>
// #include<iostream>
// #include<unordered_set>
// #include<unordered_map>
using namespace std; 

int f(int n, vector<int> &dp ){
    if(n<=1) return n;
    if(dp[n]!=-1) return dp[n];
    return dp[n]=f(n-1,dp)+f(n-2,dp);
}

int main(){
    int n=5;
    vector<int> dp(n+1,-1);
    cout<<f(n,dp);
    return 0;
}


// tabular form
#include<bits/stdc++.h>
// #include<iostream>
// #include<unordered_set>
// #include<unordered_map>
using namespace std; 

int f(int n, vector<int> &dp ){
    dp[0]=0; dp[1]=1;
    for(int i=2; i<=n; i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int main(){
    int n=5;
    vector<int> dp(n+1,-1);
    cout<<f(n,dp);
    return 0;
}


// tabular form with space optimization
#include<bits/stdc++.h>
// #include<iostream>
// #include<unordered_set>
// #include<unordered_map>
using namespace std; 

int f(int n ){
    int prev=1,prev2=0;
    // dp[0]=0; dp[1]=1;
    for(int i=2; i<=n; i++){
        // dp[i]=dp[i-1]+dp[i-2];
        int curri = prev +prev2;
        prev2 = prev;
        prev=curri;
    }
    return prev;
}

int main(){
    int n=5;
    // vector<int> dp(n+1,-1);
    cout<<f(n);
    return 0;
}





// // Geek Jump
// Difficulty: EasyAccuracy: 49.55%Submissions: 100K+Points: 2
//  Geek wants to climb from the 0th stair to the (n-1)th stair. At a time the Geek can climb either one or two steps. A height[N] array is also given. Whenever the geek jumps from stair i to stair j, the energy consumed in the jump is abs(height[i]- height[j]), where abs() means the absolute difference. return the minimum energy that can be used by the Geek to jump from stair 0 to stair N-1.

// Example:

 

// Input: n = 4, height = {10 20 30 10}
// Output: 20
// Explanation:
// Geek jump from 1st to 2nd stair(|20-10| = 10 energy lost). Then a jump from the 2nd to the last stair(|10-20| = 10 energy lost). So, total energy lost is 20 which is the minimum.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function MinimumEnergy() which takes the array height, and integer n, and returns the minimum energy that is lost.

// Expected Time Complexity: O(n)
// Expected Space Complexity: O(n)

// Constraint:
// 1<=n<=100000
// 1<=height[i]<=1000


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
    int helper(vector<int> &H,vector<int> &dp,int n){
        if(n==0) return 0;
        if(n==1) return abs(H[1]-H[0]);
        if(dp[n]!=-1) return dp[n];
        int l= helper(H,dp,n-1) + abs(H[n]-H[n-1]);
        int r= helper(H,dp,n-2) + abs(H[n]-H[n-2]);
        return dp[n]=min(l,r); 
    }
  public:
    int minimumEnergy(vector<int>& height, int n) {
        // top dowm (memoization)
        // vector<int> dp(n,-1);
        // return helper(height,dp,n-1);
        
        // vector<int> dp(n,-1);
        // dp[0]=0;
        // dp[1]=abs(height[1]-height[0]);
        // for(int i=2; i<n; i++){
        //     int l= dp[i-1]+abs(height[i]-height[i-1]);
        //     int r= dp[i-2]+abs(height[i]-height[i-2]);
        //     dp[i]=min(l,r);
        // }
        // return dp[n-1];

        int prev2=0;
        int prev=abs(height[1]-height[0]);
        for(int i=2; i<n; i++){
            int l= prev+abs(height[i]-height[i-1]);
            int r= prev2+abs(height[i]-height[i-2]);
            prev2=prev;
            prev=min(l,r);
        }
        return prev;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends





Minimal Cost
Difficulty: MediumAccuracy: 51.08%Submissions: 85K+Points: 4
There is an array arr of heights of stone and Geek is standing at the first stone and can jump to one of the following: Stone i+1, i+2, ... i+k stone, where k is the maximum number of steps that can be jumped and cost will be |hi-hj| is incurred, where j is the stone to land on. Find the minimum possible total cost incurred before the Geek reaches the last stone.

Example:

Input: k = 3, arr[]= [10, 30, 40, 50, 20]
Output: 30
Explanation: Geek will follow the path 1->2->5, the total cost would be | 10-30| + |30-20| = 30, which is minimum
Input: k = 1, arr[]= [10, 20, 10]
Output: 20
Explanation: Geek will follow the path 1->2->3, the total cost would be |10 - 20| + |20 - 10| = 20.
Expected Time Complexity: O(n*k)
Expected Auxilary Space: O(n)

Constraint:
1<= arr.size() <=104
1 <= k <= 100
1 <= arr[i] <= 104



// top down 
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
    int helper(vector<int> &arr,vector<int> &dp, int k, int n){
        if(n==0) return 0;
        if(dp[n]!=-1) return dp[n];
        int res=INT_MAX;
        for(int i=1; i<=k ;i++){
            if(n-i>=0){
                int cash= helper(arr,dp,k,n-i) + abs(arr[n]-arr[n-i]);
                res=min(res,cash);
            }
        }
        return dp[n]=res;
    }
  public:
    int minimizeCost(int k, vector<int>& arr) {
        int n=arr.size();
        vector<int> dp(n,-1);
        return helper(arr,dp,k,n-1);
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends


// bottoms up appraoch
 public:
    int minimizeCost(int k, vector<int>& arr) {
        int n=arr.size();
        vector<int> dp(n,-1);
        // return helper(arr,dp,k,n-1);
        // bottoms up appraoch
        dp[0]=0;
        for(int i=1;i<n; i++){
            int res=INT_MAX;
            for(int j=1; j<=k ;j++){
                if(i-j>=0){
                    int cash= dp[i-j]+abs(arr[i]-arr[i-j]);
                    res=min(res,cash);
                }
            }
            dp[i]=res;
        }
        return dp[n-1];
    }

space optimization
public:
    int minimizeCost(int k, vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(k, INT_MAX); // Use a k-size array
        dp[0] = 0; // Base case: cost to reach the first stone is 0

        for (int i = 1; i < n; i++) {
            int curr = INT_MAX;

            for (int j = 1; j <= k; j++) {
                if (i - j >= 0) {
                    curr = min(curr, dp[(i - j) % k] + abs(arr[i] - arr[i - j]));
                }
            }

            dp[i % k] = curr; // Update the sliding window
        }

        return dp[(n - 1) % k]; // The result is in the index corresponding to the last stone
    }
};
      



198. House Robber
Solved
Medium
Topics
Companies
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 400



top down
class Solution {
private:
// topDown approach
    int f(vector<int> &arr,vector<int> &dp,int ind){
        if(ind==0) return arr[ind];
        if(ind ==1) return max(arr[1],arr[0]);
        if(dp[ind]!=-1) return dp[ind];
        int pick= arr[ind]+ f(arr,dp,ind-2);
        int dpick = f(arr,dp,ind-1);
        return dp[ind]=max(pick,dpick);
    }
public:
    int rob(vector<int>& arr) {
        int n=arr.size();
        vector<int> dp(n,-1);
        return f(arr,dp,n-1);
    }
};


// 2nd top down approach
int f(vector<int> &arr,vector<int> &dp,int ind){
    if(ind==0) return arr[0];
    if(ind<0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int pick= f(arr,dp,ind-2) +arr[ind];
    int dpick= f(arr,dp,ind-1);
    return dp[ind]= max(pick,dpick);
}



bottom up
public:
    int rob(vector<int>& arr) {
        int n=arr.size();
        int prev2= 0;
        
        int prev= arr[0];
        for(int i=1; i<n; i++){
            int take = arr[i];
            if(i>1){
                take+=prev2;
            }
            int dtake = 0+prev;
            int res=max(take,dtake);
            prev2=prev;
            prev=res;
        }
        return prev;
    }






//Geek's Training
Difficulty: MediumAccuracy: 49.98%Submissions: 91K+Points: 4
Geek is going for a training program. He can perform any of these activities: Running, Fighting, and Learning Practice. Each activity has some point on each day. As Geek wants to improve all his skills, he can't do the same activity on two consecutive days. Help Geek to maximize his merit points as you are given a 2D array of points arr, corresponding to each day and activity.

Example:
Input: n = 3 and arr[]= [[1,2,5],[3,1,1],[3,3,3]]
Output:11
Explanation: Geek will learn a new move and earn 5 point then on second day he will do running and earn 3 point and on third day he will do fighting and earn 3 points so, maximum point is 11.
Constraint:
1 <=  arr.size <= 105
1 <=  arr[i][j] <= 100



// top down appraoch
int f(int day,int act,vector<vector<int>> &arr,vector<vector<int>> &dp){
        if(day==0){
            int res=0;
            for(int i=0; i<3; i++){
                if(i!=act){
                    res=max(res,arr[day][i]);
                    
                }
            }
            
            return dp[day][act]=res;
        }
        if(dp[day][act]!=-1) return dp[day][act];
        int res=0;
        for(int i=0; i<3; i++){
            if(i!=act){
                int cash= f(day-1,i,arr,dp)+arr[day][i];
                res=max(res,cash);
            }
        }
        return dp[day][act]= res;
    }
  public:
    int maximumPoints(vector<vector<int>>& arr, int n) {
        vector<vector<int>> dp(n+1,vector<int>(4,-1));
        return f(n-1,3,arr,dp);
    }



bottoms up
public:
    int maximumPoints(vector<vector<int>>& arr, int n) {
        // bottom's up approach
        vector<vector<int>> dp(n,vector<int>(4,-1));
        dp[0][0]= max(arr[0][1],arr[0][2]);
        dp[0][1]= max(arr[0][0],arr[0][2]);
        dp[0][2]= max(arr[0][1],arr[0][0]);
        dp[0][3]= max(arr[0][1],max(arr[0][0],arr[0][2]));
        
        for(int i=1; i<n; i++){
            for(int j=0; j<4; j++){
                int res=0;
                for(int k=0; k<3; k++){
                    if(k!=j){
                        int cash= dp[i-1][k] +arr[i][k];
                        res=max(res,cash);
                    }
                }
                dp[i][j]= res;
            }
        }
        return dp[n-1][3];
     }


// bottoms up(space optimization)
 public:
    int maximumPoints(vector<vector<int>>& arr, int n) {
        // bottom's up approach
        // vector<vector<int>> dp(n,vector<int>(4,-1));
        vector<int> dp(4,-1);
        dp[0]= max(arr[0][1],arr[0][2]);
        dp[1]= max(arr[0][0],arr[0][2]);
        dp[2]= max(arr[0][1],arr[0][0]);
        dp[3]= max(arr[0][1],max(arr[0][0],arr[0][2]));
        
        for(int i=1; i<n; i++){
            vector<int> temp(4,-1);
            for(int j=0; j<4; j++){
                int res=0;
                for(int k=0; k<3; k++){
                    if(k!=j){
                        int cash= dp[k] +arr[i][k];
                        res=max(res,cash);
                    }
                }
                temp[j]= res;
            }
            dp=temp;
            
        }
        return dp[3];
     }




//62. Unique Paths
Solved
Medium
Topics
Companies
Google
Facebook
Microsoft
Amazon
Apple
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.

 

Example 1:


Input: m = 3, n = 7
Output: 28
Example 2:

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
 

Constraints:

1 <= m, n <= 100



// top down approach
class Solution {
private:
    int f(int x, int y, vector<vector<int>> &dp){
        if(x==0 || y==0) return 1;
        if(dp[x][y]!=-1) return dp[x][y];
        int up=0,left=0;
        left= f(x-1,y,dp);
        up=f(x,y-1,dp);
        return dp[x][y]=left+up;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return f(m-1,n-1,dp);
    }
};



// bottoms up approach
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i=0; i<n; i++){
            dp[0][i]=1;
        }
        for(int i=1; i<m; i++){
            dp[i][0]=1;
        }
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};



// bottoms up (space optimization)
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n,1);
        for(int i=1; i<m; i++){
            vector<int> temp(n,1);
            for(int j=1; j<n; j++){
                temp[j]=temp[j-1]+dp[j];
            }
            dp=temp;
        }
        return dp[n-1];
    }
};








//63. Unique Paths II
Solved
Medium
Topics
Companies
Hint
Cruise Automation
Facebook
Amazon
Qualtrics
Google
You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 109.

 

Example 1:


Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
Example 2:


Input: obstacleGrid = [[0,1],[0,0]]
Output: 1
 

Constraints:

m == obstacleGrid.length
n == obstacleGrid[i].length
1 <= m, n <= 100
obstacleGrid[i][j] is 0 or 1.


// tup down approach
class Solution {
private:
    int f(int row, int col, vector<vector<int>>& dp,
          vector<vector<int>>& grid) {
        if (grid[row][col] == 1) return 0;
        if (row == 0 && col == 0) return 1;
        if (dp[row][col]!=-1) return dp[row][col];
        int left = 0, up = 0;
        if (col - 1 >= 0 ) {
            left = f(row, col - 1, dp, grid);
        }
        if (row - 1 >= 0 ) {
            up = f(row - 1, col, dp, grid);
        }
        return dp[row][col]=left + up;
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        if (grid[m - 1][n - 1] == 1 || grid[0][0] == 1) {
            return 0;
        }
        return f(m - 1, n - 1, dp, grid);
    }
};


// bottoms up approach
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if(grid[row][col]==1) dp[row][col]=0;
                else if(row==0 && col==0) dp[row][col]=1;
                else{
                    int left=0,up=0;
                    if(row>0) up=dp[row-1][col];
                    if(col>0) left=dp[row][col-1];
                    dp[row][col]= up+left;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};



// bottoms up (space optimization)
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> prev(n,0);
        for (int row = 0; row < m; row++) {
            vector<int> curr(n,0);
            for (int col = 0; col < n; col++) {
                if(grid[row][col]==1) curr[col]=0;
                else if(row==0 && col==0) curr[0]=1;
                else{
                    int left=0,up=0;
                    if(row>0) up=prev[col];
                    if(col>0) left=curr[col-1];
                    curr[col]= up+left;
                }
            }
            prev=curr;
        }
        return prev[n-1];
    }



////64. Minimum Path Sum
Solved
Medium
Topics
Companies
Amazon
Microsoft
Google
Goldman Sachs
Oracle
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

 

Example 1:


Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 200





// top down approach
class Solution {
private:
    int f(int row, int col,vector<vector<int>>& dp,vector<vector<int>>& grid){
        if(row==0 && col==0) return grid[0][0];
        if(dp[row][col]!=-1) return dp[row][col];
        int up=1e8,left=1e8;
        if(row>0) up=f(row-1,col,dp,grid)+grid[row][col];
        if(col>0) left=f(row,col-1,dp,grid)+grid[row][col];
        return dp[row][col]=min(up,left);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return f(m-1,n-1,dp,grid);
    }
};


// bottoms up approach
class Solution {

public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int row=0; row<m;row++){
            for(int col=0; col<n; col++){
                if(row==0 && col==0) {dp[row][col]=grid[row][col];}
                else{
                    int left=1e8,up=1e8;
                    if(row>0) {up=dp[row-1][col]+grid[row][col];}
                    if(col>0) {left = dp[row][col-1] +grid[row][col];}
                    dp[row][col]=min(up,left);
                }
            }
        }
        return dp[m-1][n-1];
    }
};




// bottoms up space optimized
class Solution {

public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        // vector<vector<int>> dp(m,vector<int>(n,-1));
        vector<int> prev(n,1e8);
        for(int row=0; row<m;row++){
            vector<int> curr(n,0);
            for(int col=0; col<n; col++){
                if(row==0 && col==0) {curr[0]=grid[row][col];}
                else{
                    int left=1e8,up=1e8;
                    if(row>0) {up=prev[col]+grid[row][col];}
                    if(col>0) {left =curr[col-1] +grid[row][col];}
                    curr[col]=min(up,left);
                }
            }
            prev=curr;
        }
        return prev[n-1];
    }
};