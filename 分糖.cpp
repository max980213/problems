/*给第一个小朋友 1 颗糖果，第二个小朋友 2 颗，依此类推，直到给最后一个小朋友 n 颗糖果。

然后，我们再回到队伍的起点，给第一个小朋友 n + 1 颗糖果，第二个小朋友 n + 2 颗，依此类推，直到给最后一个小朋友 2 * n 颗糖果。

重复上述过程（每次都比上一次多给出一颗糖果，当到达队伍终点后再次从队伍起点开始），直到我们分完所有的糖果。注意，就算我们手中的剩下糖果数不够（不比前一次发出的糖果多），这些糖果也会全部发给当前的小朋友。
*/




#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int maxn=1010;

int* distributeCandies(int candies, int num_people)
{
    int *ans=(int*)malloc(num_people*sizeof(int));
    memset(ans,0,num_people*sizeof(int));
    int i=0,j=1;
    while(candies>0)
    {
        if(candies>=j)
        {
            ans[i]+=j;
            candies-=j;
            j++;
        }
        else
        {
            ans[i]+=candies;
            candies=0;
        }
        i++;
        if(i==num_people)
            i=0;
    }
    int k;
    for(k=0;k<num_people;k++)
        printf("%d ",ans[k]);
        return ans;
}

int main()
{
    int candies,num_people;
    scanf("%d %d",&candies,&num_people);
    distributeCandies(candies,num_people);
    return 0;
}
