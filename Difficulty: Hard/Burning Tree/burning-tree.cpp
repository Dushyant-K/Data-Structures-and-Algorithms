//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    void mapChild(Node* root, map<Node*,Node*>& parent_track){
        queue<Node*> q;
        q.push(root);
         while (!q.empty()) {
            Node* node = q.front();
            q.pop();

            // Map the left child
            if (node->left) {
                parent_track[node->left] = node;
                q.push(node->left);
            }

            // Map the right child
            if (node->right) {
                parent_track[node->right] = node;
                q.push(node->right);
            }
        }
        
    }
    Node* findNode(Node* root, int target){
        if (root == nullptr) return nullptr;
        if (root->data == target) return root;

        Node* leftResult = findNode(root->left, target);
        if (leftResult != nullptr) return leftResult;

        return findNode(root->right, target);
    }
    int minTime(Node* root, int target) 
    {
        // Approach-1
        if(root==nullptr)return 0;
        map<Node*,Node*> parent_track;
        queue<Node*> q;
        mapChild(root,parent_track);
        
        
        Node* targetNode = findNode(root,target);
        if(targetNode==nullptr)return 0;
        q.push(targetNode);
        map<Node*,bool> visited;
        visited[targetNode]=true;
        int burnTime=0;
        //Now the traversal begins
        while(!q.empty()){
            bool burnedAny = false;
            int size = q.size();
            for(int i=0;i<size;i++){
                Node* node = q.front();
                q.pop();
                if((node->left)&&!visited[node->left]){
                    q.push(node->left);
                    visited[node->left]=true;
                    burnedAny=true;
                }
                if((node->right)&&(!visited[node->right])){
                    q.push(node->right);
                    visited[node->right]=true;
                    burnedAny=true;
                }
                if(parent_track[node]&&!visited[parent_track[node]]){
                    q.push(parent_track[node]);
                    visited[parent_track[node]]=true;
                    burnedAny=true;
                }
            }
            if(burnedAny){
             burnTime++;
            }
        }
        return burnTime;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends