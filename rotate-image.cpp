/*
Rotate Image
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/

/*
Apr 4 2014
Solution:
Rotate matrix clockwise by 90 degrees is to put (i,j) in (n-1-j, i). The transformation can be done by scanning the matrix or by following steps.
(i, j) => (n-1-j, i)
1. (i, j) => (i, n-1-j) => (n-1-j, i), flip uppder half and lower half, and flip along diagonal
2. (i, j) => (n-1-j, n-1-i) => (n-1-j, i) flip along 2nd diagonal, and flip left half and right half
Time O(n^2), space constant.
*/

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        if (matrix.empty()) return;
        if (matrix[0].empty()) return;
        int n = matrix.size();
        // (i, j) => (n-1-j, i)
        // 1st (i, j) => (i, n-1-j) => (n-1-j, i), flip uppder half and lower half, and flip along diagonal
        // 2nd (i, j) => (n-1-j, n-1-i) => (n-1-j, i) flip along 2nd diagonal, and flip left half and right half
        int tmp;
        for (int i = 0; i < n/2; i++)
        {
            for (int j = 0; j < n; j++)
            {
                tmp = matrix[i][j];
                matrix[i][j] = matrix[n-1-i][j];
                matrix[n-1-i][j] = tmp;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
    }
};
