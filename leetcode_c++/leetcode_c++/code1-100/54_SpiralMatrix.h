#pragma once
/*
给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。

 

示例 1：


输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]

*/
#include "../base.h"

class Solution54 : public Solution
{
public:
	virtual void test()
	{
		vector<vector<int> > matrix = getMatrixByInt(3, 4);
		vector<int> orders = spiralOrder(matrix);
		for(auto var : orders)
		{
			cout << var << " ";
		}
		cout << endl;
	}
private:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> orders;
		int m = matrix.size();
		if (0==m)
		{
			return orders;
		}
		int n = matrix[0].size();
		int x = 0, y = 0;
		int x1 = m, y1 = n;
		while (true)
		{
			for (int i = x, j = y; j < y1; j++)
			{
				orders.push_back(matrix[i][j]);
			}
			++x;
			if (isOver(x, x1, y, y1)) break;

			for (int i = x, j = y1-1; i < x1; i++)
			{
				orders.push_back(matrix[i][j]);
			}
			--y1;
			if (isOver(x, x1, y, y1)) break;

			for (int i = x1-1, j = y1-1; j >=y; j--)
			{
				orders.push_back(matrix[i][j]);
			}
			--x1;
			if (isOver(x, x1, y, y1)) break;

			for (int i = x1-1, j = y; i >=x; --i)
			{
				orders.push_back(matrix[i][j]);
			}
			++y;
			if (isOver(x, x1, y, y1)) break;

		}
		return orders;
	}

	bool isOver(int x, int x1, int y, int y1)
	{
		return (x == x1 || y == y1);
	}

	vector<vector<int>> getMatrixByInt(int m,int n)
	{
		vector<vector<int> > matrix;
		for (size_t i = 0; i < m; i++)
		{
			vector<int >temp;
			for (size_t j = 0; j < n; j++)
			{
				temp.push_back(i * n + j + 1);
			}
			matrix.push_back(temp);
		}
		return matrix;
	}
};
