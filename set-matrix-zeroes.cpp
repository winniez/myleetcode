/*
Set Matrix Zeroes
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

click to show follow up.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/

/*
Apr 3 2014
Solution:
O(mn) solution is to generate a new matrix. O(m+n) solution is to use a size m vector and a size n vector to record if there's a zero in the row/col.
To use constant space, use first column and first row to record if there's a zero in the row/ col. Before doing that, use 2 variable to record if there's a zero in first col and first row.
Time O(n), space O(1).
*/

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if(matrix.empty()) return;
        if (matrix[0].empty()) return;
        int n = matrix.size();
        int m = matrix[0].size();
        bool row_has_zero = false, col_has_zero = false;
        for (int i = 0; i<n; i++)
        {
            if (matrix[i][0] == 0) col_has_zero = true;
        }
        for (int j = 0; j<m; j++)
        {
            if (matrix[0][j] == 0) row_has_zero = true;
        }
        for (int i = 0; i<n; i++)
        {
            for (int j = 0; j<m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i<n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if(matrix[0][j]==0 || matrix[i][0] == 0) matrix[i][j] = 0;
            }
        }
        if (row_has_zero)
        {
            for (int j = 0; j<m; j++) matrix[0][j] = 0;
        }
        if (col_has_zero)
        {
            for (int i = 0; i<n; i++) matrix[i][0] = 0;
        }
    }
};
