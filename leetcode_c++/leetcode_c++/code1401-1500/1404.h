#pragma once

#include "../base.h"
/*给你一个以二进制形式表示的数字 s 。请你返回按下述规则将其减少到 1 所需要的步骤数：

如果当前数字为偶数，则将其除以 2 。

如果当前数字为奇数，则将其加上 1 。

题目保证你总是可以按上述规则将测试用例变为 1 。

*/

class Solution1404 : public Solution
{
public:
int numSteps(string s) {
    //s为二进制字符串，需要将其转换为十进制整数
    int num=0;
    for(int i=0;i<s.size();i++){
        num=num*2+s[i]-'0';
    }
        int ans=0;
        
        while(num!=1){
            if(num%2==0){
                num/=2;
            }else{
                num+=1;
            }
            ans++;
        }
        return ans;
}
    virtual void test()
    {
        cout << "Hello, World!" << endl;
    }
};

REGISTER_SOLUTION(1404, Solution1404)
