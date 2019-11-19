/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 */

// @lc code=start
class Solution {
public:
    static bool ascend(int i, int j) { return i>j; }
    string convert(string s, int numRows) {
        // numRows > 0
        string result=s;
        map<int, int> zigzagMap;
        map<int, int>::iterator it;
        //vector<int> zigzagMap;
        int len = s.length();
        if(len<=2) return s;

        if (numRows>1)
        {
            int circle = 2*(numRows-1); // 周期 3 -> 4
            int circleX = numRows-1;    // 步进 3 -> 2
            int RowLen = (len/circle+1)*circleX; // 行宽 = 步进 * 总周期数
            int loop = -1;  // 周期计数

            for (int i=0; i<len; i++) 
            {
                int index = 0;
                int remainder = i%circle; //[0, 4)
                if (remainder==0) loop++;
                if (remainder<numRows) // [0, 3)
                {
                    // 行宽*所在行数 + 周期*步进
                    index = RowLen*remainder+loop*circleX;
                    zigzagMap[RowLen*remainder+loop*circleX] = i;
                    //zigzagMap.push_back(RowLen*remainder+loop*circleX);
                }
                else {
                    // 行宽*所在行数 + 周期*步进 + 锯齿渐进
                    index = RowLen*(circle-remainder)+loop*circleX+(remainder-numRows+1);
                    zigzagMap[RowLen*(circle-remainder)+loop*circleX+(remainder-numRows+1)] = i;
                    //zigzagMap.push_back(RowLen*(circle-remainder)+loop*circleX+(remainder-numRows+1));
                }
                //std::cout<<index<<'['<<s[i]<<']'<<" ";
            
            }
            /*
            sort(zigzagMap.begin(), zigzagMap.end(), ascend);
            for (int i=0; i<zigzagMap.size(); i++)
            {
                result[i] = s[zigzagMap[i]];
            }*/
            int j=0;
            for (it=zigzagMap.begin(); it!=zigzagMap.end(); it++)
            {
                result[j] = s[it->second];
                j++;
                //std::cout<<it->first<<'['<<s[it->second]<<']'<<std::endl;
            }
            return result;
        }
        return result;
    }
};
// @lc code=end

