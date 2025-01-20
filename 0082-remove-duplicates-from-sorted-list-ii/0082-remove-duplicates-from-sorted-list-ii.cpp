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
    ListNode* deleteDuplicates(ListNode* head) {
    //Approach-1
    
    // Dummy node to handle edge cases like duplicates at the head
    ListNode* dummy = new ListNode(0, head);
    ListNode* prev = dummy;

    while (head) {
        // If the current node is a duplicate
        if (head->next && head->val == head->next->val) {
            // Skip all nodes with the same value
            while (head->next && head->val == head->next->val) {
                head = head->next;
            }
            // Remove duplicates by skipping them
            prev->next = head->next;
        } else {
            // Move `prev` forward if no duplicate
            prev = prev->next;
        }
        // Move `head` forward
        head = head->next;
    }

    // Return the modified list
    return dummy->next;
    }
};