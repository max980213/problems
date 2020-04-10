/*
小红想买些珠子做一串自己喜欢的珠串。卖珠子的摊主有很多串五颜六色的珠串，但是不肯把任何一串拆散了卖。于是小红要你帮忙判断一
下，某串珠子里是否包含了全部自己想要的珠子？如果是，那么告诉她有多少多余的珠子；如果不是，那么告诉她缺了多少珠子。

为方便起见，我们用[0-9]、[a-z]、[A-Z]范围内的字符来表示颜色。例如，YrR8RrY是小红想做的珠串；那么ppRYYGrrYBR2258可以买，因为包含了
全部她想要的珠子，还多了8颗不需要的珠子；ppRYYGrrYB225不能买，因为没有黑色珠子，并且少了一颗红色的珠子。

输入描述:
每个输入包含1个测试用例。每个测试用例分别在2行中先后给出摊主的珠串和小红想做的珠串，两串都不超过1000个珠子。


输出描述:
如果可以买，则在一行中输出“Yes”以及有多少多余的珠子；如果不可以买，则在一行中输出“No”以及缺了多少珠子。其间以1个空格分隔。
示例1
输入
ppRYYGrrYBR2258<br/>YrR8RrY
输出
Yes 8
*/



#include <stdio.h>
#include <string.h>
 
int main()
{
    char ch;
    int str1[256];
    memset(str1,0,sizeof(str1));
    while((ch=getchar())!='\n')
    {
        str1[ch]++;
    }
    while((ch=getchar())!='\n')
    {
        str1[ch]--;
    }
    int num1=0,num2=0,flag=0;
    for(int i=0;i<256;i++)
    {
        if(str1[i]==1)
            continue;
        else if(str1[i]>0)
            num1+=str1[i];
        else if(str1[i]<0)
        {
            num2-=str1[i];
            flag=1;
        }
    }
    if(flag==0)
        printf("Yes %d",num1);
    else
        printf("No %d",num2);
}
