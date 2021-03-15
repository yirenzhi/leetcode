#pragma once

/*
Given an array, rotate the array to the right by k steps, where k is non-negative.

Follow up:

Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
Could you do it in-place with O(1) extra space?


Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
*/

#include "../base.h"

class Solution189 : public Solution
{
public:
	virtual void test()
	{
		vector<int> nums = { 1,2,3,4,5,6,7 };
		rotate1(nums, 3);
		for (size_t i = 0; i < nums.size(); i++)
		{
			cout << nums[i] << "   ";
		}
		cout << endl;
	}

private:
	void rotate(vector<int>& nums, int k) {
		int len1 = nums.size();
		if (len1==0)
		{
			return;
		}

		if (k%len1==0)
		{
			return;
		}

		int m = k % len1;

		int temp=0;
		for (size_t i = 0; i < len1; i++)
		{

		}
	}

	//·­×ª·¨
	void rotate1(vector<int>& nums, int k) {
		int len1 = nums.size();
		if (len1==0)
		{
			return;
		}
		k = k % len1;
		reverse(nums, 0, len1 - k-1);
		reverse(nums, len1-k, len1 -1);
		reverse(nums, 0, len1-1);
	}

	void reverse(vector<int>& nums, int begin, int end)
	{
		while (begin<end)
		{
			swap(nums[begin++], nums[end--]);
		}
	}
};