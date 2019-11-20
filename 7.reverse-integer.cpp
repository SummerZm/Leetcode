/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) 
    {
        int ret = 0, val = 0;
        while(x!=0) 
        {
            // pop
            val = x%10;
            x /= 10;
            // push
            if ((ret==INT_MAX/10 && val>7) || ret>INT_MAX/10 ) return 0;
            if ((ret==INT_MIN/10 && val<-8) || ret<INT_MIN/10 ) return 0;
            ret = ret*10+val;
        }
        return ret;
    }
};
// @lc code=end

