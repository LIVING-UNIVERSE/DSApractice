// Given an array, jobs[] where each job[i] has a jobid, deadline and profit associated with it. Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit associated with a job if and only if the job is completed by its deadline.

// Find the number of jobs done and the maximum profit.

// Note: jobs will be given in the form (jobid, deadline, profit) associated with that job. Deadline of the job is the time on or before which job needs to be completed to earn the profit.

// Examples :

// Input: jobs[] = [(1,4,20), (2,1,1), (3,1,40), (4,1,30)]
// Output: [2, 60]
// Explanation: job1 and job3 can be done with maximum profit of 60 (20+40).
// Input: jobs[] = [(1,2,100), (2,1,19), (3,2,27), (4,1,25), (5,1,15)]
// Output: [2, 127]
// Explanation: 2 jobs can be done with maximum profit of 127 (100+27).
// Constraints:
// 1 <=  jobs.size <= 105
// 1 <= deadline, jobid <= jobs.size
// 1 <= profit <= 500




struct Job
{
    int id;	 // Job Id
    int deadline; // Deadline of job
    int profit; // Profit if job is over before or on deadline
};


class Solution {
  public:
    // Function to find the maximum profit and the number of jobs done.
    static bool myComp(Job a,Job b){
        return a.profit>b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) {
        sort(arr,arr+n,myComp);
        int count=0,res=0,index=INT_MIN;
        for(int i=0; i<n; i++){
            index=max(index,arr[i].deadline);
        }
        vector<int> slot(index+1,-1);
        for(int i=0; i<n; i++){
            int j=arr[i].deadline;
            for(int j=arr[i].deadline; j--; j>0){
                if(slot[j]==-1){
                    slot[j]=arr[i].id;
                    count++;
                    res+=arr[i].profit;
                    break;
                }
            }
        }
        return {count,res};
            
    }
};




// Huffman Encoding
// Difficulty: HardAccuracy: 32.4%Submissions: 38K+Points: 8
// Given a string S of distinct character of size N and their corresponding frequency f[ ] i.e. character S[i] has f[i] frequency. Your task is to build the Huffman tree print all the huffman codes in preorder traversal of the tree.
// Note: While merging if two nodes have the same value, then the node which occurs at first will be taken on the left of Binary Tree and the other one to the right, otherwise Node with less value will be taken on the left of the subtree and other one to the right.

// Example 1:

// S = "abcdef"
// f[] = {5, 9, 12, 13, 16, 45}
// Output: 
// 0 100 101 1100 1101 111
// Explanation:
// Steps to print codes from Huffman Tree
// HuffmanCodes will be:
// f : 0
// c : 100
// d : 101
// a : 1100
// b : 1101
// e : 111
// Hence printing them in the PreOrder of Binary 
// Tree.
// Your Task:
// You don't need to read or print anything. Your task is to complete the function huffmanCodes() which takes the given string S, frequency array f[ ] and number of characters N as input parameters and returns a vector of strings containing all huffman codes in order of preorder traversal of the tree.

// Expected Time complexity: O(N * LogN) 
// Expected Space complexity: O(N) 

// Constraints:
// 1 ≤ N ≤ 26

// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
// #include<unordered_set>
// #include<unordered_map>
using namespace std; 

struct Node{
    char c;
    int f;
    Node *right;
    Node *left;
    Node(int freq, char x){
        c=x;
        f=freq;
        left=right=NULL;
    }
};

struct myComp {
    bool operator()(Node* a, Node* b) {
        return a->f > b->f;
    }
};

void printHuffman(Node *root ,string str){
    if(root== NULL) return;
    if(root->c !='$') cout<<root->c<<"  "<<str<<endl;
    printHuffman(root->left,str+'0');
    printHuffman(root->right,str+'1');
}

int main(){
    string S = "abcdef";
    int f[6] = {5, 9, 12, 13, 16, 45};
    int n=6;
    priority_queue<Node*,vector<Node*>, myComp> pq; 
    for(int i=0; i<n; i++){
        Node* node =  new Node(f[i],S[i]);
        pq.push(node);
    }
    Node* root;
    while(pq.size()>1){
        Node* ln= pq.top(); pq.pop();
        Node* rn= pq.top(); pq.pop();
        root = new Node(ln->f+rn->f, '$');
        root->left=ln;
        root->right=rn;
        pq.push(root);
    }

    string str="";
    printHuffman(root,str);

    return 0;
}




// At a lemonade stand, each lemonade costs $5. Customers are standing in a queue to buy from you and order one at a time (in the order specified by bills). Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill. You must provide the correct change to each customer so that the net transaction is that the customer pays $5.

