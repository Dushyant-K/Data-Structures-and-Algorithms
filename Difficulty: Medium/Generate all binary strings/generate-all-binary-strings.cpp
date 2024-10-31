//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    private:
     
     void generateAll(string str, int len, int n, vector<string>& res){
         if(len==n){
             res.push_back(str);
             return;
         }
         
         if(str[len-1]=='0'){
             generateAll(str+"0",len+1,n,res);
             generateAll(str+"1",len+1,n,res);
         }
         else{
             generateAll(str+"0",len+1,n,res);
         }
     }
public:
    vector<string> generateBinaryStrings(int num){
        //Approach-1
        vector<string> res;
        
         //Generate all binary strings starting with 0
        generateAll("0",1,num,res);
        
        //Generate all binary strings starting with 1
        generateAll("1",1,num,res);
        
        return res;
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        
        vector<string> v = obj.generateBinaryStrings(n);
        for(auto it:v) cout<<it<<" ";
        cout << endl;
    
cout << "~" << "\n";
}

    return 0;
}

// } Driver Code Ends