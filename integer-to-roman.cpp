/*
Integer to Roman
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
*/
/*
Feb 12 2014

Symbol  Value
I   1
V   5
X   10
L   50
C   100
D   500
M   1,000
Numbers are formed by combining symbols together and adding the values. So II is two ones, i.e. 2, and XIII is a ten and three ones, i.e. 13. There is no zero in this system, so 207, for example, is CCVII, using the symbols for two hundreds, a five and two ones. 1066 is MLXVI, one thousand, fifty and ten, a five and a one.
Symbols are placed from left to right in order of value, starting with the largest. However, in a few specific cases,[2] to avoid four characters being repeated in succession (such as IIII or XXXX) these can be reduced using subtractive notation as follows:[3][4]
the numeral I can be placed before V and X to make 4 units (IV) and 9 units (IX respectively)
X can be placed before L and C to make 40 (XL) and 90 (XC respectively)
C can be placed before D and M to make 400 (CD) and 900 (CM) according to the same pattern

Reference: http://en.wikipedia.org/wiki/Roman_numerals
*/

class Solution {
public:
    string intToRoman(int num) {
        string rtn = "";
        if (num < 1 || num > 3999) return rtn;
        int cnt, cur = num;
        cnt = (int) (cur/1000);
        if (cnt)
        {
            for (int i = 0; i < cnt; i++)
            {
                rtn += "M";
            }
        }
        cur -= cnt * 1000;
        cnt = (int) (cur/900);
        if (cnt)
        {
            rtn += "CM";
        }
        cur -= cnt * 900;
        cnt = (int) (cur/500);
        if (cnt)
        {
            rtn += "D";
        }
        cur -= cnt * 500;
        cnt = (int) (cur/400);
        if (cnt)
        {
            rtn += "CD";
        }
        cur -= cnt * 400;
        cnt = (int) (cur/100);
        if (cnt)
        {
            for (int i = 0; i < cnt; i++)
            {
                rtn += "C";
            }
        }
         cur -= cnt * 100;
         cnt = (int) (cur/90);
         if (cnt)
         {
             rtn += "XC";
         }
         cur -= cnt * 90;
         cnt = (int) (cur/50);
         if (cnt)
         {
             rtn += "L";
         }
         cur -= cnt *50;
         cnt = (int) (cur/40);
         if (cnt)
         {
             rtn += "XL";
         }
         cur -= cnt * 40;
         cnt = (int) (cur/10);
         if (cnt)
         {
             for (int i = 0; i < cnt; i++)
             {
                 rtn += "X";
             }
         }
         cur -= cnt * 10;
         cnt = (int) (cur/9);
         if (cnt)
         {
             rtn += "IX";
         }
         cur -= cnt * 9;
         cnt = (int) (cur/5);
         if (cnt)
         {
             rtn += "V";
         }
         cur -= cnt * 5;
         cnt = (int) (cur/4);
         if (cnt)
         {
             rtn += "IV";
         }
         cur -= cnt * 4;
         cnt = (int) (cur/1);
         if (cnt)
         {
             for (int i = 0; i< cnt; i++)
             {
                 rtn += "I";
             }
         }
        return rtn;
    }
};
