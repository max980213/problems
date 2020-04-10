/*
题目描述
本题要求读入N名学生的成绩，将获得某一给定分数的学生人数输出。

输入描述:
输入在第1行给出不超过105的正整数N，即学生总人数。随后1行给出N名学生的百分制整数成绩，中间以空格分隔。最后1行给出要查询的分
数个数K（不超过N的正整数），随后是K个分数，中间以空格分隔。


输出描述:
在一行中按查询顺序给出得分等于指定分数的学生人数，中间以空格分隔，但行末不得有多余空格。

输入例子:
10
60 75 90 55 75 99 82 90 75 50
3 75 90 88

输出例子:
3 2 0
*/

//与买手串的题思想一样：百分制，开一个int a[100]，记录每一个成绩的出现次数
 
#include <stdio.h>
#include <string.h>
 
int main()
{
    int info[101];
    memset(info,0,sizeof(info));
    int n,grades;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&grades);
        info[grades]++;
    }
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&grades);
        printf("%d",info[grades]);
        if(i!=n-1)
            putchar(' ');
    }
    return 0;
}
