#include<iostream>
#include <ctime>
#include <chrono>
#include"LeetCode.h"
#include "code1-100/21.MergeTwoSortedLists.h"
#include"code1-100/39_CombinationSum.h"
#include"code1-100/40_CombinationSumII.h"
#include"code1-100/46_Permutations.h"
#include"code1-100//47_PermutationsII.h"
#include"code1-100/77_Combinations.h"
#include"code1-100/78_Subsets.h"
#include"code1-100/90_SubsetsII.h"
#include"code100-200/102.BinaryTreeLevelOrderTraversal.h"
#include"code100-200/107_BinaryTreeLevelOrderTraversal_II.h"
#include"code100-200/143_ReorderList.h"
#include"code100-200/199.BinaryTreeRightSideView.h"
#include"code201-300/206_ReverseLinkedList.h"
#include"code201-300/234_PalindromeLinkedList.h"
#include"code801-900/876_MiddleoftheLinkedList.h"
#include"1301-1400/1365_HowManyNumbersAreSmallerThantheCurrentNumber.h"
using namespace std;
using namespace chrono;
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
	case 39:
	{return new Solution39; }break;
	case 40:
	{return new Solution40; }break;
	case 46:
	{return new Solution46; }break;
	case 47:
	{return new Solution47; }break;
	case 77:
	{return new Solution77; }break;
	case 78:
	{return new Solution78; }break;
	case 90:
	{return new Solution90; }break;
	case 199:
	{return new Solution199;}break;
	case 21:
	{return new Solution21;}break;
	case 102:
	{return new Solution102;}break;
	case 107:
	{return new Solution107; }break;
	case 143:
	{return new Solution143; }break;
	case 206:
	{return new Solution206; }break;
	case 234:
	{return new Solution234; }break;
	case 876:
	{return new Solution876; }break;
	case 1365:
	{return new Solution1365; }break;
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
			auto start = system_clock::now();
			sol->test();
			auto end = system_clock::now();
			auto duration = duration_cast<microseconds>(end - start);
			cout << "本次执行花费："
				<< double(duration.count()) * microseconds::period::num / microseconds::period::den
				<< "秒" << endl;

			//clock_t start = clock();
			//sol->test();
			//clock_t end = clock();
			//cout << "本次执行花费：" << (double)(end - start) / CLOCKS_PER_SEC << "秒。" << endl;

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