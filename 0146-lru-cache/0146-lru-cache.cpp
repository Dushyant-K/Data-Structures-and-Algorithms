#include <map>
using namespace std;

class Node {
public:
    int key;
    int value;
    Node* next;
    Node* prev;
    Node(int key, int value) {
        this->key = key;
        this->value = value;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache {
public:
    int capacity;
    Node* head;
    Node* tail;
    map<int, Node*> mpp;

    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        mpp.clear();
    }

    void deleteNode(Node* node) {
        Node* temp1 = node->next;
        Node* temp2 = node->prev;
        temp2->next = temp1;
        temp1->prev = temp2;
    }

    void insertAfterHead(Node* node) {
        Node* afterHead = head->next;
        node->next = afterHead;
        node->prev = head;
        head->next = node;
        afterHead->prev = node;
    }

    int get(int key) {
        if (mpp.find(key) == mpp.end()) return -1; // If key not found

        Node* temp = mpp[key];
        deleteNode(temp); // Remove the node from its current position
        insertAfterHead(temp); // Insert it after head as most recently used

        return temp->value;
    }

    void put(int key, int value) {
        if (mpp.find(key) != mpp.end()) {
            // If key exists, update the value and move to the front
            Node* temp = mpp[key];
            temp->value = value;
            deleteNode(temp);
            insertAfterHead(temp);
        } else {
            // If key does not exist, check the capacity
            if (mpp.size() == capacity) {
                // Remove the least recently used node (node before tail)
                Node* lru = tail->prev;
                deleteNode(lru);
                mpp.erase(lru->key); // Remove it from the map
                delete lru; // Free memory
            }

            // Insert the new key-value pair
            Node* temp = new Node(key, value);
            insertAfterHead(temp);
            mpp[key] = temp; // Add to map
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
