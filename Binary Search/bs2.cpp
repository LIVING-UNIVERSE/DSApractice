//875. Koko Eating Bananas
Solved
Medium
Topics
Companies
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

 

Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4
Example 2:

Input: piles = [30,11,23,4,20], h = 5
Output: 30
Example 3:

Input: piles = [30,11,23,4,20], h = 6
Output: 23
 

Constraints:

1 <= piles.length <= 104
piles.length <= h <= 109
1 <= piles[i] <= 109



// optimal solution (binary search)
class Solution {
    private:
    long long f(int ele,vector<int>& arr){
            long long sum=0;
            for(int i=0; i<arr.size();i++){
               if(arr[i]%ele==0){
                    sum+=arr[i]/ele;
               }
               else{
                    sum+=(arr[i]/ele+1);
               }
            }
            return sum;
    }
    public:
        int minEatingSpeed(vector<int>& arr, int h) {
            int n=arr.size();
            int low=1;
            int high=*max_element(arr.begin(),arr.end());
            while(low<=high){
                int mid=(low+high)/2;
                long long val=f(mid,arr);
                if(val<=h){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            return low;
        }
    };





//1482. Minimum Number of Days to Make m Bouquets
Solved
Medium
Topics
Companies
Hint
You are given an integer array bloomDay, an integer m and an integer k.

You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.

The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.

Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.

 

Example 1:

Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
Output: 3
Explanation: Let us see what happened in the first three days. x means flower bloomed and _ means flower did not bloom in the garden.
We need 3 bouquets each should contain 1 flower.
After day 1: [x, _, _, _, _]   // we can only make one bouquet.
After day 2: [x, _, _, _, x]   // we can only make two bouquets.
After day 3: [x, _, x, _, x]   // we can make 3 bouquets. The answer is 3.
Example 2:

Input: bloomDay = [1,10,3,10,2], m = 3, k = 2
Output: -1
Explanation: We need 3 bouquets each has 2 flowers, that means we need 6 flowers. We only have 5 flowers so it is impossible to get the needed bouquets and we return -1.
Example 3:

Input: bloomDay = [7,7,7,7,12,7,7], m = 2, k = 3
Output: 12
Explanation: We need 2 bouquets each should have 3 flowers.
Here is the garden after the 7 and 12 days:
After day 7: [x, x, x, x, _, x, x]
We can make one bouquet of the first three flowers that bloomed. We cannot make another bouquet from the last three flowers that bloomed because they are not adjacent.
After day 12: [x, x, x, x, x, x, x]
It is obvious that we can make two bouquets in different ways.
 

Constraints:

bloomDay.length == n
1 <= n <= 105
1 <= bloomDay[i] <= 109
1 <= m <= 106
1 <= k <= n



// optimal solution (binary search)
class Solution {
    private:
        bool f(long long val,vector<int> &arr, int m, int k){
            long long n=arr.size();
            int count=0,ans=0;
            for(int i=0; i<n; i++){
                if(arr[i]<=val){
                    count++;
                }
                if(count==k || arr[i]>val){
                    if(count==k) ans++;
                    count=0;
                }
            }
            return (ans>=m);
        }
    public:
        int minDays(vector<int>& arr, int m, int k) {
            int n=arr.size();
            long long val=m*1LL*k*1LL;
            if(n<(long long)m*k) return -1;
            long long low=*min_element(arr.begin(),arr.end());
            long long high=*max_element(arr.begin(),arr.end());
            while(low<=high){
                long long mid=low+(high-low)/2;
                bool possible=f(mid,arr,m,k);
                if(possible){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            return low;
        }
};





//1011. Capacity To Ship Packages Within D Days
Solved
1725
Medium
Topics
Companies
Hint
A conveyor belt has packages that must be shipped from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

 

Example 1:

Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15
Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10

Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.
Example 2:

Input: weights = [3,2,2,4,1,4], days = 3
Output: 6
Explanation: A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
1st day: 3, 2
2nd day: 2, 4
3rd day: 1, 4
Example 3:

Input: weights = [1,2,3,1,1], days = 4
Output: 3
Explanation:
1st day: 1
2nd day: 2
3rd day: 3
4th day: 1, 1
 

Constraints:

1 <= days <= weights.length <= 5 * 104
1 <= weights[i] <= 500



// optimal solution (binary search)
class Solution {
    private:
        int f(int val,vector<int> &arr, int days){
            int count=val,ans=0;
            int n=arr.size();
            for(int i=0; i<n; i++){
                if(arr[i]<=count){
                    count-=arr[i];
                }
                else{
                    ans++;
                    count=val-arr[i];
                }
            }
            return ans+1;
        }
    public:
        int shipWithinDays(vector<int>& arr, int days) {
            int n=arr.size();
            int low=*max_element(arr.begin(),arr.end());
            int high=accumulate(arr.begin(),arr.end(),0);
            while(low<=high){
                int mid=low+(high-low)/2;
                int reqDays=f(mid,arr,days);
                if(reqDays<=days){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            return low;
        }
};





//1283. Find the Smallest Divisor Given a Threshold
Solved
Medium
Topics
Companies
Hint
Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the divisions result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

The test cases are generated so that there will be an answer.

 

Example 1:

Input: nums = [1,2,5,9], threshold = 6
Output: 5
Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1. 
If the divisor is 4 we can get a sum of 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2). 
Example 2:

Input: nums = [44,22,33,11,1], threshold = 5
Output: 44
 

Constraints:

1 <= nums.length <= 5 * 104
1 <= nums[i] <= 106
nums.length <= threshold <= 106



// optimal solution (binary search)
class Solution {
    private:
        long long f(int val,vector<int> &arr){
            long long sum=0;
            for(int i=0; i<arr.size(); i++){
                sum+=(long long)ceil((double)arr[i]/val);
            }
            return sum;
        }
    public:
        int smallestDivisor(vector<int>& arr, int threshold) {
            int n=arr.size();
            if(threshold<n) return -1;
            int low=1,high=*max_element(arr.begin(),arr.end());
            while(low<=high){
                int mid=low+(high-low)/2;
                long long val=f(mid,arr);
                if(val<=threshold){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            return low;
        }
};




//Aggressive Cows
Difficulty: MediumAccuracy: 59.57%Submissions: 114K+Points: 4Average Time: 30m
You are given an array with unique elements of stalls[], which denote the position of a stall. You are also given an integer k which denotes the number of aggressive cows. Your task is to assign stalls to k cows such that the minimum distance between any two of them is the maximum possible.

Examples :

Input: stalls[] = [1, 2, 4, 8, 9], k = 3
Output: 3
Explanation: The first cow can be placed at stalls[0], 
the second cow can be placed at stalls[2] and 
the third cow can be placed at stalls[3]. 
The minimum distance between cows, in this case, is 3, which also is the largest among all possible ways.
Input: stalls[] = [10, 1, 2, 7, 5], k = 3
Output: 4
Explanation: The first cow can be placed at stalls[0],
the second cow can be placed at stalls[1] and
the third cow can be placed at stalls[4].
The minimum distance between cows, in this case, is 4, which also is the largest among all possible ways.
Input: stalls[] = [2, 12, 11, 3, 26, 7], k = 5
Output: 1
Explanation: Each cow can be placed in any of the stalls, as the no. of stalls are exactly equal to the number of cows.
The minimum distance between cows, in this case, is 1, which also is the largest among all possible ways.
Constraints:
2 <= stalls.size() <= 106
0 <= stalls[i] <= 108
2 <= k <= stalls.size()



// optimal solution (binary search)
class Solution {
    private:
      bool f(vector<int> &arr, int k, int dist){
          int prev=arr[0],count=1;
          int n=arr.size();
          int i=1;
          while(i<n){
              if(arr[i]-prev>=dist){
                  count++;
                  prev=arr[i];
              }
              i++;
          }
          return (count>=k);
          
      }
    public:
      int aggressiveCows(vector<int> &arr, int k) {
          sort(arr.begin(),arr.end());
          int low=1,high=*max_element(arr.begin(),arr.end());
          while(low<=high){
              int mid=low+(high-low)/2;
              bool val=f(arr,k,mid);
              if(val){
                  low=mid+1;
              }
              else{
                  high=mid-1;;
              }
          }
          return high;
      }
  };