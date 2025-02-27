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




//Allocate Minimum Pages
Difficulty: MediumAccuracy: 35.51%Submissions: 252K+Points: 4Average Time: 35m
You are given an array arr[] of integers, where each element arr[i] represents the number of pages in the ith book. You also have an integer k representing the number of students. The task is to allocate books to each student such that:

Each student receives atleast one book.
Each student is assigned a contiguous sequence of books.
No book is assigned to more than one student.
The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum.

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).

Examples:

Input: arr[] = [12, 34, 67, 90], k = 2
Output: 113
Explanation: Allocation can be done in following ways:
[12] and [34, 67, 90] Maximum Pages = 191
[12, 34] and [67, 90] Maximum Pages = 157
[12, 34, 67] and [90] Maximum Pages = 113.
Therefore, the minimum of these cases is 113, which is selected as the output.
Input: arr[] = [15, 17, 20], k = 5
Output: -1
Explanation: Allocation can not be done.
Input: arr[] = [22, 23, 67], k = 1
Output: 112
Constraints:
1 <=  arr.size() <= 106
1 <= arr[i] <= 103
1 <= k <= 103 


// optimal solution (binary search)
class Solution {
    private:
      bool f(vector<int> &arr, int val ,int k){
          int n=arr.size();
          int sum=arr[0];
          int count=0;
          for(int i=1; i<n; i++){
              if(sum+arr[i]<=val){
                  sum+=arr[i];
              }
              else{
                  sum=arr[i];
                  count++;
              }
          }
          return (count+1<=k);
      }
    public:
      int findPages(vector<int> &arr, int k) {
          int n=arr.size();
          if(n<k) return -1;
          int high=accumulate(arr.begin(),arr.end(),0);
          int low=*max_element(arr.begin(),arr.end());
          while(low<=high){
              int mid=low+(high-low)/2;
              bool val=f(arr,mid,k);
              if(val){
                  high=mid-1;
              }
              else{
                  low=mid+1;
              }
          }
          return low;
      }
};



//410. Split Array Largest Sum
Solved
Hard
Topics
Companies
Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.

 

Example 1:

Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
Example 2:

Input: nums = [1,2,3,4,5], k = 2
Output: 9
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.
 

Constraints:

1 <= nums.length <= 1000
0 <= nums[i] <= 106
1 <= k <= min(50, nums.length)


