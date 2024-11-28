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
    void convertToGst(TreeNode* root, int& sum){
        if(root==nullptr)return;

        convertToGst(root->right,sum);
        int temp=sum;
        sum+=root->val;
        root->val=root->val+temp;
        convertToGst(root->left,sum);
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        //Approach-1()
        int sum=0;
        convertToGst(root,sum);
        return root;
    }
};