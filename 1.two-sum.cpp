/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start

/* 
 * @Type: Inner search.
 * @Comment: This question look like a set reflect itself with a rule. 
 * @Performatence: Due to which STL containor you choose. Some containor are good at the Search-Problem.
 *
*/
class Solution {
public:
	// Solution space: Use Space to exchange time. [n]
	// Ex: 1. [nums] --> rule --> [map] (n)
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0;
        map<int, int> nummap;
        vector<int> result;
        for (i=0; i<nums.size(); i++) {
            int indics = target - nums[i];
			// [1 or logn or ...]
            if (nummap.find(indics)!=nummap.end() && i!=nummap[indics]) 
            {
                result.push_back(i);
                result.push_back(nummap[indics]);
                return result;
            }
            nummap[nums[i]] = i;
        }
        return result;
    }


	// Solution space: [enum violence] [n*n]
	// Ex:
	//  1		-
	//  2     -
	//  3   -
	//  4 -
	//  5 4 3 2 1
    vector<int> twoSumV1(vector<int>& nums, int target) {
		int i, j;
        vector<int> result;
		for (i=0; i<nums.size(); i++) {
			for (j=0; j<nums.size(); j++) {
				if( i!=j && nums[i]+nums[j]==target ) {
					result.push_back(i);
					result.push_back(j);
					return result;
				}
			}
		}
		return result;
	}

};
// @lc code=end

