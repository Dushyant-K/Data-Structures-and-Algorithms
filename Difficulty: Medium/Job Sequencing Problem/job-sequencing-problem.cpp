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
    // Comparator function to sort jobs according to profit in descending order
    static bool comparator(Job job1, Job job2) {
        return job1.profit > job2.profit;
    }

    // Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // Sort the jobs based on their profits in descending order
        sort(arr, arr + n, comparator);

        // Find the maximum deadline
        int maxDeadline = 0;
        for (int i = 0; i < n; i++) {
            maxDeadline = max(maxDeadline, arr[i].dead);
        }

        // Create an array to keep track of free time slots
        vector<int> slot(maxDeadline + 1, -1);

        int count = 0; // To store the number of jobs done
        int totalProfit = 0; // To store the total profit

        // Iterate through all jobs
        for (int i = 0; i < n; i++) {
            // Find a free slot for this job (starting from the last possible slot)
            for (int j = arr[i].dead; j > 0; j--) {
                if (slot[j] == -1) {
                    slot[j] = arr[i].id; // Assign job id to this slot
                    count++;
                    totalProfit += arr[i].profit;
                    break; // Move to the next job
                }
            }
        }

        // Return the total number of jobs done and the total profit
        return {count, totalProfit};
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