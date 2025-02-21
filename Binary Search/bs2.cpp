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