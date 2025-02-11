class Solution {
public:
    string removeOccurrences(string s, string part) {
        //Approach-1(Brute force)
        int n=s.length();
        int m=part.length();

        while(true){
            int idx=s.find(part);

            if(idx==string::npos){
                break;
            }
            s.erase(idx,m);
        }

        return s;
    }
};