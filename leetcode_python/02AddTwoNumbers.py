#coding:UTF-8

##You are given two linked lists representing two non-negative numbers.
##The digits are stored in reverse order and each of their nodes contain
##a single digit. Add the two numbers and return it as a linked list.
##
##Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
##Output: 7 -> 0 -> 8
		
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        x=self.linkToInt(l1)+self.linkToInt(l2)
        return self.IntToLink(x)
 
        
    def linkToInt(self,l):
        m=l.val
        n=1
        while(l.next != None):
            l=l.next
            m+=pow(10,n)*l.val
            n+=1
        return m

    def IntToLink(self,m):
        l=ListNode(m%10)
        l1=l
        while(m>=10):
            m=m/10
            l.next=ListNode(m%10)
            l=l.next
        return l1


    def LinkToList(self,l):
        list1=[]
        list1.append(l.val)
        
        while(l.next != None):
            l=l.next
            list1.append(l.val)
            
        return list1
        


if __name__=='__main__':
    l3=ListNode(3)
    l3.next=ListNode(2)
    l3.next.next=ListNode(1)

    print(Solution().linkToInt(l3))
    print(Solution().linkToInt(l3))

    l1=ListNode(2)
    l1.next=ListNode(4)
    l1.next.next=ListNode(3)

    l2=ListNode(5)
    l2.next=ListNode(6)
    l2.next.next=ListNode(4)

    print(Solution().addTwoNumbers(l1,l2))

