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
    int solve(TreeNode* root, bool flag, unordered_map<TreeNode*,int>& rob, unordered_map<TreeNode*,int>& notRob){
        if(root==nullptr)return 0;
        if(flag&&rob.find(root)!=rob.end())return rob[root];
        if(!flag&&notRob.find(root)!=notRob.end())return notRob[root];

        //Take
        int take = 0;
        int notTake = 0;
        if(flag){
            take = root->val+solve(root->left,!flag,rob,notRob)+solve(root->right,!flag,rob,notRob);
            notTake = 0+solve(root->left,flag,rob,notRob)+solve(root->right,flag,rob,notRob);

             return rob[root]=max(take,notTake);
        }else{
            return notRob[root]=0+solve(root->left,!flag,rob,notRob)+solve(root->right,!flag,rob,notRob);
        }
    }
    int rob(TreeNode* root) {
        if(root==nullptr)return 0;
        unordered_map<TreeNode*,int> rob, notRob;
        return solve(root,true,rob,notRob);
    }
};