// optimal solution (binary search)
class Solution {
    private:
        bool f(vector<int> &arr,long long val, int k){
            long long sum=arr[0];
            int n=arr.size(),count=1;
            for(int i=1; i<n; i++){
                long long lsum=sum+arr[i];
                if(lsum<=val){
                    sum+=arr[i];
                }
                else{
                    sum=arr[i];
                    count++;
                }
            }
            return (count<=k);
        }
    public:
        int splitArray(vector<int>& arr, int k) {
            int n=arr.size();
            long long  low=*max_element(arr.begin(),arr.end());
            long long  high=accumulate(arr.begin(),arr.end(),0);
            while(low<=high){
                long long  mid=low+(high-low)/2;
                bool val=f(arr,mid,k);
                if(val){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            return low;
        }
};




//The Painter's Partition Problem-II
Difficulty: HardAccuracy: 27.52%Submissions: 129K+Points: 8
Dilpreet wants to paint his dogs home that has n boards with different lengths. The length of ith board is given by arr[i] where arr[] is an array of n integers. He hired k painters for this work and each painter takes 1 unit time to paint 1 unit of the board.

Return the minimum time to get this job done if all painters start together with the constraint that any painter will only paint continuous boards, say boards numbered [2,3,4] or only board [1] or nothing but not boards [2,4,5].

Examples:

Input: arr[] = [5, 10, 30, 20, 15], k = 3
Output: 35
Explanation: The most optimal way will be: Painter 1 allocation : [5,10], Painter 2 allocation : [30], Painter 3 allocation : [20,15], Job will be done when all painters finish i.e. at time = max(5+10, 30, 20+15) = 35
Input: arr[] = [10, 20, 30, 40], k = 2
Output: 60
Explanation: The most optimal way to paint: Painter 1 allocation : [10,20,30], Painter 2 allocation : [40], Job will be complete at time = 60
Input: arr[] = [100, 200, 300, 400], k = 1
Output: 1000
Explanation: There is only one painter, so the painter must paint all boards sequentially. The total time taken will be the sum of all board lengths, i.e., 100 + 200 + 300 + 400 = 1000.
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 105
1 ≤ k ≤ 105


//  optimal solution (binary search)
class Solution {
    private:
      bool f(vector<int> & arr,long long val ,int k){
          long long sum=arr[0];
          int n=arr.size();
          int count=1;
          for(int i=1;i<n; i++){
              long long lsum=arr[i]+sum;
              if(lsum<=val){
                  sum+=arr[i];
              }
              else{
                  count++;
                  sum=arr[i];
              }
          }
          return (count<=k);
      }
    public:
      int minTime(vector<int>& arr, int k) {
          int n=arr.size();
          long long low=*max_element(arr.begin(),arr.end());
          long long high=accumulate(arr.begin(),arr.end(),0);
          while(low<=high){
              long long mid=low+(high-low)/2;
              bool val=f(arr,mid,k);
              if(val){
                  high=mid-1;
              }
              else{
                  low=mid+1;
              }
          }
          return low;
      }
  };






//Minimize Max Distance to Gas Station
Difficulty: HardAccuracy: 38.36%Submissions: 69K+Points: 8Average Time: 40m
We have a horizontal number line. On that number line, we have gas stations at positions stations[0], stations[1], ..., stations[n-1], where n is the size of the stations array. Now, we add k more gas stations so that d, the maximum distance between adjacent gas stations, is minimized. We have to find the smallest possible value of d. Find the answer exactly to 2 decimal places.
Note: stations is in a strictly increasing order.

Example 1:

Input:
n = 10
stations[] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
k = 9
Output: 0.50
Explanation: Each of the 9 stations can be added mid way between all the existing adjacent stations.
Example 2:

Input:
n = 10
stations[] = [3, 6, 12, 19, 33, 44, 67, 72, 89, 95] 
k = 2 
Output: 14.00 
Explanation: Construction of gas stations at 8th(between 72 and 89) and 6th(between 44 and 67) locations.
Your Task:
You don''t need to read input or print anything. Your task is to complete the function findSmallestMaxDist() which takes a list of stations and integer k as inputs and returns the smallest possible value of d. Find the answer exactly to 2 decimal places.

Constraint:
10 <= n <= 10000 
0 <= stations[i] <= 109 
0 <= k <= 105

// better solution t:O(nlogn) s:O(n);

class Solution {
    public:
      double findSmallestMaxDist(vector<int> &arr, int k) {
          int n=arr.size();
          priority_queue<pair<double,int>> pq;
          for(int i=1; i<n;i++){
              double val=arr[i]-arr[i-1];
              pq.push({val,1});
          }
          int count=k;
          while(count--){
              auto ele=pq.top();
              pq.pop();
              double dist=ele.first*ele.second;
              int par=ele.second;
              par++;
              pq.push({dist/par,par});
          }
          return round(pq.top().first*100)/100;
      }
};



// efficent solution t:O(nlogn) s:O(1);
class Solution {
    private:
      int f(vector<int> &arr, long double dist){
          int count=0;
          for(int i=1; i<arr.size(); i++){
              int numberInBetween=(arr[i]-arr[i-1])/dist;
              if((arr[i]-arr[i-1])/dist == numberInBetween +dist){
                  numberInBetween--;
              }
              count+=numberInBetween;
          }
          return count;
      }
    public:
      double findSmallestMaxDist(vector<int> &arr, int k) {
          int n=arr.size();
          long double high=0;
          for(int i=1; i<n; i++){
              high=max(high,(long double)arr[i]-arr[i-1]);
          }
          long double low=0;
          long double diff=1e-7;
          while(high-low> diff){
              long double mid=(low+high)/2.0;
              int count=f(arr,mid);
              if(count>k){
                  low=mid;
              }
              else{
                  high=mid;
              }
          }
          return high;
      }
};




//4. Median of Two Sorted Arrays
Solved
Hard
Topics
Companies
Amazon
Adobe
Goldman Sachs
Microsoft
Apple
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106



// brute force O(m*n)
class Solution {
    private:
        int f(vector<int> &a,vector<int> &b,int ind){
            int n=a.size(),m=b.size();
            if(n==0) return b[ind-1];
            if(m==0) return a[ind-1];
            int i=0,j=0,prev;
            if(a[0]<b[0]){
                prev=a[0];i++;
            }
            else{
                prev=b[0];j++;
            }
            int count=1;
            if(ind==1) return prev;
            while(i<n && j<m){
                if(a[i]<b[j]){
                    prev=a[i];count++;i++;
                }
                else{
                    prev=b[j];count++;j++;
                }
                if(count==ind) return prev;
            }
            count++;
            if(i==n){
                while(count<ind){
                    count++;j++;
                }
                return b[j];
            }
            if(j==m){
                while(count<ind){
                    count++;i++;
                }
                return a[i];
            }
            return -1;
        }
    public:
        double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
            int n=a.size(),m=b.size();
            if((n+m)%2==0){
                int ele1=f(a,b,(n+m)/2);
                int ele2=f(a,b,(n+m)/2+1);
                return ((double)ele1+ele2)/2.0;
            }
            return (double)f(a,b,(n+m)/2+1);
        }
};



// optimal soluton O(log(min(n,m)))
class Solution {
    public:
        double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
            int n=a.size(),m=b.size();
            if(n>m) return findMedianSortedArrays(b,a);
            int t=n+m;
            int low=0,high=n;
            while(low<=high){
                int mid1=(low+high)/2;
                int mid2=t/2-mid1;
                int l1=INT_MIN,l2=INT_MIN;
                int r1=INT_MAX,r2=INT_MAX;
                if(mid1<n) r1=a[mid1];
                if(mid2<m) r2=b[mid2];
                if(mid1-1>=0) l1=a[mid1-1];
                if(mid2-1>=0) l2=b[mid2-1];
                if(l2>r1){
                    low=mid1+1;
                }
                else if(r2>=l1 && r1>=l2){
                    if(t%2==0){
                        return ((double)max(l1,l2)+(double)min(r1,r2))/2.0;
                    }
                    else{
                        return ((double)min(r1,r2));
                    }
                }
                else{
                    high=mid1-1;
                }
            }
            return 0;
        }
};




