#pragma once
#include "../base.h"

class Solution234 : public Solution
{
public:
	virtual void test()
	{

		vector<int> nums = { 1,2,3,2,1 };
		ListNode* node1 = ListNodeCreate(nums);

		printList(node1);
		bool isP = isPalindrome(node1);
		cout<< boolalpha << isP << endl;
	}

private:
	bool isPalindrome(ListNode* head) {
		if (head == NULL || head->next == NULL)
		{
			return true;
		}
		//�ÿ���ָ�����м�ڵ�
		ListNode* middle = middleNode(head);

		//��ȡ����ת�ڶ�������
		ListNode* node2 = middle->next;
		node2 = reverseList(node2);

		//�Ƚ�����
		return compareList(head, node2);
	}
	bool compareList(ListNode* node1, ListNode* node2)
	{
		while (node2)
		{
			if (node1->val != node2->val)
			{
				return false;
			}
			node1 = node1->next;
			node2 = node2->next;
		}
		return true;
	}

	ListNode* middleNode(ListNode* head) {
		ListNode* node1 = head;
		ListNode* node2 = head;
		while (node2->next != NULL && node2->next->next != NULL)//�ҵ���ƫ�����ָ��
		{
			node1 = node1->next;
			node2 = node2->next->next;
		}
		return node1;
	}

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