/*
Reverse Integer
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.

Have you thought about this?
Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

Throw an exception? Good, but what if throwing an exception is not an option? You would then have to re-design the function (ie, add an extra parameter).
*/

/*
JAN 14 2014
Solution:
Note the negative inputs, -123 mod 10 = 7, convert negative to positive before processing
The stop condition of loop.
Overflow condition? don't konw....
The commented code is another solution.
*/
class Solution {
public:
    int reverse(int x) {
        int ori = abs(x);
        int y = 0;
        //int y = ori%10;
        while(ori>0)
        {
            y = y*10 + (ori%10);
            ori = ori / 10;
            /*
            ori = ori / 10;
            y = y*10 + (ori%10);
            */
        }
        if (x>0)
            return y;
            //return y/10;
        else
            return 0 - y;
            //return 0 - y/10;
    }
};
