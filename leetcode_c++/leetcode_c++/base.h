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
void printList(ListNode* head)
{
	while (head != NULL)
	{
		cout << head->val << "  ";
		head = head->next;
	}
	cout << endl;
}
ListNode* ListNodeCreate(vector<int> nums)
{
	if (nums.size()==0)
	{
		return NULL;
	}
	ListNode* node1=NULL;
	ListNode* node2=NULL ;
	for (size_t i = 0; i < nums.size(); i++)
	{
		ListNode* temp = new ListNode(nums[i]);
		if (i==0)
		{
			node1 = temp;
			node2 = temp;
		}
		else
		{
			node1->next = temp;
			node1 = temp;
		}
	}
	return node2;
}

class Solution
{
public:
	virtual void test() = 0;

private:

};

