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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // Map to store nodes sorted by (column, row) -> set of node values
        map<int, map<int, multiset<int>>> nodes;
        
        // Queue for BFS: stores the node along with its (column, row) information
        queue<pair<TreeNode*, pair<int, int>>> todo;
        todo.push({root, {0, 0}});  // Start with the root at (0, 0)
        
        // BFS traversal
        while (!todo.empty()) {
            auto p = todo.front();
            todo.pop();
            
            TreeNode* node = p.first;
            int col = p.second.first;  // Horizontal distance (column)
            int row = p.second.second; // Vertical distance (row)
            
            // Insert the node value into the map at the (col, row) position
            nodes[col][row].insert(node->val);
            
            // Traverse the left and right children
            if (node->left) {
                todo.push({node->left, {col - 1, row + 1}});
            }
            if (node->right) {
                todo.push({node->right, {col + 1, row + 1}});
            }
        }
        
        // Prepare the result by extracting nodes from the map
        vector<vector<int>> result;
        for (auto& p : nodes) {
            vector<int> col;
            for (auto& q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            result.push_back(col);
        }
        
        return result;
    }
};