// Note that you do not have any change in hand at first.

// Given an integer array bills where bills[i] is the bill the ith customer pays, return true if you can provide every customer with the correct change, or false otherwise.

 

// Example 1:

// Input: bills = [5,5,5,10,20]
// Output: true
// Explanation: 
// From the first 3 customers, we collect three $5 bills in order.
// From the fourth customer, we collect a $10 bill and give back a $5.
// From the fifth customer, we give a $10 bill and a $5 bill.
// Since all customers got correct change, we output true.
// Example 2:

// Input: bills = [5,5,10,10,20]
// Output: false
// Explanation: 
// From the first two customers in order, we collect two $5 bills.
// For the next two customers in order, we collect a $10 bill and give back a $5 bill.
// For the last customer, we can not give the change of $15 back because we only have two $10 bills.
// Since not every customer received the correct change, the answer is false.
 

// Constraints:

// 1 <= bills.length <= 105
// bills[i] is either 5, 10, or 20.


class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fc=0,tc=0,twc=0;
        for(auto x: bills){
            if(x==5){
                fc++;
            }
            else if(x==10){
                if(fc==0) {return false;}
                else{
                    tc++;fc--;
                }
            }
            else{
                if(tc!=0){
                    if(fc==0){return false;}
                    else{
                        tc--;fc--;
                    }
                }
                else{
                    if(fc<3){ return false;}
                    else{
                        fc=fc-3;
                    }
                }
            }
        }
        return true;
    }
};

/*
Minimum Platforms
Difficulty: MediumAccuracy: 26.84%Submissions: 477K+Points: 4
Given arrival and departure times of all trains that reach a railway station. Find the minimum number of platforms required for the railway station so that no train is kept waiting.
Consider that all the trains arrive on the same day and leave on the same day. Arrival and departure time can never be the same for a train but we can have arrival time of one train equal to departure time of the other. At any given instance of time, same platform can not be used for both departure of a train and arrival of another train. In such cases, we need different platforms.

Note: Time intervals are in the 24-hour format(HHMM) , where the first two characters represent hour (between 00 to 23 ) and the last two characters represent minutes (this will be <= 59 and >= 0).

Examples:

Input: arr[] = [0900, 0940, 0950, 1100, 1500, 1800], 
            dep[] = [0910, 1200, 1120, 1130, 1900, 2000]
Output: 3
Explanation: There are three trains during the time 0940 to 1200. So we need minimum 3 platforms.
Input: arr[] = [0900, 1235, 1100], 
            dep[] = [1000, 1240, 1200]
Output: 1
Explanation: All train times are mutually exlusive. So we need only one platform
Input: arr[] = [1000, 0935, 1100], 
            dep[] = [1200, 1240, 1130]
Output: 3
Explanation: All 3 trains have to be their from 11:00 to 11:30
Expected Time Complexity: O(nLogn)
Expected Auxiliary Space: O(n)

Constraints:

1≤ number of trains ≤ 50000
0000 ≤ arr[i] ≤ dep[i] ≤ 2359


*/

//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        int ap=0,dp=0;
        int plat=1,count=0;
        while(ap<n && dp<n){
            if(arr[ap]<=dep[dp]){
                count++;
                ap++;
            }
            else{
                count--;
                dp++;
            }
            plat=max(plat,count);
        }
        return plat;
    }
};


//{ Driver Code Starts.
//  Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        vector<int> dep(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int j = 0; j < n; j++) {
            cin >> dep[j];
        }
        Solution ob;
        cout << ob.findPlatform(arr, dep) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends





//678. Valid Parenthesis String
Solved
Medium
Topics
Companies
Hint
Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid
The following rules define a valid string:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "(*)"
Output: true
Example 3:

Input: s = "(*))"
Output: true
 

Constraints:

1 <= s.length <= 100
s[i] is '(', ')' or '*'.
*/


class Solution {
public:
    bool checkValidString(string s) {
        stack<char> so;
        stack<char> ss;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='('){
                so.push('(');
            }
            else if(s[i]=='*'){
                ss.push('*');
            }
            else{
                if(so.empty() && ss.empty()){
                    return false;
                }
                else if(so.empty()){
                    ss.pop();
                }
                else{
                    so.pop();
                }
            }
        }
        if(ss.size()==so.size() || so.empty()){
            return true;
        }else{
            return false;
        }
    }
};


