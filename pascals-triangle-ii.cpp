/*
Pascal's Triangle II
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/

/*
Notice the space requirement
replacement
*/

/*
JAN 12 2014
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> layer(1,1);
        if (rowIndex == 0)
        {
            return layer;
        }
        layer.push_back(1);
        vector<int> tmp;
        for (int i = 1; i <= rowIndex; i++)
        {
            for (int j = 1; j < i; j++)
            {
                tmp.push_back(layer[j-1]+layer[j]);
            }
            layer.clear();
            layer.push_back(1);
            layer.insert(layer.end(), tmp.begin(), tmp.end());
            layer.push_back(1);
            tmp.clear();
        }
        return layer;
    }
};
