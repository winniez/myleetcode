/*
Climbing Stairs
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

/*
JAN 27 2014
Analysis:
DP
fibonacci array
* how to make n?
-- finish n-1 and add 1
-- finish n-2 and add 2
therefore, f(n) = f(n-1) + f(n-2), where f(1) = 1 f(2) = 2
Note the recursive solution exceed time limits
*/
class Solution {
public:
    int climbStairs(int n) {
        if (!n) return 0;
        if (n == 1) return 1;
        if (n == 2) return 2;
        int prev2 = 1, prev1 = 2, cur;
        for (int i = 3; i <= n; i++)
        {
            cur = prev1 + prev2;
            prev2 = prev1;
            prev1 = cur;
        }
        return cur;
    }

    /*
    int climbStairs(int n) {
        if (!n) return 0;
        if (n == 1) return 1;
        if (n == 2) return 2;
        return climbStairs(n-1) + climbStairs(n-2);
    }
    */
};
