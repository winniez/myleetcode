/*
Remove Duplicates from Sorted List
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/
/*
JAN 20 2014
Note the 2nd while condition.
Consider 3->3->3->4, w/o 2nd while condition, the program delete 2nd 3 but leave 3rd 3.
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
        ListNode *ptr, *nextnode;
        if (!head) return head;
        ptr = head;
        nextnode = ptr->next;
        while(ptr && nextnode)
        {
            while (ptr->val == nextnode->val)
            {
                ptr->next = nextnode->next;
                delete nextnode;
                if (!ptr->next) break;
                nextnode = ptr->next;
            }
            ptr = ptr->next;
            if (ptr) nextnode = ptr->next;
        }
        return head;
    }
};
