class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        //Aproach-1
        int n=classes.size();
        if(n==0)return 0.0;
        priority_queue<pair<double,int>> pq;
        for(int i=0;i<n;i++){
            double currPr=(double)classes[i][0]/classes[i][1];
            double updatedPr=(double)(classes[i][0]+1)/(classes[i][1]+1);
            double delta = updatedPr-currPr;
            pq.push({delta,i});
        }

        while(extraStudents--){
            auto it=pq.top();
            pq.pop();

            // double delta = it.first;
            int bestClassIdx=it.second;
            
            classes[bestClassIdx][0]++;
            classes[bestClassIdx][1]++;

            double currPr=(double)classes[bestClassIdx][0]/classes[bestClassIdx][1];
            double updatedPr=(double)(classes[bestClassIdx][0]+1)/(classes[bestClassIdx][1]+1);
            double delta = updatedPr-currPr;

            pq.push({delta,bestClassIdx});
        }

        double result=0.0;
        for(int i=0;i<n;i++){
            result+=(double)classes[i][0]/classes[i][1];
        }
        return result/n;
    }
};