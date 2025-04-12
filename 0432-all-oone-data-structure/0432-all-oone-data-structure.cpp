class Node{
    public:
    int count;
    list<string> keys;
    Node* prev;
    Node* next;

    Node(int c){
        count = c;
        prev=nullptr;
        next=nullptr;
    }
};
class AllOne {
    private:
    unordered_map<string,Node*> mpp;
    Node* head;
    Node* last;
public:
    AllOne() {
        head = new Node(0);
        last=head;
    }

    void addNode(Node* prevNode, int count){
        Node* currNode = new Node(count);
        currNode->next = prevNode->next;
        currNode->prev = prevNode;
        if(currNode->next!=nullptr){
            currNode->next->prev = currNode;
        }
        prevNode->next = currNode;
        if(prevNode==last){
            last = currNode;
        }
    }

    void removeNode(Node* node){
        node->prev->next = node->next;
        if(node->next!=nullptr){
            node->next->prev = node->prev;
        }

        if(last==node){
            last=node->prev;
        }
        delete(node);
    }
    
    void inc(string key) {
        if(mpp.find(key)==mpp.end()){
            if(head->next==nullptr||head->next->count!=1){
                addNode(head,1);
            }
            head->next->keys.push_front(key);
            mpp[key] = head->next;
        }else{
            Node* currNode = mpp[key];
            int currCount = currNode->count;
            if(currNode->next==nullptr||currNode->next->count!=currCount+1){
                addNode(currNode,currCount+1);
            }
            currNode->next->keys.push_front(key);
            mpp[key] = currNode->next;
            currNode->keys.remove(key);

            if(currNode->keys.empty())
            removeNode(currNode);
        }
    }
    
    void dec(string key) {
        Node* currNode = mpp[key];
        int currCount = currNode->count;

        if(currCount==1){
            mpp.erase(key);
        }else{
            if(currNode->prev->count!=currCount-1){
                addNode(currNode->prev,currCount-1);
            }
            currNode->prev->keys.push_front(key);
            mpp[key]=currNode->prev;
        }

        currNode->keys.remove(key);
        if(currNode->keys.empty()){
            removeNode(currNode);
        }
    }
    
    string getMaxKey() {
        if(last==head)return "";

        return last->keys.front();
    }
    
    string getMinKey() {
        if(head->next==nullptr)return "";

        return head->next->keys.front();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */