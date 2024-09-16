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
    void markParents(TreeNode* root, unordered_map<TreeNode*,TreeNode*>& parent_track){
        if(root==nullptr)return;

        if(root->left)parent_track[root->left]=root;
        if(root->right)parent_track[root->right]=root;

        markParents(root->left,parent_track);
        markParents(root->right,parent_track);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        //Approach-1
        unordered_map<TreeNode*,TreeNode*> parent_Track;
        markParents(root,parent_Track);
        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> q;
        int curr_size=0;
        q.push(target);
        visited[target] = true; 
        while(!q.empty()){
            if(curr_size++==k)break;
            int size =q.size();
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if((node->left)&&(!visited[node->left])){
                    q.push(node->left);
                    visited[node->left]=true;
                } 
                if((node->right)&&(!visited[node->right])){
                    q.push(node->right);
                    visited[node->right]=true;
                } 
                if((parent_Track[node])&&(!visited[parent_Track[node]])){
                    q.push(parent_Track[node]);
                    visited[parent_Track[node]]=true;
                }            
                }
                }
                vector<int> ans;
                while(!q.empty()){
                    TreeNode* node = q.front();
                    q.pop();
                    ans.push_back(node->val);
                }
                return ans;
    }
};