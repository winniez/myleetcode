/*
Binary Tree Maximum Path Sum Total Accepted: 5186 Total Submissions: 27364 My Submissions
Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.
*/

/*
JAN 27 2014

Cases:
[1, -2]: return 1, left the leaf node
[-2, 1]: return 1, left the root node
Note: cursum if the value you can append, maxsum stores the the value of max sum up to now, maxsum could be an already finished path and can not be appended/ added.
Reference: http://discuss.leetcode.com/questions/288/binary-tree-maximum-path-sum
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
    int maxPathSum(TreeNode *root) {
        int maxsum = INT_MIN;
        int currsum;
        maxPathSumHelper(root, currsum, maxsum);
        return maxsum;
    }
    void maxPathSumHelper(TreeNode *root, int &currsum, int &maxsum)
    {
        if (!root)
        {
            currsum = 0;
            return;
        }
        int leftsum, rightsum;
        maxPathSumHelper(root->left, leftsum, maxsum);
        maxPathSumHelper(root->right, rightsum, maxsum);
        currsum = max(root->val, max(root->val + leftsum, root->val + rightsum));
        maxsum = max(maxsum, max(currsum, root->val + leftsum + rightsum));
    }
};
