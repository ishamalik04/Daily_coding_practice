59. Spiral Matrix II
Medium
5.4K
227
Companies
Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.



Example 1:


Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]
Example 2:

Input: n = 1
Output: [[1]]


solution

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
      int top=0,down=n-1,left=0,right=n-1,dir=0;
      vector<vector<int>>matrix(n,vector<int>(n));
      int val=1;
      while(top<=down && left<=right)
      {
          if(dir==0)
          {
              for(int i=left;i<=right;i++)
              {
                  matrix[top][i]=val++;
              }
              top++;
          }
          else if(dir==1)
          {
              for(int i=top;i<=down;i++)
              {
                  matrix[i][right]=val++;
              }
              right--;
          }
          else if(dir==2)
          {
              for(int i=right;i>=left;i--)
              {
                  matrix[down][i]=val++;
              }
              down--;
          }
          else if(dir==3)
          {
              for(int i=down;i>=top;i--)
              {
                  matrix[i][left]=val++;
              }
              left++;
          }
          dir=(dir+1)%4;
      }
      return matrix;
    }
};
