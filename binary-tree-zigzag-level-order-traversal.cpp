/*
Binary Tree Zigzag Level Order Traversal Total Accepted: 4057 Total Submissions: 15669 My Submissions
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
*/

/*
JAN 27 2014
Solution:
-- use 2 stacks
-- note right node is pushed into s2 before left node, for s1 the order is reversed
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > rtn;
        if (!root) return rtn;
        vector<int> layer;
        stack<TreeNode*> s1;
        stack<TreeNode*>s2;
        TreeNode* ptr;
        s1.push(root);
        while(!s1.empty() || !s2.empty())
        {
            if (s1.empty())
            {
                layer.clear();
                while(!s2.empty())
                {
                    ptr = s2.top();
                    layer.push_back(ptr->val);
                    if (ptr->right)
                    {s1.push(ptr->right);}
                    if (ptr->left)
                    {s1.push(ptr->left);}
                    s2.pop();
                }
                rtn.push_back(layer);
            }
            else
            {
                layer.clear();
                while(!s1.empty())
                {
                    ptr = s1.top();
                    layer.push_back(ptr->val);
                    if (ptr->left)
                    {s2.push(ptr->left);}
                    if (ptr->right)
                    {s2.push(ptr->right);}
                    s1.pop();
                }
                rtn.push_back(layer);
            }
        }
        return rtn;
    }
};
