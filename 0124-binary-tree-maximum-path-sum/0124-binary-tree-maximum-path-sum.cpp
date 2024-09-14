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
    int sumOfAllPaths(TreeNode* root, int& maxi){
        if (root == nullptr) return 0;

        // Calculate the maximum sum of the left and right subtrees
        // If a subtree sum is negative, we discard it by taking max with 0
        int leftSum = max(0, sumOfAllPaths(root->left, maxi));
        int rightSum = max(0, sumOfAllPaths(root->right, maxi));

        // Calculate the current path sum by including the current node's value
        // This considers the current node as the root of the maximum path
        int currentPathSum = leftSum + rightSum + root->val;

        // Update the global maximum path sum if the current path sum is larger
        maxi = max(maxi, currentPathSum);

        // Return the maximum path sum including either left or right child (but not both)
        // because a path can only continue through one child
        return max(leftSum, rightSum) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        int maxSum=INT_MIN;
        sumOfAllPaths(root,maxSum);
        return maxSum;
    }
};