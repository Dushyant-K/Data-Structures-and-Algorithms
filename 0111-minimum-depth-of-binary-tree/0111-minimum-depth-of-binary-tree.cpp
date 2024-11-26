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
    private:
    int dfs(TreeNode* root){
        if(root==nullptr)return 0;

        int lh=dfs(root->left);
        int rh=dfs(root->right);

        if(lh==0&&rh==0)return 1;

        if(lh==0)return rh+1;
        if(rh==0)return lh+1;

        return min(lh,rh)+1;
    }
public:
    int minDepth(TreeNode* root) {
        //Approach-1
        return dfs(root);
    }
};