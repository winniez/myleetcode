/*
Construct Binary Tree from Preorder and Inorder Traversal
Given preorder and inorder traversal of a tree, construct the binary tree.
Note:
You may assume that duplicates do not exist in the tree.
*/

/*
Feb 4 2014
- the first element of preorder traversal is the root
- the root separate the inorder traversal sequence into left subtree and right subtree
- recursively construct left and right subtree
Note:
handle empty and one node subtree
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
 preorder -- root left right
 inorder -- left root right
 */
class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.size() != inorder.size()) return NULL;
        int n = preorder.size();
        return buildSubTree(preorder, inorder, 0, n, 0, n);
    }

    TreeNode *buildSubTree(vector<int> &preorder, vector<int> &inorder, int preorderstart, int preorderend, int inorderstart, int inorderend)
    {
        if (preorderstart == preorderend) return NULL;
        TreeNode *newnode = new TreeNode(preorder[preorderstart]);
        if (preorderstart == preorderend - 1)  return newnode;
        int rootPos;
        for (rootPos = inorderstart; rootPos < inorderend; rootPos++)
        {
            if (inorder[rootPos] == preorder[preorderstart]) break;
        }
        newnode->left = buildSubTree(preorder, inorder, preorderstart + 1, preorderstart + rootPos - inorderstart + 1, inorderstart, rootPos);
        newnode->right = buildSubTree(preorder, inorder, preorderstart + rootPos - inorderstart + 1, preorderend, rootPos + 1, inorderend);
        return newnode;
    }
};
