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
    int recursiveMaxDepth(TreeNode* root, int left, int right){
        if(root==nullptr)return 0;

        left = recursiveMaxDepth(root->left,left,right);
        right = recursiveMaxDepth(root->right,left,right);
        return (1+max(left,right));
    }
    int maxDepth(TreeNode* root) {
        int height = recursiveMaxDepth(root,0,0);
        return height;
    }
};