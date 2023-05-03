50. Pow(x, n)
Medium
7.1K
7.4K
Companies
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).



Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25

solution

class Solution {
public:
    double myPow(double x, int n) {
        if (n == INT_MAX) return (x == 1) ? 1 : (x == -1) ? -1 : 0;
        if (n == INT_MIN) return (x == 1 || x == -1) ? 1 : 0;
        double p=1;
        if(n>=0)
        {
        while(n)
        {
            p=p*x;
            n--;
        }
        return p;
        }
        else
        {
            n=-n;
            while(n)
           {
            p=p*x;
            n--;
           }
        p=1.0/p;
        return p;
        }
    }
};
