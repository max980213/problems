/*
题目描述
旧键盘上坏了几个键，于是在敲一段文字的时候，对应的字符就不会出现。现在给出应该输入的一段文字、以及实际被输入的文字，请你列出
肯定坏掉的那些键。

输入描述:
输入在2行中分别给出应该输入的文字、以及实际被输入的文字。每段文字是不超过80个字符的串，由字母A-Z（包括大、小写）、数字0-9、
以及下划线“_”（代表空格）组成。题目保证2个字符串均非空。


输出描述:
按照发现顺序，在一行中输出坏掉的键。其中英文字母只输出大写，每个坏键只输出一次。题目保证至少有1个坏键。

输入例子:
7_This_is_a_test
_hs_s_a_es

输出例子:
7TI

*/


#include <iostream>
#include <string>
#include <string.h>
 
using namespace std;
 
//用一个数组存放是否坏
/*
int main()
{
    string str1,str2;
    cin>>str1>>str2;
    bool broken[256]; //asc码有256个键
    memset(broken,0,sizeof(broken));
    //vector <char> vi;   //实现按发现顺序输出，真麻烦
    int flag=0;
    for(unsigned int i=0;i<str1.size();i++)
    {
        int temp=('a'<=str1[i]&&str1[i]<='z'?str1[i]-'a'+'A':str1[i]);
        for(unsigned int j=0;j<str2.size();j++)   //把大写小写放到一起
        {
            if(broken[temp]==1||str1[i]==str2[j])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            broken[temp]=1;
            printf("%c",temp);  //进一步优化，直接输出
        }
        flag=0;
    }
    return 0;
}
*/
 
//还能再优化
 
int main()
{
    string str1,str2;
    cin>>str1>>str2;
    bool broken[256]; //asc码有256个键
    memset(broken,0,sizeof(broken));
    for(unsigned int i=0;i<str2.size();i++) //第一次遍历str2，记录出现过的，肯定没坏
    {
        int temp=('a'<=str2[i]&&str2[i]<='z'?str2[i]-'a'+'A':str2[i]);
        broken[temp]=1;
    }
    for(unsigned int i=0;i<str1.size();i++) //第二次遍历str1，只要这里有的str2里没有，就坏了
    {
        int temp=('a'<=str1[i]&&str1[i]<='z'?str1[i]-'a'+'A':str1[i]);
        if(broken[temp]==0)
        {
            printf("%c",temp);
            broken[temp]=1; //输出过就不管他了
        }
    }
    return 0;
}
