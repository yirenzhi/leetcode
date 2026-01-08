#pragma once

/*
463. 岛屿的周长
给定一个包含 0 和 1 的二维网格地图，其中 1 表示陆地 0 表示水域。

网格中的格子水平和垂直方向相连（对角线方向不相连）。整个网格被水完全包围，但其中恰好有一个岛屿（或者说，一个或多个表示陆地的格子相连组成的岛屿）。

岛屿中没有“湖”（“湖” 指水域在岛屿内部且不和岛屿周围的水相连）。格子是边长为 1 的正方形。网格为长方形，且宽度和高度均不超过 100 。计算这个岛屿的周长。



示例 :

输入:
[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

输出: 16
*/

#include "../base.h"
class Solution463 : public Solution
{
public:
	virtual void test()
	{
		vector<vector<int>> grid;
		vector<int > nums1 = { 0,1,0,0 };
		vector<int > nums2 = { 1,1,1,0 };
		vector<int > nums3 = { 0,1,0,0 };
		vector<int > nums4 = { 1,1,0,0 };
		grid.emplace_back(nums1);
		grid.emplace_back(nums2);
		grid.emplace_back(nums3);
		grid.emplace_back(nums4);

		cout << "" << islandPerimeter(grid) << endl;

	}

private:
	int islandPerimeter(vector<vector<int>>& grid) {
		int zhouchang = 0;
		for (size_t i = 0; i < grid.size(); i++)
		{
			for (size_t j = 0; j < grid[i].size(); j++)
			{
				if (grid[i][j])
				{
					zhouchang += cacultateLength(grid, i, j);
				}
			}
		}
		return zhouchang;
	}

	int cacultateLength(vector<vector<int>>& grid, int x, int y)
	{
		int length = 0;
		//计算这个点的四周有没有其他点，没有则加1，有则不加
		int curX = 0, curY = 0;
		//左
		curX = x , curY = y-1;
		if (curY<0||grid[curX][curY]==0)
		{
			length += 1;
		}
		//右
		curX = x, curY = y+1;
		if (curY >= grid[curX].size() || grid[curX][curY] == 0)
		{
			length += 1;
		}
		//上
		curX = x - 1, curY = y;
		if (curX < 0 || grid[curX][curY] == 0)
		{
			length += 1;
		}
		//下
		curX = x + 1, curY = y;
		if (curX >= grid.size() || grid[curX][curY] == 0)
		{
			length += 1;
		}


		return length;
	}


};
