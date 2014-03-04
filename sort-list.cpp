/*
Sort List
Sort a linked list in O(n log n) time using constant space complexity.
*/

/*
Solution:
Recursively merge sort.
Keys for solving the problem:
- Break the list to two in the middle
- Recursively sort the two sub lists
- Merge the two sub lists
Note: insertion sort is O(n^2).
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
    ListNode *sortList(ListNode *head) {
        if (!head) return NULL;
        if (!head->next) return head;
        int len = 0;
        ListNode *ptr = head, *lh, *rh, *newhead;
        while(ptr)
        {
            len++;
            ptr = ptr->next;
        }
        ptr = head;
        for (int i = 0; i < len/2-1; i++)
        {
            ptr = ptr->next;
        }
        rh = sortList(ptr->next);
        ptr->next = NULL;
        lh = sortList(head);
        // merge
        newhead = merge2SortedList(lh, rh);
        return newhead;
    }
    ListNode *merge2SortedList(ListNode *l1, ListNode *l2)
    {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode *head=NULL, *cur=NULL, *ptr1 = l1, *ptr2 = l2;
        while(ptr1 && ptr2)
        {
            if (ptr1->val < ptr2->val)
            {
                if (!head)
                {
                    head = ptr1;
                    cur = head;
                }
                else
                {
                    cur->next = ptr1;
                    cur = cur->next;
                }
                ptr1 = ptr1->next;
            }
            else
            {
                if (!head)
                {
                    head = ptr2;
                    cur = head;
                }
                else
                {
                    cur->next = ptr2;
                    cur = cur->next;
                }
                ptr2 = ptr2->next;
            }
        }
        if (ptr1) cur->next = ptr1;
        if (ptr2) cur->next = ptr2;
        return head;
    }
};
