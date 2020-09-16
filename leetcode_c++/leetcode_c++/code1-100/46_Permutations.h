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

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/permutations
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
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

		stack<int> path;
		vector<bool> used(len,false);
		dfs(nums, len, 0, path, used, res);
		return res;
	}

	void dfs(vector<int> nums, int len,int depth, stack<int> path,vector<bool> used, vector<vector<int>>& res) {
		//����ǵ�dfs��������
		//forѭ���µ� dfs(nums, len, depth + 1, path, used, res);
		//depth������¼���еĲ㼶�ж��Ƿ����
		//path������¼·��������¼������������������
		//used�����жϲ�ʹ���ظ����������û������A���в���C����
		//res�������洢����ֵ
		if (len==depth)
		{
			//
			res.push_back(queueToVector(path));
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
			path.push(nums[i]);
			dfs(nums, len, depth + 1, path, used, res);
			path.pop();
			used[i] = false;

		}



	}

	vector<int> queueToVector(stack<int> path)
	{
		vector<int> vec;
		while (!path.empty()) {
			vec.push_back(path.top());
			path.pop();
		}
		reverse(vec.begin(), vec.end());
		return vec;
	}


	void test()
	{
		vector<int> nums{ 1,2,3};
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