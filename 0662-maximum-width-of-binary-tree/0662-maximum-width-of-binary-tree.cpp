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
    int widthOfBinaryTree(TreeNode* root) {
        //Approach-1
        long long ans = 0;
        if(root==nullptr)return 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!(q.empty())){
            long long mini = q.front().second;
            long long first,last;
            long long size = q.size();
            for(int i=0;i<size;i++){
                long long currid = q.front().second-mini;
                TreeNode* node = q.front().first;
                q.pop();
                if(i==0)first=currid;
                if(i==size-1)last=currid;
                if(node->left)q.push({node->left,currid*2+1});
                if(node->right)q.push({node->right,currid*2+2});
            }
            ans = max(ans,(last-first+1));
        }
        return ans;
    }
};