class Solution {
    private:
    bool isValid(stack<char> st, string part, int n){

        while(n>0){
            if(st.top()!=part[n-1])return false;
            st.pop();
            n--;
        }
        return true;
    }
public:
    string removeOccurrences(string s, string part) {
        //Approach-1(Brute force)
        // int n=s.length();
        // int m=part.length();

        // while(true){
        //     int idx=s.find(part);

        //     if(idx==string::npos){
        //         break;
        //     }
        //     s.erase(idx,m);
        // }

        // return s;

        //Approach-2
        int n=s.length();
        int m=part.length();

        stack<char> st;

        for(int i=0;i<n;i++){
            st.push(s[i]);
            if(st.size()>=m&& isValid(st,part,m)){
                for(int i=0;i<m;i++)st.pop();
            }
        }

        string result="";
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }

        reverse(result.begin(),result.end());
        return result;
    }
};