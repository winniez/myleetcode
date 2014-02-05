/*
Distinct Subsequences
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.
*/

/*
Feb 4 2014
Solution:
Let f(i, j) to be the number of distinct subsequences of T(j:) in S(i:). Consider the ith character in S. If we can use it to match T[j], namely S[i] == T[j], then

f(i, j) = f(i+1, j+1).

If we do not want use it in our matching, then

f(i, j) = f(i+1, j).

Thus,f(i, j) = f(i+1, j) + (S[i] == T[j]) * f(i+1, j+1).

It is very much the same as how we solve C(n, m) or the knapsack problem.
Note: the recursive solution O(n*m*m), the dp solution O(m*n), space O(m)
Reference:
http://discuss.leetcode.com/questions/281/distinct-subsequences
http://blog.csdn.net/abcbc/article/details/8978146
*/

class Solution {
public:
    int numDistinct(string S, string T) {
        vector<int> f(T.size()+1);
        f[T.size()] = 1;
        for (int i = S.size()-1; i >= 0; i--)
        {
            for (int j = 0; j < T.size(); j++)
            {
                f[j] += (S[i]==T[j])*f[j+1];
            }
        }
        return f[0];
    }
};


/*
// recursion, exceeds time limit
int numDistinct(string S, string T) {
        if (S.empty() || T.empty()) return 0;
        return recursiveSearch(S, T, 0, 0);
    }
    int recursiveSearch(string &S, string &T, int Sbegin, int Tbegin)
    {
        if (Tbegin == T.size()) return 0;
        if (Sbegin == S.size()) return 0;
        if (S.size() - Sbegin < T.size() - Tbegin) return 0;
        int rtn = 0;
        for (int i = Sbegin; i< S.size(); i++)
        {
            if (S[i] == T[Tbegin])
            {
                rtn += recursiveSearch(S, T, i+1, Tbegin+1);
            }
        }
        return rtn;
    }
    */
