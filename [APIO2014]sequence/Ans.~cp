#include "mode.h"
#define MN 100010
#define MK 210
int f[MN][MK],s[MN],n,k,g[MN][MK],ans2[MK];
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi,k = gi;
    for(int i = 1;i<=n;++i)
     s[i] = gi;
    for(int i = 1;i<=n;++i) 
     s[i] += s[i-1];
    CLEAR(f,0xfe);
    f[0][0] = 0;
    for(int i = 1;i<=k;++i)
     for(int j = 1;j<=n;++j)
     {
      for(int u = 0;u<j;++u)
       if(f[j][i] < f[u][i-1]+(s[j]-s[u])*(s[n]-s[j])){
        f[j][i] = f[u][i-1]+(s[j]-s[u])*(s[n]-s[j]);
        g[j][i] = u;
       }
     }
    int ans=-INF,pos = 0;
    for(int i = 1;i<=n;++i)
      if(f[i][k] > ans)
      {
       ans = f[i][k];
       pos = i;
      }
    printf("%d\n",ans);
    int now = k;
    while(now)
    {
     ans2[now] = pos;
     pos = g[pos][now];
     --now;
    }
    for(int i = 1;i<=k;++i)
     printf("%d ",ans2[i]);
    closeIO();
    return EXIT_SUCCESS;
}
