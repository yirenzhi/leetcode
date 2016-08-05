#coding:UTF-8

class Solution(object):
    
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        list=[]

        list.append(nums)
        
        return list


if __name__=='__main__':
    m=[1,2,3];
    print (Solution().permute(m))



