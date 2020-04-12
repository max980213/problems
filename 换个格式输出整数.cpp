/*
让我们用字母B来表示“百”、字母S表示“十”，用“12...n”来表示个位数字n（<10），换个格式来输出任一个不超过3位的正整数。例如234
应该被输出为BBSSS1234，因为它有2个“百”、3个“十”、以及个位的4。

输入描述:
每个测试输入包含1个测试用例，给出正整数n（<1000）。


输出描述:
每个测试用例的输出占一行，用规定的格式输出n。
示例1
输入
234
输出
BBSSS1234
*/

#include <stdio.h>
 
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        while(n>=100)
        {
            printf("B");
            n-=100;
        }
        while(n>=10)
        {
            printf("S");
            n-=10;
        }
        for(int i=1;i<=n;i++)
            printf("%d",i);
        printf("\n");
    }
    return 0;
     
}
