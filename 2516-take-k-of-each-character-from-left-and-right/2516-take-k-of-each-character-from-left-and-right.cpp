class Solution {
public:
    int takeCharacters(string s, int k) {
    int n = s.size();
    vector<int> hash(3);
    if(k==0)return 0;

    for(int i=0;i<n;i++){
        hash[s[i]-'a']++;
    }

    //Edge-case
    if(hash[0]<k||hash[1]<k||hash[2]<k)return -1;

    int left=0;
    int right=0;
    int maxSize=0;

    while(right<n){
        hash[s[right]-'a']--;
        while(hash[s[right]-'a']<k){
            hash[s[left]-'a']++;
            left++;
        }
        maxSize=max(maxSize,right-left+1);
        right++;
    }
    return n-maxSize;
    }
};