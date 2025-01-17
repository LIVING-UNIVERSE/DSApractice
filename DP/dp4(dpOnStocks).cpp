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




//309. Best Time to Buy and Sell Stock with Cooldown
Solved
Medium
Topics
Companies
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]
Example 2:

Input: prices = [1]
Output: 0
 

Constraints:

1 <= prices.length <= 5000
0 <= prices[i] <= 1000


// top down approach
class Solution {
private:
    int f(int ind,int buy,vector<int> &arr,int n,vector<vector<int>> &dp){
        if(ind>=n) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy){
            int notBought=f(ind+1,1,arr,n,dp);
            int bought = -arr[ind]+f(ind+1,0,arr,n,dp);
            return dp[ind][buy]= max(bought,notBought);
        }
        int notSell= f(ind+1,0,arr,n,dp);
        int sell=arr[ind]+f(ind+2,1,arr,n,dp);
        return dp[ind][buy]= max(sell,notSell);
    }
public:
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> dp(n+2,vector<int>(2,-1));
        return f(0,1,arr,n,dp);
    }
};


// bottoms up approach
class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        for(int i=n-1; i>=0; i--){
            for(int j=1;j>=0;j--){
                if(j){
                    int notBought=dp[i+1][1];
                    int bought = -arr[i]+dp[i+1][0];
                    dp[i][j]= max(bought,notBought);
                }
                else{
                    int notSell=dp[i+1][0];
                    int sell=arr[i]+dp[i+2][1];
                    dp[i][j]= max(sell,notSell);
                }
            }
        }
        return dp[0][1];
    }
};



// bottoms up approach(space optimized)
class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        vector<int> prev1(2,0),prev2(2,0),curr(2,0);
        for(int i=n-1; i>=0; i--){
            for(int j=1;j>=0;j--){
                if(j){
                    int notBought=prev1[1];
                    int bought = -arr[i]+prev1[0];
                    curr[j]= max(bought,notBought);
                }
                else{
                    int notSell=prev1[0];
                    int sell=arr[i]+prev2[1];
                    curr[j]= max(sell,notSell);
                }
            }
            prev2=prev1;
            prev1=curr;
        }
        return prev1[1];
    }
};




//714. Best Time to Buy and Sell Stock with Transaction Fee
Solved
Medium
Topics
Companies
Hint
Amazon
Facebook
You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note:

You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
The transaction fee is only charged once for each stock purchase and sale.
 

Example 1:

Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
Example 2:

Input: prices = [1,3,7,5,10,3], fee = 3
Output: 6
 

Constraints:

1 <= prices.length <= 5 * 104
1 <= prices[i] < 5 * 104
0 <= fee < 5 * 104



// top down approach
class Solution {
private:
    int f(int ind,int buy,vector<int> &arr,int n,vector<vector<int>> &dp,int fee){
        if(ind==n) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy){
            int notBought=f(ind+1,1,arr,n,dp,fee);
            int bought = -fee-arr[ind]+f(ind+1,0,arr,n,dp,fee);
            return dp[ind][buy]= max(bought,notBought);
        }
        int notSell= f(ind+1,0,arr,n,dp,fee);
        int sell=arr[ind]+f(ind+1,1,arr,n,dp,fee);
        return dp[ind][buy]= max(sell,notSell);
    }
public:
    int maxProfit(vector<int>& arr, int fee) {
        int n=arr.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return  f(0,1,arr,n,dp,fee);
    }
};

// bottoms up approach
class Solution {
public:
    int maxProfit(vector<int>& arr, int fee) {
        int n=arr.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        for(int i=n-1; i>=0; i--){
            for(int j=1;j>=0;j--){
                if(j){
                    int notBought=dp[i+1][1];
                    int bought = -fee-arr[i]+dp[i+1][0];
                    dp[i][j]= max(bought,notBought);
                }
                else{
                    int notSell= dp[i+1][0];
                    int sell=arr[i]+dp[i+1][1];
                    dp[i][j]= max(sell,notSell);
                }
            }
        }
        return  dp[0][1];
    }
};

