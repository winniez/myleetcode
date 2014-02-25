/*
Merge Two Sorted Lists Total
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
*/
/*
Feb 24 2014
Note:
Initialize pointers to NULL!!!
*/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    };

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode *head=NULL, *cur=NULL, *newnode=NULL, *ptr1 = l1, *ptr2 = l2;
        while (ptr1 || ptr2)
        {
            if (!ptr2)
            {
                newnode = new ListNode(ptr1->val);
                ptr1 = ptr1->next;
            }
            else if (!ptr1)
            {
                newnode = new ListNode(ptr2->val);
                ptr2 = ptr2->next;
            }
            else
            {
                if (ptr1->val < ptr2->val)
                {
                    newnode = new ListNode(ptr1->val);
                    ptr1 = ptr1->next;
                }
                else
                {
                    newnode = new ListNode(ptr2->val);
                    ptr2 = ptr2->next;
                }
            }
            if (!head)
            {
                head = newnode;
            }
            else
            {
                cur->next = newnode;
            }
            cur = newnode;
        }
        return head;
    }
};

int main()
{
    Solution s;
    ListNode *l1, *l2, *l3, *ptr;
    l1 = new ListNode(2);
    l2 = new ListNode(1);
    l3 = s.mergeTwoLists(l1,l2);
    ptr = l3;
    while(ptr)
    {
        cout<<ptr->val<<" ";
        ptr = ptr->next;
    }
    cout<<endl;
}
