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
    TreeNode* prev=nullptr;
    void flatten(TreeNode* root) {
        //Approach-1
    //    if(root==nullptr)return;

    //     flatten(root->right);
    //     flatten(root->left);

    //     root->right=prev;
    //     root->left=nullptr;
    //     prev=root;

        //Approach-2
        stack<TreeNode*> st;
        if(root==nullptr)return;
        st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            if(node->right)st.push(node->right);
            if(node->left)st.push(node->left);

            if(!st.empty())node->right = st.top();
            node->left = nullptr;
        }
    }
};