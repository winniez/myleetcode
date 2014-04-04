/*
Reverse Linked List II
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
*/

/*
Apr 4 2014
Solution:
- scan list to (m-1)th element, cut the list;
- scan the 2nd list from (m+1) till n, append cur node to the head of reversed list head
- concatenate 1 st list, reversed list and remaining list.
Note:
Use a virtual newhead in case of m = 1 and need to change head.
Time O(n), space constant.
*/

#include <iostream>
#include <vector>

using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (!head) return head;
        ListNode *newhead = new ListNode(0);
        newhead->next = head;
        int cnt = 0;
        ListNode* cur = newhead, *prev = NULL, *next = NULL, *firsttail = NULL, *secondhead = NULL, *secondtail = NULL;
        while(cnt < m)
        {
            cnt++;
            prev = cur;
            cur = cur->next;
        }
        firsttail = prev;
        secondtail = cur;
        secondhead = cur;
        next = cur->next;
        while(cnt < n)
        {
            cnt++;
            cur = next;
            next = next->next;
            cur->next = secondhead;
            secondhead = cur;
        }
        firsttail->next = secondhead;
        secondtail->next = next;
        return newhead->next;
    }
};

int main()
{
    ListNode *head = new ListNode(5);
    Solution s;
    ListNode *newhead = s.reverseBetween(head, 1, 1);
    ListNode *ptr = newhead;
    while(ptr)
    {
        cout<<ptr->val<<"->";
    }
    cout<<"NULL\n";
}
