/*
Candy
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?
*/

/*
JAN 27 2014
Analysis:
-- each child must have at least one candy -- initiate an all 1 array
-- children with a higher rating get more candies than their neighbors 
---- scan from left to right, if gets higher rating than left neighbor, get 1 more candy than left neighbor
---- sacan from right to left, if gets higher rating than right neighbor, get max (1 + #candies right neighbor have, #candies I have)
Note: the max of 2nd scan.
Time O(n), space O(n)
*/
class Solution {
public:
    int candy(vector<int> &ratings) {
        if (ratings.empty()) return 0;
        vector<int> assign(ratings.size(), 1);
        for (int i = 0; i<ratings.size()-1; i++)
        {
            if (ratings[i+1] > ratings[i])
            {
                assign[i+1] = max(assign[i+1], assign[i] + 1);
            }
        }
        for (int i = ratings.size()-1; i > 0; i--)
        {
            if (ratings[i-1] > ratings[i])
            {
                assign[i-1] = max(assign[i-1], assign[i] + 1);
            }
        }
        int sum = 0;
        for (int i = 0; i < assign.size(); i++)
        {
            sum += assign[i];
        }
        return sum;
    }
};
