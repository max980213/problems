#include <stdio.h>
#include <string.h>

int main()
{
    int A[10][10];
    int num=1;
    for(int i=0;i<10;i++)   //处理左上三角，外层循环是行
    {
        for(int j=0;j<=i;j++)
        {
            A[i-j][j]=num++;
        }
    }

    for(int j=1;j<10;j++)   //处理右下三角，从角落开始会更容易，但我偏不
    {
        for(int i=9;i>=j;i--)
        {
            A[i][9-i+j]=num++;
        }
    }

    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
}
