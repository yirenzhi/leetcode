#include<iostream>
#include <ctime>
#include <chrono>
#include"LeetCode.h"
#include "code1-100/19_RemoveNthFromEnd.h"
#include "code1-100/21.MergeTwoSortedLists.h"
#include"code1-100/39_CombinationSum.h"
#include"code1-100/40_CombinationSumII.h"
#include"code1-100/46_Permutations.h"
#include"code1-100/47_PermutationsII.h"
#include"code1-100/51_NQueen.h"
#include"code1-100/54_SpiralMatrix.h"
#include"code1-100/77_Combinations.h"
#include"code1-100/78_Subsets.h"
#include"code1-100/90_SubsetsII.h"
#include"code100-200/102.BinaryTreeLevelOrderTraversal.h"
#include"code100-200/189_RotateArray.h"
#include"code100-200/107_BinaryTreeLevelOrderTraversal_II.h"
#include"code100-200/121_BestTimetoBuyandSellStock.h"
#include"code100-200/143_ReorderList.h"
#include"code100-200/199.BinaryTreeRightSideView.h"
#include"code201-300/206_ReverseLinkedList.h"
#include"code201-300/234_PalindromeLinkedList.h"
#include"code401-500/463_IslandPerimeter.h"
#include"code501-600/509_FibonacciNumber.h"
#include"code701-800/752_OpenLock.h"
#include"code801-900/860_LemonadeChange.h"
#include"code801-900/876_MiddleoftheLinkedList.h"
#include"code801-900/830_PositionsofLargeGroups.h"
#include"1301-1400/1365_HowManyNumbersAreSmallerThantheCurrentNumber.h"
#include"code2501-2600/2530_Maximal_Score_After_Applying_K_Operations.h"
#include <sstream>
#include<fstream>
#include<algorithm>
using namespace std;
using namespace chrono;
#define add(a,b) a+b
#define A(x)  Solution##x()
#define CASE(x) case x:{return new Solution##x;}break;
using std::cout;
Solution* createSolution(int num)
{
	// return new A(num);
	switch (num)
	{
	// case 19: {return new Solution19(); }break;
	case 19: {return new A(19); }break;
	// CASE(21);
	// case 21: {return new Solution21; }break;
	case 39:{return new Solution39; }break;
	case 40:{return new Solution40; }break;
	case 46:{return new Solution46; }break;
	case 47: {return new Solution47; }break;
	CASE(51)
	case 54: {return new Solution54; }break;
	case 77:{return new Solution77; }break;
	case 78:{return new Solution78; }break;
	case 90:{return new Solution90; }break;
	case 102:{return new Solution102; }break;
	case 107: {return new Solution107; }break;
	case 121: {return new Solution121; }break;
	case 143: {return new Solution143; }break;
	case 189: {return new Solution189; }break;
	case 199:{return new Solution199; }break;
	case 206:{return new Solution206; }break;
	case 234:{return new Solution234; }break;
	case 463: {return new Solution463; }break;
	case 509: {return new Solution509; }break;
	CASE(752)
	case 830: {return new Solution830; }break;
	case 860: {return new Solution860; }break;
	case 876:{return new Solution876; }break;
	case 1365:{return new Solution1365; }break;
	CASE(2530)
	default:
		break;
	}
	return NULL;
}


//添加屏蔽字
void addPingBi()
{
	vector<string> strs;
	fstream f2("words");
	string buf1;
	if (f2)
	{
		while (getline(f2, buf1))
		{
			strs.push_back(buf1);
		}
	}
	cout << "size:" << strs.size() << endl;
	f2.close();
	f2.open("words", ofstream::app);

	fstream f1("1.text");
	if (f1)
	{
		string buf;
		int i = 0;
		while (getline(f1,buf))
		{
			
			auto iter = std::find(strs.begin(), strs.end(), buf);
			if (iter!=strs.end())
			{
				f2 << buf << endl;
				i++;
			}

		}
		cout << "addSize:" << i << endl;
	}
}

int main()
{
	//addPingBi();
	//int b;
	//cin >> b;

	vector<double> vec(20);

	//long aa = 1000;
	//cout << Solution1365::anyToString(aa) << endl;

	std::cout<< "请输入题目编号,输入0跳出循环"<<std::endl;

	while (true)
	{
		cout << "请输入题目编号,输入0跳出循环" << endl;
		int tag;
		cin >> tag;
		if (tag==0)
		{
			break;
		}
		Solution* sol = createSolution(tag);
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