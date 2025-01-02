// fibonacci with recursion

// // #include<bits/stdc++.h>
// #include<iostream>
// #include<unordered_set>
// #include<unordered_map>
// using namespace std; 

// int f(int n ){
//     if(n<=1) return n;
//     return f(n-1)+f(n-2);
// }

// int main(){
//     int n=5;
//     cout<<f(n);
//     return 0;
// }

// // with memoization
// #include<bits/stdc++.h>
// // #include<iostream>
// // #include<unordered_set>
// // #include<unordered_map>
// using namespace std; 

// int f(int n, vector<int> &dp ){
//     if(n<=1) return n;
//     if(dp[n]!=-1) return dp[n];
//     return dp[n]=f(n-1,dp)+f(n-2,dp);
// }

// int main(){
//     int n=5;
//     vector<int> dp(n+1,-1);
//     cout<<f(n,dp);
//     return 0;
// }


// // tabular form
// #include<bits/stdc++.h>
// // #include<iostream>
// // #include<unordered_set>
// // #include<unordered_map>
// using namespace std; 

// int f(int n, vector<int> &dp ){
//     dp[0]=0; dp[1]=1;
//     for(int i=2; i<=n; i++){
//         dp[i]=dp[i-1]+dp[i-2];
//     }
//     return dp[n];
// }

// int main(){
//     int n=5;
//     vector<int> dp(n+1,-1);
//     cout<<f(n,dp);
//     return 0;
// }


// // tabular form with space optimization
// #include<bits/stdc++.h>
// // #include<iostream>
// // #include<unordered_set>
// // #include<unordered_map>
// using namespace std; 

// int f(int n ){
//     int prev=1,prev2=0;
//     // dp[0]=0; dp[1]=1;
//     for(int i=2; i<=n; i++){
//         // dp[i]=dp[i-1]+dp[i-2];
//         int curri = prev +prev2;
//         prev2 = prev;
//         prev=curri;
//     }
//     return prev;
// }

// int main(){
//     int n=5;
//     // vector<int> dp(n+1,-1);
//     cout<<f(n);
//     return 0;
// }





// // // Geek Jump
// // Difficulty: EasyAccuracy: 49.55%Submissions: 100K+Points: 2
// //  Geek wants to climb from the 0th stair to the (n-1)th stair. At a time the Geek can climb either one or two steps. A height[N] array is also given. Whenever the geek jumps from stair i to stair j, the energy consumed in the jump is abs(height[i]- height[j]), where abs() means the absolute difference. return the minimum energy that can be used by the Geek to jump from stair 0 to stair N-1.

// // Example:

 

// // Input: n = 4, height = {10 20 30 10}
// // Output: 20
// // Explanation:
// // Geek jump from 1st to 2nd stair(|20-10| = 10 energy lost). Then a jump from the 2nd to the last stair(|10-20| = 10 energy lost). So, total energy lost is 20 which is the minimum.
// // Your Task:
// // You don't need to read input or print anything. Your task is to complete the function MinimumEnergy() which takes the array height, and integer n, and returns the minimum energy that is lost.

// // Expected Time Complexity: O(n)
// // Expected Space Complexity: O(n)

// // Constraint:
// // 1<=n<=100000
// // 1<=height[i]<=1000


// //{ Driver Code Starts
// #include <bits/stdc++.h>
// using namespace std;


// // } Driver Code Ends
// class Solution {
//   private:
//     int helper(vector<int> &H,vector<int> &dp,int n){
//         if(n==0) return 0;
//         if(n==1) return abs(H[1]-H[0]);
//         if(dp[n]!=-1) return dp[n];
//         int l= helper(H,dp,n-1) + abs(H[n]-H[n-1]);
//         int r= helper(H,dp,n-2) + abs(H[n]-H[n-2]);
//         return dp[n]=min(l,r); 
//     }
//   public:
//     int minimumEnergy(vector<int>& height, int n) {
//         // top dowm (memoization)
//         // vector<int> dp(n,-1);
//         // return helper(height,dp,n-1);
        
//         // vector<int> dp(n,-1);
//         // dp[0]=0;
//         // dp[1]=abs(height[1]-height[0]);
//         // for(int i=2; i<n; i++){
//         //     int l= dp[i-1]+abs(height[i]-height[i-1]);
//         //     int r= dp[i-2]+abs(height[i]-height[i-2]);
//         //     dp[i]=min(l,r);
//         // }
//         // return dp[n-1];

//         int prev2=0;
//         int prev=abs(height[1]-height[0]);
//         for(int i=2; i<n; i++){
//             int l= prev+abs(height[i]-height[i-1]);
//             int r= prev2+abs(height[i]-height[i-2]);
//             prev2=prev;
//             prev=min(l,r);
//         }
//         return prev;
//     }
// };

// //{ Driver Code Starts.

