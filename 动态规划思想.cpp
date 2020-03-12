#include <stdio.h>   //gets()在这里
#include <iostream>
#include <algorithm>
#include <string.h>  //memset,strlen

using namespace std;

const int maxn=1010;
const int INF=100000000;


//动态规划思想：用于解决最优解的问题，将一个复杂的问题分解为若干子问题
//综合子问题的最优解得到全局的最优解


//1.动态规划的递归写法：斐波那契数列
//对于原来的写法，会涉及很多重复的计算。故可以设置数组dp[]，把已经求得直接存起来

int dp[maxn];  //初始化为-1，表示没计算过
//memset()  外面只能定义，main函数才是程序的开始

int fib(int n)
{
    if(n==0||n==1)
        return 1; //递归边界
    if(dp[n]!=-1)
        return dp[n]; //之前算过了
    else
    {
        dp[n]=fib(n-1)+fib(n-2);
        return dp[n];
    }
}




//动态规划的递推写法
//1.数塔问题：第i层有i个数，从第一层到最后一层的最大数和？每次只能走左边或右边
//暴力法会超时，复杂度2^n
//从最底层开始，逐一统计该点到最底层的最短，显然最底层就是它自身
//然后依次上层，与下层决策进行比较，逐一选择最优方案


void tower()
{
    int tower[maxn][maxn];
    int dp[maxn][maxn];
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            scanf("%d",&tower[i][j]);  //建立塔
        }
    }
    for(int j=1;j<=n;j++)
    {
        dp[n][j]=tower[n][j];
    }

    for(int i=n-1;i>=1;i--)
    {
        for(int j=1;j<=i;j++)
        {
            dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+tower[i][j];   //根据下一层更新自己
        }
    }

    printf("%d",dp[1][1]);  //得到了最优解
}



//2.最大连续子序列和
//暴力法复杂度为N^3
//稍微思考以下，用动态规划思想，只看右边的端点，统计以该店为终点的最大子序列
//从最小的端点开始，该值即为它本身
//逐个右移计算

void seq()
{
    int A[maxn];
    int dp[maxn];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&A[i]);

    //边界
    dp[0]=A[0];
    for(int i=1;i<n;i++)
    {
        dp[i]=max(dp[i-1]+A[i],A[i]);
    }
    //此时dp存放了以i为A[i]为结尾的最大子序列和，需要遍历一遍找到最大的
    int k=0;
    for(int i=1;i<n;i++)
        if(dp[i]>dp[k])
            k=i;
    printf("%d",dp[k]);
}



//3.最长不下降子序列：找到一个最长的子序列（可以不连续），使得这个子序列非递减
//暴力法复杂度为2^n（每个数字都有选和不选两个选择）
//同样的思想，设置dp[]数组，dp[i]表示以A[i]结尾的最长不下降子序列长度
//故，如果存在A[i]之前的元素A[j]，使A[j]<=A[i]且dp[j]+1>dp[i]，就更新
//每次遍历i之前到i的元素

