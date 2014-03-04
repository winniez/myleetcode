/*
Rotate List Total Accepted: 6074 Total Submissions: 28182 My Submissions
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
*/
/*
Mar 3 2014
Solution:
- get the length of input list
- check and mod k (handle k >= len(list))
- scan array to (len-k-1), cur the list, move the right part to the left head.
- appen 2 lists, return new head.
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
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head) return head;
        ListNode *ptr = head, *newhead = NULL;
        int cnt = 0, len = 0;
        while(ptr)
        {
            ptr = ptr->next;
            len++;
        }
        if (k >= len) k = k %len;
        if (!k) return head;
        ptr = head;
        while(ptr)
        {
            if (cnt == len-k-1) break;
            cnt++;
            ptr = ptr->next;
        }
        newhead = ptr->next;
        ptr->next = NULL;
        ptr = newhead;
        while(ptr->next)
        {
            ptr = ptr->next;
        }
        ptr->next = head;
        return newhead;
    }
};

