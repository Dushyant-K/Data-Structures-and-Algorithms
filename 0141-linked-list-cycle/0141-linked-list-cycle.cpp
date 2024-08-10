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
    bool hasCycle(ListNode *head) {
        //Approach-1
        // map<ListNode*,int> mpp;
        // ListNode* mover = head;
        // int count=0;
        // while(mover!=nullptr){
        //     if(mpp.contains(mover)==true)return true;
        //     mpp[mover] = count;
        //     mover = mover->next;
        //     count++;
        // }
        // return false;

        //Approach-2
        ListNode* tortoise = head;
        ListNode* hare = head;
        while(hare!=nullptr && hare->next!=nullptr){
            tortoise = tortoise->next;
            hare = hare->next->next; 
             if(hare==tortoise)return true;
        }
        return false;
    }
};