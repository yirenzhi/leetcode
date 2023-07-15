#pragma once
#include "../base.h"

//����һ�ö������������Լ�վ�������Ҳ࣬���մӶ������ײ���˳�򣬷��ش��Ҳ����ܿ����Ľڵ�ֵ��
class Solution199 :public Solution{
	//bfs����  ���ö���ȡ��ÿ������֣�Ȼ��ÿ�����һ��Ԫ���ռ�����Ϊ���ұ�Ԫ��
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
		cout << "����һ�ö������������Լ�վ�������Ҳ࣬���մӶ������ײ���˳�򣬷��ش��Ҳ����ܿ����Ľڵ�ֵ��" << endl;
		for (size_t i = 0; i < nums.size(); i++)
		{
			cout << nums[i] << "   ";
		}
		cout << endl<<endl;

	}
};