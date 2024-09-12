//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    class meetings{
    public:
        int start;
        int end;
        int pos;
    };
     static bool comparator(meetings meet1, meetings meet2){
        if (meet1.end < meet2.end) return true;
        else if (meet1.end > meet2.end) return false;
        else return meet1.pos < meet2.pos;
    }
    int maxMeetings(int n, int start[], int end[]) {
         meetings arr[n];
         vector<int> order;
        for(int i=0;i<n;i++){
            arr[i].start = start[i];
            arr[i].end = end[i];
            arr[i].pos = i+1;
            }
            sort(arr,arr+n,comparator);
            int count=1;
            order.push_back(arr[0].pos);
            int freeTime=arr[0].end;
            for(int i=1;i<n;i++){
                if(arr[i].start>freeTime){
                    count++;
                    freeTime = arr[i].end;
                    order.push_back(arr[i].pos);
                }
            }
            return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(n, start, end);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends