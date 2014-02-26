/*
Minimum Path Sum
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/
/*
Feb 26 2014
Solution:
2d dp, time O(n^2), space O(n^2)
*/
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if (grid.empty()) return 0;
        int n = grid.size();
        int m = grid[0].size();
        if (!m) return 0;
        vector<vector<int> > sums(n, vector<int>(m, 0));
        sums[0][0] = grid[0][0];
        for (int i = 1; i < n; i++) sums[i][0] = grid[i][0] + sums[i-1][0];
        for (int j = 1; j < m; j++) sums[0][j] = grid[0][j] + sums[0][j-1];
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                sums[i][j] = grid[i][j] + min(sums[i-1][j], sums[i][j-1]);
            }
        }
        return sums[n-1][m-1];
    }
};
