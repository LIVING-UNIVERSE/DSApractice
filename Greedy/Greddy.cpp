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



/*
struct Job
{
    int id;	 // Job Id
    int deadline; // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
*/

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