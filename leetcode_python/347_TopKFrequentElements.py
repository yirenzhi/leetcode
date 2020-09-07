class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        #创建字典
        dict1={}
        for i in nums:
            if i in dict1:
                dict1[i]= dict1[i]+1
            else:
                dict1[i]=1
        
        list2=sorted(dict1.items(), key = lambda kv:(kv[1], kv[0]),reverse=True)
        return [list2[i][0] for i in range(k)]
        # list1=[]
        # for i in range(k):
        #     list1.append(list2[i][0])

        # return list1[:k]

        #一行解题法
        #return [num for num, _ in Counter(nums).most_common(k)]