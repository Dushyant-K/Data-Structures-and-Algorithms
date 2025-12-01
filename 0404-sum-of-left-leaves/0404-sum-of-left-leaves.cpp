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
    bool isLeaf(TreeNode* root){
        if(root->left!=nullptr||root->right!=nullptr)return false;
        return true;
    }
    int solve(TreeNode* root, bool flag){
        if(root==nullptr)return 0;
        if(isLeaf(root)){
            if(flag)return root->val;
            return 0;
        }

        int left = solve(root->left,true);
        int right = solve(root->right,false);

        return left+right;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        //Approach-1(Using DFS Traversal)
        if(root==nullptr)return 0;

        return solve(root,false);
    }
};