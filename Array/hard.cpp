118. Pascals Triangle
Solved
Easy
Topics
Companies
Amazon
Apple
Microsoft
Goldman Sachs
Snapchat
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


 

Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Example 2:

Input: numRows = 1
Output: [[1]]
 

Constraints:

1 <= numRows <= 30


// optimal solution
class Solution {
private:
    vector<int> f(int ind){
        int r=ind-1,res=1;
        vector<int> v;
        v.push_back(1);
        for(int i=1; i<ind; i++){
            res*=(r-i+1);
            res=res/i;
            v.push_back(res);
        }
        return v;
    }
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> res;
        for(int i=1; i<=n; i++){
            res.push_back(f(i));
        }
        return res;
    }
};



//56. Merge Intervals
Solved
Medium
Topics
Companies
Facebook
Amazon
Google
Bloomberg
Salesforce
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 

Constraints:

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104



// optimal solution
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        int begin=arr[0][0],end=arr[0][1];
        for(int i=1; i<n; i++){
            if(arr[i][0]>end){
                vector<int> temp;
                temp.push_back(begin);
                temp.push_back(end);
                ans.push_back(temp);
                begin=arr[i][0];
                end=arr[i][1];
            }
            else{
                end=max(end,arr[i][1]);
            }
        }
        vector<int> temp;
        temp.push_back(begin);
        temp.push_back(end);
        ans.push_back(temp);
        return ans;
    }
};

// further optimal solution
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            if(ans.empty() || (arr[i][0]>ans.back()[1])){
                ans.push_back({arr[i][0],arr[i][1]});
            }
            else{
                ans.back()[1]=max(ans.back()[1],arr[i][1]);
            }
        }
        return ans;
    }
};





//Merge Without Extra Space
Difficulty: MediumAccuracy: 32.01%Submissions: 285K+Points: 4Average Time: 20m
Given two sorted arrays a[] and b[] of size n and m respectively, the task is to merge them in sorted order without using any extra space. Modify a[] so that it contains the first n elements and modify b[] so that it contains the last m elements.

Examples:

Input: a[] = [2, 4, 7, 10], b[] = [2, 3]
Output:
2 2 3 4
7 10
Explanation: After merging the two non-decreasing arrays, we get, 2 2 3 4 7 10
Input: a[] = [1, 5, 9, 10, 15, 20], b[] = [2, 3, 8, 13]
Output:
1 2 3 5 8 9
10 13 15 20
Explanation: After merging two sorted arrays we get 1 2 3 5 8 9 10 13 15 20.
Input: a[] = [0, 1], b[] = [2, 3]
Output:
0 1
2 3
Explanation: After merging two sorted arrays we get 0 1 2 3.
Constraints:
1 <= a.size(), b.size() <= 105
0 <= a[i], b[i] <= 107


// optimal solution 1
class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        int n=a.size(),m=b.size();
        int i=n-1,j=0;
        while(i>=0 && j<m){
            if(a[i]>b[j]){
                swap(a[i],b[j]);
                i--;j++;
            }
            else{
                break;
            }
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
    }
};


// optimal approach 2(gap method using shell sort)
class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        int n=a.size(),m=b.size();
        int gap=(m+n+1)/2;
        while(gap>0){
            int left=0,right=gap;
            while(right<m+n){
                if(left<n && right>=n){
                    if(a[left]>b[right-n]){
                        swap(a[left],b[right-n]);
                    }
                }
                else if(left<n && right<n){
                    if(a[left]>a[right]){
                        swap(a[left],a[right]);
                    }
                }
                else{
                    if(b[left-n]>b[right-n]){
                        swap(b[left-n],b[right-n]);
                    }
                }
                left++;right++;
            }
            if(gap==1) {break;}
            gap=(gap+1)/2;
        }
    }
};




//Subarray with given XOR
Programming
Hashing
medium
52.2% Success

959

20

Bookmark
Asked In:
Problem Description
 
 

Given an array of integers A and an integer B.

Find the total number of subarrays having bitwise XOR of all elements equals to B.



Problem Constraints
1 <= length of the array <= 105

1 <= A[i], B <= 109



Input Format
The first argument given is the integer array A.

The second argument given is integer B.



Output Format
Return the total number of subarrays having bitwise XOR equals to B.



Example Input
Input 1:

 A = [4, 2, 2, 6, 4]
 B = 6
Input 2:

 A = [5, 6, 7, 8, 9]
 B = 5


Example Output
Output 1:

 4
Output 2:

 2


Example Explanation
Explanation 1:

 The subarrays having XOR of their elements as 6 are:
 [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], [6]
Explanation 2:

 The subarrays having XOR of their elements as 5 are [5] and [5, 6, 7, 8, 9]


 // brute force solution
    int Solution::solve(vector<int> &A, int B) {
        int n=A.size();
        int count=0;
        for(int i=0; i<n; i++){
            int xor_val=0;
            for(int j=i; j<n; j++){
                xor_val^=A[j];
                if(xor_val==B){
                    count++;
                }
            }
        }
        return count;


// optimal solution
int Solution::solve(vector<int> &arr, int k) {
    int n=arr.size();
    unordered_map<int,int> m;
    int count=0,res=0;
    for(int i=0; i<n; i++){
        res=res^arr[i];
        if(res==k) count++;
        if(m.find(res^k)!=m.end()){
            count+=m[res^k];
        }
        m[res]++;
    }
    return count;
}





//229. Majority Element II
Solved
Medium
Topics
Companies
Hint
Amazon
Microsoft
Adobe
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

 

Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]
 

