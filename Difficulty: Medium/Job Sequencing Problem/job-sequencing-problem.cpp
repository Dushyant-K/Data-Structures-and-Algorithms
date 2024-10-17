//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    static bool comparator(Job job1, Job job2){
        if(job1.profit>job2.profit)return true;
        else if(job1.profit<job2.profit)return false;
        else return(job1.id<job2.id);
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // Approach-1
        sort(arr,arr+n,comparator);
        int maxDeadline=0;
        for(int i=0;i<n;i++){
            maxDeadline = max(maxDeadline,arr[i].dead);
        }
        vector<int> slot(maxDeadline+1,-1);
        slot[0]=0;
        int count=0;
        int totalProfit=0;
        for(int i=0;i<n;i++){
            for(int j=arr[i].dead;j>=0;j--){
                if(slot[j]==-1){
                    count++;
                    totalProfit+=arr[i].profit;
                    slot[j]=arr[i].id;
                    break;
                }
            }
        }
        return {count,totalProfit};
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends