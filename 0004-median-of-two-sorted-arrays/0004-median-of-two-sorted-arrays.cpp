class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //Approach-1
        
        // int n1 =nums1.size();
        // int n2 = nums2.size();
        // int p1=0;
        // int p2=0;
        // vector<int> ans;
        // while(p1<n1&&p2<n2){
        //     if(nums1[p1]<=nums2[p2]){
        //         ans.push_back(nums1[p1]);
        //         p1++;
        //     }
        //     else{
        //         ans.push_back(nums2[p2]);
        //         p2++;
        //     }
        // }

        // while(p1<n1){
        //     ans.push_back(nums1[p1]);
        //     p1++;
        // }

        // while(p2<n2){
        //     ans.push_back(nums2[p2]);
        //     p2++;
        // }
        // int n = n1+n2;
        // if(n%2==0){
        //     return (double)((double)ans[n/2]+(double(n/2-1))/2.0);
        // }
        // else{
        //     return ans[n/2];
        // }
        // return -1;

        // Approach-2
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = (n1+n2);
        int i =0;
        int j =0;
        int ind2 = (n/2);
        int ind1 = ind2-1;
        int count=0;
        int ind1el=-1;
        int ind2el=-1;
        while(i<n1&&j<n2){
            if(nums1[i]<nums2[j]){
                if(count==ind1)ind1el=nums1[i];
                if(count==ind2)ind2el=nums1[i];
                count++;
                i++;
            }
            else{
                if(count==ind1)ind1el=nums2[j];
                if(count==ind2)ind2el=nums2[j];
                count++;
                j++;
            }
        }
        while(i<n1){
             if(count==ind1)ind1el=nums1[i];
             if(count==ind2)ind2el=nums1[i];
                count++;
                i++;
        }

        while(j<n2){
            if(count==ind1)ind1el=nums2[j];
            if(count==ind2)ind2el=nums2[j];
                count++;
                j++;
        }

        if(n%2==1){
            return ind2el;
        }
        else{
            return (double)((double)(ind1el+ind2el))/2.0;
        }
        }
};