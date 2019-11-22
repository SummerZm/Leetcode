/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum1(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        vector<int> ans;  
        int len = nums.size();
        int a, b, c, d;
        for (a=0; a<len; a++) 
        {
            for (b=a+1; b<len; b++)		// why add 1 ?
            {
                for (c=b+1; c<len; c++)
                {
                    for (d=c+1; d<len; d++)
                    {
                        if(nums[a]+nums[b]+nums[c]+nums[d]==target &&
                           a!=b && a!=c && a!=d && b!=c && b!=d && c!=d) {
                            ans.clear();
                            ans.push_back(nums[a]);
                            ans.push_back(nums[b]);
                            ans.push_back(nums[c]);
                            ans.push_back(nums[d]);
                            sort(ans.begin(), ans.end()); // Create unorder relation of subitem for clear duplicate item.
                            ret.push_back(ans);
                        }
                    }
                }
            }
        }
        sort(ret.begin(), ret.end());
        ret.erase(unique(ret.begin(), ret.end()), ret.end());
        return ret;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
    }
};
// @lc code=end
