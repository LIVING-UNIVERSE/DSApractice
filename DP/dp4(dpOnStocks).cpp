//121. Best Time to Buy and Sell Stock
Solved
Easy
Topics
Companies
Amazon
Facebook
Microsoft
Bloomberg
Google
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
 

Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 104



//solution
class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        int minele=1e8,profit=0;
        for(int i=0; i<n; i++){
            minele=min(minele,arr[i]);
            profit=max(profit,arr[i]-minele);
        }
        return profit;
    }
};



//122. Best Time to Buy and Sell Stock II
Solved
Medium
Topics
Companies
Amazon
Facebook
Walmart Global Tech
Microsoft
Bloomberg
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.
 

Constraints:

1 <= prices.length <= 3 * 104
0 <= prices[i] <= 104



// top donw approach
class Solution {
private:
    int f(int ind,int buy,vector<int> &arr,int n,vector<vector<int>> &dp){
        if(ind==n) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy){
            int notBought=f(ind+1,1,arr,n,dp);
            int bought = -arr[ind]+f(ind+1,0,arr,n,dp);
            return dp[ind][buy]= max(bought,notBought);
        }
        int notSell= f(ind+1,0,arr,n,dp);
        int sell=arr[ind]+f(ind+1,1,arr,n,dp);
        return dp[ind][buy]= max(sell,notSell);
    }
public:
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return  f(0,1,arr,n,dp);
    }
};



// bottoms up approach
class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        for(int i=n-1; i>=0; i--){
            for(int j=1;j>=0;j--){
                if(j){
                    int notBought=dp[i+1][1];
                    int bought = -arr[i]+dp[i+1][0];
                    dp[i][j]=max(bought,notBought);
                }
                else{
                    int notSell=dp[i+1][0];
                    int sell= arr[i]+dp[i+1][1];
                    dp[i][j]=max(sell,notSell);
                }
            }
        }
        return  dp[0][1];
    }
};



// bottoms up approach(space optimization)
class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        vector<int> prev(2,0),curr(2,0);
        for(int i=n-1; i>=0; i--){
            for(int j=1;j>=0;j--){
                if(j){
                    int notBought=prev[1];
                    int bought = -arr[i]+prev[0];
                    curr[j]=max(bought,notBought);
                }
                else{
                    int notSell=prev[0];
                    int sell= arr[i]+prev[1];
                    curr[j]=max(sell,notSell);
                }
            }
            prev=curr;
        }
        return  prev[1];
    }
};