#include<iostream>
#include"LeetCode.h"
#include "code1-100/21.MergeTwoSortedLists.h"
#include"code1-100/46_Permutations.h"
#include"code100-200/102.BinaryTreeLevelOrderTraversal.h"
#include"code100-200/107_BinaryTreeLevelOrderTraversal_II.h"
#include"code100-200/199.BinaryTreeRightSideView.h"

using namespace std;
#define add(a,b) a+b
#define A(x) return Solution##x
Solution* createSolutin(int num)
{
	switch (num)
	{
	case 3:
	{
		//LeetCode::leetcode3();
	}
	break;
	case 5:
	{

	}
	break;
	case 6:
	{

	}
	break;
	case 8:
	{

	}
	break;
	case 12:
	{

	}
	break;
	case 14:
	{

	}
	break;
	case 15:
	{

	}
	break;
	case 16:
	{

	}
	break;
	case 46:
	{return new Solution46;}
	break;
	case 199:
	{return new Solution199;}
	break;
	case 21:
	{return new Solution21;}
	break;
	case 102:
	{return new Solution102;}
	break;
	case 107:
	{return new Solution107;}
	break;
	default:
		break;
	}
	return NULL;
}

int main()
{
	while (true)
	{
		cout << "请输入题目编号,输入0跳出循环" << endl;
		int tag;
		cin >> tag;
		if (tag==0)
		{
			break;
		}
		Solution* sol = createSolutin(tag);
		if (sol)
		{
			sol->test();
		}
		else
		{
			cout << "编号不存在" << endl;
		}
	}


	int a;
	cin >> a;
	return 0;
}