'''
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]
'''

class Solution:
    #全部组合
    def threeSum(self, nums):
        list1=[]
        for i in range(len(nums)-2):
            for j in range(i+1,len(nums)-1):
                for k in range(i+2,len(nums)):
                    if(nums[i]+nums[j]+nums[k]==0):
                        list1.append([nums[i],nums[j],nums[k]])

        return list1

    def threeSum1(self,nums):
        list1=[]
        d1={}
        for i in range(len(nums)-2):
            for j in range(i+1,len(nums)-1):
                if nums[j] in d1:
                    print(nums[j])
                    print(d1[nums[j]])
                    temp = d1[nums[j]].copy()
                    temp.append(nums[j])
                    list1.append(temp)
                else:
                    d1[-nums[i]-nums[j]]=[nums[i],nums[j]]
        return list1

    def threeSum2(self,nums):
        list1=[]
        nums=sorted(nums)
        print(nums)
        for i in range(1,len(nums)-1):
            # if(i>1):
            #     if(nums[i]==nums[i-1]): 
            #         continue
                
            k=0
            j=len(nums)-1
            while(i<j and i>k):
                if(nums[i]+nums[j]+nums[k]==0):
                    print('append')
                    print(i,j,k)
                    list1.append([nums[i],nums[j],nums[k]])
                if(nums[i]+nums[j]+nums[k]<=0 and k<i):
                    print(i,j,k)
                    k+=1
                    while(nums[k]==nums[k-1]):
                        print('<'+str(k))
                        k+=1
                elif(nums[i]+nums[j]+nums[k]>=0 and i<j):
                    print(i,j,k)
                    j-=1
                    while(nums[j]==nums[j+1]):
                        print('>'+str(j))
                        j-=1
                else:
                    break

        return list1


if __name__ == '__main__':
    nums = [-1, 0, 1, 2, -1, -4]
    nums
    #print(Solution().threeSum(nums))
    #print(Solution().threeSum1(nums))
    print(Solution().threeSum2(nums))
