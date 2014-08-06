#include <cstdlib>
#include <iostream>

using namespace std;
const int maxn = 10000+10;
int n;
int d[maxn],f[maxn],up[maxn],ans[maxn];
int main(int argc, char *argv[])
{
    freopen("mr396.in1","r",stdin);
    freopen("mr396.ou1","w",stdout);
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
            scanf("%d",&d[i]);
    for(int i = 1;i<=n;i++)
     {
     f[i] = 1;
     for(int j = 1;j<i;j++)
      if(d[i] > d[j] && i-j < d[i]-d[j] && f[j]+1 >= f[i])
      {
      f[i] = f[j]+1;
      up[i] = j;
      }
      if(f[i] == 0)
      {
      up[i] = 0;
      if(i-1 > d[i])
       f[i] = 0;
      }
     }
    
     int maxx = 0,x = 0;
     for(int i = 1;i<=n;i++)
             if(maxx <= f[i])
             {
             maxx = f[i];x = i;
             }
     maxx = x;
     for(int i = 1;i<=n-x;i++)
      ans[x+i] = d[x]+i;
     while(up[x] != 0)
     {
                 ans[x] = d[x];
                 ans[up[x]] = d[up[x]];
                 for(int i = 1;i<=x-up[x]-1;i++)
                  ans[up[x]+i] = d[up[x]]+i;
                 x=up[x];
     }
     ans[x] = d[x];
     for(int i = 0;i<=x-2;i++)
      ans[i+1]=i;
     int sum = 0;
     for(int i = 1;i<=n;i++)
             sum = sum+ans[i];
     printf("%d %d",n-f[maxx],sum);
     

    return EXIT_SUCCESS;
}
