/*
Longest Palindromic Substring
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/
/*
Feb 16 2014
Solution:
* dp -- time O(n^2) space O(n^2)
* expand around center -- time O(n^2) space O(1)
-- We observe that a palindrome mirrors around its center. Therefore, a palindrome can be expanded from its center, and there are only 2N-1 such centers
* Manacher’s algorithm -- time O(n) space O(n)


Reference:
http://leetcode.com/2011/11/longest-palindromic-substring-part-i.html O(n^2) solution

http://www.felix021.com/blog/read.php?2040
http://leetcode.com/2011/11/longest-palindromic-substring-part-ii.html O(n) O(n) slotion
*/

// time O(n^2), space O(1) solution
class Solution {
public:
    int expandAroundCenter(string s, int c1, int c2)
    {
        int l = c1, r = c2, n = s.size();
        while(l>=0 && r<=n-1 && s[l]==s[r])
        {
            l--;
            r++;
        }
        return r-l-1;
    }

    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int n = s.size();
        int maxlen = 1, start = 0, end = 0, curlen = 0;
        for(int i = 0; i < n-1; i++)
        {
            curlen = expandAroundCenter(s, i, i);
            if (curlen>maxlen)
            {
                maxlen = curlen;
                start = i - curlen/2;
                end = i + curlen/2;
            }
            curlen = expandAroundCenter(s, i, i+1);
            if (curlen>maxlen)
            {
                maxlen = curlen;
                start = i - (curlen-2)/2;
                end = i + 1 +(curlen-2)/2;
            }
        }
        string rtn (s, start, maxlen);
        return rtn;
    }
};


// time O(n), space O(n) solution
// Transform S into T.
// For example, S = "abba", T = "^#a#b#b#a#$".
// ^ and $ signs are sentinels appended to each end to avoid bounds checking
string preProcess(string s) {
  int n = s.length();
  if (n == 0) return "^$";
  string ret = "^";
  for (int i = 0; i < n; i++)
    ret += "#" + s.substr(i, 1);

  ret += "#$";
  return ret;
}

string longestPalindrome(string s)
{
    string T = preProcess(s);
    int n = T.length();
    int *P = new int[n];
    int C = 0, R = 0;
    for (int i = 1; i < n-1; i++)
    {
        int i_mirror = 2*C-i; // equals to i' = C - (i-C)
        P[i] = (R > i) ? min(R-i, P[i_mirror]) : 0;
        // Attempt to expand palindrome centered at i
        while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
            P[i]++;
        // If palindrome centered at i expand past R,
        // adjust center based on expanded palindrome.
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
    }
    // Find the maximum element in P.
    int maxLen = 0;
    int centerIndex = 0;
    for (int i = 1; i < n-1; i++)
    {
        if (P[i] > maxLen)
        {
            maxLen = P[i];
            centerIndex = i;
        }
    }
    delete[] P;
    return s.substr((centerIndex - 1 - maxLen)/2, maxLen);
}
