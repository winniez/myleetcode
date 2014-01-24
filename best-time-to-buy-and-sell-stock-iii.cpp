/*
Best Time to Buy and Sell Stock III
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/
/*
JAN 21 2014
Note: need to update min after a max gap is recorded. e.g. [1,2,4]

Reference:
http://blog.unieagle.net/2012/12/05/leetcode%E9%A2%98%E7%9B%AE%EF%BC%9Abest-time-to-buy-and-sell-stock-iii%EF%BC%8C%E4%B8%80%E7%BB%B4%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92/

Solution1: divide and conquer
- divide the whole sequence into two parts at each i; find the maximum intervals or profits in both left and right parts; add both of them together to get the maximum profit on this division; select the largest one.

Solution2: dp
time complexity: O(n) space complexity: O(n)
*/

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) return 0;
        int max = INT_MIN;
        int min = INT_MAX;
        vector<int> profits1(prices.size(),0);
        vector<int> profits2(prices.size(),0);
        int profit = 0;
        min = prices[0];
        // find max profit of sub vector 0~i
        for (int i = 1; i<prices.size(); i++)
        {
            if (min > prices[i])
            {min = prices[i];}
            if (prices[i] - min > profits1[i-1])
            {
                profits1[i] = prices[i] - min;
            }
            else
            {
                profits1[i] = profits1[i-1];
            }
        }
        // find max profit of sub vector i+1~n-1
        max = prices[prices.size()-1];
        for (int i = prices.size()-2; i > 0; i--)
        {
            if (max < prices[i])
            {
                max = prices[i];
            }
            if (max - prices[i] > profits2[i+1])
            {
                profits2[i] = max - prices[i];
            }
            else
            {
                profits2[i] = profits2[i+1];
            }
        }
        for (int i = 0; i<prices.size(); i++)
        {
            // determine max of sum of 2 profits
            if (profit < profits1[i]+profits2[i])
            {
                profit = profits1[i]+profits2[i];
            }
        }
        return profit;
    }
};

