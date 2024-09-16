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
    void recursion(TreeNode* root,vector<int>& ans){
          if(root==nullptr)return;
           ans.push_back(root->val);
           recursion(root->left,ans);
           recursion(root->right,ans);
           return;
    }
   
    vector<int> preorderTraversal(TreeNode* root) {
        //Recursive Approach
        // vector<int> ans;
        // recursion(root,ans);
        // return ans;

        //Approach-2
        // vector<int> ans;
        // if(root==nullptr)return ans;
        // stack<TreeNode*> st;
        // st.push(root);
        // while(!st.empty()){
        //     TreeNode* temp = st.top();
        //     st.pop();
        //     if(temp->right!=nullptr)st.push(temp->right);
        //     if(temp->left!=nullptr)st.push(temp->left);
        //     ans.push_back(temp->val);
        // }
        // return ans;

        //Approach-3(Morris pre-order Traversal)
        vector<int> preorder;
        if(root==nullptr)return preorder;
        TreeNode* curr = root;
        while(curr!=nullptr){
            if(curr->left==nullptr){
                preorder.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode* prev = curr->left;
                while(prev->right&&prev->right!=curr){
                    prev = prev->right;
                }
                if(prev->right==nullptr){
                    prev->right=curr;
                    preorder.push_back(curr->val);
                    curr = curr->left;
                }
                else{
                    prev->right = nullptr;
                    curr = curr->right;
                }
            }
        }
        return preorder;
    }

};