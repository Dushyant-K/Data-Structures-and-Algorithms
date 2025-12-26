class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        //Approach-1(Using Greedy Algorithm with two pointer)
        int n = apple.size();
        int m = capacity.size();

        sort(capacity.begin(),capacity.end(),greater<int>());

        int i=0;
        int j=0;
        while(i<n){
            if(capacity[j]>=apple[i]){
                capacity[j]=capacity[j]-apple[i];
                i++;
            }else{
                apple[i]=apple[i]-capacity[j];
                j++;
            }
        }

        return j+1;
    }
};