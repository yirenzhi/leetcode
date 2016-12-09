#pragma once
#include <iostream>
#include <vector>
using std::vector;
using std::string;
class LeetCode
{
public:
	LeetCode(void);
	~LeetCode(void);
	static string leetcode3(string str);
	static int leetcode3_(string str);

	static string leetcode5(string str);

	static string leetcode6(string str, int numRows);

	static int leetcode8(string str);
	static string leetcode12(int num);

	static string leetcode14(vector<string>& strs);
	static vector<vector<int>> leetcode15(vector<int>& nums);
	static int leetcode16(vector<int>& nums, int target);
};

