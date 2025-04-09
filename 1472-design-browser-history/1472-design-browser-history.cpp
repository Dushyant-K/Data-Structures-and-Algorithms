#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string data;
    Node* next;
    Node* prev;

    Node(string val) {
        this->data = val;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class BrowserHistory {
private:
    Node* curr;

    void deleteAll(Node* node) {
        while (node) {
            Node* temp = node;
            node = node->next;
            delete temp;
        }
    }

public:
    BrowserHistory(string homepage) {
        curr = new Node(homepage);
    }

    void visit(string url) {
        if (curr->next) {
            deleteAll(curr->next);  // clear forward history
            curr->next = nullptr;
        }
        Node* newNode = new Node(url);
        curr->next = newNode;
        newNode->prev = curr;
        curr = newNode;
    }

    string back(int steps) {
        while (curr->prev != nullptr && steps-- > 0) {
            curr = curr->prev;
        }
        return curr->data;
    }

    string forward(int steps) {
        while (curr->next != nullptr && steps-- > 0) {
            curr = curr->next;
        }
        return curr->data;
    }

    ~BrowserHistory() {
        // clean up all nodes from head
        while (curr->prev) curr = curr->prev;
        deleteAll(curr);
    }
};
