/*
Swap Nodes in Pairs
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/

/*
JAN 20 2014
Note: the lasttail pointer. Need to remember the tail of already tailored linked list
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
    ListNode *swapPairs(ListNode *head) {
        ListNode *ptr1, *ptr2, *nexthead, *newhead, *lasttail;
        if (!head) return head;
        ptr1 = head;
        ptr2 = head->next;
        if (!ptr2) return head;
        newhead = ptr2;
        lasttail = NULL;
        while (ptr1 && ptr2)
        {
            nexthead = ptr2->next;
            ptr1->next = nexthead;
            ptr2->next = ptr1;
            if (lasttail)
            {
                lasttail->next = ptr2;
            }
            lasttail = ptr1;
            ptr1 = ptr1->next;
            if (ptr1) 
            {ptr2 = ptr1->next;}
            else 
            {ptr2 = NULL;}
        }
        return newhead;
    }
};