int lis()
{
    int n;
    scanf("%d",&n);
    int a[n],dp[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int ans=-1; //记录最大的dp[i]
    for(int i=0;i<n;i++)
    {
        dp[i]=1;  //每个元素先自成一个序列
        for(int j=0;j<i;j++)
        {
            if(a[i]>=a[j]&&dp[j]+1>dp[i])
            {
                dp[i]=dp[j]+1; //更新
            }
        }
        ans=max(dp[i],ans);
    }
    return ans;
}


//4.最长公共子序列LCS
//给定两个字符串（或数字序列）A和B，求一个子串，使得这个字符串是A和B的最长公共部分（子序列可以不连续）
//暴力法2^(m+n)*max(m,n)
//设置dp[i][j]数组，表示以A[i]，B[j]为结尾之前的LCS长度，则到了A[i][j]的决策有两种：
//1.若A[i]==B[j]，则字符串A和B的LCS增加了1位，即dp[i][j]=dp[i-1][j-1]+1
//2.若A[i]!=B[j]，说明LCS无法延长，则dp[i][j]继承dp[i-1][j]和dp[i][j-1]较大的那个
//边界：dp[i][0]和dp[0][j]，初始为0
//通过以上分析，可知，输入字符串下标应从1开始

int lcs()
{
    const int maxn=100;
    char A[maxn],B[maxn];
    int dp[maxn][maxn];   //若想要边长，可用vector
    gets(A+1);
    gets(B+1);
    int lenA=strlen(A+1);
    int lenB=strlen(B+1);
    for(int i=0;i<lenA;i++) //边界
    {
        dp[i][0]=0;
    }
    for(int j=0;j<lenB;j++)
    {
        dp[0][j]=0;
    }
    for(int i=1;i<lenA;i++)
    {
        for(int j=1;j<lenB;j++)
        {
            if(A[i]==B[j])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    return dp[lenA][lenB];  //因为下标是从1开始，所以不需要减1
}

//5.最长回文子串：给定字符串S，求S的最长回文子串长度
//暴力法复杂度n^3
//不可S倒过来用LCS模型，因为如果存在子序和它倒序，就会出错
//用dp[i][j]表示区间i、j之间是否存在最长回文子串，两种转移情况：
//1.若S[i]==S[j]，只要S[i+1]至[j-1]是回文子串，那么S[i]至S[j]也是
//若不等于，那么一定不是
//边界：dp[i][i]=1， dp[i][i+1]=(S[i]==S[i+1])?1:0

//存在问题：如果按照i、j从小到大的顺序来枚举子串的两个端点，会无法保证dp[i+1][j-1]已经被计算过
//解决方法：注意到边界表示长度是1或者2的子串，且每次转移时对子串的长度减1，故枚举子串的长度和初始位置
//即，第一遍求出长度为3的子串的dp值，第二次计算长度为4的字串的dp值

int lrsc()
{
    const int maxn=1010;
    char S[maxn];
    int dp[maxn][maxn];
    gets(S);
    int len=strlen(S),ans=1;
    memset(dp,0,sizeof(dp));  //初始化为0
    for(int i=0;i<len;i++)
    {
        dp[i][i]=1;  //本身构成一个回文串
        if(i<len-1)   //对于长度为2的子串进行边界处理
        {
            if(S[i]==S[i+1])
            {
                dp[i][i+1]=1;
                ans=2;  //更新ans
            }
        }
    }

    //状态转移

    for(int L=3;L<=len;L++)  //枚举子串长度
    {
        for(int i=0;i+L-1<len;i++)   //枚举起始端点
        {
            int j=i+L-1; //右端点
            if(S[i]==S[j]&&dp[i+1][j-1]==1)
            {
                dp[i][j]=1;
                ans=L; //更新最长L
            }
        }
    }
    return ans;
}



//6.DAG最长路（有向无环图
//关键路径的另一种求法，着重解决两个问题：1.整个的最长路径，不固定起点终点  2.固定终点后的最长路径

//问题1：令dp[i]表示从i号顶点出发能获得的最大路径长度
//可知，如果从i号顶点出发能直接到达顶点j1，j2...，而dp[j1]，dp[j2]....已知
//那么有dp[i]=max(dp[j1]+length[i->j1]........)
//显然，可按照逆拓扑序列求解，但用递归可不用求出逆拓扑序列

//假设用邻接矩阵存储
//从出度为0的顶点出发的最长路径为0，故边界为这些顶点的dp值为0，但具体实现不妨设整个dp数组为0
//这样出度为0时返回了0，不为0则递归求解，遇到了计算过的直接返回
//从逻辑上实现了逆拓扑

//在dj斯特拉算法中，使用pre数组记录每个顶点的前驱
//这里可以类似，使用choice数组来记录每个结点的后继
//若存在多个最长路径，可使用vector数组

int choice[maxn];
int G[maxn][maxn];
int n;

int DP(int i)
{
    if(dp[i]>0)
        return dp[i]; //dp[i]已计算得到
    for(int j=0;j<n;j++)  //遍历i的所有出边
    {
        if(G[i][j]!=INF) //可达
        {
            int temp=DP(j)+G[i][j]; //单独计算，防止if中调用DP函数两次
            if(temp>dp[i])
            {
                dp[i]=temp;
                choice[i]=j;
            }
            //dp[i]=max(dp[i],DP(j)+G[i][j]);
        }
    }
    return dp[i];
}

//遍历dp数组，得到最大的dp[i]，便可得到路径
void printpath(int i)
{
    printf("%d ",i);
    while(choice[i]!=-1)
    {
        i=choice[i];
        printf("%d ",i);
    }
}


//问题2：固定终点T
//在问题1的基础上，令dp[i]表示从i号顶点到T能获得的最长路径长度
//那么仍然有dp[i]=max(dp[j1]+length[i->j1]........)，但无法体现终点为T
//故修改边界，问题1没有固定终点，故所有出度为0的顶点dp值为0
//本问题固定了终点，因此dp[T]=0才是边界
//此时若初始化数组dp为0会出错，由于从某些顶点出发也许到不了T，如出度为0的结点会得到0，这样不对
//合适的做法是初始化dp为一个负的大数，来保证无法到达终点得到表达
//然后设置一个vis数组表示顶点是否已经被计算

bool vis[maxn]={0};

int DPT(int i)
{
    if(vis[i])
        return dp[i]; //计算过就返回
    vis[i]=1;
    for(int j=0;j<n;j++) //遍历所有出边
    {
        if(G[i][j]!=INF) //可达
        {
            dp[i]=max(dp[i],DP(j)+G[i][j]);
        }
    }
    return dp[i];
}


//7.背包问题
//多阶段动态规划问题：问题被描述成若干有序阶段，且每个阶段的状态只和上一个阶段的状态有关
//只要从第一个问题开始，按照阶段的顺序解决每个阶段中状态的计算，就可以得到最后一个阶段的状态的解

//1.  0-1背包问题
//问题描述：有n件物品，每件物品重w[i]，价值为c[i]，现有一个容量为V的背包，问如何选取物品放入背包，使总价值最大，每种物品只有一件
//暴力法复杂度为2^n
//动态规划思想：令dp[i][v]表示前i件物品恰好装入容量为v的背包中所能获得的最大价值
//对第i件物品有两种选择策略：
//1. 不放第i件物品，那么问题转化为前i-1件物品恰好装入容量v的背包的最大价值也即dp[i-1][v]
//2. 放第i件物品，那么转化为前i-1物品恰好装入容量为v-w[i]背包中所能获得的最大值，也即dp[i-1][v-w[i]]+c[i]
//因此dp[i][v]=max(dp[i-1][v],dp[i-1][v-w[i]]+c[i])  1<=i<=n,w[i]<=v<=V v正逆序均可
//边界dp[0][v]=0，即前0件物品只能得到价值为0
//利用滚动数组可以对空间进行优化，因为每次只能用到dp[i-1]即上一层
//故可只开一个一维数组dp[v]，但此时对v的枚举必须逆序，因为用到的是上一层，正序可能导致后面要用到的被覆盖
//此时dp[v]=max(dp[v],dp[v-w[i]]+c[i])   1<=i<=n,w[i]<=v<=V   v只能逆序

int pack01()
{
    const int maxn=100; //物品最大件数
    const int maxv=1000; //V上限
    int w[maxn]={0},c[maxn]={0},dp[maxv];  //第一个元素是0
    memset(dp,0,sizeof(dp)); //初始化0
    int n,V;
    scanf("%d %d",&n,&V);
    for(int i=1;i<=n;i++)  //下标从1开始
        scanf("%d",&w[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i]);
    //边界
    for(int v=0;v<=V;v++)
        dp[v]=0;
    for(int i=1;i<=n;i++)
        for(int v=V;v>=w[i];v--)
        {
            dp[v]=max(dp[v],dp[v-w[i]]+c[i]);
        }

    //此时，dp中最大的就是答案
    int max=0;
    for(int v=0;v<=V;v++)
    {
        if(dp[v]>max)
            max=dp[v];
    }
    return max;
}

//2.  完全背包问题：物品可取无限次
//与0-1背包完全类似，但也不完全相同：对第i件物品，若不放，那么dp[i][v]=dp[i-1][v]，与0-1相同
//若放了，不是转移到d[i-1][v-w[i]]，而是d[i][v-w[i]]，因为物品i可放任意件
//故状态转移方程仍为 dp[i][v]=max(dp[i-1][v],dp[i][v-w[i]]+c[i])
//利用滚动数组，但v必须是正序了，因为要现获得dp[i]才可比较
//0-1背包逆序是防止数据覆盖，用到dp[i-1]
//完全背包正序是因为要提前用到，用到dp[i]

int packcompleted()
{
    const int maxn=100; //物品最大件数
    const int maxv=1000; //V上限
    int w[maxn]={0},c[maxn]={0},dp[maxv];  //第一个元素是0
    memset(dp,0,sizeof(dp)); //初始化0
    int n,V;
    scanf("%d %d",&n,&V);
    for(int i=1;i<=n;i++)  //下标从1开始
        scanf("%d",&w[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i]);
    //边界
    for(int v=0;v<=V;v++)
        dp[v]=0;
    for(int i=1;i<=n;i++)
        for(int v=w[i];v<=V;v++)   //只这里不一样，这里是正序
        {
            dp[v]=max(dp[v],dp[v-w[i]]+c[i]);
        }

    //此时，dp中最大的就是答案
    int max=0;
    for(int v=0;v<=V;v++)
    {
        if(dp[v]>max)
            max=dp[v];
    }
    return max;
}


int main()
{
    memset(dp,-1,sizeof(dp));
    memset(choice,-1,sizeof(choice));
    return 1;
}
