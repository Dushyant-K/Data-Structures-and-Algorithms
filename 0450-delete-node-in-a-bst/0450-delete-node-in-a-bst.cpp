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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr)return root;

        if(root->val==key){
            return (helper(root));
        }

        TreeNode* dummy = root;
        while(root!=nullptr){
            if(key>root->val){
                if(root->right!=nullptr&&root->right->val==key){
                    root->right=helper(root->right);
                    break;
                }
                else{
                    root=root->right;
                }
            }
            else{
                if(root->left!=nullptr&&root->left->val==key){
                    root->left = helper(root->left);
                    break;
                }
                else{
                    root = root->left;
                }
            }
        }
        return dummy;
    }
    TreeNode* findLastRight(TreeNode* root){
        while(root->right!=nullptr){
            root = root->right;
        }
        return root;
        }
    TreeNode* helper(TreeNode* root){
        if(root->left==nullptr)return root->right;
        if(root->right==nullptr)return root->left;
        TreeNode* leftNode = root->left;
        TreeNode* lastRight = findLastRight(leftNode);
        lastRight->right = root->right;
        return leftNode;
    }
};