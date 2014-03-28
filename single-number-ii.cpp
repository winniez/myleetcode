/*
Single Number II
Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

/*
Mar 26 2014
Solution:
We count the number of 1s for each bit position. Then find mod 3 of each of them. The bit positions having mod 3 equal to one are the bits that are set due to the number occurring once.

Reference:
http://www.cnblogs.com/daijinqiao/p/3352893.html
*/

class Solution {
public:
    int singleNumber(int A[], int n) {
        if ((!A) || (!n)) return 0;
        int bits[32];
        int res = 0;
        for (int i = 0; i < 32; i++)
        {
            bits[i] = 0;
            for(int j = 0; j < n; j++)
            {
                if (((A[j] >> i) & 1) == 1)
                {
                    bits[i] = (bits[i]+1)%3;
                }
            }
            res |= (bits[i] << i);
        }
        return res;
    }
};
