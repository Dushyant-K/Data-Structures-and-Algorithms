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
    private:
    ListNode* dummy;
public:
    Solution(ListNode* head) {
        dummy = head;
        srand(time(0));
    }
    
    int getRandom() {
        int result=dummy->val;
        ListNode* curr = dummy->next;
        int i=2;
        while(curr){
            if(rand()%i==0)result=curr->val;
            curr=curr->next;
            i++;
        }
        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */