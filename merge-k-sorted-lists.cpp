/*
Merge k Sorted Lists
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
*/

/*
Feb 24 2014
Let N be total number of nodes in K sorted lists.
Solution:
* 1. Similar with merge 2 sorted lists. Maintain a vector of current pointers to k lists. Find the node with minimal value, merge it to the new list and move that pointer to its next. Time O(N*K)
* 2. Call merge 2 sorted list K-1 times. Time O(N*K). The constant coefficient is half of constant coefficient for Solution 1.
* 3. Use min heap to keep track of current samllest node in all lists. (there are k sorted lists, thus the maximum size required for heap is K)

Reference:
http://discuss.leetcode.com/questions/204/merge-k-sorted-lists

C++ stl heap algorithm: http://www.cplusplus.com/reference/algorithm/make_heap/
C++ stl priority queue: http://www.cplusplus.com/reference/queue/priority_queue/
*/

// Solution 1: naive solution O(n*k), n is the total # of nodes in k lists
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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty()) return NULL;
        ListNode *head = NULL, *cur = NULL, *newnode = NULL, *select = NULL;
        int n = lists.size(), cnt = 0, selectindex = 0;
        vector<ListNode *> ptrs;
        for (int i = 0; i < n; i++)
        {
            ptrs.push_back(lists[i]);
            if (lists[i]) cnt++;
        }
        while(cnt)
        {
            cnt = 0;
            select = NULL;
            selectindex = -1;
            for (int i = 0; i < n; i++)
            {
                if (ptrs[i])
                {
                    cnt++;
                    if (!select) 
                    {
                        select = ptrs[i];
                        selectindex = i;
                    }
                    else
                    {
                        if (ptrs[i]->val < select->val) 
                        {
                            select = ptrs[i];
                            selectindex = i;
                        }
                    }
                }
            }
            if(select)
            {
                newnode = new ListNode(select->val);
                if (!head) head = newnode;
                else cur->next = newnode;
                cur = newnode;
                ptrs[selectindex] = ptrs[selectindex]->next;
            }
        }
        return head;
    }
};

// Solution 2, call mergeTwoSortedLists K-1 times
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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty()) return NULL;
        ListNode *head = NULL;
        int n = lists.size();
        head = lists[0];
        for (int i = 1; i < n; i++)
        {
            head = mergeTwoLists(head, lists[i]);
        }
        return head;
    }

// Solution 3: use min heap/ priority queue to keep track of current smallest element
 bool compNodes(ListNode *n1, ListNode *n2)
{
    return n1->val < n2->val ? false: true;
}

ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty()) return NULL;
        ListNode *head = NULL, *cur = NULL, *newnode = NULL, *select = NULL;
        int n = lists.size();
        vector<ListNode *> ptrs;
        for (int i = 0; i < n; i++)
        {
            if (lists[i]) ptrs.push_back(lists[i]);
        }
        make_heap(ptrs.begin(), ptrs.end(), compNodes);
        while(!ptrs.empty())
        {
            select = ptrs.front();
            pop_heap(ptrs.begin(), ptrs.end(), compNodes);
            ptrs.pop_back();

            newnode = new ListNode(select->val);
            if (head) cur->next = newnode;
            else head = newnode;
            cur = newnode;

            if (select->next)
            {
                ptrs.push_back(select->next);
                push_heap(ptrs.begin(), ptrs.end(), compNodes);
            }
        }
        return head;
    }
