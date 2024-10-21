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
    int height(TreeNode* root, int& maxi){
        if(root==nullptr)return 0;

        int lh = height(root->left,maxi);
        int rh = height(root->right,maxi);

        maxi = max(maxi,lh+rh);
        return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        //Approach-1
        if(root==nullptr)return 0;
        int diameter=0;
        height(root,diameter);
        return diameter;
    }
};