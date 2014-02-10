/*
Gray Code
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
*/

/*
Feb 9 2014
Solution1:
* convert binary i to its gray code, right shift i bit and XOR with itself -- i ^ (i >> 1)
Solution2:
from wiki
Constructing an n-bit Gray code[edit]

The first few steps of the reflect-and-prefix method.

4-bit Gray code permutation
The binary-reflected Gray code list for n bits can be generated recursively from the list for n−1 bits by reflecting the list (i.e. listing the entries in reverse order), concatenating the original list with the reversed list, prefixing the entries in the original list with a binary 0, and then prefixing the entries in the reflected list with a binary 1.[5] For example, generating the n = 3 list from the n = 2 list:
2-bit list: 00, 01, 11, 10   
Reflected:      10, 11, 01, 00
Prefix old entries with 0:  000, 001, 011, 010,  
Prefix new entries with 1:      110, 111, 101, 100
Concatenated:   000, 001, 011, 010, 110, 111, 101, 100

Reference:
http://fisherlei.blogspot.com/2012/12/leetcode-gray-code.html
http://en.wikipedia.org/wiki/Gray_code
*/

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> rtn;
        int q = pow(2, n);
        unsigned int tmp = 0;
        for (unsigned int i = 0; i < q; i++)
        {
            rtn.push_back((tmp >> 1)^tmp);
            tmp++;
        }
        return rtn;
    }
};

// from wiki
/*
        The purpose of this function is to convert an unsigned
        binary number to reflected binary Gray code.
 
        The operator >> is shift right. The operator ^ is exclusive or.
*/
unsigned int binaryToGray(unsigned int num)
{
        return (num >> 1) ^ num;
}
 
/*
        The purpose of this function is to convert a reflected binary
        Gray code number to a binary number.
*/
unsigned int grayToBinary(unsigned int num)
{
    unsigned int mask;
    for (mask = num >> 1; mask != 0; mask = mask >> 1)
    {
        num = num ^ mask;
    }
    return num;
}