Constraints:

1 <= nums.length <= 5 * 104
-109 <= nums[i] <= 109
 

Follow up: Could you solve the problem in linear time and in O(1) space?



// brute force t:O(n^2) s:O(1)
class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        // brute force
        int n=arr.size();
        vector<int> ans;
        for(int i=0;i<n; i++){
            int count=0;
            for(int j=i; j<n ;j++){
                if(arr[j]==arr[i]) count++;
            }
            if(count>(n/3)){
                if(ans.size()==0) ans.push_back(arr[i]);
                else{
                    if(arr[i]!=ans[0]) ans.push_back(arr[i]);
                    if(ans.size()==2) break;
                }
            }
        }
        return ans;
    }
};



// better solution t:O(n) s:O(n)
class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int> m;
        for(int i=0; i<n ; i++){
            m[arr[i]]++;
        }
        vector<int> v;
        for(auto x: m){
            if(x.second>(n/3)) v.push_back(x.first);
        }
        return v;
    }
};


// optimal solution t:O(n) s:O(1) moore's voting algorithm
class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        // moore's voting algorithm for (n/3).
        int n=arr.size();
        int ele1,ele2,count1=0,count2=0;
        for(int i=0; i<n; i++){
            if(count1==0 && arr[i]!=ele2){
                ele1=arr[i];
                count1=1;
            }
            else if(count2==0 && arr[i]!=ele1){
                ele2=arr[i];
                count2=1;
            }
            else if(arr[i]==ele1){
                count1++;
            }
            else if(arr[i]==ele2){
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }
        vector<int> v;
        count1=0;count2=0;
        for(int i=0; i<n; i++){
            if(arr[i]==ele1) count1++;
            if(arr[i]==ele2) count2++;
        }
        if(count1> n/3) v.push_back(ele1);
        if(count2> n/3 && ele2!=ele1) v.push_back(ele2);
        return v;
    }
};





//Missing And Repeating
Difficulty: EasyAccuracy: 24.83%Submissions: 558K+Points: 2Average Time: 30m
Given an unsorted array arr of positive integers. One number a from the set [1, 2,....,n] is missing and one number b occurs twice in the array. Find numbers a and b.

Note: The test cases are generated such that there always exists one missing and one repeating number within the range [1,n].

Examples:

Input: arr[] = [2, 2]
Output: [2, 1]
Explanation: Repeating number is 2 and smallest positive missing number is 1.
Input: arr[] = [1, 3, 3] 
Output: [3, 2]
Explanation: Repeating number is 3 and smallest positive missing number is 2.
Input: arr[] = [4, 3, 6, 2, 1, 1]
Output: [1, 5]
Explanation: Repeating number is 1 and the missing number is 5.
Constraints:
2 ≤ arr.size() ≤ 106
1 ≤ arr[i] ≤ arr.size()


// brute force t:O(n^2)  s:O(1)
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // brute force
        int n=arr.size();
        int A,B;
        for(int i=1; i<=n; i++){
            int a=-1,count=0;
            for(int j=0;j<n; j++){
                if(arr[j]==i){
                    a=i;count++;
                }
            }
            if(a==-1) A=i;
            if(count==2) B=i;
        }
        return {B,A};
    }
};


// better solution t:O(n) s:O(n)
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n=arr.size();
        vector<int> v(n+1,0);
        for(int i=0; i<n; i++){
            v[arr[i]]++;
        }
        int a,b;
        for(int i=1; i<v.size(); i++){
            if(v[i]==0) a=i;
            if(v[i]==2) b=i;
        }
        return {b,a};
    }
};



// optimal solution I t:O(n) s:O(1)  using mathemaical formula
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // optimal solution 
        long long n=arr.size();
        long long ns=n*(n+1)/2;
        long long nss=n*(n+1)*(2*n+1)/6;
        long long ss=0,s=0;
        for(int i=0; i<n; i++){
            s+=arr[i];
            ss+=(long long)arr[i]*(long long)arr[i];
        }
        long long x=ns-s,y=nss-ss;
        long long a= (x+y/x)/2;
        long long b=a-x;
        return {(int)b,(int)a};
    }
};



// optimal solution II t:O(n) s:O(1)  using xor
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // optimal solution 2 (using XOR)
        int n=arr.size();
        int c=0;
        for(int i=0; i<n; i++){
            c^=arr[i];
            c^=(i+1);
        }
        int bitCount=0;
        while((c&(1<<bitCount))==0){
            bitCount++;
        }
        int one=0,zero=0;
        for(int i=0; i<n; i++){
            if((arr[i]&(1<<bitCount))==0){
                zero^=arr[i];
            }
            else{
                one^=arr[i];
            }
        }
        for(int i=1; i<=n; i++){
            if((i&(1<<bitCount))==0){
                zero^=i;
            }
            else{
                one^=i;
            }
        }
        for(int i=0; i<n ;i++){
            if(arr[i]==zero){
                return {zero,one};
            }
            else if(arr[i]==one){
                return {one,zero};
            }
        }
    }
};