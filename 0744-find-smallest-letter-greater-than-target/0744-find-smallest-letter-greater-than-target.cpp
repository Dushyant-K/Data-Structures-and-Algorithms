class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        //Approach-1(Using Binary Search)
        int n = letters.size();

        int ans=-1;
        int low=0;
        int high=n-1;

        while(low<=high){
            int mid=(low+high)/2;
            if(letters[mid]-'a'>target-'a'){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        if(ans!=-1)return letters[ans];
        return letters[0];
    }
};