class Solution {
public:
    bool checkValidString(string s) {
        int mn = 0, mx = 0;
        
        for (char c : s) {
            if (c == '(') {
                // Treat `(` as increasing both min and max open parentheses needed.
                mn++;
                mx++;
            } else if (c == '*') {
                // `*` could be `(`, `)`, or an empty string.
                if (mn > 0) mn--;  // Decrease mn as if `*` could close an open parenthesis
                mx++;               // Increase max, as `*` could also be an open parenthesis
            } else {
                // For `)`, attempt to close an open parenthesis.
                if (mn > 0) mn--;
                mx--;
            }
            
            // If `mx` is negative, too many `)` have been encountered.
            if (mx < 0) return false;
        }
        
        // Return true if all open parentheses could be closed.
        return mn == 0;
    }
};


// valid parenthesis with DP 

/*




            // O(n*n) time and O(n*n) space DP solution will come after DP





*/



//55. Jump Game
Solved
Medium
Topics
Companies
Amazon
Facebook
Apple
DoorDash
Flipkart
You are given an integer array nums. You are initially positioned at the array''s first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 

Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 105



// solution 1 t:O(n) s:O(1)
class Solution {
    public:
        bool canJump(vector<int>& arr) {
            int n=arr.size();
            if(n==1) return true;
            int maxIndex=arr[0];
            for(int i=1; i<n; i++){
                if(i>maxIndex) return false;
                if(maxIndex>=n-1) return true;
                if(i+arr[i]>maxIndex){
                    maxIndex=i+arr[i];
                }
            }
            return true;
        }
};


// another solution t:O(n) s:O(1)
class Solution {
    public:
        bool canJump(vector<int>& arr) {
            int n=arr.size();
            if(n==1) return true;
            int maxJump=-1;
            for(int i=0; i<n; i++){
                if(arr[i]>=maxJump){
                    maxJump=arr[i];
                }
                else{
                    maxJump--;
                }
                if(i<n-1 && maxJump==0) return false;
            }
            return true;
        }
};


//57. Insert Interval
Solved
Medium
Topics
Companies
Hint
Google
LinkedIn
Amazon
Facebook
Robinhood
You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

Note that you dont need to modify intervals in-place. You can make a new array and return it.

 

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
 

Constraints:

0 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 105
intervals is sorted by starti in ascending order.
newInterval.length == 2
0 <= start <= end <= 105


// solution (my own)
// t:O(n) sp:O(n) as required to return the ans;
class Solution {
    public:
        vector<vector<int>> insert(vector<vector<int>>& arr, vector<int>& interval) {
            arr.push_back(interval);
            int n=arr.size();
            for(int i=n-1;i>=0;i--){
                if(i>=1 && arr[i][0]<arr[i-1][0]){
                    swap(arr[i],arr[i-1]);
                }
            }
            vector<vector<int>> res;
            int begin=arr[0][0],end=arr[0][1];
            for(int i=1;i<n;i++){
                if(arr[i][0]>end){
                    res.push_back({begin,end});
                    begin=arr[i][0],end=arr[i][1];
                }
                else{
                    end=max(end,arr[i][1]);
                }
            }
            res.push_back({begin,end});
            return res;
        }
};


