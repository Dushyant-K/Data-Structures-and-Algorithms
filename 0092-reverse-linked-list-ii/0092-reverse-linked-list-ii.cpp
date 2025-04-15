class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int> arr;
        ListNode* temp = head;

        // \U0001f4e5 Step 1: Store values in vector
        while (temp) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        // \U0001f504 Step 2: Reverse the sublist
        reverse(arr.begin() + left - 1, arr.begin() + right);

        // \U0001f4e4 Step 3: Update linked list with reversed values
        temp = head;
        int index = 0;
        while (temp) {
            temp->val = arr[index++];
            temp = temp->next;
        }

        return head;
    }
};