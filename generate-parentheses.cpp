/*
Generate Parentheses
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/

/*
ANALYSIS
use helper to do that, left means the number of used "(", right means the number of used ")"
when left == n, it means no more "(", so directly add all ")"
when left < n
a. it can add "(" to every strings in return value of helper(left + 1, right, n);
b. when right < left, it can add ")" to every strings in return value of helper(left, right+1,n);
*/

/* JAN. 11 2014
REFERENCE: 
http://vialgorithms.blogspot.com/2013/11/leetcode-generate-parentheses.html
http://discuss.leetcode.com/questions/203/generate-parentheses

http://www.cnblogs.com/zhuli19901106/p/3462373.html
"
If you're familiar with the Catalan Numbers, you'll see it's a typical solution for this problem.

　　Since all the combinations are required, we'll use DFS to go through every possible sequence.

　　Let's consider the recursion in the following way:

　　　　1. For a sequence of length 2 * n, there're n '(' and n ')'

　　　　2. For a valid sequence, number of '(' will never be less than the number of ')' at any position. If there're more ')' than '(', there must be a mismatch.

　　　　3. Always do the recursion from left to right.

　　Time complexity is H(n) * O(n) = C(2 * n, n) / (n + 1) * n, that's roughly O(n!). Space complexity is not sure yet...
"
Time complexity: O(n!)
Space complexity: O(n^2) ?

*/

class Solution {
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> rtn;
        if (n>0)
            recursive(rtn, "", n, 0, 0);
        return rtn;
    }

    void recursive(vector<string> &parenthesis, string s, int n, int left, int right)
    {
        if (left == n)
        {
            s.append(n-right, ')');
            parenthesis.push_back(s);
            return;
        }
        recursive(parenthesis, s+"(", n, left+1, right);
        if (left > right)
        {
            recursive(parenthesis, s+")", n, left, right+1);
        }
    }
};
