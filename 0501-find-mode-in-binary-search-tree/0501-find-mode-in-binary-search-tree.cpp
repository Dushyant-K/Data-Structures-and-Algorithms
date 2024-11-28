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
    void inOrder(TreeNode* root, vector<int>& inorder){
        if(root==nullptr)return;

        inOrder(root->left,inorder);
        inorder.push_back(root->val);
        inOrder(root->right,inorder);
    }
public:
    vector<int> findMode(TreeNode* root) {
        //Approach-1(Inorder Traversal)
        if(root==nullptr)return {};
        vector<int> inorder;
        inOrder(root,inorder);
        vector<int> ans;
        int maxCount = 0;
        int currentCount = 0;
        int prevValue = INT_MIN;

        for (int value : inorder) {
            if (value == prevValue) {
                currentCount++;
            } else {
                currentCount = 1;
                prevValue = value;
            }

            if (currentCount > maxCount) {
                ans.clear();
                ans.push_back(value);
                maxCount = currentCount;
            } else if (currentCount == maxCount) {
                ans.push_back(value);
            }
        }

        return ans;
    }
};