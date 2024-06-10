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

    public static ListNode findmiddle(ListNode head){
       
       ListNode hare = head;
       ListNode turtle = head;
       while(hare.next!=null&&hare.next.next!=null){
        hare =hare.next.next;
        turtle=turtle.next;
       }
       return turtle;
    }

    public static ListNode reverseLL(ListNode head){
        if(head.next==null){
            return head;
        }
        ListNode newheadNode = reverseLL(head.next);
        ListNode currNode=head;
        currNode.next.next=currNode;
        currNode.next=null;
        return newheadNode;
    }
    public boolean isPalindrome(ListNode head) {
        if(head==null || head.next==null){
           return true;
        }
         
         ListNode firsthalfend=findmiddle(head);
         ListNode secondhalfstart=reverseLL(firsthalfend.next);

        ListNode start=head;
         while(secondhalfstart!=null){
            if(start.val!=secondhalfstart.val){
                return false;
            }
            start=start.next;
            secondhalfstart=secondhalfstart.next;
         }

         return true;
    }
}