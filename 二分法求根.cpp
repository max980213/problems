//二分法求 x^3-x^2-1=0在[0,3]的根（已知只有一个根）

#include <stdio.h>

const double eps=1e-5;

double function(double x)
{
    return x*x*x-x*x-1;
}

double getans(double left,double right)
{
    double i=left,j=right,mid;  //已知递增
    while(j-i>eps)
    {
        mid=(i+j)/2;
        if(function(mid)>0)
            j=mid;
        else
            i=mid;
    }
    return mid;
}

int main()
{
    printf("%f",getans(0,3));
    return 0;
}
