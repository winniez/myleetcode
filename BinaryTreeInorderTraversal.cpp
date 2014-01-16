/*
Binary Tree Inorder Traversal
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?
*/

/*
JAN 15 2014
-- Recursive
-- Iterative: use stack; pop and print when left child is empty, then push right child into stack;
Reference: http://leetcode.com/2010/04/binary-search-tree-in-order-traversal.html
http://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/

TODO fix the commented code.
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
// iterative
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> inorder;
        if (!root) return inorder;
        stack<TreeNode*> traverse;
        TreeNode *ptr = root;
        //traverse.push(ptr);
        
        while (!traverse.empty() || ptr)
        {
            if (ptr)
            {
                traverse.push(ptr);
                ptr = ptr->left;
            }
            else
            {
                ptr = traverse.top();
                traverse.pop();
                inorder.push_back(ptr->val);
                ptr = ptr->right;
            }
        }
        /*
        while(!traverse.empty())
        {
            if (ptr->left)
            {
                traverse.push(ptr->left);
            }
            else
            {
                inorder.push_back(ptr->val);
                traverse.pop();
                if (ptr->right)
                {
                    traverse.push(ptr->right);
                } 
            }
            if (!traverse.empty())
            {ptr = traverse.top();}
        }
        */
        return inorder;
    }
};
