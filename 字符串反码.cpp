//题目描述：定义一个字符的反码。如果这是一个小写字符，则它和字符'a’的距离与它的反码和字符'z’的距离相同；
//如果是一个大写字符，则它和字符'A’的距离与它的反码和字符'Z’的距离相同；如果不是上面两种情况，它的反码就是它自身。



#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int maxn=1010;

int main()
{
    char str[maxn];
    char rev[maxn]; //临时存放反码
    int i=0;
    while(1)
    {
    gets(str);
    if(str[0]=='!'&&str[1]=='\0')
        return 0;
    for(i=0;i<strlen(str);i++)
    {
        if(str[i]>='a'&&str[i]<='z')
        {
            rev[i]=('z'-str[i]+'a');
        }
        else if(str[i]>='A'&&str[i]<='Z')
        {
            rev[i]=('Z'-str[i]+'A');
        }
        else
        {
            rev[i]=str[i];
        }
    }
    rev[i]='\0';
    puts(rev);
    }
}
