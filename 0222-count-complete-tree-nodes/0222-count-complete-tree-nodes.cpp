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
    int findLH(TreeNode* root){
        int height=0;
        while(root){
            root=root->left;
            height++;
        }
        return height;
    }

    int findRH(TreeNode* root){
        int height=0;
        while(root){
            root = root->right;
            height++;
        }
        return height;
    }
    int countNodes(TreeNode* root) {
        //Approach-1
        if(root==nullptr)return 0;

        int lh = findLH(root);
        int rh = findRH(root);

        if(rh==lh){
            return (1<<lh)-1;
        }   

        int leftHeight=countNodes(root->left);
        int rightHeight=countNodes(root->right);

        return (leftHeight+rightHeight+1);
    }
};