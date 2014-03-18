/*
Reorder List
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
*/

/*
Mar 18 2014
Solution:
- cut linked list into 1st half and 2nd half;
- reverse 2nd half;
- merge 2 list in order.
Note:
- place NULL to the end of 1st half after cutting
- place NULL to the original head->next for reverse, otherwise it is a cyclic linked list!
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
    void reorderList(ListNode *head) {
        if (!head) return;
        int size = 0;
        ListNode* ptr = head;
        while(ptr)
        {
            size++;
            ptr = ptr->next;
        }
        int indexsum = size-1;
        int mid = indexsum/2;
        ptr = head;
        int cnt = 0;
        while(ptr)
        {
            if (cnt == mid) break;
            cnt++;
            ptr = ptr->next;
        }
        // cut into 2 lists
        ListNode *h2 = ptr->next;
        ptr->next = NULL;
        // reverse 2nd list
        h2 = reverseList(h2);
        // merge 2 list
        ListNode *ptr1 = head, *ptr2 = h2, *ptr1next = NULL, *ptr2next = NULL;
        while(ptr1 && ptr2)
        {
            ptr1next = ptr1->next;
            ptr2next = ptr2->next;
            ptr1->next = ptr2;
            ptr2->next = ptr1next;
            ptr1 = ptr1next;
            ptr2 = ptr2next;
        }
        return;
    }

    ListNode *reverseList(ListNode* head)
    {
        if (!head) return NULL;
        ListNode *cur = head, *nxt = head->next, *tmp = NULL;
        while (nxt)
        {
            tmp = nxt->next;
            nxt->next = cur;
            if (cur == head) cur->next = NULL;
            cur = nxt;
            nxt = tmp;
        }
        return cur;
    }
};
