/*
Palindrome Number
Determine whether an integer is a palindrome. Do this without extra space.

Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.
*/

/*
Mar 18 2014
Solution:
As the problem requires constant space, therefore we cannot convert integer to string.
1. use the reverse integer function, reverse input and compare.
2. compare mst and lst, then remove mst and lst and compare mst and lst of the new number, until the new number is less than 10.
*/
// solution 1
class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return false;
        if (x == reverse(x)) return true;
        else return false;
    }
    int reverse(int x) {
        int ori = abs(x);
        int y = 0;
        while(ori>0)
        {
            y = y*10 + (ori%10);
            ori = ori / 10;
        }
        if (x>0)
            return y;
        else
            return 0 - y;
    }
};

// solution 2
class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return false;
        int cpy = x, divide = 1;
        while(cpy >= 10)
        {
            divide *= 10;
            cpy /= 10;
        }
        cpy = x;
        int d1 = 10, d2 = divide;
        while (cpy >= 10)
        {
            if (cpy%d1 != cpy/d2) return false;
            cpy -= (cpy/d2)*d2;
            cpy /= 10;
            d2 /= 100;
        }
        return true;
    }
};

//
