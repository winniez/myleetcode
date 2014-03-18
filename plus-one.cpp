/*
Plus One
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
*/

/*
Solution:
Create a new vector of sizeofinput+1.
Scan array from least significant bit and add, add carry to its left element.
Remove the most significant bit if it is a 0.
*/

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int size = digits.size();
        vector<int> rtn(size+1, 0);
        rtn[size] = 1;
        for (int i = size-1; i >= 0; i--)
        {
            rtn[i+1] += digits[i];
            if (rtn[i+1] > 9)
            {
                rtn[i] = 1;
                rtn[i+1] = rtn[i+1] % 10;
            }
        }
        if (!rtn[0]) rtn.erase(rtn.begin(), rtn.begin()+1);
        return rtn;
    }
};
