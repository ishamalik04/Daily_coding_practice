744. Find Smallest Letter Greater Than Target
Easy
3K
2K
Companies
You are given an array of characters letters that is sorted in non-decreasing order, and a character target. There are at least two different characters in letters.

Return the smallest character in letters that is lexicographically greater than target. If such a character does not exist, return the first character in letters.



Example 1:

Input: letters = ["c","f","j"], target = "a"
Output: "c"
Explanation: The smallest character that is lexicographically greater than 'a' in letters is 'c'.
Example 2:

Input: letters = ["c","f","j"], target = "c"
Output: "f"
Explanation: The smallest character that is lexicographically greater than 'c' in letters is 'f'.
Example 3:

Input: letters = ["x","x","y","y"], target = "z"
Output: "x"
Explanation: There are no characters in letters that is lexicographically greater than 'z' so we return letters[0].



solution

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {

        int low=0;
        int high=letters.size()-1;

        if(letters[0] > target)
          return letters[0];

        else if(target >= letters[letters.size()-1])
        return letters[0];

        char ans;

        while( low <= high)
        {
            int mid=(low+high)/2;

             if(letters[mid] > target){
                 ans = letters[mid];
                 high = mid-1;
             }

             else
             low = mid+1;

        }

        return ans;

    }
};
