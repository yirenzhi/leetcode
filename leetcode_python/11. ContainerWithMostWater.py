'''
11. 盛最多水的容器
给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器，且 n 的值至少为 2。

示例：

输入：[1,8,6,2,5,4,8,3,7]
输出：49
'''

class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        #一共有(n*n-n)/2种
        maxarea=0
        for i in range(len(height)-1):
            for j in range(1,len(height)):
                #计算面积
                area=self.getArea(height,i,j)
                if area>maxarea:
                    maxarea=area
        return maxarea

    def getArea(self,height,i,j):
        width = j-i
        height=min(height[i],height[j])
        return width*height

    def maxArea2(self, height):
        l=0
        r=len(height)-1
        maxarea=0
        while l<r:
            area=self.getArea(height,l,r)
            maxarea=max(maxarea,area)
            if height[l]<height[r]:
                l+=1
            else:
                r-=1
        return maxarea
            


if __name__ == '__main__':
    nums=[1,8,6,2,5,4,8,3,7]
    print(Solution().maxArea(nums))
    print(Solution().maxArea2(nums))
