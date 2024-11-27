/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        //Approach-1(level Order Traversal)
        if(root==nullptr)return "#";
        string data;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node==nullptr)data.append("#,");
            else data.append(to_string(node->val)+',');
            if(node!=nullptr){
                q.push(node->left);
                q.push(node->right);
            }
        }
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
       if(data=="#")return nullptr;
       stringstream s(data);
       string str;
       getline(s,str,',');
       TreeNode* root = new TreeNode(stoi(str));
       queue<TreeNode*> q;
       q.push(root);


       while(!q.empty()){
        TreeNode* node = q.front();
        q.pop();

        getline(s,str,',');
        if(str=="#"){
            node->left = nullptr;
        }else{
            TreeNode* left = new TreeNode(stoi(str));
            node->left = left;
            q.push(left);
        }
        getline(s,str,',');
        if(str=="#"){
            node->right = nullptr;
        }else{
            TreeNode* right = new TreeNode(stoi(str));
            node->right = right;
            q.push(right);
        }
       }
       return root;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;