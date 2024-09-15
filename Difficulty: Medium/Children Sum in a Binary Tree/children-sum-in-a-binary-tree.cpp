//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*Complete the function below

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){80
        data = x;
        left = right = NULL;
    }
};
*/

class Solution{
    public:
    
    bool isLeaf(Node* root) {
        return (root != nullptr && root->left == nullptr && root->right == nullptr);
    }

    // Function to check whether all nodes of a tree have the value
    // equal to the sum of their child nodes.
    bool isSumProperty2(Node *root) {
        // Base case: if the node is null or it is a leaf node, return true.
        if (root == nullptr || isLeaf(root)) {
            return true;
        }

        // Initialize the sum of children as 0.
        int childSum = 0;

        // Add the value of the left child if it exists.
        if (root->left) {
            childSum += root->left->data;
        }

        // Add the value of the right child if it exists.
        if (root->right) {
            childSum += root->right->data;
        }

        // Check if the current node's data is equal to the sum of its children.
        // Also, recursively check the left and right subtrees.
        return (root->data == childSum) &&
               isSumProperty(root->left) &&
               isSumProperty(root->right);
    }
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
     // Approach-1(This code is for converting any tree to a tree having child sum property.)
    //  if(root==nullptr)return 0;
     
    //  int child;
     
    //  if(root->left)child+=root->left->data;
    //  if(root->right)child+=root->right->data;
     
    //  if(child>=root->data){
    //      root->data = child;
    //  }else{
    //      if(root->left)root->left->data = root->data;
    //      if(root->right)root->right->data = root->data;
    //  }
     
    //  Node* node1 = isSumProperty(root->left);
    //  Node* node2 = isSumProperty(root->right);
     
    //  int total=0;
     
    //  if(node1)total+=node1->data;
    //  if(node2)total+=node2->data;
    //  root->data = total;
    
    //Approach-2
    return isSumProperty2(root)?1:0;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.isSumProperty(root) << endl;
    }
    return 0;
}

// } Driver Code Ends