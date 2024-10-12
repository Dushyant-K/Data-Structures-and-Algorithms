class Solution {
public:
    vector<int> NSE(vector<int> arr){
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!(st.empty())&&(arr[st.top()]>=arr[i])){
                st.pop();
            }
            if(st.empty()){
                nse[i] = n;
            }
            else{
                nse[i] = st.top();
            }
            st.push(i);
        }
        return nse;
    }

    vector<int> PSE(vector<int> arr){
        vector<int> pse;
        stack<int> st;
        int n = arr.size();
        for(int i=0;i<=n-1;i++){
            while(!(st.empty())&&(arr[st.top()]>arr[i])){
                st.pop();
            }
            if(st.empty()){
                pse.push_back(-1);
            }
            else{
                pse.push_back(st.top());
            }
            st.push(i);
        }
        return pse;
    }
    int sumSubarrayMins(vector<int>& arr) {
        //Approach-1
        // int total =0;
        // int n = arr.size();
        // for(int i=0;i<n;i++){
        //     int mini = arr[i];
        //     for(int j=i;j<n;j++){
        //         mini = min(mini,arr[j]);
        //         total+=mini%mod;
        //     }
        // }
        // return total;

        //Approach-2
        int n = arr.size();
        vector<int> pse = PSE(arr);
        vector<int> nse = NSE(arr);
        int total =0;
        int mod =(int)(1e9+7);
        for(int i=0;i<n;i++){
            int left = i - pse[i];
            int right = nse[i] - i;
            total+=((left*right*1LL%mod)*arr[i]%mod)%mod;
        }
        return total;
    }
};