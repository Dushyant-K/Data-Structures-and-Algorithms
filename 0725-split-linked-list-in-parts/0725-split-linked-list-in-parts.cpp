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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        // Calculate the length of the list
        int length = 0;
        ListNode* current = head;
        while (current != nullptr) {
            length++;
            current = current->next;
        }

        // Calculate the size of each part and the remainder
        int partSize = length / k;
        int extra = length % k;

        vector<ListNode*> ans(k, nullptr);
        current = head;

        for (int i = 0; i < k; i++) {
            if (current == nullptr) {
                ans[i] = nullptr; // If no nodes are left, assign nullptr
                continue;
            }

            ans[i] = current; // The start of the current part
            int currentPartSize = partSize + (extra > 0 ? 1 : 0); // Add an extra node if needed
            extra--;

            // Traverse the current part
            for (int j = 1; j < currentPartSize; j++) {
                current = current->next;
            }

            // Break the link to the next part
            ListNode* next = current->next;
            current->next = nullptr;
            current = next;
        }

        return ans;
    }
};