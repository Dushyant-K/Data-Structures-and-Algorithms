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
    ListNode* merge(ListNode* head1, ListNode* head2){
        ListNode* dummy = new ListNode(-1);
        ListNode* newHead=dummy;

        while(head1&&head2){
            if(head1->val<=head2->val){
                dummy->next=head1;
                dummy=head1;
                head1=head1->next;
            }else{
                dummy->next=head2;
                dummy=head2;
                head2=head2->next;
            }
        }
        while(head1){
            dummy->next=head1;
            dummy=head1;
            head1=head1->next;
        }
        while(head2){
            dummy->next=head2;
            dummy=head2;
            head2=head2->next;
        }
        return newHead->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //Approach-1
        if(lists.size()==0)return nullptr;
        if(lists.size()==1)return lists[0];

        ListNode* temp = merge(lists[0],lists[1]);
        int n=lists.size();

        for(int i=2;i<n;i++){
            temp=merge(temp,lists[i]);
        }
        return temp;
    }
};