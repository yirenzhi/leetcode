#pragma once

/*
In a string s of lowercase letters, these letters form consecutive groups of the same character.

For example, a string like s = "abbxxxxzyy" has the groups "a", "bb", "xxxx", "z", and "yy".

A group is identified by an interval [start, end], where start and end denote the start and end indices (inclusive) of the group. In the above example, "xxxx" has the interval [3,6].

A group is considered large if it has 3 or more characters.

Return the intervals of every large group sorted in increasing order by start index.



Example 1:

Input: s = "abbxxxxzzy"
Output: [[3,6]]
Explanation: "xxxx" is the only large group with start index 3 and end index 6.
Example 2:

Input: s = "abc"
Output: []
Explanation: We have groups "a", "b", and "c", none of which are large groups.
Example 3:

Input: s = "abcdddeeeeaabbbcd"
Output: [[3,5],[6,9],[12,14]]
Explanation: The large groups are "ddd", "eeee", and "bbb".
Example 4:

Input: s = "aba"
Output: []


*/
#include "../base.h"

class Solution830 : public Solution
{
public:
	virtual void test()
	{
		string s = "abcdddeeeeaabbbcd";
		vector<vector<int>> result = largeGroupPositions(s);
		for (size_t i = 0; i < result.size(); i++)
		{
			for (int j = 0; j < result[i].size(); j++)
			{
				cout << result[i][j] << "   ";
			}
			cout << endl;
		}
	}

private:
	vector<vector<int>> largeGroupPositions(string s) {
		int len1 = s.size();
		int begin=0, end = 0;
		char cur_c='a'-1;
		vector<vector<int>> result;
		for (size_t i = 0; i < len1; i++)
		{
			if (cur_c==s[i])
			{
				end++;
			}
			if (cur_c != s[i] || i == len1 - 1)
			{
				cur_c = s[i];
				if (end-begin>=2)
				{
					result.push_back({begin,end});
				}
				begin = i;
				end = i;
			}
		}
		return result;
	}
};