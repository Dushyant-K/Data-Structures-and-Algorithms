class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        int left[n];
        int right[n];
        int count=2;
        left[0]=1;
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                left[i]=count;
                 count++;
            }
            else{
                left[i]=1;
                count=2;
            }
        }
        right[n-1]=1;
        count=2;
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                right[i]=count;
                 count++;
            }
            else{
                right[i]=1;
                count=2;
            }
        }
        int candies=0;
        for(int i=0;i<n;i++){
            candies+= max(left[i],right[i]);
        }
        return candies;
    }
};