//2220. Minimum Bit Flips to Convert Number
Solved
1282
Easy
Topics
Companies
Hint
persistent systems
A bit flip of a number x is choosing a bit in the binary representation of x and flipping it from either 0 to 1 or 1 to 0.

For example, for x = 7, the binary representation is 111 and we may choose any bit (including any leading zeros not shown) and flip it. We can flip the first bit from the right to get 110, flip the second bit from the right to get 101, flip the fifth bit from the right (a leading zero) to get 10111, etc.
Given two integers start and goal, return the minimum number of bit flips to convert start to goal.

 

Example 1:

Input: start = 10, goal = 7
Output: 3
Explanation: The binary representation of 10 and 7 are 1010 and 0111 respectively. We can convert 10 to 7 in 3 steps:
- Flip the first bit from the right: 1010 -> 1011.
- Flip the third bit from the right: 1011 -> 1111.
- Flip the fourth bit from the right: 1111 -> 0111.
It can be shown we cannot convert 10 to 7 in less than 3 steps. Hence, we return 3.
Example 2:

Input: start = 3, goal = 4
Output: 3
Explanation: The binary representation of 3 and 4 are 011 and 100 respectively. We can convert 3 to 4 in 3 steps:
- Flip the first bit from the right: 011 -> 010.
- Flip the second bit from the right: 010 -> 000.
- Flip the third bit from the right: 000 -> 100.
It can be shown we cannot convert 3 to 4 in less than 3 steps. Hence, we return 3.



// solution
class Solution {
    public:
        int minBitFlips(int start, int goal) {
            int temp=start^goal;
            int count=0;
            while(temp!=0){
                temp=temp&(temp-1);
                count++;
            }
            return count;
        }
    };




//136. Single Number
Solved
Easy
Topics
Companies
Hint
Amazon
Microsoft
Bloomberg
Google
Adobe
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,1]

Output: 1

Example 2:

Input: nums = [4,1,2,1,2]

Output: 4

Example 3:

Input: nums = [1]

Output: 1

 

Constraints:

1 <= nums.length <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104
Each element in the array appears twice except for one element which appears only once.



// solution
class Solution {
    public:
        int singleNumber(vector<int>& arr) {
            int n=arr.size();
            int num=arr[0];
            for(int i=1; i<n;i++){
                num^=arr[i];
            }
            return num;
        }
};





//78. Subsets
Solved
Medium
Topics
Companies
Facebook
Amazon
Google
Bloomberg
Microsoft
Given an integer array nums of unique elements, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.



// dp solution (top down)
class Solution {
    private:
        vector<vector<int>> f(int ind,vector<int> &arr){
            if(ind==0){
                return {{},{arr[0]}};
            }
            vector<vector<int>> temp=f(ind-1,arr);
            vector<vector<int>> ans;
            for(int i=0; i<temp.size(); i++){
                ans.push_back(temp[i]);
                temp[i].push_back(arr[ind]);
                ans.push_back(temp[i]);
            }
            return ans;
        }
    public:
        vector<vector<int>> subsets(vector<int>& arr) {
            int n=arr.size();
            return f(n-1,arr);
        }
};

// dp solution (bottoms up)
class Solution {
    public:
        vector<vector<int>> subsets(vector<int>& arr) {
            int n=arr.size();
            vector<vector<vector<int>>> dp(n);
            dp[0]={{},{arr[0]}};
            for(int i=1; i<n; i++){
                vector<vector<int>> temp=dp[i-1];
                vector<vector<int>> ans;
                for(int j=0;j<temp.size(); j++){
                    ans.push_back(temp[j]);
                    temp[j].push_back(arr[i]);
                    ans.push_back(temp[j]);
                }
                dp[i]=ans;
            }
            return dp[n-1];
        }
};


// bit manipulation
class Solution {
    public:
        vector<vector<int>> subsets(vector<int>& arr) {
            int n=arr.size();
            int p=1<<n;
            vector<vector<int>> ans;
            for(int i=0; i<p; i++){
                vector<int> v;
                int k=p;
                for(int j=1; j<=n; j++){
                    if((p>>j)&i){
                        v.push_back(arr[j-1]);
                    }
                }
                ans.push_back(v);
            }
            return ans;
        }
};






//Find XOR of numbers from L to R.
Difficulty: EasyAccuracy: 50.0%Submissions: 52K+Points: 2Average Time: 10m
You are given two integers L and R, your task is to find the XOR of elements of the range [L, R].

Example:

Input: 
L = 4, R = 8 
Output:
8 
Explanation:
4 ^ 5 ^ 6 ^ 7 ^ 8 = 8
Your Task:

Your task is to complete the function findXOR() which takes two integers l and r and returns the XOR of numbers from l to r.

Expected Time Complexity: O(1).

Expected Auxiliary Space: O(1).

Constraints:

1<=l<=r<=109



// bit manipulation
class Solution {
    private:
      int f(int n){
          if(n%4==0) return n;
          if(n%4==1) return 1;
          if(n%4==2) return n+1;
          return 0;
      }
    public:
      int findXOR(int l, int r) {
          l=f(l-1);r=f(r);
          return l^r;
      }
  };




