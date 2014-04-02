/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.
*/

/*
Apr 1 2014
2d dp
Let f(i,j) be # unique path from start to point (i,j). As robot can only move either down or right.
f(i,j) = f(i-1, j) + f(i, j-1), where f(0,0) = 1.
It can be solved using a 2d m*n matrix recording each f(i, j).
To optimize space usage, actually all 2d dp can be sloved with O(n) spcace. Calculate from i: 0 ~ m, dp[j] always have the dp[i-1, j]
Time O(n*m), space O(min(n,m)).
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 0) return 0;
        if (n == 0) return 0;
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dp[j+1] = dp[j] + dp[j+1];
            }
        }
        return dp[n];
    }
};
