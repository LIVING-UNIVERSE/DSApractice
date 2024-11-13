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




/*
678. Valid Parenthesis String
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








