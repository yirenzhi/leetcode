#pragma once
/*
����һ�鲻���ظ�Ԫ�ص��������� nums�����ظ��������п��ܵ��Ӽ����ݼ�����

˵�����⼯���ܰ����ظ����Ӽ���

ʾ��:

����: nums = [1,2,3]
���:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

*/

#include "../base.h"
class Solution78 : public Solution
{
public:
	virtual void test()
	{
		vector<int> nums{ 1,2,3 };
		vector<vector<int>> res = subsets(nums);
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
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> res;
		if (nums.size()==0)
		{
			return res;
		}
		vector<int> path;
		dfs(nums, 0, path, res);
		return res;
	}

	void dfs(vector<int>& nums, int depth, vector<int>& path, vector<vector<int>>& res)
	{
		res.emplace_back(path);
		for (int i = depth; i < nums.size(); i++)
		{

			path.emplace_back(nums[i]);
			//cout << "�ݹ�֮ǰ => ";
			//for (int k = 0; k < path.size(); k++)
			//{
			//	cout << path[k] << " ";
			//}
			//cout << "��i = " << i << " depth=" << depth << endl;

			dfs(nums, i + 1, path, res);
			path.pop_back();
			//cout << "�ݹ�֮��=> ";
			//for (int k = 0; k < path.size(); k++)
			//{
			//	cout << path[k] << " ";
			//}
			//cout << "��i = " << i << " depth=" << depth << endl;
		}
	}

};