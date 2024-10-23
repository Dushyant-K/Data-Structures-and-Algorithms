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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
         if (root == nullptr) {
            return new TreeNode(val); // If the tree is empty, create a new root
        }
        TreeNode* dummy = root;
        while (dummy != nullptr) {
            if (val > dummy->val) {
                if (dummy->right == nullptr) {
                    dummy->right = new TreeNode(val); // Create a new node and assign it to the right
                    break;
                } else {
                    dummy = dummy->right; // Move to the right child
                }
            } else { // val < dummy->val
                if (dummy->left == nullptr) {
                    dummy->left = new TreeNode(val); // Create a new node and assign it to the left
                    break;
                } else {
                    dummy = dummy->left; // Move to the left child
                }
            }
        }
        return root;
    }
};