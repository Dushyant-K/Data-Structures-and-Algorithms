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
    ListNode* collisionPoint(ListNode* small, ListNode* large, int diff){
        while(diff){
            diff--;
            large = large->next;
        }

        while(small!=large){
            small = small->next;
            large = large->next;
        }
        return small;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //Appraoch-1
        // map<ListNode*,int> mpp;
        // ListNode* temp = headA;
        // while(temp!=nullptr){
        //     mpp[temp] = 1;
        //     temp = temp->next;
        // }
        // temp = headB;
        // while(temp!=nullptr){
        //     if(mpp.contains(temp))return temp;
        //     temp = temp->next;
        // }
        // return nullptr;

        //Approach-2
        int n1=0;
        int n2=0;
        ListNode* temp = headA;
        while(temp!=nullptr){
            temp = temp->next;
            n1++;
        }
        temp = headB;
        while(temp!=nullptr){
            temp = temp->next;
            n2++;
        }

        if(n1>n2) return (collisionPoint(headB,headA,(n1-n2)));
        return (collisionPoint(headA,headB,(n2-n1)));
    }
};