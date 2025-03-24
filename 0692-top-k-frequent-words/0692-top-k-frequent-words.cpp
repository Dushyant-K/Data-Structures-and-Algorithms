class Solution {
public:
    static bool comparator(pair<string,int> p1, pair<string,int> p2){
        if(p1.second==p2.second){
            return p1.first<p2.first;
        }
        else if(p1.second<p2.second){
            return false;
        }
        return true;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        //Approach-1(Hashmap Method)
        int  n=words.size();
        unordered_map<string,int> hash;

        for(auto it:words){
            hash[it]++;
        }

        vector<pair<string,int>> freq;
        for(auto it:hash){
            string word=it.first;
            int frequency=it.second;

            freq.push_back({word,frequency});
        }

        sort(freq.begin(), freq.end(), comparator);

        vector<string> ans;
        for(int i=0;i<k;i++){
            ans.push_back(freq[i].first);
        }

        return ans;
    }
};