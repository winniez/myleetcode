/*
Flatten Binary Tree to Linked List
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
click to show hints.

Hints:
If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.
*/

/*
JAN 16 2014
Solution: Recursive
2 solutions:
-- record right child, root->right = left, append right child to the current most right, flatten root->right
-- record right child, flatten left sub-tree, apped left sub tree, trace to the current most right, flatten root's right sub-tree, append.
Reference:
http://discuss.leetcode.com/questions/280/flatten-binary-tree-to-linked-list
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
    void flatten(TreeNode *root) {
        /*
        if (!root) return;
        TreeNode *leftchild = root->left;
        TreeNode *rightchild = root->right;
        if (leftchild)
        {
            root->right = leftchild;
            root->left = NULL;
            TreeNode *cur = root;
            while(cur->right)
            {
                cur = cur->right;
            }
            cur->right = rightchild;
        }
        flatten(root->right);
        */
        recursiveflatten(root);
    }
    TreeNode *recursiveflatten(TreeNode *root)
    {
        if (!root) return NULL;
        TreeNode *rightchild = root->right;
        TreeNode *tmp = NULL;
        tmp = recursiveflatten(root->left);
        root->right = tmp;
        root->left = NULL;
        TreeNode *cur = root;
        while(cur->right)
        {
            cur = cur->right;
        }
        cur->right = recursiveflatten(rightchild);
        return root;
    }
};

