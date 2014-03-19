/*
Remove Nth Node From End of List
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
*/
/*
May 18 2014
Solution:
Use 2 pointers ptr1 and ptr2 and scan list, ptr1 first start from head, ptr2 only starts when ptr1 have walked over n steps. When ptr1 reaches the tail, ptr2 will be pointing to the node previous to the one we want to remove.
Note:
When n is size with the size of the list, the head node should be removed and updated. Consider this scenario in the code
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (!head || !n) return head;
        ListNode *ptr1 = head, *ptr2 = head, *nxt = NULL;
        int cnt = 0;
        while(ptr1)
        {
            if (cnt > n) ptr2 = ptr2->next;
            cnt++;
            ptr1 = ptr1->next;
        }
        if (cnt == n)
        {
            ptr2 = ptr2->next;
            delete head;
            head = ptr2;
        }
        else
        {
            nxt = ptr2->next->next;
            delete ptr2->next;
            ptr2->next = nxt;
        }
        return head;
    }
};
