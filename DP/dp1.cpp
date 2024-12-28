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