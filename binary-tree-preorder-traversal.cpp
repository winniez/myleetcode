/*
Binary Tree Preorder Traversal
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?
*/

/*
JAN 15 2014
Solutions:
-- Recursive
-- Iterative: stack, push root -> while (stack not empty) {read stack top as ptr -> pop -> push ptr right child if not empty -> push ptr left child if not empty}
Reference: http://www.geeksforgeeks.org/iterative-preorder-traversal/
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
    vector<int> preorderTraversal(TreeNode *root) {
        stack<TreeNode*> traverse;
        vector<int> preorder;
        if (!root) return preorder;
        TreeNode *ptr;
        traverse.push(root);
        while(!traverse.empty())
        {
            ptr = traverse.top();
            preorder.push_back(ptr->val);
            traverse.pop();
            // first in, last out
            if (ptr->right)
            {traverse.push(ptr->right);}
            if (ptr->left)
            {traverse.push(ptr->left);}
        }
        return preorder;
    }

    //recursive
    /*
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> preorder;
        recursive(preorder, root);
        return preorder;
    }
    void recursive(vector<int> &preorder, TreeNode *root)
    {
        if (!root) return;
        preorder.push_back(root->val);
        recursive(preorder, root->left);
        recursive(preorder, root->right);
    }
    */
};
