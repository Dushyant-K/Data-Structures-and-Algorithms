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
    bool checkSymmetric(TreeNode* p, TreeNode* q){
        if(p==nullptr||q==nullptr)return (p==q);

        return ((p->val==q->val)&&(checkSymmetric(p->left,q->right))&&(checkSymmetric(p->right,q->left)));
    }
    bool isSymmetric(TreeNode* root) {
        //Approach-1
        if(root==nullptr)return true;

        return checkSymmetric(root->left,root->right);
    }
};