//Two numbers with odd occurrences
Difficulty: MediumAccuracy: 49.49%Submissions: 70K+Points: 4
Given an unsorted array, Arr[] of size N and that contains even number of occurrences for all numbers except two numbers. Find the two numbers in decreasing order which has odd occurrences.

Example 1:

Input:
N = 8
Arr = {4, 2, 4, 5, 2, 3, 3, 1}
Output: {5, 1} 
Explanation: 5 and 1 have odd occurrences.

Example 2:

Input:
N = 8
Arr = {1 7 5 7 5 4 7 4}
Output: {7, 1}
Explanation: 7 and 1 have odd occurrences.

Your Task:
You dont need to read input or print anything. Your task is to complete the function twoOddNum() which takes the array Arr[] and its size N as input parameters and returns the two numbers in decreasing order which have odd occurrences.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)


Constraints:
2 ≤ N ≤ 106
1 ≤ Arri ≤ 1012


// bit manipulation
class Solution{
    public:
    vector<long long int> twoOddNum(long long int arr[], long long int n)  
    {
        long long c=0;
        for(long long i=0; i<n ;i++){
            c=c^arr[i];
        }
        long long bitCount=0;
        while((c&(1<<bitCount))==0){
            bitCount++;
        }
        long long zero=0,one=0;
        for(long long i=0; i<n; i++){
            if(arr[i]&(1<<bitCount)){
                one=one^arr[i];
            }
            else{
                zero=zero^arr[i];
            }
        }
        if(zero>one){
            return {zero,one};
        }
        return {one,zero};
    }
};





//Count total set bits
Difficulty: MediumAccuracy: 35.77%Submissions: 216K+Points: 4
You are given a number n. Find the total count of set bits for all numbers from 1 to n (both inclusive).

Examples :

Input: n = 4
Output: 5
Explanation: For numbers from 1 to 4. For 1: 0 0 1 = 1 set bits For 2: 0 1 0 = 1 set bits For 3: 0 1 1 = 2 set bits For 4: 1 0 0 = 1 set bits Therefore, the total set bits is 5.
Input: n = 17
Output: 35
Explanation: From numbers 1 to 17(both inclusive), the total number of set bits is 35.
Expected Time Complexity: O(logn)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ n ≤ 108


// O(logn) solution
class Solution{
    private:
        int f(int n){
            int bitCount=-1;
            while(n!=0){
                n=n>>1;
                bitCount++;
            }
            return bitCount;
        }
    public:
    int countSetBits(int n){
        if(n==0) return 0;
        int count=f(n);
        return count*(1<<(count-1)) + (n-(1<<count)+1) + countSetBits(n-(1<<count));
    }
};





//29. Divide Two Integers
Solved
Medium
Topics
Companies
Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.

 

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = 3.33333.. which is truncated to 3.
Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = -2.33333.. which is truncated to -2.
 

Constraints:

-231 <= dividend, divisor <= 231 - 1
divisor != 0



// brute force solution
class Solution {
    public:
        int divide(int dividend, int divisor) {
            int divi=abs(dividend),div=abs(divisor);
            int count=0;
            while(divi>=div){
                divi-=div;
                count++;
            }
            if(dividend*divisor<0) return -count;
            return count;
        }
};


// optimal solution
class Solution {
    public:
        int divide(int dividend, int divisor) {
            long long n=abs((long long)dividend);
            long long d=abs((long long)divisor);
            long long q=0;
            while(n>=d){
                long long bitCount=0;
                while((d*(1LL<<bitCount))<=n){
                    bitCount++;
                }
                q+=(1LL<<(bitCount-1));
                n-=d*(1LL<<(bitCount-1));
            }
            long long test=((long long)dividend)*((long long)divisor);
            if((q==pow(2,31)) && (test>0)) return INT_MAX;
            else if((q==pow(2,31)) && (test<0)) return INT_MIN;
            return (test<0)?-q:q;
        }
    };





// some basic maths but important
//Prime Number
Difficulty: BasicAccuracy: 22.2%Submissions: 327K+Points: 1
Given a number n, determine whether it is a prime number or not. A prime number is a number greater than 1 that has no positive divisors other than 1 and itself.

Examples :

Input: n = 7
Output: true
Explanation: 7 has exactly two divisors: 1 and 7, making it a prime number.
Input: n = 25
Output: false
Explanation: 25 has more than two divisors: 1, 5, and 25, so it is not a prime number.
Input: n = 1
Output: false
Explanation: 1 has only one divisor (1 itself), which is not sufficient for it to be considered prime.
Constraints:
1 ≤ n ≤ 109



// brute force
class Solution{
    public:
    bool isPrime(int n){
        if(n==1) return false;
        for(int i=2; i*i<=n; i++){
            if(n%i==0) return false;
        }
        return true;
    }
};


// efficient solution
class Solution {
    public:
      bool isPrime(int n) {
          if(n==1) return false;
          for(int i=2; i*i<=n; i++){
              if(n%i==0){
                  return false;
              }
          }
          return true;
      }
};


// optimal solution
class Solution {
    public:
      bool isPrime(int n) {
          if(n==1) return false;
          for(int i=2; i*i<=n; i++){
              if(n%i==0){
                  return false;
              }
          }
          return true;
      }
  };