/*
Decode Ways Total Accepted: 4523 Total Submissions: 29425 My Submissions
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
*/
/*
Feb 4 2014
The problem is simliar to climbing stairs with restrictions. "Each time you can either climb 1 or 2 steps."
Solution:
DP
Note:
* an single '0' cannot be decoded.
* if s[i] != 0 then  ways[i] = ways[i-1] else ways[i] = 0
* if s[i-1] and s[i] is decodeable, ways[i] += ways[i-2]
*/
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) return 0;
        int tmp1 = 0, tmp2 = 0, tmp3 = 0;
        if (s[0] != '0') tmp1 = 1;
        else tmp1 = 0;
        if (s[1] != '0') tmp2 += tmp1;
        tmp2 += decodeable(s, 0);
        if (s.size() == 1) return tmp1;
        if (s.size() == 2) return tmp2;
        for (int i = 2; i < s.size(); i++)
        {
            if (s[i] != '0') tmp3 = tmp2;
            else tmp3 = 0;
            if (decodeable(s, i-1))
            {
                tmp3 += tmp1;
            }
            tmp1 = tmp2;
            tmp2 = tmp3;
        }
        return tmp3;
    }
    int decodeable(string s, int start)
    {
        int rtn = 0;
        if (s[start] == '1')
        {
            rtn = 1;
        }
        if (s[start]== '2')
        {
            if(s[start+1]>='0' && s[start+1] <='6')
            {
                rtn = 1;
            }
        }
        return rtn;
    }
};

