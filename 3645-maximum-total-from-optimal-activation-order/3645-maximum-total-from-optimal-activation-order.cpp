class Solution {
public:
    static bool comparator(const tuple<int,int,int> &a, const tuple<int,int,int> &b) {
        if (get<1>(a) != get<1>(b)) return get<1>(a) < get<1>(b);
        return get<0>(a) > get<0>(b);
    }

    long long maxTotal(vector<int>& value, vector<int>& limit) {
        // int n = value.size();

        // vector<tuple<int,int,int>> elements;
        // for (int i = 0; i < n; i++) {
        //     elements.push_back({value[i], limit[i], i});
        // }

        // sort(elements.begin(), elements.end(), comparator);

        // long long activationValue = 0;
        // long long totalActive = 0;
        // vector<int> activeStatus(n, 0);

        // for (auto &[val, lim, idx] : elements) {
        //     if (activeStatus[idx] == -1) continue;
        //     if (activeStatus[idx] == 0) {
        //         activationValue += val;
        //         totalActive++;
        //         activeStatus[idx] = 1;
        //     }

        //     vector<int> toDeactivate;
        //     for (auto &[v, l, i] : elements) {
        //         if (activeStatus[i] == -1) continue;
        //         if (l <= totalActive) {
        //             toDeactivate.push_back(i);
        //         }
        //     }
        //     for (int i : toDeactivate) {
        //         if (activeStatus[i] == 1) totalActive--;
        //         activeStatus[i] = -1;
        //     }
        // }

        // return activationValue;

        //Approach-2(Using Priority Queue)
        unordered_map<int, priority_queue<int>> umap;

        long long ans = 0;

        int n = value.size();

        for (int i = 0; i < n; i++) {
            umap[limit[i]].push(value[i]);
        }

        for (auto &[lim, pq]: umap) {
            for (int i = 0; i < lim && !pq.empty(); i++) {
                ans += pq.top();
                pq.pop();
            }
        }


        return ans;
    }
};
