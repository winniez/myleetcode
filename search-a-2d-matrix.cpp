/*
Search a 2D Matrix Total Accepted: 8754 Total Submissions: 29114 My Submissions
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
*/

/*
Apr 1 2014
Solution:
- do binary search on the last element of each row.
- once determin the row, do binary search within the row.
Note:
When doing binary search on the last element of each row, note if larger than target, we still keep the row in range.
Time O(log n + log m), constant space.
*/


class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.empty()) return false;
        if (matrix[0].empty()) return false;
        int n = matrix.size(), m = matrix[0].size();
        int rs = 0, re = n-1, cs = 0, ce = m-1;
        int mid;
        while(1)
        {
            if (rs >= re) break;
            mid = (rs + re)/2;
            if (matrix[mid][ce] > target)
            {
                re = mid;
            }
            if (matrix[mid][ce] < target)
            {
                rs = mid + 1;
            }
            if (matrix[mid][ce] == target) return true;
        }
        while (cs <= ce)
        {
            mid = (cs + ce)/2;
            if (matrix[rs][mid] < target)
            {
                cs = mid + 1;
            }
            if (matrix[rs][mid] > target)
            {
                ce = mid - 1;
            }
            if (matrix[rs][mid] == target) return true;
        }
        return false;
    }
};
