/*
Spiral Matrix II Total Accepted: 3161 Total Submissions: 10680 My Submissions
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

/*
JAN 11 2014

*/

/*
Solution 1:
Fill in the matrix by loop.

Solution 2:
Fill in the matrix from 1 to n*n. There are four sections, x and y changes in different pattern in different sections.
*/


#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
/* my solution */
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > matrix(n, vector<int>(n, 0));
        int loop_num = n/2 + n%2;
        for (int loop = 0; loop < loop_num; loop++)
        {
            int side = n - loop*2;
            int start = n*n - (n-loop*2)*(n-loop*2)+1;
            int cur = start;
            if (side == 1)
            {
                matrix[loop][loop] = cur;
                break;
            }
            // index 0 ~ n-1
            for (int x = loop; x <= n - 1 - loop - 1; x++)    //loop + side - 1 = n - loop - 1
            {
                matrix[loop][x] = cur;
                cur++;
            }
            for (int y = loop; y <= n - 1 - loop - 1; y++)
            {
                matrix[y][n-1-loop] = cur;
                cur++;
            }
            for (int x = n - 1 - loop; x >= loop + 1 ; x--)
            {
                matrix[n-1-loop][x] = cur;
                cur++;
            }
            for (int y = n - 1 - loop; y >= loop + 1  ; y--)
            {
                matrix[y][loop] = cur;
                cur++;
            }
        }
        return matrix;
    }
};

int main()
{
    int input = 1;
    vector<vector<int> > m = generateMatrix(input);

    //print
    for (int y = 0; y < input; y++)
    {
        cout<<"[";
        for (int x = 0; x < input; x++)
        {
            cout<<m[y][x]<<",";
        }
        cout<<"]\n";
    }

}

