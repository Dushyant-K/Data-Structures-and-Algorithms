class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxi = 0;
        for(int i=0;i<n;i++){
            while(!(st.empty())&&(heights[st.top()]>=heights[i])){
                int element = heights[st.top()];
                st.pop();
                int nse = i;
                int pse = st.empty()?-1:st.top();
                int area = element*(nse-pse-1);
                maxi = max(maxi,area);
            }
            st.push(i);
        }
        while(!(st.empty())){
                int nse = n;
                int element = heights[st.top()];
                st.pop();
                int pse = st.empty()?-1:st.top();
                int area = element*(nse-pse-1);
                maxi = max(maxi,area);
            }
            return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if (n == 0) return 0; // Edge case: empty matrix
        int m = matrix[0].size();
        
        // Convert char matrix to a prefix sum matrix of integers
        vector<vector<int>> prefixSum(n, vector<int>(m, 0));
        for (int j = 0; j < m; j++) {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                if (matrix[i][j] == '1') {
                    sum++;
                } else {
                    sum = 0;
                }
                prefixSum[i][j] = sum;
            }
        }
        
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, largestRectangleArea(prefixSum[i]));
        }
        return maxi;
    }
};