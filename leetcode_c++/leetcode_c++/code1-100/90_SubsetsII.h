#pragma once
/*
给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: [1,2,2]
输出:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subsets-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include "../base.h"
class Solution90 : public Solution
{
public:
	virtual void test()
	{
		vector<int> nums{ 1,2,2 };
		vector<vector<int>> res = subsetsWithDup(nums);
		for (size_t i = 0; i < res.size(); i++)
		{
			for (int j = 0; j < res[i].size(); j++)
			{

				cout << res[i][j] << "  ";
			}
			cout << endl;
		}
	}

private:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> res;
		if (nums.size() == 0)
		{
			return res;
		}
		sort(nums.begin(), nums.end());
		vector<int> path;
		dfs(nums, 0, path, res);
		return res;
	}


	void dfs(vector<int>& nums, int depth, vector<int>& path, vector<vector<int>>& res)
	{
		res.emplace_back(path);
		for (int i = depth; i < nums.size(); i++)
		{
			if (i>depth&&nums[i]==nums[i-1])
			{
				continue;
			}
			path.emplace_back(nums[i]);
			cout << "i=" << i << " depth=" << depth<<" ";
			for (int k = 0; k < path.size(); k++)
			{
				cout << path[k]<<" ";
			}
			cout << endl;
			dfs(nums, i + 1, path, res);
			path.pop_back();
		}
	}
};
