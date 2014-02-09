/*
Gas Station
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.
*/

/*
Feb 9 2014
Time Limit Exceeded for O(n^2) solution.
Note:
-- if start from i and stop at j, which means any stop between i and j won't work as a start station.

Reference:
http://discuss.leetcode.com/questions/1995/gas-station-problem
*/
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        if (gas.empty() || gas.size() != cost.size()) return -1;
        int tank = 0, flag = 0, n = cost.size(), start=0;
        int index;
        while(start < n)
        {
            if(gas[start] < cost[start])
            {
                start++;
            }
            else
            {
                index = start;
                flag = 0;
                tank = 0;
                while(flag < n)
                {
                    if (tank + gas[index%n] >= cost[index%n])
                    {
                        flag++;
                        tank += (gas[index%n] - cost[index%n]);
                        index++;
                        if (flag == n) return start;
                    }
                    else
                    {
                        // the max func is important here, incase start never moves
                        start = max(index, start + 1);
                        break;
                    }
                }
            }
        }
        return -1;
    }
};


// a reference
public int canCompleteCircuit(int[] gas, int[] cost) {
    int i,start,sum,len = gas.length;

    for(i=0;i<len;i++) gas[i]-=cost[i]; //let's keep difference in gas[]

    start=0;
    while(true){

        for(    ;start<len && gas[start]<0; start++); //find first non-negative diff

        if(start==len) break;  //we've checked everything, there is no solution

        for(sum=0,i=start;i<(len+start) && sum>=0;i++) sum+=gas[i%len]; //check route, if sum is negotive at any step then we used wrong starting pos.

        if(sum>=0 && i==(len+start)) return start; //since it's should be unique, then we've found it!

        for(    ;start<len && gas[start]>=0; start++); //find first negative diff

        if(start==len) break;   //we've checked everything, there is no solution
    }

    return -1;
}

