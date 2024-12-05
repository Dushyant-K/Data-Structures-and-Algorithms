class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        //Approach-1(BFS Algorithim)
        if(target=="0000")return 0;
        set<string> st;
        st.insert(deadends.begin(),deadends.end());
        if(st.count("0000"))return -1;
        queue<string> q;
        q.push("0000");
        st.insert("0000");
        
        //Now the containers are ready
        int moves=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                string curr=q.front();
                q.pop();
                if(curr==target)return moves;
                for(int j=0;j<4;j++){
                    char ch=curr[j];

                    curr[j]=(ch=='9')?'0':ch+1;
                    if(!st.count(curr)){
                        st.insert(curr);
                        q.push(curr);
                    }

                    curr[j]=(ch=='0')?'9':ch-1;
                    if(!st.count(curr)){
                        st.insert(curr);
                        q.push(curr);
                    }
                    curr[j]=ch;
                }
            }
            moves++;
        }
        return -1;
    }
};