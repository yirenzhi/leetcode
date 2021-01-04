#pragma once
/*����һ������ nums����������ÿ��Ԫ�� nums[i]������ͳ�������б���С���������ֵ���Ŀ��

������֮������ÿ�� nums[i] �����������Ч�� j ������������ j ���� j != i �� nums[j] < nums[i] ��

��������ʽ���ش𰸡�

 

ʾ�� 1��

���룺nums = [8,1,2,2,3]
�����[4,0,1,1,3]
���ͣ� 
���� nums[0]=8 �����ĸ�����С�����֣���1��2��2 �� 3���� 
���� nums[1]=1 �����ڱ���С�����֡�
���� nums[2]=2 ����һ������С�����֣���1���� 
���� nums[3]=2 ����һ������С�����֣���1���� 
���� nums[4]=3 ������������С�����֣���1��2 �� 2����
ʾ�� 2��

���룺nums = [6,5,4,8]
�����[2,1,0,3]
ʾ�� 3��

���룺nums = [7,7,7,7]
�����[0,0,0,0]
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
	//O(n)ʱ�临�Ӷ�
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
