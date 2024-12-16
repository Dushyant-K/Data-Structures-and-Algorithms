class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
       //Approach-1(Using min-heap)
    //    int n=nums.size();
    //    if(n==0)return {};
    //    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    //    for(int i=0;i<n;i++){
    //     pq.push({nums[i],i});
    //    } 

    //    while(k--){
    //     auto it=pq.top();
    //     pq.pop();
    //     int element=it.first;
    //     int idx=it.second;
    //     pq.push({element*multiplier,idx});
    //    }

    //    vector<int> result(n,0);
    //    while(!pq.empty()){
    //     auto it=pq.top();
    //     pq.pop();
    //     int element=it.first;
    //     int idx=it.second;
    //     result[idx]=element;
    //    }

    //    return result;

    //Approach-2(Heapify Approach-O(n))
    int n=nums.size();
    if(n==0)return {};
    vector<pair<int,int>> pairs;
    for(int i=0;i<n;i++){
        pairs.push_back({nums[i],i});
    }

    make_heap(pairs.begin(),pairs.end(),greater<>());//Heapify-O(n)

    while(k--){
       pop_heap(pairs.begin(),pairs.end(),greater<>());
       auto it=pairs.back();
       pairs.pop_back();

       int element=it.first;
       int idx=it.second;

       nums[idx]=element*multiplier;

       pairs.push_back({nums[idx],idx});
       push_heap(pairs.begin(),pairs.end(),greater<>());
    }
    return nums;
    }
};