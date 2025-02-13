class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
       //Approach-1(Using Min Heap)
       int n=nums.size();
       if(n<2)return 0;
       priority_queue<long,vector<long>,greater<long>> pq(nums.begin(),nums.end());

       int count=0;
       while(pq.size()>=2&&pq.top()<k){
        long firstElement=pq.top();
        pq.pop();
        long secondElement=pq.top();
        pq.pop();

        long newElement=firstElement*2+secondElement;

        pq.push(newElement);
        count++;
       }

       return count;
    }
};