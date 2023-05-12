709. To Lower Case
Easy
1.6K
2.6K
Companies
Given a string s, return the string after replacing every uppercase letter with the same lowercase letter.



Example 1:

Input: s = "Hello"
Output: "hello"
Example 2:

Input: s = "here"
Output: "here"

solution

class Solution {
public:
    string toLowerCase(string s) {
        for(int i=0; i<s.size(); i++){
            s[i]=tolower(s[i]);
        }
        return s;
    }
};
