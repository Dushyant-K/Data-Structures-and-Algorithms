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
    void reverseLL(ListNode* head){
        ListNode* temp = head;
        ListNode*prev = nullptr;
        while(temp!=nullptr){
            head = head->next;
            temp->next = prev;
            prev = temp;
            temp = head;
        }
    }
    ListNode* getKthNode(ListNode* temp, int k){
        k--;
        while(temp!=nullptr&&k>0){
            k--;
            temp = temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        // ListNode* temp = head;
        // ListNode* prevLast = nullptr;
        // while(temp!=nullptr){
        //     ListNode* kNode = getKthNode(temp,k);
        //     if(kNode==nullptr){
        //         if(prevLast)prevLast->next = temp;
        //         break;
        //     }
        //     ListNode* nextNode = kNode->next;
        //     kNode->next = nullptr;
        //     reverseLL(temp);
        //     if(head==temp)
        //     { head = kNode;
        //     }
        //     else  {
        //      prevLast->next = nextNode;
        //     }
        //     prevLast = temp;
        //     temp = nextNode;
        // }
        // return head;

        if (!head || k == 1) return head;

        // Dummy node initialization
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Initialize pointers
        ListNode* curr = dummy, *prev = dummy, *next = dummy;
        int count = 0;
        ListNode* temp = head;

        // Count the number of nodes in the list
        while (temp) {
            count++;
            temp = temp->next;
        }

        // Main loop to reverse k nodes at a time
        while (count >= k) {
            curr = prev->next;
            next = curr->next;
            // Reverse k nodes
            for (int i = 1; i < k; ++i) {
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
                next = curr->next;
            }
            prev = curr;
            count -= k;
        }

        return dummy->next;
    }
};