/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring1(string s) {
		int i, j, k, lastest, max=1;
		int n = s.length();
        if (n==0) return n; // Empty input.
        
        for (i=0; i<n; i++) 
        {
            lastest = 1;
            for (j=i+1; j<n; j++)   // Cut down repeat compare.
            {     
                if (lastest==0) break;
				for (k=i; k<j; k++) 
				{   
					if (s[k]==s[j]) {
						lastest=0;
						break;
					}
				}
				if (lastest==0) break;
                else lastest += 1; 
                if (max<lastest) max = lastest; // Get max length
            }
        } 
		return max;
	}

	// Find table. -- memory limit
    int lengthOfLongestSubstringV2(string s) {
		int i, j, k, lastest, max=1;
		int n = s.length();
        if (n==0) return n; // Empty input.
        
        char** arr = new char*[n]();
        for (i=0; i<n; i++) arr[i] = new char[n]();
        // Init table.
        for (i=0; i<n; i++)
            for (j=0; j<n; j++)
                arr[i][j] = -1;

        for (i=0; i<n; i++) 
        {
            lastest = 1;
            for (j=i+1; j<n; j++)   // Cut down repeat compare.
            {     
                if (lastest==0) break;
                if (arr[i][j] == 0) // Find in table.
                {
                    lastest=0;
                    break;
                }
                else if (arr[i][j] == 1)    // Find in table.
                {
                    lastest += 1; 
                }
                else //  If j duplicate in [i, j)
                {
                    for (k=i; k<j; k++) 
                    {   
                        if (s[k]==s[j]) {
                            lastest=0;
                            arr[i][j] = 0;
                            break;
                        }
                    }
                    if (lastest==0) break;
                    else lastest += 1; 
                    arr[i][j] = 1;
                }
                if (max<lastest) max = lastest; // Get max length
            }
        } 
		return max;
    }

	// Find table. -- memory limit
    int lengthOfLongestSubstringV1(string s) {
        int i, j, k, max=1;
		int n = s.length();
		std::vector<std::vector<int>> table(n, std::vector<int>(n));

        if(n==0) return 0;
		// init table 
		for (i=0; i<n; i++) 
			for (j=0; j<n; j++)
				table[i][j] = 1;

		// create table
		for (i=0; i<n; i++) 
        {
            for (j=i+1; j<n; j++) 
            {
                // 查表 -- 对比
			    if (table[i][j-1]==0) 
                {
                    table[i][j] = 0;
                }
                else 
                {
                    table[i][j] = table[i][j-1] + 1;
                    for(k=i; k<j; k++)  
                        if(s[k]==s[j]) 
                            table[i][j] = 0;
                    if (max<table[i][j]) max = table[i][j];
                }
            }
		}
		return max;
    }  


};
// @lc code=e(n, std::vector<int>(n));

        // ini        // init table
