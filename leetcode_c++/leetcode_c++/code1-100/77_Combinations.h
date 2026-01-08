#pragma once
/*
给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

示例:

输入:n = 4, k = 2
输出:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

#include "../base.h"
class Solution77 : public Solution
{
public:
	virtual void test()
	{
		vector<vector<int>> res = combine1(4, 2);
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
	int target;
	vector<vector<int>> combine(int n, int k)
	{
		target = k;
		vector<vector<int>> res;
		vector<int> path;
		dfs(n, 1, path, res);

		return res;
	}

	void dfs(int n, int depth, vector<int> &path, vector<vector<int>> &res)
	{
		if (path.size() == target)
		{
			cout << " depth=" << depth << endl;

			res.emplace_back(path);
			return;
		}
		//		for (int i = depth; i <= n; i++)
		// 搜索起点的上届+接下来要选择的元素个数-1=n
		// 上届+(k-path.size())-1=n
		// 上届=n-(k-path.size())+1
		for (int i = depth; i <= n - (target - path.size()) + 1; i++)
		{
			// if (i-depth==n-target+1)
			//{
			//	break;
			// }
			path.emplace_back(i);
			cout << "递归之前 => ";
			for (int k = 0; k < path.size(); k++)
			{
				cout << path[k] << " ";
			}
			cout << "，i = " << i << " depth=" << depth << endl;

			dfs(n, i + 1, path, res);
			path.pop_back();
			cout << "递归之后=> ";
			for (int k = 0; k < path.size(); k++)
			{
				cout << path[k] << " ";
			}
			cout << "，i = " << i << " depth=" << depth << endl;
		}
	}
	vector<vector<int>> m_res;

	vector<vector<int>> combine1(int n, int k)
	{
		vector<int> nums;
		for (auto i = 1; i <= n; i++)
		{
			nums.emplace_back(i);
		}

		vector<int> track;
		vector<bool> flags(n, false);

		backtrack(nums, track,  k,0);
		return m_res;
	}

	void backtrack(vector<int> &nums, vector<int> &track, int k, int tag)
	{
		if (track.size() == k)
		{
			m_res.emplace_back(track);
			return;
		}

		for (auto i = tag; i < nums.size(); i++)
		{
			track.emplace_back(nums[i]);
			backtrack(nums, track,k,i+1);
			track.pop_back();
		}
	}
};