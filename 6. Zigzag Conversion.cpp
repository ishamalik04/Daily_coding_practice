6. Zigzag Conversion
Medium
6.1K
12.2K
Companies
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);


Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
Example 3:

Input: s = "A", numRows = 1
Output: "A"


solution


class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)
        {
            return s;
        }
        int len=s.length(),pos=numRows-1,k=0,col;
        if(len==1)
        {
            return s;
        }
        char a[numRows][len];
        string res;
        for(int j=0;j<len;j++)
        {
            if(k>=len)
            {
                col=j;
                break;
            }
            if(pos==0)
            {
                pos=numRows-1;
            }
            if(pos==numRows-1)
            {
                for(int i=0;i<numRows;i++)
                {
                    if(k<len)
                    {
                        a[i][j]=s[k++];
                    }
                    else
                    {
                        a[i][j]='$';
                    }
                }
            }
            else
            {
                for(int i=0;i<numRows;i++)
                {
                    if(pos==i && k<len)
                    {
                        a[i][j]=s[k++];
                    }
                    else
                    {
                        a[i][j]='$';
                    }
                }
            }
            pos--;
        }
        for(int i=0;i<numRows;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(a[i][j]!='$')
                {
                    res=res+a[i][j];
                }
            }
        }
        return res;
    }
};
