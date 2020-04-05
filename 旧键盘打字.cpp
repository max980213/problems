/*
题目描述
旧键盘上坏了几个键，于是在敲一段文字的时候，对应的字符就不会出现。现在给出应该输入的一段文字、以及坏掉的那些键，打出的结果文字会是怎样？

输入描述:
输入在2行中分别给出坏掉的那些键、以及应该输入的文字。其中对应英文字母的坏键以大写给出；每段文字是不超过10^5个字符的串。可用的字符包括字母[a-z, A-Z]、数字0-9、以及下划线“_”（代表空格）、“,”、“.”、“-”、“+”（代表上档键）。题目保证第2行输入的文字串非空。
注意：如果上档键坏掉了，那么大写的英文字母无法被打出。


输出描述:
在一行中输出能够被打出的结果文字。如果没有一个字符能被打出，则输出空行。

输入例子:
7+IE.
7_This_is_a_test.

输出例子:
_hs_s_a_tst
*/




#include <iostream>
#include <string>
 
#include <stdio.h>
#include <string.h>
 
using namespace std;
 
/*
 
int main()
{
    string str1,str2;   //str1是坏了的键盘
    cin>>str1>>str2;
    for(unsigned int i=0;i<str1.size();i++)  //参考erase的用法，删除单个应该用迭代器，如果是下标，则为
    {                                        //erase(pos,len)，从pos位置//从0开始开始删除len个，不填的话就是后面全都删
                                             //而且，每一次删除后，str.size()会更新，故j--
        if(str1[i]=='+')
        {
            for(unsigned int j=0;j<str2.size();j++)
            {
                if('A'<=str2[j]&&str2[j]<='Z')
                    str2.erase(j--,1);
            }
        }
        else if('A'<=str1[i]&&str1[i]<='Z')
        {
            for(unsigned int j=0;j<str2.size();j++)
            {
                if(str2[j]==str1[i]||str2[j]==str1[i]-'A'+'a')
                    str2.erase(j--,1);
            }
        }
        else
        {
            for(unsigned int j=0;j<str2.size();j++)
            {
                if(str1[i]==str2[j])
                    str2.erase(j--,1);
            }
        }
    }
    cout<<str2;
    return 0;
}
 
*/
 
//采用更简单的方法
 
 
int main()
{
    int a[256];
    memset(a,0,sizeof(a));
    char ch;
    while((ch=getchar())!='\n')  //读入第一个
    {
        a[ch]++;
    }
    while((ch=getchar())!='\n')  //读入第二个
    {
        if(('A'<=ch&&ch<='Z'&&a['+'])||(a['a'<=ch&&ch<='z'?ch-'a'+'A':ch]))
            continue;
        else
            putchar(ch);
    }
    return 0;
}
