#pragma once

/*
����һ������ͷ��� head �ķǿյ���������������м��㡣

����������м��㣬�򷵻صڶ����м��㡣



ʾ�� 1��

���룺[1,2,3,4,5]
��������б��еĽ�� 3 (���л���ʽ��[3,4,5])
���صĽ��ֵΪ 3 �� (����ϵͳ�Ըý�����л������� [3,4,5])��
ע�⣬���Ƿ�����һ�� ListNode ���͵Ķ��� ans��������
ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, �Լ� ans.next.next.next = NULL.
ʾ�� 2��

���룺[1,2,3,4,5,6]
��������б��еĽ�� 4 (���л���ʽ��[4,5,6])
���ڸ��б��������м��㣬ֵ�ֱ�Ϊ 3 �� 4�����Ƿ��صڶ�����㡣

*/
#include "../base.h"


//Definition for singly-linked list.
//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};

class Solution876 : public Solution
{
public:
	virtual void test()
	{

		vector<int> nums = { 1,2,3,4,5 };
		ListNode* node11 = ListNodeCreate(nums);

		printList(node11);
		middleNode(node11);
	}
private:
	ListNode* middleNode(ListNode* head) {
		//�ÿ���ָ���˼�룬һ��ָ����һ����һ��ָ�������������Դ��Ч��
		ListNode* node1 = head;
		ListNode* node2 = head;
		while (node2 !=NULL&& node2->next !=NULL)
		{
			node1 = node1->next;

			node2 = node2->next->next;

		}
		if (node1)
		{
			cout << node1->val;
		}
		return node1;
	}
};