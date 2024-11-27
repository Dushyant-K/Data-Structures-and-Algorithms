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
    TreeNode* buildTree(TreeNode* root1, TreeNode* root2){
        if(root1==nullptr&&root2==nullptr)return root1;

        int sum=0;
        if(root1)sum+=root1->val;
        if(root2)sum+=root2->val;

        TreeNode* root=new TreeNode(sum);

        if(root1&&root2){
            root->left=buildTree(root1->left,root2->left);
            root->right=buildTree(root1->right,root2->right);
        }
        else if(root1&&root2==nullptr){
            root->left=buildTree(root1->left,nullptr);
            root->right=buildTree(root1->right,nullptr);
        }
        else if(root1==nullptr&&root2!=nullptr){
            root->left=buildTree(nullptr,root2->left);
            root->right=buildTree(nullptr,root2->right);
        }
        return root;
    }
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        //Approach-1
        return buildTree(root1,root2);
    }
};