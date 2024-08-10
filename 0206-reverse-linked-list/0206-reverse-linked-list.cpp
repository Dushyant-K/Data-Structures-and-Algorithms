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
    ListNode* reverseList(ListNode* head) {
        
        //Approach-1(Iterative Method)
        // if(head==nullptr || head->next==nullptr)return head;

        // ListNode* mover = head;
        // ListNode* temp = nullptr;
        // while(mover!=nullptr){
        //     head = head->next;
        //     mover->next = temp;
        //     temp = mover;
        //     mover = head;
        // }
        // return temp;

        //Approach-2(Recursive Method)
        if(head==nullptr || head->next==nullptr)return head;
        ListNode* newHead = reverseList(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = nullptr;
        return newHead;
    }
};