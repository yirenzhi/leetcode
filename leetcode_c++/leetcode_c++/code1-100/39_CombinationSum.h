#pragma once
#include "../base.h"


class Solution39 : public Solution
{
public:
	virtual void test()
	{
		//vector<int> nums{ 1,1,3 };
		vector<int> nums{ 2,3,5 };
		vector<vector<int>> res = combinationSum2(nums,8);
		for (size_t i = 0; i < res.size(); i++)
		{
			for (int j = 0; j < res[i].size(); j++)
			{

				cout << res[i][j] << "  ";
			}
			cout << endl;
		}
	}

	//官方解法
	void dfs2(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& combine, int idx) {
		if (idx == candidates.size()) {
			return;
		}
		if (target == 0) {
			ans.emplace_back(combine);
			return;
		}
		// 直接跳过
		dfs2(candidates, target, ans, combine, idx + 1);
		// 选择当前数
		if (target - candidates[idx] >= 0) {
			combine.emplace_back(candidates[idx]);
			dfs2(candidates, target - candidates[idx], ans, combine, idx);
			combine.pop_back();
		}
	}

	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> ans;
		vector<int> combine;
		dfs2(candidates, target, ans, combine, 0);
		return ans;
	}



	//自己解法
	int m_target;
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		m_target = target;
		sort(candidates.begin(), candidates.end());
		int len = candidates.size();
		vector<vector<int>> res;
		if (len == 0)
		{
			return res;
		}

		vector<int> path;
		dfs(candidates, len, 0, path, res);
		return res;
	}

	int sumVec(vector<int> vec)
	{
		int count = 0;
		for (size_t i = 0; i < vec.size(); i++)
		{
			count += vec[i];
		}
		return count;
	}

	void dfs(vector<int> nums, int len, int depth, vector<int>& path, vector<vector<int>>& res) {
		
		if (sumVec(path) == m_target)
		{
			//
			res.push_back(path);
			return;
		}
		if (sumVec(path) > m_target)
		{
			//
			return;
		}
		if ((m_target/nums[0]) == depth)
		{
			return;
		}

		for (int i = 0; i < len; i++)
		{

			if (path.size()>0&&nums[i] < path.back())
			{
				continue;
			}
			path.emplace_back(nums[i]);
			dfs(nums, len, depth + 1, path, res);
			path.pop_back();

		}
	}

};

/*
给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的数字可以无限制重复被选取。

说明：

所有数字（包括 target）都是正整数。
解集不能包含重复的组合。
示例 1：

输入：candidates = [2,3,6,7], target = 7,
所求解集为：
[
  [7],
  [2,2,3]
]
示例 2：

输入：candidates = [2,3,5], target = 8,
所求解集为：
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
*/