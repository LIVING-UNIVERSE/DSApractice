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

