/*
Maximal Rectangle
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.
*/

/*
Mar 19 2014
Solution:
- create height matrix same size as input matrix, preprosess the input matrix to get the hight (number) of 1's above (and include) each cell;
- run largest rectangle in histograms for each row and keep record of largest area
Time: O(n^2), space O(n^2)
*/

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.empty()) return 0;
        if (matrix[0].empty()) return 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int> > height(rows, vector<int>(cols,0));
        for (int i = 0; i < cols; i++)
        {
            for (int j = 0; j < rows; j++)
            {
                if (matrix[j][i] == '0') height[j][i] = 0;
                else if (j == 0) height[j][i] = 1;
                else height[j][i] = height[j-1][i] + 1;
            }
        }
        stack<int> s;
        int area = 0, maxarea = 0, i, tp;
        for (int j = 0; j < rows; j++)
        {
            i = 0;
            while(i < cols)
            {
                if (s.empty() || height[j][s.top()] <= height[j][i]) 
                {
                    s.push(i);
                    i++;
                }
                else
                {
                    tp = s.top();
                    s.pop();
                    area = height[j][tp] * (s.empty()?i:i-s.top()-1);
                    maxarea = max(maxarea, area);
                }
            }
            while(!s.empty())
            {
                tp = s.top();
                s.pop();
                area = height[j][tp] * (s.empty()?i:i-s.top()-1);
                maxarea = max(maxarea, area);
            }
        }
        return maxarea;
    }
};
