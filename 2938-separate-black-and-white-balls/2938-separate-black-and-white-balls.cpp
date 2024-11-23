class Solution {
public:
    long long minimumSteps(string s) {
        //Approach-1(Two-Pointer Approach)
        // int n=s.length();
        // int count=0;
        // int low=0;
        // int high=0;
        // while(high<n){
        //     while(high<n&&s[high]!='1'){
        //         high++;
        //     }
        //     if(high==n)return count;
        //     low=high;
        //     while(high<n&&s[high]!='0'){
        //         high++;
        //     }
        //     if(high==n)return count;
        //     count+=high-low;
        //     swap(s[high],s[low]);
        //     high=low+1;
        // }
        // return -1;

        //Approach-2
        int n = s.length();
        long long count = 0;
        int nextPosition = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                // If `1` is out of place, move it to the next correct position
                count += i - nextPosition;
                nextPosition++;
            }
        }

        return count;
    }
};