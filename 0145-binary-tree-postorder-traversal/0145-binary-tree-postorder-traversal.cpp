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
    void recursivepostorderTraversal(TreeNode* root, vector<int>& ans){
        if(root==nullptr)return;
        recursivepostorderTraversal(root->left,ans);
        recursivepostorderTraversal(root->right,ans);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        //Approach-1
        // vector<int> ans;
        // recursivepostorderTraversal(root,ans);
        // return ans;

        //Approach-2
        // vector<int> ans;
        // if(root==nullptr)return ans;
        // stack<TreeNode*> st1;
        // stack<TreeNode*> st2;
        // st1.push(root);
        // while(!st1.empty()){
        //     TreeNode* node = st1.top();
        //     st1.pop();
        //     if(node->left!=nullptr)st1.push(node->left);
        //     if(node->right!=nullptr)st1.push(node->right);
        //     st2.push(node);
        // }
        // while(!st2.empty()){
        //     ans.push_back(st2.top()->val);
        //     st2.pop();
        // }
        // return ans;

        //Approach-3
        vector<int> result;
    if (root == nullptr) return result; // If the tree is empty

    stack<TreeNode*> s;
    TreeNode* current = root;
    TreeNode* lastVisited = nullptr;

    while (!s.empty() || current != nullptr) {
        if (current != nullptr) {
            s.push(current);
            current = current->left;  // Traverse to the left subtree
        } else {
            TreeNode* peekNode = s.top();
            // If right child exists and traversing node from left child, move to right child
            if (peekNode->right != nullptr && lastVisited != peekNode->right) {
                current = peekNode->right;
            } else {
                result.push_back(peekNode->val);
                lastVisited = s.top();
                s.pop();
            }
        }
    }

    return result;
    }
};