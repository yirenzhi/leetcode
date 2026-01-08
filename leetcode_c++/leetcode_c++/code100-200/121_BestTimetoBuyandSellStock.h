#pragma once

/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

Example 1:

Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
?            Not 7-1 = 6, as selling price needs to be larger than buying price.
Example 2:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
*/

#include "../base.h"
class Solution121 : public Solution
{
public:
	virtual void test()
	{
		vector<int> prices = { 7,1,5,3,6,4 };
		cout << maxProfit1(prices) << endl;
	}

private:
	int maxProfit(vector<int>& prices) {
		int maxPrice = 0;
		int begin = 0, end = 1;
		for ( ; end < prices.size(); end++)
		{

			if (prices[end]<prices[begin])
			{
				begin = end;
			}
			else
			{
				int temp = prices[end] - prices[begin];
				if (temp > maxPrice)
				{
					maxPrice = temp;
				}
			}

		}
		return maxPrice;
	}

	//动态规划
	//分析 用两个数存储 一个是当天不持有股票，一个是持有股票
	int maxProfit1(vector<int>& prices) {
		if (prices.size()<2)
		{
			return 0;
		}
		int notHoldStock = 0;
		int holdStock = -prices[0];
		for (size_t i = 1; i < prices.size(); i++)
		{
			notHoldStock = max(notHoldStock, holdStock + prices[i]);
			holdStock = max(holdStock, -prices[i]);
		}
		return notHoldStock;
	}
};


