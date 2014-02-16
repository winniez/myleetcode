/*
Linked List Cycle
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
*/

/*
Feb 15 2014
Solution:
maintain a slow and fast pointer, traverse the linked list and check if the 2 pointers points at same node.
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
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        if (!head->next) return false;
        ListNode *fast = head, *slow = head;
        while(fast)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast)
            {
                fast = fast->next;
            }
            if (fast == slow) return true;
        }
        return false;
    }
};
