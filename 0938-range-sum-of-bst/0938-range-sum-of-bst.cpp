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
    int dfs(TreeNode* root, int low, int high){
        if(root==nullptr)return 0;

        if(root->val>high){
            return dfs(root->left,low,high);
        }
        else if(root->val<low){
            return dfs(root->right,low,high);
        }

        int left=dfs(root->left,low,high);
        int right=dfs(root->right,low,high);

        return left+right+root->val;
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        //Approach-1(dfs-traversal)
        return dfs(root,low,high);
    }
};