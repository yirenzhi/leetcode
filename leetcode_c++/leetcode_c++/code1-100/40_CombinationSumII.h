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
			//�ؼ���ɾ��ͬԪ��  i>beginɾ����ͬ����ͬԪ��
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
����һ������ candidates ��һ��Ŀ���� target ���ҳ� candidates �����п���ʹ���ֺ�Ϊ target ����ϡ�

candidates �е�ÿ��������ÿ�������ֻ��ʹ��һ�Ρ�

˵����

�������֣�����Ŀ������������������
�⼯���ܰ����ظ�����ϡ�
ʾ�� 1:

����: candidates = [10,1,2,7,6,1,5], target = 8,
����⼯Ϊ:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]


*/