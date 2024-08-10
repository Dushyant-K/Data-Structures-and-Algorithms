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
        map<ListNode*,int> mpp;
        ListNode* mover = head;
        int count=0;
        while(mover!=nullptr){
            if(mpp.contains(mover)==true)return true;
            mpp[mover] = count;
            mover = mover->next;
            count++;
        }
        return false;
    }
};