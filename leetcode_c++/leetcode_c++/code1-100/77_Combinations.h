#pragma once
/*
������������ n �� k������ 1 ... n �����п��ܵ� k ��������ϡ�

ʾ��:

����:n = 4, k = 2
���:
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
		vector<vector<int>> res = combine(4, 2);
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
	vector<vector<int>> combine(int n, int k) {
		target = k;
		vector<vector<int>> res;
		vector<int> path;
		dfs(n, 1, path, res);

		return res;
	}



	void dfs(int n, int depth, vector<int>& path, vector<vector<int>>& res)
	{
		if (path.size()==target)
		{
			cout << " depth=" << depth << endl;

			res.emplace_back(path);
			return;
		}
//		for (int i = depth; i <= n; i++)
		//���������Ͻ�+������Ҫѡ���Ԫ�ظ���-1=n
		//�Ͻ�+(k-path.size())-1=n
		//�Ͻ�=n-(k-path.size())+1
		for (int i=depth;i<=n-(target-path.size())+1;i++)
		{
			//if (i-depth==n-target+1)
			//{
			//	break;
			//}
			path.emplace_back(i);
			cout << "�ݹ�֮ǰ => ";
			for (int k = 0; k < path.size(); k++)
			{
				cout << path[k] << " ";
			}
			cout << "��i = " << i<<" depth="<<depth << endl;

			dfs(n, i + 1, path, res);
			path.pop_back();
			cout << "�ݹ�֮��=> ";
			for (int k = 0; k < path.size(); k++)
			{
				cout << path[k] << " ";
			}
			cout << "��i = " << i << " depth=" << depth << endl;
		}
	}
	//vector<vector<int>> combine(int n, int k) {
	//	target = k;
	//	vector<int> candidates;
	//	for (int i = 0; i < n; i++)
	//	{
	//		candidates.emplace_back(i + 1);
	//	}
	//	vector<vector<int>> res;
	//	vector<int> path;
	//	dfs(candidates, 0, path, res);

	//	return res;
	//}



	//void dfs(vector<int>& candidates, int depth, vector<int>& path, vector<vector<int>>& res)
	//{
	//	if (path.size() == target)
	//	{
	//		res.emplace_back(path);
	//		return;
	//	}
	//	for (int i = depth; i < candidates.size(); i++)
	//	{
	//		//if (path.size() > 0 && path[path.size() - 1] >= candidates[i])
	//		//{
	//		//	continue;
	//		//}
	//		path.emplace_back(candidates[i]);
	//		dfs(candidates, i + 1, path, res);
	//		path.pop_back();
	//	}
	//}
};