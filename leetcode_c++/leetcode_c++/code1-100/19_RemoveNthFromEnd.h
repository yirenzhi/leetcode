#pragma once

#include "../base.h"
//��������������ϲ�Ϊһ���µ������������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ�

class Solution19 :public Solution {
    private:

    ListNode* removeNthFromEnd(ListNode* head, int n) {

        auto temp = head;
        ListNode* nodes[32];
        auto node1=head;
        int i=0;
        for(;node1!=nullptr;++i)
        {
            nodes[i]=node1;
            node1=node1->next;
        }
        if(i==n){
            temp=temp->next;
        }else{
            nodes[i-n-1]->next =nodes[i-n]->next;   
        }        


        return temp;

    }
public:

	

	//�ݹ�
	



	void test() {


        ListNode* l2=new ListNode(2);
        ListNode* l1=new ListNode(1,l2);

		ListNode* l3 = removeNthFromEnd(l1,1);
		printList(l3);
	}


};
