/*
Add Two Numbers
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

/*
JAN 17 2014
Analysis:
As the digits are stored in the reverse order, the problem is easy. Handle the carry.
Note:
Check the input digit before creating a 0 next node for sum. When both digits are 0 and there's no carry, there's no need for a 0 next node.
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if ((!l1) && (!l2)) return NULL;
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode *ptr1, *ptr2, *cur, *head;
        ptr1 = l1;
        ptr2 = l2;
        cur = new ListNode(0);
        head = cur;
        int sum;
        while (ptr1 || ptr2)
        {
            sum = cur->val;
            if (ptr1)
            {
                sum += ptr1->val;
                ptr1 = ptr1->next;
            }
            if (ptr2)
            {
                sum += ptr2->val;
                ptr2 = ptr2->next;
            }
            cur->val = sum % 10;
            if (sum>=10)
            {
                cur->next = new ListNode(1);
            }
            else
            {
                if (ptr1 || ptr2)
                {
                    cur->next = new ListNode(0);
                }
            }
            cur = cur->next;
        }
        return head;
    }
};
