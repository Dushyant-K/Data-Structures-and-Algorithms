class Solution {
public:
    bool check(int n){
        if(n==0)return false;
        int count=0;
        while(n!=0){
            n = n&(n-1);
            count++;
        }
        return count==1;
    }
    bool constructNumber(int n, string str, vector<int>& freq){
        if(n==0){
            return check(stoi(str));
        }

        for(int i=0;i<=9;i++){
            if(freq[i]==0)continue;
            str.push_back('0'+i);
            freq[i]--;
            if(constructNumber(n-1,str,freq))return true;
            freq[i]++;
            str.pop_back();
        }

        return false;
    }
    bool reorderedPowerOf2(int n) {
        //Approach-1(Using Bit Manipulation and Recursion)
        if(n==1)return true;

        if(check(n))return true;

        vector<int> freq(10,0);
        int count=0;

        for(int i=n;i!=0;i/=10){
            int dig = i%10;
            freq[dig]++;
            count++;
        }

        string str="";

        for(int i=1;i<=9;i++){
            if(freq[i]==0)continue;
            str.push_back('0'+i);
            freq[i]--;
            if(constructNumber(count-1,str,freq))return true;
            str.pop_back();
            freq[i]++;
        }

        return false;
    }
};