#include<iostream>
#include<vector>
using namespace std;
/*
JAN 16 2014
Solution:
the idea is binary search. note the quit condition of binary search, especially when the target is not in the array.
*/
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> range(2, -1);
        int start, end;
        int tmp1=0,tmp2=n-1;
        int index;
        while(tmp1 <= tmp2)
        {
            index = (tmp1 + tmp2)/2;
            if (A[index] == target)
            {
                range[0] = searchleftmost(A, 0, index, target);
                range[1] = searchrightmost(A, index, n-1, target);
                break;
            }
            else
            {
                // This test have to happen before the modification in > or < cases, otherwise we may miss the tailored tmp1 and tmp2 situation.
                if (tmp1 == tmp2) break;
            }
            if (A[index] > target)
            {
                tmp2 = index;
            }
            if (A[index] < target)
            {
                tmp1 = index + 1;
            }
        }
        return range;
    }
    int searchleftmost(int A[], int start, int end, int target)
    {
        int tmp1 = start;
        int tmp2 = end;
        int index = end;
        while(tmp1 <= tmp2)
        {
            index = (tmp1+tmp2)/2;
            if (tmp1 == tmp2)
            {
                return index;
            }
            if (A[index] < target)
            {
                tmp1 = index + 1;
            }
            if (A[index] == target)
            {
                if (index == 0)
                {
                    return index;
                }
                else
                {
                    if (A[index-1] < target)
                    {
                        return index;
                    }
                    else
                    {
                        tmp2 = index;
                    }
                }
            }
        }
        return index;
    }
    int searchrightmost(int A[], int start, int end, int target)
    {
        int tmp1 = start; 
        int tmp2 = end; 
        int index = start; 
        while(tmp1 <= tmp2)
        {
            index = (tmp1+tmp2)/2; 
            if (tmp1 == tmp2)
            {
                return index;
            }
            if (A[index] > target)
            {
                tmp2 = index;
            }
            if (A[index] == target)
            {
                if (index == end)
                {
                    return index;
                }
                else
                {
                    if (A[index+1] > target)
                    {
                        return index;
                    }
                    else
                    {
                        tmp1 = index+1;
                    }
                }
            }
        }
        return index;
    }
};

int main()
{
    int A[] = {1,4};
    int target = 4;
    vector<int> range = searchRange(A, 2, target);
    cout<<range[0]<<","<<range[1]<<endl;
}
