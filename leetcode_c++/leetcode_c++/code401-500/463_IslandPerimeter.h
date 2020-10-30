#pragma once

/*
463. ������ܳ�
����һ������ 0 �� 1 �Ķ�ά�����ͼ������ 1 ��ʾ½�� 0 ��ʾˮ��

�����еĸ���ˮƽ�ʹ�ֱ�����������Խ��߷�������������������ˮ��ȫ��Χ��������ǡ����һ�����죨����˵��һ��������ʾ½�صĸ���������ɵĵ��죩��

������û�С������������� ָˮ���ڵ����ڲ��Ҳ��͵�����Χ��ˮ�������������Ǳ߳�Ϊ 1 �������Ρ�����Ϊ�����Σ��ҿ�Ⱥ͸߶Ⱦ������� 100 ���������������ܳ���



ʾ�� :

����:
[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

���: 16
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
		//����������������û�������㣬û�����1�����򲻼�
		int curX = 0, curY = 0;
		//��
		curX = x , curY = y-1;
		if (curY<0||grid[curX][curY]==0)
		{
			length += 1;
		}
		//��
		curX = x, curY = y+1;
		if (curY >= grid[curX].size() || grid[curX][curY] == 0)
		{
			length += 1;
		}
		//��
		curX = x - 1, curY = y;
		if (curX < 0 || grid[curX][curY] == 0)
		{
			length += 1;
		}
		//��
		curX = x + 1, curY = y;
		if (curX >= grid.size() || grid[curX][curY] == 0)
		{
			length += 1;
		}


		return length;
	}


};
