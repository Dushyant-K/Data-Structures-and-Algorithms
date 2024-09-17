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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder;
        inorder=preorder;
        sort(inorder.begin(),inorder.end());
        map<int,int> hash;
        for(int i=0;i<inorder.size();i++){
            hash[inorder[i]]=i;
        }
        TreeNode* root = buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,hash);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int,int> hash){
        if(preStart>preEnd||inStart>inEnd)return nullptr;

        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = hash[root->val];

        int numsLeft = inRoot-inStart;

        root->left = buildTree(preorder,preStart+1,preEnd+numsLeft,inorder,inStart,inRoot-1,hash);
        root->right = buildTree(preorder,preStart+numsLeft+1,preEnd,inorder,inRoot+1,inEnd,hash);
        return root;
    }
};