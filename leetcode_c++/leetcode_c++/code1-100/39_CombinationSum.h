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

	//�ٷ��ⷨ
	void dfs2(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& combine, int idx) {
		if (idx == candidates.size()) {
			return;
		}
		if (target == 0) {
			ans.emplace_back(combine);
			return;
		}
		// ֱ������
		dfs2(candidates, target, ans, combine, idx + 1);
		// ѡ��ǰ��
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



	//�Լ��ⷨ
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
����һ�����ظ�Ԫ�ص����� candidates ��һ��Ŀ���� target ���ҳ� candidates �����п���ʹ���ֺ�Ϊ target ����ϡ�
candidates �е����ֿ����������ظ���ѡȡ��

˵����

�������֣����� target��������������
�⼯���ܰ����ظ�����ϡ�
ʾ�� 1��

���룺candidates = [2,3,6,7], target = 7,
����⼯Ϊ��
[
  [7],
  [2,2,3]
]
ʾ�� 2��

���룺candidates = [2,3,5], target = 8,
����⼯Ϊ��
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
*/