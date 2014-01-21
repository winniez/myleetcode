/*
Best Time to Buy and Sell Stock II Total Accepted: 6145 Total Submissions: 17306 My Submissions
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

/*
JAN 21 2014
Note:
Two rules:
- Sell stock when the next is a decrease
- Buy/Hold stock when the next is a increase
*/
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) return 0;
        bool hold = false;
        int profit = 0;
        for (int i = 0; i < prices.size()-1; i++)
        {
            if (prices[i] < prices[i+1])
            {
                hold = true;
                profit += prices[i+1] - prices[i];
            }
            if (prices[i] > prices[i+1])
            {
                hold = false;
            }
        }
        return profit;
    }
};
