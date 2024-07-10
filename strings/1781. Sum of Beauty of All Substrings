The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.
For example, the beauty of "abaacc" is 3 - 1 = 2.
Given a string s, return the sum of beauty of all of its substrings.

Example 1:
Input: s = "aabcb"
Output: 5
Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.

Example 2:
Input: s = "aabcbaa"
Output: 17

class Solution {
public:

    int beauty(vector<int>&alpha){
        int maxFreq=-1;
        int lowFreq=1e9;
        for(int i=0;i<26;i++){
            maxFreq=max(maxFreq,alpha[i]);
            if(alpha[i]>=1)
            lowFreq=min(lowFreq,alpha[i]);
        }
        return maxFreq-lowFreq;
    }
    int beautySum(string s) {
       int res=0;
    //    substring
    for(int i=0;i<s.size();i++){
        vector<int>alpha(26,0);
        for(int j=i;j<s.size();j++){
            alpha[s[j]-'a']++;
            res=res+beauty(alpha);
        }
    }
    return res;
    }
};
