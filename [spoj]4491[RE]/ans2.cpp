/* ***********************************************
Author        :kuangbin
Created Time  :2013-10-19 22:01:05
File Name     :E:\2013ACM\专题学习\数学\莫比乌斯反演\SPOJ_PGCD.cpp
************************************************ */

#include "mode.h"
using namespace std;

const int MAXN = 10000000;
bool check[MAXN+10];
int prime[MAXN+10];
int mu[MAXN+10];
int g[MAXN+10];
int sum[MAXN+10];
void Moblus()
{
    memset(check,false,sizeof(check));
    mu[1] = 1;
    int tot = 0;
    for(int i = 2; i <= MAXN; i++)
    {
        if(!check[i])
        {
            prime[tot++] = i;
            mu[i] = -1;
            g[i] = 1;
        }
        for(int j = 0;j < tot;j++)
        {
            if(i * prime[j] > MAXN)break;
            check[i*prime[j]] = true;
            if(i % prime[j] == 0)
            {
                mu[i * prime[j]] = 0;
                g[i * prime[j]] = mu[i];
                break;
            }
            else
            {
                mu[i * prime[j]] = -mu[i];
                g[i * prime[j]] = -g[i] + mu[i];
            }
        }
    }
    sum[0] = 0;
    for(int i = 1;i <= MAXN;i++)
        sum[i] = sum[i-1] + g[i];
}
int main()
{
    setIO("sample");
    Moblus();
    int T;
    int n,m;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        if(n > m)swap(n,m);
        long long ans = 0;
        int last = 0;
        for(int i = 1;i <= n;i = last+1)
        {
            last = min(n/(n/i),m/(m/i));
            ans += (long long)(sum[last] - sum[i-1])*(n/i)*(m/i);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
