/*
Insertion Sort List
Sort a linked list using insertion sort.
*/

/*
Feb 12 2014
Insertion sort http://en.wikipedia.org/wiki/Insertion_sort
Note:
if we find the next node in smaller and moved it, we should not update the current pointer then, since the next node is a new node.
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
    ListNode *insertionSortList(ListNode *head) {
        if (!head) return NULL;
        ListNode *ptr, *find, *tmp;
        ptr = head; 
        while(ptr->next)
        {
            if (ptr->next->val < ptr->val)
            {
                find = head;
                if (ptr->next->val < head->val)
                {
                    tmp = ptr->next;
                    ptr->next = tmp->next;
                    tmp->next = head;
                    head = tmp;
                }
                else
                {
                    while(find->next->val < ptr->next->val)
                    {
                        find = find->next;
                    }
                    tmp = ptr->next;
                    ptr->next = tmp->next;
                    tmp->next = find->next;
                    find->next = tmp;
                }
            }
            else
            {
                ptr = ptr->next;
            }
        }
        return head;
    }
};
