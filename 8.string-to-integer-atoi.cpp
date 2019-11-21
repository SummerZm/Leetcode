/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
class Solution {
public:
    // 1. +/-
    // 2. 333ss
    // 3. ss333
    // 4. Max-Min
    int myAtoi(string str) {
        int i=0, ret=0, sign=1;
        int len = str.length();
        if (len==0) return ret;
        while (str[i]==' ') i++; // skip whitespace.
        if (str[i]=='-') {
            sign=-1;
            i++;
        }
        else if (str[i]=='+') {
            i++;
        }
        while (str[i]<='9' && str[i]>='0' && i<len) 
        {
            // cheak overflow
            if (ret>INT_MAX/10 || (ret==INT_MAX/10 && str[i]>'7')) return INT_MAX;
            if (ret<INT_MIN/10 || (ret==INT_MIN/10 && str[i]>'8')) return INT_MIN;
            ret = ret*10 + (str[i]-48)*sign; // sign and char offset
            if (ret>0) ret *= sign; 
            i++;
        }
        return ret;
    }
};
// @lc code=end

