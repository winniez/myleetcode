/*
Pow(x, n)
Implement pow(x, n).
*/

/*
Mar 31 2014
Solution:
- recursively calculate square
- note when n < 0 ( 1/ pow(x, abs(n)) or as below)
Time (log n)
*/

class Solution {
public:
    double pow(double x, int n) {
        if (n == 0) return 1.0;
        double half = pow(x, n/2);
        if (n%2 == 0)
        {
            return half * half;
        }
        else if (n > 0)
        {
            return half * half * x;
        }
        else
        {
            return half * half / x;
        }
    }
};
