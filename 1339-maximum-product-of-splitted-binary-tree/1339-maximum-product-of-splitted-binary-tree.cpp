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
    long long maxiProduct = 0;
    int sum=0;
    int mod = 1e9+7;

    int getMaxProduct(TreeNode* root){
        if(root==nullptr)return 0;

        long long left = getMaxProduct(root->left);
        long long right = getMaxProduct(root->right);

        maxiProduct = max(maxiProduct,(left*(sum-left))%mod);
        maxiProduct = max(maxiProduct,(right*(sum-right))%mod);

        return root->val+left+right;

    }
    int getSum(TreeNode* root){
        if(root==nullptr)return 0;

        int left = getSum(root->left);
        int right = getSum(root->right);

        return left+right+root->val;
    }
    int maxProduct(TreeNode* root) {
        //Approach-1
        sum = getSum(root);
        getMaxProduct(root);

        return maxiProduct;
    }
};