/*
Convert Sorted List to Binary Search Tree
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*/

/*
JAN 13 2014
Top Down solution
Find the middle one for each sub linked-list.
Time complexity -- O(n^2)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if (!head) return NULL;
        if (!head->next)
        {
            return new TreeNode(head->val);
        }
        // first find the middle one
        ListNode *singleStep, *doubleStep, *tmp;
        singleStep = head;
        doubleStep = head;
        tmp = NULL;
        while(doubleStep->next)
        {
            tmp = singleStep;
            singleStep = singleStep->next;
            doubleStep = doubleStep->next;
            if (doubleStep->next)
            {
                doubleStep = doubleStep->next;
            }
        }
        tmp->next = NULL;
        TreeNode* root = new TreeNode(singleStep->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(singleStep->next);
        return root;
    }
};

/*
Bottom Up Solution
Time Complexity -- O(n)
Reference: https://github.com/starcroce/leetcode
*/

class Solution {
public:
    // bottom-up solution
    TreeNode *sortedListToBST(ListNode *head) {
        int len = 0;
        ListNode *p = head;
        while(p != NULL) {
            len++;
            p = p->next;
        }
        return sortedListToBST(head, 0, len-1);
    }
    TreeNode *sortedListToBST(ListNode *&node, int start, int end) {
        if(start > end) {
            return NULL;
        }
        int middle = (start + end) / 2;
        // any continuous 3 list nodes are leftChild, root, rightChild
        // get these 3 nodes in recursive way
        TreeNode *leftChild = sortedListToBST(node, start, middle-1);
        TreeNode *root = new TreeNode(node->val);
        root->left = leftChild;
        // current node is root, so move to the next node to get the right child
        node = node->next;
        TreeNode *rightChild = sortedListToBST(node, middle+1, end);
        root->right = rightChild;
        return root;
    }
};

