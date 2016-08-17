#coding:UTF-8

##Given a string, find the length of the longest substring without repeating characters.
##
##Examples:
##
##Given "abcabcbb", the answer is "abc", which the length is 3.
##
##Given "bbbbb", the answer is "b", with the length of 1.
##
##Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
##
##Subscribe to see which companies asked this question

class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        max=1
        i=0
        j=1
        count=0
        for i in range(0,len(s)):
##            print('i:',i)
##            print('len(s)',len(s))
##            print('max',max)
            count=1
            m=0
            for j in range(i+1,len(s)):
                for m in range(i,j):
##                    print('i=',i,'   j=',j,'   count',count,'    m',m)
                    if (s[m] != s[j]):
                        count+=1 
                    else:
                        count=1
                        i=m+1
                        break

                if(count>max):
                    max=count
                count=1
        return max

if __name__=='__main__':
    print(range(1,5))
    for i in range(1,5):
        print (i)
    print('abc')
    print("aab---------=",Solution().lengthOfLongestSubstring("aab"))
    print("abcabcbb---------=",Solution().lengthOfLongestSubstring("abcabcbb"))
    print("bbbbb---------=",Solution().lengthOfLongestSubstring("bbbbb"))
    print("pwwkew---------=",Solution().lengthOfLongestSubstring("pwwkew"))
    print("au---------=",Solution().lengthOfLongestSubstring("au"))
    print("bwf---------=",Solution().lengthOfLongestSubstring("bwf"))
    print("dvdf---------=",Solution().lengthOfLongestSubstring("dvdf"))
    print("dvdf---------=",Solution().lengthOfLongestSubstring("sguishzlcvfqlwpiyiiutakxrnmtndmhkgqcqrpuoxlzvchukrqftaclnpecuqjeybjqtalhzyhvcq"))
    
    print("aa---------=",Solution().lengthOfLongestSubstring("aa"))
    
