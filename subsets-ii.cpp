/*
Subsets II
Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

/*
Mar 26 2014
Solution:
DP. Similar to subset. Compute result for S[:0], which is empty set. Then compute S[:1] based on result of S[:0].
To avoid duplication. When S[i] = S[i-1], we should avoid computing S[i] with the result of S[i-2], which will generate identical subsets with the computation of S[i-1] and result of S[i-2].
Time: O(2^n), space O(2^n).
*/

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> >rtn;
        sort(S.begin(), S.end());
        vector<int>subset;
        rtn.push_back(subset);
        int curlen, lastlen, start;
        for(int i = 0; i < S.size(); i++)
        {
            curlen = rtn.size();
            if (i>0 && S[i] == S[i-1])
            {
                start = lastlen;
            }
            else
            {
                start = 0;
            }
            for(int j = start; j < curlen; j++)
            {
                subset.clear();
                subset.assign(rtn[j].begin(), rtn[j].end());
                subset.push_back(S[i]);
                rtn.push_back(subset);
            }
            lastlen = curlen;
        }
        return rtn;
    }
};
