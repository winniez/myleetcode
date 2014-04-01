/*
Sqrt(x)
Implement int sqrt(int x).

Compute and return the square root of x.
*/

/*
Mar 31 2014
Solution 1: 
binary search within solution space. [0 - (x+1)/2]

Solution 2:
Newton 

Reference:
http://www.cnblogs.com/AnnieKim/archive/2013/04/18/3028607.html
http://en.wikipedia.org/wiki/Newton%27s_method
*/

// Solution 1
class Solution {
public:
    int sqrt(int x) {
        assert(x>=0);
        long long start = 0;
        long long end = x/2 + 1; // y - 2*sqrt(y) + 1 >= 0 => (y+1)/2 >= sqrt(y)
        long long mid, square;
        while(start <= end)
        {
            mid = (start+end)/2;
            square = mid*mid;
            if (square == x) return mid;
            else if (square < x) start = mid+1;
            else end = mid - 1;
        }
        return end;
    }
};

// Solution 2
class Solution {
public:
    int sqrt(int x){
        assert(x>=0);
        if (x == 0) return 0;
        double x1 = x/2 + 1, x2 = 0;
        // newton iteration
        // f(x) = f(x_i) + f’(x_i)(x - x_i)  = f(x_i)+2*x_i(x-x_i) = 0>
        // x_{i+1} = x_i - (x_i^2 - x)/(2*x_i) = x_i/2+n/(2*x_i) = (x_i+x/x_i)/2
        while(x1 != x2)
        {
            x2 = x1;
            x1 = (x2 + x/x2)/2;
        }
        return (int)x1;
    }
};
