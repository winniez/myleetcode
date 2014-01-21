/*
Remove Duplicates from Sorted List II
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/
/*
JAN 20 2014
Note the situation when head is deleted. And use lasttail to remember the tail of already processed linked list. (newhead, lasttail & duplicate flag)
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
    ListNode *deleteDuplicates(ListNode *head) {
         ListNode *ptr, *nextnode, *lasttail, *newhead;
        if (!head) return head;
        ptr = head;
        nextnode = ptr->next;
        lasttail = NULL;
        newhead = head;
        bool duplicate;
        while(ptr && nextnode)
        {
            duplicate = false;
            while (ptr->val == nextnode->val)
            {
                duplicate = true;
                ptr->next = nextnode->next;
                delete nextnode;
                if (!ptr->next) break;
                nextnode = ptr->next;
            }
            if (duplicate)
            {
                if (ptr == newhead)
                {
                    newhead = ptr->next;
                }
                if (lasttail)
                {
                    lasttail->next = ptr->next;
                }
                nextnode = ptr->next;
                delete ptr;
                ptr = nextnode;
            }
            else
            {
                lasttail = ptr;
                ptr = ptr->next;
            }
            if (ptr) nextnode = ptr->next;
            else nextnode = NULL;
        }
        return newhead;
    }
};
