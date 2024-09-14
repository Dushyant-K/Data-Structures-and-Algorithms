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
    int longestPath(TreeNode* root, int& maxi){
        if(root==nullptr)return 0;

        int lh = longestPath(root->left,maxi);
        int rh = longestPath(root->right,maxi);

        maxi = max(maxi,lh+rh);
        return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        //Approach-1
        if(root==nullptr)return 0;
        int maxi=0;
        longestPath(root,maxi);
        return maxi;
    }
};