// int main() {
//     int t;
//     cin >> t;
//     while (t--) {
//         int N;
//         cin >> N;
//         vector<int> arr(N);
//         for (int i = 0; i < N; i++) {
//             cin >> arr[i];
//         }
//         Solution obj;
//         cout << obj.minimumEnergy(arr, N) << "\n";
    
// cout << "~" << "\n";
// }
//     return 0;
// }
// // } Driver Code Ends





// Minimal Cost
// Difficulty: MediumAccuracy: 51.08%Submissions: 85K+Points: 4
// There is an array arr of heights of stone and Geek is standing at the first stone and can jump to one of the following: Stone i+1, i+2, ... i+k stone, where k is the maximum number of steps that can be jumped and cost will be |hi-hj| is incurred, where j is the stone to land on. Find the minimum possible total cost incurred before the Geek reaches the last stone.

// Example:

// Input: k = 3, arr[]= [10, 30, 40, 50, 20]
// Output: 30
// Explanation: Geek will follow the path 1->2->5, the total cost would be | 10-30| + |30-20| = 30, which is minimum
// Input: k = 1, arr[]= [10, 20, 10]
// Output: 20
// Explanation: Geek will follow the path 1->2->3, the total cost would be |10 - 20| + |20 - 10| = 20.
// Expected Time Complexity: O(n*k)
// Expected Auxilary Space: O(n)

// Constraint:
// 1<= arr.size() <=104
// 1 <= k <= 100
// 1 <= arr[i] <= 104



// // top down 
// //{ Driver Code Starts
// #include <bits/stdc++.h>
// using namespace std;


// // } Driver Code Ends
// class Solution {
//   private:
//     int helper(vector<int> &arr,vector<int> &dp, int k, int n){
//         if(n==0) return 0;
//         if(dp[n]!=-1) return dp[n];
//         int res=INT_MAX;
//         for(int i=1; i<=k ;i++){
//             if(n-i>=0){
//                 int cash= helper(arr,dp,k,n-i) + abs(arr[n]-arr[n-i]);
//                 res=min(res,cash);
//             }
//         }
//         return dp[n]=res;
//     }
//   public:
//     int minimizeCost(int k, vector<int>& arr) {
//         int n=arr.size();
//         vector<int> dp(n,-1);
//         return helper(arr,dp,k,n-1);
//     }
// };

// //{ Driver Code Starts.

// int main() {
//     string ts;
//     getline(cin, ts);
//     int t = stoi(ts);
//     while (t--) {
//         string ks;
//         getline(cin, ks);
//         int k = stoi(ks);
//         vector<int> arr;
//         string input;
//         getline(cin, input);
//         stringstream ss(input);
//         int number;
//         while (ss >> number) {
//             arr.push_back(number);
//         }
//         Solution obj;
//         int res = obj.minimizeCost(k, arr);
//         cout << res << endl;
//         cout << "~" << endl;
//         // string tl;
//         // getline(cin, tl);
//     }
//     return 0;
// }

// // } Driver Code Ends


// // bottoms up appraoch
//  public:
//     int minimizeCost(int k, vector<int>& arr) {
//         int n=arr.size();
//         vector<int> dp(n,-1);
//         // return helper(arr,dp,k,n-1);
//         // bottoms up appraoch
//         dp[0]=0;
//         for(int i=1;i<n; i++){
//             int res=INT_MAX;
//             for(int j=1; j<=k ;j++){
//                 if(i-j>=0){
//                     int cash= dp[i-j]+abs(arr[i]-arr[i-j]);
//                     res=min(res,cash);
//                 }
//             }
//             dp[i]=res;
//         }
//         return dp[n-1];
//     }

// space optimization
// public:
//     int minimizeCost(int k, vector<int>& arr) {
//         int n = arr.size();
//         vector<int> dp(k, INT_MAX); // Use a k-size array
//         dp[0] = 0; // Base case: cost to reach the first stone is 0

//         for (int i = 1; i < n; i++) {
//             int curr = INT_MAX;

//             for (int j = 1; j <= k; j++) {
//                 if (i - j >= 0) {
//                     curr = min(curr, dp[(i - j) % k] + abs(arr[i] - arr[i - j]));
//                 }
//             }

//             dp[i % k] = curr; // Update the sliding window
//         }

//         return dp[(n - 1) % k]; // The result is in the index corresponding to the last stone
//     }
// };







// 198. House Robber
// Solved
// Medium
// Topics
// Companies
// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

// Example 1:

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.
// Example 2:

// Input: nums = [2,7,9,3,1]
// Output: 12
// Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
// Total amount you can rob = 2 + 9 + 1 = 12.
 

// Constraints:

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 400



