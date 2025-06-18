class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        //Approach-1
        int n = plants.size();
        int steps=0;
        int cap = capacity;

        for(int i=0;i<n;i++){
            if(cap>=plants[i]){
                steps+=1;
                cap-=plants[i];
            }else{
                steps+=2*i+1;
                cap=capacity-plants[i];
            }
        }

        return steps;
    }
};