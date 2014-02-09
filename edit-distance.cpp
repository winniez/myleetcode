/*
Edit Distance
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/

/*
Feb 9 2014
Analysis:
dp
for word1[0:i] and word2[0:j]
- if word1[i] == word2[j], f(i,j) = (word1[i] == word2[j])*f(i-1, j-1)
- if word1[i] != word2[j], f(i,j) = min (f(i-1, j-1), f(i, j-1), f(i-1, j))
-- replace word1[i] with word2[j] -> 1 + f(i-1, j-1)
-- insert word2[j] to word1 -> 1 + f(i, j-1)
-- delete word1[i] -> 1 + f(i, j-1)

Note:
Time O(m*n), space O(m*n).
Reference:
http://fisherlei.blogspot.com/2012/12/leetcode-edit-distance.html
http://discuss.leetcode.com/questions/248/edit-distance
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int tmp;
        int dp[n+1][m+1];
        for (int i = 0; i <= n; i++)
        {
            // word2 is empty, delete i characters from word1
            dp[i][0] = i;
        }
        for (int j = 0; j <= m; j++)
        {
            // word1 is empty, insert j characters to word1
            dp[0][j] = j;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (word1[i-1] == word2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    tmp = min(dp[i-1][j], dp[i][j-1]);
                    dp[i][j] = min(tmp, dp[i-1][j-1])+1;
                }
            }
        }
        return dp[n][m];
    }
};

