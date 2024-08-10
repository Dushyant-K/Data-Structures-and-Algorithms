//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void loopHere(Node *head, Node *tail, int position) {
    if (position == 0)
        return;

    Node *walk = head;
    for (int i = 1; i < position; i++)
        walk = walk->next;
    tail->next = walk;
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
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(struct Node *head) {
        //Approach-1
        // Node* mover = head;
        // map<Node*,int> mpp;
        // int timer =1;
        // while(mover!=nullptr){
        //     if(mpp.contains(mover)==true){
        //         int value = mpp[mover];
        //         return (timer-value);
        //     }
        //     mpp[mover] = timer;
        //     mover = mover->next;
        //     timer++;
        // }
        // return 0;
        
        //Approach-2
        Node* tortoise = head;
        Node* hare = head;
        while(hare!=nullptr && hare->next!= nullptr){
            tortoise = tortoise->next;
            hare = hare->next->next;
            if(tortoise==hare){
                int count=1;
                tortoise = tortoise->next;
                while(tortoise!=hare){
                    tortoise = tortoise->next;
                    count++;
                }
                return count;
            }
        }
        return 0;
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
        while (ss >> number) {
            arr.push_back(number);
        }
        int k;
        cin >> k;
        cin.ignore();
        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        loopHere(head, tail, k);

        Solution ob;
        cout << ob.countNodesinLoop(head) << endl;
    }
    return 0;
}

// } Driver Code Ends