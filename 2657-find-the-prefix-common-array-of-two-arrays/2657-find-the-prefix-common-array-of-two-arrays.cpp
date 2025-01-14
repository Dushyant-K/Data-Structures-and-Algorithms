class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        //Approach-1
        int n=A.size();
        vector<int> freq(n+1,0);
        vector<int> prefixCommonArray(n);
        int count=0;

        for(int i=0;i<n;i++){
            if(freq[A[i]])count++;
            else freq[A[i]]++;

            if(freq[B[i]])count++;
            else freq[B[i]]++;

            prefixCommonArray[i]=count;
        }

        return prefixCommonArray;
    }
};