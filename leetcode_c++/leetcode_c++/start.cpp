#include<iostream>
#include"199.BinaryTreeRightSideView.h"
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
		default:
			break;
	}
	return NULL;
}

int main()
{
	while (true)
	{
		cout << "��������Ŀ���,����0����ѭ��" << endl;
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
			cout << "��Ų�����" << endl;
		}
	}


	int a;
	cin >> a;
	return 0;
}