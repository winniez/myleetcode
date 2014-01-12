/*
Maximum Depth of Binary Tree Total Accepted: 7323 Total Submissions: 16231 My Submissions
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/

/*
JAN 12 2014
Note:
return (1 + maxDepth(root->left)) > (1 + maxDepth(root->right)) ? (1 + maxDepth(root->left)):(1 + maxDepth(root->right));
will double the number of times maxDepth is called.
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
    int maxDepth(TreeNode *root) {
        if (!root) return 0;
        int ld = maxDepth(root->left);
        int rd = maxDepth(root->right);
        return ld > rd ? (1 + ld):(1 + rd);
    }
};
