#include<stdio.h>

int a[21],k,sum,num=1;
bool b[21]={0};
bool flag=0;

bool isprime(int s) //判断素数
{
    for(int i=2;i*i<=s;i++)
        if(s%i==0) return 0;
    return 1;
}

void print() //输出，注意格式
{
    for(int i=1;i<20;i++)
    printf("%d ",a[i]);
    printf("%d\n",a[20]);
}

void search(int r)
{
    for(int i=1;i<=20;i++) //枚举1~20 20个待填的数
    {
        if(!b[i]&&isprime(i+a[r-1])) //如果没有被使用并且和上一个数之和为素数
    	{
        	a[r]=i;
        	b[i]=1; //记录并标记
        	if(r==20&&isprime(a[1]+a[20]))
            {
            	print(); //如果填完20个数且第一个数与最后一个数之和为素数（连成环），便输出
            }
          else search(r+1);
        	b[i]=0; //回溯，作相反操作（a[r]的值会覆盖，可不清0）
   		 }
    }
}

int main()
{
    search(1);
    return 0;
}
