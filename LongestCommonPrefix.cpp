/*
Longest Common Prefix
Write a function to find the longest common prefix string amongst an array of strings.
 */

/*
JAN 14 2014
Note: all string must have common prefix. We are not looking for most common prefix.
*/

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string prefix = "";
        if (!strs.size()) return prefix;
        int agree = 1;
        for (int i = 0; i < strs[0].length(); i++)
        {
            agree = 1;
            for (int j = 0; j<strs.size(); j++)
            {
                if (i == strs[j].length())
                {
                    agree = -1;
                    break;
                }
                if (strs[0][i] != strs[j][i])
                {
                    agree = -1;
                    break;
                }
            }
            if (agree > 0)
            {
                prefix = prefix + strs[0][i];
            }
            else
            {
                break;
            }
        }
        return prefix;
    }
};


