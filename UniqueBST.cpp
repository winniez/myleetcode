/*
Unique Binary Search Trees Total Accepted: 5797 Total Submissions: 16321 My Submissions
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/


/*
JAN 15 2014
Solution: DP

Reference: http://fisherlei.blogspot.com/2013/03/leetcode-unique-binary-search-trees.html
http://discuss.leetcode.com/questions/270/unique-binary-search-trees
BST build from the rule: i is the root, construct left sub-tree with [1~i-1], construct right sub-tree with [i+1~n]
** cantalan numbers http://en.wikipedia.org/wiki/Catalan_number
*/
class Solution {
public:
// O(1) space, O(n) time, Catalan numbers
// Cn = (2n!)/((n+1)!n!), So we can get the recurrence relation between Cn and Cn-1
    int numTrees(int n) {
        int c = 1;
    for (int i = 2; i <= n; i++)
        c = 2*(2*i-1)*c/(i+1);
    return c;
    }
/*
O(n) space, O(n) time
int numTrees(int n) {
    vector<int> count(n+1, 0);
    count[0] =1;
    count[1] =1;
    for(int i =2; i<=n; i++)
    {
        for(int j =0; j<i; j++)
        {
            count[i] += count[j]*count[i-j-1];
        }
    }
    return count[n];
}
*/
};
