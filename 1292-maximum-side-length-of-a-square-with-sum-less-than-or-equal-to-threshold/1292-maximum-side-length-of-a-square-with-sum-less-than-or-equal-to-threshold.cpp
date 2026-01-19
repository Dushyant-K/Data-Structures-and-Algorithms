class Solution {
public:
    bool isPossible(vector<vector<int>>& mat, int sideLength, int threshold){
        int n = mat.size();
        int m = mat[0].size();

        int left=-1;
        int right = sideLength-1;
        int top = 0;

        while(right<m){

            int sum=0;
            int curr=top;
            while(curr<=top+sideLength-1){
                sum+=mat[curr][right];
                if(left!=-1)sum-=mat[curr][left];
                curr++;
            }
            if(sum<=threshold)return true;
            left++;
            right++;
            if(right==m){
                left=-1;
                right=sideLength-1;
                top++;
                if(top>n-sideLength)break;
            }
        }

        return false;
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        //Approach-1(Using Binary Search and Prefix Sum)
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> prefixSum(n,vector<int>(m));

        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=0;j<m;j++){
                sum+=mat[i][j];
                prefixSum[i][j]=sum;
            }
        }

        int low=1;
        int high = min(n,m);
        int ans = 0;
        while(low<=high){
            int mid = (low+high)/2;

            if(isPossible(prefixSum,mid,threshold)){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }

        return ans;
    }
};