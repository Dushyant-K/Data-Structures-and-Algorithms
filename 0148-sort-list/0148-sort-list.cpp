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
    ListNode* merge2(ListNode* list1, ListNode* list2){
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;
        while(list1!=nullptr && list2!=nullptr){
            if(list1->val <=list2->val){
                temp->next = list1;
                temp = list1;
                list1 = list1->next;
            }
            else{
                temp->next = list2;
                temp = list2;
                list2=list2->next;
            }
        }
        if(list1){ 
            temp->next=list1;
            }
        else {
            temp->next=list2;
            }
        return dummyNode->next;

    }
    ListNode* findMiddle(ListNode* head){
        ListNode* tortoise = head;
        ListNode* hare = head->next;
        while(hare!= nullptr && hare->next!=nullptr){
            tortoise = tortoise->next;
            hare = hare->next->next;
        }
        return tortoise;
    }
    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr)return head;

        ListNode* middle = findMiddle(head);
        ListNode* right = middle->next;
        middle->next = nullptr;
        ListNode* left = head;
        left=sortList(left);
        right=sortList(right);

        return merge2(left,right);
    }
};