/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int len3 = len1+len2;
        int start1=0, start2=0, pos=0;
        int* nums3 = new int[len3]();
        while (start1<len1 && start2<len2) 
            nums3[pos++] = nums1[start1] < nums2[start2] ? nums1[start1++] : nums2[start2++];
        while (start1<len1)
            nums3[pos++] = nums1[start1++];
        while (start2<len2)
            nums3[pos++] = nums2[start2++];

        if(len3%2!=0) {
            return nums3[(len3-1)/2] * 1.0;
        }
        else {
            return (nums3[len3/2] + nums3[len3/2-1]) / 2.0;
        }
    }
};
// @lc code=end

