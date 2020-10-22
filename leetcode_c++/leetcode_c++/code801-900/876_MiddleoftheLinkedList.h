#pragma once

/*
给定一个带有头结点 head 的非空单链表，返回链表的中间结点。

如果有两个中间结点，则返回第二个中间结点。



示例 1：

输入：[1,2,3,4,5]
输出：此列表中的结点 3 (序列化形式：[3,4,5])
返回的结点值为 3 。 (测评系统对该结点序列化表述是 [3,4,5])。
注意，我们返回了一个 ListNode 类型的对象 ans，这样：
ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, 以及 ans.next.next.next = NULL.
示例 2：

输入：[1,2,3,4,5,6]
输出：此列表中的结点 4 (序列化形式：[4,5,6])
由于该列表有两个中间结点，值分别为 3 和 4，我们返回第二个结点。

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
		//用快慢指针的思想，一个指针跳一步，一个指针跳两步，可以达成效果
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