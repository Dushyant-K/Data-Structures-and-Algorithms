/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //Approach-1(Using hashmap)
        if(head==nullptr)return head;

        unordered_map<Node*,Node*> hash;
        Node* temp=head;

        while(temp){
            Node* newNode = new Node(temp->val);
            hash[temp]=newNode;
            temp=temp->next;
        }

        temp=head;
        while(temp){
            Node* copy = hash[temp];
            copy->next = hash[temp->next];
            copy->random = hash[temp->random];
            temp=temp->next;
        }

        return hash[head];
    }
};