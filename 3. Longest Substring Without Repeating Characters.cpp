3. Longest Substring Without Repeating Characters
Medium
33.6K
1.5K
Companies
Given a string s, find the length of the longest
substring
 without repeating characters.



Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.


solution

class Solution {
public:
        int lengthOfLongestSubstring(string s) {
        int length=0 , maxlength=0,j=0;
        map<char ,int> mp;
        for(int i=0 ;i<s.size(); i++){
            mp[s[i]]++;
            length++;
                while(mp[s[i]]>1){
                    mp[s[j++]]--;
                    length--;
                }
            maxlength = max(maxlength,length);
        }
        return maxlength;
    }
};
