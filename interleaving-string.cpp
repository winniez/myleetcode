/*
Interleaving String
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
*/
/*
Feb 12 2014
Solution: 2d dp
Fill in t[i][j] according to t[i-1][j] and t[i][j-1].

Reference: http://www.geeksforgeeks.org/check-whether-a-given-string-is-an-interleaving-of-two-other-given-strings-set-2/

if s1[:i] s2[:j] could match to s3[:i+j]
*/

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.empty() && s1.empty() && s2.empty()) return true;
        if (s1.size() + s2.size() != s3.size()) return false;
        int m = s1.size(), n = s2.size();
        vector<vector<bool> > t(m+1, vector<bool>(n+1, false));
        t[0][0] = true;
        // Process all characters of A and B
        for (int i=0; i<=m; ++i)
        {
            for (int j=0; j<=n; ++j)
            {
                // two empty strings have an empty string
                // as interleaving
                if (i==0 && j==0)
                    t[i][j] = true;
                // A is empty
                else if (i==0 && s2[j-1]==s3[j-1])
                    t[i][j] = t[i][j-1];
                    // B is empty
                else if (j==0 && s1[i-1]==s3[i-1])
                    t[i][j] = t[i-1][j];
                // Current character of s3 matches with current character of s1,
                // but doesn't match with current character of s2
                else if(s1[i-1]==s3[i+j-1] && s2[j-1]!=s3[i+j-1])
                    t[i][j] = t[i-1][j];
                // Current character of C matches with current character of B,
                // but doesn't match with current character of A
                else if (s1[i-1]!=s3[i+j-1] && s2[j-1]==s3[i+j-1])
                    t[i][j] = t[i][j-1];
                // Current character of C matches with that of both A and B
                else if (s1[i-1]==s3[i+j-1] && s2[j-1]==s3[i+j-1])
                    t[i][j]=(t[i-1][j] || t[i][j-1]) ;
            }
        }
        return t[m][n];
    }
};

