/*
题目描述
某城镇进行人口普查，得到了全体居民的生日。现请你写个程序，找出镇上最年长和最年轻的人。

这里确保每个输入的日期都是合法的，但不一定是合理的——假设已知镇上没有超过200岁的老人，而今天是2014年9月6日，所以超过200
岁的生日和未出生的生日都是不合理的，应该被过滤掉。

输入描述:
输入在第一行给出正整数N，取值在(0, 105]；随后N行，每行给出1个人的姓名（由不超过5个英文字母组成的字符串）、以及
按“yyyy/mm/dd”（即年/月/日）格式给出的生日。题目保证最年长和最年轻的人没有并列。


输出描述:
在一行中顺序输出有效生日的个数、最年长人和最年轻人的姓名，其间以空格分隔。

输入例子:
5
John 2001/05/12
Tom 1814/09/06
Ann 2121/01/30
James 1814/09/05
Steve 1967/11/20

输出例子:
3 Tom John
*/

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct person
{
    string name,birthday;
}person;

bool cmp(person a,person b)
{
    return a.birthday>b.birthday;
}

int main()
{
    int n;
    cin>>n;
    person data[n];
    for(int i=0;i<n;i++)
    {
        cin>>data[i].name>>data[i].birthday;
    }
    sort(data,data+n,cmp);  //先排序，降序   //年份越大，年龄越小，我真憨憨
    int i,j;
    string small="1814/09/06";
    string large="2014/09/06";
    for(i=0;i<n;i++)
    {
        if(data[i].birthday>large)
            continue;
        else
            break;
    }
    for(j=n-1;j>-1;j--)
    {
        if(data[j].birthday<small)
            continue;
        else
            break;
    }
    cout<<j-i+1<<" "<<data[j].name<<" "<<data[i].name;   //年龄大的年份小，我就是个憨憨
    return 0;
}
