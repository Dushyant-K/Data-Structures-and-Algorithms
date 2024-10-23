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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==nullptr||root->val==val)return root;
        TreeNode* dummy = root;
        while(dummy!=nullptr){
            if(dummy->val == val)return dummy;
            else if(dummy->val>val)dummy=dummy->left;
            else{
                dummy = dummy->right;
            }
        }
        return dummy;
    }
};