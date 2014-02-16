/*
Linked List Cycle II
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Follow up:
Can you solve it without using extra space?
*/

/*
Feb 15 2014
Solution:
Use slow and fast pointer to detect loop.
Let head be X, start of loop be Y, the node where fast and slow pointer meets be Z.
Let a = X->Y, b = Y->Z, c = Z->Y.
When fast and slow pointer first met, fast pointer travels a+b+c+b, slow pointer travels a+b. + Fast pointer travels twice distance as slow pointer.

a+b+c+b = 2*(a+b) => a = c.

Now let a pointer start from head, another pointer start from Z, both pointer travels at same speed and they will meet at Y.

Reference:
http://www.cnblogs.com/hiddenfox/p/3408931.html
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
    ListNode *detectCycle(ListNode *head) {
        if (!head) return NULL;
        if (!head->next) return NULL;
        ListNode *slow = head, *fast = head;
        int cnts = 0, cntf = 0, flag = 0;
        while(fast)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast)
            {
                fast = fast->next;
            }
            if (fast == slow)
            {
                flag = 1;
                break;
            }
        }
        if (flag)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
        else return NULL;
    }
};

