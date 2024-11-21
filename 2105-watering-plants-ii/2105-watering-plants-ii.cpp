class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        //Approach-1
        int n=plants.size();
        int refills=0;
        int low=0;
        int high=n-1;
        int container1=capacityA;
        int container2=capacityB;
        while(low<=high){
            if(low==high){
                if(container1<plants[low]&&container2<plants[low])refills++;
                break;
            }

            if(container1>=plants[low]){
                container1-=plants[low];
            }
            else{
                container1=capacityA;
                container1-=plants[low];
                refills++;
            }

            if(container2>=plants[high]){
                container2-=plants[high];
            }
            else{
                container2=capacityB;
                container2-=plants[high];
                refills++;
            }
            low++;
            high--;
        }
        return refills;
    }
};