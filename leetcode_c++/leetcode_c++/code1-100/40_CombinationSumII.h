#pragma once
#include "../base.h"


class Solution40 : public Solution
{
public:
	virtual void test()
	{
		vector<int> candidates{ 10,1,2,7,6,1,5 };
		vector<vector<int>> res = combinationSum2(candidates, 8);
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
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		int len = candidates.size();
		vector<vector<int>> res;

		if (len == 0)
		{
			return res;
		}
		sort(candidates.begin(), candidates.end());

		vector<int> path;
		dfs(candidates, 0, path, res,target);
		return res;
	}

	void dfs(vector<int>& candidates, int begin, vector<int>& path, vector<vector<int>>& res,int target)
	{
		if (target==0)
		{
			res.emplace_back(path);
			return;
		}

		for (int i = begin; i < candidates.size(); i++)
		{
			if (target-candidates[i]<0)
			{
				break;
			}
			//关键点删除同元素  i>begin删除不同级的同元素
			if (i>begin&&candidates[i]==candidates[i-1])
			{
				continue;
			}

			path.emplace_back(candidates[i]);
			dfs(candidates, i+1 , path, res, target - candidates[i]);
			path.pop_back();

		}
	}
};

/*
给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用一次。

说明：

所有数字（包括目标数）都是正整数。
解集不能包含重复的组合。
示例 1:

输入: candidates = [10,1,2,7,6,1,5], target = 8,
所求解集为:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]


*/