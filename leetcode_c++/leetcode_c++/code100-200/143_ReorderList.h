#pragma once
/*
����һ�������� L��L0��L1������Ln-1��Ln ��
�����������к��Ϊ�� L0��Ln��L1��Ln-1��L2��Ln-2����

�㲻��ֻ�ǵ����ĸı�ڵ��ڲ���ֵ��������Ҫʵ�ʵĽ��нڵ㽻����

ʾ�� 1:

�������� 1->2->3->4, ��������Ϊ 1->4->2->3->
ʾ�� 2:

�������� 1->2->3->4->5, ��������Ϊ 1->5->2->4->3->*/

#include "../base.h"
class Solution143 : public Solution
{
public:
	virtual void test()
	{

		vector<int> nums = {1,2,3,4,5 };
		ListNode* node11 = ListNodeCreate(nums);

		printList(node11);
		reorderList2(node11);
		printList(node11);

	}

private:
	void reorderList(ListNode* head) {
		if (head==NULL||head->next==NULL)
		{
			return;
		}
		ListNode* middle = middleNode(head);
		ListNode* node2 = middle->next;
		middle->next = NULL;
		node2 = reverseList(node2);

		mergeList(head, node2);

	}

	void mergeList(ListNode* node1,ListNode* node2)
	{
		ListNode* node1t;
		ListNode* node2t;
		while (node1 !=NULL&&node2!=NULL)
		{
			node1t = node1->next;
			node2t = node2->next;

			node1->next = node2;
			node1 = node1t;

			node2->next = node1;
			node2 = node2t;
		}

	}
	ListNode* middleNode(ListNode* head) {
		ListNode* node1 = head;
		ListNode* node2 = head;
		while (node2->next != NULL && node2->next->next != NULL)
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

	void reorderList2(ListNode* head) {
		if (head == NULL || head->next == NULL || head->next->next == NULL)return;

		// 1-> ���е㣬��slowָ���е㣬�����е�λ��
		ListNode*slow = head, *fast = head->next;
		while (fast != NULL && fast->next != NULL) {
			slow = slow->next;
			fast = fast->next->next;
		}

		// 2-> �Ͽ��е㣬��ת��벿��
		ListNode*head2 = NULL, *next = slow->next;
		slow->next = NULL;
		slow = next;
		while (slow != NULL) {
			next = slow->next;
			slow->next = head2;
			head2 = slow;
			slow = next;
		}

		// 3-> �ϲ�����head��head2
		ListNode*curr = head;
		ListNode*curr2 = head2;
		while (curr != NULL && curr2 != NULL) {
			next = curr->next;
			curr->next = curr2;
			curr2 = curr2->next;
			curr->next->next = next;
			curr = next;
		}
	}
};