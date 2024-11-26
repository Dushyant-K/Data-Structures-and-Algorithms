//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void push(struct Node **head_ref, int new_data) {
    struct Node *new_node = new Node(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void lvl(TreeNode *r) {
    if (r == NULL)
        return;
    queue<TreeNode *> q;
    q.push(r);
    while (!q.empty()) {
        TreeNode *j = q.front();
        cout << j->data << " ";
        q.pop();
        if (j->left)
            q.push(j->left);
        if (j->right)
            q.push(j->right);
    }
}

void reverses(Node **head) {
    Node *prev = NULL;
    Node *cur = *head;
    Node *nxt;
    while (cur != NULL) {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    *head = prev;
}


// } Driver Code Ends
/*
// Link list Node
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    TreeNode* linkedListToBinaryTree(Node* head) {
    // Approach-1
    if (!head)
        return NULL;

    // Create the root node
    TreeNode* root = new TreeNode(head->data);
    queue<TreeNode*> q;
    q.push(root);

    Node* current = head->next;

    // Level-order construction of the binary tree
    while (current) {
        TreeNode* parent = q.front();
        q.pop();

        // Create the left child
        parent->left = new TreeNode(current->data);
        q.push(parent->left);
        current = current->next;

        // Create the right child, if available
        if (current) {
            parent->right = new TreeNode(current->data);
            q.push(parent->right);
            current = current->next;
        }
    }

    return root;
    }
};


//{ Driver Code Starts.

int main() {
    int T;

    cin >> T;
    cin.ignore();
    while (T--) {
        struct Node *head = NULL;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num) {
            a.push_back(num); // Read the array elements from input string
            push(&head, num); // Add to linked list
        }

        reverses(&head);
        Node *prevhead = head;
        Solution obj;

        TreeNode *root = obj.linkedListToBinaryTree(head);
        if (root == NULL) {
            cout << "[]\n";
        } else {
            lvl(root);
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends