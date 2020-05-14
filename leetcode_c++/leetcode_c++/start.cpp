#include<iostream>
#include"199.BinaryTreeRightSideView.h"
#include"21.MergeTwoSortedLists.h"
#include"102.BinaryTreeLevelOrderTraversal.h"
using namespace std;
#define add(a,b) a+b
#define A(x) return Solution##x
Solution* createSolutin(int num)
{
	switch (num)
	{
		case 199:
		{
			return new Solution199;
		}
		break;
		case 21:
		{
			return new Solution21;
		}
		case 102:
		{
			return new Solution102;
		}
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