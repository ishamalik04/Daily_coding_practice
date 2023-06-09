/* Find the Missing Number
Given an array arr[] of size N-1 with integers in the range of [1, N], the task is to find the missing number from the first N integers.

Note: There are no duplicates in the list.

Examples:

Input: arr[] = {1, 2, 4, 6, 3, 7, 8}, N = 8
Output: 5
Explanation: The missing number between 1 to 8 is 5*/
#include<stdio.h>
int main()
{
    int n;
    printf("\nenter number of elements: \t");
    scanf("%d",&n);
    int arr[n];
    printf("\nenter array elements: \t");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int temp[n+1];
    for(int i=0;i<=n;i++)
    {
        temp[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        temp[arr[i]-1]=1;
    }
    int ans;
    for(int i=0;i<=n;i++)
    {
        if(temp[i]==0)
        {
            ans=i+1;
        }
    }
    printf("\n%d is the missing value",ans);
}
/* Time complexity -O(N)
   Space complexity-O(N)  */
/*
   Second approach.
   Find the sum of the numbers in the range [1, N] using the formula N * (N+1)/2.
   Now find the sum of all the elements in the array and subtract it from the sum of the first N natural numbers.
   This will give the value of the missing element.

   Time complexity-O(N)
   Space complexity-O(1)   */
