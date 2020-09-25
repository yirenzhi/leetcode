#pragma once
#include "../base.h"

/*给定一个 没有重复 数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
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
		//最初是的dfs仅仅包含
		//for循环下的 dfs(nums, len, depth + 1, path, used, res);
		//depth用来记录进行的层级判断是否结束
		//path用来记录路径，即记录从数顶走下来的数列
		//used用来判断不使用重复的数，如果没有则是A排列不是C排列
		//res则用来存储最后的值
		if (len==depth)
		{
			//
			res.push_back(path);
			return;
		}
		//未加used，为A排列，数量为len的len次方，加了used后为阶乘
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