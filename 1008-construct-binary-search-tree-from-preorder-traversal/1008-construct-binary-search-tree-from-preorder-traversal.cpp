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
     TreeNode* build(vector<int>& preorder, int& i, int bound){
        if(i==preorder.size()||preorder[i]>bound)return nullptr;

        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = build(preorder,i,root->val);
        root->right = build(preorder,i,bound);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int,int> hash){
        if(preStart>preEnd||inStart>inEnd)return nullptr;

        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);

        int idxRoot = hash[rootVal];
        int numsLeft = idxRoot-inStart;

        root->left = buildTree(preorder,preStart+1,preStart+numsLeft,inorder,inStart,idxRoot-1,hash);
        root->right = buildTree(preorder,preStart+numsLeft+1,preEnd,inorder,idxRoot+1,inEnd,hash);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        //Approach-1
        // vector<int> inorder(preorder);
        // sort(inorder.begin(),inorder.end());
        // map<int,int> hash;
        // for(int i=0;i<inorder.size();i++){
        //     hash[inorder[i]]=i;
        // }
        // TreeNode* root = buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,hash);
        // return root;

        //Approach-2
        int i=0;
        return build(preorder,i,INT_MAX);
    }
};