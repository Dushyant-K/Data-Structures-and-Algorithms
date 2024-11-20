class Solution {
    private:
    int upperBound(vector<int> &nums, int val){
        int idx=nums.size();
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]>val){
                idx=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return idx;
    }
public:
    int createSortedArray(vector<int>& instructions) {
        //Approach-1
        // int n=instructions.size();
        // int mod=(1e9+7);
        // int cost=0;
        // vector<int> nums;
        // nums.push_back(instructions[0]);
        // for(int i=1;i<n;i++){
        //     int idx = upperBound(nums,instructions[i]);
        //     int greater=nums.size()-idx;
        //     int smaller=idx;
        //     while (smaller > 0 && nums[smaller - 1] == instructions[i]) {
        //         smaller--;
        //     }
        //     cost = (cost + min(greater, smaller)) % mod;
        //    nums.insert(nums.begin() + idx, instructions[i]);
        // }
        // return cost;

        //Approach-2(Fenwick tree)
                const int MOD = 1e9 + 7;
        int maxVal = *max_element(instructions.begin(), instructions.end());
        vector<int> fenwick(maxVal + 1, 0);

        auto update = [&](int index, int value) {
            while (index <= maxVal) {
                fenwick[index] += value;
                index += index & -index;
            }
        };

        auto query = [&](int index) {
            int sum = 0;
            while (index > 0) {
                sum += fenwick[index];
                index -= index & -index;
            }
            return sum;
        };

        long long cost = 0;
        for (int i = 0; i < instructions.size(); ++i) {
            int num = instructions[i];
            int smaller = query(num - 1);   // Count of elements smaller than `num`
            int greater = i - query(num);  // Count of elements greater than `num`
            cost += min(smaller, greater);
            cost %= MOD;
            update(num, 1);                // Insert `num` into the Fenwick Tree
        }

        return cost;
    }
};