//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   //Approach-1
   class meetings{
       public:
       int start;
       int end;
       int pos;
   };
   static bool comparator(meetings meet1, meetings meet2){
       if(meet1.end<meet2.end)return true;
       else if(meet1.end>meet2.end)return false;
       else return meet1.pos<meet2.pos;
   }
    int maxMeetings(vector<int> start, vector<int> end) {
        // Approach-1
        int n = start.size();
        meetings arr[n];
        for(int i=0;i<n;i++){
            arr[i].start = start[i];
            arr[i].end  = end[i];
            arr[i].pos = i+1;
        }
        vector<int> order;
        sort(arr,arr+n, comparator);
        int freeTime = arr[0].end;
        order.push_back(arr[0].pos);
        int count=1;
        for(int i=1;i<n;i++){
            if(freeTime<arr[i].start){
                count++;
                order.push_back(arr[i].pos);
                freeTime=arr[i].end;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> start;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            start.push_back(num);
        }

        vector<int> end;
        getline(cin, input);
        stringstream s22(input);
        while (s22 >> num) {
            end.push_back(num);
        }

        Solution ob;
        int ans = ob.maxMeetings(start, end);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends