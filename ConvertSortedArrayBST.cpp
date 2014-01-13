/*
Convert Sorted Array to Binary Search Tree Total Accepted: 5093 Total Submissions: 15861 My Submissions
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
*/

/*
JAN 12 2014
Solution: recursive
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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return buildTree(num, 0, num.size()-1);
    }
    TreeNode* buildTree(vector<int> &num, int start, int end)
    {
        if (start > end) return NULL;
        int rootIndex = (start + end)/2;
        TreeNode *node = new TreeNode(num[rootIndex]);
        node->left = buildTree(num, start, rootIndex-1);
        node->right = buildTree(num, rootIndex+1, end);
        return node;
    }
};


