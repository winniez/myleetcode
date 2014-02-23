/*
Combinations Total
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

/*
Analysis
Recursion
Similiar to generate parentheses
Time Complexity: O(N!)

Note
Start from 1
next is the next one to add
*/

/*
JAN 12 2014
*/

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > rtn;
        vector<int> element;
        recursive(rtn, element, 1, n, k);
        return rtn;
    }

    void recursive (vector<vector<int> > &rtn, vector<int> element, int next, int n, int k)
    {
        if (element.size() == k)
        {
            rtn.push_back(element);
            return;
        }
        if (n - next + 1 == k - element.size())
        {
            for (int i = next; i <= n; i++)
            {
                element.push_back(i);
            }
            rtn.push_back(element);
            return;
        }
        recursive(rtn, element, next+1, n, k);
        element.push_back(next);
        recursive(rtn, element, next+1, n, k);
    }
};
