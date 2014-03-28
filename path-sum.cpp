/*
Path Suma
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
*/
/*
Mar 28 2014
Solution:
* recursive dfs
* iterative bfs
Note:
input {}, 0 will produce output false
Time: O(n) n is total number of nodes in tree, O(logn) for recursive solution, O(n/2) for iterative solution.
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
// recursive Solution
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (!root) return false;
        if (!root->left && !root->right && root->val == sum) return true;
        return (hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val));
    }
};

// iterative solution
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (!root) return false;
        queue<TreeNode *> nodes;
        queue<int> cursum;
        nodes.push(root);
        cursum.push(root->val);
        TreeNode *cur;
        int tmpsum;
        while(!nodes.empty())
        {
            cur = nodes.front();
            nodes.pop();
            tmpsum = cursum.front();
            cursum.pop();
            if (!cur->left && !cur->right && tmpsum == sum)
            {return true;}
            if (cur->left)
            {
                nodes.push(cur->left);
                cursum.push(tmpsum+cur->left->val);
            }
            if (cur->right)
            {
                nodes.push(cur->right);
                cursum.push(tmpsum+cur->right->val);
            }
        }
        return false;
    }
};
