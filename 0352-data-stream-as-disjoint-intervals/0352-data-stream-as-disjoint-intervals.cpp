class SummaryRanges {
public:
 unordered_set<int> st;
    SummaryRanges() {
       st.clear();
    }
    
    void addNum(int value) {
        st.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        if(st.empty())return {};

        vector<int> ans(st.begin(),st.end());

        sort(ans.begin(),ans.end());


        vector<vector<int>> intervals;
        int n = ans.size();
        for(int i=0;i<n;i++){
            int start = ans[i];
            while(i<n-1&&ans[i+1]-1==ans[i])i++;

            intervals.push_back({start,ans[i]});
        }
        
        return intervals;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */