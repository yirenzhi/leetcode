#pragma once
#include "../base.h"
/*
给你一个下标从 0 开始的整数数组 nums 和一个整数 k 。你的 起始分数 为 0 。

在一步 操作 中：

选出一个满足 0 <= i < nums.length 的下标 i ，
将你的 分数 增加 nums[i] ，并且
将 nums[i] 替换为 ceil(nums[i] / 3) 。
返回在 恰好 执行 k 次操作后，你可能获得的最大分数。

向上取整函数 ceil(val) 的结果是大于或等于 val 的最小整数。

*/
class Solution2530 : public Solution
{
public:
	virtual void test()
	{
		cout << "maxKelements:"<< maxKelements({1,10,3,3,3},3) << endl;
	}

private:
	long long maxKelements(vector<int>&& nums, int k) {
        long long res=0;
        if(nums.size()==0)return res;
        priority_queue<int> pq(nums.begin(),nums.end());
        
        for(auto i=0;i<k;i++){
            auto a=pq.top();
            if(a==0)return res;
            pq.pop();
            // auto x=std::ceil(a/3);
            auto x=a/3+((a%3!=0)?1:0);
            res+=a;
            pq.push(x);

        }
        return res;
    }


	int openLock(vector<string>& deadends, string target) {

    }
};
