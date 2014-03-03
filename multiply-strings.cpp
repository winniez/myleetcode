/*
Multiply Strings
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
*/

/*
Mar 2 2014
Solution:
Read input string into int vector, multipy digit by digit.
The product of 2 numbers have largest possible digits of len1+len2, where len1 is the # of digits in first number.
Handle carry from lower digit to higher digit, remove the highest digit if it is 0.
Note:
When one of input is "0", the product is "0".
*/
class Solution {
public:
    string multiply(string num1, string num2) {
        string r;
        if (num1.empty() || num2.empty()) return r;
        if(num1[0] == '0' || num2[0] == '0') return "0";
        int l1 = num1.size();
        int l2 = num2.size();
        vector<int> n1 (l1, 0);
        vector<int> n2 (l2, 0);
        for (int i = 0; i < l1; i++) n1[i] = num1[i]-'0';
        for (int i = 0; i < l2; i++) n2[i] = num2[i]-'0';
        int tmp1, tmp2;
        vector<int> res(l1+l2, 0);
        for (int i = l1-1; i >= 0; i--)
        {
            for (int j = l2-1; j >= 0; j--)
            {
                res[i+j+1] += n1[i]*n2[j];
            }
        }
        for (int i = l1+l2-1; i >= 0; i--)
        {
            tmp1 = res[i];
            res[i-1] += tmp1/10;
            res[i] = tmp1%10;
        }
        int p = 0;
        while(!res[p]) p++;
        for (; p<l1+l2; p++)
        {
            r += '0' +res[p];
        }
        return r;
    }
};
