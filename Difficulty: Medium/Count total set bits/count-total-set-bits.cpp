//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function Template for C++

class Solution{
    public:
    int helper(int n){
        int count=0;

        while(n>0){
            if(n&1){
                count++;
            }
            n=n>>1;
        }

        return count;
    }
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        //Approach-1(Brute Force Approach)
        // int count=0;

        // for(int i=0;i<=n;i++){
        //     count+= helper(i);
        // }

        // return count;
        
        //Approach-2(Optimal Approach)
        // vector<int> bits(n+1,0);
        // int count=0;
        
        // for(int i=1;i<=n;i++){
        //     if(i%2==0){
        //         bits[i]=bits[i/2];
        //     }else{
        //         bits[i]=bits[i/2]+1;
        //     }
        //     count+=bits[i];
        // }
        
        // return count;
        
        //Your logic here
        
        // including 0;
        int totaln = n+1;
        // in binary representation 0th position contain 1 ones after every 2 number
        int noofones = 1;
        //store ans;
        int ans = 0;
        while(n!=0){
            // noofones*2 eauql no of ones and zeros are their
            int temp = totaln/(noofones*2);
            //adding complete pairs multiply with noofones contain in each pair
            ans+=(temp*noofones);
            //adding incomplete pairs
            //if only consider 0
            temp = totaln/noofones;
            //if %2==1 means remains are 1 beacuse 0&1 complete pair so %noofones gives 1 count
            if(temp%2==1) ans+= (totaln%noofones);
            // deciding how many times loop runs
            n>>=1;
            //next position contain 2*ones of previous position
            noofones*=2;
        }
        return ans;
    }
};



//{ Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  
cout << "~" << "\n";
}
	  return 0;
}

// } Driver Code Ends