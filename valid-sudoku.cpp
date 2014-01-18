/*
Valid Sudoku Total Accepted: 3250 Total Submissions: 12111 My Submissions
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
A partially filled sudoku which is valid.
*/

/*
JAN 17 2014
There are just 3 rules to Sudoku.
Each row must have the numbers 1-9 occuring just once.
Each column must have the numbers 1-9 occuring just once.
And the numbers 1-9 must occur just once in each of the 9 sub-boxes of the grid.
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<string> &board) {
        // check size and value
        int value;
        if (board.size()!=9) return false;
        for (int i = 0; i < 9; i++)
        {
            if (board[i].size() != 9)
            {
                cout<<i<<endl;
                return false;
            }
            for (int j = 0; j < 9; j++)
            {
                value = board[i][j] - '0';
                if (board[i][j] != '.')
                {
                    if ((value > 9) || (value < 1))
                    {
                        cout<<i<<" "<<j<<" "<<board[i][j]<<endl;
                        return false;
                    }
                }
            }
        }
        cout<<"pass size value check\n";
        vector<int>flags(9,0);
        char tmp;
        // check row
        for (int i = 0; i < 9; i++)
        {
            flags.assign(9,0);
            for (int j = 0; j < 9; j++)
            {
                tmp = board[i][j];
                if (tmp != '.')
                {
                    flags[tmp-'1']++;
                }
            }
            for (int k = 0; k < 9; k++)
            {
                if (flags[k] > 1) return false;
            }
        }
        cout<<"pass row check\n";
        // check column
        for (int i = 0; i < 9; i++)
        {
            flags.assign(9,0);
            for (int j = 0; j < 9; j++)
            {
                tmp = board[j][i];
                if (tmp != '.')
                {
                    flags[tmp-'1']++;
                }
            }
            for (int k = 0; k < 9; k++)
            {
                if (flags[k] > 1) return false;
            }
        }
        cout<<"pass column check\n";
        // check square
        for (int a = 0; a < 3; a++)
        {
            for (int b = 0; b < 3; b++)
            {
                flags.assign(9,0);
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        tmp = board[b*3+j][a*3+i];
                        if (tmp != '.')
                        {
                            flags[tmp-'1']++;
                        }
                    }
                }
                for (int k = 0; k < 9; k++)
                {
                if (flags[k] > 1) return false;
                }
            }
        }
        cout<<"pass block check\n";
        return true;
    }
};

int main()
{
    vector<string>input;
    input.push_back(".87654321");
    input.push_back("2........");
    input.push_back("3........");
    input.push_back("4........");
    input.push_back("5........");
    input.push_back("6........");
    input.push_back("7........");
    input.push_back("8........");
    input.push_back("9........");
    Solution s;
    bool res = s.isValidSudoku(input);
}
