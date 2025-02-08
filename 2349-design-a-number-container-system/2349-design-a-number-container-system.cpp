class NumberContainers {
public:
    unordered_map<int,int> idxMapping;
    unordered_map<int,set<int>> search;
    NumberContainers() {
    }
    
    void change(int index, int number) {
        if(idxMapping.find(index)!=idxMapping.end()){
            int node=idxMapping[index];
            search[node].erase(index);
        }
        idxMapping[index]=number;
        search[number].insert(index);
    }
    
    int find(int number) {
         return search[number].empty() ? -1 : *search[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */