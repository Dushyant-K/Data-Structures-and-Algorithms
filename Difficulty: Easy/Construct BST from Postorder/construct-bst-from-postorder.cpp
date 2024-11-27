//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

Node *constructTree (int [], int );

void printInorder (Node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	printf("%d ", node->data);
	printInorder(node->right);
	

}

int main ()
{   
    int t,n;
   scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int post[n];
        for(int i=0;i<n;i++)
        scanf("%d",&post[i]);

    Node* root = constructTree(post, n);

	printInorder(root);
    printf("\n");

cout << "~" << "\n";
}
	return 0;
}

// } Driver Code Ends


/*struct Node
{
	int data;
	Node *left, *right;
};*/
// Helper function to perform inorder traversal

Node* constructTreeHelper(int post[], int& index, int minVal, int maxVal, int size) {
    if (index < 0 || post[index] < minVal || post[index] > maxVal) {
        return NULL;
    }

    Node* root = new Node(post[index--]);

    root->right = constructTreeHelper(post, index, root->data, maxVal, size);
    root->left = constructTreeHelper(post, index, minVal, root->data, size);

    return root;
}
Node *constructTree (int post[], int size)
{
    int index = size - 1; 
    return constructTreeHelper(post, index, INT_MIN, INT_MAX, size);
}