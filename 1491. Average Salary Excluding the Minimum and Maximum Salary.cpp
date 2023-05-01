1491. Average Salary Excluding the Minimum and Maximum Salary
Easy
1.4K
152
Companies
You are given an array of unique integers salary where salary[i] is the salary of the ith employee.

Return the average salary of employees excluding the minimum and maximum salary. Answers within 10-5 of the actual answer will be accepted.



Example 1:

Input: salary = [4000,3000,1000,2000]
Output: 2500.00000
Explanation: Minimum salary and maximum salary are 1000 and 4000 respectively.
Average salary excluding minimum and maximum salary is (2000+3000) / 2 = 2500


solution

class Solution {
public:
    double average(vector<int>& salary) {
        double max=INT_MIN,min=INT_MAX;
        for(int i=0;i<salary.size();i++)
        {
            if(salary[i]<min)
            {
                min=salary[i];
            }
            if(salary[i]>max)
            {
                max=salary[i];
            }
        }
        double sum=0;
        for(int i=0;i<salary.size();i++)
        {
            sum=sum+salary[i];
        }
        sum=sum-min-max;
        double x=salary.size();
        x=x-2;
        double average;
        average=sum/x;
        return average;
    }
};
