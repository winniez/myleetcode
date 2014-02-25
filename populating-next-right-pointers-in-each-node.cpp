/*
Populating Next Right Pointers in Each Node
Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
*/
/*
Feb 24 2014
Solution:
- BFS tree
- use queue to store nodes
- push a NULL pointer to separate layers
- next pointer assigned to the next element in queue (the NULL separate is useful here :))
- do not push NULL separator when the qeue just pop out a NULL separator and the queue is now empty
Assume the height of tree is H.
Time O(2^(H+1)), space O(2^H).
*/
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        queue<TreeLinkNode*> q;
        q.push(root);
        q.push(NULL);
        TreeLinkNode *ptr = q.front();
        while(!q.empty())
        {
            ptr = q.front();
            q.pop();
            if (ptr)
            {
                ptr->next = q.front();
                if (ptr->left) q.push(ptr->left);
                if (ptr->right) q.push(ptr->right);
            }
            else
            {
                if (!q.empty()) q.push(NULL);
            }
        }
    }
};
