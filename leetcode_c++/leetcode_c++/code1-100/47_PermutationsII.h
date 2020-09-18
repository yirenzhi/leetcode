#pragma once
#include "../base.h"


class Solution47 : public Solution
{
public:
	//��д�Ĵ𰸺͹ٷ��𰸵Ĳ�࣬�����������С�㷨ʱ��
	//1.�����ӵ��жϷŵ�forѭ����ʼ�ĵط�����ֱ���� if ((i > 0 && nums[i] == nums[i - 1] && !used[i - 1]))�����ʽ���ж�
	//2.����vector<bool> used��������������ڲ����б�����Խ�ʡʱ��
	//3.�������б���Ĳ����������ã���ʡʱ��
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