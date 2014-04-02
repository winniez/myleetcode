/*
Word Search
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/

/*
Apr 1 2014
Solution:
Use a same size matrix to record visited cells.
After finding word[0], recursively search for word[1:]. DFS in 4 directions.
Note the expand func return false when the cell is already visited. Also note the expand func return false when index out of bound.

!!! When the recursive search finishes, set the visted cell back to false for further search.
Time O(m*n*word.size()), space O(m*n).
Reference:
http://discuss.leetcode.com/questions/254/word-search/2154
*/


class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if (board.empty() || word.empty()) return false;
        int n = board.size(), m = board[0].size();
        if (m == 0) return false;
        bool find = false;
        vector<vector<bool> > visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == word[0])
                {find = find || expand(board, visited, word, 0, i, j);}
            }
        }
        return find;
    }

    bool expand(vector<vector<char> > &board, vector<vector<bool> >&visited, string word, int pos, int x, int y)
    {
        if (pos == word.size()) return true;
        int n = board.size(), m = board[0].size();
        if (x < 0 || x >= n || y < 0 || y >= m) return false;
        if (board[x][y] != word[pos]) return false;
        if (visited[x][y]) return false;
        visited[x][y] = true;
        bool res = expand(board, visited, word, pos+1, x-1, y) ||
                    expand(board, visited, word, pos+1, x+1, y) ||
                    expand(board, visited, word, pos+1, x, y-1) ||
                    expand(board, visited, word, pos+1, x, y+1);
        visited[x][y] = false;
        return res;
    }
};

