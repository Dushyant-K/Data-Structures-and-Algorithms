/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool getPath(TreeNode* root, TreeNode* p, vector<TreeNode*>& res){
        if(root==nullptr)return false;

        res.push_back(root);

        if(root==p)return true;

        bool flag1 = getPath(root->left,p,res);
        bool flag2 = getPath(root->right,p,res);

        if(flag1||flag2)return true;

        res.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       vector<TreeNode*> path1, path2;

        if (!getPath(root, p, path1) || !getPath(root, q, path2)) {
            // Handle cases where p or q is not in the tree
            return nullptr;
        }

        int i = 0;
        while (i < path1.size() && i < path2.size() && path1[i] == path2[i]) {
            i++;
        }

        return path1[i - 1];
    }
};