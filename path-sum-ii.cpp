/*
Path Sum II
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
*/

/*
Mar 18 2014
Solution:
Recursively find eligible path and once find an eligible path, push into reuslts.
Reference:
non-recursive method: http://discuss.leetcode.com/questions/279/path-sum-ii/1261
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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> >allpath;
        vector<int> path;
        if (!root) return allpath;
        findPath(allpath, path, sum, root);
        return allpath;
    }
    void findPath(vector<vector<int> > &allpath, vector<int> path, int diff, TreeNode* root)
    {
        if (!root) return;
        if (!root->left && !root->right && root->val == diff)
        {
            path.push_back(root->val);
            allpath.push_back(path);
            return;
        }
        path.push_back(root->val);
        if (root->left)
        {
            findPath(allpath, path, diff-root->val, root->left);
        }
        if (root->right)
        {
            findPath(allpath, path, diff-root->val, root->right);
        }
    }
};

// Non recursive solution
typedef struct path_element {
struct TreeNode *node;
int level; } path_element;

void addNodeToPath(std::vector<path_element> *path, path_element element)
{
    while (!path->empty()) {
        if (path->back().level >= element.level) {
            path->pop_back();
        } else {
            break;
        }
    }
    path->push_back(element);
}

bool verifyPathSum(std::vector<path_element> *path, int sum) {
    int s = 0;
    std::vector<path_element>::iterator it;

    for (it = path->begin(); it != path->end(); it++) {
        s += it->node->val;
    }

    return (s == sum);
}

vector<vector<int> > pathSum(TreeNode *root, int sum) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    std::stack<path_element> s;
    std::vector<path_element> v;
    std::vector<vector<int> > multi_pathes;

    if (!root) {
        return multi_pathes;
    }

    path_element r;
    r.node = root;
    r.level = 1;
    s.push(r);
    v.push_back(r);

    while (!s.empty()) {
        path_element tmp, p = s.top();
        s.pop();

        addNodeToPath(&v, p);

        if (!(p.node->right) && !(p.node->left)) {
            if (verifyPathSum(&v, sum)) {
                std::vector<int> one_path;
                std::vector<path_element>::iterator it;
                for (it = v.begin(); it != v.end(); it++) {
                    one_path.push_back(it->node->val);
                }
                multi_pathes.push_back(one_path);
            }
            continue;
        }

        if ((p.node)->right) {
            tmp.node = (p.node)->right;
            tmp.level = p.level + 1;
            s.push(tmp);
        }
        if ((p.node)->left) {
            tmp.node = (p.node)->left;
            tmp.level = p.level + 1;
            s.push(tmp);
        }
    }

    return multi_pathes;
}
