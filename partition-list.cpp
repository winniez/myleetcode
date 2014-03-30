/*
Partition List
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
*/

/*
Mar 30 2014
Solution:
The idea is to split input list into 2 lists. Delete nodes less than x from the 2nd list and append nodes to the end of 1st list.
Start from head, find the first node no less than x. Set it as the partition node (start of 2nd node).
Start from partition node, delete nodes less than x from the 2nd list and append to the end of 1st list.
Append 1st and 2nd list. Return head. (head could be changed).
Note cases:
- x is less than anyone in the list
- x is no less than anyone in the list
- After partition, 1st list is empty, new head, new 1st list tail.

Time O(n), space constant.
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
    ListNode *partition(ListNode *head, int x) {
        if (!head) return NULL;
        ListNode *firstTail = NULL, *ptr = head, *prev = NULL, *secondhead = NULL;
        while(ptr)
        {
            if (ptr->val >= x) break;
            prev = ptr;
            ptr = ptr->next;
        }
        // x is less than anyone in the list
        if (!ptr) return head;
        if (prev) firstTail = prev;
        secondhead = ptr;
        while(ptr)
        {
            if (ptr->val < x)
            {
                if (firstTail)
                {
                    firstTail->next = ptr;
                }
                else
                {
                    head = ptr;
                }
                firstTail = ptr;
                prev->next = ptr->next;
            }
            else
            {
                prev = ptr;
            }
            ptr = ptr->next;
        }
        if (firstTail) firstTail->next = secondhead;
        return head;
    }
};


