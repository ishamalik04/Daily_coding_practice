1822. Sign of the Product of an Array
Easy
1.1K
141
Companies
There is a function signFunc(x) that returns:

1 if x is positive.
-1 if x is negative.
0 if x is equal to 0.
You are given an integer array nums. Let product be the product of all values in the array nums.

Return signFunc(product).



Example 1:

Input: nums = [-1,-2,-3,-4,3,2,1]
Output: 1
Explanation: The product of all values in the array is 144, and signFunc(144) = 1


class Solution {
public:
    int arraySign(vector<int>& nums) {
        double x=1;
        for(int i=0;i<nums.size();i++)
        {
            x=x*nums[i];
        }
        if(x<0)
        {
            return -1;
        }
        if(x>0)
        {
            return 1;
        }
        return 0;
    }
};
