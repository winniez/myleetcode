/*
Pascal's Triangle
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
 */

/*
Solution:
Iterative or Recurision
*/

/*
JAN 12 2014
*/

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> >triangle;
        for (int l = 0; l < numRows; l++)
        {
            vector<int> layer(1,1);
            for (int i = 1; i < l; i++)
            {
                layer.push_back(triangle[l-1][i-1]+triangle[l-1][i]);
            }
            if (l == layer.size())
            {
                layer.push_back(1);
            }
            triangle.push_back(layer);
        }
        return triangle;
    }
};
