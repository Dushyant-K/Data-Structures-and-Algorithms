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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==nullptr || head->next==nullptr)return nullptr;
        ListNode* prev = nullptr;
        ListNode* tortoise = head;
        ListNode* hare = head;
        while(hare!=nullptr && hare->next!= nullptr){
            prev = tortoise;
            tortoise = tortoise->next;
            hare = hare->next->next;
        }
        prev->next = prev->next->next;
        tortoise->next = nullptr;
        delete(tortoise);
        return head;
    }
};