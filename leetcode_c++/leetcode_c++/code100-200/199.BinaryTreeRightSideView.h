#pragma once
#include "../base.h"

//给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
class Solution199 :public Solution{
	//bfs方法  利用队列取出每层的数字，然后将每层最后一个元素收集，即为最右边元素
	vector<int> rightSideView(TreeNode* root) {
		vector<int> vecNum;
		if (!root)
		{
			return vecNum;
		}
		queue<TreeNode*> q;
		q.push(root);
		while (q.size()>0)
		{
			int len = q.size();
			for (int i = 0; i<len; i++)
			{
				TreeNode* temp = q.front();
				q.pop();
				if (len == i + 1)
				{
					vecNum.push_back(temp->val);
				}
				if (temp->left) {
					q.push(temp->left);
				}
				if (temp->right) {
					q.push(temp->right);
				}
			}

		}
		return vecNum;
	}
public:

	void test()
	{
		TreeNode* root = new TreeNode(1);
		root->left = new TreeNode(2);
		root->left->right = new TreeNode(5);
		root->right = new TreeNode(3);
		root->right->right = new TreeNode(4);

		vector<int> nums;
		nums = rightSideView(root);
		cout << "给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。" << endl;
		for (size_t i = 0; i < nums.size(); i++)
		{
			cout << nums[i] << "   ";
		}
		cout << endl<<endl;

	}
};