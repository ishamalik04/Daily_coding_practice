7. Reverse Integer
Medium
10.5K
12K
Companies
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).



Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321


solution

class Solution {
public:
    int reverse(int x) {
        if(x==INT_MIN || x==INT_MAX)
        {
            return 0;
        }
        int rev=0;
        while(x)
        {
            if(rev<INT_MIN/10 || rev>INT_MAX/10)
            {
                return 0;
            }
            rev=rev*10+x%10;
            x=x/10;
        }
        return rev;
    }
};
