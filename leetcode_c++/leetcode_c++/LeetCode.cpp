#include "LeetCode.h"
#include <vector>

LeetCode::LeetCode(void)
{
}


LeetCode::~LeetCode(void)
{
}

string getStr(string str ,unsigned int x,unsigned int y)
{
	string str1;
	for (unsigned int m=x;m<=y;++m)
	{
		str1+=str[m];
	}
	return str1;
}
//3. Longest Substring Without Repeating Characters
string LeetCode::leetcode3(string str)
{
	if (str.empty())
	{
		return NULL;
	}
	string longstr;
	unsigned int max=0;
	unsigned int nums=1;
	bool isEqual=false;
	for (unsigned int i=0;i<str.size();++i)
	{
		isEqual =false;
		for (unsigned int j=i+1;j<str.size();++j)
		{
			nums = 1;
			unsigned int k=i;
			for (;k<j;++k)
			{
				if (str[k]!=str[j])
				{
					++nums;
				}
				else
				{
					isEqual = true;
					break;
				}
			}
			if (nums>max)
			{
				longstr=getStr(str,i,k);
				max=nums;
			}
			if (isEqual)
			{
				i+=(k-i);
				break;
			}
			else
			{

			}
		}
	}
	return longstr;
}

//超级天才的算法 so beautiful
int LeetCode::leetcode3_(string str)
{
	std::vector<int > dict(256,-1);
	int maxLen = 0, start = -1;
	for (int i = 0; i!= str.length();i++)
	{
		if (dict[str[i]]>start)
			start = dict[str[i]];
		dict[str[i]] = i;
		maxLen=std::max(maxLen,start);
	}
	return maxLen;
}

//5. Longest Palindromic Substring
string LeetCode::leetcode5(string str)
{
	int maxLen=0;
	string maxString;
	for (unsigned int i=0;i<str.length();++i)
	{
		for (unsigned int j=0;j<(str.length()+1)/2;++j)
		{
			if (i<j || i+j>=str.length())
			{
				break;
			}
			if (str[i-j]==str[i+j])
			{
				if (2*j+1>maxLen)
				{
					maxLen=2*j+1;
					maxString=getStr(str,i-j,i+j);
				}
			}
			else
			{
				break;
			}
		}

		for (unsigned int j=0;j<str.length()/2;++j)
		{
			if (i<j || i+j+1>=str.length())
				break;
			if (str[i-j]==str[i+j+1])
			{
				if (2*(j+1)>maxLen)
				{
					maxLen=2*j+1;
// 					maxString=getStr(str,i-j,i+j+1);
					maxString= str.substr(i-j,i+j+1);
				}
			}
			else
			{
				break;
			}

		}
	}
	return maxString;
}
//6. ZigZag Conversion
//
/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

	P   A   H   N
	A P L S I I G
	Y   I   R
	And then read line by line: "PAHNAPLSIIGYIR"
*/
string LeetCode::leetcode6(string str, int numRows)
{
	if (str.empty()||numRows<=1)
	{
		return str;
	}
	string finStr;
	std::vector<string > strs;
	for (unsigned int i=0;i<numRows;i++)
	{
		strs.push_back("");
	}
	int coupleL=(numRows-1)*2;

	for (unsigned int i=0;i<str.length();++i)
	{
		int m = i%coupleL;
		if (m>=numRows)
			m=coupleL-m;

		strs[m]+=str[i];
	}

	for (auto str1 : strs)
	{
		finStr+=str1;
	}
	return finStr;
}

//Implement atoi to convert a string to an integer.
int LeetCode::leetcode8(string str)
{
	if (str.empty())
	{
		return 0;
	}
	int num=0;

}

string LeetCode::leetcode12(int num)
{
	string roman;





	return roman;
}

string LeetCode::leetcode14(vector<string>& strs)
{
	if (strs.empty())
	{
		return NULL;
	}
	string commonStr;
	for (unsigned int i=0;i<strs[0].size();++i)
	{
		auto m=strs[0][i];
		for (auto str :strs)
		{
			if (str.length()>i)
			{
				if (str[i]==m)
				{
					continue;
				}
			}
			commonStr=strs[0].substr(0,i);
			return commonStr;
		}
	}
	return strs[0];
}

vector<vector<int>> LeetCode::leetcode15(vector<int>& nums)
{
	vector<vector<int>> vecNums;
	for (unsigned int i=0;i<nums.size();i++)
	{
		for (unsigned int j=i+1;j<nums.size();j++)
		{
			for (unsigned int z=j+1;z<nums.size();z++)
			{
				if (nums[i]+nums[j]+nums[z]==0)
				{
					vector<int> vecNum;
					vecNum.push_back(nums[i]);
					vecNum.push_back(nums[j]);
					vecNum.push_back(nums[z]);
					vecNums.push_back(vecNum);
					break;
				}
			}
		}
	}
	return vecNums;
}

int LeetCode::leetcode16(vector<int>& nums, int target)
{
	if (nums.size()<3)
	{
		return 0;
	}
	// int m=INT_MAX;
	int n=0;
	// for (unsigned int i=0;i<nums.size();i++)
	// {
	// 	for (unsigned int j=i+1;j<nums.size();j++)
	// 	{
	// 		for (unsigned int z=j+1;z<nums.size();z++)
	// 		{
	// 			if (abs(nums[i]+nums[j]+nums[z]-target)<m)
	// 			{
	// 				m=abs(nums[i]+nums[j]+nums[z]-target);
	// 				n=nums[i]+nums[j]+nums[z];
	// 			}
	// 		}
	// 	}
	// }
	return n;
}
