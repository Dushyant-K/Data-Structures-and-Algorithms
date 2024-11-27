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
    int cumulativeSum = 0; 

    void convertToGreaterTree(TreeNode* root) {
        if (!root) return;

        convertToGreaterTree(root->right);

        cumulativeSum += root->val;
        root->val = cumulativeSum;

        convertToGreaterTree(root->left);
    }

public:
    TreeNode* convertBST(TreeNode* root) {
        //Approach-1(recursive Inorder Traversal)
        convertToGreaterTree(root);
        return root;
    }
};