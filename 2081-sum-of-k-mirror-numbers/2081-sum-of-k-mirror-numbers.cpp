class Solution {
    private:
    bool isPalindrome(string str){
        int n=str.length();
        int low=0;
        int high=n-1;
        while(low<high){
            if(str[low]!=str[high])return false;
            low++;
            high--;
        }

        return true;
    }
    string convertToKBase(int  n, int k){
        string str="";

        while(n!=0){
            int rem=n%k;
            str += (rem < 10 ? rem + '0' : rem - 10 + 'a');
            n=n/k;
        }

        reverse(str.begin(),str.end());
        return str;
    }
public:
    long long kMirror(int k, int n) {
        //Approach-1(Brute force Approach)
        // long long sum=0;

        // int i=1;
        // while(n>0){
        //     if(isPalindrome(to_string(i))){
        //         string convert = convertToKBase(i,k);
        //         if(isPalindrome(convert)){
        //             sum+=i;
        //             n--;
        //         }
        //     }
        //     i++;
        // }

        // return sum;

        //Approach-2(Optimal Approach-Generating Palindromw)
        long long sum=0;
        int length=1;

        while(n>0){
            int mid = (length+1)/2;

            int low = pow(10,mid-1);
            int high = pow(10,mid)-1;
            for(int i=low;i<=high;i++){
                string first_half=  to_string(i);
                string second_half = first_half;
                reverse(second_half.begin(),second_half.end());

                string pal="";
                if(length%2==0){
                    pal = first_half+ second_half;
                }else{
                    pal = first_half+second_half.substr(1);
                }

                long long num = stoll(pal);
                string convert = convertToKBase(num,k);
                if(isPalindrome(convert)){
                    sum+=num;
                    n--;
                    if(n==0)break;
                }
            }
            length++;
        }

        return sum;
    }
};