// top down
// class Solution {
// private:
// // topDown approach
//     int f(vector<int> &arr,vector<int> &dp,int ind){
//         if(ind==0) return arr[ind];
//         if(ind ==1) return max(arr[1],arr[0]);
//         if(dp[ind]!=-1) return dp[ind];
//         int pick= arr[ind]+ f(arr,dp,ind-2);
//         int dpick = f(arr,dp,ind-1);
//         return dp[ind]=max(pick,dpick);
//     }
// public:
//     int rob(vector<int>& arr) {
//         int n=arr.size();
//         vector<int> dp(n,-1);
//         return f(arr,dp,n-1);
//     }
// };


// // 2nd top down approach
// int f(vector<int> &arr,vector<int> &dp,int ind){
//     if(ind==0) return arr[0];
//     if(ind<0) return 0;
//     if(dp[ind]!=-1) return dp[ind];
//     int pick= f(arr,dp,ind-2) +arr[ind];
//     int dpick= f(arr,dp,ind-1);
//     return dp[ind]= max(pick,dpick);
// }



// bottom up
// public:
//     int rob(vector<int>& arr) {
//         int n=arr.size();
//         int prev2= 0;
        
//         int prev= arr[0];
//         for(int i=1; i<n; i++){
//             int take = arr[i];
//             if(i>1){
//                 take+=prev2;
//             }
//             int dtake = 0+prev;
//             int res=max(take,dtake);
//             prev2=prev;
//             prev=res;
//         }
//         return prev;
//     }






// //Geek's Training
// Difficulty: MediumAccuracy: 49.98%Submissions: 91K+Points: 4
// Geek is going for a training program. He can perform any of these activities: Running, Fighting, and Learning Practice. Each activity has some point on each day. As Geek wants to improve all his skills, he can't do the same activity on two consecutive days. Help Geek to maximize his merit points as you are given a 2D array of points arr, corresponding to each day and activity.

// Example:
// Input: n = 3 and arr[]= [[1,2,5],[3,1,1],[3,3,3]]
// Output:11
// Explanation: Geek will learn a new move and earn 5 point then on second day he will do running and earn 3 point and on third day he will do fighting and earn 3 points so, maximum point is 11.
// Constraint:
// 1 <=  arr.size <= 105
// 1 <=  arr[i][j] <= 100



// // top down appraoch
// int f(int day,int act,vector<vector<int>> &arr,vector<vector<int>> &dp){
//         if(day==0){
//             int res=0;
//             for(int i=0; i<3; i++){
//                 if(i!=act){
//                     res=max(res,arr[day][i]);
                    
//                 }
//             }
            
//             return dp[day][act]=res;
//         }
//         if(dp[day][act]!=-1) return dp[day][act];
//         int res=0;
//         for(int i=0; i<3; i++){
//             if(i!=act){
//                 int cash= f(day-1,i,arr,dp)+arr[day][i];
//                 res=max(res,cash);
//             }
//         }
//         return dp[day][act]= res;
//     }
//   public:
//     int maximumPoints(vector<vector<int>>& arr, int n) {
//         vector<vector<int>> dp(n+1,vector<int>(4,-1));
//         return f(n-1,3,arr,dp);
//     }



// bottoms up
// public:
//     int maximumPoints(vector<vector<int>>& arr, int n) {
//         // bottom's up approach
//         vector<vector<int>> dp(n,vector<int>(4,-1));
//         dp[0][0]= max(arr[0][1],arr[0][2]);
//         dp[0][1]= max(arr[0][0],arr[0][2]);
//         dp[0][2]= max(arr[0][1],arr[0][0]);
//         dp[0][3]= max(arr[0][1],max(arr[0][0],arr[0][2]));
        
//         for(int i=1; i<n; i++){
//             for(int j=0; j<4; j++){
//                 int res=0;
//                 for(int k=0; k<3; k++){
//                     if(k!=j){
//                         int cash= dp[i-1][k] +arr[i][k];
//                         res=max(res,cash);
//                     }
//                 }
//                 dp[i][j]= res;
//             }
//         }
//         return dp[n-1][3];
//      }


// // bottoms up(space optimization)
//  public:
//     int maximumPoints(vector<vector<int>>& arr, int n) {
//         // bottom's up approach
//         // vector<vector<int>> dp(n,vector<int>(4,-1));
//         vector<int> dp(4,-1);
//         dp[0]= max(arr[0][1],arr[0][2]);
//         dp[1]= max(arr[0][0],arr[0][2]);
//         dp[2]= max(arr[0][1],arr[0][0]);
//         dp[3]= max(arr[0][1],max(arr[0][0],arr[0][2]));
        
//         for(int i=1; i<n; i++){
//             vector<int> temp(4,-1);
//             for(int j=0; j<4; j++){
//                 int res=0;
//                 for(int k=0; k<3; k++){
//                     if(k!=j){
//                         int cash= dp[k] +arr[i][k];
//                         res=max(res,cash);
//                     }
//                 }
//                 temp[j]= res;
//             }
//             dp=temp;
            
//         }
//         return dp[3];
//      }





