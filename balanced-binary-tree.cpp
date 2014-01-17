/*
Balanced Binary Tree
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
*/

/*
JAN 17 2014
Solution: recursive
TODO iterative
Note: diff of the height of 2 sub-trees, not the diff of hightest tree & lowest tree
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
/*
recursive
*/
    bool isBalanced(TreeNode *root) {
        if (!root) return true;
         int lh = 0, rh = INT_MAX, h = 0;
         //maxh = maxHeight(root);
         //minh = minHeight(root);
         lh = maxHeight(root->left);
         rh = maxHeight(root->right);
         return isBalanced(root->left) && isBalanced(root->right) && (abs(lh-rh)<2);
    }
    int minHeight(TreeNode *root)
    {
        if (!root) return 0;
        int ll = 1 + minHeight(root->left);
        int lr = 1 + minHeight(root->right);
        return ll < lr?ll:lr;
    }
    int maxHeight(TreeNode *root)
    {
        if (!root) return 0;
        int ll = 1 + maxHeight(root->left);
        int lr = 1 + maxHeight(root->right);
        return ll > lr?ll:lr;
    }
};
