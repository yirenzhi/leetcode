#pragma once
/*给你一个数组 nums，对于其中每个元素 nums[i]，请你统计数组中比它小的所有数字的数目。

换而言之，对于每个 nums[i] 你必须计算出有效的 j 的数量，其中 j 满足 j != i 且 nums[j] < nums[i] 。

以数组形式返回答案。

 

示例 1：

输入：nums = [8,1,2,2,3]
输出：[4,0,1,1,3]
解释： 
对于 nums[0]=8 存在四个比它小的数字：（1，2，2 和 3）。 
对于 nums[1]=1 不存在比它小的数字。
对于 nums[2]=2 存在一个比它小的数字：（1）。 
对于 nums[3]=2 存在一个比它小的数字：（1）。 
对于 nums[4]=3 存在三个比它小的数字：（1，2 和 2）。
示例 2：

输入：nums = [6,5,4,8]
输出：[2,1,0,3]
示例 3：

输入：nums = [7,7,7,7]
输出：[0,0,0,0]
*/

#include "../base.h"

class Solution1365 : public Solution
{
public:
	virtual void test()
	{
		vector<int> nums = { 8,1,2,2,3 };
		printVector1(nums);
		nums = smallerNumbersThanCurrent2(nums);
		printVector(nums);

	}
	template<class T>
	static std::string anyToString(T a);

private:
	//O(n)时间复杂度
	vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
		vector<int> nums1;
		nums1.resize(nums.size());
		for (size_t i = 0; i < nums.size(); i++)
		{
			int temp = 0;
			for (size_t j = 0; j < nums.size(); j++)
			{
				if (nums[i]>nums[j])
				{
					temp++;
				}
			}
			nums1[i] = temp;
		}
		return nums1;
	}
	//O(NlogN)
	vector<int> smallerNumbersThanCurrent1(vector<int>& nums) {
		vector<pair<int, int>> datas;
		for (size_t i = 0; i < nums.size(); i++)
		{
			datas.emplace_back(nums[i], i);
		}

		sort(datas.begin(), datas.end());

		vector<int> rets(nums.size(), 0);

		int pre = -1;
		for (size_t i = 0; i < nums.size(); i++)
		{
			if (i == 0||datas[i].first!=datas[i-1].first)
			{
				pre = i;
			}
			rets[datas[i].second] = pre;
		}
		return rets;
	}
	vector<int> smallerNumbersThanCurrent2(vector<int>& nums) {
		vector<int> counts(101, 0);
		int n = nums.size();
		for (size_t i = 0; i < n; i++)
		{
			counts[nums[i]]++;
		}

		for (size_t i = 1; i < counts.size(); i++)
		{
			counts[i] += counts[i - 1];
		}

		vector<int> rets(nums.size(),0);
		for (int i = 0; i < n; i++)
		{
			if (nums[i] ==0)
			{
				rets[i] = 0;
				continue;
			}
			rets[i] = counts[nums[i] - 1];
		}
		return rets;
	}


};


template<class T>
std::string Solution1365::anyToString(T a)
{
	std::ostringstream oss;
	oss.str("");
	oss.clear();
	oss << a;
	return oss.str();
}
