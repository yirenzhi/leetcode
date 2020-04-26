#pragma once
#include <iostream>
#include <vector>
#include<queue>
#include<stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//typedef int ElementType;
//typedef struct LinkNode* LinkList;
//struct LinkNode
//{
//	ElementType Data;
//	LinkList Next;
//};

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

class Solution
{
public:
	virtual void test() = 0;

private:

};

