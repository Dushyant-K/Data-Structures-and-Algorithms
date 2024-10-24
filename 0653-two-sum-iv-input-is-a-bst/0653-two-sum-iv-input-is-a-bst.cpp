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
 class BSTIterator {
    private:
    stack<TreeNode*> st;
    bool reverse;
public:
    BSTIterator(TreeNode* root, bool reverse) {
        this->reverse = reverse;
        pushAll(root);
    }
    
    int next() {
        TreeNode* node = st.top();
        st.pop();
        if(reverse)
        pushAll(node->left);
        else 
        pushAll(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return (!st.empty());
    }
    void pushAll(TreeNode* root){
        if(reverse){
            while(root){
                st.push(root);
                root = root->right;
            }
        }
        else{
            while(root){
                st.push(root);
                root = root->left;
            }
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        //Approach-1
        BSTIterator l(root,false);
        BSTIterator r(root,true);

        int i = l.next();
        int j = r.next();
        while(i<j){
            if(i+j==k)return true;
            else if(i+j<k)i = l.next();
            else j = r.next();
        }
        return false;
    }
};