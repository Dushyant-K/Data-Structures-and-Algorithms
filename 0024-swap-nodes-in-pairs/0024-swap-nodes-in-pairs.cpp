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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        // Create a dummy node to simplify the swap logic
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        while (prev->next && prev->next->next) {
            // Identify the nodes to be swapped
            ListNode* first = prev->next;
            ListNode* second = prev->next->next;

            // Perform the swap
            first->next = second->next;
            second->next = first;
            prev->next = second;

            // Move to the next pair
            prev = first;
        }

        return dummy.next;
    }
};