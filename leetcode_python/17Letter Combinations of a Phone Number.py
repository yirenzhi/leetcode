#coding:UTF-8

'''
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
'''

class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        dict2={'2':'abc','3':'def','4':'ghi','5':'jkl','6':'mno','7':'pqrs','8':'tuv','9':'wxyz'}
        if not digits:
            return []
        listAll=['']
        # for digit in digits:
        #     digit_letter = dict2[digit]
        #     res_temp=[]
        #     for item in digit_letter:
        #         res_temp+=[x+item for x in listAll]
        #     listAll=res_temp

        for digit in digits:
            listAll=[x+y for x in listAll for y in dict2[digit]]

        return listAll


        # for i in digits:
        #     list1.append(dict2[i])
        # print(list1)
        # listAll=[]
        # listAll.append('')
        # for item in list1:
        #     listAll=self.addStr(listAll,item)
        # return listAll

    def addStr(self,str1,str2):
        listAll=[]
        for x in str1:
            for y in str2:
                listAll.append(x+y)
        return listAll

if __name__ == '__main__':
    print('hello')
    nums = '23'
    print(Solution().letterCombinations(nums))
