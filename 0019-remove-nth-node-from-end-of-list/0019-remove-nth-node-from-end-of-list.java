/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode currNode = head;
        int size=0;
        while(currNode!=null){
              currNode = currNode.next;
              size++;
        }

        if(n==size){
            return head.next;
        }

        int indextosearch = size-n;
        ListNode prev = head;
        int i=1;
        while(i<indextosearch){
            prev = prev.next;
            i++;
        }
        prev.next = prev.next.next;
        return head;
  
    }
}