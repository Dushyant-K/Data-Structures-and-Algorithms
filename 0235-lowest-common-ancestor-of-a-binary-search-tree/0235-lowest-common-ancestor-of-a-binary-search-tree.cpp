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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        //Approach-1
        // if(root==p||root==q||root==nullptr){
        //     return root;
        // }

        // TreeNode* left = lowestCommonAncestor(root->left,p,q);
        // TreeNode* right = lowestCommonAncestor(root->right,p,q);

        // if(left==nullptr)return right;
        // if(right==nullptr)return left;

        // else return root;

        //Approach-2
        if(root==nullptr)return nullptr;

        int curr = root->val;

        if(p->val>curr&&q->val>curr){
           return lowestCommonAncestor(root->right,p,q);
        }
        if(p->val<curr&&q->val<curr){
            return lowestCommonAncestor(root->left,p,q);
        }
        return root;
    }
};