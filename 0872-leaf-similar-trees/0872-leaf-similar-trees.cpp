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
    void dfs(TreeNode* root,vector<int>& leaf){
        if(root==nullptr)return;

        if(isLeaf(root))leaf.push_back(root->val);

        dfs(root->left,leaf);
        dfs(root->right,leaf);
    }
    bool isLeaf(TreeNode* root){
        if(root->left==nullptr&&root->right==nullptr)return true;
        return false;
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        //Approach-1
        vector<int> leaf1;
        dfs(root1,leaf1);
        vector<int> leaf2;
        dfs(root2,leaf2);
        int n1=leaf1.size();
        int n2=leaf2.size();
        if(n1!=n2)return false;
        for(int i=0;i<n1;i++){
            if(leaf1[i]!=leaf2[i])return false;
        }
        return true;
    }
};