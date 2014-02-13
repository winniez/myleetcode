/*
Jump Game
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/

/*
Feb 12 2014
Analysis:
The only case we cannot reach the last index is we are trapped at a 0. That is, suppose A[k]=0, any value A[i] before k is no larger than the distance to k and we have no choice but reach 0.

Solution:
Scan array, for every 0, check values ahead of 0.
A[pos] = 0; for 0<= i <= pos. if no A[i] > pos-i, we end up trapped at 0.

Note:
- cornor case as n == 1, which is already last index.
- cornor case as trapped at last index 0. It is already the last index.
*/
class Solution {
public:
    bool canJump(int A[], int n) {
        if (!A || !n) return false;
        if (n == 1) return true;
        int pos0 = -1;
        int flag = true;
        for (int i = n-1; i >=0; i--)
        {
            if (A[i] == 0)
            {
                pos0 = i;
                flag = false;
                for (int j = pos0; j>= 0; j--)
                {
                    if(A[j] > pos0-j) flag = true;
                }
                if (!flag && pos0 != n-1) return false;
            }
        }
        if (pos0 == n-1) return true;
        return flag;
    }
};

