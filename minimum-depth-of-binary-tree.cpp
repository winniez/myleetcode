/*
Minimum Depth of Binary Tree
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
*/
/*
Feb 25 2014
To find the length of shortest path from the root node down to the nearest leaf node. The depth must be calculated from a leaf node. A node with only left or only right child is not a leaf node.
For a parent node with both children, we select the shorter path.
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
    int minDepth(TreeNode *root) {
        if (!root) return 0;
        int ld = minDepth(root->left);
        int rd = minDepth(root->right);
        if (ld == 0 ) return rd+1;
        if (rd == 0 ) return ld+1;
        if (ld < rd) return ld+1;
        else return rd+1;
    }
};

