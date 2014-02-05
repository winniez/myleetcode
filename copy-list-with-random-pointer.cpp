/*
Copy List with Random Pointer
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
*/

/*
Feb 4 2014
Solution:
Use a map<int, RandomListNode*> to record already created nodes.
Space O(n). Time O(n).
*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return NULL;
        RandomListNode *ptr, *newptr, *ptrrandom, *newptrrandom, *newhead = NULL, *prev = NULL;
        map<int, RandomListNode*> table;
        ptr = head;
        while (ptr)
        {
            if (!table.count(ptr->label))
            {
                newptr = new RandomListNode(ptr->label);
                table[ptr->label] = newptr;
            }
            newptr = table[ptr->label];
            if (!newhead) newhead  = newptr;
            if (ptr->random)
            {
                if (table.count(ptr->random->label))
                {
                    newptr->random = table[ptr->random->label];
                }
                else
                {
                    newptr->random = new RandomListNode(ptr->random->label);
                    table[ptr->random->label] = newptr->random;
                }
            }
            if (prev)
            {
                prev->next = newptr;
            }
            prev = newptr;
            ptr = ptr->next;
        }
        return newhead;
    }
};
