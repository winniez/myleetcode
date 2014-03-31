/*
Palindrome Partitioning
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]
*/

/*
Mar 30 2014
Solution1:
dfs + recursion, similar to permutation, combination sum.
To get the all the partitions of a string s:
1. find all the palindromes in substring s[0], and all the palindromes in substring s[1:end]
2. find all the palindromes in substring s[0:1], and all the palindromes in substring s[2:end]
...
find all the palindromes in substring s[1:end-1], and all the palindromes in substring s[end]
Analysis:
validatePalindrome is O(n).
All possible number of cuts of is O(2^n). (Will explain later)
To validate each cut, calling validatePanlindrome cost n.
Total complexity O(n*2^n). Space O(n*2^n).

Now let's talk about the gerenal term for # cuts for string of size n.
Let f(n) be # of cuts for string of size n, T(n) be all cuts. How do we get T(n+1)? Let s[n+1] be x.
For each cut in T(n), cut in the end, then append x; for each cut in T(n), append x. That's all possible cuts s[:n+1].
Therefore, f(n+1) = 2*f(n), f(1) = 1, f(n) = 2^(n-1).

Refer to question "In how many ways can you split a string of length n such that every substring has length at least m?"
http://math.stackexchange.com/questions/412338/in-how-many-ways-can-you-split-a-string-of-length-n-such-that-every-substring-ha
The problem is in fact combinatorics partitions problem. wiki http://en.wikipedia.org/wiki/Partition_(number_theory)
A partition of a positive integer n, also called an integer partition, is a way of writing n as a sum of positive integers.
Let f(n) be # of ways to cut string with size n, f(n+1) = 2*f(n), f(n) = f(1)+f(2)+...+f(n-1). Thus the there are 2^n possible cuts.

----------------------------------------------------------------------------------
Solution2:
dp + backtracking
Using DP to calculate and save if a given substring of s is palindrome. Then using backtracking to build up the solution.
Time O(n^2) space O(n^2).

Reference:
dfs + recursion: http://yucoding.blogspot.com/2013/08/leetcode-question-132-palindrome.html
analysis reference: http://polythinking.wordpress.com/2013/06/08/leetcode-palindrome-partitioning/
dp + backtracking:
http://discuss.leetcode.com/questions/1265/palindrome-partitioning
https://sites.google.com/site/mytechnicalcollection/algorithms/dynamic-programming/partition-problem


Time O(n^2), space O(n^2)
*/

// Soution 1 dfs
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > res;
        vector<string> onesolution;
        dfs(res, onesolution, 0, s);
        return res;
    }

    void dfs(vector<vector<string> > &res, vector<string> &one, int start, string s)
    {
        if (start == s.size())
        {
            res.push_back(one);
            return;
        }
        for (int i = start; i < s.size(); i++)
        {
            if (validatePalindrome(s, start, i))
            {
                one.push_back(s.substr(start, i-start+1));
                dfs(res, one, i+1, s);
                one.pop_back();
            }
        }
    }

    bool validatePalindrome(string s, int start, int end)
    {
        assert(start <= end);
        while(start <= end)
        {
            if (s[start] != s[end]) return false;
            start++; end--;
        }
        return true;
    }
};


// Solution 2

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > res;
        int n = s.size();
        vector<vector<bool> > isPalindrome(n, vector<bool>(n, false));
        for(int i = 0; i < n; i++) isPalindrome[i][i] = true;
        // fill from back to front, otherwise we may access value that is not filled yet
        for(int i = n-2; i >= 0; i--)
        {
            // expand from size 1 to size 2
            isPalindrome[i][i+1] = (s[i] == s[i+1]);
            for (int j = i+2; j < n; j++)
            {
                isPalindrome[i][j] = isPalindrome[i+1][j-1] && (s[i] == s[j]);
            }
        }
        // dfs search for eligible path
        vector<string> one;
        searchPath(res, one, s, 0, isPalindrome);
        return res;
    }
    
    void searchPath(vector<vector<string> > &res, vector<string>&one, string s, int start, vector<vector<bool> >& isPalindrome)
    {
        if (start == s.size())
        {
            res.push_back(one);
            return;
        }
        for (int i = start; i < s.size(); i++)
        {
            if (isPalindrome[start][i])
            {
                one.push_back(s.substr(start, i-start+1));
                searchPath(res, one, s, i+1, isPalindrome);
                one.pop_back();
            }
        }
    }
};
