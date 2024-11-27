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
    bool isCousins(TreeNode* root, int x, int y) {
        //Approach-1(bfs Traversal)
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int size = q.size();
            bool foundX = false;
            bool foundY = false;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                // Check if the current node has x and y as its children
                if (node->left && node->right) {
                    int leftVal = node->left->val;
                    int rightVal = node->right->val;
                    if ((leftVal == x && rightVal == y) || (leftVal == y && rightVal == x)) {
                        return false; // Siblings, not cousins
                    }
                }

                // Check if the current node is x or y
                if (node->val == x) foundX = true;
                if (node->val == y) foundY = true;

                // Push the children into the queue
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // If both x and y are found at the same level and are not siblings, return true
            if (foundX && foundY) return true;

            // If only one of them is found, they can't be cousins
            if (foundX || foundY) return false;
        }

        return false;
    }
};