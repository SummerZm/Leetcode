/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> item;
        sort(candidates.begin(), candidates.end());
        _combinationSum(candidates, target, result, item);
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()),  result.end());
        return result;
    }


    bool _combinationSum(vector<int>& candidates, int target, vector<vector<int>>& table, vector<int> item)
    {
        bool ret = false;
        if (target<candidates[0]) return ret;
        for (int i=0; i<candidates.size(); i++) 
        {
            item.push_back(candidates[i]);
            if (target < candidates[i]) ret = false;
            else if (target-candidates[i] > 0) ret = _combinationSum(candidates, target-candidates[i], table, item);
            else {
                sort(item.begin(), item.end());
                table.push_back(item); // (target-candidates[i] == 0)
            }
            item.pop_back();
        }
        return ret;
    }
};
// @lc code=end

