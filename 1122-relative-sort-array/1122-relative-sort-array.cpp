class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        //Approach-1
        int n1=arr1.size();
        int n2=arr2.size();
        vector<int> ans;
        map<int,int> mpp;


        //Now the containers are ready
        for(int i=0;i<n1;i++){
            mpp[arr1[i]]++;//Storing the frequency of each element
        }

        for(int i=0;i<n2;i++){
            int freq=mpp[arr2[i]];
            int element=arr2[i];
            while(freq!=0){
                ans.push_back(element);
                freq--;
            }
            mpp.erase(arr2[i]);
        }

        for(auto it:mpp){
            int element=it.first;
            int freq=it.second;
            while(freq!=0){
                ans.push_back(element);
                freq--;
            }
        }
        return ans;
    }
};