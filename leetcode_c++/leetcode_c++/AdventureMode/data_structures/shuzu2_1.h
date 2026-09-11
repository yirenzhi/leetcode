#pragma once
#include "../../base.h"

/*
Q2. 有多少小于当前数字的数字
已解答
简单
相关标签
premium lock icon
相关企业
提示
给你一个数组 nums，对于其中每个元素 nums[i]，请你统计数组中比它小的所有数字的数目。

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
*/

class Solution_5 : public Solution
{
public:
	virtual void test()
	{
		vector<int> nums = { 5,0,10,0,10,6 };
		printVector(nums);
		nums = smallerNumbersThanCurrent(nums);
		printVector(nums);
	}

    private:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        // for(int i=0;i<n;++i){
        //     int temp=0;
        //     for(int j=0;j<n;++j){
        //         if(nums[j]<nums[i]){
        //             ++temp;
        //         }
        //     }
        //     ans[i]=temp;
        // }

        vector<int> vec(101,0);
        for(auto &x:nums){
            vec[x]+=1;
        }
        printVector(vec);
        for(int i=1;i<vec.size();++i){
            vec[i]=vec[i]+vec[i-1];
        }
        printVector(vec);
        for(int i=0;i<n;++i){
            if(nums[i]==0){
                ans[i]=0;
            }else{
                ans[i]=vec[nums[i]-1];
            }
        }
        return ans;
    }
};

REGISTER_SOLUTION(-5, Solution_5)