//K-th element of two Arrays
Difficulty: MediumAccuracy: 37.4%Submissions: 323K+Points: 4Average Time: 15m
Given two sorted arrays a[] and b[] and an element k, the task is to find the element that would be at the kth position of the combined sorted array.

Examples :

Input: a[] = [2, 3, 6, 7, 9], b[] = [1, 4, 8, 10], k = 5
Output: 6
Explanation: The final combined sorted array would be [1, 2, 3, 4, 6, 7, 8, 9, 10]. The 5th element of this array is 6.
Input: a[] = [100, 112, 256, 349, 770], b[] = [72, 86, 113, 119, 265, 445, 892], k = 7
Output: 256
Explanation: Combined sorted array is [72, 86, 100, 112, 113, 119, 256, 265, 349, 445, 770, 892]. The 7th element of this array is 256.
Constraints:

1 <= a.size(), b.size() <= 106
1 <= k <= a.size() + b.size()
0 <= a[i], b[i] < 108



// brute force O(n+m)
class Solution {
    public:
      int kthElement(vector<int>& a, vector<int>& b, int k) {
          int n=a.size(),m=b.size();
          int i=0,j=0;
          int prev=-1,count=0;
          while(i<n && j<m){
              if(a[i]<b[j]){
                  prev=a[i];
                  i++;count++;
              }
              else{
                  prev=b[j];
                  j++;count++;
              }
              if(count==k) return prev;
          }
          count++;
          if(j>=m){
              while(count<k){
                  i++;count++;
              }
              return a[i];
          }
          if(i>=n){
              while(count<k){
                  j++;count++;
              }
              return b[j];
          }
          return -1;
      }
  };


  // optimal solution O(log(min(n,m)))
  class Solution {
    public:
      int kthElement(vector<int>& a, vector<int>& b, int k) {
          int n=a.size(),m=b.size();
          int low=max(0,k-m),high=min(n,k);
          while(low<=high){
              int mid1=(low+high)/2;
              int mid2=k-mid1;
              int l1=INT_MIN,l2=INT_MIN;
              int r1=INT_MAX,r2=INT_MAX;
              if(mid1<n) r1=a[mid1];
              if(mid2<m) r2=b[mid2];
              if(mid1-1>=0) l1=a[mid1-1];
              if(mid2-1>=0) l2=b[mid2-1];
              if(l2>r1){
                  low=mid1+1;
              }
              else if(r2>=l1 && r1>=l2){
                  return max(l1,l2);
              }
              else{
                  high=mid1-1;
              }
          }
          return 0;
      }
  };


  