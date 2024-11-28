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
        void inOrder(TreeNode* root, int& prev, int& minDiff) {
        if (root == nullptr) return;

        inOrder(root->left, prev, minDiff);

        if (prev != -1) { 
            minDiff = std::min(minDiff, root->val - prev);
        }
        prev = root->val;

        inOrder(root->right, prev, minDiff);
    }
public:
    int minDiffInBST(TreeNode* root) {
       //Approach-1
        int minDiff = INT_MAX; 
        int prev = -1;        
        inOrder(root, prev, minDiff);
        return minDiff;
    }
};