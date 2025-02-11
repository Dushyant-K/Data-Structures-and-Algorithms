//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
    
  public:
    Node* rotate(Node* head, int k) {
       if (!head || k == 0) return head;
        
        // Count the length of the linked list
        Node* temp = head;
        int length = 1;
        while (temp->next) {
            temp = temp->next;
            length++;
        }
        
        // If k is greater than or equal to length, adjust k
        k = k % length;
        if (k == 0) return head;  // No rotation needed
        
        // Find the k-th node
        temp = head;
        for (int i = 1; i < k; i++) {
            temp = temp->next;
        }
        
        // Split the list and update pointers
        Node* newHead = temp->next;
        temp->next = nullptr;
        
        Node* tail = newHead;
        while (tail && tail->next) {
            tail = tail->next;
        }
        
        if (tail) tail->next = head;  // Connect end of new list to original head
        
        return newHead;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }

        Node* head = nullptr;

        // Check if the array is empty
        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node* tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.rotate(head, k);
        printList(head);
        cout << "~\n";
    }
    return 1;
}

// } Driver Code Ends