/*
Single Number
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

/*
Use XOR, scan only once.
Note the property of XOR operation: a XOR a = 0; 0 XOR a = a; commutativity-- a XOR b = b XOR a
*/

/*
JAN 12 2014
*/

class Solution {
public:
    int singleNumber(int A[], int n) {
        int rtn = 0;
        for (int i = 0; i < n; i++)
        {
            rtn = rtn^A[i];
        }
        return rtn;
    }
};

