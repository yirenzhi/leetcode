#pragma once
#include "../base.h"

class Solution509 : public Solution
{
public:
	virtual void test()
	{
		cout << "fib 5:"<< fib(5) << endl;
	}

private:
	int fib(int n) {
		if (n==0)
		{
			return 0;
		}
		else if (n==1)
		{
			return 1;
		}
		else
		{
			return fib(n - 1) + fib(n - 2);
		}
	}
};
