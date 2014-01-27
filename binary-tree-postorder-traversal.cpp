/*
Binary Tree Postorder Traversal Total Accepted: 6703 Total Submissions: 22237 My Submissions
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?
*/

/*
JAN 26 2014
Analysis:
-- maintain a visit flag vector, take extra space
--Solution:
We use a prev variable to keep track of the previously-traversed node. Let’s assume curr is the current node that’s on top of the stack. When prev is curr‘s parent, we are traversing down the tree. In this case, we try to traverse to curr‘s left child if available (ie, push left child to the stack). If it is not available, we look at curr‘s right child. If both left and right child do not exist (ie, curr is a leaf node), we print curr‘s value and pop it off the stack.

If prev is curr‘s left child, we are traversing up the tree from the left. We look at curr‘s right child. If it is available, then traverse down the right child (ie, push right child to the stack), otherwise print curr‘s value and pop it off the stack.

If prev is curr‘s right child, we are traversing up the tree from the right. In this case, we print curr‘s value and pop it off the stack.

Reference:
http://leetcode.com/2010/10/binary-tree-post-order-traversal.html
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
 // post order: left right root
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int>postOrder;
        if (!root) return postOrder;
        stack<TreeNode*> s;
        TreeNode *ptr = root;
        TreeNode *prev = NULL;
        s.push(root);
        while(!s.empty())
        {
            ptr = s.top();
            if (!prev || prev -> left == ptr || prev -> right == ptr)
            {
                if (ptr->left)
                {
                    s.push(ptr->left);
                }
                else if (ptr->right)
                {
                    s.push(ptr->right);
                }
            }
            else if (ptr->left == prev)
            {
                if (ptr->right)
                {
                    s.push(ptr->right);
                }
            }
            else
            {
                s.pop();
                postOrder.push_back(ptr->val);
            }
            prev = ptr;
        }

        return postOrder;
    }
};

// the original solution
void postOrderTraversalIterative(BinaryTree *root) {
  if (!root) return;
  stack<BinaryTree*> s;
  s.push(root);
  BinaryTree *prev = NULL;
  while (!s.empty()) {
    BinaryTree *curr = s.top();
    // we are traversing down the tree
    if (!prev || prev->left == curr || prev->right == curr) {
      if (curr->left) {
        s.push(curr->left);
      } else if (curr->right) {
        s.push(curr->right);
      } else {
        cout << curr->data << " ";
        s.pop();
      }
    } 
    // we are traversing up the tree from the left
    else if (curr->left == prev) {
      if (curr->right) {
        s.push(curr->right);
      } else {
        cout << curr->data << " ";
        s.pop();
      }
    }
    // we are traversing up the tree from the right
    else if (curr->right == prev) {
      cout << curr->data << " ";
      s.pop();
    }
    prev = curr;  // record previously traversed node
  }
}
