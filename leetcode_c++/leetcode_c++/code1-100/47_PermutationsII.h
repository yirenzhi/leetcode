#pragma once
/*
给定一个可包含重复数字的序列，返回所有不重复的全排列。

示例:

输入: [1,1,2]
输出:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/
#include "../base.h"


class Solution47 : public Solution
{
public:
	//我写的答案和官方答案的差距，有三点可以缩小算法时间
	//1.将增加的判断放到for循环开始的地方，且直接用 if ((i > 0 && nums[i] == nums[i - 1] && !used[i - 1]))这个形式来判断
	//2.增加vector<bool> used的类变量，不放在参数列表里，可以节省时间
	//3.将参数列表里的参数增加引用，节省时间
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int len = nums.size();
		vector<vector<int>> res;
		if (len == 0)
		{
			return res;
		}

		vector<int> path;
		vector<bool> used(len, false);
		dfs(nums, len, 0, path, used, res);
		return res;
	}
	void dfs(vector<int> nums, int len, int depth, vector<int> path, vector<bool> used, vector<vector<int>>& res) {
		if (len == depth)
		{
			//
			res.push_back(path);
			return;
		}	

		for (int i = 0; i < len; i++)
		{
			if (used[i])
			{
				continue;
			}
			if ((i > 0 && nums[i] == nums[i - 1] && !used[i - 1]))
			{
				continue;
			}
			used[i] = true;
			path.emplace_back(nums[i]);
			dfs(nums, len, depth + 1, path, used, res);
			path.pop_back();
			used[i] = false;
			//for ( ; i < len-1; i++)
			//{
			//	if (nums[i] != nums[i+1])
			//	{
			//		break;
			//	}
			//}
		}
	}


	vector<int> vis;
	void backtrack(vector<int>& nums, vector<vector<int>>& ans, int idx, vector<int>& perm) {
		if (idx == nums.size()) {
			ans.emplace_back(perm);
			return;
		}
		for (int i = 0; i < (int)nums.size(); ++i) {
			if (vis[i] ) {
				continue;
			}
			if ((i > 0 && nums[i] == nums[i - 1] && !vis[i - 1]))
			{
			continue;
			}
			perm.emplace_back(nums[i]);
			vis[i] = 1;
			backtrack(nums, ans, idx + 1, perm);
			vis[i] = 0;
			perm.pop_back();
		}
	}

	vector<vector<int>> permuteUnique2(vector<int>& nums) {
		vector<vector<int>> ans;
		vector<int> perm;
		for (int i = 0; i < nums.size(); i++)
		{
			vis.emplace_back(0);
		}
		//vis.permize(nums.size());
		sort(nums.begin(), nums.end());
		backtrack(nums, ans, 0, perm);
		return ans;
	}


	virtual void test()
	{
		//vector<int> nums{ 1,1,3 };
		vector<int> nums{ 1,1,3,4,9,3,5,7,6 };
		vector<vector<int>> res = permuteUnique2(nums);
		//for (size_t i = 0; i < res.size(); i++)
		//{
		//	for (int j = 0; j < res[i].size(); j++)
		//	{

		//		cout << res[i][j] << "  ";
		//	}
		//	cout << endl;
		//}
	}

private:

};