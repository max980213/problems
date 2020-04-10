/*
字符串APPAPT中包含了两个单词“PAT”，其中第一个PAT是第2位(P),第4位(A),第6位(T)；第二个PAT是第3位(P),第4位(A),第6位(T)。

现给定字符串，问一共可以形成多少个PAT？

输入描述:
输入只有一行，包含一个字符串，长度不超过105，只包含P、A、T三种字母。


输出描述:
在一行中输出给定字符串中包含多少个PAT。由于结果可能比较大，只输出对1000000007取余数的结果。
示例1
输入
APPAPT
输出
2
*/

//动态规划思想
 
#include <stdio.h>
 
int main()
{
    int p,pa,pat;
    p=pa=pat=0;
    char ch;
    while((ch=getchar())!='\n')
    {
        if(ch=='P')
            p++;
        else if(ch=='A')
            pa+=p;
        else
            pat+=pa;
        p%=1000000007;
        pa%=1000000007;
        pat%=1000000007;
    }
    printf("%d",pat);
    return 0;
}
