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
    bool isPalindrome(ListNode* head) {
        //Approach-1
        stack<int> st;
        ListNode* mover = head;
        while(mover!=nullptr){
            st.push(mover->val);
            mover = mover->next;
        }

        mover = head;
        while(mover!=nullptr){
            if(mover->val!=st.top())return false;
            st.pop();
            mover = mover->next;
        }
        return true;
    }
};