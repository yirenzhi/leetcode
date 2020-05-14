#pragma once
#include "base.h"


//102. 二叉树的层序遍历
class Solution102 :public Solution {
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> vecNum;
		if (!root)
		{
			return vecNum;
		}
		queue<TreeNode*> q;
		q.push(root);
		while (q.size()>0)
		{
			int len = q.size();
			vector<int> order;
			for (int i = 0; i<len; i++)
			{
				TreeNode* temp = q.front();
				q.pop();
				order.push_back(temp->val);
				if (temp->left) {
					q.push(temp->left);
				}
				if (temp->right) {
					q.push(temp->right);
				}
			}
			vecNum.push_back(order);
		}
		return vecNum;
	}
public:

	void test()
	{
		/*
		示例：
			二叉树：[3, 9, 20, null, null, 15, 7],

			3
			/ \
			9  20
			/ \
			15   7

		*/
		TreeNode* root = new TreeNode(3);
		root->left = new TreeNode(9);
		root->right = new TreeNode(20);
		root->left->left = new TreeNode(15);
		root->left->right = new TreeNode(7);

		vector<vector<int>> vecNum;		
		vecNum = levelOrder(root);

		for (size_t i = 0; i < vecNum.size(); i++)
		{
			for (size_t j = 0; j < vecNum[i].size(); j++)
			{
				cout << vecNum[i][j] << " ";
			}
			cout << endl;
		}


	}
};