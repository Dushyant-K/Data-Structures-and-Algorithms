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
    ListNode* middleNode(ListNode* head) {
       //Approach-1
    //    ListNode* mover = head;
    //    int count=0;
    //    while(mover!=nullptr){
    //     mover = mover->next;
    //     count++;
    //    }
    //    int midNode = (count/2)+1;
    //    ListNode* temp = head;
    //    while(temp!=nullptr){
    //     midNode--;
    //     if(midNode==0)break;
    //     temp = temp->next;
    //    }
    //    return temp;
       
        // Appraoch-2
        ListNode* tortoise = head;
        ListNode* hare = head;
        while(hare!=nullptr && hare->next!=nullptr){
            tortoise = tortoise->next;
            hare = hare->next->next;
        }
        return tortoise; 
    }
};