/*
Permutation Sequence
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
*/

/*
Mar 29 2014
Solution:
* call next permutation k times. Too slow....
* Math
- Let say the kth permutation is a1, a2, a3, ..., an
- if we remove a1, the rest a2, a3, ..., an, n-1 elements, there are (n-1)! arrangements.
- k1 = k
- a1 = k1/(n-1)!, k2 = k1 % (n-1)!
- a2 = k2/(n-2)!, k3 = k2 % (n-2)!
- a3 = k3/(n-3)!, k4 = k3 % (n-3)!
...
- a(n-1) = k(n-1)/1!, k(n-1) = k(n-2)/2!
- an = k(n-1)

Note:
the origin input is 1~n, change it to 0~n-1.
Reference:
http://fisherlei.blogspot.com/2013/04/leetcode-permutation-sequence-solution.html
*/

class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        int factor = factorial(n);
        if (k < 1 || k > factor) return res;
        vector<bool> index(n, false);
        int kth = 0, cnt = 0;
        // change 1 to n! to 0 to n!-1
        k--;
        for (int i = n-1; i >= 0; i--)
        {
            factor /= i+1;
            kth = k / factor+1;
            cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if (!index[j]) cnt++;
                if (cnt == kth)
                {
                    index[j] = true;
                    res += j+1+'0';
                    break;
                }
            }
            k -= (kth-1) * factor;
        }
        return res;
    }
    int factorial(int n)
    {
        int res = 1;
        for(int i = 1; i <= n; i++)
        {
            res *= i;
        }
        return res;
    }
};

