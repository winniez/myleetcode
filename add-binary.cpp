/*
Add Binary Total Accepted: 4149 Total Submissions: 16671 My Submissions
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/
/*
JAN 17 2014
Note: carry
*/

class Solution {
public:
    string addBinary(string a, string b) {
        if (a.empty() && b.empty()) return "";
        if (a.empty()) return b;
        if (b.empty()) return a;
        string sumstr = "0";
        int sum;
        int ptra = a.size()-1, ptrb = b.size()-1;
        while(ptra > -1 || ptrb > -1)
        {
            sum = sumstr[0] - '0';
            if (ptra>=0)
            {
                sum += a[ptra]-'0';
                ptra--;
            }
            if (ptrb>=0)
            {
                sum += b[ptrb]-'0';
                ptrb--;
            }
            sumstr[0] = '0' + sum%2;
            if (sum>=2)
            {
                sumstr.insert(0,1,'1');
            }
            else
            {
                if(ptra>-1 || ptrb>-1)
                {
                    sumstr.insert(0,1,'0');
                }
            }
        }
        return sumstr;
    }
};