// better solution(given by striver)
class Solution {
    public:
        vector<vector<int>> insert(vector<vector<int>>& arr, vector<int>& interval) {
            int n=arr.size();
            vector<vector<int>> res;
            int i=0;
            while(i<n){
                if(arr[i][1]<interval[0]){
                    res.push_back(arr[i]);i++;
                }
                else{
                    break;
                }
            }
            vector<int> newInterval({interval[0],interval[1]});
            while(i<n && arr[i][0]<=interval[1]){
                newInterval[0]=min(newInterval[0],arr[i][0]);
                newInterval[1]=max(newInterval[1],arr[i][1]);
                i++;
            }
            res.push_back(newInterval);
            while(i<n){
                res.push_back(arr[i]);i++;
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



// solution
// t:O(nlogn) sp:O(n)just to return the ans
class Solution {
    private:
        static bool cmp(vector<int>&a ,vector<int> &b){
            return (a[0]<b[0]);
        }
    public:
        vector<vector<int>> merge(vector<vector<int>>& arr) {
            int n=arr.size();
            vector<vector<int>> ans;
            sort(arr.begin(),arr.end(),cmp);
            vector<int> newInterval={arr[0][0],arr[0][1]};
            for(int i=1;i<n;i++){
                if(arr[i][0]<=newInterval[1]){
                    newInterval[0]=min(newInterval[0],arr[i][0]);
                    newInterval[1]=max(newInterval[1],arr[i][1]);
                }
                else{
                    ans.push_back(newInterval);
                    newInterval[0]=arr[i][0];
                    newInterval[1]=arr[i][1];
                }
            }
            ans.push_back(newInterval);
            return ans;
        }
};


//435. Non-overlapping Intervals
Solved
Medium
Topics
Companies
Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Note that intervals which only touch at a point are non-overlapping. For example, [1, 2] and [2, 3] are non-overlapping.

 

Example 1:

Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
Example 2:

Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.
Example 3:

Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
 

Constraints:

1 <= intervals.length <= 105
intervals[i].length == 2
-5 * 104 <= starti < endi <= 5 * 104


// solution
// t:O(nlogn) sp:O(1)
class Solution {
    private:
        static bool cmp(vector<int> &a, vector<int> &b){
            return a[1]<b[1];
        }
    public:
        int eraseOverlapIntervals(vector<vector<int>>& arr) {
            int n=arr.size();
            int count=0;
            sort(arr.begin(),arr.end(),cmp);
            int end=arr[0][1];
            for(int i=1;i<n;i++){
                if(arr[i][0] < end){
                    count++;
                }
                else{
                    end=arr[i][1];
                }
            }
            return count;
        }
}; 



//Shortest Job first
Difficulty: MediumAccuracy: 68.79%Submissions: 29K+Points: 4Average Time: 30m
Geek is a software engineer. He is assigned with the task of calculating average waiting time of all the processes by following shortest job first policy.

The shortest job first (SJF) or shortest job next, is a scheduling policy that selects the waiting process with the smallest execution time to execute next.

Given an array of integers bt of size n. Array bt denotes the burst time of each process. Calculate the average waiting time of all the processes and return the nearest integer which is smaller or equal to the output.

Note: Consider all process are available at time 0.

Example 1:

Input:
n = 5
bt = [4,3,7,1,2]
Output: 4
Explanation: After sorting burst times by shortest job policy, calculated average waiting time is 4.
Example 2:

Input:
n = 4
arr = [1,2,3,4]
Output: 2
Explanation: After sorting burst times by shortest job policy, calculated average waiting time is 2.
Your Task:
You dont need to read input or print anything. Your task is to complete the function solve() which takes bt[] as input parameter and returns the average waiting time of all the processes.

Expected Time Complexity: O(nlog(n))
Expected Auxiliary Space: O(1)

Constraints:
1 <= n <= 105
1 <= arr[i] <= 105

//solution

class Solution {
    public:
      long long solve(vector<int>& arr) {
          int n=arr.size();
          long long sum=0;
          sort(arr.begin(),arr.end());
          long long prev=0;
          for(int i=0;i<n;i++){
              sum= (long long)(sum+prev);
              prev= (long long)(prev+arr[i]);
          }
          return sum/n;
      }
};



//45. Jump Game II
Solved
Medium
Topics
Companies
Amazon
Apple
Bloomberg
Google
DoorDash
You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2
 

Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 1000
Its guaranteed that you can reach nums[n - 1].



// brute force
// t:O(n*n) sp:O(n)
class Solution {
private:
    int f(int ind,vector<int> &arr){
        if(ind>=arr.size()-1) return 0;
        int jump=1e8;
        for(int i=1;i<=arr[ind];i++){
            jump=min(jump,f(ind+i,arr));
        }
        return jump+1;
    }
public:
    // brute force
    int jump(vector<int>& arr) {
       return f(0,arr);
    }
};

// you can further optimize it using dp to O(n*n) time complexity

// better solution
// t:O(n) sp:O(1)
class Solution {
    public:
        int jump(vector<int>& arr) {
            // brute force
            int n=arr.size();
            int count=0;
            int i=0;
            while(i<n){
                if(i==n-1) return count;
                if(i+arr[i]>=n-1) return count+1;
                int maxe=-1,ind=i;
                for(int j=1;j<=arr[i];j++){
                    int val=i+j;
                    if(val+arr[val]>=maxe){
                        maxe=val+arr[val];ind=val;
                    }
                }
                i=ind;count++;
            }
            return count;
        }
};



// optimal solution
class Solution {
    public:
        int jump(vector<int>& arr) {
            int n=arr.size();
            int maxIndex=arr[0];
            int maxe=arr[0];
            int count=0;
            for(int i=1;i<n;i++){
                if(maxIndex>=n-1) return count+1;
                maxe=max(maxe,i+arr[i]);
                if(i==maxIndex){
                    count++;
                    maxIndex=maxe;
                }
            }
            return count;
        }
};