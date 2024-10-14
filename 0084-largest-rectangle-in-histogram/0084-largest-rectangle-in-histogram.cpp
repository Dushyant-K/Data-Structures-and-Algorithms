class Solution {
public:
  vector<int> PSE(vector<int> arr){
        vector<int> pse;
        stack<int> st;
        for(int i=0;i<arr.size();i++){
            while(!(st.empty())&&(arr[st.top()]>=arr[i])){
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
    
    vector<int> NSE(vector<int> arr){
        vector<int> nse(arr.size());
        stack<int> st;
        for(int i=arr.size()-1;i>=0;i--){
            while(!(st.empty())&&(arr[st.top()]>=arr[i])){
                st.pop();
            }
            if(st.empty()){
                nse[i] = arr.size();
            }
            else{
                nse[i] = st.top();
            }
            st.push(i);
        }
        return nse;
    }
    int largestRectangleArea(vector<int>& heights) {

        //Approach-1
        int n=heights.size();
        vector<int> nse = NSE(heights);
        vector<int> pse = PSE(heights);
        int maxArea=0;
        for(int i=0;i<n;i++){
            maxArea = max(maxArea,heights[i]*(nse[i]-pse[i]-1));
        }
        return maxArea;

        // int n = heights.size();
        // stack<int> st;
        // int maxi = 0;
        // for(int i=0;i<n;i++){
        //     while(!(st.empty())&&(heights[st.top()]>=heights[i])){
        //         int element = heights[st.top()];
        //         st.pop();
        //         int nse = i;
        //         int pse = st.empty()?-1:st.top();
        //         int area = element*(nse-pse-1);
        //         maxi = max(maxi,area);
        //     }
        //     st.push(i);
        // }
        // while(!(st.empty())){
        //         int nse = n;
        //         int element = heights[st.top()];
        //         st.pop();
        //         int pse = st.empty()?-1:st.top();
        //         int area = element*(nse-pse-1);
        //         maxi = max(maxi,area);
        //     }
        //     return maxi;
    }
};