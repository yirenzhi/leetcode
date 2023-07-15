#pragma once
#include <iostream>
#include <vector>
#include<queue>
#include<stack>
#include<map>
#include <sstream>

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
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

template <typename T>
void printVector(const vector<T>& vec)
{
	for_each(vec.begin(), vec.end(),
		[](const T& val) {cout << val << "  "; });
	cout << endl;
}

template <typename T>
void printVector1(const T& vec)
{
	for_each(vec.begin(), vec.end(),
		[](const typename T::value_type& val) {cout << val << "  "; });
	cout << endl;
}
void printList(ListNode* head)
{
	while (head != NULL)
	{
		cout << head->val << "  ";
		head = head->next;
	}
	cout << endl;
}
ListNode* ListNodeCreate(vector<int> &nums)
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

