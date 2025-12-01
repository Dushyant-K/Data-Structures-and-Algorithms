/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int getSubtreeSum(TreeNode* root, unordered_map<int,int>& mpp){
        if(root==nullptr)return 0;

        int left = getSubtreeSum(root->left,mpp);
        int right = getSubtreeSum(root->right,mpp);

        mpp[left+right+root->val]++;

        return left+right+root->val;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        //Approach-1(Using DFS Traversal)
        if(root==nullptr)return {};

        unordered_map<int,int> mpp;

        getSubtreeSum(root,mpp);

        vector<int> ans;
        int maxFreq = 0;
        for(auto it: mpp){
            int value = it.first;
            int frequency = it.second;

            if(frequency>maxFreq){
                ans.clear();
                ans.push_back(value);
                maxFreq = frequency;
            }else if(frequency==maxFreq){
                ans.push_back(value);
            }
        }

        return ans;
    }
};