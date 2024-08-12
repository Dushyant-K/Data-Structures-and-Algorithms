/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //Appraoch-1
        map<ListNode*,int> mpp;
        ListNode* temp = headA;
        while(temp!=nullptr){
            mpp[temp] = 1;
            temp = temp->next;
        }
        temp = headB;
        while(temp!=nullptr){
            if(mpp.contains(temp))return temp;
            temp = temp->next;
        }
        return nullptr;
    }
};