/*
Triangle
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/

/*
JAN 21 2014
DP
Reference:
http://jane4532.blogspot.com/2013/09/triangleleetcode.html
- key point is DP and we can replace the value in triangle, which can be done in place.
- bottom up, sum up the smaller elements that the current one can reach in next level. Return the first node in first level in the end.
*/
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int h = triangle.size();
        for (int l = h - 2; l>=0; l--)
        {
            for (int i = 0; i < triangle[l].size(); i++)
            {
                triangle[l][i] += min(triangle[l+1][i], triangle[l+1][i+1]);
            }
        }
        return triangle.empty()? 0:triangle[0][0];
    }
};
