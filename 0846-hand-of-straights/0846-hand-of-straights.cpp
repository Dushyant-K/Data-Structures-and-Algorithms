class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        //Approach-1(Using Max Heap)
        int n = hand.size();
        if(n<groupSize||n%groupSize!=0)return false;
        unordered_map<int,int> freq;

        for(int i=0;i<n;i++){
            freq[hand[i]]++;
        }

        priority_queue<pair<int,int>> pq;

        for(auto it: freq){
            pq.push({it.first,it.second});
        }

        while(!pq.empty()){
            vector<pair<int,int>> ds;
            pair<int,int> firstElement = pq.top();
            pq.pop();
            ds.push_back({firstElement.first,firstElement.second-1});

            int size = groupSize-1;
            while(size>0){
                pair<int,int> nextElement = pq.top();
                pq.pop();
                if((nextElement.first+1)!=firstElement.first)return false;
                ds.push_back({nextElement.first,nextElement.second-1});
                firstElement=nextElement;
                size--;
            } 

            for(auto it:ds){
                if(it.second>0)pq.push({it.first,it.second});
            }
        }

        return true;
    }
};