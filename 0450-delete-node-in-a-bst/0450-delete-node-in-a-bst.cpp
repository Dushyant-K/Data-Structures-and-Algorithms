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
        while(dummy!=nullptr){
            if(dummy->val>key){
                if(dummy->left!=nullptr&&dummy->left->val==key){
                    dummy->left = helper(dummy->left);
                    break;
                }
                dummy = dummy->left;
            }
            else{
                if(dummy->right!=nullptr&&dummy->right->val==key){
                    dummy->right = helper(dummy->right);
                    break;
                }
                dummy = dummy->right;
            }
        }
        return root;
    }
    TreeNode* findLastRight(TreeNode* root){
        while(root->right!=nullptr){
            root=root->right;
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