'''You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
'''
# Definition for singly-linked list.
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
        count=self.getNumbers(l1)+self.getNumbers(l2)
        return self.getNodes(count)

    def getNumbers(self,l1):
        count=0
        while(l1!=None):
            count=count*10+l1.val
            l1=l1.next
        return count

    def getNodes(self,count):
        l=ListNode(int(str(count)[:1]))
        l1=l
        for i in str(count)[1:]:
            l.next=ListNode(int(i))
            l=l.next
        return l1

    def printNodes(self,l1):
        while l1:
            print(l1.val,end=' ')
            l1=l1.next



if __name__=='__main__':

    s1=Solution()
    l1=s1.getNodes(7243)
    l2=s1.getNodes(564)
    s1.printNodes(s1.addTwoNumbers(l1,l2))


