/*
Count and Say
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/
/*
JAN 16 2014
TODO:Time Complexity: ?

Note: int to string: std::to_string() introduced by c++ 11
*/

class Solution {
public:
    string countAndSay(int n) {
        if (!n) return "";
        string rtn = "1";
        string tmp;
        string cvt;
        char cur;
        int cnt = 0;
        for (int i = 2; i<=n; i++)
        {
            tmp.clear();
            cnt = 0;
            for (int j = 0; j<rtn.size(); j++)
            {
                if (j==0) cur = rtn[0];
                if (cur == rtn[j])
                {
                    cnt++;
                }
                else
                {
                    tmp.append(to_string(cnt));
                    tmp += cur;
                    cur = rtn[j];
                    cnt = 1;
                }
            }
            tmp.append(to_string(cnt));
            tmp += cur;
            rtn = tmp;
        }
        return rtn;
    }
};
