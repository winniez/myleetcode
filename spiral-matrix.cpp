/*
Spiral Matrix
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/
/*
Feb 23 2014
Solution:
Use left, right, top, bottom to specify the range of continuous filling.
Use a flag to specify the direction of filling
Time O(m*n) space (m*n)
Reference:
http://discuss.leetcode.com/questions/29/spiral-matrix/1331
http://discuss.leetcode.com/questions/29/spiral-matrix
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> rtn;
        if (matrix.empty()) return rtn;
        int m = matrix[0].size();
        int n = matrix.size();
        // i for row, range 0~n-1
        // j for column, range 0~m-1
        int i = 0, j = 0;
        int top = 0, left = 0, right = m-1, bottom = n-1;
        int flag = 0;
        while (left <= right && top <= bottom)
        {
            switch(flag)
            {
                case 0:     // from left to right
                    for (j = left; j <= right; j++) rtn.push_back(matrix[top][j]);
                    top++;
                    flag = 1;
                    break;
                case 1:     // from top to bottom
                    for (i = top; i <= bottom; i++) rtn.push_back(matrix[i][right]);
                    right--;
                    flag = 2;
                    break;
                case 2:     // from right to left
                    for (j = right; j >= left; j--) rtn.push_back(matrix[bottom][j]);
                    bottom--;
                    flag = 3;
                    break;
                case 3:     // from bottom to top
                    for (i = bottom; i >= top; i--) rtn.push_back(matrix[i][left]);
                    left++;
                    flag = 0;
                    break;
            }
        }
        return rtn;
    }
};