// bottoms up approach(space optimized)
class Solution {
public:
    int maxProfit(vector<int>& arr, int fee) {
        int n=arr.size();
        vector<int> prev(2,0),curr(2,0);
        for(int i=n-1; i>=0; i--){
            for(int j=1;j>=0;j--){
                if(j){
                    int notBought=prev[1];
                    int bought = -fee-arr[i]+prev[0];
                    curr[j]= max(bought,notBought);
                }
                else{
                    int notSell= prev[0];
                    int sell=arr[i]+prev[1];
                    curr[j]= max(sell,notSell);
                }
            }
            prev=curr;
        }
        return  prev[1];
    }
};




//123. Best Time to Buy and Sell Stock III
Solved
Hard
Topics
Companies
Amazon
Uber
Apple
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
 

Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 105



// top down approach
class Solution {
private:
    int f(int ind,int buy,vector<int> &arr,vector<vector<int>> &dp){
        if(buy==0 || ind==arr.size()) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy%2==0){
            int notBought=f(ind+1,buy,arr,dp);
            int bought=-arr[ind]+f(ind+1,buy-1,arr,dp);
            return dp[ind][buy]= max(bought,notBought);
        }
        int notSell=f(ind+1,buy,arr,dp);
        int sell=arr[ind]+f(ind+1,buy-1,arr,dp);
        return dp[ind][buy]= max(sell,notSell);
    }
public:
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> dp(n+1,vector<int>(5,-1));
        return f(0,4,arr,dp);
    }
};



// bottoms up approach
class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> dp(n+1,vector<int>(5,0));
        for(int i=n-1; i>=0; i--){
            for(int j=1; j<=4; j++){
                if(j%2==0){
                    int notBought=dp[i+1][j];
                    int bought=-arr[i]+dp[i+1][j-1];
                    dp[i][j]= max(bought,notBought);
                }
                else{
                    int notSell=dp[i+1][j];
                    int sell=arr[i]+dp[i+1][j-1];
                    dp[i][j]= max(sell,notSell); 
                }
            }
        }
        return dp[0][4];
    }
};



// bottoms up approach(space optimized)
class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        vector<int> prev(5,0),curr(5,0);
        for(int i=n-1; i>=0; i--){
            for(int j=1; j<=4; j++){
                if(j%2==0){
                    int notBought=prev[j];
                    int bought=-arr[i]+prev[j-1];
                    curr[j]= max(bought,notBought);
                }
                else{
                    int notSell=prev[j];
                    int sell=arr[i]+prev[j-1];
                    curr[j]= max(sell,notSell); 
                }
            }
            prev=curr;
        }
        return prev[4];
    }
};



//188. Best Time to Buy and Sell Stock IV
Solved
Hard
Topics
Companies
Amazon
Apple
Nvidia
Google
Citadel
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 

Constraints:

1 <= k <= 100
1 <= prices.length <= 1000
0 <= prices[i] <= 1000



// this is just same as the previous problem Best Time to Buy and Sell Stock III ; here you have to do 'k' transactions instead
//of 2 so replace 4 by 2*k


// bottoms up approach(space optimized)
class Solution {
public:
    int maxProfit(int k, vector<int>& arr) {
         int n=arr.size();
        vector<int> prev(2*k+1,0),curr(2*k+1,0);
        for(int i=n-1; i>=0; i--){
            for(int j=1; j<=2*k; j++){
                if(j%2==0){
                    int notBought=prev[j];
                    int bought=-arr[i]+prev[j-1];
                    curr[j]= max(bought,notBought);
                }
                else{
                    int notSell=prev[j];
                    int sell=arr[i]+prev[j-1];
                    curr[j]= max(sell,notSell); 
                }
            }
            prev=curr;
        }
        return prev[2*k];
    }
};