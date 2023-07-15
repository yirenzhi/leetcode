#pragma once

#include "../base.h"
//将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。

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

	

	//递归
	



	void test() {


        ListNode* l2=new ListNode(2);
        ListNode* l1=new ListNode(1,l2);

		ListNode* l3 = removeNthFromEnd(l1,1);
		printList(l3);
	}


};
