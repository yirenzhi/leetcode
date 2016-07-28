#coding:UTF-8
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """
        return bianli(p,q)
##        if(p.left!=None and q.left!=None):
##            bianli(p.left,q.left)
##        elif((p.left!=None)!=(q.left!=None)):
##            return False
##        if(p.val!=p.val):
##            return False
##
##        if(p.right!=None and q.right!=None):
##            bianli(p.right,q.right)
##        elif((p.right!=None)!=(q.right!=None)):
##            return False
##
##        return True
        

def bianli(p,q):
    if(p.left!=None and q.left!=None):
        bianli(p.left,q.left)
    elif((p.left!=None)!=(q.left!=None)):
        return False
    if(p.val!=p.val):
        return False

    if(p.right!=None and q.right!=None):
        bianli(p.right,q.right)
    elif((p.right!=None)!=(q.right!=None)):
        return False

    return True


    

if __name__=='__main__':
    print('abb')
    p1=TreeNode(8)
    p2=TreeNode(9)
    p3=TreeNode(10)
    p1.left = p2
    p1.right = p3
    m=Solution()
    print(m.isSameTree(p1,p2))

    p4=TreeNode(8)
    p5=TreeNode(9)
    p6=TreeNode(10)
    p4.left = p5
    p4.right = p6
    print(m.isSameTree(p1,p4))
    print(m.isSameTree(p1,p2)^m.isSameTree(p1,p4))

    print (type(p1) is TreeNode)
    print(hasattr(p1,'val'))
    
          
