/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int font, after, start, maxLen=0, currLen=0;
        int len = s.length();
        if (len<=1) return s;
        for (int i=1; i<len; i++)
        {
            currLen=1;
            font = i-1;
            after = i+1;
            while ( font>=0 && s[font]==s[i]) {
                    currLen++;
                    font--;
            }
            while (after<len && s[after]==s[i]) {
                    currLen++;
                    after++;
            }
            //while ( font>=0 && after<len && s[font--]==s[after++]) currLen += 2;
            while ( font>=0 && after<len && s[font]==s[after]) {
                currLen += 2;
                font--;
                after++;
            }
            if (currLen>maxLen) {
                    maxLen = currLen;
                    start = font+1;
                    std::cout<<"i+ "<<i<<" Maxlen: "<<maxLen<<std::endl;
            }
        }
        return s.substr(start, maxLen);
    }
};
// @lc code=end

