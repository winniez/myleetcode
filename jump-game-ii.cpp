/*
Jump Game II
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
*/

/*
Feb 12 2014
Solution: greedy
- at index cur, search A[cur] ~ A[cur + A[cur]], go to the largest one within this range.
Note:
- n = 1, a[0] = 1, already at last.
- A[cur] + cur should not exceed n-1, once reach n-1, return.
*/
class Solution {
public:
    int jump(int A[], int n) {
        if (!n || !A) return 0;
        int step = 0;
        int cur = 0, next;
        int max = -1;
        while(cur < n-1)
        {
            step++;
            max = -1;
            if (!A[cur]) return step;
            if (A[cur]+cur >= n-1) return step;
            for (int i = cur; i <= cur+A[cur]; i++)
            {
                if (i + A[i] > max)
                {
                    next = i;
                    max = i + A[i];
                }
            }
            cur = next;
        }
        return step;
    }
};
