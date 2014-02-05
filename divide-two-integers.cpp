/*
Divide Two Integers
Divide two integers without using multiplication, division and mod operator.
*/

/*
Feb 4 2014
Solution:
qouted:
In the first beginning, I use minus operator to minus the divisor each time, until the dividend is smaller than the divisor. Though this method can work out, yet it is toooo slow. Especially in the case that the dividend is too large while the divisor is too small.

So we can use the bit operation here.

See the algorithm below. It move the divisor one step left each time, so the divisor*2 each time. Then dividend-divisor, and count+=1<<i. When dividend minus i times of divisor, then, count will add i correspondingly.

In the mean time, we need to pay attention to the positive/negative sign of dividend and divisor.
We use(dividend^divisor)>>31. Why move 31 steps right? Because the highest bit represent the sign of an integer.

* bit operation: [variable]<<[number of places]
Assignment-level expressions    = *= /= %= += -=
>>= <<= &= ^= |=    assignment / compound assignment    Right-to-left

Note:
convert to double before calling abs, otherwise overflows. TODO why???
e.g.
Input:  -2147483648, 1
Output: 0
Expected:   -2147483648

Reference:
http://jane4532.blogspot.com/2013/06/divide-2-integersleetcode.html
http://www.cplusplus.com/doc/tutorial/operators/
*/
class Solution {
public:
    int divide(int dividend, int divisor) {
        long long rtn = 0;
        long long tmp1 = abs((double)dividend);
        long long tmp2 = abs((double)divisor);
        long long tmp3;
        while (tmp1 >= tmp2)
        {
            tmp3 = tmp2;
            for (int i = 0; tmp1 >= tmp3; ++i, tmp3 <<=1)
            {
                tmp1 -= tmp3;
                rtn += 1<<i;
            }
        }
        return ((dividend^divisor)>>31) ? (-rtn) : (rtn);
    }

    /*
    // toooo slow
    int divide(int dividend, int divisor) {
        int rtn = 0;
        int tmp1 = abs(dividend);
        int tmp2 = abs(divisor);
        if (!divisor) return 0;
        if (divisor == 1) return dividend;
        if(divisor == -1) return 0-dividend;
        int flag;
        if (dividend < 0 && divisor < 0) 
        {flag = 1;}
        else if (dividend >=0 && divisor > 0) 
        {flag = 1;}
        else 
        {flag = 0;}
        while (tmp1 >= tmp2)
        {
            tmp1 -= tmp2;
            rtn++;
        }
        if (flag) return rtn;
        else return 0-rtn;
    }
    */
};

