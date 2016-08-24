## The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
##
##P   A   H   N
##A P L S I I G
##Y   I   R
##
##And then read line by line: "PAHNAPLSIIGYIR"
##
##Write the code that will take a string and make this conversion given a number of rows:
##
##string convert(string text, int nRows);
##
##convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR"

#coding:UTF-8


class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        m=len(s)
        if m<=0:
            return ''
        else:
            s1=''            
            for y in range(0,numRows):
                x1=y
                for i in range(y,m):
                    if(x1<m):
                        s1+=s[x1]
                        print(x1)
                        if y==numRows//2:
                            print('a')
                            x1+=((numRows+1)//2)
                        else:
                            print('b')
                            x1+=((numRows+1))
                            
            return s1


if __name__=='__main__':
    print('abc')
    print(type([0,4,8,12]))
    #print (Solution().convert("PAYPALISHIRING",3))
    print (Solution().convert("abc",2))

