1582. Special Positions in a Binary Matrix
Easy
609
22
Companies
Given an m x n binary matrix mat, return the number of special positions in mat.

A position (i, j) is called special if mat[i][j] == 1 and all other elements in row i and column j are 0 (rows and columns are 0-indexed).



Example 1:


Input: mat = [[1,0,0],[0,0,1],[1,0,0]]
Output: 1
Explanation: (1, 2) is a special position because mat[1][2] == 1 and all other elements in row 1 and column 2 are 0.
Example 2:


Input: mat = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
Explanation: (0, 0), (1, 1) and (2, 2) are special positions.


solution

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int res=0;
        vector<int> row(mat.size(),0);// sum of row
        vector<int> col(mat[0].size(),0);// sum of col

        for(int i=0;i<mat.size();i++)
        {
            int t=0;
            for(int j=0;j<mat[0].size();j++)
                t+=mat[i][j];
            row[i]=t;
        }
        for(int j=0;j<mat[0].size();j++)
        {
            int t=0;
            for(int i=0;i<mat.size();i++)
                t+=mat[i][j];
            col[j]=t;
        }

        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
            // row and col ==1 means mat[i][j]==1 was only the element in the row and col ( special )
                if(mat[i][j]==1 && row[i]==1 && col[j]==1)
                    res++;
            }
        }
        return res;
    }
};
