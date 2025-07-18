class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        //Approach-1(Using Frequency Map)
        int n = keysPressed.length();

        map<char,int> mpp;

        mpp[keysPressed[0]] = releaseTimes[0];

        for(int i=1;i<n;i++){
            mpp[keysPressed[i]]+= releaseTimes[i]-releaseTimes[i-1];
        }

        char ch ='-';
        int maxi = 0;
        for(int i=0;i<n;i++){
            int freq = mpp[keysPressed[i]];
            if(freq>maxi){
                maxi = freq;
                ch=keysPressed[i];
            }else if(freq==maxi){
                if(ch<keysPressed[i])ch=keysPressed[i];
            }
        }

        return ch;
    }
};