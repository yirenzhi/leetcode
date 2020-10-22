#pragma once


#include "../base.h"

class Solution206 : public Solution
{
public:
	virtual void test()
	{

		vector<int> nums = { 1,2,3,4,5 };
		ListNode* node11 = ListNodeCreate(nums);

		printList(node11);
		ListNode* node2=reverseList(node11);
		printList(node2);

	}

private:


	ListNode* reverseList(ListNode* head) {
		ListNode* node1 = head;
		ListNode* node2 = NULL;
		while (node1)
		{
			ListNode* temp = node1->next;
			node1->next = node2;
			node2 = node1;
			node1 = temp;
		}
		return node2;
	}
};