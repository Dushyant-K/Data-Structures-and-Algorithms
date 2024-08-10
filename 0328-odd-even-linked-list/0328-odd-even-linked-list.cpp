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
    ListNode* oddEvenList(ListNode* head) {
        //Approach-1
        if(head==nullptr || head->next==nullptr)return head;
        vector<int> temp;
        ListNode* mover = head;
        while(mover!=nullptr && mover->next!=nullptr){
            temp.push_back(mover->val);
            mover = mover->next->next;
        }
        if(mover)temp.push_back(mover->val);

        mover = head->next;
        while(mover!=nullptr && mover->next!=nullptr){
            temp.push_back(mover->val);
            mover = mover->next->next;
        }
        if(mover)temp.push_back(mover->val);
        
        int i=0;
        mover = head;
        while(mover!=nullptr){
            mover->val = temp[i];
            i++;
            mover = mover->next;
        }
        return head;
    }
};