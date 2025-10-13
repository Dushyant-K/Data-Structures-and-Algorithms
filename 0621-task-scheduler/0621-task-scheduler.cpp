class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //Approach-2(Using Priority Queue)
        priority_queue<int> pq;
        unordered_map<char,int> mpp;

        for(int i=0;i<tasks.size();i++){
            mpp[tasks[i]]++;
        }

        for(auto it:mpp){
            pq.push(it.second);
        }

        int timer = 0;

        while(!pq.empty()){
            vector<int> ds;
            int i=0;
            while(!pq.empty()&&i<=n){
                int freq = pq.top();
                pq.pop();
                ds.push_back(freq-1);
                i++;
            }

            for(auto it:ds){
                if(it>0)pq.push(it);
            }

            if(pq.empty()){
                timer+=ds.size();
            }else{
                timer+=n+1;
            }
        }

        return timer;
    }
};