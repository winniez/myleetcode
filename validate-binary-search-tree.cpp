/*
Validate Binary Search Tree
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
*/
/*
Mar 3 2014
Solution:
Inorder traversal and then validate if the inorder traversal is a sorted array.
Note:
Ask if the BST follow strict order or allow less or equal than, larger or equal than.
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
    bool isValidBST(TreeNode *root) {
        if (!root) return true;
        vector<int> inorder;
        inOrder(root, inorder);
        for (int i = 0; i < inorder.size()-1; i++)
        {
            if (inorder[i] >= inorder[i+1]) return false;
        }
        return true;
    }
    void inOrder(TreeNode *root, vector<int> &inorder)
    {
        if (!root) return;
        inOrder(root->left, inorder);
        inorder.push_back(root->val);
        inOrder(root->right, inorder);
    }
};
