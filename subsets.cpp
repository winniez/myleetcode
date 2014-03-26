/*
Subsets
Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

/*
Mar 26 2014
Solution:
DP. Store result of S[:1] and make S[:2] from result of S[:1].
Similar to "Letter Combinations of a Phone Number".
Note:
The input is not sorted. Sort the input before dp.
*/
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > rtn;
        sort(S.begin(), S.end());
        vector<int> sub;
        rtn.push_back(sub);
        int curlen;
        for(int i = 0; i < S.size(); i++)
        {
            curlen = rtn.size();
            for (int j = 0; j<curlen; j++)
            {
                sub.clear();
                sub.assign(rtn[j].begin(), rtn[j].end());
                sub.push_back(S[i]);
                rtn.push_back(sub);
            }
        }
        return rtn;
    }
};
