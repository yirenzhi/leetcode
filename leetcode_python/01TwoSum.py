#coding:UTF-8

##1. Two Sum  QuestionEditorial Solution  My Submissions
##Total Accepted: 266605
##Total Submissions: 1057204
##Difficulty: Easy
##Given an array of integers, return indices of the two numbers such that they add up to a specific target.
##
##You may assume that each input would have exactly one solution.
##
##Example:
##Given nums = [2, 7, 11, 15], target = 9,
##
##Because nums[0] + nums[1] = 2 + 7 = 9,
##return [0, 1].


class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        
        for i in range(0,len(nums)):
            for j in range(i+1,len(nums)):
                if(nums[i]+nums[j]==target):
                    l=[]
                    l.append(i)
                    l.append(j)
                    return l


if __name__ == '__main__':
    print('hello')
    nums = [2, 7, 11, 15]
    target = 9
    print(Solution().twoSum(nums,target))
    
