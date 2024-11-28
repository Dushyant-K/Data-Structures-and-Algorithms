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
    TreeNode* current;
    private:
        void inOrder(TreeNode* root) {
        if (root == nullptr) return;
        inOrder(root->left);

        root->left = nullptr;          
        current->right = root;         
        current = root;                
        inOrder(root->right);
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy = new TreeNode(-1); 
        current = dummy;                   
        inOrder(root);                     
        return dummy->right;  
    }
};