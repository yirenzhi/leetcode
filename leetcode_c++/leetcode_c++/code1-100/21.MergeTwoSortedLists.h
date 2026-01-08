#pragma once

#include "../base.h"
//将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。

class Solution21 :public Solution {
public:

	ListNode * mergeTwoLists(ListNode* l1, ListNode* l2) {



		ListNode* p1=l1, *p2=l2;
		ListNode* l3=new ListNode(0);
		ListNode* l4=l3;
		while (p1&&p2)
		{
			if (p1->val <= p2->val)
			{
				l3->next = p1;
				p1 = p1->next;
			}
			else
			{
				l3->next = p2;
				p2 = p2->next;
			}
			l3 = l3->next;
		}
		if (p1 == NULL)
		{
			l3->next=p2;
		}
		else if (p2 == NULL)
		{
			l3->next = p1;
		}
		return l4->next;
	}

	//递归
	ListNode* mergeTwoLists1(ListNode* l1, ListNode* l2) {
		if (l1 == NULL) {
			return l2;
		}
		else if (l2 == NULL) {
			return l1;
		}
		else if (l1->val < l2->val) {
			l1->next = mergeTwoLists1(l1->next, l2);
			return l1;
		}
		else {
			l2->next = mergeTwoLists1(l1, l2->next);
			return l2;
		}

	}


	void printList(ListNode*  L)
	{
		ListNode* p = L;
		while (p)
		{
			cout << p->val << "    ";
			p = p->next;
		}
		cout << endl;
	}

	void test() {
		ListNode* l1 = new ListNode(1);
		l1->next = new ListNode(2);
		l1->next->next = new ListNode(4);

		ListNode* l2 = new ListNode(1);
		l2->next = new ListNode(3);
		l2->next->next = new ListNode(4);

		ListNode* l3 = mergeTwoLists1(l1, l2);
		printList(l3);
	}


};
