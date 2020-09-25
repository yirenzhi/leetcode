#pragma once
#include "../base.h"

/*����һ�� û���ظ� ���ֵ����У����������п��ܵ�ȫ���С�

ʾ��:

����: [1,2,3]
���:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

*/



class Solution46 :public Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		int len = nums.size();
		vector<vector<int>> res;
		if (len==0)
		{
			return res;
		}

		vector<int> path;
		vector<bool> used(len,false);
		dfs(nums, len, 0, path, used, res);
		return res;
	}

	void dfs(vector<int> nums, int len,int depth, vector<int>& path,vector<bool>& used, vector<vector<int>>& res) {
		//����ǵ�dfs��������
		//forѭ���µ� dfs(nums, len, depth + 1, path, used, res);
		//depth������¼���еĲ㼶�ж��Ƿ����
		//path������¼·��������¼������������������
		//used�����жϲ�ʹ���ظ����������û������A���в���C����
		//res�������洢����ֵ
		if (len==depth)
		{
			//
			res.push_back(path);
			return;
		}
		//δ��used��ΪA���У�����Ϊlen��len�η�������used��Ϊ�׳�
		//for (int i = 0; i < len; i++)
		//{
		//	path.push(nums[i]);
		//	dfs(nums, len, depth + 1, path, used, res);
		//	path.pop();
		//}		
		
		for (int i = 0; i < len; i++)
		{
			if (used[i])
			{
				continue;
			}
			used[i] = true;
			path.emplace_back(nums[i]);
			dfs(nums, len, depth + 1, path, used, res);
			path.pop_back();
			used[i] = false;

		}



	}


	void backtrack(vector<vector<int>>& res, vector<int>& output, int first, int len) {
		if (first==len)
		{
			res.emplace_back(output);
			return;
		}
		for (size_t i = first; i < len; i++)
		{

			swap(output[i], output[first]);
			cout << "swap before:";
			for (size_t j = 0; j <= first; j++)
			{
				cout << output[j] << "  ";
			}
			cout << endl;
			backtrack(res, output, first+1, len);
			swap(output[i], output[first]);
			cout << "swap end:   " ;
			for (size_t j = 0; j < first; j++)
			{
				cout << output[j] << "  ";
			}
			cout << endl;



		}

	}

	vector<vector<int>> permute2(vector<int>& nums) {
		vector<vector<int> > res;
		sort(nums.begin(),nums.end());
		backtrack(res, nums, 0, (int)nums.size());
		return res;


	}



	void test()
	{
		vector<int> nums{ 0,1,0,0,9};
		vector<vector<int>> res = permute(nums);
		for (size_t i = 0; i < res.size(); i++)
		{
			for (int j = 0; j < res[i].size(); j++)
			{

				cout << res[i][j] << "  ";
			}
			cout << endl;
		}
	}


};