4. Median of Two Sorted Arrays
Hard
23.2K
2.6K
Companies
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).



Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.


solution

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int n1=nums1.size();
        int n2=nums2.size();
        int i=0;
        int j=0;
        int lastindex=-1;

        vector<int>v(n1+n2,0);

        while(i<n1&&j<n2)
        {
            if(nums1[i]<=nums2[j])
                v[++lastindex]=nums1[i++];
            else
                v[++lastindex]=nums2[j++];
        }

        while(i<n1)
            v[++lastindex]=nums1[i++];
        while(j<n2)
            v[++lastindex]=nums2[j++];

        int n=n1+n2;
        return n%2?v[n/2]:(v[n/2]+v[n/2-1])/2.0;

    }
};
