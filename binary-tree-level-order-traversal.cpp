/*
Binary Tree Level Order Traversal
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
*/
/*
JAN 23 2014
Solution: store pointers to nodes in queue, use NULL pointer to separate layers
Time complexity: O(n)
Space complexity: O(log n)
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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > rtn;
        if (!root) return rtn;
        queue<TreeNode*>qLevel;
        vector<int> level;
        qLevel.push(root);
        qLevel.push(NULL);
        TreeNode *ptr;
        while (!qLevel.empty())
        {
            ptr = qLevel.front();
            if(ptr)
            {
                if (ptr->left)
                {qLevel.push(ptr->left);}
                if (ptr->right)
                {qLevel.push(ptr->right);}
                level.push_back(ptr->val);
            }
            else
            {
                rtn.push_back(level);
                level.clear();
                if (qLevel.size()>1)
                {
                    qLevel.push(NULL);
                }
            }
            qLevel.pop();
        }
       return rtn;
    }
};


