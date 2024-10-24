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
    TreeNode* first=nullptr;
    TreeNode* middle=nullptr;
    TreeNode* last=nullptr;
    TreeNode* prev = nullptr;
public:
    void recursion(TreeNode* root){
        if(root==nullptr)return;

        recursion(root->left);
        if(prev!=nullptr&&prev->val>root->val){
            if(first==nullptr){
                first = prev;
                middle = root;
            }
            else{
                last = root;
            }
        }
        prev = root;
        recursion(root->right);

    }
    void recoverTree(TreeNode* root) {
        //Approach-1
        
        recursion(root);
        if(first!=nullptr&&last!=nullptr)swap(first->val,last->val);
        else swap(first->val,middle->val);
    }
};