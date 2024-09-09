class StockSpanner {
public:
    vector<int> arr;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int count =1;
        arr.push_back(price);
        for(int i =arr.size()-2;i>=0;i--){
            if(arr[i]<=price){
                count++;
            }else{
                break;
            }
        }
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */