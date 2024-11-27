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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

    TreeNode* buildTree(int low, int high, ListNode* head){
        if(low>high)return nullptr;

        int mid=(low+high)/2;
        TreeNode* root = buildTreeHelper(head,mid);
        root->left=buildTree(low,mid-1,head);
        root->right=buildTree(mid+1,high,head);
        return root;
    }
    TreeNode* buildTreeHelper(ListNode* head, int mid){
        int count=0;
        while(head!=nullptr){
            count++;
            if(count==mid){
                if(head==nullptr)return nullptr;
                TreeNode* root=new TreeNode(head->val);
                return root;
            }
            head=head->next;
        }
       return nullptr;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==nullptr)return nullptr;
        int length=0;
        ListNode* dummy=head;
        while(dummy!=nullptr){
            dummy=dummy->next;
            length++;
        }

        return buildTree(1,length,head);
    }
};