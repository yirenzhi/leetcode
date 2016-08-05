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

        if(p==None or q==None):
            if(p==None and q==None):
                return True
            else:
                return False
        return (p.val==q.val) and (self.isSameTree(p.left,q.left)) and self.isSameTree(p.right,q.right)
        

def zhongxubianli(p):
    if(type(p)==TreeNode):
        print(p.val)
        
##    if(p.left!=None):
        zhongxubianli(p.left)

##    if(p.right!=None):
        zhongxubianli(p.right)

    


    

if __name__=='__main__':
    print('abb')
    p1=TreeNode(8)
    p2=TreeNode(9)
    p3=TreeNode(10)
    p1.left = p2
    p1.right = p3
    m=Solution()
    print(m.isSameTree(p1,p2))
    print(m.isSameTree(p2,None))

    p4=TreeNode(8)
    p5=TreeNode(9)
##    p5.left=TreeNode(100)
    p6=TreeNode(10)
    p4.left = p5
    p4.right = p6
    print(m.isSameTree(p1,p4))
    print(m.isSameTree(p1,p2)^m.isSameTree(p1,p4))

    zhongxubianli(p4)
    
          
