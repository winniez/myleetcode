/*
Binary Tree Level Order Traversal II
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7]
  [9,20],
  [3],
]
*/
/*
JAN 24 2014
Analysis:
same as Binary Tree Level Order Traversal, reverse the vector berfore return
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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
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
                // use push_back and rtn.reverse(rtn.begin(), rtn.end()) would also be fine 
                //rtn.push_back(level);
                rtn.insert(rtn.begin(), level);
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

