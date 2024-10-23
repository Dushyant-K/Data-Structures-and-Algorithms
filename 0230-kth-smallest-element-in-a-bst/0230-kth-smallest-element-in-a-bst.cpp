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
    void mark_parents(TreeNode* root, map<TreeNode*,TreeNode*>& parent_track){
        if(root==nullptr)return;
        if(root->left)parent_track[root->left]=root;
        if(root->right)parent_track[root->right]=root;
        mark_parents(root->left,parent_track);
        mark_parents(root->right,parent_track);
    }
    TreeNode* findLastLeft(TreeNode* root){
        while(root->left!=nullptr){
            root=root->left;
        }
        return root;
    }
    void inorderTraversal(TreeNode* root, int& k, int& result){
        if(root==nullptr)return;

        inorderTraversal(root->left,k,result);
        k--;
        if(k==0){
            result = root->val;
            return;
        }

        inorderTraversal(root->right,k,result);
    }
    int kthSmallest(TreeNode* root, int k) {
        //Approach-1(Tried it on my own)
        // map<TreeNode*,TreeNode*> parent_track;
        // mark_parents(root,parent_track);
        // TreeNode* leftNode = findLastLeft(root);
        // TreeNode* temp = leftNode;
        // int count=1;
        // while(leftNode!=nullptr){
        //     if(count==k)break;
        //     if(temp->right!=nullptr){
        //         temp=temp->right;
        //     }
        //     else{
        //         temp = parent_track[leftNode];
        //         leftNode = parent_track[leftNode];
        //     }
        //     count++;
        // }
        // if(temp==nullptr)return -1;
        // return temp->val;

        //Approach-2
        int result=-1;
        inorderTraversal(root,k,result);
        return result;
    }
};