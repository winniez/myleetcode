/*
Best Time to Buy and Sell Stock Total Accepted: 6302 Total Submissions: 20280 My Submissions
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
*/

/*
JAN 21 2014
Note: update max to min when min is updated.
*/
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) return 0;
        int max = INT_MIN;
        int min = INT_MAX;
        int profit = INT_MIN;
        for (int i = 0; i< prices.size(); i++)
        {
            if (prices[i]<min)
            {
                min = prices[i];
                max = min;
            }
            if (prices[i]>max)
            {
                max = prices[i];
            }
            if (profit < max - min)
            {profit = max - min;}
        }
        return profit;
    }
};
