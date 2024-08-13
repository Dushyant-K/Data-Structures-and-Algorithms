/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // ListNode* findPrevTail(ListNode* head){
    //     while(head->next->next!=nullptr){
    //         head = head->next;
    //     }
    //     return head;
    // }
    // ListNode* calculateLength(ListNode* head){
    //     int n=0;
    //     while(head!=nullptr){
    //         head = head->next;
    //         n++;
    //     }
    //     return n;
    // }
    // ListNode* findTail(Node* head){
    //     while(head->next!=nullptr){
    //         head = head->next;
    //     }
    //     return head;
    // }
    ListNode* findNthNode(ListNode* temp, int k){
        int cnt= 1;
        while(temp!=nullptr){
            if(cnt==k)return temp;
            cnt++;
            temp = temp->next;
        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr||k==0)return head;
        ListNode* tail = head;
        int len=1;
        while(tail->next!=nullptr){
            tail = tail->next;
            len++;
        }
        if(k%len==0)return head;

        k = k%len;

        tail->next = head;
        ListNode* newLastNode = findNthNode(head,len-k);
        head = newLastNode->next;
        newLastNode->next = nullptr;
        return head;
    }
};