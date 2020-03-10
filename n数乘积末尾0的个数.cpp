//思路：若能产生末尾0，必须同时存在能被2和5整除的数，然后看这个数能被2除多少次，累加，再看能被5除多少次，再累加，取小的那个值
//分解成乘积得到0的素数，最小的为2和5


#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int num=0;
    //int ans=1000000000000000;
    int number[n];
    int temp[2]={0,0}; //0位存能用来整数2的，1位存能用来整除5的
    for(int i=0;i<n;i++)
    {
        scanf("%d",&number[i]);  //读入
    }
    for(int i=0;i<n;i++)
    {
        //while(number[i]%10==0)  //特殊处理0，这一步可省，因为0结尾的既能被2除也能被5除，会在下面两部都加上，即使一个比另一个多，最后也是取小的
      //  {
      //      num++;
     //       number[i]/=10;
     //   }
        while(number[i]%5==0)
        {
            temp[1]++;
            number[i]/=5;
        }
        while(number[i]%2==0)    //要么它结尾为0，否则不可能能同时被2和5除，相当于if判断
        {
            temp[0]++;
            number[i]/=2;
        }
    }
    if(temp[0]>temp[1])
        num+=temp[1];
    else
        num+=temp[0];
    printf("%d",num);
    return 0;
}
