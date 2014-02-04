/*
Construct Binary Tree from Inorder and Postorder Traversal
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
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
 /*
 inorder -- left root right
 postorder -- left right root
 */
/*
Feb 4 2014
Solution:
- the last element of postorder traversal is the root
- the root separate the inorder traversal sequence into left subtree and right subtree
- recursively construct left and right subtree
Note:
handle empty and one node subtree
*/
class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if(inorder.empty() || postorder.empty()) return NULL;
        if (inorder.size() != postorder.size()) return NULL;
        int n = inorder.size();
        return buildSubTree(inorder, postorder, 0, n, 0, n);
    }
    TreeNode *buildSubTree(vector<int> &inorder, vector<int> &postorder, int inorderstart, int inorderend, int postorderstart, int postorderend)
    {
        // empty sub tree
        if (inorderstart == inorderend)
        {
            return NULL;
        }
        // one node sub tree
        TreeNode *newnode = new TreeNode(postorder[postorderend - 1]);
        if (inorderstart == inorderend - 1)
        {
            return newnode;
        }
        int rootPos;
        for (rootPos = inorderstart; rootPos < inorderend; rootPos++)
        {
            if(inorder[rootPos] == postorder[postorderend - 1]) break;
        }
        newnode->left = buildSubTree(inorder, postorder, inorderstart, rootPos, postorderstart, postorderstart + rootPos - inorderstart);
        newnode->right = buildSubTree(inorder, postorder, rootPos+1, inorderend, postorderstart + rootPos - inorderstart, postorderend-1);
        return newnode;
    }
};
