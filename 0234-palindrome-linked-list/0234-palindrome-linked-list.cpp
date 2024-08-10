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
    ListNode* reverseLL(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while(temp!=nullptr){
            head = head->next;
            temp->next = prev;
            prev = temp;
            temp = head;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        //Approach-1
        // stack<int> st;
        // ListNode* mover = head;
        // while(mover!=nullptr){
        //     st.push(mover->val);
        //     mover = mover->next;
        // }

        // mover = head;
        // while(mover!=nullptr){
        //     if(mover->val!=st.top())return false;
        //     st.pop();
        //     mover = mover->next;
        // }
        // return true;

        //Approach-2
        if(head==nullptr || head->next==nullptr)return true;
        ListNode* tortoise = head;
        ListNode* hare = head;
        while(hare->next!=nullptr && hare->next->next!=nullptr){
            tortoise = tortoise->next;
            hare = hare->next->next;
        }
        ListNode* newHead = reverseLL(tortoise->next);
        ListNode* first = head;
        ListNode* second = newHead;
        while(second!=nullptr){
            if(first->val!=second->val)return false;
            first = first->next;
            second = second->next;
        }
        reverseLL(newHead);
        return true;
    }
};