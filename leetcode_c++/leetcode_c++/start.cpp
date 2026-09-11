#include<iostream>
#include <ctime>
#include <chrono>
#include"LeetCode.h"
#include "all_problems.h"
#include <sstream>
#include<fstream>
#include<algorithm>
using namespace std;
using namespace chrono;
using std::cout;
// 通过 REGISTER_SOLUTION 宏自动登记的题目，直接按编号查找
Solution* createSolution(int num)
{
	return Solution::create(num);
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