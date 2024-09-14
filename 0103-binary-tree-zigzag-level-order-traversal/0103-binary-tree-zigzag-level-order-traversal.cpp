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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> zigzag;
        if(root==nullptr)return zigzag;
        queue<TreeNode*> q;
        int flag = 0;
        q.push(root);
        while(!q.empty()){
            vector<int> levelNodes;
            int size = q.size();

                for(int i=0;i<size;i++){
                    TreeNode* node = q.front();
                    q.pop();
                    if(node->left!=nullptr)q.push(node->left);
                    if(node->right!=nullptr)q.push(node->right);
                    levelNodes.push_back(node->val);
                }
                
               if(flag%2==0)
                zigzag.push_back(levelNodes);
                else{
                    reverse(levelNodes.begin(),levelNodes.end());
                    zigzag.push_back(levelNodes);
                }
                flag++;
        }
        return zigzag;
    }
};